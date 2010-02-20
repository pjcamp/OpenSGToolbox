/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 *   contact:  David Kabala (djkabala@gmail.com)                             *
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
 **     class TextureLayer
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGTEXTURELAYERBASE_H_
#define _OSGTEXTURELAYERBASE_H_
#ifdef __sgi
#pragma once
#endif


#include "OSGConfig.h"
#include "OSGContribUserInterfaceDef.h"

//#include "OSGBaseTypes.h"

#include "OSGLayer.h" // Parent

#include "OSGTextureObjChunkFields.h"   // Texture type
#include "OSGTextureTransformChunkFields.h" // Transformation type
#include "OSGBaseFields.h"              // Color type
#include "OSGSysFields.h"               // Scale type
#include "OSGVecFields.h"               // ScaleAbsoluteSize type

#include "OSGTextureLayerFields.h"

OSG_BEGIN_NAMESPACE

class TextureLayer;

//! \brief TextureLayer Base Class.

class OSG_CONTRIBUSERINTERFACE_DLLMAPPING TextureLayerBase : public Layer
{
  public:

    typedef Layer Inherited;
    typedef Layer ParentContainer;

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    OSG_GEN_INTERNALPTR(TextureLayer);

    /*==========================  PUBLIC  =================================*/

  public:

    enum
    {
        TextureFieldId = Inherited::NextFieldId,
        TransformationFieldId = TextureFieldId + 1,
        ColorFieldId = TransformationFieldId + 1,
        ScaleFieldId = ColorFieldId + 1,
        ScaleAbsoluteSizeFieldId = ScaleFieldId + 1,
        VerticalAlignmentFieldId = ScaleAbsoluteSizeFieldId + 1,
        HorizontalAlignmentFieldId = VerticalAlignmentFieldId + 1,
        NextFieldId = HorizontalAlignmentFieldId + 1
    };

    static const OSG::BitVector TextureFieldMask =
        (TypeTraits<BitVector>::One << TextureFieldId);
    static const OSG::BitVector TransformationFieldMask =
        (TypeTraits<BitVector>::One << TransformationFieldId);
    static const OSG::BitVector ColorFieldMask =
        (TypeTraits<BitVector>::One << ColorFieldId);
    static const OSG::BitVector ScaleFieldMask =
        (TypeTraits<BitVector>::One << ScaleFieldId);
    static const OSG::BitVector ScaleAbsoluteSizeFieldMask =
        (TypeTraits<BitVector>::One << ScaleAbsoluteSizeFieldId);
    static const OSG::BitVector VerticalAlignmentFieldMask =
        (TypeTraits<BitVector>::One << VerticalAlignmentFieldId);
    static const OSG::BitVector HorizontalAlignmentFieldMask =
        (TypeTraits<BitVector>::One << HorizontalAlignmentFieldId);
    static const OSG::BitVector NextFieldMask =
        (TypeTraits<BitVector>::One << NextFieldId);
        
    typedef SFUnrecTextureObjChunkPtr SFTextureType;
    typedef SFUnrecTextureTransformChunkPtr SFTransformationType;
    typedef SFColor4f         SFColorType;
    typedef SFUInt32          SFScaleType;
    typedef SFVec2s           SFScaleAbsoluteSizeType;
    typedef SFReal32          SFVerticalAlignmentType;
    typedef SFReal32          SFHorizontalAlignmentType;

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

            const SFUnrecTextureObjChunkPtr *getSFTexture        (void) const;
                  SFUnrecTextureObjChunkPtr *editSFTexture        (void);
            const SFUnrecTextureTransformChunkPtr *getSFTransformation (void) const;
                  SFUnrecTextureTransformChunkPtr *editSFTransformation (void);

                  SFColor4f           *editSFColor          (void);
            const SFColor4f           *getSFColor           (void) const;

                  SFUInt32            *editSFScale          (void);
            const SFUInt32            *getSFScale           (void) const;

                  SFVec2s             *editSFScaleAbsoluteSize(void);
            const SFVec2s             *getSFScaleAbsoluteSize (void) const;

                  SFReal32            *editSFVerticalAlignment(void);
            const SFReal32            *getSFVerticalAlignment (void) const;

                  SFReal32            *editSFHorizontalAlignment(void);
            const SFReal32            *getSFHorizontalAlignment (void) const;


                  TextureObjChunk * getTexture        (void) const;

                  TextureTransformChunk * getTransformation (void) const;

                  Color4f             &editColor          (void);
            const Color4f             &getColor           (void) const;

                  UInt32              &editScale          (void);
                  UInt32               getScale           (void) const;

                  Vec2s               &editScaleAbsoluteSize(void);
            const Vec2s               &getScaleAbsoluteSize (void) const;

                  Real32              &editVerticalAlignment(void);
                  Real32               getVerticalAlignment (void) const;

                  Real32              &editHorizontalAlignment(void);
                  Real32               getHorizontalAlignment (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

            void setTexture        (TextureObjChunk * const value);
            void setTransformation (TextureTransformChunk * const value);
            void setColor          (const Color4f &value);
            void setScale          (const UInt32 value);
            void setScaleAbsoluteSize(const Vec2s &value);
            void setVerticalAlignment(const Real32 value);
            void setHorizontalAlignment(const Real32 value);

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

    static  TextureLayerTransitPtr  create          (void);
    static  TextureLayer           *createEmpty     (void);

    static  TextureLayerTransitPtr  createLocal     (
                                               BitVector bFlags = FCLocal::All);

    static  TextureLayer            *createEmptyLocal(
                                              BitVector bFlags = FCLocal::All);

    static  TextureLayerTransitPtr  createDependent  (BitVector bFlags);

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

    SFUnrecTextureObjChunkPtr _sfTexture;
    SFUnrecTextureTransformChunkPtr _sfTransformation;
    SFColor4f         _sfColor;
    SFUInt32          _sfScale;
    SFVec2s           _sfScaleAbsoluteSize;
    SFReal32          _sfVerticalAlignment;
    SFReal32          _sfHorizontalAlignment;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    TextureLayerBase(void);
    TextureLayerBase(const TextureLayerBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~TextureLayerBase(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
    /*! \{                                                                 */

    void onCreate(const TextureLayer *source = NULL);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Generic Field Access                      */
    /*! \{                                                                 */

    GetFieldHandlePtr  getHandleTexture         (void) const;
    EditFieldHandlePtr editHandleTexture        (void);
    GetFieldHandlePtr  getHandleTransformation  (void) const;
    EditFieldHandlePtr editHandleTransformation (void);
    GetFieldHandlePtr  getHandleColor           (void) const;
    EditFieldHandlePtr editHandleColor          (void);
    GetFieldHandlePtr  getHandleScale           (void) const;
    EditFieldHandlePtr editHandleScale          (void);
    GetFieldHandlePtr  getHandleScaleAbsoluteSize (void) const;
    EditFieldHandlePtr editHandleScaleAbsoluteSize(void);
    GetFieldHandlePtr  getHandleVerticalAlignment (void) const;
    EditFieldHandlePtr editHandleVerticalAlignment(void);
    GetFieldHandlePtr  getHandleHorizontalAlignment (void) const;
    EditFieldHandlePtr editHandleHorizontalAlignment(void);

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

            void execSync (      TextureLayerBase *pFrom,
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
    void operator =(const TextureLayerBase &source);
};

typedef TextureLayerBase *TextureLayerBaseP;

OSG_END_NAMESPACE

#endif /* _OSGTEXTURELAYERBASE_H_ */
