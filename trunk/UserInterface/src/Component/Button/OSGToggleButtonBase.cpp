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
 **     class ToggleButton!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILETOGGLEBUTTONINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGToggleButtonBase.h"
#include "OSGToggleButton.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  ToggleButtonBase::SelectedFieldMask = 
    (TypeTraits<BitVector>::One << ToggleButtonBase::SelectedFieldId);

const OSG::BitVector ToggleButtonBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var bool            ToggleButtonBase::_sfSelected
    
*/

//! ToggleButton description

FieldDescription *ToggleButtonBase::_desc[] = 
{
    new FieldDescription(SFBool::getClassType(), 
                     "Selected", 
                     SelectedFieldId, SelectedFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ToggleButtonBase::editSFSelected))
};


FieldContainerType ToggleButtonBase::_type(
    "ToggleButton",
    "Button",
    NULL,
    reinterpret_cast<PrototypeCreateF>(&ToggleButtonBase::createEmpty),
    ToggleButton::initMethod,
    _desc,
    sizeof(_desc));

//! ToggleButton Produced Methods

MethodDescription *ToggleButtonBase::_methodDesc[] =
{
    new MethodDescription("ButtonSelected", 
                     ButtonSelectedMethodId, 
                     SFEventPtr::getClassType(),
                     FunctorAccessMethod()),
    new MethodDescription("ButtonDeselected", 
                     ButtonDeselectedMethodId, 
                     SFEventPtr::getClassType(),
                     FunctorAccessMethod())
};

EventProducerType ToggleButtonBase::_producerType(
    "ToggleButtonProducerType",
    "ButtonProducerType",
    NULL,
    InitEventProducerFunctor(),
    _methodDesc,
    sizeof(_methodDesc));
//OSG_FIELD_CONTAINER_DEF(ToggleButtonBase, ToggleButtonPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &ToggleButtonBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &ToggleButtonBase::getType(void) const 
{
    return _type;
} 

const EventProducerType &ToggleButtonBase::getProducerType(void) const
{
    return _producerType;
}


FieldContainerPtr ToggleButtonBase::shallowCopy(void) const 
{ 
    ToggleButtonPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const ToggleButton *>(this)); 

    return returnValue; 
}

UInt32 ToggleButtonBase::getContainerSize(void) const 
{ 
    return sizeof(ToggleButton); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void ToggleButtonBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl(static_cast<ToggleButtonBase *>(&other),
                          whichField);
}
#else
void ToggleButtonBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((ToggleButtonBase *) &other, whichField, sInfo);
}
void ToggleButtonBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void ToggleButtonBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

ToggleButtonBase::ToggleButtonBase(void) :
    _sfSelected               (bool(false)), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

ToggleButtonBase::ToggleButtonBase(const ToggleButtonBase &source) :
    _sfSelected               (source._sfSelected               ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

ToggleButtonBase::~ToggleButtonBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 ToggleButtonBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (SelectedFieldMask & whichField))
    {
        returnValue += _sfSelected.getBinSize();
    }


    return returnValue;
}

void ToggleButtonBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (SelectedFieldMask & whichField))
    {
        _sfSelected.copyToBin(pMem);
    }


}

void ToggleButtonBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (SelectedFieldMask & whichField))
    {
        _sfSelected.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void ToggleButtonBase::executeSyncImpl(      ToggleButtonBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (SelectedFieldMask & whichField))
        _sfSelected.syncWith(pOther->_sfSelected);


}
#else
void ToggleButtonBase::executeSyncImpl(      ToggleButtonBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (SelectedFieldMask & whichField))
        _sfSelected.syncWith(pOther->_sfSelected);



}

void ToggleButtonBase::execBeginEditImpl (const BitVector &whichField, 
                                                 UInt32     uiAspect,
                                                 UInt32     uiContainerSize)
{
    Inherited::execBeginEditImpl(whichField, uiAspect, uiContainerSize);

}
#endif



OSG_END_NAMESPACE

#include <OpenSG/OSGSFieldTypeDef.inl>
#include <OpenSG/OSGMFieldTypeDef.inl>

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldDataTraits<ToggleButtonPtr>::_type("ToggleButtonPtr", "ButtonPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(ToggleButtonPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(ToggleButtonPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);


OSG_END_NAMESPACE

