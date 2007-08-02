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

/*****************************************************************************\
 *****************************************************************************
 **                                                                         **
 **                  This file is automatically generated.                  **
 **                                                                         **
 **          Any changes made to this file WILL be lost when it is          **
 **           regenerated, which can become necessary at any time.          **
 **                                                                         **
 **     Do not change this file, changes should be done in the derived      **
 **     class Scrollbar!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <OpenSG/OSGConfig.h>

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &ScrollbarBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 ScrollbarBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

//! create a new instance of the class
inline
ScrollbarPtr ScrollbarBase::create(void) 
{
    ScrollbarPtr fc; 

    if(getClassType().getPrototype() != OSG::NullFC) 
    {
        fc = ScrollbarPtr::dcast(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

//! create an empty new instance of the class, do not copy the prototype
inline
ScrollbarPtr ScrollbarBase::createEmpty(void) 
{ 
    ScrollbarPtr returnValue; 
    
    newPtr(returnValue); 

    return returnValue; 
}


/*------------------------------ get -----------------------------------*/

//! Get the Scrollbar::_sfOrientation field.
inline
SFUInt32 *ScrollbarBase::getSFOrientation(void)
{
    return &_sfOrientation;
}

//! Get the Scrollbar::_sfUnitIncrement field.
inline
SFUInt32 *ScrollbarBase::getSFUnitIncrement(void)
{
    return &_sfUnitIncrement;
}

//! Get the Scrollbar::_sfBlockIncrement field.
inline
SFUInt32 *ScrollbarBase::getSFBlockIncrement(void)
{
    return &_sfBlockIncrement;
}

//! Get the Scrollbar::_sfMinButton field.
inline
SFButtonPtr *ScrollbarBase::getSFMinButton(void)
{
    return &_sfMinButton;
}

//! Get the Scrollbar::_sfMaxButton field.
inline
SFButtonPtr *ScrollbarBase::getSFMaxButton(void)
{
    return &_sfMaxButton;
}

//! Get the Scrollbar::_sfScrollbar field.
inline
SFUIDrawObjectCanvasPtr *ScrollbarBase::getSFScrollbar(void)
{
    return &_sfScrollbar;
}

//! Get the Scrollbar::_sfScrollField field.
inline
SFUIDrawObjectCanvasPtr *ScrollbarBase::getSFScrollField(void)
{
    return &_sfScrollField;
}


//! Get the value of the Scrollbar::_sfOrientation field.
inline
UInt32 &ScrollbarBase::getOrientation(void)
{
    return _sfOrientation.getValue();
}

//! Get the value of the Scrollbar::_sfOrientation field.
inline
const UInt32 &ScrollbarBase::getOrientation(void) const
{
    return _sfOrientation.getValue();
}

//! Set the value of the Scrollbar::_sfOrientation field.
inline
void ScrollbarBase::setOrientation(const UInt32 &value)
{
    _sfOrientation.setValue(value);
}

//! Get the value of the Scrollbar::_sfUnitIncrement field.
inline
UInt32 &ScrollbarBase::getUnitIncrement(void)
{
    return _sfUnitIncrement.getValue();
}

//! Get the value of the Scrollbar::_sfUnitIncrement field.
inline
const UInt32 &ScrollbarBase::getUnitIncrement(void) const
{
    return _sfUnitIncrement.getValue();
}

//! Set the value of the Scrollbar::_sfUnitIncrement field.
inline
void ScrollbarBase::setUnitIncrement(const UInt32 &value)
{
    _sfUnitIncrement.setValue(value);
}

//! Get the value of the Scrollbar::_sfBlockIncrement field.
inline
UInt32 &ScrollbarBase::getBlockIncrement(void)
{
    return _sfBlockIncrement.getValue();
}

//! Get the value of the Scrollbar::_sfBlockIncrement field.
inline
const UInt32 &ScrollbarBase::getBlockIncrement(void) const
{
    return _sfBlockIncrement.getValue();
}

//! Set the value of the Scrollbar::_sfBlockIncrement field.
inline
void ScrollbarBase::setBlockIncrement(const UInt32 &value)
{
    _sfBlockIncrement.setValue(value);
}

//! Get the value of the Scrollbar::_sfMinButton field.
inline
ButtonPtr &ScrollbarBase::getMinButton(void)
{
    return _sfMinButton.getValue();
}

//! Get the value of the Scrollbar::_sfMinButton field.
inline
const ButtonPtr &ScrollbarBase::getMinButton(void) const
{
    return _sfMinButton.getValue();
}

//! Set the value of the Scrollbar::_sfMinButton field.
inline
void ScrollbarBase::setMinButton(const ButtonPtr &value)
{
    _sfMinButton.setValue(value);
}

//! Get the value of the Scrollbar::_sfMaxButton field.
inline
ButtonPtr &ScrollbarBase::getMaxButton(void)
{
    return _sfMaxButton.getValue();
}

//! Get the value of the Scrollbar::_sfMaxButton field.
inline
const ButtonPtr &ScrollbarBase::getMaxButton(void) const
{
    return _sfMaxButton.getValue();
}

//! Set the value of the Scrollbar::_sfMaxButton field.
inline
void ScrollbarBase::setMaxButton(const ButtonPtr &value)
{
    _sfMaxButton.setValue(value);
}

//! Get the value of the Scrollbar::_sfScrollbar field.
inline
UIDrawObjectCanvasPtr &ScrollbarBase::getScrollbar(void)
{
    return _sfScrollbar.getValue();
}

//! Get the value of the Scrollbar::_sfScrollbar field.
inline
const UIDrawObjectCanvasPtr &ScrollbarBase::getScrollbar(void) const
{
    return _sfScrollbar.getValue();
}

//! Set the value of the Scrollbar::_sfScrollbar field.
inline
void ScrollbarBase::setScrollbar(const UIDrawObjectCanvasPtr &value)
{
    _sfScrollbar.setValue(value);
}

//! Get the value of the Scrollbar::_sfScrollField field.
inline
UIDrawObjectCanvasPtr &ScrollbarBase::getScrollField(void)
{
    return _sfScrollField.getValue();
}

//! Get the value of the Scrollbar::_sfScrollField field.
inline
const UIDrawObjectCanvasPtr &ScrollbarBase::getScrollField(void) const
{
    return _sfScrollField.getValue();
}

//! Set the value of the Scrollbar::_sfScrollField field.
inline
void ScrollbarBase::setScrollField(const UIDrawObjectCanvasPtr &value)
{
    _sfScrollField.setValue(value);
}


OSG_END_NAMESPACE

#define OSGSCROLLBARBASE_INLINE_CVSID "@(#)$Id: FCBaseTemplate_inl.h,v 1.20 2002/12/04 14:22:22 dirk Exp $"
