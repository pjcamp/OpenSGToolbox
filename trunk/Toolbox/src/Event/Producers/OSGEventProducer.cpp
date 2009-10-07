/*---------------------------------------------------------------------------*\
 *                        OpenSG ToolBox Toolbox                             *
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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>

#define OSG_COMPILETOOLBOXLIB

#include <OpenSG/OSGConfig.h>

#include "OSGEventProducer.h"
#include <boost/bind.hpp>

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class osg::EventProducer

*/

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

EventProducerType EventProducer::_ProducerType(
    "EventProducerType",
    NULL,
    NULL,
    InitEventProducerFunctor(),
    NULL,
    0);
    
/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/
UInt32 EventProducer::getNumListenersAttached(UInt32 ProducedEventId) const
{
    ListenerMapConstItor SearchItor(_AttachedListeners.find(ProducedEventId));
    if(SearchItor == _AttachedListeners.end())
    {
        return 0;
    }
    else
    {
    }
    return SearchItor->second.size();
}

EventListenerPtr EventProducer::getAttachedListener(UInt32 ProducedEventId, UInt32 ListenerIndex) const
{
    ListenerMapConstItor SearchItor(_AttachedListeners.find(ProducedEventId));
    if(SearchItor == _AttachedListeners.end())
    {
        return EventListenerPtr();
    }
    else
    {
        if(ListenerIndex >= SearchItor->second.size())
        {
            return EventListenerPtr();
        }
        else
        {
            ListenerSetConstItor SetItor(SearchItor->second.begin());
            for(UInt32 i(0) ; i<ListenerIndex; ++i) ++SetItor;
            return *SetItor;
        }
    }
}

EventConnection EventProducer::attachEventListener(EventListenerPtr Listener, UInt32 ProducedEventId)
{
    if(_AttachedListeners.find(ProducedEventId) == _AttachedListeners.end())
    {
        _AttachedListeners[ProducedEventId] = std::set<EventListenerPtr>();
    }

   _AttachedListeners[ProducedEventId].insert(Listener);
   return EventConnection(
       boost::bind(&EventProducer::isEventListenerAttached, this, Listener, ProducedEventId),
       boost::bind(&EventProducer::detachEventListener, this, Listener, ProducedEventId));
}

bool EventProducer::isEventListenerAttached(EventListenerPtr Listener, UInt32 ProducedEventId) const
{
    return _AttachedListeners.find(ProducedEventId)->second.find(Listener) != _AttachedListeners.find(ProducedEventId)->second.end();
}

void EventProducer::detachEventListener(EventListenerPtr Listener, UInt32 ProducedEventId)
{
   ListenerSetItor EraseIter(_AttachedListeners[ProducedEventId].find(Listener));
   if(EraseIter != _AttachedListeners[ProducedEventId].end())
   {
      _AttachedListeners[ProducedEventId].erase(EraseIter);
   }
}

void EventProducer::produceEvent(UInt32 ProducedEventId, const EventPtr TheEvent)
{
    ListenerSet TheListenerSet(_AttachedListeners[ProducedEventId]);
    for(ListenerSetConstItor SetItor(TheListenerSet.begin()) ; SetItor != TheListenerSet.end() ; ++SetItor)
    {
        (*SetItor)->eventProduced(TheEvent, ProducedEventId);
    }
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

EventProducer::EventProducer(void)
{
}

EventProducer::EventProducer(const EventProducer &source)
{
}

EventProducer::~EventProducer(void)
{
}

OSG_END_NAMESPACE

