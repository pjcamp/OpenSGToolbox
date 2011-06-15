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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <cstdlib>
#include <cstdio>

#include <OSGConfig.h>

#include "OSGAnimation.h"
#include "OSGUpdateEventDetails.h"
#include "OSGStatCollector.h"
#include <boost/bind.hpp>

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGAnimationBase.cpp file.
// To modify it, please change the .fcd file (OSGAnimation.fcd) and
// regenerate the base file.

/*!\fn Real32 Animation::getUnclippedCycleLength(void) const
 *
 * \brief Get the length, in seconds, of one unclipped cycle of the animation.
 *
 * If the animation cycles infinitely, then this will return -1.0.
 * Otherwise, this will return the length of each unclipped cycle times
 * the number of cycles.  This length does NOT take into account the
 * span and scale of the animation.
 *
 * @return The length, in seconds, of one unclipped cycle of the
 * animation.
 */

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

StatElemDesc<StatTimeElem> Animation::statAnimUpdateTime("AnimUpdateTime", 
                                                         "time to update all animations");

StatElemDesc<StatIntElem> Animation::statNAnimations("NAnimations", 
                                                     "number of animations updated");


/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void Animation::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
    }
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*!\fn Real32 Animation::getLength(void) const
 *
 * \brief Get the length, in seconds, of the animation.
 *
 * If the animation cycles infinitely, then this will return -1.0.  Otherwise,
 * this will return the length of each cycle times the number of cycles.  This
 * length takes into account the span and scale of the animation.
 *
 * @return The length in seconds of the animation.
 */
Real32 Animation::getLength(void) const
{
    if(getCycling() > 0)
    {
        return getCycleLength() * static_cast<Real32>(getCycling());
    }
    else
    {
        return -1.0f;
    }
}

/*!\fn Real32 Animation::getCycleLength(void) const
 *
 * \brief Get the length, in seconds, of one cycle of the animation.
 *
 * This length takes into account the span and scale of the animation.
 *
 * @return The length, in seconds, of one cycle of the animation.
 */
Real32 Animation::getCycleLength(void) const
{
    Real32 UnclippedCycleLength;
    if(getSpan() > 0.0f)
    {
        UnclippedCycleLength = getSpan();
    }
    else
    {
        UnclippedCycleLength = getUnclippedCycleLength();
    }

    if(UnclippedCycleLength < 0.0f ||
       getScale() == 0.0f)
    {
        return -1.0f;
    }
    else
    {
        return UnclippedCycleLength / getScale();
    }
}

/*!\fn Real32 Animation::getUnclippedLength(void) const
 *
 * \brief Get the length, in seconds, of the unclipped animation.
 *
 * If the animation cycles infinitely, then this will return -1.0.  Otherwise,
 * this will return the length of each unclipped cycle times the number
 * of cycles. This length does NOT take into account the span and scale
 * of the animation.
 *
 * @return The length, in seconds, of the unclipped animation.
 */
Real32 Animation::getUnclippedLength(void) const
{
    if(getCycling() > 0)
    {
        return getUnclippedCycleLength() * static_cast<Real32>(getCycling());
    }
    else
    {
        return -1.0f;
    }
}

/*!\fn void Animation::start(const Time& StartTime)
 *
 * \brief Start the animation at the given start time.
 *
 * @param[in] StartTime The time (in seconds) to start the animation at.
 * This defaults to time 0.0.
 */
void Animation::start(const Time& StartTime)
{
    if(_IsPlaying)
    {
        stop(false);
    }

    _CurrentTime = _PrevTime = StartTime;
    setCycles(0);
    //commitChanges();
    _IsPlaying = true;

    update(0.0);

    produceAnimationStarted();
}

/*!\fn void Animation::seek(const Time& SeekTime)
 *
 * \brief Move the current time of the animation.
 *
 * @param[in] SeekTime The time, in seconds, to move the animation to.
 */
void Animation::seek(const Time& SeekTime)
{
    if(_IsPlaying)
    {
        _CurrentTime = _PrevTime = SeekTime;
    }
}

/*!\fn void Animation::pause(bool ShouldPause)
 *
 * \brief Pause and unpause an animation.
 *
 * If paused, the animation will not apply any changes if update() is called.
 *
 * @param[in] ShouldPause If true, the animation will be paused unless the
 * animation is already paused.  If false, the animation will be
 * unpaused.
 */
void Animation::pause(bool ShouldPause)
{
    if(_IsPaused && !ShouldPause)
    {
        _IsPaused = ShouldPause;
        produceAnimationUnpaused();
    }
    if(!_IsPaused && ShouldPause)
    {
        _IsPaused = ShouldPause;
        produceAnimationPaused();
    }
}

/*!\fn void Animation::stop(bool DisconnectFromEventProducer)
 *
 * \brief Stops a playing animation.
 *
 * @param[in] DisconnectFromEventProducer If true the animation will also be
 * detached from the event producer. By default it is true.
 */
void Animation::stop(bool DisconnectFromEventProducer)
{
    if(_IsPlaying)
    {
        _IsPlaying = false;
        if(DisconnectFromEventProducer)
        {
            _UpdateEventConnection.disconnect();
        }
        produceAnimationStopped();
    }
}

/*!
 * \fn bool OSG::Animation::update(const Time& ElapsedTime)
 *
 * \brief Update the animation with the time since the last update
 *
 * The result of the animation will also be applied to the
 * object it is connected to.
 *
 * \param[in] ElapsedTime The time, in seconds, since the previous call to
 * update.
 */
bool Animation::update(const Time& ElapsedTime)
{
    if(!_IsPlaying || _IsPaused)
    {
        return false;
    }

    //Increment the updated animations statistic
    StatIntElem *NAnimationsStatElem = StatCollector::getGlobalElem(statNAnimations);
    if(NAnimationsStatElem) { NAnimationsStatElem->inc(); }

    //Start the  animation update time statistic
    StatTimeElem *AnimUpdateTimeStatElem = StatCollector::getGlobalElem(statAnimUpdateTime);
    if(AnimUpdateTimeStatElem) { AnimUpdateTimeStatElem->start(); }

    _CurrentTime += getScale()*ElapsedTime;
    UInt32 PreUpdateCycleCount(getCycles());
    if(getCycling() < 0 || PreUpdateCycleCount < getCycling())
    {
        Real32 CycleLength(getCycleLength() * getScale());

        //Check if the Animation Time is past the end
        if(_CurrentTime >= CycleLength)
        {
            //Update the number of cycles completed
            setCycles( (CycleLength <= 0.0f) ? (0): (static_cast<UInt32>( osgFloor( _CurrentTime / CycleLength ) )) );
            //commitChanges();
        }
        Real32 t(_CurrentTime);

        if(getCycling() > 0 && getCycles() >= getCycling())
        {
            if(getSpan() > 0.0f)
            {
                t = getSpan();
            }
            t -= 0.0001f;
        }
        else
        {
            if(getSpan() > 0.0f)
            {
                t -= osgFloor(_CurrentTime/getSpan())*getSpan();
            }
        }
        t += getOffset();

        //Internal Update
        internalUpdate(t, _PrevTime);


        //If the number of cycles has changed
        if(getCycles() != PreUpdateCycleCount)
        {
            if(getCycling() > 0 && getCycles() >= getCycling())
            {
                //Animation has reached the end
                //Remove the Animation from it's update producer
                _UpdateEventConnection.disconnect();
                _IsPlaying = false;

                //Produce the Ended event
                produceAnimationEnded();
            }
            else
            {
                //Animation hasn't finished yet
                //Produce the Cycled event
                produceAnimationCycled();
            }
        }
    }

    _PrevTime = _CurrentTime;

    //Stp[ the  animation update time statistic
    if(AnimUpdateTimeStatElem) { AnimUpdateTimeStatElem->stop(); }

    //Return true if the animation has completed its number of cycles, false otherwise
    return (getCycling() > 0 && getCycles() >= getCycling());
}

/*!\fn void Animation::attachUpdateProducer(ReflexiveContainer* const producer)
 *
 * \brief Attach an update event producer to this animation.
 *
 * This event producer should produce an update event regularly to update the
 * animation.
 *
 * @param[in] Producer A ReflexiveContainer that can produce an UpdateEvent.
 */
void Animation::attachUpdateProducer(ReflexiveContainer* const producer)
{
    const EventDescription* Desc(producer->getProducerType().findEventDescription("Update"));

    if(_UpdateEventConnection.connected())
    {
        _UpdateEventConnection.disconnect();
    }

    _UpdateEventConnection = connectToEvent(Desc, producer);
}

/*!\fn void Animation::detachUpdateProducer(void)
 *
 * \brief Detach the event update producer from this animation if there is one
 * attached.
 */
void Animation::detachUpdateProducer(void)
{
    _UpdateEventConnection.disconnect();
}

bool Animation::isConnectableEvent(EventDescription const * eventDesc) const
{
    return eventDesc->getEventArgumentType() == FieldTraits<UpdateEventDetails *>::getType();
}

Animation::EventDescVector Animation::getConnectableEvents(void) const
{
    EventDescVector ConnectableEvents;

    EventDescPair UpdateEventDesc("Update", &FieldTraits<UpdateEventDetails *>::getType());

    ConnectableEvents.push_back(UpdateEventDesc);

    return ConnectableEvents;
}

bool
Animation::isConnected(EventDescription const * eventDesc) const
{
    if(eventDesc->getEventArgumentType() == FieldTraits<UpdateEventDetails *>::getType())
    {
        return _UpdateEventConnection.connected();
    }
    else
    {
        return false;
    }
}

bool
Animation::disconnectFromEvent(EventDescription const * eventDesc) const
{
    if(eventDesc->getEventArgumentType() == FieldTraits<UpdateEventDetails *>::getType())
    {
        _UpdateEventConnection.disconnect();
        return true;
    }
    else
    {
        return false;
    }
}

boost::signals2::connection 
Animation::connectToEvent(EventDescription const * eventDesc,
                          ReflexiveContainer* const eventProducer) const
{
    //Validate the EventDescription and producer
    EventDescription const * LocalDesc(eventProducer->getEventDescription(eventDesc->getName().c_str()));
    if(validateConnectable(eventDesc,eventProducer))
    {
        return eventProducer->connectEvent(LocalDesc->getEventId(),
                                           boost::bind(&Animation::handleUpdate,
                                                       const_cast<Animation*>(this),
                                                       _1));
    }
    else
    {
        return boost::signals2::connection();
    }
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

void Animation::produceAnimationStarted(void)
{
    AnimationEventDetailsUnrecPtr Details = AnimationEventDetails::create(this,getTimeStamp());
   
    Inherited::produceAnimationStarted(Details);
}

void Animation::produceAnimationStopped(void)
{
    AnimationEventDetailsUnrecPtr Details = AnimationEventDetails::create(this,getTimeStamp());
   
    Inherited::produceAnimationStopped(Details);
}

void Animation::produceAnimationPaused(void)
{
    AnimationEventDetailsUnrecPtr Details = AnimationEventDetails::create(this,getTimeStamp());
   
    Inherited::produceAnimationPaused(Details);
}

void Animation::produceAnimationUnpaused(void)
{
    AnimationEventDetailsUnrecPtr Details = AnimationEventDetails::create(this,getTimeStamp());
   
    Inherited::produceAnimationUnpaused(Details);
}

void Animation::produceAnimationEnded(void)
{
    AnimationEventDetailsUnrecPtr Details = AnimationEventDetails::create(this,getTimeStamp());
   
    Inherited::produceAnimationEnded(Details);
}

void Animation::produceAnimationCycled(void)
{
    AnimationEventDetailsUnrecPtr Details = AnimationEventDetails::create(this,getTimeStamp());
   
    Inherited::produceAnimationCycled(Details);
}

/*----------------------- constructors & destructors ----------------------*/

Animation::Animation(void) :
    Inherited(),
    _CurrentTime(0.0),
    _PrevTime(0.0),
    _IsPlaying(false),
    _IsPaused(false)
{
}

Animation::Animation(const Animation &source) :
    Inherited(source),
    _CurrentTime(0.0),
    _PrevTime(0.0),
    _IsPlaying(false),
    _IsPaused(false)
{
}

Animation::~Animation(void)
{
}

/*----------------------------- class specific ----------------------------*/

void Animation::changed(ConstFieldMaskArg whichField, 
                            UInt32            origin,
                            BitVector         details)
{
    Inherited::changed(whichField, origin, details);
}

void Animation::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump Animation NI" << std::endl;
}

void Animation::handleUpdate(EventDetails* const details)
{
    Time elapsed = dynamic_cast<UpdateEventDetails* const>(details)->getElapsedTime();
    update(elapsed);
}

OSG_END_NAMESPACE
