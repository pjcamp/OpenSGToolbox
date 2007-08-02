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
 **     class Button!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <OpenSG/OSGConfig.h>

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &ButtonBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 ButtonBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

//! create a new instance of the class
inline
ButtonPtr ButtonBase::create(void) 
{
    ButtonPtr fc; 

    if(getClassType().getPrototype() != OSG::NullFC) 
    {
        fc = ButtonPtr::dcast(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

//! create an empty new instance of the class, do not copy the prototype
inline
ButtonPtr ButtonBase::createEmpty(void) 
{ 
    ButtonPtr returnValue; 
    
    newPtr(returnValue); 

    return returnValue; 
}


/*------------------------------ get -----------------------------------*/

//! Get the Button::_sfFont field.
inline
SFFontPtr *ButtonBase::getSFFont(void)
{
    return &_sfFont;
}

//! Get the Button::_sfText field.
inline
SFString *ButtonBase::getSFText(void)
{
    return &_sfText;
}

//! Get the Button::_sfActive field.
inline
SFBool *ButtonBase::getSFActive(void)
{
    return &_sfActive;
}

//! Get the Button::_sfActiveBorder field.
inline
SFBorderPtr *ButtonBase::getSFActiveBorder(void)
{
    return &_sfActiveBorder;
}

//! Get the Button::_sfActiveBackground field.
inline
SFUIBackgroundPtr *ButtonBase::getSFActiveBackground(void)
{
    return &_sfActiveBackground;
}

//! Get the Button::_sfActiveForegroundColor field.
inline
SFColor4f *ButtonBase::getSFActiveForegroundColor(void)
{
    return &_sfActiveForegroundColor;
}

//! Get the Button::_sfVerticalAlignment field.
inline
SFUInt32 *ButtonBase::getSFVerticalAlignment(void)
{
    return &_sfVerticalAlignment;
}

//! Get the Button::_sfHorizontalAlignment field.
inline
SFUInt32 *ButtonBase::getSFHorizontalAlignment(void)
{
    return &_sfHorizontalAlignment;
}


//! Get the value of the Button::_sfFont field.
inline
FontPtr &ButtonBase::getFont(void)
{
    return _sfFont.getValue();
}

//! Get the value of the Button::_sfFont field.
inline
const FontPtr &ButtonBase::getFont(void) const
{
    return _sfFont.getValue();
}

//! Set the value of the Button::_sfFont field.
inline
void ButtonBase::setFont(const FontPtr &value)
{
    _sfFont.setValue(value);
}

//! Get the value of the Button::_sfText field.
inline
std::string &ButtonBase::getText(void)
{
    return _sfText.getValue();
}

//! Get the value of the Button::_sfText field.
inline
const std::string &ButtonBase::getText(void) const
{
    return _sfText.getValue();
}

//! Set the value of the Button::_sfText field.
inline
void ButtonBase::setText(const std::string &value)
{
    _sfText.setValue(value);
}

//! Get the value of the Button::_sfActive field.
inline
bool &ButtonBase::getActive(void)
{
    return _sfActive.getValue();
}

//! Get the value of the Button::_sfActive field.
inline
const bool &ButtonBase::getActive(void) const
{
    return _sfActive.getValue();
}

//! Set the value of the Button::_sfActive field.
inline
void ButtonBase::setActive(const bool &value)
{
    _sfActive.setValue(value);
}

//! Get the value of the Button::_sfActiveBorder field.
inline
BorderPtr &ButtonBase::getActiveBorder(void)
{
    return _sfActiveBorder.getValue();
}

//! Get the value of the Button::_sfActiveBorder field.
inline
const BorderPtr &ButtonBase::getActiveBorder(void) const
{
    return _sfActiveBorder.getValue();
}

//! Set the value of the Button::_sfActiveBorder field.
inline
void ButtonBase::setActiveBorder(const BorderPtr &value)
{
    _sfActiveBorder.setValue(value);
}

//! Get the value of the Button::_sfActiveBackground field.
inline
UIBackgroundPtr &ButtonBase::getActiveBackground(void)
{
    return _sfActiveBackground.getValue();
}

//! Get the value of the Button::_sfActiveBackground field.
inline
const UIBackgroundPtr &ButtonBase::getActiveBackground(void) const
{
    return _sfActiveBackground.getValue();
}

//! Set the value of the Button::_sfActiveBackground field.
inline
void ButtonBase::setActiveBackground(const UIBackgroundPtr &value)
{
    _sfActiveBackground.setValue(value);
}

//! Get the value of the Button::_sfActiveForegroundColor field.
inline
Color4f &ButtonBase::getActiveForegroundColor(void)
{
    return _sfActiveForegroundColor.getValue();
}

//! Get the value of the Button::_sfActiveForegroundColor field.
inline
const Color4f &ButtonBase::getActiveForegroundColor(void) const
{
    return _sfActiveForegroundColor.getValue();
}

//! Set the value of the Button::_sfActiveForegroundColor field.
inline
void ButtonBase::setActiveForegroundColor(const Color4f &value)
{
    _sfActiveForegroundColor.setValue(value);
}

//! Get the value of the Button::_sfVerticalAlignment field.
inline
UInt32 &ButtonBase::getVerticalAlignment(void)
{
    return _sfVerticalAlignment.getValue();
}

//! Get the value of the Button::_sfVerticalAlignment field.
inline
const UInt32 &ButtonBase::getVerticalAlignment(void) const
{
    return _sfVerticalAlignment.getValue();
}

//! Set the value of the Button::_sfVerticalAlignment field.
inline
void ButtonBase::setVerticalAlignment(const UInt32 &value)
{
    _sfVerticalAlignment.setValue(value);
}

//! Get the value of the Button::_sfHorizontalAlignment field.
inline
UInt32 &ButtonBase::getHorizontalAlignment(void)
{
    return _sfHorizontalAlignment.getValue();
}

//! Get the value of the Button::_sfHorizontalAlignment field.
inline
const UInt32 &ButtonBase::getHorizontalAlignment(void) const
{
    return _sfHorizontalAlignment.getValue();
}

//! Set the value of the Button::_sfHorizontalAlignment field.
inline
void ButtonBase::setHorizontalAlignment(const UInt32 &value)
{
    _sfHorizontalAlignment.setValue(value);
}


OSG_END_NAMESPACE

#define OSGBUTTONBASE_INLINE_CVSID "@(#)$Id: FCBaseTemplate_inl.h,v 1.20 2002/12/04 14:22:22 dirk Exp $"

