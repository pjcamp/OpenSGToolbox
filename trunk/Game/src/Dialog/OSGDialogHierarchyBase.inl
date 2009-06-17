/*---------------------------------------------------------------------------*\
 *                        OpenSG ToolBox Game                                *
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
 **     class DialogHierarchy!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <OpenSG/OSGConfig.h>

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &DialogHierarchyBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 DialogHierarchyBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

//! create a new instance of the class
inline
DialogHierarchyPtr DialogHierarchyBase::create(void) 
{
    DialogHierarchyPtr fc; 

    if(getClassType().getPrototype() != OSG::NullFC) 
    {
        fc = DialogHierarchyPtr::dcast(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

//! create an empty new instance of the class, do not copy the prototype
inline
DialogHierarchyPtr DialogHierarchyBase::createEmpty(void) 
{ 
    DialogHierarchyPtr returnValue; 
    
    newPtr(returnValue); 

    return returnValue; 
}


/*------------------------------ get -----------------------------------*/

//! Get the DialogHierarchy::_sfRootDialog field.
inline
SFDialogPtr *DialogHierarchyBase::getSFRootDialog(void)
{
    return &_sfRootDialog;
}

//! Get the DialogHierarchy::_sfCurrentDialog field.
inline
SFDialogPtr *DialogHierarchyBase::getSFCurrentDialog(void)
{
    return &_sfCurrentDialog;
}

//! Get the DialogHierarchy::_mfCurrentDialogResponses field.
inline
MFDialogPtr *DialogHierarchyBase::getMFCurrentDialogResponses(void)
{
    return &_mfCurrentDialogResponses;
}

//! Get the DialogHierarchy::_sfDualNodeStyle field.
inline
SFBool *DialogHierarchyBase::getSFDualNodeStyle(void)
{
    return &_sfDualNodeStyle;
}


//! Get the value of the DialogHierarchy::_sfRootDialog field.
inline
DialogPtr &DialogHierarchyBase::getRootDialog(void)
{
    return _sfRootDialog.getValue();
}

//! Get the value of the DialogHierarchy::_sfRootDialog field.
inline
const DialogPtr &DialogHierarchyBase::getRootDialog(void) const
{
    return _sfRootDialog.getValue();
}

//! Set the value of the DialogHierarchy::_sfRootDialog field.
inline
void DialogHierarchyBase::setRootDialog(const DialogPtr &value)
{
    _sfRootDialog.setValue(value);
}

//! Get the value of the DialogHierarchy::_sfCurrentDialog field.
inline
DialogPtr &DialogHierarchyBase::getCurrentDialog(void)
{
    return _sfCurrentDialog.getValue();
}

//! Get the value of the DialogHierarchy::_sfCurrentDialog field.
inline
const DialogPtr &DialogHierarchyBase::getCurrentDialog(void) const
{
    return _sfCurrentDialog.getValue();
}

//! Set the value of the DialogHierarchy::_sfCurrentDialog field.
inline
void DialogHierarchyBase::setCurrentDialog(const DialogPtr &value)
{
    _sfCurrentDialog.setValue(value);
}

//! Get the value of the DialogHierarchy::_sfDualNodeStyle field.
inline
bool &DialogHierarchyBase::getDualNodeStyle(void)
{
    return _sfDualNodeStyle.getValue();
}

//! Get the value of the DialogHierarchy::_sfDualNodeStyle field.
inline
const bool &DialogHierarchyBase::getDualNodeStyle(void) const
{
    return _sfDualNodeStyle.getValue();
}

//! Set the value of the DialogHierarchy::_sfDualNodeStyle field.
inline
void DialogHierarchyBase::setDualNodeStyle(const bool &value)
{
    _sfDualNodeStyle.setValue(value);
}


//! Get the value of the \a index element the DialogHierarchy::_mfCurrentDialogResponses field.
inline
DialogPtr &DialogHierarchyBase::getCurrentDialogResponses(const UInt32 index)
{
    return _mfCurrentDialogResponses[index];
}

//! Get the DialogHierarchy::_mfCurrentDialogResponses field.
inline
MFDialogPtr &DialogHierarchyBase::getCurrentDialogResponses(void)
{
    return _mfCurrentDialogResponses;
}

//! Get the DialogHierarchy::_mfCurrentDialogResponses field.
inline
const MFDialogPtr &DialogHierarchyBase::getCurrentDialogResponses(void) const
{
    return _mfCurrentDialogResponses;
}

OSG_END_NAMESPACE

#define OSGDIALOGHIERARCHYBASE_INLINE_CVSID "@(#)$Id: FCBaseTemplate_inl.h,v 1.20 2002/12/04 14:22:22 dirk Exp $"

