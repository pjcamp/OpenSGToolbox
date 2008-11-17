/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *   Authors: David Kabala, Alden Peterson, Lee Zaniewski, Jonathan Flory    *
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
#ifndef _OSGDRAG_GESTUREEVENT_H_
#define _OSGDRAG_GESTUREEVENT_H_
#ifdef __sgi
#pragma once
#endif

#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"

#include <OpenSG/Input/OSGEvent.h>

#include "Component/OSGComponentFields.h"

OSG_BEGIN_NAMESPACE

class OSG_USERINTERFACELIB_DLLMAPPING DragGestureEvent : public Event
{
/*=========================  PUBLIC  ===============================*/
public:

    ComponentPtr getOriginComponent(void) const;
    const Pnt2f &getDragLocation(void) const;

    DragGestureEvent(FieldContainerPtr Source, Time TimeStamp, ComponentPtr TheComponent, const Pnt2f &DragLocation);
    
    virtual const EventType &getType(void) const;
    
    static const EventType &getClassType(void);
protected:
    ComponentPtr _OriginComponent;
    Pnt2f _DragLocation;

  private:
     static EventType _Type;
};

OSG_END_NAMESPACE

#include "OSGDragGestureEvent.inl"

#endif /* _OSGDRAG_GESTUREEVENT_H_ */
