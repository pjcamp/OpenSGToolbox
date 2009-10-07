/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
 *                                                                           *
 *                                                                           *
 *                                                                           *
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

/*****************************************************************************\
 *****************************************************************************
 **                                                                         **
 **                  This file is automatically generated.                  **
 **                                                                         **
 **          Any changes made to this file WILL be lost when it is          **
 **           regenerated, which can become necessary at any time.          **
 **                                                                         **
 **     Do not change this file, changes should be done in the derived      **
 **     class UIViewport!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <OpenSG/OSGConfig.h>

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &UIViewportBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 UIViewportBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

//! access the producer type of the class
inline
const EventProducerType &UIViewportBase::getProducerClassType(void)
{
    return _producerType;
}

//! access the producer type id of the class
inline
UInt32 UIViewportBase::getProducerClassTypeId(void)
{
    return _producerType.getId();
}

//! create a new instance of the class
inline
UIViewportPtr UIViewportBase::create(void) 
{
    UIViewportPtr fc; 

    if(getClassType().getPrototype() != OSG::NullFC) 
    {
        fc = UIViewportPtr::dcast(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

//! create an empty new instance of the class, do not copy the prototype
inline
UIViewportPtr UIViewportBase::createEmpty(void) 
{ 
    UIViewportPtr returnValue; 
    
    newPtr(returnValue); 

    return returnValue; 
}


/*------------------------------ get -----------------------------------*/

//! Get the UIViewport::_sfViewPosition field.
inline
const SFPnt2s *UIViewportBase::getSFViewPosition(void) const
{
    return &_sfViewPosition;
}

//! Get the UIViewport::_sfViewPosition field.
inline
SFPnt2s *UIViewportBase::editSFViewPosition(void)
{
    return &_sfViewPosition;
}

//! Get the UIViewport::_sfViewComponent field.
inline
const SFComponentPtr *UIViewportBase::getSFViewComponent(void) const
{
    return &_sfViewComponent;
}

//! Get the UIViewport::_sfViewComponent field.
inline
SFComponentPtr *UIViewportBase::editSFViewComponent(void)
{
    return &_sfViewComponent;
}

//! Get the UIViewport::_sfViewSize field.
inline
const SFVec2s *UIViewportBase::getSFViewSize(void) const
{
    return &_sfViewSize;
}

//! Get the UIViewport::_sfViewSize field.
inline
SFVec2s *UIViewportBase::editSFViewSize(void)
{
    return &_sfViewSize;
}


//! Get the value of the UIViewport::_sfViewPosition field.
inline
Pnt2s &UIViewportBase::editViewPosition(void)
{
    return _sfViewPosition.getValue();
}

//! Get the value of the UIViewport::_sfViewPosition field.
inline
const Pnt2s &UIViewportBase::getViewPosition(void) const
{
    return _sfViewPosition.getValue();
}

//! Set the value of the UIViewport::_sfViewPosition field.
inline
void UIViewportBase::setViewPosition(const Pnt2s &value)
{
    _sfViewPosition.setValue(value);
}

//! Get the value of the UIViewport::_sfViewComponent field.
inline
ComponentPtr &UIViewportBase::editViewComponent(void)
{
    return _sfViewComponent.getValue();
}

//! Get the value of the UIViewport::_sfViewComponent field.
inline
const ComponentPtr &UIViewportBase::getViewComponent(void) const
{
    return _sfViewComponent.getValue();
}

//! Set the value of the UIViewport::_sfViewComponent field.
inline
void UIViewportBase::setViewComponent(const ComponentPtr &value)
{
    _sfViewComponent.setValue(value);
}

//! Get the value of the UIViewport::_sfViewSize field.
inline
Vec2s &UIViewportBase::editViewSize(void)
{
    return _sfViewSize.getValue();
}

//! Get the value of the UIViewport::_sfViewSize field.
inline
const Vec2s &UIViewportBase::getViewSize(void) const
{
    return _sfViewSize.getValue();
}

//! Set the value of the UIViewport::_sfViewSize field.
inline
void UIViewportBase::setViewSize(const Vec2s &value)
{
    _sfViewSize.setValue(value);
}


OSG_END_NAMESPACE

