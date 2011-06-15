/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 * contact: David Kabala (djkabala@gmail.com)                                *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                License                                    *
 *                                                                           *
 * This library is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU Library General Public License as published    *
 * by the Free Software Foundation, version 2.                               *
 *                                                                           *
 * This library is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of                *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 * Library General Public License for more details.                          *
 *                                                                           *
 * You should have received a copy of the GNU Library General Public         *
 * License along with this library; if not, write to the Free Software       *
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.                 *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                Changes                                    *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
\*---------------------------------------------------------------------------*/

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"

#include "OSGPostShaderStage.h"
#include "OSGPostShaderStageData.h"

#include "OSGFrameBufferObject.h"
#include "OSGFrameBufferAttachment.h"
#include "OSGRenderBuffer.h"
#include "OSGTextureBuffer.h"
#include "OSGRenderAction.h"

#include "OSGChunkMaterial.h"
#include "OSGMaterialChunk.h"
#include "OSGTextureObjChunk.h"
#include "OSGDrawEnv.h"
#include "OSGStateOverride.h"
#include "OSGTextureEnvChunk.h"
#include "OSGGL.h"

#include "OSGMatrixUtility.h"

#include <boost/lexical_cast.hpp>

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGPostShaderStageBase.cpp file.
// To modify it, please change the .fcd file (OSGPostShaderStage.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

UInt32 PostShaderStage::_uiFramebuffer_object_extension = Window::invalidExtensionID;
UInt32 PostShaderStage::_extDepthTexture      = Window::invalidExtensionID;

UInt32 PostShaderStage::_uiFuncDrawBuffers = Window::invalidFunctionID;

typedef void   (OSG_APIENTRY *GLDrawBuffersEXTProcT)(GLsizei  n, 
                                                     const GLenum  *buffers);

const std::string PostShaderStage::ShaderSceneColorTexName  = std::string("PostSceneColorTex");
const std::string PostShaderStage::ShaderSceneDepthTexName  = std::string("PostSceneDepthTex");
const std::string PostShaderStage::ShaderFBOWidthName       = std::string("PostFBOWidth");
const std::string PostShaderStage::ShaderFBOHeightName      = std::string("PostFBOHeight");
const std::string PostShaderStage::ShaderCameraNearName     = std::string("PostCameraNear");
const std::string PostShaderStage::ShaderCameraFarName      = std::string("PostCameraFar");
const std::string PostShaderStage::PrePassXName             = std::string("PostPass");
const std::string PostShaderStage::PostPassXColorTexName    = std::string("ColorTex");
const std::string PostShaderStage::PostPassXColorWidthName  = std::string("Width");
const std::string PostShaderStage::PostPassXColorHeightName = std::string("Height");

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void PostShaderStage::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
        RenderAction::registerEnterDefault(
            PostShaderStage::getClassType(), 
            reinterpret_cast<Action::Callback>(&PostShaderStage::renderEnter));
        
        RenderAction::registerLeaveDefault( 
            PostShaderStage::getClassType(), 
            reinterpret_cast<Action::Callback>(&PostShaderStage::renderLeave));

        _uiFramebuffer_object_extension = 
            Window::registerExtension("GL_EXT_framebuffer_object");

        _extDepthTexture      = 
            Window::registerExtension("GL_ARB_depth_texture");

        _uiFuncDrawBuffers  =
            Window::registerFunction (
                OSG_DLSYM_UNDERSCORE"glDrawBuffersARB", 
                _uiFramebuffer_object_extension);
    }
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

PostShaderStageDataTransitPtr PostShaderStage::setupStageData(Int32 iPixelWidth,
                                                              Int32 iPixelHeight)
{
    PostShaderStageDataTransitPtr returnValue = PostShaderStageData::createLocal();

    if(returnValue == NULL)
        return returnValue;

    OSG::Thread::setCurrentLocalFlags();

    // Scene Target
    FrameBufferObjectUnrecPtr pSceneFBO    = FrameBufferObject::createLocal();
        
    //Depth texture
    _SceneDepthTex     = TextureObjChunk::createLocal();
    TextureEnvChunkUnrecPtr pSceneDepthTexEnv  = TextureEnvChunk::createLocal();
    ImageUnrecPtr           pDepthImg          = Image          ::createLocal();

    pDepthImg->set(Image::OSG_L_PF, 
                   iPixelWidth, 
                   iPixelHeight,
                   1,
                   1,
                   1,
                   0.0,
                   NULL,
                   Image::OSG_UINT8_IMAGEDATA,
                   false);

    _SceneDepthTex   ->setImage         (pDepthImg        ); 
    _SceneDepthTex   ->setMinFilter     (GL_LINEAR        );
    _SceneDepthTex   ->setMagFilter     (GL_LINEAR        );
    _SceneDepthTex   ->setWrapS         (GL_CLAMP_TO_EDGE );
    _SceneDepthTex   ->setWrapT         (GL_CLAMP_TO_EDGE );
    _SceneDepthTex   ->setInternalFormat(GL_DEPTH_COMPONENT);
    _SceneDepthTex   ->setExternalFormat(GL_DEPTH_COMPONENT);

    pSceneDepthTexEnv->setEnvMode       (GL_REPLACE       );
    
    TextureBufferUnrecPtr pDepthBuffer   = TextureBuffer::createLocal();
    //pDepthBuffer->setInternalFormat(GL_DEPTH_COMPONENT24   );
    
    pDepthBuffer->setTexture(_SceneDepthTex);

        
    //Color Buffer
    _SceneTex     = TextureObjChunk::createLocal();
    TextureEnvChunkUnrecPtr pSceneTexEnv  = TextureEnvChunk::createLocal();
    ImageUnrecPtr           pImg          = Image          ::createLocal();
    
    pImg->set(Image::OSG_RGB_PF, 
              iPixelWidth, 
              iPixelHeight,
              1,
              1,
              1,
              0.0,
              0,
              Image::OSG_UINT8_IMAGEDATA,
              false);
    
    _SceneTex   ->setImage         (pImg             ); 
    _SceneTex   ->setMinFilter     (GL_LINEAR        );
    _SceneTex   ->setMagFilter     (GL_LINEAR        );
    _SceneTex   ->setWrapS         (GL_CLAMP_TO_EDGE );
    _SceneTex   ->setWrapT         (GL_CLAMP_TO_EDGE );
    _SceneTex   ->setInternalFormat(getColorBufferFormat());

    pSceneTexEnv->setEnvMode       (GL_REPLACE       );
    
    TextureBufferUnrecPtr pSceneTexBuffer   = TextureBuffer::createLocal();
    
    pSceneTexBuffer->setTexture(_SceneTex);
    

    
    pSceneFBO->setSize(iPixelWidth, iPixelHeight);
    
    pSceneFBO->setColorAttachment(pSceneTexBuffer, 0);
    pSceneFBO->setDepthAttachment(pDepthBuffer      );
    
    pSceneFBO->editMFDrawBuffers()->push_back(GL_COLOR_ATTACHMENT0_EXT);
    
    setRenderTarget(pSceneFBO);
    
    // general mat chunk

    //Init all of the render passes
    _PostProcessPasses.clear();
    UInt32 NumPasses(getNumPasses());
    for(UInt32 i(0) ; i != NumPasses ; ++i)
    {
        _PostProcessPasses.push_back(RenderPassData::create(getVertexShaders(i),
                                                            getFragmentShaders(i),
                                                            (i == NumPasses-1),
                                                            i,
                                                            iPixelWidth,
                                                            iPixelHeight,
                                                            returnValue.get(),
                                                            getPassSizes(i),
                                                            _SceneTex,
                                                            _SceneDepthTex,
                                                            _PostProcessPasses,
                                                            pSceneFBO));
    }

    OSG::Thread::resetCurrentLocalFlags();

    Thread::getCurrentChangeList()->commitChanges();

    return returnValue;
}

void PostShaderStage::resizeStageData(PostShaderStageData *pData,
                                      Int32         iPixelWidth,
                                      Int32         iPixelHeight)
{

    //Update the sizes of the passes
    for(RenderPassVector::iterator PassItor(_PostProcessPasses.begin()) ;
        PassItor != _PostProcessPasses.end() ;
        ++PassItor)
    {
        (*PassItor)->updateSize(iPixelWidth, iPixelHeight, _PostProcessPasses);
    }

    //Update the image sizes
    _SceneDepthTex->getImage()->set(Image::OSG_L_PF, 
                                    iPixelWidth, 
                                    iPixelHeight,
                                    1,
                                    1,
                                    1,
                                    0.0,
                                    NULL,
                                    Image::OSG_UINT8_IMAGEDATA,
                                    false);

    _SceneTex->getImage()->set(Image::OSG_RGB_PF, 
                               iPixelWidth, 
                               iPixelHeight,
                               1,
                               1,
                               1,
                               0.0,
                               0,
                               Image::OSG_UINT8_IMAGEDATA,
                               false);

    getRenderTarget()->setSize(iPixelWidth, iPixelHeight);
}

void PostShaderStage::initData(Viewport         *pViewport,
                               RenderActionBase *pAction  )
{
    PostShaderStageDataUnrecPtr pData;// = pAction->getData<PostShaderStageData *>(_iDataSlotId);

    //if(pData == NULL)
    //{
        pData = setupStageData(pViewport->getPixelWidth(),
                               pViewport->getPixelHeight());
        
        pData->setWidth (pViewport->getPixelWidth ());
        pData->setHeight(pViewport->getPixelHeight());

        this->setData(pData, _iDataSlotId, pAction);
    //}
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

void PostShaderStage::postProcess(DrawEnv *pEnv)
{
    Window *win = pEnv->getWindow();

    if(win->hasExtension(_uiFramebuffer_object_extension) == false ||
       win->hasExtension(_extDepthTexture     ) == false)
    {
        FNOTICE(("Framebuffer objects not supported on Window %p!\n", win));
        return;        
    }

    GLDrawBuffersEXTProcT glDrawBuffersEXTProc =
        reinterpret_cast<GLDrawBuffersEXTProcT>(
            win->getFunction(_uiFuncDrawBuffers));

    glColor3f(1.f, 1.f, 1.f);
    
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glLoadIdentity();

    PostShaderStageData *pData = pEnv->getData<PostShaderStageData *>(_iDataSlotId);

    if(pData == NULL)
    {
        return;
    }

    if((pData->getWidth () != pEnv->getPixelWidth() ) ||
       (pData->getHeight() != pEnv->getPixelHeight())  )
    {
        resizeStageData(pData, 
                        pEnv->getPixelWidth(),
                        pEnv->getPixelHeight());
    }

    // PostShader pass
    glDisable(GL_DEPTH_TEST);

    //Render each pass
    for(RenderPassVector::iterator PassItor(_PostProcessPasses.begin()) ;
        PassItor != _PostProcessPasses.end() ;
        ++PassItor)
    {
        (*PassItor)->draw(pEnv, pData);
    }

    glEnable(GL_DEPTH_TEST);

    pEnv->deactivateState();

    glPopMatrix();
}

ActionBase::ResultE PostShaderStage::renderEnter(Action *action)
{
    RenderAction *a = dynamic_cast<RenderAction *>(action);

    a->disableDefaultPartition();

    this->beginPartitionGroup(a);
    {
        this->pushPartition(a);
        {
            RenderPartition   *pPart    = a->getActivePartition();
            FrameBufferObject *pTarget  = this->getRenderTarget();
            Viewport          *pPort    = a->getViewport();
            Camera            *pCam     = a->getCamera  ();
            Background        *pBack    = a->getBackground();
            
            if(pTarget == NULL)
            {
                this->initData(pPort, a);

                pTarget  = this->getRenderTarget();
            }

            pPart->setRenderTarget(pTarget);
            
#ifdef OSG_DEBUGX
            std::string szMessage("RenderPartition\n");
            pPart->setDebugString(szMessage          );
#endif

            if(pPort != NULL)
            {
//                pPart->setViewport(pPort         );
                pPart->setWindow  (a->getWindow());
                
                if(pTarget != NULL)
                {
                    pPart->calcViewportDimension(pPort->getLeft  (),
                                                 pPort->getBottom(),
                                                 pPort->getRight (),
                                                 pPort->getTop   (),
                                                 
                                                 pTarget->getWidth    (),
                                                 pTarget->getHeight   ());
                }
                else
                {
                    pPart->calcViewportDimension(pPort->getLeft  (),
                                                 pPort->getBottom(),
                                                 pPort->getRight (),
                                                 pPort->getTop   (),
                                                 
                                                 a->getWindow()->getWidth (),
                                                 a->getWindow()->getHeight());
                }
                
                if(pCam != NULL)
                {
                    Matrix m, t;
                    
                    // set the projection
                    pCam->getProjection          (m, 
                                                  pPart->getViewportWidth (), 
                                                  pPart->getViewportHeight());
                    
                    pCam->getProjectionTranslation(t, 
                                                   pPart->getViewportWidth (), 
                                                   pPart->getViewportHeight());
                    
                    pPart->setupProjection(m, t);
                    
                    pCam->getViewing(m, 
                                     pPart->getViewportWidth (),
                                     pPart->getViewportHeight());
                    
                    
                    pPart->setupViewing(m);
                    
                    pPart->setNear     (pCam->getNear());
                    pPart->setFar      (pCam->getFar ());
                    
                    pPart->calcFrustum();
                }
                
                pPart->setBackground(pBack);
            }
            
            this->recurseFromThis(a);
        }
        this->popPartition(a);
        
        this->pushPartition(a,
                            (RenderPartition::CopyWindow      |
                             RenderPartition::CopyViewportSize),
                            RenderPartition::SimpleCallback    );
        {
            RenderPartition *pPart  = a->getActivePartition();

#ifdef OSG_DEBUGX
            std::string szMessage("PostProcessPartition\n");
            pPart->setDebugString(szMessage          );
#endif
           
            Matrix m, t;
                
            m.setIdentity();
            t.setIdentity();
                
            MatrixOrthogonal( m,
                              0.f, 1.f,
                              0.f, 1.f,
                             -1.f, 1.f);
            
            pPart->setupProjection(m, t);
                
            RenderPartition::SimpleDrawCallback f;
                
            f = boost::bind(&PostShaderStage::postProcess, this, _1);
                
            pPart->dropFunctor(f);
        }
        this->popPartition(a);
    }
    this->endPartitionGroup(a);

    //Update the uniform parameters to the shader
    for(RenderPassVector::iterator PassItor(_PostProcessPasses.begin()) ;
        PassItor != _PostProcessPasses.end() ;
        ++PassItor)
    {
        (*PassItor)->updateUniformVariables(a);
    }

    return Action::Skip;
}

ActionBase::ResultE PostShaderStage::renderLeave(Action *action)
{
    return Action::Skip;
}

/*----------------------- constructors & destructors ----------------------*/

PostShaderStage::PostShaderStage(void) :
    Inherited()
{
}

PostShaderStage::PostShaderStage(const PostShaderStage &source) :
    Inherited(source)
{
}

PostShaderStage::~PostShaderStage(void)
{
}

/*----------------------------- class specific ----------------------------*/

void PostShaderStage::changed(ConstFieldMaskArg whichField, 
                              UInt32            origin,
                              BitVector         details)
{
    Inherited::changed(whichField, origin, details);
    if(this->getRenderTarget() != NULL)
    {
        if((whichField & (ColorBufferFormatFieldMask |
                          VertexShadersFieldMask |
                          FragmentShadersFieldMask)))
        {
            this->setRenderTarget(NULL);
        }
    }
}

void PostShaderStage::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump PostShaderStage NI" << std::endl;
}

PostShaderStage::RenderPassData::RenderPassData(const std::string& VertexProgram,
                                                const std::string& FragmentProgram,
                                                bool isLastPass,
                                                UInt32 Index,
                                                Int32 iPixelWidth,
                                                Int32 iPixelHeight,
                                                PostShaderStageData *StageData,
                                                const Vec2f& FBOSize,
                                                TextureObjChunk* const SceneColorTex,
                                                TextureObjChunk* const SceneDepthTex,
                                                const RenderPassVector& Passes,
                                                FrameBufferObject* const SceneFBO) : 
                                                    _IsLassPass(isLastPass),
                                                    _Index(Index),
                                                    _FBOSize(FBOSize)
{
    //If this pass is not the last
    if(!_IsLassPass)
    {
        _FBO = FrameBufferObject::createLocal();

        _OutputTexture                   = TextureObjChunk::createLocal();
        TextureEnvChunkUnrecPtr pTexEnv  = TextureEnvChunk::createLocal();
        ImageUnrecPtr           pImg     = Image          ::createLocal();
        
        pImg->set(Image::OSG_RGB_PF, 
                  static_cast<Real32>(iPixelWidth)  * _FBOSize.x() , 
                  static_cast<Real32>(iPixelHeight) * _FBOSize.y(),
                  1,
                  1,
                  1,
                  0.0,
                  0,
                  Image::OSG_UINT8_IMAGEDATA,
                  false);
        
        _OutputTexture   ->setImage         (pImg             ); 
        _OutputTexture   ->setMinFilter     (GL_LINEAR        );
        _OutputTexture   ->setMagFilter     (GL_LINEAR        );
        _OutputTexture   ->setWrapS         (GL_CLAMP_TO_EDGE );
        _OutputTexture   ->setWrapT         (GL_CLAMP_TO_EDGE );
        _OutputTexture   ->setInternalFormat(GL_RGB           );

        pTexEnv->setEnvMode       (GL_REPLACE       );
        
        TextureBufferUnrecPtr pTexBuffer   = TextureBuffer::createLocal();
        
        pTexBuffer->setTexture(_OutputTexture);
        
        _FBO->setSize(static_cast<Real32>(iPixelWidth)  * _FBOSize.x(),
                      static_cast<Real32>(iPixelHeight) * _FBOSize.y());
        _FBO->setColorAttachment(pTexBuffer, 0);
        _FBO->editMFDrawBuffers()->push_back(GL_COLOR_ATTACHMENT0_EXT);

        StageData->pushToRenderTargets(_FBO);
        OSG_ASSERT(StageData->getMFRenderTargets()->size() == _Index+1);
    }
    else
    {
        _FBO = SceneFBO;
    }
    //Update the flags on what uniforms are present
    _ShaderHasSceneColorTex = ((FragmentProgram.find(PostShaderStage::ShaderSceneColorTexName) != std::string::npos) ||
                               (VertexProgram.find(PostShaderStage::ShaderSceneColorTexName) != std::string::npos));

    _ShaderHasSceneDepthTex = ((FragmentProgram.find(PostShaderStage::ShaderSceneDepthTexName) != std::string::npos) ||
                               (VertexProgram.find(PostShaderStage::ShaderSceneDepthTexName) != std::string::npos));

    _ShaderHasFBOWidth = ((FragmentProgram.find(PostShaderStage::ShaderFBOWidthName) != std::string::npos) ||
                          (VertexProgram.find(PostShaderStage::ShaderFBOWidthName) != std::string::npos));

    _ShaderHasFBOHeight = ((FragmentProgram.find(PostShaderStage::ShaderFBOHeightName) != std::string::npos) ||
                          (VertexProgram.find(PostShaderStage::ShaderFBOHeightName) != std::string::npos));

    _ShaderHasCameraNear = ((FragmentProgram.find(PostShaderStage::ShaderCameraNearName) != std::string::npos) ||
                          (VertexProgram.find(PostShaderStage::ShaderCameraNearName) != std::string::npos));

    _ShaderHasCameraFar = ((FragmentProgram.find(PostShaderStage::ShaderCameraFarName) != std::string::npos) ||
                          (VertexProgram.find(PostShaderStage::ShaderCameraFarName) != std::string::npos));

    //Create the material used by this pass
    ChunkMaterialUnrecPtr    pPostShaderMat  = ChunkMaterial  ::createLocal();

    UInt16 TextureId(0);

    _Shader = SimpleSHLChunk::createLocal();

    TextureEnvChunkUnrecPtr pGenericTexEnv  = TextureEnvChunk::createLocal();
    pGenericTexEnv->setEnvMode(GL_REPLACE);

    //Scene Color Texture
    if(_ShaderHasSceneColorTex)
    {
        pPostShaderMat->addChunk(SceneColorTex,       TextureId);
        pPostShaderMat->addChunk(pGenericTexEnv,  TextureId);
        _Shader->addUniformVariable(PostShaderStage::ShaderSceneColorTexName.c_str(), TextureId);
        ++TextureId;
    }
    //Scene Depth Texture
    if(_ShaderHasSceneDepthTex)
    {
        pPostShaderMat->addChunk(SceneDepthTex, TextureId);
        pPostShaderMat->addChunk(pGenericTexEnv, TextureId);
        _Shader->addUniformVariable(PostShaderStage::ShaderSceneDepthTexName.c_str(), TextureId);
        ++TextureId;
    }
    _HeightRefs.clear();
    _WidthRefs.clear();
    //Preceding passes variables
    std::string VariableName;
    for(RenderPassVector::const_iterator PassItor(Passes.begin()) ;
        PassItor != Passes.end() ;
        ++PassItor)
    {
        VariableName = (*PassItor)->getOutputTextureName();
        if((FragmentProgram.find(VariableName) != std::string::npos) ||
           (VertexProgram.find(VariableName) != std::string::npos))
        {
            pPostShaderMat->addChunk((*PassItor)->getOutputTexture(), TextureId);
            pPostShaderMat->addChunk(pGenericTexEnv, TextureId);
            _Shader->addUniformVariable(VariableName.c_str(), TextureId);
            ++TextureId;
        }

        VariableName = (*PassItor)->getWidthName();
        if((FragmentProgram.find(VariableName) != std::string::npos) ||
           (VertexProgram.find(VariableName) != std::string::npos))
        {
            _Shader->addUniformVariable<Real32>(VariableName.c_str(),
                                        (*PassItor)->getOutputTexture()->getImage()->getWidth());
            _WidthRefs.push_back((*PassItor)->getIndex());
        }

        VariableName = (*PassItor)->getHeightName();
        if((FragmentProgram.find(VariableName) != std::string::npos) ||
           (VertexProgram.find(VariableName) != std::string::npos))
        {
            _Shader->addUniformVariable<Real32>(VariableName.c_str(),
                                        (*PassItor)->getOutputTexture()->getImage()->getHeight());
            _HeightRefs.push_back((*PassItor)->getIndex());
        }
    }

    MaterialChunkUnrecPtr pMatChunk = MaterialChunk::createLocal();
    pMatChunk->setLit(false);
    pPostShaderMat->addChunk(pMatChunk);

    _Shader->setVertexProgram(VertexProgram);
    _Shader->setFragmentProgram(FragmentProgram);
    
    //Add the uniform parameters
    _Shader->addUniformVariable(ShaderFBOWidthName.c_str(),   0.0f);
    _Shader->addUniformVariable(ShaderFBOHeightName.c_str(),  0.0f);
    _Shader->addUniformVariable(ShaderCameraNearName.c_str(), 0.0f);
    _Shader->addUniformVariable(ShaderCameraFarName.c_str(),  1.0f);
    
    pPostShaderMat->addChunk(_Shader, 0);
    
    StageData->pushToShaderMaterials(pPostShaderMat);
    OSG_ASSERT(StageData->getMFShaderMaterials()->size() == _Index+1);
}

void PostShaderStage::RenderPassData::updateUniformVariables(RenderAction *action)
{
    if(_ShaderHasFBOWidth)
    {
        _Shader->updateUniformVariable(PostShaderStage::ShaderFBOWidthName.c_str(),
                                       static_cast<Real32>(_FBO->getWidth()));
    }
    if(_ShaderHasFBOHeight)
    {
        _Shader->updateUniformVariable(PostShaderStage::ShaderFBOHeightName.c_str(),
                                       static_cast<Real32>(_FBO->getHeight()));
    }
    if(_ShaderHasCameraNear)
    {
        _Shader->updateUniformVariable(PostShaderStage::ShaderCameraNearName.c_str(),
                                       action->getCamera()->getNear());
    }
    if(_ShaderHasCameraFar)
    {
        _Shader->updateUniformVariable(PostShaderStage::ShaderCameraFarName.c_str(),
                                       action->getCamera()->getFar());
    }
}

void PostShaderStage::RenderPassData::updateSize(Int32 iPixelWidth,
                                                 Int32 iPixelHeight,
                                                 const RenderPassVector& Passes)
{
    if(!_IsLassPass)
    {
        _OutputTexture->getImage()->set(Image::OSG_RGB_PF, 
                                        static_cast<Real32>(iPixelWidth)  * _FBOSize.x(), 
                                        static_cast<Real32>(iPixelHeight) * _FBOSize.y(),
                                        1,
                                        1,
                                        1,
                                        0.0,
                                        0,
                                        Image::OSG_UINT8_IMAGEDATA,
                                        false);

        _FBO->setSize(static_cast<Real32>(iPixelWidth)  * _FBOSize.x(),
                      static_cast<Real32>(iPixelHeight) * _FBOSize.y());
    }
    //Update references to preceding passes
    for(UInt32 i(0) ; i < _WidthRefs.size() ; ++i)
    {
        _Shader->updateUniformVariable<Real32>(Passes[_WidthRefs[i]]->getWidthName().c_str(),
                                               Passes[_WidthRefs[i]]->getOutputTexture()->getImage()->getWidth());
    }
    for(UInt32 i(0) ; i < _HeightRefs.size() ; ++i)
    {
        _Shader->updateUniformVariable<Real32>(Passes[_HeightRefs[i]]->getHeightName().c_str(),
                                               Passes[_HeightRefs[i]]->getOutputTexture()->getImage()->getHeight());
    }
}

void PostShaderStage::RenderPassData::draw(DrawEnv *pEnv,
                                           PostShaderStageData* const StageData)
{
    if(!_IsLassPass)
    {
        StageData->getRenderTargets(_Index)->activate(pEnv);
        glViewport(pEnv->getPixelLeft  (), 
                   pEnv->getPixelBottom(),
                   pEnv->getPixelLeft () +
                   StageData->getRenderTargets(_Index)->getWidth(),
                   pEnv->getPixelBottom() +
                   StageData->getRenderTargets(_Index)->getHeight());
    }
    else
    {
        glViewport(pEnv->getPixelLeft  (), 
                   pEnv->getPixelBottom(),
                   pEnv->getPixelRight (),
                   pEnv->getPixelHeight());
    }


    pEnv->activateState(StageData->getShaderMaterials(_Index)->getState(), NULL);

    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.00, 0.00);
        glVertex2f  (0.00, 0.00);
        
        glTexCoord2f(1.00, 0.00);
        glVertex2f  (1.00, 0.00);
        
        glTexCoord2f(1.00, 1.00);
        glVertex2f  (1.00, 1.00);
        
        glTexCoord2f(0.00, 1.00);
        glVertex2f  (0.00, 1.00);
    }
    glEnd();
            
    if(!_IsLassPass)
    {
        StageData->getRenderTargets(_Index)->deactivate(pEnv);
    }
}

PostShaderStage::RenderPassDataPtr
PostShaderStage::RenderPassData::create(const std::string& VertexProgram,
                                        const std::string& FragmentProgram,
                                        bool isLastPass,
                                        UInt32 Index,
                                        Int32 iPixelWidth,
                                        Int32 iPixelHeight,
                                        PostShaderStageData *StageData,
                                        const Vec2f& FBOSize,
                                        TextureObjChunk* const SceneColorTex,
                                        TextureObjChunk* const SceneDepthTex,
                                        const RenderPassVector& Passes,
                                        FrameBufferObject* const SceneFBO)
{
    return RenderPassDataPtr(new RenderPassData(VertexProgram,
                                                FragmentProgram,
                                                isLastPass,
                                                Index,
                                                iPixelWidth,
                                                iPixelHeight,
                                                StageData,
                                                FBOSize,
                                                SceneColorTex,
                                                SceneDepthTex,
                                                Passes,
                                                SceneFBO));
}

OSG_END_NAMESPACE
