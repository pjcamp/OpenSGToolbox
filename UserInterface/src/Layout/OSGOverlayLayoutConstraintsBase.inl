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
 **     class OverlayLayoutConstraints!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <OpenSG/OSGConfig.h>

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &OverlayLayoutConstraintsBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 OverlayLayoutConstraintsBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

//! create a new instance of the class
inline
OverlayLayoutConstraintsPtr OverlayLayoutConstraintsBase::create(void) 
{
    OverlayLayoutConstraintsPtr fc; 

    if(getClassType().getPrototype() != OSG::NullFC) 
    {
        fc = OverlayLayoutConstraintsPtr::dcast(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

//! create an empty new instance of the class, do not copy the prototype
inline
OverlayLayoutConstraintsPtr OverlayLayoutConstraintsBase::createEmpty(void) 
{ 
    OverlayLayoutConstraintsPtr returnValue; 
    
    newPtr(returnValue); 

    return returnValue; 
}


/*------------------------------ get -----------------------------------*/

//! Get the OverlayLayoutConstraints::_sfAlignment field.
inline
SFVec2f *OverlayLayoutConstraintsBase::getSFAlignment(void)
{
    return &_sfAlignment;
}


//! Get the value of the OverlayLayoutConstraints::_sfAlignment field.
inline
Vec2f &OverlayLayoutConstraintsBase::getAlignment(void)
{
    return _sfAlignment.getValue();
}

//! Get the value of the OverlayLayoutConstraints::_sfAlignment field.
inline
const Vec2f &OverlayLayoutConstraintsBase::getAlignment(void) const
{
    return _sfAlignment.getValue();
}

//! Set the value of the OverlayLayoutConstraints::_sfAlignment field.
inline
void OverlayLayoutConstraintsBase::setAlignment(const Vec2f &value)
{
    _sfAlignment.setValue(value);
}


OSG_END_NAMESPACE

#define OSGOVERLAYLAYOUTCONSTRAINTSBASE_INLINE_CVSID "@(#)$Id: FCBaseTemplate_inl.h,v 1.20 2002/12/04 14:22:22 dirk Exp $"

