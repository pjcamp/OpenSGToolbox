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
 **     class Font!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <OpenSG/OSGConfig.h>

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &FontBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 FontBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

//! create a new instance of the class
inline
FontPtr FontBase::create(void) 
{
    FontPtr fc; 

    if(getClassType().getPrototype() != OSG::NullFC) 
    {
        fc = FontPtr::dcast(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

//! create an empty new instance of the class, do not copy the prototype
inline
FontPtr FontBase::createEmpty(void) 
{ 
    FontPtr returnValue; 
    
    newPtr(returnValue); 

    return returnValue; 
}


/*------------------------------ get -----------------------------------*/

//! Get the Font::_sfFamily field.
inline
SFString *FontBase::getSFFamily(void)
{
    return &_sfFamily;
}

//! Get the Font::_sfGlyphPixelSize field.
inline
SFUInt32 *FontBase::getSFGlyphPixelSize(void)
{
    return &_sfGlyphPixelSize;
}

//! Get the Font::_sfSize field.
inline
SFUInt32 *FontBase::getSFSize(void)
{
    return &_sfSize;
}

//! Get the Font::_sfGap field.
inline
SFUInt32 *FontBase::getSFGap(void)
{
    return &_sfGap;
}

//! Get the Font::_sfTextureWidth field.
inline
SFUInt32 *FontBase::getSFTextureWidth(void)
{
    return &_sfTextureWidth;
}

//! Get the Font::_sfStyle field.
inline
SFUInt32 *FontBase::getSFStyle(void)
{
    return &_sfStyle;
}

//! Get the Font::_sfTexture field.
inline
SFTextureChunkPtr *FontBase::getSFTexture(void)
{
    return &_sfTexture;
}


//! Get the value of the Font::_sfFamily field.
inline
std::string &FontBase::getFamily(void)
{
    return _sfFamily.getValue();
}

//! Get the value of the Font::_sfFamily field.
inline
const std::string &FontBase::getFamily(void) const
{
    return _sfFamily.getValue();
}

//! Set the value of the Font::_sfFamily field.
inline
void FontBase::setFamily(const std::string &value)
{
    _sfFamily.setValue(value);
}

//! Get the value of the Font::_sfGlyphPixelSize field.
inline
UInt32 &FontBase::getGlyphPixelSize(void)
{
    return _sfGlyphPixelSize.getValue();
}

//! Get the value of the Font::_sfGlyphPixelSize field.
inline
const UInt32 &FontBase::getGlyphPixelSize(void) const
{
    return _sfGlyphPixelSize.getValue();
}

//! Set the value of the Font::_sfGlyphPixelSize field.
inline
void FontBase::setGlyphPixelSize(const UInt32 &value)
{
    _sfGlyphPixelSize.setValue(value);
}

//! Get the value of the Font::_sfSize field.
inline
UInt32 &FontBase::getSize(void)
{
    return _sfSize.getValue();
}

//! Get the value of the Font::_sfSize field.
inline
const UInt32 &FontBase::getSize(void) const
{
    return _sfSize.getValue();
}

//! Set the value of the Font::_sfSize field.
inline
void FontBase::setSize(const UInt32 &value)
{
    _sfSize.setValue(value);
}

//! Get the value of the Font::_sfGap field.
inline
UInt32 &FontBase::getGap(void)
{
    return _sfGap.getValue();
}

//! Get the value of the Font::_sfGap field.
inline
const UInt32 &FontBase::getGap(void) const
{
    return _sfGap.getValue();
}

//! Set the value of the Font::_sfGap field.
inline
void FontBase::setGap(const UInt32 &value)
{
    _sfGap.setValue(value);
}

//! Get the value of the Font::_sfTextureWidth field.
inline
UInt32 &FontBase::getTextureWidth(void)
{
    return _sfTextureWidth.getValue();
}

//! Get the value of the Font::_sfTextureWidth field.
inline
const UInt32 &FontBase::getTextureWidth(void) const
{
    return _sfTextureWidth.getValue();
}

//! Set the value of the Font::_sfTextureWidth field.
inline
void FontBase::setTextureWidth(const UInt32 &value)
{
    _sfTextureWidth.setValue(value);
}

//! Get the value of the Font::_sfStyle field.
inline
UInt32 &FontBase::getStyle(void)
{
    return _sfStyle.getValue();
}

//! Get the value of the Font::_sfStyle field.
inline
const UInt32 &FontBase::getStyle(void) const
{
    return _sfStyle.getValue();
}

//! Set the value of the Font::_sfStyle field.
inline
void FontBase::setStyle(const UInt32 &value)
{
    _sfStyle.setValue(value);
}

//! Get the value of the Font::_sfTexture field.
inline
TextureChunkPtr &FontBase::getTexture(void)
{
    return _sfTexture.getValue();
}

//! Get the value of the Font::_sfTexture field.
inline
const TextureChunkPtr &FontBase::getTexture(void) const
{
    return _sfTexture.getValue();
}

//! Set the value of the Font::_sfTexture field.
inline
void FontBase::setTexture(const TextureChunkPtr &value)
{
    _sfTexture.setValue(value);
}


OSG_END_NAMESPACE

#define OSGFONTBASE_INLINE_CVSID "@(#)$Id: FCBaseTemplate_inl.h,v 1.20 2002/12/04 14:22:22 dirk Exp $"

