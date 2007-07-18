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
 **     class Graphics!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <OpenSG/OSGConfig.h>

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &GraphicsBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 GraphicsBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 


/*------------------------------ get -----------------------------------*/

//! Get the Graphics::_sfOpacity field.
inline
SFReal32 *GraphicsBase::getSFOpacity(void)
{
    return &_sfOpacity;
}

//! Get the Graphics::_sfEnablePointAntiAliasing field.
inline
SFBool *GraphicsBase::getSFEnablePointAntiAliasing(void)
{
    return &_sfEnablePointAntiAliasing;
}

//! Get the Graphics::_sfEnableLineAntiAliasing field.
inline
SFBool *GraphicsBase::getSFEnableLineAntiAliasing(void)
{
    return &_sfEnableLineAntiAliasing;
}

//! Get the Graphics::_sfEnablePolygonAntiAliasing field.
inline
SFBool *GraphicsBase::getSFEnablePolygonAntiAliasing(void)
{
    return &_sfEnablePolygonAntiAliasing;
}


//! Get the value of the Graphics::_sfOpacity field.
inline
Real32 &GraphicsBase::getOpacity(void)
{
    return _sfOpacity.getValue();
}

//! Get the value of the Graphics::_sfOpacity field.
inline
const Real32 &GraphicsBase::getOpacity(void) const
{
    return _sfOpacity.getValue();
}

//! Set the value of the Graphics::_sfOpacity field.
inline
void GraphicsBase::setOpacity(const Real32 &value)
{
    _sfOpacity.setValue(value);
}

//! Get the value of the Graphics::_sfEnablePointAntiAliasing field.
inline
bool &GraphicsBase::getEnablePointAntiAliasing(void)
{
    return _sfEnablePointAntiAliasing.getValue();
}

//! Get the value of the Graphics::_sfEnablePointAntiAliasing field.
inline
const bool &GraphicsBase::getEnablePointAntiAliasing(void) const
{
    return _sfEnablePointAntiAliasing.getValue();
}

//! Set the value of the Graphics::_sfEnablePointAntiAliasing field.
inline
void GraphicsBase::setEnablePointAntiAliasing(const bool &value)
{
    _sfEnablePointAntiAliasing.setValue(value);
}

//! Get the value of the Graphics::_sfEnableLineAntiAliasing field.
inline
bool &GraphicsBase::getEnableLineAntiAliasing(void)
{
    return _sfEnableLineAntiAliasing.getValue();
}

//! Get the value of the Graphics::_sfEnableLineAntiAliasing field.
inline
const bool &GraphicsBase::getEnableLineAntiAliasing(void) const
{
    return _sfEnableLineAntiAliasing.getValue();
}

//! Set the value of the Graphics::_sfEnableLineAntiAliasing field.
inline
void GraphicsBase::setEnableLineAntiAliasing(const bool &value)
{
    _sfEnableLineAntiAliasing.setValue(value);
}

//! Get the value of the Graphics::_sfEnablePolygonAntiAliasing field.
inline
bool &GraphicsBase::getEnablePolygonAntiAliasing(void)
{
    return _sfEnablePolygonAntiAliasing.getValue();
}

//! Get the value of the Graphics::_sfEnablePolygonAntiAliasing field.
inline
const bool &GraphicsBase::getEnablePolygonAntiAliasing(void) const
{
    return _sfEnablePolygonAntiAliasing.getValue();
}

//! Set the value of the Graphics::_sfEnablePolygonAntiAliasing field.
inline
void GraphicsBase::setEnablePolygonAntiAliasing(const bool &value)
{
    _sfEnablePolygonAntiAliasing.setValue(value);
}


OSG_END_NAMESPACE

#define OSGGRAPHICSBASE_INLINE_CVSID "@(#)$Id: FCBaseTemplate_inl.h,v 1.20 2002/12/04 14:22:22 dirk Exp $"

