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

#include "OSGAbstractCellEditor.h"
#include <boost/bind.hpp>

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGAbstractCellEditorBase.cpp file.
// To modify it, please change the .fcd file (OSGAbstractCellEditor.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void AbstractCellEditor::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
    }
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

void AbstractCellEditor::cancelCellEditing(void)
{
    produceEditingCanceled();
}

bool AbstractCellEditor::isCellEditable(const EventUnrecPtr anEvent) const
{
    return true;
}

bool AbstractCellEditor::shouldSelectCell(const EventUnrecPtr anEvent) const
{
    return true;
}

bool AbstractCellEditor::stopCellEditing(void)
{
    produceEditingStopped();
    return true;
}

EventConnection AbstractCellEditor::addCellEditorListener(CellEditorListenerPtr l)
{
    _CellEditorListeners.insert(l);
    return EventConnection(
                           boost::bind(&AbstractCellEditor::isCellEditorListenerAttached, this, l),
                           boost::bind(&AbstractCellEditor::removeCellEditorListener, this, l));
}

void AbstractCellEditor::removeCellEditorListener(CellEditorListenerPtr l)
{
    CellEditorListenerSetItor EraseIter(_CellEditorListeners.find(l));
    if(EraseIter != _CellEditorListeners.end())
    {
        _CellEditorListeners.erase(EraseIter);
    }
}

void AbstractCellEditor::produceEditingCanceled(void)
{
    const ChangeEventUnrecPtr TheEvent = ChangeEvent::create(NULL, getSystemTime());
    CellEditorListenerSet CellEditorListenerSet(_CellEditorListeners);
    for(CellEditorListenerSetConstItor SetItor(CellEditorListenerSet.begin()) ; SetItor != CellEditorListenerSet.end() ; ++SetItor)
    {
        (*SetItor)->editingCanceled(TheEvent);
    }
    _Producer.produceEvent(EditingCanceledMethodId,TheEvent);
}

void AbstractCellEditor::produceEditingStopped(void)
{
    const ChangeEventUnrecPtr TheEvent = ChangeEvent::create(NULL, getSystemTime());
    CellEditorListenerSet CellEditorListenerSet(_CellEditorListeners);
    for(CellEditorListenerSetConstItor SetItor(CellEditorListenerSet.begin()) ; SetItor != CellEditorListenerSet.end() ; ++SetItor)
    {
        (*SetItor)->editingStopped(TheEvent);
    }
    _Producer.produceEvent(EditingStoppedMethodId,TheEvent);
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

AbstractCellEditor::AbstractCellEditor(void) :
    Inherited()
{
}

AbstractCellEditor::AbstractCellEditor(const AbstractCellEditor &source) :
    Inherited(source)
{
}

AbstractCellEditor::~AbstractCellEditor(void)
{
}

/*----------------------------- class specific ----------------------------*/

void AbstractCellEditor::changed(ConstFieldMaskArg whichField, 
                            UInt32            origin,
                            BitVector         details)
{
    Inherited::changed(whichField, origin, details);
}

void AbstractCellEditor::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump AbstractCellEditor NI" << std::endl;
}

OSG_END_NAMESPACE
