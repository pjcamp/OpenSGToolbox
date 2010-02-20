/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *   contact:  David Kabala (djkabala@gmail.com)                             *
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
 **     class RotatedComponent!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &RotatedComponentBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 RotatedComponentBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 RotatedComponentBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the RotatedComponent::_sfAngle field.

inline
Real32 &RotatedComponentBase::editAngle(void)
{
    editSField(AngleFieldMask);

    return _sfAngle.getValue();
}

//! Get the value of the RotatedComponent::_sfAngle field.
inline
      Real32  RotatedComponentBase::getAngle(void) const
{
    return _sfAngle.getValue();
}

//! Set the value of the RotatedComponent::_sfAngle field.
inline
void RotatedComponentBase::setAngle(const Real32 value)
{
    editSField(AngleFieldMask);

    _sfAngle.setValue(value);
}

//! Get the value of the RotatedComponent::_sfInternalComponent field.
inline
Component * RotatedComponentBase::getInternalComponent(void) const
{
    return _sfInternalComponent.getValue();
}

//! Set the value of the RotatedComponent::_sfInternalComponent field.
inline
void RotatedComponentBase::setInternalComponent(Component * const value)
{
    editSField(InternalComponentFieldMask);

    _sfInternalComponent.setValue(value);
}
//! Get the value of the RotatedComponent::_sfResizePolicy field.

inline
UInt32 &RotatedComponentBase::editResizePolicy(void)
{
    editSField(ResizePolicyFieldMask);

    return _sfResizePolicy.getValue();
}

//! Get the value of the RotatedComponent::_sfResizePolicy field.
inline
      UInt32  RotatedComponentBase::getResizePolicy(void) const
{
    return _sfResizePolicy.getValue();
}

//! Set the value of the RotatedComponent::_sfResizePolicy field.
inline
void RotatedComponentBase::setResizePolicy(const UInt32 value)
{
    editSField(ResizePolicyFieldMask);

    _sfResizePolicy.setValue(value);
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void RotatedComponentBase::execSync (      RotatedComponentBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (AngleFieldMask & whichField))
        _sfAngle.syncWith(pFrom->_sfAngle);

    if(FieldBits::NoField != (InternalComponentFieldMask & whichField))
        _sfInternalComponent.syncWith(pFrom->_sfInternalComponent);

    if(FieldBits::NoField != (ResizePolicyFieldMask & whichField))
        _sfResizePolicy.syncWith(pFrom->_sfResizePolicy);
}
#endif


inline
const Char8 *RotatedComponentBase::getClassname(void)
{
    return "RotatedComponent";
}
OSG_GEN_CONTAINERPTR(RotatedComponent);

OSG_END_NAMESPACE

