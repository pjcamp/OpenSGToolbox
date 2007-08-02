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
 **     class UIRectangle!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"
#include "UIDrawingSurface/OSGUIDrawingSurface.h"

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &UIRectangleBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 UIRectangleBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

//! create a new instance of the class
inline
UIRectanglePtr UIRectangleBase::create(void) 
{
    UIRectanglePtr fc; 

    if(getClassType().getPrototype() != OSG::NullFC) 
    {
        fc = UIRectanglePtr::dcast(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

//! create an empty new instance of the class, do not copy the prototype
inline
UIRectanglePtr UIRectangleBase::createEmpty(void) 
{ 
    UIRectanglePtr returnValue; 
    
    newPtr(returnValue); 

    return returnValue; 
}


/*------------------------------ get -----------------------------------*/

//! Get the UIRectangle::_sfPoint field.
inline
SFPnt3f *UIRectangleBase::getSFPoint(void)
{
    return &_sfPoint;
}

//! Get the UIRectangle::_sfWidth field.
inline
SFReal32 *UIRectangleBase::getSFWidth(void)
{
    return &_sfWidth;
}

//! Get the UIRectangle::_sfHeight field.
inline
SFReal32 *UIRectangleBase::getSFHeight(void)
{
    return &_sfHeight;
}

//! Get the UIRectangle::_sfDrawingSurface field.
inline
SFUIDrawingSurfacePtr *UIRectangleBase::getSFDrawingSurface(void)
{
    return &_sfDrawingSurface;
}

//! Get the UIRectangle::_sfRectColorMask field.
inline
SFColorMaskChunkPtr *UIRectangleBase::getSFRectColorMask(void)
{
    return &_sfRectColorMask;
}

//! Get the UIRectangle::_sfRectPolygon field.
inline
SFPolygonChunkPtr *UIRectangleBase::getSFRectPolygon(void)
{
    return &_sfRectPolygon;
}

//! Get the UIRectangle::_sfMouseTransformFunctor field.
inline
SFUIRectangleMouseTransformFunctorPtr *UIRectangleBase::getSFMouseTransformFunctor(void)
{
    return &_sfMouseTransformFunctor;
}


//! Get the value of the UIRectangle::_sfPoint field.
inline
Pnt3f &UIRectangleBase::getPoint(void)
{
    return _sfPoint.getValue();
}

//! Get the value of the UIRectangle::_sfPoint field.
inline
const Pnt3f &UIRectangleBase::getPoint(void) const
{
    return _sfPoint.getValue();
}

//! Set the value of the UIRectangle::_sfPoint field.
inline
void UIRectangleBase::setPoint(const Pnt3f &value)
{
    _sfPoint.setValue(value);
}

//! Get the value of the UIRectangle::_sfWidth field.
inline
Real32 &UIRectangleBase::getWidth(void)
{
    return _sfWidth.getValue();
}

//! Get the value of the UIRectangle::_sfWidth field.
inline
const Real32 &UIRectangleBase::getWidth(void) const
{
    return _sfWidth.getValue();
}

//! Set the value of the UIRectangle::_sfWidth field.
inline
void UIRectangleBase::setWidth(const Real32 &value)
{
    _sfWidth.setValue(value);
}

//! Get the value of the UIRectangle::_sfHeight field.
inline
Real32 &UIRectangleBase::getHeight(void)
{
    return _sfHeight.getValue();
}

//! Get the value of the UIRectangle::_sfHeight field.
inline
const Real32 &UIRectangleBase::getHeight(void) const
{
    return _sfHeight.getValue();
}

//! Set the value of the UIRectangle::_sfHeight field.
inline
void UIRectangleBase::setHeight(const Real32 &value)
{
    _sfHeight.setValue(value);
}

//! Get the value of the UIRectangle::_sfDrawingSurface field.
inline
UIDrawingSurfacePtr &UIRectangleBase::getDrawingSurface(void)
{
    return _sfDrawingSurface.getValue();
}

//! Get the value of the UIRectangle::_sfDrawingSurface field.
inline
const UIDrawingSurfacePtr &UIRectangleBase::getDrawingSurface(void) const
{
    return _sfDrawingSurface.getValue();
}

//! Set the value of the UIRectangle::_sfDrawingSurface field.
inline
void UIRectangleBase::setDrawingSurface(const UIDrawingSurfacePtr &value)
{
	if(getDrawingSurface() != NullFC)
	{
		getDrawingSurface()->removeMouseTransformFunctor(getMouseTransformFunctor());
	}
    _sfDrawingSurface.setValue(value);
	if(getDrawingSurface() != NullFC)
	{
		getDrawingSurface()->addMouseTransformFunctor(getMouseTransformFunctor());
	}
}

//! Get the value of the UIRectangle::_sfRectColorMask field.
inline
ColorMaskChunkPtr &UIRectangleBase::getRectColorMask(void)
{
    return _sfRectColorMask.getValue();
}

//! Get the value of the UIRectangle::_sfRectColorMask field.
inline
const ColorMaskChunkPtr &UIRectangleBase::getRectColorMask(void) const
{
    return _sfRectColorMask.getValue();
}

//! Set the value of the UIRectangle::_sfRectColorMask field.
inline
void UIRectangleBase::setRectColorMask(const ColorMaskChunkPtr &value)
{
    _sfRectColorMask.setValue(value);
}

//! Get the value of the UIRectangle::_sfRectPolygon field.
inline
PolygonChunkPtr &UIRectangleBase::getRectPolygon(void)
{
    return _sfRectPolygon.getValue();
}

//! Get the value of the UIRectangle::_sfRectPolygon field.
inline
const PolygonChunkPtr &UIRectangleBase::getRectPolygon(void) const
{
    return _sfRectPolygon.getValue();
}

//! Set the value of the UIRectangle::_sfRectPolygon field.
inline
void UIRectangleBase::setRectPolygon(const PolygonChunkPtr &value)
{
    _sfRectPolygon.setValue(value);
}

//! Get the value of the UIRectangle::_sfMouseTransformFunctor field.
inline
UIRectangleMouseTransformFunctorPtr &UIRectangleBase::getMouseTransformFunctor(void)
{
    return _sfMouseTransformFunctor.getValue();
}

//! Get the value of the UIRectangle::_sfMouseTransformFunctor field.
inline
const UIRectangleMouseTransformFunctorPtr &UIRectangleBase::getMouseTransformFunctor(void) const
{
    return _sfMouseTransformFunctor.getValue();
}

//! Set the value of the UIRectangle::_sfMouseTransformFunctor field.
inline
void UIRectangleBase::setMouseTransformFunctor(const UIRectangleMouseTransformFunctorPtr &value)
{
    _sfMouseTransformFunctor.setValue(value);
}


OSG_END_NAMESPACE

#define OSGUIRECTANGLEBASE_INLINE_CVSID "@(#)$Id: FCBaseTemplate_inl.h,v 1.20 2002/12/04 14:22:22 dirk Exp $"

