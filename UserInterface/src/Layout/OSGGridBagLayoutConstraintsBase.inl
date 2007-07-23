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
 **     class GridBagLayoutConstraints!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <OpenSG/OSGConfig.h>

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &GridBagLayoutConstraintsBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 GridBagLayoutConstraintsBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

//! create a new instance of the class
inline
GridBagLayoutConstraintsPtr GridBagLayoutConstraintsBase::create(void) 
{
    GridBagLayoutConstraintsPtr fc; 

    if(getClassType().getPrototype() != OSG::NullFC) 
    {
        fc = GridBagLayoutConstraintsPtr::dcast(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

//! create an empty new instance of the class, do not copy the prototype
inline
GridBagLayoutConstraintsPtr GridBagLayoutConstraintsBase::createEmpty(void) 
{ 
    GridBagLayoutConstraintsPtr returnValue; 
    
    newPtr(returnValue); 

    return returnValue; 
}


/*------------------------------ get -----------------------------------*/

//! Get the GridBagLayoutConstraints::_sfGridX field.
inline
SFUInt16 *GridBagLayoutConstraintsBase::getSFGridX(void)
{
    return &_sfGridX;
}

//! Get the GridBagLayoutConstraints::_sfGridY field.
inline
SFUInt16 *GridBagLayoutConstraintsBase::getSFGridY(void)
{
    return &_sfGridY;
}

//! Get the GridBagLayoutConstraints::_sfGridWidth field.
inline
SFUInt16 *GridBagLayoutConstraintsBase::getSFGridWidth(void)
{
    return &_sfGridWidth;
}

//! Get the GridBagLayoutConstraints::_sfGridHeight field.
inline
SFUInt16 *GridBagLayoutConstraintsBase::getSFGridHeight(void)
{
    return &_sfGridHeight;
}

//! Get the GridBagLayoutConstraints::_sfFill field.
inline
SFUInt32 *GridBagLayoutConstraintsBase::getSFFill(void)
{
    return &_sfFill;
}

//! Get the GridBagLayoutConstraints::_sfHorizontalAlignment field.
inline
SFReal32 *GridBagLayoutConstraintsBase::getSFHorizontalAlignment(void)
{
    return &_sfHorizontalAlignment;
}

//! Get the GridBagLayoutConstraints::_sfVerticalAlignment field.
inline
SFReal32 *GridBagLayoutConstraintsBase::getSFVerticalAlignment(void)
{
    return &_sfVerticalAlignment;
}

//! Get the GridBagLayoutConstraints::_sfWeightX field.
inline
SFReal32 *GridBagLayoutConstraintsBase::getSFWeightX(void)
{
    return &_sfWeightX;
}

//! Get the GridBagLayoutConstraints::_sfWeightY field.
inline
SFReal32 *GridBagLayoutConstraintsBase::getSFWeightY(void)
{
    return &_sfWeightY;
}

//! Get the GridBagLayoutConstraints::_sfInternalPadX field.
inline
SFUInt32 *GridBagLayoutConstraintsBase::getSFInternalPadX(void)
{
    return &_sfInternalPadX;
}

//! Get the GridBagLayoutConstraints::_sfInternalPadY field.
inline
SFUInt32 *GridBagLayoutConstraintsBase::getSFInternalPadY(void)
{
    return &_sfInternalPadY;
}

//! Get the GridBagLayoutConstraints::_sfPadLeft field.
inline
SFUInt32 *GridBagLayoutConstraintsBase::getSFPadLeft(void)
{
    return &_sfPadLeft;
}

//! Get the GridBagLayoutConstraints::_sfPadRight field.
inline
SFUInt32 *GridBagLayoutConstraintsBase::getSFPadRight(void)
{
    return &_sfPadRight;
}

//! Get the GridBagLayoutConstraints::_sfPadTop field.
inline
SFUInt32 *GridBagLayoutConstraintsBase::getSFPadTop(void)
{
    return &_sfPadTop;
}

//! Get the GridBagLayoutConstraints::_sfPadBottom field.
inline
SFUInt32 *GridBagLayoutConstraintsBase::getSFPadBottom(void)
{
    return &_sfPadBottom;
}


//! Get the value of the GridBagLayoutConstraints::_sfGridX field.
inline
UInt16 &GridBagLayoutConstraintsBase::getGridX(void)
{
    return _sfGridX.getValue();
}

//! Get the value of the GridBagLayoutConstraints::_sfGridX field.
inline
const UInt16 &GridBagLayoutConstraintsBase::getGridX(void) const
{
    return _sfGridX.getValue();
}

//! Set the value of the GridBagLayoutConstraints::_sfGridX field.
inline
void GridBagLayoutConstraintsBase::setGridX(const UInt16 &value)
{
    _sfGridX.setValue(value);
}

//! Get the value of the GridBagLayoutConstraints::_sfGridY field.
inline
UInt16 &GridBagLayoutConstraintsBase::getGridY(void)
{
    return _sfGridY.getValue();
}

//! Get the value of the GridBagLayoutConstraints::_sfGridY field.
inline
const UInt16 &GridBagLayoutConstraintsBase::getGridY(void) const
{
    return _sfGridY.getValue();
}

//! Set the value of the GridBagLayoutConstraints::_sfGridY field.
inline
void GridBagLayoutConstraintsBase::setGridY(const UInt16 &value)
{
    _sfGridY.setValue(value);
}

//! Get the value of the GridBagLayoutConstraints::_sfGridWidth field.
inline
UInt16 &GridBagLayoutConstraintsBase::getGridWidth(void)
{
    return _sfGridWidth.getValue();
}

//! Get the value of the GridBagLayoutConstraints::_sfGridWidth field.
inline
const UInt16 &GridBagLayoutConstraintsBase::getGridWidth(void) const
{
    return _sfGridWidth.getValue();
}

//! Set the value of the GridBagLayoutConstraints::_sfGridWidth field.
inline
void GridBagLayoutConstraintsBase::setGridWidth(const UInt16 &value)
{
    _sfGridWidth.setValue(value);
}

//! Get the value of the GridBagLayoutConstraints::_sfGridHeight field.
inline
UInt16 &GridBagLayoutConstraintsBase::getGridHeight(void)
{
    return _sfGridHeight.getValue();
}

//! Get the value of the GridBagLayoutConstraints::_sfGridHeight field.
inline
const UInt16 &GridBagLayoutConstraintsBase::getGridHeight(void) const
{
    return _sfGridHeight.getValue();
}

//! Set the value of the GridBagLayoutConstraints::_sfGridHeight field.
inline
void GridBagLayoutConstraintsBase::setGridHeight(const UInt16 &value)
{
    _sfGridHeight.setValue(value);
}

//! Get the value of the GridBagLayoutConstraints::_sfFill field.
inline
UInt32 &GridBagLayoutConstraintsBase::getFill(void)
{
    return _sfFill.getValue();
}

//! Get the value of the GridBagLayoutConstraints::_sfFill field.
inline
const UInt32 &GridBagLayoutConstraintsBase::getFill(void) const
{
    return _sfFill.getValue();
}

//! Set the value of the GridBagLayoutConstraints::_sfFill field.
inline
void GridBagLayoutConstraintsBase::setFill(const UInt32 &value)
{
    _sfFill.setValue(value);
}

//! Get the value of the GridBagLayoutConstraints::_sfHorizontalAlignment field.
inline
Real32 &GridBagLayoutConstraintsBase::getHorizontalAlignment(void)
{
    return _sfHorizontalAlignment.getValue();
}

//! Get the value of the GridBagLayoutConstraints::_sfHorizontalAlignment field.
inline
const Real32 &GridBagLayoutConstraintsBase::getHorizontalAlignment(void) const
{
    return _sfHorizontalAlignment.getValue();
}

//! Set the value of the GridBagLayoutConstraints::_sfHorizontalAlignment field.
inline
void GridBagLayoutConstraintsBase::setHorizontalAlignment(const Real32 &value)
{
    _sfHorizontalAlignment.setValue(value);
}

//! Get the value of the GridBagLayoutConstraints::_sfVerticalAlignment field.
inline
Real32 &GridBagLayoutConstraintsBase::getVerticalAlignment(void)
{
    return _sfVerticalAlignment.getValue();
}

//! Get the value of the GridBagLayoutConstraints::_sfVerticalAlignment field.
inline
const Real32 &GridBagLayoutConstraintsBase::getVerticalAlignment(void) const
{
    return _sfVerticalAlignment.getValue();
}

//! Set the value of the GridBagLayoutConstraints::_sfVerticalAlignment field.
inline
void GridBagLayoutConstraintsBase::setVerticalAlignment(const Real32 &value)
{
    _sfVerticalAlignment.setValue(value);
}

//! Get the value of the GridBagLayoutConstraints::_sfWeightX field.
inline
Real32 &GridBagLayoutConstraintsBase::getWeightX(void)
{
    return _sfWeightX.getValue();
}

//! Get the value of the GridBagLayoutConstraints::_sfWeightX field.
inline
const Real32 &GridBagLayoutConstraintsBase::getWeightX(void) const
{
    return _sfWeightX.getValue();
}

//! Set the value of the GridBagLayoutConstraints::_sfWeightX field.
inline
void GridBagLayoutConstraintsBase::setWeightX(const Real32 &value)
{
    _sfWeightX.setValue(value);
}

//! Get the value of the GridBagLayoutConstraints::_sfWeightY field.
inline
Real32 &GridBagLayoutConstraintsBase::getWeightY(void)
{
    return _sfWeightY.getValue();
}

//! Get the value of the GridBagLayoutConstraints::_sfWeightY field.
inline
const Real32 &GridBagLayoutConstraintsBase::getWeightY(void) const
{
    return _sfWeightY.getValue();
}

//! Set the value of the GridBagLayoutConstraints::_sfWeightY field.
inline
void GridBagLayoutConstraintsBase::setWeightY(const Real32 &value)
{
    _sfWeightY.setValue(value);
}

//! Get the value of the GridBagLayoutConstraints::_sfInternalPadX field.
inline
UInt32 &GridBagLayoutConstraintsBase::getInternalPadX(void)
{
    return _sfInternalPadX.getValue();
}

//! Get the value of the GridBagLayoutConstraints::_sfInternalPadX field.
inline
const UInt32 &GridBagLayoutConstraintsBase::getInternalPadX(void) const
{
    return _sfInternalPadX.getValue();
}

//! Set the value of the GridBagLayoutConstraints::_sfInternalPadX field.
inline
void GridBagLayoutConstraintsBase::setInternalPadX(const UInt32 &value)
{
    _sfInternalPadX.setValue(value);
}

//! Get the value of the GridBagLayoutConstraints::_sfInternalPadY field.
inline
UInt32 &GridBagLayoutConstraintsBase::getInternalPadY(void)
{
    return _sfInternalPadY.getValue();
}

//! Get the value of the GridBagLayoutConstraints::_sfInternalPadY field.
inline
const UInt32 &GridBagLayoutConstraintsBase::getInternalPadY(void) const
{
    return _sfInternalPadY.getValue();
}

//! Set the value of the GridBagLayoutConstraints::_sfInternalPadY field.
inline
void GridBagLayoutConstraintsBase::setInternalPadY(const UInt32 &value)
{
    _sfInternalPadY.setValue(value);
}

//! Get the value of the GridBagLayoutConstraints::_sfPadLeft field.
inline
UInt32 &GridBagLayoutConstraintsBase::getPadLeft(void)
{
    return _sfPadLeft.getValue();
}

//! Get the value of the GridBagLayoutConstraints::_sfPadLeft field.
inline
const UInt32 &GridBagLayoutConstraintsBase::getPadLeft(void) const
{
    return _sfPadLeft.getValue();
}

//! Set the value of the GridBagLayoutConstraints::_sfPadLeft field.
inline
void GridBagLayoutConstraintsBase::setPadLeft(const UInt32 &value)
{
    _sfPadLeft.setValue(value);
}

//! Get the value of the GridBagLayoutConstraints::_sfPadRight field.
inline
UInt32 &GridBagLayoutConstraintsBase::getPadRight(void)
{
    return _sfPadRight.getValue();
}

//! Get the value of the GridBagLayoutConstraints::_sfPadRight field.
inline
const UInt32 &GridBagLayoutConstraintsBase::getPadRight(void) const
{
    return _sfPadRight.getValue();
}

//! Set the value of the GridBagLayoutConstraints::_sfPadRight field.
inline
void GridBagLayoutConstraintsBase::setPadRight(const UInt32 &value)
{
    _sfPadRight.setValue(value);
}

//! Get the value of the GridBagLayoutConstraints::_sfPadTop field.
inline
UInt32 &GridBagLayoutConstraintsBase::getPadTop(void)
{
    return _sfPadTop.getValue();
}

//! Get the value of the GridBagLayoutConstraints::_sfPadTop field.
inline
const UInt32 &GridBagLayoutConstraintsBase::getPadTop(void) const
{
    return _sfPadTop.getValue();
}

//! Set the value of the GridBagLayoutConstraints::_sfPadTop field.
inline
void GridBagLayoutConstraintsBase::setPadTop(const UInt32 &value)
{
    _sfPadTop.setValue(value);
}

//! Get the value of the GridBagLayoutConstraints::_sfPadBottom field.
inline
UInt32 &GridBagLayoutConstraintsBase::getPadBottom(void)
{
    return _sfPadBottom.getValue();
}

//! Get the value of the GridBagLayoutConstraints::_sfPadBottom field.
inline
const UInt32 &GridBagLayoutConstraintsBase::getPadBottom(void) const
{
    return _sfPadBottom.getValue();
}

//! Set the value of the GridBagLayoutConstraints::_sfPadBottom field.
inline
void GridBagLayoutConstraintsBase::setPadBottom(const UInt32 &value)
{
    _sfPadBottom.setValue(value);
}


OSG_END_NAMESPACE

#define OSGGRIDBAGLAYOUTCONSTRAINTSBASE_INLINE_CVSID "@(#)$Id: FCBaseTemplate_inl.h,v 1.20 2002/12/04 14:22:22 dirk Exp $"

