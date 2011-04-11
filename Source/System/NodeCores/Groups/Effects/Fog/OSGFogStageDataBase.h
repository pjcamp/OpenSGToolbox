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

/*****************************************************************************\
 *****************************************************************************
 **                                                                         **
 **                  This file is automatically generated.                  **
 **                                                                         **
 **          Any changes made to this file WILL be lost when it is          **
 **           regenerated, which can become necessary at any time.          **
 **                                                                         **
 **     Do not change this file, changes should be done in the derived      **
 **     class FogStageData
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGFOGSTAGEDATABASE_H_
#define _OSGFOGSTAGEDATABASE_H_
#ifdef __sgi
#pragma once
#endif


#include "OSGConfig.h"
#include "OSGEffectGroupsDef.h"

//#include "OSGBaseTypes.h"

#include "OSGStageData.h" // Parent

#include "OSGChunkMaterialFields.h"     // FogMaterial type
#include "OSGSysFields.h"               // Width type
#include "OSGFrameBufferObjectFields.h" // RenderTarget type
#include "OSGCameraFields.h"            // Camera type

#include "OSGFogStageDataFields.h"

OSG_BEGIN_NAMESPACE

class FogStageData;

//! \brief FogStageData Base Class.

class OSG_EFFECTGROUPS_DLLMAPPING FogStageDataBase : public StageData
{
  public:

    typedef StageData Inherited;
    typedef StageData ParentContainer;

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    OSG_GEN_INTERNALPTR(FogStageData);
    
    

    /*==========================  PUBLIC  =================================*/

  public:

    enum
    {
        FogMaterialFieldId = Inherited::NextFieldId,
        WidthFieldId = FogMaterialFieldId + 1,
        HeightFieldId = WidthFieldId + 1,
        RenderTargetFieldId = HeightFieldId + 1,
        CameraFieldId = RenderTargetFieldId + 1,
        NextFieldId = CameraFieldId + 1
    };

    static const OSG::BitVector FogMaterialFieldMask =
        (TypeTraits<BitVector>::One << FogMaterialFieldId);
    static const OSG::BitVector WidthFieldMask =
        (TypeTraits<BitVector>::One << WidthFieldId);
    static const OSG::BitVector HeightFieldMask =
        (TypeTraits<BitVector>::One << HeightFieldId);
    static const OSG::BitVector RenderTargetFieldMask =
        (TypeTraits<BitVector>::One << RenderTargetFieldId);
    static const OSG::BitVector CameraFieldMask =
        (TypeTraits<BitVector>::One << CameraFieldId);
    static const OSG::BitVector NextFieldMask =
        (TypeTraits<BitVector>::One << NextFieldId);
        
    typedef SFUnrecChunkMaterialPtr SFFogMaterialType;
    typedef SFInt32           SFWidthType;
    typedef SFInt32           SFHeightType;
    typedef SFUnrecFrameBufferObjectPtr SFRenderTargetType;
    typedef SFUnrecCameraPtr  SFCameraType;

    /*---------------------------------------------------------------------*/
    /*! \name                    Class Get                                 */
    /*! \{                                                                 */

    static FieldContainerType &getClassType   (void);
    static UInt32              getClassTypeId (void);
    static UInt16              getClassGroupId(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                FieldContainer Get                            */
    /*! \{                                                                 */

    virtual       FieldContainerType &getType         (void);
    virtual const FieldContainerType &getType         (void) const;

    virtual       UInt32              getContainerSize(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Get                                 */
    /*! \{                                                                 */

            const SFUnrecChunkMaterialPtr *getSFFogMaterial    (void) const;
                  SFUnrecChunkMaterialPtr *editSFFogMaterial    (void);

                  SFInt32             *editSFWidth          (void);
            const SFInt32             *getSFWidth           (void) const;

                  SFInt32             *editSFHeight         (void);
            const SFInt32             *getSFHeight          (void) const;
            const SFUnrecFrameBufferObjectPtr *getSFRenderTarget   (void) const;
                  SFUnrecFrameBufferObjectPtr *editSFRenderTarget   (void);
            const SFUnrecCameraPtr    *getSFCamera         (void) const;
                  SFUnrecCameraPtr    *editSFCamera         (void);


                  ChunkMaterial * getFogMaterial    (void) const;

                  Int32               &editWidth          (void);
                  Int32                getWidth           (void) const;

                  Int32               &editHeight         (void);
                  Int32                getHeight          (void) const;

                  FrameBufferObject * getRenderTarget   (void) const;

                  Camera * getCamera         (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

            void setFogMaterial    (ChunkMaterial * const value);
            void setWidth          (const Int32 value);
            void setHeight         (const Int32 value);
            void setRenderTarget   (FrameBufferObject * const value);
            void setCamera         (Camera * const value);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr Field Set                                 */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr MField Set                                */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Binary Access                              */
    /*! \{                                                                 */

    virtual UInt32 getBinSize (ConstFieldMaskArg  whichField);
    virtual void   copyToBin  (BinaryDataHandler &pMem,
                               ConstFieldMaskArg  whichField);
    virtual void   copyFromBin(BinaryDataHandler &pMem,
                               ConstFieldMaskArg  whichField);


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Construction                               */
    /*! \{                                                                 */

    static  FogStageDataTransitPtr  create          (void);
    static  FogStageData           *createEmpty     (void);

    static  FogStageDataTransitPtr  createLocal     (
                                               BitVector bFlags = FCLocal::All);

    static  FogStageData            *createEmptyLocal(
                                              BitVector bFlags = FCLocal::All);

    static  FogStageDataTransitPtr  createDependent  (BitVector bFlags);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Copy                                   */
    /*! \{                                                                 */

    virtual FieldContainerTransitPtr shallowCopy     (void) const;
    virtual FieldContainerTransitPtr shallowCopyLocal(
                                       BitVector bFlags = FCLocal::All) const;
    virtual FieldContainerTransitPtr shallowCopyDependent(
                                                      BitVector bFlags) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    static TypeObject _type;

    static       void   classDescInserter(TypeObject &oType);
    static const Char8 *getClassname     (void             );

    /*---------------------------------------------------------------------*/
    /*! \name                      Fields                                  */
    /*! \{                                                                 */

    SFUnrecChunkMaterialPtr _sfFogMaterial;
    SFInt32           _sfWidth;
    SFInt32           _sfHeight;
    SFUnrecFrameBufferObjectPtr _sfRenderTarget;
    SFUnrecCameraPtr  _sfCamera;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    FogStageDataBase(void);
    FogStageDataBase(const FogStageDataBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~FogStageDataBase(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
    /*! \{                                                                 */

    void onCreate(const FogStageData *source = NULL);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Generic Field Access                      */
    /*! \{                                                                 */

    GetFieldHandlePtr  getHandleFogMaterial     (void) const;
    EditFieldHandlePtr editHandleFogMaterial    (void);
    GetFieldHandlePtr  getHandleWidth           (void) const;
    EditFieldHandlePtr editHandleWidth          (void);
    GetFieldHandlePtr  getHandleHeight          (void) const;
    EditFieldHandlePtr editHandleHeight         (void);
    GetFieldHandlePtr  getHandleRenderTarget    (void) const;
    EditFieldHandlePtr editHandleRenderTarget   (void);
    GetFieldHandlePtr  getHandleCamera          (void) const;
    EditFieldHandlePtr editHandleCamera         (void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#ifdef OSG_MT_CPTR_ASPECT
    virtual void execSyncV(      FieldContainer    &oFrom,
                                 ConstFieldMaskArg  whichField,
                                 AspectOffsetStore &oOffsets,
                                 ConstFieldMaskArg  syncMode  ,
                           const UInt32             uiSyncInfo);

            void execSync (      FogStageDataBase *pFrom,
                                 ConstFieldMaskArg  whichField,
                                 AspectOffsetStore &oOffsets,
                                 ConstFieldMaskArg  syncMode  ,
                           const UInt32             uiSyncInfo);
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Edit                                   */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Aspect Create                            */
    /*! \{                                                                 */

#ifdef OSG_MT_CPTR_ASPECT
    virtual FieldContainer *createAspectCopy(
                                    const FieldContainer *pRefAspect) const;
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Edit                                   */
    /*! \{                                                                 */
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

    virtual void resolveLinks(void);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:
    /*---------------------------------------------------------------------*/

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const FogStageDataBase &source);
};

typedef FogStageDataBase *FogStageDataBaseP;

OSG_END_NAMESPACE

#endif /* _OSGFOGSTAGEDATABASE_H_ */
