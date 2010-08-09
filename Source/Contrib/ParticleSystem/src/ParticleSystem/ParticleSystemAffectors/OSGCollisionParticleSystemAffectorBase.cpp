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
 **     class CollisionParticleSystemAffector!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"


#include "OSGParticleCollisionEventDetails.h"


#include "OSGParticleSystem.h"          // SecondaryCollisionSystems Class

#include "OSGCollisionParticleSystemAffectorBase.h"
#include "OSGCollisionParticleSystemAffector.h"

#include <boost/bind.hpp>

#include "OSGEventDetails.h"

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::CollisionParticleSystemAffector
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Real32          CollisionParticleSystemAffectorBase::_sfCollisionDistance
    
*/

/*! \var ParticleSystem * CollisionParticleSystemAffectorBase::_mfSecondaryCollisionSystems
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<CollisionParticleSystemAffector *>::_type("CollisionParticleSystemAffectorPtr", "ParticleSystemAffectorPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(CollisionParticleSystemAffector *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           CollisionParticleSystemAffector *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           CollisionParticleSystemAffector *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void CollisionParticleSystemAffectorBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFReal32::Description(
        SFReal32::getClassType(),
        "CollisionDistance",
        "",
        CollisionDistanceFieldId, CollisionDistanceFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&CollisionParticleSystemAffector::editHandleCollisionDistance),
        static_cast<FieldGetMethodSig >(&CollisionParticleSystemAffector::getHandleCollisionDistance));

    oType.addInitialDesc(pDesc);

    pDesc = new MFUnrecParticleSystemPtr::Description(
        MFUnrecParticleSystemPtr::getClassType(),
        "SecondaryCollisionSystems",
        "",
        SecondaryCollisionSystemsFieldId, SecondaryCollisionSystemsFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&CollisionParticleSystemAffector::editHandleSecondaryCollisionSystems),
        static_cast<FieldGetMethodSig >(&CollisionParticleSystemAffector::getHandleSecondaryCollisionSystems));

    oType.addInitialDesc(pDesc);
}


CollisionParticleSystemAffectorBase::TypeObject CollisionParticleSystemAffectorBase::_type(
    CollisionParticleSystemAffectorBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&CollisionParticleSystemAffectorBase::createEmptyLocal),
    CollisionParticleSystemAffector::initMethod,
    CollisionParticleSystemAffector::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&CollisionParticleSystemAffector::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"CollisionParticleSystemAffector\"\n"
    "\tparent=\"ParticleSystemAffector\"\n"
    "    library=\"ContribParticleSystem\"\n"
    "    pointerfieldtypes=\"both\"\n"
    "\tstructure=\"concrete\"\n"
    "    systemcomponent=\"true\"\n"
    "    parentsystemcomponent=\"true\"\n"
    "    decoratable=\"false\"\n"
    "    useLocalIncludes=\"false\"\n"
    "    isNodeCore=\"false\"\n"
    "    authors=\"David Kabala (djkabala@gmail.com)                             \"\n"
    ">\n"
    "\t<Field\n"
    "\t\tname=\"CollisionDistance\"\n"
    "\t\ttype=\"Real32\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"0.0f\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"SecondaryCollisionSystems\"\n"
    "\t\ttype=\"ParticleSystem\"\n"
    "        category=\"pointer\"\n"
    "\t\tcardinality=\"multi\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<ProducedEvent\n"
    "\t\tname=\"ParticleCollision\"\n"
    "\t\tdetailsType=\"ParticleCollisionEventDetails\"\n"
    "\t\tconsumable=\"true\"\n"
    "\t>\n"
    "\t</ProducedEvent>\n"
    "</FieldContainer>\n",
    ""
    );

//! CollisionParticleSystemAffector Produced Events

EventDescription *CollisionParticleSystemAffectorBase::_eventDesc[] =
{
    new EventDescription("ParticleCollision", 
                          "",
                          ParticleCollisionEventId, 
                          FieldTraits<ParticleCollisionEventDetails *>::getType(),
                          true,
                          static_cast<EventGetMethod>(&CollisionParticleSystemAffectorBase::getHandleParticleCollisionSignal))

};

EventProducerType CollisionParticleSystemAffectorBase::_producerType(
    "CollisionParticleSystemAffectorProducerType",
    "EventProducerType",
    "",
    InitEventProducerFunctor(),
    _eventDesc,
    sizeof(_eventDesc));

/*------------------------------ get -----------------------------------*/

FieldContainerType &CollisionParticleSystemAffectorBase::getType(void)
{
    return _type;
}

const FieldContainerType &CollisionParticleSystemAffectorBase::getType(void) const
{
    return _type;
}

const EventProducerType &CollisionParticleSystemAffectorBase::getProducerType(void) const
{
    return _producerType;
}

UInt32 CollisionParticleSystemAffectorBase::getContainerSize(void) const
{
    return sizeof(CollisionParticleSystemAffector);
}

/*------------------------- decorator get ------------------------------*/


SFReal32 *CollisionParticleSystemAffectorBase::editSFCollisionDistance(void)
{
    editSField(CollisionDistanceFieldMask);

    return &_sfCollisionDistance;
}

const SFReal32 *CollisionParticleSystemAffectorBase::getSFCollisionDistance(void) const
{
    return &_sfCollisionDistance;
}


//! Get the CollisionParticleSystemAffector::_mfSecondaryCollisionSystems field.
const MFUnrecParticleSystemPtr *CollisionParticleSystemAffectorBase::getMFSecondaryCollisionSystems(void) const
{
    return &_mfSecondaryCollisionSystems;
}

MFUnrecParticleSystemPtr *CollisionParticleSystemAffectorBase::editMFSecondaryCollisionSystems(void)
{
    editMField(SecondaryCollisionSystemsFieldMask, _mfSecondaryCollisionSystems);

    return &_mfSecondaryCollisionSystems;
}



void CollisionParticleSystemAffectorBase::pushToSecondaryCollisionSystems(ParticleSystem * const value)
{
    editMField(SecondaryCollisionSystemsFieldMask, _mfSecondaryCollisionSystems);

    _mfSecondaryCollisionSystems.push_back(value);
}

void CollisionParticleSystemAffectorBase::assignSecondaryCollisionSystems(const MFUnrecParticleSystemPtr &value)
{
    MFUnrecParticleSystemPtr::const_iterator elemIt  =
        value.begin();
    MFUnrecParticleSystemPtr::const_iterator elemEnd =
        value.end  ();

    static_cast<CollisionParticleSystemAffector *>(this)->clearSecondaryCollisionSystems();

    while(elemIt != elemEnd)
    {
        this->pushToSecondaryCollisionSystems(*elemIt);

        ++elemIt;
    }
}

void CollisionParticleSystemAffectorBase::removeFromSecondaryCollisionSystems(UInt32 uiIndex)
{
    if(uiIndex < _mfSecondaryCollisionSystems.size())
    {
        editMField(SecondaryCollisionSystemsFieldMask, _mfSecondaryCollisionSystems);

        _mfSecondaryCollisionSystems.erase(uiIndex);
    }
}

void CollisionParticleSystemAffectorBase::removeObjFromSecondaryCollisionSystems(ParticleSystem * const value)
{
    Int32 iElemIdx = _mfSecondaryCollisionSystems.findIndex(value);

    if(iElemIdx != -1)
    {
        editMField(SecondaryCollisionSystemsFieldMask, _mfSecondaryCollisionSystems);

        _mfSecondaryCollisionSystems.erase(iElemIdx);
    }
}
void CollisionParticleSystemAffectorBase::clearSecondaryCollisionSystems(void)
{
    editMField(SecondaryCollisionSystemsFieldMask, _mfSecondaryCollisionSystems);


    _mfSecondaryCollisionSystems.clear();
}



/*------------------------------ access -----------------------------------*/

UInt32 CollisionParticleSystemAffectorBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (CollisionDistanceFieldMask & whichField))
    {
        returnValue += _sfCollisionDistance.getBinSize();
    }
    if(FieldBits::NoField != (SecondaryCollisionSystemsFieldMask & whichField))
    {
        returnValue += _mfSecondaryCollisionSystems.getBinSize();
    }

    return returnValue;
}

void CollisionParticleSystemAffectorBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (CollisionDistanceFieldMask & whichField))
    {
        _sfCollisionDistance.copyToBin(pMem);
    }
    if(FieldBits::NoField != (SecondaryCollisionSystemsFieldMask & whichField))
    {
        _mfSecondaryCollisionSystems.copyToBin(pMem);
    }
}

void CollisionParticleSystemAffectorBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (CollisionDistanceFieldMask & whichField))
    {
        _sfCollisionDistance.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (SecondaryCollisionSystemsFieldMask & whichField))
    {
        _mfSecondaryCollisionSystems.copyFromBin(pMem);
    }
}

//! create a new instance of the class
CollisionParticleSystemAffectorTransitPtr CollisionParticleSystemAffectorBase::createLocal(BitVector bFlags)
{
    CollisionParticleSystemAffectorTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<CollisionParticleSystemAffector>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
CollisionParticleSystemAffectorTransitPtr CollisionParticleSystemAffectorBase::createDependent(BitVector bFlags)
{
    CollisionParticleSystemAffectorTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<CollisionParticleSystemAffector>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
CollisionParticleSystemAffectorTransitPtr CollisionParticleSystemAffectorBase::create(void)
{
    CollisionParticleSystemAffectorTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<CollisionParticleSystemAffector>(tmpPtr);
    }

    return fc;
}

CollisionParticleSystemAffector *CollisionParticleSystemAffectorBase::createEmptyLocal(BitVector bFlags)
{
    CollisionParticleSystemAffector *returnValue;

    newPtr<CollisionParticleSystemAffector>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
CollisionParticleSystemAffector *CollisionParticleSystemAffectorBase::createEmpty(void)
{
    CollisionParticleSystemAffector *returnValue;

    newPtr<CollisionParticleSystemAffector>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr CollisionParticleSystemAffectorBase::shallowCopyLocal(
    BitVector bFlags) const
{
    CollisionParticleSystemAffector *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const CollisionParticleSystemAffector *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr CollisionParticleSystemAffectorBase::shallowCopyDependent(
    BitVector bFlags) const
{
    CollisionParticleSystemAffector *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const CollisionParticleSystemAffector *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr CollisionParticleSystemAffectorBase::shallowCopy(void) const
{
    CollisionParticleSystemAffector *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const CollisionParticleSystemAffector *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}



/*------------------------- event producers ----------------------------------*/
void CollisionParticleSystemAffectorBase::produceEvent(UInt32 eventId, EventDetails* const e)
{
    switch(eventId)
    {
    case ParticleCollisionEventId:
        OSG_ASSERT(dynamic_cast<ParticleCollisionEventDetailsType* const>(e));

        _ParticleCollisionEvent.set_combiner(ConsumableEventCombiner(e));
        _ParticleCollisionEvent(dynamic_cast<ParticleCollisionEventDetailsType* const>(e), ParticleCollisionEventId);
        break;
    default:
        SWARNING << "No event defined with that ID";
        break;
    }
}

boost::signals2::connection CollisionParticleSystemAffectorBase::connectEvent(UInt32 eventId, 
                                                             const BaseEventType::slot_type &listener, 
                                                             boost::signals2::connect_position at)
{
    switch(eventId)
    {
    case ParticleCollisionEventId:
        return _ParticleCollisionEvent.connect(listener, at);
        break;
    default:
        SWARNING << "No event defined with that ID";
        return boost::signals2::connection();
        break;
    }

    return boost::signals2::connection();
}

boost::signals2::connection  CollisionParticleSystemAffectorBase::connectEvent(UInt32 eventId, 
                                                              const BaseEventType::group_type &group,
                                                              const BaseEventType::slot_type &listener,
                                                              boost::signals2::connect_position at)
{
    switch(eventId)
    {
    case ParticleCollisionEventId:
        return _ParticleCollisionEvent.connect(group, listener, at);
        break;
    default:
        SWARNING << "No event defined with that ID";
        return boost::signals2::connection();
        break;
    }

    return boost::signals2::connection();
}
    
void  CollisionParticleSystemAffectorBase::disconnectEvent(UInt32 eventId, const BaseEventType::group_type &group)
{
    switch(eventId)
    {
    case ParticleCollisionEventId:
        _ParticleCollisionEvent.disconnect(group);
        break;
    default:
        SWARNING << "No event defined with that ID";
        break;
    }
}

void  CollisionParticleSystemAffectorBase::disconnectAllSlotsEvent(UInt32 eventId)
{
    switch(eventId)
    {
    case ParticleCollisionEventId:
        _ParticleCollisionEvent.disconnect_all_slots();
        break;
    default:
        SWARNING << "No event defined with that ID";
        break;
    }
}

bool  CollisionParticleSystemAffectorBase::isEmptyEvent(UInt32 eventId) const
{
    switch(eventId)
    {
    case ParticleCollisionEventId:
        return _ParticleCollisionEvent.empty();
        break;
    default:
        SWARNING << "No event defined with that ID";
        return true;
        break;
    }
}

UInt32  CollisionParticleSystemAffectorBase::numSlotsEvent(UInt32 eventId) const
{
    switch(eventId)
    {
    case ParticleCollisionEventId:
        return _ParticleCollisionEvent.num_slots();
        break;
    default:
        SWARNING << "No event defined with that ID";
        return 0;
        break;
    }
}


/*------------------------- constructors ----------------------------------*/

CollisionParticleSystemAffectorBase::CollisionParticleSystemAffectorBase(void) :
    Inherited(),
    _sfCollisionDistance      (Real32(0.0f)),
    _mfSecondaryCollisionSystems()
{
}

CollisionParticleSystemAffectorBase::CollisionParticleSystemAffectorBase(const CollisionParticleSystemAffectorBase &source) :
    Inherited(source),
    _sfCollisionDistance      (source._sfCollisionDistance      ),
    _mfSecondaryCollisionSystems()
{
}


/*-------------------------- destructors ----------------------------------*/

CollisionParticleSystemAffectorBase::~CollisionParticleSystemAffectorBase(void)
{
}

void CollisionParticleSystemAffectorBase::onCreate(const CollisionParticleSystemAffector *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        CollisionParticleSystemAffector *pThis = static_cast<CollisionParticleSystemAffector *>(this);

        MFUnrecParticleSystemPtr::const_iterator SecondaryCollisionSystemsIt  =
            source->_mfSecondaryCollisionSystems.begin();
        MFUnrecParticleSystemPtr::const_iterator SecondaryCollisionSystemsEnd =
            source->_mfSecondaryCollisionSystems.end  ();

        while(SecondaryCollisionSystemsIt != SecondaryCollisionSystemsEnd)
        {
            pThis->pushToSecondaryCollisionSystems(*SecondaryCollisionSystemsIt);

            ++SecondaryCollisionSystemsIt;
        }
    }
}

GetFieldHandlePtr CollisionParticleSystemAffectorBase::getHandleCollisionDistance (void) const
{
    SFReal32::GetHandlePtr returnValue(
        new  SFReal32::GetHandle(
             &_sfCollisionDistance,
             this->getType().getFieldDesc(CollisionDistanceFieldId),
             const_cast<CollisionParticleSystemAffectorBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr CollisionParticleSystemAffectorBase::editHandleCollisionDistance(void)
{
    SFReal32::EditHandlePtr returnValue(
        new  SFReal32::EditHandle(
             &_sfCollisionDistance,
             this->getType().getFieldDesc(CollisionDistanceFieldId),
             this));


    editSField(CollisionDistanceFieldMask);

    return returnValue;
}

GetFieldHandlePtr CollisionParticleSystemAffectorBase::getHandleSecondaryCollisionSystems (void) const
{
    MFUnrecParticleSystemPtr::GetHandlePtr returnValue(
        new  MFUnrecParticleSystemPtr::GetHandle(
             &_mfSecondaryCollisionSystems,
             this->getType().getFieldDesc(SecondaryCollisionSystemsFieldId),
             const_cast<CollisionParticleSystemAffectorBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr CollisionParticleSystemAffectorBase::editHandleSecondaryCollisionSystems(void)
{
    MFUnrecParticleSystemPtr::EditHandlePtr returnValue(
        new  MFUnrecParticleSystemPtr::EditHandle(
             &_mfSecondaryCollisionSystems,
             this->getType().getFieldDesc(SecondaryCollisionSystemsFieldId),
             this));

    returnValue->setAddMethod(
        boost::bind(&CollisionParticleSystemAffector::pushToSecondaryCollisionSystems,
                    static_cast<CollisionParticleSystemAffector *>(this), _1));
    returnValue->setRemoveMethod(
        boost::bind(&CollisionParticleSystemAffector::removeFromSecondaryCollisionSystems,
                    static_cast<CollisionParticleSystemAffector *>(this), _1));
    returnValue->setRemoveObjMethod(
        boost::bind(&CollisionParticleSystemAffector::removeObjFromSecondaryCollisionSystems,
                    static_cast<CollisionParticleSystemAffector *>(this), _1));
    returnValue->setClearMethod(
        boost::bind(&CollisionParticleSystemAffector::clearSecondaryCollisionSystems,
                    static_cast<CollisionParticleSystemAffector *>(this)));

    editMField(SecondaryCollisionSystemsFieldMask, _mfSecondaryCollisionSystems);

    return returnValue;
}


GetEventHandlePtr CollisionParticleSystemAffectorBase::getHandleParticleCollisionSignal(void) const
{
    GetEventHandlePtr returnValue(
        new  GetTypedEventHandle<ParticleCollisionEventType>(
             const_cast<ParticleCollisionEventType *>(&_ParticleCollisionEvent),
             _producerType.getEventDescription(ParticleCollisionEventId),
             const_cast<CollisionParticleSystemAffectorBase *>(this)));

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void CollisionParticleSystemAffectorBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    CollisionParticleSystemAffector *pThis = static_cast<CollisionParticleSystemAffector *>(this);

    pThis->execSync(static_cast<CollisionParticleSystemAffector *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *CollisionParticleSystemAffectorBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    CollisionParticleSystemAffector *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const CollisionParticleSystemAffector *>(pRefAspect),
                  dynamic_cast<const CollisionParticleSystemAffector *>(this));

    return returnValue;
}
#endif

void CollisionParticleSystemAffectorBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<CollisionParticleSystemAffector *>(this)->clearSecondaryCollisionSystems();


}


OSG_END_NAMESPACE
