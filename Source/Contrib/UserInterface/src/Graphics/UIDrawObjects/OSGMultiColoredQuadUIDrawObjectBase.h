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
 **     class MultiColoredQuadUIDrawObject
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGMULTICOLOREDQUADUIDRAWOBJECTBASE_H_
#define _OSGMULTICOLOREDQUADUIDRAWOBJECTBASE_H_
#ifdef __sgi
#pragma once
#endif


#include "OSGConfig.h"
#include "OSGContribUserInterfaceDef.h"

//#include "OSGBaseTypes.h"

#include "OSGUIDrawObject.h" // Parent

#include "OSGVecFields.h"               // Point1 type
#include "OSGBaseFields.h"              // Color1 type
#include "OSGSysFields.h"               // Opacity type

#include "OSGMultiColoredQuadUIDrawObjectFields.h"

OSG_BEGIN_NAMESPACE

class MultiColoredQuadUIDrawObject;

//! \brief MultiColoredQuadUIDrawObject Base Class.

class OSG_CONTRIBUSERINTERFACE_DLLMAPPING MultiColoredQuadUIDrawObjectBase : public UIDrawObject
{
  public:

    typedef UIDrawObject Inherited;
    typedef UIDrawObject ParentContainer;

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    OSG_GEN_INTERNALPTR(MultiColoredQuadUIDrawObject);

    /*==========================  PUBLIC  =================================*/

  public:

    enum
    {
        Point1FieldId = Inherited::NextFieldId,
        Point2FieldId = Point1FieldId + 1,
        Point3FieldId = Point2FieldId + 1,
        Point4FieldId = Point3FieldId + 1,
        Color1FieldId = Point4FieldId + 1,
        Color2FieldId = Color1FieldId + 1,
        Color3FieldId = Color2FieldId + 1,
        Color4FieldId = Color3FieldId + 1,
        OpacityFieldId = Color4FieldId + 1,
        NextFieldId = OpacityFieldId + 1
    };

    static const OSG::BitVector Point1FieldMask =
        (TypeTraits<BitVector>::One << Point1FieldId);
    static const OSG::BitVector Point2FieldMask =
        (TypeTraits<BitVector>::One << Point2FieldId);
    static const OSG::BitVector Point3FieldMask =
        (TypeTraits<BitVector>::One << Point3FieldId);
    static const OSG::BitVector Point4FieldMask =
        (TypeTraits<BitVector>::One << Point4FieldId);
    static const OSG::BitVector Color1FieldMask =
        (TypeTraits<BitVector>::One << Color1FieldId);
    static const OSG::BitVector Color2FieldMask =
        (TypeTraits<BitVector>::One << Color2FieldId);
    static const OSG::BitVector Color3FieldMask =
        (TypeTraits<BitVector>::One << Color3FieldId);
    static const OSG::BitVector Color4FieldMask =
        (TypeTraits<BitVector>::One << Color4FieldId);
    static const OSG::BitVector OpacityFieldMask =
        (TypeTraits<BitVector>::One << OpacityFieldId);
    static const OSG::BitVector NextFieldMask =
        (TypeTraits<BitVector>::One << NextFieldId);
        
    typedef SFPnt2f           SFPoint1Type;
    typedef SFPnt2f           SFPoint2Type;
    typedef SFPnt2f           SFPoint3Type;
    typedef SFPnt2f           SFPoint4Type;
    typedef SFColor4f         SFColor1Type;
    typedef SFColor4f         SFColor2Type;
    typedef SFColor4f         SFColor3Type;
    typedef SFColor4f         SFColor4Type;
    typedef SFReal32          SFOpacityType;

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


                  SFPnt2f             *editSFPoint1         (void);
            const SFPnt2f             *getSFPoint1          (void) const;

                  SFPnt2f             *editSFPoint2         (void);
            const SFPnt2f             *getSFPoint2          (void) const;

                  SFPnt2f             *editSFPoint3         (void);
            const SFPnt2f             *getSFPoint3          (void) const;

                  SFPnt2f             *editSFPoint4         (void);
            const SFPnt2f             *getSFPoint4          (void) const;

                  SFColor4f           *editSFColor1         (void);
            const SFColor4f           *getSFColor1          (void) const;

                  SFColor4f           *editSFColor2         (void);
            const SFColor4f           *getSFColor2          (void) const;

                  SFColor4f           *editSFColor3         (void);
            const SFColor4f           *getSFColor3          (void) const;

                  SFColor4f           *editSFColor4         (void);
            const SFColor4f           *getSFColor4          (void) const;

                  SFReal32            *editSFOpacity        (void);
            const SFReal32            *getSFOpacity         (void) const;


                  Pnt2f               &editPoint1         (void);
            const Pnt2f               &getPoint1          (void) const;

                  Pnt2f               &editPoint2         (void);
            const Pnt2f               &getPoint2          (void) const;

                  Pnt2f               &editPoint3         (void);
            const Pnt2f               &getPoint3          (void) const;

                  Pnt2f               &editPoint4         (void);
            const Pnt2f               &getPoint4          (void) const;

                  Color4f             &editColor1         (void);
            const Color4f             &getColor1          (void) const;

                  Color4f             &editColor2         (void);
            const Color4f             &getColor2          (void) const;

                  Color4f             &editColor3         (void);
            const Color4f             &getColor3          (void) const;

                  Color4f             &editColor4         (void);
            const Color4f             &getColor4          (void) const;

                  Real32              &editOpacity        (void);
                  Real32               getOpacity         (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

            void setPoint1         (const Pnt2f &value);
            void setPoint2         (const Pnt2f &value);
            void setPoint3         (const Pnt2f &value);
            void setPoint4         (const Pnt2f &value);
            void setColor1         (const Color4f &value);
            void setColor2         (const Color4f &value);
            void setColor3         (const Color4f &value);
            void setColor4         (const Color4f &value);
            void setOpacity        (const Real32 value);

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

    static  MultiColoredQuadUIDrawObjectTransitPtr  create          (void);
    static  MultiColoredQuadUIDrawObject           *createEmpty     (void);

    static  MultiColoredQuadUIDrawObjectTransitPtr  createLocal     (
                                               BitVector bFlags = FCLocal::All);

    static  MultiColoredQuadUIDrawObject            *createEmptyLocal(
                                              BitVector bFlags = FCLocal::All);

    static  MultiColoredQuadUIDrawObjectTransitPtr  createDependent  (BitVector bFlags);

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

    SFPnt2f           _sfPoint1;
    SFPnt2f           _sfPoint2;
    SFPnt2f           _sfPoint3;
    SFPnt2f           _sfPoint4;
    SFColor4f         _sfColor1;
    SFColor4f         _sfColor2;
    SFColor4f         _sfColor3;
    SFColor4f         _sfColor4;
    SFReal32          _sfOpacity;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    MultiColoredQuadUIDrawObjectBase(void);
    MultiColoredQuadUIDrawObjectBase(const MultiColoredQuadUIDrawObjectBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~MultiColoredQuadUIDrawObjectBase(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
    /*! \{                                                                 */


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Generic Field Access                      */
    /*! \{                                                                 */

    GetFieldHandlePtr  getHandlePoint1          (void) const;
    EditFieldHandlePtr editHandlePoint1         (void);
    GetFieldHandlePtr  getHandlePoint2          (void) const;
    EditFieldHandlePtr editHandlePoint2         (void);
    GetFieldHandlePtr  getHandlePoint3          (void) const;
    EditFieldHandlePtr editHandlePoint3         (void);
    GetFieldHandlePtr  getHandlePoint4          (void) const;
    EditFieldHandlePtr editHandlePoint4         (void);
    GetFieldHandlePtr  getHandleColor1          (void) const;
    EditFieldHandlePtr editHandleColor1         (void);
    GetFieldHandlePtr  getHandleColor2          (void) const;
    EditFieldHandlePtr editHandleColor2         (void);
    GetFieldHandlePtr  getHandleColor3          (void) const;
    EditFieldHandlePtr editHandleColor3         (void);
    GetFieldHandlePtr  getHandleColor4          (void) const;
    EditFieldHandlePtr editHandleColor4         (void);
    GetFieldHandlePtr  getHandleOpacity         (void) const;
    EditFieldHandlePtr editHandleOpacity        (void);

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

            void execSync (      MultiColoredQuadUIDrawObjectBase *pFrom,
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
    void operator =(const MultiColoredQuadUIDrawObjectBase &source);
};

typedef MultiColoredQuadUIDrawObjectBase *MultiColoredQuadUIDrawObjectBaseP;

OSG_END_NAMESPACE

#endif /* _OSGMULTICOLOREDQUADUIDRAWOBJECTBASE_H_ */
