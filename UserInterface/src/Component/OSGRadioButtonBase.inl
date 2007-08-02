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
 **     class RadioButton!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <OpenSG/OSGConfig.h>

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &RadioButtonBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 RadioButtonBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

//! create a new instance of the class
inline
RadioButtonPtr RadioButtonBase::create(void) 
{
    RadioButtonPtr fc; 

    if(getClassType().getPrototype() != OSG::NullFC) 
    {
        fc = RadioButtonPtr::dcast(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

//! create an empty new instance of the class, do not copy the prototype
inline
RadioButtonPtr RadioButtonBase::createEmpty(void) 
{ 
    RadioButtonPtr returnValue; 
    
    newPtr(returnValue); 

    return returnValue; 
}


/*------------------------------ get -----------------------------------*/

//! Get the RadioButton::_sfDrawObject field.
inline
SFUIDrawObjectCanvasPtr *RadioButtonBase::getSFDrawObject(void)
{
    return &_sfDrawObject;
}

//! Get the RadioButton::_sfSelectedDrawObject field.
inline
SFUIDrawObjectCanvasPtr *RadioButtonBase::getSFSelectedDrawObject(void)
{
    return &_sfSelectedDrawObject;
}

//! Get the RadioButton::_sfActiveDrawObject field.
inline
SFUIDrawObjectCanvasPtr *RadioButtonBase::getSFActiveDrawObject(void)
{
    return &_sfActiveDrawObject;
}

//! Get the RadioButton::_sfActiveSelectedDrawObject field.
inline
SFUIDrawObjectCanvasPtr *RadioButtonBase::getSFActiveSelectedDrawObject(void)
{
    return &_sfActiveSelectedDrawObject;
}


//! Get the value of the RadioButton::_sfDrawObject field.
inline
UIDrawObjectCanvasPtr &RadioButtonBase::getDrawObject(void)
{
    return _sfDrawObject.getValue();
}

//! Get the value of the RadioButton::_sfDrawObject field.
inline
const UIDrawObjectCanvasPtr &RadioButtonBase::getDrawObject(void) const
{
    return _sfDrawObject.getValue();
}

//! Set the value of the RadioButton::_sfDrawObject field.
inline
void RadioButtonBase::setDrawObject(const UIDrawObjectCanvasPtr &value)
{
    _sfDrawObject.setValue(value);
}

//! Get the value of the RadioButton::_sfSelectedDrawObject field.
inline
UIDrawObjectCanvasPtr &RadioButtonBase::getSelectedDrawObject(void)
{
    return _sfSelectedDrawObject.getValue();
}

//! Get the value of the RadioButton::_sfSelectedDrawObject field.
inline
const UIDrawObjectCanvasPtr &RadioButtonBase::getSelectedDrawObject(void) const
{
    return _sfSelectedDrawObject.getValue();
}

//! Set the value of the RadioButton::_sfSelectedDrawObject field.
inline
void RadioButtonBase::setSelectedDrawObject(const UIDrawObjectCanvasPtr &value)
{
    _sfSelectedDrawObject.setValue(value);
}

//! Get the value of the RadioButton::_sfActiveDrawObject field.
inline
UIDrawObjectCanvasPtr &RadioButtonBase::getActiveDrawObject(void)
{
    return _sfActiveDrawObject.getValue();
}

//! Get the value of the RadioButton::_sfActiveDrawObject field.
inline
const UIDrawObjectCanvasPtr &RadioButtonBase::getActiveDrawObject(void) const
{
    return _sfActiveDrawObject.getValue();
}

//! Set the value of the RadioButton::_sfActiveDrawObject field.
inline
void RadioButtonBase::setActiveDrawObject(const UIDrawObjectCanvasPtr &value)
{
    _sfActiveDrawObject.setValue(value);
}

//! Get the value of the RadioButton::_sfActiveSelectedDrawObject field.
inline
UIDrawObjectCanvasPtr &RadioButtonBase::getActiveSelectedDrawObject(void)
{
    return _sfActiveSelectedDrawObject.getValue();
}

//! Get the value of the RadioButton::_sfActiveSelectedDrawObject field.
inline
const UIDrawObjectCanvasPtr &RadioButtonBase::getActiveSelectedDrawObject(void) const
{
    return _sfActiveSelectedDrawObject.getValue();
}

//! Set the value of the RadioButton::_sfActiveSelectedDrawObject field.
inline
void RadioButtonBase::setActiveSelectedDrawObject(const UIDrawObjectCanvasPtr &value)
{
    _sfActiveSelectedDrawObject.setValue(value);
}


OSG_END_NAMESPACE

#define OSGRADIOBUTTONBASE_INLINE_CVSID "@(#)$Id: FCBaseTemplate_inl.h,v 1.20 2002/12/04 14:22:22 dirk Exp $"

