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

#ifndef _OSGPOSTSHADERSTAGE_H_
#define _OSGPOSTSHADERSTAGE_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGPostShaderStageBase.h"

#include "OSGRenderAction.h"
#include "OSGPostShaderStageDataFields.h"
#include "OSGTextureObjChunkFields.h"
#include "OSGSimpleSHLChunk.h"

#include <boost/shared_ptr.hpp>

OSG_BEGIN_NAMESPACE

/*! \brief PostShaderStage class. See \ref
           PageEffectGroupsPostShaderStage for a description.
*/

class OSG_EFFECTGROUPS_DLLMAPPING PostShaderStage : public PostShaderStageBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef PostShaderStageBase Inherited;
    typedef PostShaderStage     Self;

    static const std::string ShaderSceneColorTexName;
    static const std::string ShaderSceneDepthTexName;
    static const std::string ShaderFBOWidthName;
    static const std::string ShaderFBOHeightName;
    static const std::string ShaderCameraNearName;
    static const std::string ShaderCameraFarName;
    static const std::string PrePassXName;
    static const std::string PostPassXColorTexName;
    static const std::string PostPassXColorWidthName;
    static const std::string PostPassXColorHeightName;

    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    virtual void changed(ConstFieldMaskArg whichField,
                         UInt32            origin,
                         BitVector         details    );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual void dump(      UInt32     uiIndent = 0,
                      const BitVector  bvFlags  = 0) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                         GL                                   */
    /*! \{                                                                 */

    static UInt32 _uiFramebuffer_object_extension;
    static UInt32 _extDepthTexture;
    static UInt32 _uiFuncDrawBuffers;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Render Passes                              */
    /*! \{                                                                 */

    UInt32 getNumPasses(void) const;

    void insertPass(UInt32 Index,
                    const std::string& VertexProgram,
                    const std::string& FragmentProgram,
                    Vec2f Size = Vec2f(1.0f, 1.0f));

    void addPass(const std::string& VertexProgram,
                 const std::string& FragmentProgram,
                 Vec2f Size = Vec2f(1.0f, 1.0f));

    void clearPasses(void);

    void erasePass(UInt32 Index);

    SimpleSHLChunk*  getPassShader(UInt32 Index) const;

    /*! \}                                                                 */



    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in PostShaderStageBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    PostShaderStage(void);
    PostShaderStage(const PostShaderStage &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~PostShaderStage(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Stage init                                 */
    /*! \{                                                                 */

    void initData(Viewport         *pViewport,
                  RenderActionBase *pAction  );

    PostShaderStageDataTransitPtr setupStageData (Int32         iPixelWidth,
                                                  Int32         iPixelHeight);

    void                   resizeStageData(PostShaderStageData *pData,
                                           Int32                iPixelWidth,
                                           Int32                iPixelHeight);


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Process                                 */
    /*! \{                                                                 */

    void postProcess(DrawEnv *);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Draw                                       */
    /*! \{                                                                 */

    ActionBase::ResultE renderEnter(Action *action);
    ActionBase::ResultE renderLeave(Action *action);

    /*! \}                                                                 */
    

    class RenderPassData;

    typedef boost::shared_ptr<RenderPassData> RenderPassDataPtr;

    typedef std::vector<RenderPassDataPtr> RenderPassVector;

    class RenderPassData
    {
      public:

        static RenderPassDataPtr create(const std::string& VertexProgram,
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
                                        FrameBufferObject* const SceneFBO);

        void updateUniformVariables(RenderAction *action);
        void updateSize(Int32         iPixelWidth,
                        Int32         iPixelHeight,
                        const RenderPassVector& Passes);
        void draw(DrawEnv *pEnv,
                  PostShaderStageData* const StageData);

        TextureObjChunk* getOutputTexture    (void) const;
        std::string      getOutputTextureName(void) const;
        std::string      getWidthName        (void) const;
        std::string      getHeightName       (void) const;
        bool             getIsLastPass       (void) const;
        SimpleSHLChunk*  getShader           (void) const;
        UInt32           getIndex            (void) const;

      private:
        RenderPassData(const std::string& VertexProgram,
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
                       FrameBufferObject* const SceneFBO
                       );

        // prohibit default functions
        RenderPassData(const RenderPassData&);
        void operator=(const RenderPassData&);

        SimpleSHLChunkUnrecPtr    _Shader;
        FrameBufferObjectUnrecPtr _FBO;
        TextureObjChunkRecPtr     _OutputTexture;
        bool                      _IsLassPass;
        UInt32                    _Index;
        Vec2f                     _FBOSize;
        std::vector<UInt32>       _WidthRefs;
        std::vector<UInt32>       _HeightRefs;

        bool _ShaderHasSceneColorTex,
             _ShaderHasSceneDepthTex,
             _ShaderHasFBOWidth,
             _ShaderHasFBOHeight,
             _ShaderHasCameraNear,
             _ShaderHasCameraFar;
    };

    RenderPassVector  _PostProcessPasses;
    TextureObjChunkRecPtr _SceneTex;
    TextureObjChunkRecPtr _SceneDepthTex;

    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class PostShaderStageBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const PostShaderStage &source);
};

typedef PostShaderStage *PostShaderStageP;

OSG_END_NAMESPACE

#include "OSGPostShaderStageBase.inl"
#include "OSGPostShaderStage.inl"

#endif /* _OSGPOSTSHADERSTAGE_H_ */
