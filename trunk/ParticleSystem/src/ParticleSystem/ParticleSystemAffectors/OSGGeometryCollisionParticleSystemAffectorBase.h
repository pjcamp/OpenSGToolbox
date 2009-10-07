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
 **     class GeometryCollisionParticleSystemAffector
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGGEOMETRYCOLLISIONPARTICLESYSTEMAFFECTORBASE_H_
#define _OSGGEOMETRYCOLLISIONPARTICLESYSTEMAFFECTORBASE_H_
#ifdef __sgi
#pragma once
#endif


#include <OpenSG/OSGConfig.h>
#include "OSGParticleSystemDef.h"

#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGRefPtr.h>
#include <OpenSG/OSGCoredNodePtr.h>

#include "OSGParticleSystemAffector.h" // Parent

#include "ParticleSystem/ParticleAffectors/OSGParticleAffectorFields.h" // CollisionAffectors type
#include <OpenSG/OSGNodeFields.h> // CollisionNode type

#include "OSGGeometryCollisionParticleSystemAffectorFields.h"
#include <OpenSG/Toolbox/OSGEventProducer.h>
#include <OpenSG/Toolbox/OSGEventProducerType.h>
#include <OpenSG/Toolbox/OSGMethodDescription.h>

OSG_BEGIN_NAMESPACE

class GeometryCollisionParticleSystemAffector;
class BinaryDataHandler;

//! \brief GeometryCollisionParticleSystemAffector Base Class.

class OSG_PARTICLESYSTEMLIB_DLLMAPPING GeometryCollisionParticleSystemAffectorBase : public ParticleSystemAffector, public EventProducer
{
  private:

    typedef ParticleSystemAffector    Inherited;
    typedef EventProducer    ProducerInherited;

    /*==========================  PUBLIC  =================================*/
  public:

    typedef GeometryCollisionParticleSystemAffectorPtr  Ptr;

    enum
    {
        CollisionAffectorsFieldId = Inherited::NextFieldId,
        CollisionNodeFieldId      = CollisionAffectorsFieldId + 1,
        NextFieldId               = CollisionNodeFieldId      + 1
    };

    static const OSG::BitVector CollisionAffectorsFieldMask;
    static const OSG::BitVector CollisionNodeFieldMask;


    enum
    {
        ParticleCollisionMethodId = ProducerInherited::NextMethodId,
        NextMethodId              = ParticleCollisionMethodId + 1
    };



    static const OSG::BitVector MTInfluenceMask;

    /*---------------------------------------------------------------------*/
    /*! \name                    Class Get                                 */
    /*! \{                                                                 */

    static        FieldContainerType &getClassType    (void); 
    static        UInt32              getClassTypeId  (void); 
    static const  EventProducerType  &getProducerClassType  (void); 
    static        UInt32              getProducerClassTypeId(void); 

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


           MFParticleAffectorPtr *editMFCollisionAffectors(void);
     const MFParticleAffectorPtr *getMFCollisionAffectors(void) const;

           SFNodePtr           *editSFCollisionNode  (void);
     const SFNodePtr           *getSFCollisionNode  (void) const;


           NodePtr             &editCollisionNode  (void);
     const NodePtr             &getCollisionNode  (void) const;

           ParticleAffectorPtr &editCollisionAffectors(const UInt32 index);
     const ParticleAffectorPtr &getCollisionAffectors(const UInt32 index) const;
#ifndef OSG_2_PREP
           MFParticleAffectorPtr &getCollisionAffectors(void);
     const MFParticleAffectorPtr &getCollisionAffectors(void) const;
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

     void setCollisionNode  ( const NodePtr &value );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Method Produced Get                           */
    /*! \{                                                                 */

    virtual const EventProducerType &getProducerType(void) const; 

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

    static  GeometryCollisionParticleSystemAffectorPtr      create          (void); 
    static  GeometryCollisionParticleSystemAffectorPtr      createEmpty     (void); 

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

    MFParticleAffectorPtr   _mfCollisionAffectors;
    SFNodePtr           _sfCollisionNode;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    GeometryCollisionParticleSystemAffectorBase(void);
    GeometryCollisionParticleSystemAffectorBase(const GeometryCollisionParticleSystemAffectorBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~GeometryCollisionParticleSystemAffectorBase(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#if !defined(OSG_FIXED_MFIELDSYNC)
    void executeSyncImpl(      GeometryCollisionParticleSystemAffectorBase *pOther,
                         const BitVector         &whichField);

    virtual void   executeSync(      FieldContainer    &other,
                               const BitVector         &whichField);
#else
    void executeSyncImpl(      GeometryCollisionParticleSystemAffectorBase *pOther,
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

    static MethodDescription   *_methodDesc[];
    static EventProducerType _producerType;

    static FieldDescription   *_desc[];
    static FieldContainerType  _type;


    // prohibit default functions (move to 'public' if you need one)
    void operator =(const GeometryCollisionParticleSystemAffectorBase &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------


typedef GeometryCollisionParticleSystemAffectorBase *GeometryCollisionParticleSystemAffectorBaseP;

typedef osgIF<GeometryCollisionParticleSystemAffectorBase::isNodeCore,
              CoredNodePtr<GeometryCollisionParticleSystemAffector>,
              FieldContainer::attempt_to_create_CoredNodePtr_on_non_NodeCore_FC
              >::_IRet GeometryCollisionParticleSystemAffectorNodePtr;

typedef RefPtr<GeometryCollisionParticleSystemAffectorPtr> GeometryCollisionParticleSystemAffectorRefPtr;

OSG_END_NAMESPACE

#endif /* _OSGGEOMETRYCOLLISIONPARTICLESYSTEMAFFECTORBASE_H_ */
