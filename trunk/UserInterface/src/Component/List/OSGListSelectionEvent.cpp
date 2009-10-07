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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>

#define OSG_COMPILEUSERINTERFACELIB

#include <OpenSG/OSGConfig.h>

#include "OSGListSelectionEvent.h"

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class osg::ListSelectionEvent

*/

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void ListSelectionEvent::initMethod (void)
{
}

ListSelectionEventPtr ListSelectionEvent::create(  FieldContainerPtr Source,
                                                   Time TimeStamp,
                                                   Int32 FirstIndex,
                                                   Int32 LastIndex,
                                                   bool ValueIsAdjusting)
{
    ListSelectionEventPtr TheEvent = ListSelectionEvent::createEmpty();

    TheEvent->setSource(Source);
    TheEvent->setTimeStamp(TimeStamp);
    TheEvent->setFirstIndex(FirstIndex);
    TheEvent->setLastIndex(LastIndex);
    TheEvent->setValueIsAdjusting(ValueIsAdjusting);

    return TheEvent;
}

/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

ListSelectionEvent::ListSelectionEvent(void) :
    Inherited()
{
}

ListSelectionEvent::ListSelectionEvent(const ListSelectionEvent &source) :
    Inherited(source)
{
}

ListSelectionEvent::~ListSelectionEvent(void)
{
}

/*----------------------------- class specific ----------------------------*/

void ListSelectionEvent::changed(BitVector whichField, UInt32 origin)
{
    Inherited::changed(whichField, origin);
}

void ListSelectionEvent::dump(      UInt32    , 
                         const BitVector ) const
{
    SLOG << "Dump ListSelectionEvent NI" << std::endl;
}


OSG_END_NAMESPACE

