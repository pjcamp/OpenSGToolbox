/*---------------------------------------------------------------------------*\
 *                         OpenSG ToolBox Physics                            *
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
 **     class PhysicsHandler!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <OpenSG/OSGConfig.h>

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &PhysicsHandlerBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 PhysicsHandlerBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

//! create a new instance of the class
inline
PhysicsHandlerPtr PhysicsHandlerBase::create(void) 
{
    PhysicsHandlerPtr fc; 

    if(getClassType().getPrototype() != OSG::NullFC) 
    {
        fc = PhysicsHandlerPtr::dcast(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

//! create an empty new instance of the class, do not copy the prototype
inline
PhysicsHandlerPtr PhysicsHandlerBase::createEmpty(void) 
{ 
    PhysicsHandlerPtr returnValue; 
    
    newPtr(returnValue); 

    return returnValue; 
}


/*------------------------------ get -----------------------------------*/

//! Get the PhysicsHandler::_sfWorld field.
inline
SFPhysicsWorldPtr *PhysicsHandlerBase::getSFWorld(void)
{
    return &_sfWorld;
}

//! Get the PhysicsHandler::_mfSpaces field.
inline
MFPhysicsSpacePtr *PhysicsHandlerBase::getMFSpaces(void)
{
    return &_mfSpaces;
}

//! Get the PhysicsHandler::_sfStepSize field.
inline
SFReal32 *PhysicsHandlerBase::getSFStepSize(void)
{
    return &_sfStepSize;
}

//! Get the PhysicsHandler::_sfMaxStepsPerUpdate field.
inline
SFUInt32 *PhysicsHandlerBase::getSFMaxStepsPerUpdate(void)
{
    return &_sfMaxStepsPerUpdate;
}


//! Get the value of the PhysicsHandler::_sfWorld field.
inline
PhysicsWorldPtr &PhysicsHandlerBase::getWorld(void)
{
    return _sfWorld.getValue();
}

//! Get the value of the PhysicsHandler::_sfWorld field.
inline
const PhysicsWorldPtr &PhysicsHandlerBase::getWorld(void) const
{
    return _sfWorld.getValue();
}

//! Set the value of the PhysicsHandler::_sfWorld field.
inline
void PhysicsHandlerBase::setWorld(const PhysicsWorldPtr &value)
{
    _sfWorld.setValue(value);
}

//! Get the value of the PhysicsHandler::_sfStepSize field.
inline
Real32 &PhysicsHandlerBase::getStepSize(void)
{
    return _sfStepSize.getValue();
}

//! Get the value of the PhysicsHandler::_sfStepSize field.
inline
const Real32 &PhysicsHandlerBase::getStepSize(void) const
{
    return _sfStepSize.getValue();
}

//! Set the value of the PhysicsHandler::_sfStepSize field.
inline
void PhysicsHandlerBase::setStepSize(const Real32 &value)
{
    _sfStepSize.setValue(value);
}

//! Get the value of the PhysicsHandler::_sfMaxStepsPerUpdate field.
inline
UInt32 &PhysicsHandlerBase::getMaxStepsPerUpdate(void)
{
    return _sfMaxStepsPerUpdate.getValue();
}

//! Get the value of the PhysicsHandler::_sfMaxStepsPerUpdate field.
inline
const UInt32 &PhysicsHandlerBase::getMaxStepsPerUpdate(void) const
{
    return _sfMaxStepsPerUpdate.getValue();
}

//! Set the value of the PhysicsHandler::_sfMaxStepsPerUpdate field.
inline
void PhysicsHandlerBase::setMaxStepsPerUpdate(const UInt32 &value)
{
    _sfMaxStepsPerUpdate.setValue(value);
}


//! Get the value of the \a index element the PhysicsHandler::_mfSpaces field.
inline
PhysicsSpacePtr &PhysicsHandlerBase::getSpaces(const UInt32 index)
{
    return _mfSpaces[index];
}

//! Get the PhysicsHandler::_mfSpaces field.
inline
MFPhysicsSpacePtr &PhysicsHandlerBase::getSpaces(void)
{
    return _mfSpaces;
}

//! Get the PhysicsHandler::_mfSpaces field.
inline
const MFPhysicsSpacePtr &PhysicsHandlerBase::getSpaces(void) const
{
    return _mfSpaces;
}

OSG_END_NAMESPACE

#define OSGPHYSICSHANDLERBASE_INLINE_CVSID "@(#)$Id: FCBaseTemplate_inl.h,v 1.20 2002/12/04 14:22:22 dirk Exp $"

