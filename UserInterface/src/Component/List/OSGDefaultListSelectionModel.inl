/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2002 by the OpenSG Forum                 *
 *                                                                           *
 *   contact: dirk@opensg.org, gerrit.voss@vossg.org, jbehr@zgdv.de          *
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

#include <OpenSG/OSGConfig.h>

OSG_BEGIN_NAMESPACE

inline
void DefaultListSelectionModel::addListSelectionListener(ListSelectionListenerPtr Listener)
{
   _ListSelectionListeners.insert(Listener);
}

inline
void DefaultListSelectionModel::removeListSelectionListener(ListSelectionListenerPtr Listener)
{
   ListSelectionListenerSetItor EraseIter(_ListSelectionListeners.find(Listener));
   if(EraseIter != _ListSelectionListeners.end())
   {
      _ListSelectionListeners.erase(EraseIter);
   }
}

inline
void DefaultListSelectionModel::setMode(SelectionMode Mode)
{
	_SelectionMode = Mode;
}

inline
DefaultListSelectionModel::SelectionMode DefaultListSelectionModel::getMode(void) const
{
	return _SelectionMode;
}

OSG_END_NAMESPACE


