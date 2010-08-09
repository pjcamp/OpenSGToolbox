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
 **     class CellEditor!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGCellEditorBase.h"
#include "OSGCellEditor.h"

#include <boost/bind.hpp>

#include "OSGEventDetails.h"

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::CellEditor
    A UI Cell Editor.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<CellEditor *>::_type("CellEditorPtr", "FieldContainerPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(CellEditor *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           CellEditor *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           CellEditor *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void CellEditorBase::classDescInserter(TypeObject &oType)
{
}


CellEditorBase::TypeObject CellEditorBase::_type(
    CellEditorBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    NULL,
    CellEditor::initMethod,
    CellEditor::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&CellEditor::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"CellEditor\"\n"
    "\tparent=\"FieldContainer\"\n"
    "    library=\"ContribUserInterface\"\n"
    "    pointerfieldtypes=\"both\"\n"
    "\tstructure=\"abstract\"\n"
    "    systemcomponent=\"true\"\n"
    "    parentsystemcomponent=\"true\"\n"
    "    decoratable=\"false\"\n"
    "    useLocalIncludes=\"false\"\n"
    "    isNodeCore=\"false\"\n"
    "    authors=\"David Kabala (djkabala@gmail.com)                             \"\n"
    ">\n"
    "A UI Cell Editor.\n"
    "\t<ProducedEvent\n"
    "\t\tname=\"EditingCanceled\"\n"
    "\t\tdetailsType=\"ChangeEventDetails\"\n"
    "\t\tconsumable=\"true\"\n"
    "\t>\n"
    "\t</ProducedEvent>\n"
    "\t<ProducedEvent\n"
    "\t\tname=\"EditingStopped\"\n"
    "\t\tdetailsType=\"ChangeEventDetails\"\n"
    "\t\tconsumable=\"true\"\n"
    "\t>\n"
    "\t</ProducedEvent>\n"
    "</FieldContainer>\n",
    "A UI Cell Editor.\n"
    );

//! CellEditor Produced Events

EventDescription *CellEditorBase::_eventDesc[] =
{
    new EventDescription("EditingCanceled", 
                          "",
                          EditingCanceledEventId, 
                          FieldTraits<ChangeEventDetails *>::getType(),
                          true,
                          static_cast<EventGetMethod>(&CellEditorBase::getHandleEditingCanceledSignal)),

    new EventDescription("EditingStopped", 
                          "",
                          EditingStoppedEventId, 
                          FieldTraits<ChangeEventDetails *>::getType(),
                          true,
                          static_cast<EventGetMethod>(&CellEditorBase::getHandleEditingStoppedSignal))

};

EventProducerType CellEditorBase::_producerType(
    "CellEditorProducerType",
    "EventProducerType",
    "",
    InitEventProducerFunctor(),
    _eventDesc,
    sizeof(_eventDesc));

/*------------------------------ get -----------------------------------*/

FieldContainerType &CellEditorBase::getType(void)
{
    return _type;
}

const FieldContainerType &CellEditorBase::getType(void) const
{
    return _type;
}

const EventProducerType &CellEditorBase::getProducerType(void) const
{
    return _producerType;
}

UInt32 CellEditorBase::getContainerSize(void) const
{
    return sizeof(CellEditor);
}

/*------------------------- decorator get ------------------------------*/






/*------------------------------ access -----------------------------------*/

UInt32 CellEditorBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);


    return returnValue;
}

void CellEditorBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

}

void CellEditorBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

}



/*------------------------- event producers ----------------------------------*/
void CellEditorBase::produceEvent(UInt32 eventId, EventDetails* const e)
{
    switch(eventId)
    {
    case EditingCanceledEventId:
        OSG_ASSERT(dynamic_cast<EditingCanceledEventDetailsType* const>(e));

        _EditingCanceledEvent.set_combiner(ConsumableEventCombiner(e));
        _EditingCanceledEvent(dynamic_cast<EditingCanceledEventDetailsType* const>(e), EditingCanceledEventId);
        break;
    case EditingStoppedEventId:
        OSG_ASSERT(dynamic_cast<EditingStoppedEventDetailsType* const>(e));

        _EditingStoppedEvent.set_combiner(ConsumableEventCombiner(e));
        _EditingStoppedEvent(dynamic_cast<EditingStoppedEventDetailsType* const>(e), EditingStoppedEventId);
        break;
    default:
        SWARNING << "No event defined with that ID";
        break;
    }
}

boost::signals2::connection CellEditorBase::connectEvent(UInt32 eventId, 
                                                             const BaseEventType::slot_type &listener, 
                                                             boost::signals2::connect_position at)
{
    switch(eventId)
    {
    case EditingCanceledEventId:
        return _EditingCanceledEvent.connect(listener, at);
        break;
    case EditingStoppedEventId:
        return _EditingStoppedEvent.connect(listener, at);
        break;
    default:
        SWARNING << "No event defined with that ID";
        return boost::signals2::connection();
        break;
    }

    return boost::signals2::connection();
}

boost::signals2::connection  CellEditorBase::connectEvent(UInt32 eventId, 
                                                              const BaseEventType::group_type &group,
                                                              const BaseEventType::slot_type &listener,
                                                              boost::signals2::connect_position at)
{
    switch(eventId)
    {
    case EditingCanceledEventId:
        return _EditingCanceledEvent.connect(group, listener, at);
        break;
    case EditingStoppedEventId:
        return _EditingStoppedEvent.connect(group, listener, at);
        break;
    default:
        SWARNING << "No event defined with that ID";
        return boost::signals2::connection();
        break;
    }

    return boost::signals2::connection();
}
    
void  CellEditorBase::disconnectEvent(UInt32 eventId, const BaseEventType::group_type &group)
{
    switch(eventId)
    {
    case EditingCanceledEventId:
        _EditingCanceledEvent.disconnect(group);
        break;
    case EditingStoppedEventId:
        _EditingStoppedEvent.disconnect(group);
        break;
    default:
        SWARNING << "No event defined with that ID";
        break;
    }
}

void  CellEditorBase::disconnectAllSlotsEvent(UInt32 eventId)
{
    switch(eventId)
    {
    case EditingCanceledEventId:
        _EditingCanceledEvent.disconnect_all_slots();
        break;
    case EditingStoppedEventId:
        _EditingStoppedEvent.disconnect_all_slots();
        break;
    default:
        SWARNING << "No event defined with that ID";
        break;
    }
}

bool  CellEditorBase::isEmptyEvent(UInt32 eventId) const
{
    switch(eventId)
    {
    case EditingCanceledEventId:
        return _EditingCanceledEvent.empty();
        break;
    case EditingStoppedEventId:
        return _EditingStoppedEvent.empty();
        break;
    default:
        SWARNING << "No event defined with that ID";
        return true;
        break;
    }
}

UInt32  CellEditorBase::numSlotsEvent(UInt32 eventId) const
{
    switch(eventId)
    {
    case EditingCanceledEventId:
        return _EditingCanceledEvent.num_slots();
        break;
    case EditingStoppedEventId:
        return _EditingStoppedEvent.num_slots();
        break;
    default:
        SWARNING << "No event defined with that ID";
        return 0;
        break;
    }
}


/*------------------------- constructors ----------------------------------*/

CellEditorBase::CellEditorBase(void) :
    Inherited()
{
}

CellEditorBase::CellEditorBase(const CellEditorBase &source) :
    Inherited(source)
{
}


/*-------------------------- destructors ----------------------------------*/

CellEditorBase::~CellEditorBase(void)
{
}



GetEventHandlePtr CellEditorBase::getHandleEditingCanceledSignal(void) const
{
    GetEventHandlePtr returnValue(
        new  GetTypedEventHandle<EditingCanceledEventType>(
             const_cast<EditingCanceledEventType *>(&_EditingCanceledEvent),
             _producerType.getEventDescription(EditingCanceledEventId),
             const_cast<CellEditorBase *>(this)));

    return returnValue;
}

GetEventHandlePtr CellEditorBase::getHandleEditingStoppedSignal(void) const
{
    GetEventHandlePtr returnValue(
        new  GetTypedEventHandle<EditingStoppedEventType>(
             const_cast<EditingStoppedEventType *>(&_EditingStoppedEvent),
             _producerType.getEventDescription(EditingStoppedEventId),
             const_cast<CellEditorBase *>(this)));

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void CellEditorBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    CellEditor *pThis = static_cast<CellEditor *>(this);

    pThis->execSync(static_cast<CellEditor *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif



void CellEditorBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
