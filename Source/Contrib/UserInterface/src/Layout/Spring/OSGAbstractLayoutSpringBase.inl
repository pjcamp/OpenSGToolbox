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
 **     class AbstractLayoutSpring!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &AbstractLayoutSpringBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 AbstractLayoutSpringBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 AbstractLayoutSpringBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the AbstractLayoutSpring::_sfSize field.

inline
Real32 &AbstractLayoutSpringBase::editSize(void)
{
    editSField(SizeFieldMask);

    return _sfSize.getValue();
}

//! Get the value of the AbstractLayoutSpring::_sfSize field.
inline
      Real32  AbstractLayoutSpringBase::getSize(void) const
{
    return _sfSize.getValue();
}

//! Set the value of the AbstractLayoutSpring::_sfSize field.
inline
void AbstractLayoutSpringBase::setSize(const Real32 value)
{
    editSField(SizeFieldMask);

    _sfSize.setValue(value);
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void AbstractLayoutSpringBase::execSync (      AbstractLayoutSpringBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (SizeFieldMask & whichField))
        _sfSize.syncWith(pFrom->_sfSize);
}
#endif


inline
const Char8 *AbstractLayoutSpringBase::getClassname(void)
{
    return "AbstractLayoutSpring";
}
OSG_GEN_CONTAINERPTR(AbstractLayoutSpring);

OSG_END_NAMESPACE

