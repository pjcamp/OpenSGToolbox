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

#include "OSGAction.h"
#include "OSGPostShaderStageDataFields.h"
#include "OSGTextureObjChunkFields.h"
#include "OSGSimpleSHLChunk.h"

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
    /*! \name                      Process                                 */
    /*! \{                                                                 */

    void postProcess(DrawEnv *);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                        Init                                  */
    /*! \{                                                                 */

    void initData(Viewport         *pViewport,
                  RenderActionBase *pAction  );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                         GL                                   */
    /*! \{                                                                 */

    static UInt32 _uiFramebuffer_object_extension;
    static UInt32 _extDepthTexture;
    static UInt32 _uiFuncDrawBuffers;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Draw                                       */
    /*! \{                                                                 */

    ActionBase::ResultE renderEnter(Action *action);
    ActionBase::ResultE renderLeave(Action *action);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Stage init                                 */
    /*! \{                                                                 */

    PostShaderStageDataTransitPtr setupStageData (Int32         iPixelWidth,
                                                  Int32         iPixelHeight);

    void                   resizeStageData(PostShaderStageData *pData,
                                           Int32                iPixelWidth,
                                           Int32                iPixelHeight);


    /*! \}                                                                 */
    SimpleSHLChunk*  getShader(void) const;

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
    
    SimpleSHLChunkUnrecPtr  _PostProcessShader;
    TextureObjChunkRecPtr _SceneTex;
    TextureObjChunkRecPtr _SceneDepthTex;

    bool _ShaderHasSceneColorTex,
         _ShaderHasSceneDepthTex,
         _ShaderHasFBOWidth,
         _ShaderHasFBOHeight,
         _ShaderHasCameraNear,
         _ShaderHasCameraFar;

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
