/*---------------------------------------------------------------------------*\
 *                       OpenSG ToolBox Animation                            *
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
 **     class Bone!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <OpenSG/OSGConfig.h>

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &BoneBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 BoneBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 


/*------------------------------ get -----------------------------------*/

//! Get the Bone::_sfRotation field.
inline
SFQuaternion *BoneBase::getSFRotation(void)
{
    return &_sfRotation;
}

//! Get the Bone::_sfTranslation field.
inline
SFPnt3f *BoneBase::getSFTranslation(void)
{
    return &_sfTranslation;
}

//! Get the Bone::_sfLength field.
inline
SFReal32 *BoneBase::getSFLength(void)
{
    return &_sfLength;
}

//! Get the Bone::_mfInternalChildren field.
inline
MFBonePtr *BoneBase::getMFInternalChildren(void)
{
    return &_mfInternalChildren;
}

//! Get the Bone::_sfInternalParent field.
inline
SFBonePtr *BoneBase::getSFInternalParent(void)
{
    return &_sfInternalParent;
}


//! Get the value of the Bone::_sfRotation field.
inline
Quaternion &BoneBase::getRotation(void)
{
    return _sfRotation.getValue();
}

//! Get the value of the Bone::_sfRotation field.
inline
const Quaternion &BoneBase::getRotation(void) const
{
    return _sfRotation.getValue();
}

//! Set the value of the Bone::_sfRotation field.
inline
void BoneBase::setRotation(const Quaternion &value)
{
    _sfRotation.setValue(value);
}

//! Get the value of the Bone::_sfTranslation field.
inline
Pnt3f &BoneBase::getTranslation(void)
{
    return _sfTranslation.getValue();
}

//! Get the value of the Bone::_sfTranslation field.
inline
const Pnt3f &BoneBase::getTranslation(void) const
{
    return _sfTranslation.getValue();
}

//! Set the value of the Bone::_sfTranslation field.
inline
void BoneBase::setTranslation(const Pnt3f &value)
{
    _sfTranslation.setValue(value);
}

//! Get the value of the Bone::_sfLength field.
inline
Real32 &BoneBase::getLength(void)
{
    return _sfLength.getValue();
}

//! Get the value of the Bone::_sfLength field.
inline
const Real32 &BoneBase::getLength(void) const
{
    return _sfLength.getValue();
}

//! Set the value of the Bone::_sfLength field.
inline
void BoneBase::setLength(const Real32 &value)
{
    _sfLength.setValue(value);
}

//! Get the value of the Bone::_sfInternalParent field.
inline
BonePtr &BoneBase::getInternalParent(void)
{
    return _sfInternalParent.getValue();
}

//! Get the value of the Bone::_sfInternalParent field.
inline
const BonePtr &BoneBase::getInternalParent(void) const
{
    return _sfInternalParent.getValue();
}

//! Set the value of the Bone::_sfInternalParent field.
inline
void BoneBase::setInternalParent(const BonePtr &value)
{
    _sfInternalParent.setValue(value);
}


//! Get the value of the \a index element the Bone::_mfInternalChildren field.
inline
BonePtr &BoneBase::getInternalChildren(const UInt32 index)
{
    return _mfInternalChildren[index];
}

//! Get the Bone::_mfInternalChildren field.
inline
MFBonePtr &BoneBase::getInternalChildren(void)
{
    return _mfInternalChildren;
}

//! Get the Bone::_mfInternalChildren field.
inline
const MFBonePtr &BoneBase::getInternalChildren(void) const
{
    return _mfInternalChildren;
}

OSG_END_NAMESPACE

#define OSGBONEBASE_INLINE_CVSID "@(#)$Id: FCBaseTemplate_inl.h,v 1.20 2002/12/04 14:22:22 dirk Exp $"

