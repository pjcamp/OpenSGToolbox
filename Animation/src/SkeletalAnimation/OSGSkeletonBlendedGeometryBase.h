/*---------------------------------------------------------------------------*\
 *                       OpenSG ToolBox Animation                            *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                         www.vrac.iastate.edu                              *
 *                                                                           *
 *                          Authors: David Kabala                            *
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
 **     class SkeletonBlendedGeometry
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGSKELETONBLENDEDGEOMETRYBASE_H_
#define _OSGSKELETONBLENDEDGEOMETRYBASE_H_
#ifdef __sgi
#pragma once
#endif


#include <OpenSG/OSGConfig.h>
#include "OSGAnimationDef.h"

#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGRefPtr.h>
#include <OpenSG/OSGCoredNodePtr.h>

#include <OpenSG/OSGGeometry.h> // Parent

#include <OpenSG/OSGGeometryFields.h> // BaseGeometry type
#include "SkeletalAnimation/OSGBoneFields.h" // Bones type
#include <OpenSG/OSGUInt32Fields.h> // PositionIndexes type
#include <OpenSG/OSGReal32Fields.h> // BlendAmounts type

#include "OSGSkeletonBlendedGeometryFields.h"

OSG_BEGIN_NAMESPACE

class SkeletonBlendedGeometry;
class BinaryDataHandler;

//! \brief SkeletonBlendedGeometry Base Class.

class OSG_ANIMATIONLIB_DLLMAPPING SkeletonBlendedGeometryBase : public Geometry
{
  private:

    typedef Geometry    Inherited;

    /*==========================  PUBLIC  =================================*/
  public:

    typedef SkeletonBlendedGeometryPtr  Ptr;

    enum
    {
        BaseGeometryFieldId    = Inherited::NextFieldId,
        BonesFieldId           = BaseGeometryFieldId    + 1,
        PositionIndexesFieldId = BonesFieldId           + 1,
        BlendAmountsFieldId    = PositionIndexesFieldId + 1,
        NextFieldId            = BlendAmountsFieldId    + 1
    };

    static const OSG::BitVector BaseGeometryFieldMask;     //Field Masks
    static const OSG::BitVector BonesFieldMask;
    static const OSG::BitVector PositionIndexesFieldMask;
    static const OSG::BitVector BlendAmountsFieldMask;


    static const OSG::BitVector MTInfluenceMask;

    /*---------------------------------------------------------------------*/
    /*! \name                    Class Get                                 */
    /*! \{                                                                 */

    static        FieldContainerType &getClassType    (void); 
    static        UInt32              getClassTypeId  (void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                FieldContainer Get                            */
    /*! \{                                                                 */

    virtual       FieldContainerType &getType  (void); 
    virtual const FieldContainerType &getType  (void) const; 

    virtual       UInt32              getContainerSize(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Get                                 */
    /*! \{                                                                 */

           SFGeometryPtr       *getSFBaseGeometry   (void);

           GeometryPtr         &getBaseGeometry   (void);
     const GeometryPtr         &getBaseGeometry   (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

     void setBaseGeometry   ( const GeometryPtr &value );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Binary Access                              */
    /*! \{                                                                 */

    virtual UInt32 getBinSize (const BitVector         &whichField);
    virtual void   copyToBin  (      BinaryDataHandler &pMem,
                               const BitVector         &whichField);
    virtual void   copyFromBin(      BinaryDataHandler &pMem,
                               const BitVector         &whichField);


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Construction                               */
    /*! \{                                                                 */

    static  SkeletonBlendedGeometryPtr      create          (void); 
    static  SkeletonBlendedGeometryPtr      createEmpty     (void); 

    /*! \}                                                                 */

    /*---------------------------------------------------------------------*/
    /*! \name                       Copy                                   */
    /*! \{                                                                 */

    virtual FieldContainerPtr     shallowCopy     (void) const; 

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/
  protected:

    /*---------------------------------------------------------------------*/
    /*! \name                      Fields                                  */
    /*! \{                                                                 */

    SFGeometryPtr       _sfBaseGeometry;
    MFBonePtr           _mfBones;
    MFUInt32            _mfPositionIndexes;
    MFReal32            _mfBlendAmounts;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    SkeletonBlendedGeometryBase(void);
    SkeletonBlendedGeometryBase(const SkeletonBlendedGeometryBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~SkeletonBlendedGeometryBase(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Get                                 */
    /*! \{                                                                 */

           MFBonePtr           *getMFBones          (void);
           MFUInt32            *getMFPositionIndexes(void);
           MFReal32            *getMFBlendAmounts   (void);

           BonePtr             &getBones          (UInt32 index);
           MFBonePtr           &getBones          (void);
     const MFBonePtr           &getBones          (void) const;
           UInt32              &getPositionIndexes(UInt32 index);
           MFUInt32            &getPositionIndexes(void);
     const MFUInt32            &getPositionIndexes(void) const;
           Real32              &getBlendAmounts   (UInt32 index);
           MFReal32            &getBlendAmounts   (void);
     const MFReal32            &getBlendAmounts   (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#if !defined(OSG_FIXED_MFIELDSYNC)
    void executeSyncImpl(      SkeletonBlendedGeometryBase *pOther,
                         const BitVector         &whichField);

    virtual void   executeSync(      FieldContainer    &other,
                               const BitVector         &whichField);
#else
    void executeSyncImpl(      SkeletonBlendedGeometryBase *pOther,
                         const BitVector         &whichField,
                         const SyncInfo          &sInfo     );

    virtual void   executeSync(      FieldContainer    &other,
                               const BitVector         &whichField,
                               const SyncInfo          &sInfo);

    virtual void execBeginEdit     (const BitVector &whichField,
                                          UInt32     uiAspect,
                                          UInt32     uiContainerSize);

            void execBeginEditImpl (const BitVector &whichField,
                                          UInt32     uiAspect,
                                          UInt32     uiContainerSize);

    virtual void onDestroyAspect(UInt32 uiId, UInt32 uiAspect);
#endif

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/
  private:

    friend class FieldContainer;

    static FieldDescription   *_desc[];
    static FieldContainerType  _type;


    // prohibit default functions (move to 'public' if you need one)
    void operator =(const SkeletonBlendedGeometryBase &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------


typedef SkeletonBlendedGeometryBase *SkeletonBlendedGeometryBaseP;

typedef osgIF<SkeletonBlendedGeometryBase::isNodeCore,
              CoredNodePtr<SkeletonBlendedGeometry>,
              FieldContainer::attempt_to_create_CoredNodePtr_on_non_NodeCore_FC
              >::_IRet SkeletonBlendedGeometryNodePtr;

typedef RefPtr<SkeletonBlendedGeometryPtr> SkeletonBlendedGeometryRefPtr;

OSG_END_NAMESPACE

#define OSGSKELETONBLENDEDGEOMETRYBASE_HEADER_CVSID "@(#)$Id: FCBaseTemplate_h.h,v 1.40 2005/07/20 00:10:14 vossg Exp $"

#endif /* _OSGSKELETONBLENDEDGEOMETRYBASE_H_ */
