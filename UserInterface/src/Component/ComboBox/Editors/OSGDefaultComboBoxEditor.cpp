/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                         www.vrac.iastate.edu                              *
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

#include "OSGDefaultComboBoxEditor.h"
#include "Component/Text/OSGTextField.h"

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class osg::DefaultComboBoxEditor
A UI DefaultComboBoxEditor. 	
*/

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void DefaultComboBoxEditor::initMethod (void)
{
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

void DefaultComboBoxEditor::addActionListener(ActionListenerPtr Listener)
{
	if(getEditor() != NullFC)
	{
		getEditor()->addActionListener(Listener);
	}
}

void DefaultComboBoxEditor::removeActionListener(ActionListenerPtr Listener)
{
	if(getEditor() != NullFC)
	{
		getEditor()->removeActionListener(Listener);
	}
}

ComponentPtr DefaultComboBoxEditor::getEditorComponent(void)
{
	return getEditor();
}

SharedFieldPtr DefaultComboBoxEditor::getItem(void)
{
	//TODO: Implement
	return SharedFieldPtr();
}

void DefaultComboBoxEditor::selectAll(void)
{
	//TODO: Implement
	if(getEditor() != NullFC)
	{
		getEditor()->selectAll();
	}
}

void DefaultComboBoxEditor::setItem(SharedFieldPtr anObject)
{
	//TODO: Implement
}

void DefaultComboBoxEditor::focusGained(const FocusEvent& e)
{
	//TODO: Implement
	selectAll();
}

void DefaultComboBoxEditor::focusLost(const FocusEvent& e)
{
	//TODO: Implement
}
/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

DefaultComboBoxEditor::DefaultComboBoxEditor(void) :
    Inherited()
{
}

DefaultComboBoxEditor::DefaultComboBoxEditor(const DefaultComboBoxEditor &source) :
    Inherited(source)
{
}

DefaultComboBoxEditor::~DefaultComboBoxEditor(void)
{
}

/*----------------------------- class specific ----------------------------*/

void DefaultComboBoxEditor::changed(BitVector whichField, UInt32 origin)
{
    Inherited::changed(whichField, origin);

	if((whichField & EditorFieldMask) && getEditor() != NullFC)
	{
		getEditor()->addFocusListener(this);
	}
}

void DefaultComboBoxEditor::dump(      UInt32    , 
                         const BitVector ) const
{
    SLOG << "Dump DefaultComboBoxEditor NI" << std::endl;
}


/*------------------------------------------------------------------------*/
/*                              cvs id's                                  */

#ifdef OSG_SGI_CC
#pragma set woff 1174
#endif

#ifdef OSG_LINUX_ICC
#pragma warning( disable : 177 )
#endif

namespace
{
    static Char8 cvsid_cpp       [] = "@(#)$Id: FCTemplate_cpp.h,v 1.20 2006/03/16 17:01:53 dirk Exp $";
    static Char8 cvsid_hpp       [] = OSGDEFAULTCOMBOBOXEDITORBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGDEFAULTCOMBOBOXEDITORBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGDEFAULTCOMBOBOXEDITORFIELDS_HEADER_CVSID;
}

#ifdef __sgi
#pragma reset woff 1174
#endif

OSG_END_NAMESPACE
