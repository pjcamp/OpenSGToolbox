/*---------------------------------------------------------------------------*\
 *                        OpenSG ToolBox Game                                *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                   Authors: David Kabala, Eric Langkamp                    *
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
 **     class DefaultDialogComponentGenerator!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <OpenSG/OSGConfig.h>

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &DefaultDialogComponentGeneratorBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 DefaultDialogComponentGeneratorBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

//! create a new instance of the class
inline
DefaultDialogComponentGeneratorPtr DefaultDialogComponentGeneratorBase::create(void) 
{
    DefaultDialogComponentGeneratorPtr fc; 

    if(getClassType().getPrototype() != OSG::NullFC) 
    {
        fc = DefaultDialogComponentGeneratorPtr::dcast(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

//! create an empty new instance of the class, do not copy the prototype
inline
DefaultDialogComponentGeneratorPtr DefaultDialogComponentGeneratorBase::createEmpty(void) 
{ 
    DefaultDialogComponentGeneratorPtr returnValue; 
    
    newPtr(returnValue); 

    return returnValue; 
}


/*------------------------------ get -----------------------------------*/

//! Get the DefaultDialogComponentGenerator::_sfResponseButtonPrototype field.
inline
SFButtonPtr *DefaultDialogComponentGeneratorBase::getSFResponseButtonPrototype(void)
{
    return &_sfResponseButtonPrototype;
}

//! Get the DefaultDialogComponentGenerator::_sfQuestionPrototype field.
inline
SFLabelPtr *DefaultDialogComponentGeneratorBase::getSFQuestionPrototype(void)
{
    return &_sfQuestionPrototype;
}


//! Get the value of the DefaultDialogComponentGenerator::_sfResponseButtonPrototype field.
inline
ButtonPtr &DefaultDialogComponentGeneratorBase::getResponseButtonPrototype(void)
{
    return _sfResponseButtonPrototype.getValue();
}

//! Get the value of the DefaultDialogComponentGenerator::_sfResponseButtonPrototype field.
inline
const ButtonPtr &DefaultDialogComponentGeneratorBase::getResponseButtonPrototype(void) const
{
    return _sfResponseButtonPrototype.getValue();
}

//! Set the value of the DefaultDialogComponentGenerator::_sfResponseButtonPrototype field.
inline
void DefaultDialogComponentGeneratorBase::setResponseButtonPrototype(const ButtonPtr &value)
{
    _sfResponseButtonPrototype.setValue(value);
}

//! Get the value of the DefaultDialogComponentGenerator::_sfQuestionPrototype field.
inline
LabelPtr &DefaultDialogComponentGeneratorBase::getQuestionPrototype(void)
{
    return _sfQuestionPrototype.getValue();
}

//! Get the value of the DefaultDialogComponentGenerator::_sfQuestionPrototype field.
inline
const LabelPtr &DefaultDialogComponentGeneratorBase::getQuestionPrototype(void) const
{
    return _sfQuestionPrototype.getValue();
}

//! Set the value of the DefaultDialogComponentGenerator::_sfQuestionPrototype field.
inline
void DefaultDialogComponentGeneratorBase::setQuestionPrototype(const LabelPtr &value)
{
    _sfQuestionPrototype.setValue(value);
}


OSG_END_NAMESPACE

#define OSGDEFAULTDIALOGCOMPONENTGENERATORBASE_INLINE_CVSID "@(#)$Id: FCBaseTemplate_inl.h,v 1.20 2002/12/04 14:22:22 dirk Exp $"
