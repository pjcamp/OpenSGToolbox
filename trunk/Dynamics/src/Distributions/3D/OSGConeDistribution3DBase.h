/*---------------------------------------------------------------------------*\
 *                        OpenSG ToolBox Dynamics                            *
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
 **     class ConeDistribution3D
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGCONEDISTRIBUTION3DBASE_H_
#define _OSGCONEDISTRIBUTION3DBASE_H_
#ifdef __sgi
#pragma once
#endif


#include <OpenSG/OSGConfig.h>
#include "OSGDynamicsDef.h"

#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGRefPtr.h>
#include <OpenSG/OSGCoredNodePtr.h>

#include "Function/OSGFunction.h" // Parent

#include <OpenSG/OSGPnt3fFields.h> // Position type
#include <OpenSG/OSGVec3fFields.h> // Direction type
#include <OpenSG/OSGReal32Fields.h> // Spread type
#include <OpenSG/OSGReal32Fields.h> // Min type
#include <OpenSG/OSGReal32Fields.h> // Max type
#include <OpenSG/OSGUInt32Fields.h> // SurfaceOrVolume type

#include "OSGConeDistribution3DFields.h"

OSG_BEGIN_NAMESPACE

class ConeDistribution3D;
class BinaryDataHandler;

//! \brief ConeDistribution3D Base Class.

class OSG_DYNAMICSLIB_DLLMAPPING ConeDistribution3DBase : public Function
{
  private:

    typedef Function    Inherited;

    /*==========================  PUBLIC  =================================*/
  public:

    typedef ConeDistribution3DPtr  Ptr;

    enum
    {
        PositionFieldId        = Inherited::NextFieldId,
        DirectionFieldId       = PositionFieldId        + 1,
        SpreadFieldId          = DirectionFieldId       + 1,
        MinFieldId             = SpreadFieldId          + 1,
        MaxFieldId             = MinFieldId             + 1,
        SurfaceOrVolumeFieldId = MaxFieldId             + 1,
        NextFieldId            = SurfaceOrVolumeFieldId + 1
    };

    static const OSG::BitVector PositionFieldMask;
    static const OSG::BitVector DirectionFieldMask;
    static const OSG::BitVector SpreadFieldMask;
    static const OSG::BitVector MinFieldMask;
    static const OSG::BitVector MaxFieldMask;
    static const OSG::BitVector SurfaceOrVolumeFieldMask;


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

           SFPnt3f             *getSFPosition       (void);
           SFVec3f             *getSFDirection      (void);
           SFReal32            *getSFSpread         (void);
           SFReal32            *getSFMin            (void);
           SFReal32            *getSFMax            (void);
           SFUInt32            *getSFSurfaceOrVolume(void);

           Pnt3f               &getPosition       (void);
     const Pnt3f               &getPosition       (void) const;
           Vec3f               &getDirection      (void);
     const Vec3f               &getDirection      (void) const;
           Real32              &getSpread         (void);
     const Real32              &getSpread         (void) const;
           Real32              &getMin            (void);
     const Real32              &getMin            (void) const;
           Real32              &getMax            (void);
     const Real32              &getMax            (void) const;
           UInt32              &getSurfaceOrVolume(void);
     const UInt32              &getSurfaceOrVolume(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

     void setPosition       ( const Pnt3f &value );
     void setDirection      ( const Vec3f &value );
     void setSpread         ( const Real32 &value );
     void setMin            ( const Real32 &value );
     void setMax            ( const Real32 &value );
     void setSurfaceOrVolume( const UInt32 &value );

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

    static  ConeDistribution3DPtr      create          (void); 
    static  ConeDistribution3DPtr      createEmpty     (void); 

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

    SFPnt3f             _sfPosition;
    SFVec3f             _sfDirection;
    SFReal32            _sfSpread;
    SFReal32            _sfMin;
    SFReal32            _sfMax;
    SFUInt32            _sfSurfaceOrVolume;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    ConeDistribution3DBase(void);
    ConeDistribution3DBase(const ConeDistribution3DBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~ConeDistribution3DBase(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#if !defined(OSG_FIXED_MFIELDSYNC)
    void executeSyncImpl(      ConeDistribution3DBase *pOther,
                         const BitVector         &whichField);

    virtual void   executeSync(      FieldContainer    &other,
                               const BitVector         &whichField);
#else
    void executeSyncImpl(      ConeDistribution3DBase *pOther,
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
    void operator =(const ConeDistribution3DBase &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------


typedef ConeDistribution3DBase *ConeDistribution3DBaseP;

typedef osgIF<ConeDistribution3DBase::isNodeCore,
              CoredNodePtr<ConeDistribution3D>,
              FieldContainer::attempt_to_create_CoredNodePtr_on_non_NodeCore_FC
              >::_IRet ConeDistribution3DNodePtr;

typedef RefPtr<ConeDistribution3DPtr> ConeDistribution3DRefPtr;

OSG_END_NAMESPACE

#define OSGCONEDISTRIBUTION3DBASE_HEADER_CVSID "@(#)$Id: FCBaseTemplate_h.h,v 1.40 2005/07/20 00:10:14 vossg Exp $"

#endif /* _OSGCONEDISTRIBUTION3DBASE_H_ */