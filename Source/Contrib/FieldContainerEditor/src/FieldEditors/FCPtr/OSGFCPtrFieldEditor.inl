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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

OSG_BEGIN_NAMESPACE

inline
FCPtrFieldEditor::TextFieldListener::TextFieldListener(FCPtrFieldEditor * ptr) : _FCPtrFieldEditor(ptr)
{
}

inline
FCPtrFieldEditor::MenuButtonFieldListener::MenuButtonFieldListener(FCPtrFieldEditor * ptr) : _FCPtrFieldEditor(ptr)
{
}

inline
FCPtrFieldEditor::CreateContainerDialogListener::CreateContainerDialogListener(FCPtrFieldEditor * ptr) : _FCPtrFieldEditor(ptr)
{
}

inline
FCPtrFieldEditor::FindContainerDialogListener::FindContainerDialogListener(FCPtrFieldEditor * ptr) : _FCPtrFieldEditor(ptr)
{
}

inline
FCPtrEditorStorePtr FCPtrFieldEditor::getFCStore(void) const
{
    return _FindFCStore;
}

inline
void FCPtrFieldEditor::setFCStore(FCPtrEditorStorePtr store)
{
    _FindFCStore = store;
}

OSG_END_NAMESPACE