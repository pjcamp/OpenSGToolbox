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
 **     class FocusEventDetails!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &FocusEventDetailsBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 FocusEventDetailsBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 FocusEventDetailsBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the FocusEventDetails::_sfIsTemporary field.

inline
bool &FocusEventDetailsBase::editIsTemporary(void)
{
    editSField(IsTemporaryFieldMask);

    return _sfIsTemporary.getValue();
}

//! Get the value of the FocusEventDetails::_sfIsTemporary field.
inline
      bool  FocusEventDetailsBase::getIsTemporary(void) const
{
    return _sfIsTemporary.getValue();
}

//! Set the value of the FocusEventDetails::_sfIsTemporary field.
inline
void FocusEventDetailsBase::setIsTemporary(const bool value)
{
    editSField(IsTemporaryFieldMask);

    _sfIsTemporary.setValue(value);
}

//! Get the value of the FocusEventDetails::_sfOppositeComponent field.
inline
Component * FocusEventDetailsBase::getOppositeComponent(void) const
{
    return _sfOppositeComponent.getValue();
}

//! Set the value of the FocusEventDetails::_sfOppositeComponent field.
inline
void FocusEventDetailsBase::setOppositeComponent(Component * const value)
{
    editSField(OppositeComponentFieldMask);

    _sfOppositeComponent.setValue(value);
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void FocusEventDetailsBase::execSync (      FocusEventDetailsBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (IsTemporaryFieldMask & whichField))
        _sfIsTemporary.syncWith(pFrom->_sfIsTemporary);

    if(FieldBits::NoField != (OppositeComponentFieldMask & whichField))
        _sfOppositeComponent.syncWith(pFrom->_sfOppositeComponent);
}
#endif


inline
const Char8 *FocusEventDetailsBase::getClassname(void)
{
    return "FocusEventDetails";
}
OSG_GEN_CONTAINERPTR(FocusEventDetails);

OSG_END_NAMESPACE

