/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                         www.vrac.iastate.edu                              *
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
 **     class InputEvent!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEINPUTEVENTINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGInputEventBase.h"
#include "OSGInputEvent.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  InputEventBase::ConsumedFieldMask = 
    (TypeTraits<BitVector>::One << InputEventBase::ConsumedFieldId);

const OSG::BitVector InputEventBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var bool            InputEventBase::_sfConsumed
    
*/

//! InputEvent description

FieldDescription *InputEventBase::_desc[] = 
{
    new FieldDescription(SFBool::getClassType(), 
                     "Consumed", 
                     ConsumedFieldId, ConsumedFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&InputEventBase::editSFConsumed))
};


FieldContainerType InputEventBase::_type(
    "InputEvent",
    "Event",
    NULL,
    NULL, 
    InputEvent::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(InputEventBase, InputEventPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &InputEventBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &InputEventBase::getType(void) const 
{
    return _type;
} 


UInt32 InputEventBase::getContainerSize(void) const 
{ 
    return sizeof(InputEvent); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void InputEventBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl(static_cast<InputEventBase *>(&other),
                          whichField);
}
#else
void InputEventBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((InputEventBase *) &other, whichField, sInfo);
}
void InputEventBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void InputEventBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

InputEventBase::InputEventBase(void) :
    _sfConsumed               (bool(false)), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

InputEventBase::InputEventBase(const InputEventBase &source) :
    _sfConsumed               (source._sfConsumed               ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

InputEventBase::~InputEventBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 InputEventBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ConsumedFieldMask & whichField))
    {
        returnValue += _sfConsumed.getBinSize();
    }


    return returnValue;
}

void InputEventBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ConsumedFieldMask & whichField))
    {
        _sfConsumed.copyToBin(pMem);
    }


}

void InputEventBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ConsumedFieldMask & whichField))
    {
        _sfConsumed.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void InputEventBase::executeSyncImpl(      InputEventBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (ConsumedFieldMask & whichField))
        _sfConsumed.syncWith(pOther->_sfConsumed);


}
#else
void InputEventBase::executeSyncImpl(      InputEventBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (ConsumedFieldMask & whichField))
        _sfConsumed.syncWith(pOther->_sfConsumed);



}

void InputEventBase::execBeginEditImpl (const BitVector &whichField, 
                                                 UInt32     uiAspect,
                                                 UInt32     uiContainerSize)
{
    Inherited::execBeginEditImpl(whichField, uiAspect, uiContainerSize);

}
#endif



OSG_END_NAMESPACE

#include <OpenSG/OSGSFieldTypeDef.inl>

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldDataTraits<InputEventPtr>::_type("InputEventPtr", "EventPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(InputEventPtr, OSG_INPUTLIB_DLLTMPLMAPPING);


OSG_END_NAMESPACE

