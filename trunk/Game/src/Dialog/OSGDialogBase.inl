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
 **     class Dialog!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <OpenSG/OSGConfig.h>

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &DialogBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 DialogBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

//! access the producer type of the class
inline
const EventProducerType &DialogBase::getProducerClassType(void)
{
    return _producerType;
}

//! access the producer type id of the class
inline
UInt32 DialogBase::getProducerClassTypeId(void)
{
    return _producerType.getId();
}

//! create a new instance of the class
inline
DialogPtr DialogBase::create(void) 
{
    DialogPtr fc; 

    if(getClassType().getPrototype() != OSG::NullFC) 
    {
        fc = DialogPtr::dcast(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

//! create an empty new instance of the class, do not copy the prototype
inline
DialogPtr DialogBase::createEmpty(void) 
{ 
    DialogPtr returnValue; 
    
    newPtr(returnValue); 

    return returnValue; 
}


/*------------------------------ get -----------------------------------*/

//! Get the Dialog::_sfResponse field.
inline
const SFString *DialogBase::getSFResponse(void) const
{
    return &_sfResponse;
}

//! Get the Dialog::_sfResponse field.
inline
SFString *DialogBase::editSFResponse(void)
{
    return &_sfResponse;
}

//! Get the Dialog::_sfResponsePresentationDelay field.
inline
const SFReal32 *DialogBase::getSFResponsePresentationDelay(void) const
{
    return &_sfResponsePresentationDelay;
}

//! Get the Dialog::_sfResponsePresentationDelay field.
inline
SFReal32 *DialogBase::editSFResponsePresentationDelay(void)
{
    return &_sfResponsePresentationDelay;
}

//! Get the Dialog::_sfInteractive field.
inline
const SFBool *DialogBase::getSFInteractive(void) const
{
    return &_sfInteractive;
}

//! Get the Dialog::_sfInteractive field.
inline
SFBool *DialogBase::editSFInteractive(void)
{
    return &_sfInteractive;
}

//! Get the Dialog::_mfResponses field.
inline
const MFDialogPtr *DialogBase::getMFResponses(void) const
{
    return &_mfResponses;
}

//! Get the Dialog::_mfResponses field.
inline
MFDialogPtr *DialogBase::editMFResponses(void)
{
    return &_mfResponses;
}

//! Get the Dialog::_sfDialogSound field.
inline
const SFSoundPtr *DialogBase::getSFDialogSound(void) const
{
    return &_sfDialogSound;
}

//! Get the Dialog::_sfDialogSound field.
inline
SFSoundPtr *DialogBase::editSFDialogSound(void)
{
    return &_sfDialogSound;
}

//! Get the Dialog::_sfParentDialogHierarchy field.
inline
const SFDialogHierarchyPtr *DialogBase::getSFParentDialogHierarchy(void) const
{
    return &_sfParentDialogHierarchy;
}

//! Get the Dialog::_sfParentDialogHierarchy field.
inline
SFDialogHierarchyPtr *DialogBase::editSFParentDialogHierarchy(void)
{
    return &_sfParentDialogHierarchy;
}


//! Get the value of the Dialog::_sfResponse field.
inline
std::string &DialogBase::editResponse(void)
{
    return _sfResponse.getValue();
}

//! Get the value of the Dialog::_sfResponse field.
inline
const std::string &DialogBase::getResponse(void) const
{
    return _sfResponse.getValue();
}

//! Set the value of the Dialog::_sfResponse field.
inline
void DialogBase::setResponse(const std::string &value)
{
    _sfResponse.setValue(value);
}

//! Get the value of the Dialog::_sfResponsePresentationDelay field.
inline
Real32 &DialogBase::editResponsePresentationDelay(void)
{
    return _sfResponsePresentationDelay.getValue();
}

//! Get the value of the Dialog::_sfResponsePresentationDelay field.
inline
const Real32 &DialogBase::getResponsePresentationDelay(void) const
{
    return _sfResponsePresentationDelay.getValue();
}

//! Set the value of the Dialog::_sfResponsePresentationDelay field.
inline
void DialogBase::setResponsePresentationDelay(const Real32 &value)
{
    _sfResponsePresentationDelay.setValue(value);
}

//! Get the value of the Dialog::_sfInteractive field.
inline
bool &DialogBase::editInteractive(void)
{
    return _sfInteractive.getValue();
}

//! Get the value of the Dialog::_sfInteractive field.
inline
const bool &DialogBase::getInteractive(void) const
{
    return _sfInteractive.getValue();
}

//! Set the value of the Dialog::_sfInteractive field.
inline
void DialogBase::setInteractive(const bool &value)
{
    _sfInteractive.setValue(value);
}

//! Get the value of the Dialog::_sfDialogSound field.
inline
SoundPtr &DialogBase::editDialogSound(void)
{
    return _sfDialogSound.getValue();
}

//! Get the value of the Dialog::_sfDialogSound field.
inline
const SoundPtr &DialogBase::getDialogSound(void) const
{
    return _sfDialogSound.getValue();
}

//! Set the value of the Dialog::_sfDialogSound field.
inline
void DialogBase::setDialogSound(const SoundPtr &value)
{
    _sfDialogSound.setValue(value);
}

//! Get the value of the Dialog::_sfParentDialogHierarchy field.
inline
DialogHierarchyPtr &DialogBase::editParentDialogHierarchy(void)
{
    return _sfParentDialogHierarchy.getValue();
}

//! Get the value of the Dialog::_sfParentDialogHierarchy field.
inline
const DialogHierarchyPtr &DialogBase::getParentDialogHierarchy(void) const
{
    return _sfParentDialogHierarchy.getValue();
}

//! Set the value of the Dialog::_sfParentDialogHierarchy field.
inline
void DialogBase::setParentDialogHierarchy(const DialogHierarchyPtr &value)
{
    _sfParentDialogHierarchy.setValue(value);
}


//! Get the value of the \a index element the Dialog::_mfResponses field.
inline
DialogPtr &DialogBase::editResponses(const UInt32 index)
{
    return _mfResponses[index];
}

//! Get the value of the \a index element the Dialog::_mfResponses field.
inline
const DialogPtr &DialogBase::getResponses(const UInt32 index) const
{
    return _mfResponses[index];
}

#ifndef OSG_2_PREP
//! Get the Dialog::_mfResponses field.
inline
MFDialogPtr &DialogBase::getResponses(void)
{
    return _mfResponses;
}

//! Get the Dialog::_mfResponses field.
inline
const MFDialogPtr &DialogBase::getResponses(void) const
{
    return _mfResponses;
}

#endif
OSG_END_NAMESPACE

