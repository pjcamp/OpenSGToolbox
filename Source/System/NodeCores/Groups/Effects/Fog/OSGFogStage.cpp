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

#include "OSGAction.h"
#include "OSGCamera.h"
#include "OSGRenderAction.h"
#include "OSGSceneFileHandler.h"
#include "OSGVolumeDraw.h"

#include "OSGFogStage.h"
#include "OSGFogStageData.h"

#include "OSGFrameBufferObject.h"
#include "OSGFrameBufferAttachment.h"
#include "OSGRenderBuffer.h"
#include "OSGTextureBuffer.h"

#include "OSGChunkMaterial.h"
#include "OSGMaterialChunk.h"
#include "OSGTextureObjChunk.h"
#include "OSGDrawEnv.h"
#include "OSGImageFunctions.h"
#include "OSGStateOverride.h"
#include "OSGTextureEnvChunk.h"
#include "OSGSimpleSHLFunctions.h"
#include "OSGGL.h"

#include "OSGMatrixUtility.h"

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGFogStageBase.cpp file.
// To modify it, please change the .fcd file (OSGFogStage.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/
UInt32 FogStage::_uiFramebuffer_object_extension = Window::invalidExtensionID;
UInt32 FogStage::_extDepthTexture      = Window::invalidExtensionID;

UInt32 FogStage::_uiFuncDrawBuffers = Window::invalidFunctionID;

typedef void   (OSG_APIENTRY *GLDrawBuffersEXTProcT)(GLsizei  n, 
                                                     const GLenum  *buffers);

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void FogStage::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
        RenderAction::registerEnterDefault(
            FogStage::getClassType(), 
            reinterpret_cast<Action::Callback>(&FogStage::renderEnter));
        
        RenderAction::registerLeaveDefault( 
            FogStage::getClassType(), 
            reinterpret_cast<Action::Callback>(&FogStage::renderLeave));

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

FogStageDataTransitPtr FogStage::setupStageData(Int32 iPixelWidth,
                                                Int32 iPixelHeight)
{
    FogStageDataTransitPtr returnValue = FogStageData::createLocal();

    if(returnValue == NULL)
        return returnValue;

    OSG::Thread::setCurrentLocalFlags();

    // Scene Target

    FrameBufferObjectUnrecPtr pSceneFBO    = FrameBufferObject::createLocal();
        
    //Depth texture
    TextureObjChunkUnrecPtr pSceneDepthTex     = TextureObjChunk::createLocal();
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

    pSceneDepthTex   ->setImage         (pDepthImg        ); 
    pSceneDepthTex   ->setMinFilter     (GL_LINEAR        );
    pSceneDepthTex   ->setMagFilter     (GL_LINEAR        );
    pSceneDepthTex   ->setWrapS         (GL_CLAMP_TO_EDGE );
    pSceneDepthTex   ->setWrapT         (GL_CLAMP_TO_EDGE );
    pSceneDepthTex   ->setInternalFormat(GL_DEPTH_COMPONENT);
    pSceneDepthTex   ->setExternalFormat(GL_DEPTH_COMPONENT);

    pSceneDepthTexEnv->setEnvMode       (GL_REPLACE       );
    
    TextureBufferUnrecPtr pDepthBuffer   = TextureBuffer::createLocal();
    //pDepthBuffer->setInternalFormat(GL_DEPTH_COMPONENT24   );
    
    pDepthBuffer->setTexture(pSceneDepthTex);

        
    TextureObjChunkUnrecPtr pSceneTex     = TextureObjChunk::createLocal();
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
              Image::OSG_FLOAT32_IMAGEDATA,
              false);
    
    pSceneTex   ->setImage         (pImg             ); 
    pSceneTex   ->setMinFilter     (GL_LINEAR        );
    pSceneTex   ->setMagFilter     (GL_LINEAR        );
    pSceneTex   ->setWrapS         (GL_CLAMP_TO_EDGE );
    pSceneTex   ->setWrapT         (GL_CLAMP_TO_EDGE );
    pSceneTex   ->setInternalFormat(getBufferFormat());

    pSceneTexEnv->setEnvMode       (GL_REPLACE       );
    
    TextureBufferUnrecPtr pSceneTexBuffer   = TextureBuffer::createLocal();
    
    pSceneTexBuffer->setTexture(pSceneTex);
    

    
    pSceneFBO->setSize(iPixelWidth, iPixelHeight);
    
    pSceneFBO->setColorAttachment(pSceneTexBuffer, 0);
    pSceneFBO->setDepthAttachment(pDepthBuffer      );
    
    pSceneFBO->editMFDrawBuffers()->push_back(GL_COLOR_ATTACHMENT0_EXT);
    
    setRenderTarget(pSceneFBO);
    
    // general mat chunk
    MaterialChunkUnrecPtr pMatChunk = MaterialChunk::createLocal();
        
    pMatChunk->setLit(false);




    //Fog material
    ChunkMaterialUnrecPtr    pFogMat  = ChunkMaterial  ::createLocal();
    
    pFogMat->addChunk(pMatChunk         );
    pFogMat->addChunk(pSceneTex,       0);
    pFogMat->addChunk(pSceneTexEnv,    0);
    pFogMat->addChunk(pSceneDepthTex,       1);
    pFogMat->addChunk(pSceneDepthTexEnv,    1);

    _FogShader = generateFogFragmentProgram();
    
    _FogShader->addUniformVariable("sceneTex",    0);
    _FogShader->addUniformVariable("depthTex",    1);
    _FogShader->addUniformVariable("nearPlane",   0.0f);
    _FogShader->addUniformVariable("farPlane",    1.0f);
    _FogShader->addUniformVariable("fogColor",    getFogColor());
    _FogShader->addUniformVariable("fogStart",    getFogStart());
    _FogShader->addUniformVariable("fogEnd",      getFogEnd());
    _FogShader->addUniformVariable("fogDensity",  getFogDensity());
    _FogShader->addUniformVariable<int>("fogMode",     getFogMode());
    
    pFogMat->addChunk(_FogShader, 0);
    
    returnValue->setFogMaterial(pFogMat);

    OSG::Thread::resetCurrentLocalFlags();

    Thread::getCurrentChangeList()->commitChanges();

    return returnValue;
}

void FogStage::resizeStageData(FogStageData *pData,
                               Int32         iPixelWidth,
                               Int32         iPixelHeight)
{
    FWARNING(("FogStage resize not implemented ==> wrong results\n"));
}

void FogStage::postProcess(DrawEnv *pEnv)
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

    FogStageData *pData = pEnv->getData<FogStageData *>(_iDataSlotId);

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

    // Fog pass
    glDisable(GL_DEPTH_TEST);

    glViewport(pEnv->getPixelLeft  (), 
               pEnv->getPixelBottom(),
               pEnv->getPixelWidth (),
               pEnv->getPixelHeight());

    ChunkMaterial *pTCM = pData->getFogMaterial();

    State *pTState = pTCM->getState();
        
    pEnv->activateState(pTState, NULL);
            
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

    glEnable(GL_DEPTH_TEST);
            
    pEnv->deactivateState();

    glPopMatrix();
}

void FogStage::initData(Viewport         *pViewport,
                        RenderActionBase *pAction  )
{
    FogStageDataUnrecPtr pData;// = pAction->getData<FogStageData *>(_iDataSlotId);

    //if(pData == NULL)
    //{
        pData = setupStageData(pViewport->getPixelWidth(),
                               pViewport->getPixelHeight());
        
        pData->setWidth (pViewport->getPixelWidth ());
        pData->setHeight(pViewport->getPixelHeight());

        this->setData(pData, _iDataSlotId, pAction);
    //}
}

#define OSGFogL << std::endl

SimpleSHLChunkTransitPtr FogStage::generateFogFragmentProgram(void)
{
    std::ostringstream ost;

    ost << "uniform sampler2D sceneTex;"                                 OSGFogL
        << "uniform sampler2D depthTex;"                                  OSGFogL
        << "uniform float     nearPlane;"                                 OSGFogL
        << "uniform float     farPlane;"                               OSGFogL
        << "uniform vec4      fogColor;"                               OSGFogL
        << "uniform float     fogStart;"                               OSGFogL
        << "uniform float     fogEnd;"                               OSGFogL
        << "uniform float     fogDensity;"                               OSGFogL
        << "uniform int     fogMode;"                               OSGFogL
        << ""                                                            OSGFogL
        << "void main(void)"                                             OSGFogL
        << "{"                                                           OSGFogL
        << "    vec4 scene   = texture2D(sceneTex, gl_TexCoord[0].xy);"  OSGFogL
        << "    vec4 depthSample = texture2D( depthTex, gl_TexCoord[0].st );"  OSGFogL
        << ""                                                            OSGFogL
        << "    float depth = depthSample.x * 255.0 / 256.0 +"  OSGFogL
        << "                  depthSample.y * 255.0 / 65536.0 +"  OSGFogL
        << "                  depthSample.z * 255.0 / 16777216.0;"  OSGFogL
        << "    float zDistance = (nearPlane * farPlane) / (farPlane - depth * (farPlane - nearPlane));"  OSGFogL
        << "    const float LOG2 = 1.442695;"                                       OSGFogL
        << "    float fogFactor  = 1.0;"                                       OSGFogL
        << "    if(fogMode == 1)"                                       OSGFogL
        << "    {"                                       OSGFogL
        << "        fogFactor  = (depth - fogStart)/(fogEnd - fogStart);"                                       OSGFogL
        << "    }"                                       OSGFogL
        << "    else if(fogMode == 2)"                                       OSGFogL
        << "    {"                                       OSGFogL
        << "        fogFactor  = exp2( -fogDensity * "                                       OSGFogL
        << "                              zDistance     * "                                       OSGFogL
        << "                              LOG2);"                                       OSGFogL
        << "    }"                                       OSGFogL
        << "    else if(fogMode == 3)"                                       OSGFogL
        << "    {"                                       OSGFogL
        << "        fogFactor  = exp2( -fogDensity * "                                       OSGFogL
        << "                              fogDensity * "                                       OSGFogL
        << "                              zDistance      * "                                       OSGFogL
        << "                              zDistance     * "                                       OSGFogL
        << "                              LOG2);"                                       OSGFogL
        << "    }"                                       OSGFogL
        << "    fogFactor = clamp(fogFactor, 0.0, 1.0);"                                       OSGFogL
        << "    gl_FragColor = vec4( mix( fogColor.rgb, scene.rgb,fogFactor), 1.0);"                                       OSGFogL
        << "}"                                                           OSGFogL
        << "";

    SimpleSHLChunkTransitPtr returnValue = SimpleSHLChunk::createLocal();

    returnValue->setFragmentProgram(ost.str());

    return returnValue;
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
/*                                Draw                                     */

/*!
  Draw loaded geometry. If nothing was loaded until now, start
  loading. If loading is not finished, draw the children of 
  thid group.
 */

ActionBase::ResultE FogStage::renderEnter(Action *action)
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
                
            f = boost::bind(&FogStage::postProcess, this, _1);
                
            pPart->dropFunctor(f);
        }
        this->popPartition(a);
    }
    this->endPartitionGroup(a);

    _FogShader->updateUniformVariable("nearPlane",   a->getCamera()->getNear());
    _FogShader->updateUniformVariable("farPlane",    a->getCamera()->getFar());

    return Action::Skip;
}

ActionBase::ResultE FogStage::renderLeave(Action *action)
{
    return Action::Skip;
}

/*----------------------- constructors & destructors ----------------------*/

FogStage::FogStage(void) :
    Inherited()
{
}

FogStage::FogStage(const FogStage &source) :
    Inherited(source)
{
}

FogStage::~FogStage(void)
{
}

/*----------------------------- class specific ----------------------------*/

void FogStage::changed(ConstFieldMaskArg whichField, 
                            UInt32            origin,
                            BitVector         details)
{
    Inherited::changed(whichField, origin, details);
    if(this->getRenderTarget() != NULL)
    {
        if((whichField & BufferFormatFieldMask))
        {
            this->setRenderTarget(NULL);
        }
    }

    if(_FogShader != NULL)
    {
        if(whichField & FogColorFieldMask)
        {
            _FogShader->updateUniformVariable("fogColor", getFogColor());
        }
        if(whichField & FogModeFieldMask)
        {
            _FogShader->updateUniformVariable<int>("fogMode", getFogMode());
        }
        if(whichField & FogStartFieldMask)
        {
            _FogShader->updateUniformVariable("fogStart", getFogStart());
        }
        if(whichField & FogEndFieldMask)
        {
            _FogShader->updateUniformVariable("fogEnd", getFogEnd());
        }
        if(whichField & FogDensityFieldMask)
        {
            _FogShader->updateUniformVariable("fogDensity", getFogDensity());
        }
    }
}

void FogStage::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump FogStage NI" << std::endl;
}

OSG_END_NAMESPACE
