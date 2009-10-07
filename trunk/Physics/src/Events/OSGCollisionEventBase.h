/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
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
 **     class CollisionEvent
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGCOLLISIONEVENTBASE_H_
#define _OSGCOLLISIONEVENTBASE_H_
#ifdef __sgi
#pragma once
#endif


#include <OpenSG/OSGConfig.h>
#include "OSGPhysicsDef.h"

#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGRefPtr.h>
#include <OpenSG/OSGCoredNodePtr.h>

#include <OpenSG/Toolbox/OSGEvent.h> // Parent

#include <OpenSG/OSGPnt3fFields.h> // Position type
#include <OpenSG/OSGVec3fFields.h> // Normal type
#include "ODE/Geom/OSGPhysicsGeomFields.h" // Object1Geom type
#include "ODE/Geom/OSGPhysicsGeomFields.h" // Object2Geom type
#include <OpenSG/OSGVec3fFields.h> // Object1Velocity type
#include <OpenSG/OSGVec3fFields.h> // Object2Velocity type

#include "OSGCollisionEventFields.h"
OSG_BEGIN_NAMESPACE

class CollisionEvent;
class BinaryDataHandler;

//! \brief CollisionEvent Base Class.

class OSG_PHYSICSLIB_DLLMAPPING CollisionEventBase : public Event
{
  private:

    typedef Event    Inherited;

    /*==========================  PUBLIC  =================================*/
  public:

    typedef CollisionEventPtr  Ptr;

    enum
    {
        PositionFieldId        = Inherited::NextFieldId,
        NormalFieldId          = PositionFieldId        + 1,
        Object1GeomFieldId     = NormalFieldId          + 1,
        Object2GeomFieldId     = Object1GeomFieldId     + 1,
        Object1VelocityFieldId = Object2GeomFieldId     + 1,
        Object2VelocityFieldId = Object1VelocityFieldId + 1,
        NextFieldId            = Object2VelocityFieldId + 1
    };

    static const OSG::BitVector PositionFieldMask;
    static const OSG::BitVector NormalFieldMask;
    static const OSG::BitVector Object1GeomFieldMask;
    static const OSG::BitVector Object2GeomFieldMask;
    static const OSG::BitVector Object1VelocityFieldMask;
    static const OSG::BitVector Object2VelocityFieldMask;


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

     const SFPnt3f             *getSFPosition       (void) const;
     const SFVec3f             *getSFNormal         (void) const;
     const SFPhysicsGeomPtr    *getSFObject1Geom    (void) const;
     const SFPhysicsGeomPtr    *getSFObject2Geom    (void) const;
     const SFVec3f             *getSFObject1Velocity(void) const;
     const SFVec3f             *getSFObject2Velocity(void) const;


     const Pnt3f               &getPosition       (void) const;

     const Vec3f               &getNormal         (void) const;

     const PhysicsGeomPtr      &getObject1Geom    (void) const;

     const PhysicsGeomPtr      &getObject2Geom    (void) const;

     const Vec3f               &getObject1Velocity(void) const;

     const Vec3f               &getObject2Velocity(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */


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

    static  CollisionEventPtr      create          (void); 
    static  CollisionEventPtr      createEmpty     (void); 

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
    SFVec3f             _sfNormal;
    SFPhysicsGeomPtr    _sfObject1Geom;
    SFPhysicsGeomPtr    _sfObject2Geom;
    SFVec3f             _sfObject1Velocity;
    SFVec3f             _sfObject2Velocity;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    CollisionEventBase(void);
    CollisionEventBase(const CollisionEventBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~CollisionEventBase(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Get                                 */
    /*! \{                                                                 */

           SFPnt3f             *editSFPosition       (void);
           SFVec3f             *editSFNormal         (void);
           SFPhysicsGeomPtr    *editSFObject1Geom    (void);
           SFPhysicsGeomPtr    *editSFObject2Geom    (void);
           SFVec3f             *editSFObject1Velocity(void);
           SFVec3f             *editSFObject2Velocity(void);

           Pnt3f               &editPosition       (void);
           Vec3f               &editNormal         (void);
           PhysicsGeomPtr      &editObject1Geom    (void);
           PhysicsGeomPtr      &editObject2Geom    (void);
           Vec3f               &editObject1Velocity(void);
           Vec3f               &editObject2Velocity(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

     void setPosition       (const Pnt3f &value);
     void setNormal         (const Vec3f &value);
     void setObject1Geom    (const PhysicsGeomPtr &value);
     void setObject2Geom    (const PhysicsGeomPtr &value);
     void setObject1Velocity(const Vec3f &value);
     void setObject2Velocity(const Vec3f &value);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#if !defined(OSG_FIXED_MFIELDSYNC)
    void executeSyncImpl(      CollisionEventBase *pOther,
                         const BitVector         &whichField);

    virtual void   executeSync(      FieldContainer    &other,
                               const BitVector         &whichField);
#else
    void executeSyncImpl(      CollisionEventBase *pOther,
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
    void operator =(const CollisionEventBase &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------


typedef CollisionEventBase *CollisionEventBaseP;

typedef osgIF<CollisionEventBase::isNodeCore,
              CoredNodePtr<CollisionEvent>,
              FieldContainer::attempt_to_create_CoredNodePtr_on_non_NodeCore_FC
              >::_IRet CollisionEventNodePtr;

typedef RefPtr<CollisionEventPtr> CollisionEventRefPtr;

OSG_END_NAMESPACE

#endif /* _OSGCOLLISIONEVENTBASE_H_ */
