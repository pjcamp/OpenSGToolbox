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

#include "OSGVideoWrapper.h"
#include "OSGUpdateEventDetails.h"
#include <boost/filesystem/operations.hpp>

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGVideoWrapperBase.cpp file.
// To modify it, please change the .fcd file (OSGVideoWrapper.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void VideoWrapper::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
    }
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

void VideoWrapper::attachUpdateProducer(ReflexiveContainer* const producer)
{
    const EventDescription* Desc(producer->getProducerType().findEventDescription("Update"));

    if(_UpdateEventConnection.connected())
    {
        _UpdateEventConnection.disconnect();
    }

    _UpdateEventConnection = connectToEvent(Desc, producer);
}

bool VideoWrapper::isConnectableEvent(EventDescription const * eventDesc) const
{
    return eventDesc->getEventArgumentType() == FieldTraits<UpdateEventDetails *>::getType();
}

VideoWrapper::EventDescVector VideoWrapper::getConnectableEvents(void) const
{
    EventDescVector ConnectableEvents;

    EventDescPair UpdateEventDesc("Update", &FieldTraits<UpdateEventDetails *>::getType());

    ConnectableEvents.push_back(UpdateEventDesc);

    return ConnectableEvents;
}

bool
VideoWrapper::isConnected(EventDescription const * eventDesc) const
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
VideoWrapper::disconnectFromEvent(EventDescription const * eventDesc) const
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
VideoWrapper::connectToEvent(EventDescription const * eventDesc,
                          ReflexiveContainer* const eventProducer) const
{
    //Validate the EventDescription and producer
    EventDescription const * LocalDesc(eventProducer->getEventDescription(eventDesc->getName().c_str()));
    if(validateConnectable(eventDesc,eventProducer))
    {
        return eventProducer->connectEvent(LocalDesc->getEventId(),
                                           boost::bind(&VideoWrapper::handleUpdate,
                                                       const_cast<VideoWrapper*>(this),
                                                       _1));
    }
    else
    {
        return boost::signals2::connection();
    }
}

void VideoWrapper::handleUpdate(EventDetails* const details)
{
    updateImage();
}

bool VideoWrapper::open(const BoostPath& ThePath, Window* const TheWindow)
{
    //Check if the file exists
    if(boost::filesystem::exists(ThePath))
    {
        return open(ThePath.file_string(), TheWindow);
    }
    else
    {
        SWARNING << "VideoWrapper::open(): File " << ThePath.file_string() << " could not be opened, because no file with that path exists" << std::endl;
        return false;
    }
}

void VideoWrapper::producePaused(void)
{
    VideoEventDetailsUnrecPtr Details = VideoEventDetails::create(this,getTimeStamp());
   
    Inherited::producePaused(Details);
}

void VideoWrapper::produceUnpaused(void)
{
    VideoEventDetailsUnrecPtr Details = VideoEventDetails::create(this,getTimeStamp());
   
    Inherited::produceUnpaused(Details);
}

void VideoWrapper::produceStarted(void)
{
    VideoEventDetailsUnrecPtr Details = VideoEventDetails::create(this,getTimeStamp());
   
    Inherited::produceStarted(Details);
}

void VideoWrapper::produceStopped(void)
{
    VideoEventDetailsUnrecPtr Details = VideoEventDetails::create(this,getTimeStamp());
   
    Inherited::produceStopped(Details);
}

void VideoWrapper::produceOpened(void)
{
    VideoEventDetailsUnrecPtr Details = VideoEventDetails::create(this,getTimeStamp());
   
    Inherited::produceOpened(Details);
}

void VideoWrapper::produceClosed(void)
{
    VideoEventDetailsUnrecPtr Details = VideoEventDetails::create(this,getTimeStamp());
   
    Inherited::produceClosed(Details);
}

void VideoWrapper::produceEnded(void)
{
    VideoEventDetailsUnrecPtr Details = VideoEventDetails::create(this,getTimeStamp());
   
    Inherited::produceEnded(Details);
}

void VideoWrapper::produceSeeked(void)
{
    VideoEventDetailsUnrecPtr Details = VideoEventDetails::create(this,getTimeStamp());
   
    Inherited::produceSeeked(Details);
}

void VideoWrapper::produceCycled(void)
{
    VideoEventDetailsUnrecPtr Details = VideoEventDetails::create(this,getTimeStamp());
   
    Inherited::produceCycled(Details);
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

VideoWrapper::VideoWrapper(void) :
    Inherited()
{
}

VideoWrapper::VideoWrapper(const VideoWrapper &source) :
    Inherited(source)
{
}

VideoWrapper::~VideoWrapper(void)
{
}

/*----------------------------- class specific ----------------------------*/

void VideoWrapper::changed(ConstFieldMaskArg whichField, 
                            UInt32            origin,
                            BitVector         details)
{
    Inherited::changed(whichField, origin, details);
}

void VideoWrapper::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump VideoWrapper NI" << std::endl;
}

OSG_END_NAMESPACE
