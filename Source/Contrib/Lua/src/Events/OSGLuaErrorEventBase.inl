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
 **     class LuaErrorEvent!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &LuaErrorEventBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 LuaErrorEventBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 LuaErrorEventBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the LuaErrorEvent::_sfLuaStateVoidP field.

inline
void* &LuaErrorEventBase::editLuaStateVoidP(void)
{
    editSField(LuaStateVoidPFieldMask);

    return _sfLuaStateVoidP.getValue();
}

//! Get the value of the LuaErrorEvent::_sfLuaStateVoidP field.
inline
const void* LuaErrorEventBase::getLuaStateVoidP(void) const
{
    return _sfLuaStateVoidP.getValue();
}

//! Set the value of the LuaErrorEvent::_sfLuaStateVoidP field.
inline
void LuaErrorEventBase::setLuaStateVoidP(void* value)
{
    editSField(LuaStateVoidPFieldMask);

    _sfLuaStateVoidP.setValue(value);
}
//! Get the value of the LuaErrorEvent::_sfStatus field.

inline
Int32 &LuaErrorEventBase::editStatus(void)
{
    editSField(StatusFieldMask);

    return _sfStatus.getValue();
}

//! Get the value of the LuaErrorEvent::_sfStatus field.
inline
      Int32  LuaErrorEventBase::getStatus(void) const
{
    return _sfStatus.getValue();
}

//! Set the value of the LuaErrorEvent::_sfStatus field.
inline
void LuaErrorEventBase::setStatus(const Int32 value)
{
    editSField(StatusFieldMask);

    _sfStatus.setValue(value);
}
//! Get the value of the LuaErrorEvent::_sfStackTraceEnabled field.

inline
bool &LuaErrorEventBase::editStackTraceEnabled(void)
{
    editSField(StackTraceEnabledFieldMask);

    return _sfStackTraceEnabled.getValue();
}

//! Get the value of the LuaErrorEvent::_sfStackTraceEnabled field.
inline
      bool  LuaErrorEventBase::getStackTraceEnabled(void) const
{
    return _sfStackTraceEnabled.getValue();
}

//! Set the value of the LuaErrorEvent::_sfStackTraceEnabled field.
inline
void LuaErrorEventBase::setStackTraceEnabled(const bool value)
{
    editSField(StackTraceEnabledFieldMask);

    _sfStackTraceEnabled.setValue(value);
}

//! Get the value of the \a index element the LuaErrorEvent::_mfStackTrace field.
inline
const std::string &LuaErrorEventBase::getStackTrace(const UInt32 index) const
{
    return _mfStackTrace[index];
}

inline
std::string &LuaErrorEventBase::editStackTrace(const UInt32 index)
{
    editMField(StackTraceFieldMask, _mfStackTrace);

    return _mfStackTrace[index];
}



#ifdef OSG_MT_CPTR_ASPECT
inline
void LuaErrorEventBase::execSync (      LuaErrorEventBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (LuaStateVoidPFieldMask & whichField))
        _sfLuaStateVoidP.syncWith(pFrom->_sfLuaStateVoidP);

    if(FieldBits::NoField != (StatusFieldMask & whichField))
        _sfStatus.syncWith(pFrom->_sfStatus);

    if(FieldBits::NoField != (StackTraceFieldMask & whichField))
        _mfStackTrace.syncWith(pFrom->_mfStackTrace,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);

    if(FieldBits::NoField != (StackTraceEnabledFieldMask & whichField))
        _sfStackTraceEnabled.syncWith(pFrom->_sfStackTraceEnabled);
}
#endif


inline
const Char8 *LuaErrorEventBase::getClassname(void)
{
    return "LuaErrorEvent";
}
OSG_GEN_CONTAINERPTR(LuaErrorEvent);

OSG_END_NAMESPACE

