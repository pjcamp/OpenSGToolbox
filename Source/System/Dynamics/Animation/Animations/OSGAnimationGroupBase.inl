/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
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
 **     class AnimationGroup!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &AnimationGroupBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 AnimationGroupBase::getClassTypeId(void)
{
    return _type.getId();
}
//! access the producer type of the class
inline
const EventProducerType &AnimationGroupBase::getProducerClassType(void)
{
    return _producerType;
}

//! access the producer type id of the class
inline
UInt32 AnimationGroupBase::getProducerClassTypeId(void)
{
    return _producerType.getId();
}

inline
OSG::UInt16 AnimationGroupBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the AnimationGroup::_sfScale field.

inline
Real32 &AnimationGroupBase::editScale(void)
{
    editSField(ScaleFieldMask);

    return _sfScale.getValue();
}

//! Get the value of the AnimationGroup::_sfScale field.
inline
      Real32  AnimationGroupBase::getScale(void) const
{
    return _sfScale.getValue();
}

//! Set the value of the AnimationGroup::_sfScale field.
inline
void AnimationGroupBase::setScale(const Real32 value)
{
    editSField(ScaleFieldMask);

    _sfScale.setValue(value);
}
//! Get the value of the AnimationGroup::_sfOffset field.

inline
Real32 &AnimationGroupBase::editOffset(void)
{
    editSField(OffsetFieldMask);

    return _sfOffset.getValue();
}

//! Get the value of the AnimationGroup::_sfOffset field.
inline
      Real32  AnimationGroupBase::getOffset(void) const
{
    return _sfOffset.getValue();
}

//! Set the value of the AnimationGroup::_sfOffset field.
inline
void AnimationGroupBase::setOffset(const Real32 value)
{
    editSField(OffsetFieldMask);

    _sfOffset.setValue(value);
}
//! Get the value of the AnimationGroup::_sfSpan field.

inline
Real32 &AnimationGroupBase::editSpan(void)
{
    editSField(SpanFieldMask);

    return _sfSpan.getValue();
}

//! Get the value of the AnimationGroup::_sfSpan field.
inline
      Real32  AnimationGroupBase::getSpan(void) const
{
    return _sfSpan.getValue();
}

//! Set the value of the AnimationGroup::_sfSpan field.
inline
void AnimationGroupBase::setSpan(const Real32 value)
{
    editSField(SpanFieldMask);

    _sfSpan.setValue(value);
}

//! Get the value of the \a index element the AnimationGroup::_mfAnimations field.
inline
Animation * AnimationGroupBase::getAnimations(const UInt32 index) const
{
    return _mfAnimations[index];
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void AnimationGroupBase::execSync (      AnimationGroupBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (AnimationsFieldMask & whichField))
        _mfAnimations.syncWith(pFrom->_mfAnimations,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);

    if(FieldBits::NoField != (ScaleFieldMask & whichField))
        _sfScale.syncWith(pFrom->_sfScale);

    if(FieldBits::NoField != (OffsetFieldMask & whichField))
        _sfOffset.syncWith(pFrom->_sfOffset);

    if(FieldBits::NoField != (SpanFieldMask & whichField))
        _sfSpan.syncWith(pFrom->_sfSpan);
}
#endif


inline
const Char8 *AnimationGroupBase::getClassname(void)
{
    return "AnimationGroup";
}

inline
boost::signals2::connection AnimationGroupBase::attachActivity(UInt32 eventId,
                                                              Activity* TheActivity)
{
    return connectEvent(eventId, boost::bind(&Activity::eventProduced, TheActivity, _1, _2) );
}

inline
UInt32 AnimationGroupBase::getNumProducedEvents(void) const
{
    return getProducerType().getNumEventDescs();
}

inline
const EventDescription *AnimationGroupBase::getProducedEventDescription(const std::string &ProducedEventName) const
{
    return getProducerType().findEventDescription(ProducedEventName);
}

inline
const EventDescription *AnimationGroupBase::getProducedEventDescription(UInt32 ProducedEventId) const
{
    return getProducerType().getEventDescription(ProducedEventId);
}

inline
UInt32 AnimationGroupBase::getProducedEventId(const std::string &ProducedEventName) const
{
    return getProducerType().getProducedEventId(ProducedEventName);
}

inline
boost::signals2::connection  AnimationGroupBase::connectAnimationsStarted(const AnimationsStartedEventType::slot_type &listener, 
                                                                               boost::signals2::connect_position at)
{
    return _AnimationsStartedEvent.connect(listener, at);
}

inline
boost::signals2::connection  AnimationGroupBase::connectAnimationsStarted(const AnimationsStartedEventType::group_type &group,
                                                    const AnimationsStartedEventType::slot_type &listener, boost::signals2::connect_position at)
{
    return _AnimationsStartedEvent.connect(group, listener, at);
}

inline
void  AnimationGroupBase::disconnectAnimationsStarted(const AnimationsStartedEventType::group_type &group)
{
    _AnimationsStartedEvent.disconnect(group);
}

inline
void  AnimationGroupBase::disconnectAllSlotsAnimationsStarted(void)
{
    _AnimationsStartedEvent.disconnect_all_slots();
}

inline
bool  AnimationGroupBase::isEmptyAnimationsStarted(void) const
{
    return _AnimationsStartedEvent.empty();
}

inline
UInt32  AnimationGroupBase::numSlotsAnimationsStarted(void) const
{
    return _AnimationsStartedEvent.num_slots();
}

inline
void AnimationGroupBase::produceAnimationsStarted(AnimationsStartedEventDetailsType* const e)
{
    produceEvent(AnimationsStartedEventId, e);
}

inline
boost::signals2::connection  AnimationGroupBase::connectAnimationsStopped(const AnimationsStoppedEventType::slot_type &listener, 
                                                                               boost::signals2::connect_position at)
{
    return _AnimationsStoppedEvent.connect(listener, at);
}

inline
boost::signals2::connection  AnimationGroupBase::connectAnimationsStopped(const AnimationsStoppedEventType::group_type &group,
                                                    const AnimationsStoppedEventType::slot_type &listener, boost::signals2::connect_position at)
{
    return _AnimationsStoppedEvent.connect(group, listener, at);
}

inline
void  AnimationGroupBase::disconnectAnimationsStopped(const AnimationsStoppedEventType::group_type &group)
{
    _AnimationsStoppedEvent.disconnect(group);
}

inline
void  AnimationGroupBase::disconnectAllSlotsAnimationsStopped(void)
{
    _AnimationsStoppedEvent.disconnect_all_slots();
}

inline
bool  AnimationGroupBase::isEmptyAnimationsStopped(void) const
{
    return _AnimationsStoppedEvent.empty();
}

inline
UInt32  AnimationGroupBase::numSlotsAnimationsStopped(void) const
{
    return _AnimationsStoppedEvent.num_slots();
}

inline
void AnimationGroupBase::produceAnimationsStopped(AnimationsStoppedEventDetailsType* const e)
{
    produceEvent(AnimationsStoppedEventId, e);
}

inline
boost::signals2::connection  AnimationGroupBase::connectAnimationsPaused(const AnimationsPausedEventType::slot_type &listener, 
                                                                               boost::signals2::connect_position at)
{
    return _AnimationsPausedEvent.connect(listener, at);
}

inline
boost::signals2::connection  AnimationGroupBase::connectAnimationsPaused(const AnimationsPausedEventType::group_type &group,
                                                    const AnimationsPausedEventType::slot_type &listener, boost::signals2::connect_position at)
{
    return _AnimationsPausedEvent.connect(group, listener, at);
}

inline
void  AnimationGroupBase::disconnectAnimationsPaused(const AnimationsPausedEventType::group_type &group)
{
    _AnimationsPausedEvent.disconnect(group);
}

inline
void  AnimationGroupBase::disconnectAllSlotsAnimationsPaused(void)
{
    _AnimationsPausedEvent.disconnect_all_slots();
}

inline
bool  AnimationGroupBase::isEmptyAnimationsPaused(void) const
{
    return _AnimationsPausedEvent.empty();
}

inline
UInt32  AnimationGroupBase::numSlotsAnimationsPaused(void) const
{
    return _AnimationsPausedEvent.num_slots();
}

inline
void AnimationGroupBase::produceAnimationsPaused(AnimationsPausedEventDetailsType* const e)
{
    produceEvent(AnimationsPausedEventId, e);
}

inline
boost::signals2::connection  AnimationGroupBase::connectAnimationsUnpaused(const AnimationsUnpausedEventType::slot_type &listener, 
                                                                               boost::signals2::connect_position at)
{
    return _AnimationsUnpausedEvent.connect(listener, at);
}

inline
boost::signals2::connection  AnimationGroupBase::connectAnimationsUnpaused(const AnimationsUnpausedEventType::group_type &group,
                                                    const AnimationsUnpausedEventType::slot_type &listener, boost::signals2::connect_position at)
{
    return _AnimationsUnpausedEvent.connect(group, listener, at);
}

inline
void  AnimationGroupBase::disconnectAnimationsUnpaused(const AnimationsUnpausedEventType::group_type &group)
{
    _AnimationsUnpausedEvent.disconnect(group);
}

inline
void  AnimationGroupBase::disconnectAllSlotsAnimationsUnpaused(void)
{
    _AnimationsUnpausedEvent.disconnect_all_slots();
}

inline
bool  AnimationGroupBase::isEmptyAnimationsUnpaused(void) const
{
    return _AnimationsUnpausedEvent.empty();
}

inline
UInt32  AnimationGroupBase::numSlotsAnimationsUnpaused(void) const
{
    return _AnimationsUnpausedEvent.num_slots();
}

inline
void AnimationGroupBase::produceAnimationsUnpaused(AnimationsUnpausedEventDetailsType* const e)
{
    produceEvent(AnimationsUnpausedEventId, e);
}

inline
boost::signals2::connection  AnimationGroupBase::connectAnimationsEnded(const AnimationsEndedEventType::slot_type &listener, 
                                                                               boost::signals2::connect_position at)
{
    return _AnimationsEndedEvent.connect(listener, at);
}

inline
boost::signals2::connection  AnimationGroupBase::connectAnimationsEnded(const AnimationsEndedEventType::group_type &group,
                                                    const AnimationsEndedEventType::slot_type &listener, boost::signals2::connect_position at)
{
    return _AnimationsEndedEvent.connect(group, listener, at);
}

inline
void  AnimationGroupBase::disconnectAnimationsEnded(const AnimationsEndedEventType::group_type &group)
{
    _AnimationsEndedEvent.disconnect(group);
}

inline
void  AnimationGroupBase::disconnectAllSlotsAnimationsEnded(void)
{
    _AnimationsEndedEvent.disconnect_all_slots();
}

inline
bool  AnimationGroupBase::isEmptyAnimationsEnded(void) const
{
    return _AnimationsEndedEvent.empty();
}

inline
UInt32  AnimationGroupBase::numSlotsAnimationsEnded(void) const
{
    return _AnimationsEndedEvent.num_slots();
}

inline
void AnimationGroupBase::produceAnimationsEnded(AnimationsEndedEventDetailsType* const e)
{
    produceEvent(AnimationsEndedEventId, e);
}

inline
boost::signals2::connection  AnimationGroupBase::connectAnimationsCycled(const AnimationsCycledEventType::slot_type &listener, 
                                                                               boost::signals2::connect_position at)
{
    return _AnimationsCycledEvent.connect(listener, at);
}

inline
boost::signals2::connection  AnimationGroupBase::connectAnimationsCycled(const AnimationsCycledEventType::group_type &group,
                                                    const AnimationsCycledEventType::slot_type &listener, boost::signals2::connect_position at)
{
    return _AnimationsCycledEvent.connect(group, listener, at);
}

inline
void  AnimationGroupBase::disconnectAnimationsCycled(const AnimationsCycledEventType::group_type &group)
{
    _AnimationsCycledEvent.disconnect(group);
}

inline
void  AnimationGroupBase::disconnectAllSlotsAnimationsCycled(void)
{
    _AnimationsCycledEvent.disconnect_all_slots();
}

inline
bool  AnimationGroupBase::isEmptyAnimationsCycled(void) const
{
    return _AnimationsCycledEvent.empty();
}

inline
UInt32  AnimationGroupBase::numSlotsAnimationsCycled(void) const
{
    return _AnimationsCycledEvent.num_slots();
}

inline
void AnimationGroupBase::produceAnimationsCycled(AnimationsCycledEventDetailsType* const e)
{
    produceEvent(AnimationsCycledEventId, e);
}

OSG_GEN_CONTAINERPTR(AnimationGroup);

OSG_END_NAMESPACE

