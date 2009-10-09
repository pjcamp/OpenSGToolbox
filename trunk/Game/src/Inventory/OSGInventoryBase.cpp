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
 **     class Inventory!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEINVENTORYINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGInventoryBase.h"
#include "OSGInventory.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  InventoryBase::InventoryItemsFieldMask = 
    (TypeTraits<BitVector>::One << InventoryBase::InventoryItemsFieldId);

const OSG::BitVector  InventoryBase::RootInventoryFieldMask = 
    (TypeTraits<BitVector>::One << InventoryBase::RootInventoryFieldId);

const OSG::BitVector  InventoryBase::InventoryClassesFieldMask = 
    (TypeTraits<BitVector>::One << InventoryBase::InventoryClassesFieldId);

const OSG::BitVector  InventoryBase::InventoryClassNameFieldMask = 
    (TypeTraits<BitVector>::One << InventoryBase::InventoryClassNameFieldId);

const OSG::BitVector  InventoryBase::EventProducerFieldMask =
    (TypeTraits<BitVector>::One << InventoryBase::EventProducerFieldId);

const OSG::BitVector InventoryBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var InventoryItemPtr InventoryBase::_mfInventoryItems
    
*/
/*! \var bool            InventoryBase::_sfRootInventory
    
*/
/*! \var InventoryPtr    InventoryBase::_mfInventoryClasses
    
*/
/*! \var std::string     InventoryBase::_sfInventoryClassName
    
*/

//! Inventory description

FieldDescription *InventoryBase::_desc[] = 
{
    new FieldDescription(MFInventoryItemPtr::getClassType(), 
                     "InventoryItems", 
                     InventoryItemsFieldId, InventoryItemsFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&InventoryBase::editMFInventoryItems)),
    new FieldDescription(SFBool::getClassType(), 
                     "RootInventory", 
                     RootInventoryFieldId, RootInventoryFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&InventoryBase::editSFRootInventory)),
    new FieldDescription(MFInventoryPtr::getClassType(), 
                     "InventoryClasses", 
                     InventoryClassesFieldId, InventoryClassesFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&InventoryBase::editMFInventoryClasses)),
    new FieldDescription(SFString::getClassType(), 
                     "InventoryClassName", 
                     InventoryClassNameFieldId, InventoryClassNameFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&InventoryBase::editSFInventoryClassName))
    , 
    new FieldDescription(SFEventProducerPtr::getClassType(), 
                     "EventProducer", 
                     EventProducerFieldId,EventProducerFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&InventoryBase::editSFEventProducer))
};


FieldContainerType InventoryBase::_type(
    "Inventory",
    "AttachmentContainer",
    NULL,
    reinterpret_cast<PrototypeCreateF>(&InventoryBase::createEmpty),
    Inventory::initMethod,
    _desc,
    sizeof(_desc));

//! Inventory Produced Methods

MethodDescription *InventoryBase::_methodDesc[] =
{
    new MethodDescription("ItemAdded", 
                     ItemAddedMethodId, 
                     SFEventPtr::getClassType(),
                     FunctorAccessMethod()),
    new MethodDescription("InventorySorted", 
                     InventorySortedMethodId, 
                     SFEventPtr::getClassType(),
                     FunctorAccessMethod()),
    new MethodDescription("ItemRemoved", 
                     ItemRemovedMethodId, 
                     SFEventPtr::getClassType(),
                     FunctorAccessMethod())
};

EventProducerType InventoryBase::_producerType(
    "InventoryProducerType",
    "EventProducerType",
    NULL,
    InitEventProducerFunctor(),
    _methodDesc,
    sizeof(_methodDesc));
//OSG_FIELD_CONTAINER_DEF(InventoryBase, InventoryPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &InventoryBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &InventoryBase::getType(void) const 
{
    return _type;
} 

const EventProducerType &InventoryBase::getProducerType(void) const
{
    return _producerType;
}


FieldContainerPtr InventoryBase::shallowCopy(void) const 
{ 
    InventoryPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const Inventory *>(this)); 

    return returnValue; 
}

UInt32 InventoryBase::getContainerSize(void) const 
{ 
    return sizeof(Inventory); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void InventoryBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl(static_cast<InventoryBase *>(&other),
                          whichField);
}
#else
void InventoryBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((InventoryBase *) &other, whichField, sInfo);
}
void InventoryBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void InventoryBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

    _mfInventoryItems.terminateShare(uiAspect, this->getContainerSize());
    _mfInventoryClasses.terminateShare(uiAspect, this->getContainerSize());
}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

InventoryBase::InventoryBase(void) :
    _Producer(&getProducerType()),
    _mfInventoryItems         (), 
    _sfRootInventory          (), 
    _mfInventoryClasses       (), 
    _sfInventoryClassName     (), 
    _sfEventProducer(&_Producer),
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

InventoryBase::InventoryBase(const InventoryBase &source) :
    _Producer(&getProducerType()),
    _mfInventoryItems         (source._mfInventoryItems         ), 
    _sfRootInventory          (source._sfRootInventory          ), 
    _mfInventoryClasses       (source._mfInventoryClasses       ), 
    _sfInventoryClassName     (source._sfInventoryClassName     ), 
    _sfEventProducer(&_Producer),
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

InventoryBase::~InventoryBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 InventoryBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (InventoryItemsFieldMask & whichField))
    {
        returnValue += _mfInventoryItems.getBinSize();
    }

    if(FieldBits::NoField != (RootInventoryFieldMask & whichField))
    {
        returnValue += _sfRootInventory.getBinSize();
    }

    if(FieldBits::NoField != (InventoryClassesFieldMask & whichField))
    {
        returnValue += _mfInventoryClasses.getBinSize();
    }

    if(FieldBits::NoField != (InventoryClassNameFieldMask & whichField))
    {
        returnValue += _sfInventoryClassName.getBinSize();
    }

    if(FieldBits::NoField != (EventProducerFieldMask & whichField))
    {
        returnValue += _sfEventProducer.getBinSize();
    }


    return returnValue;
}

void InventoryBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (InventoryItemsFieldMask & whichField))
    {
        _mfInventoryItems.copyToBin(pMem);
    }

    if(FieldBits::NoField != (RootInventoryFieldMask & whichField))
    {
        _sfRootInventory.copyToBin(pMem);
    }

    if(FieldBits::NoField != (InventoryClassesFieldMask & whichField))
    {
        _mfInventoryClasses.copyToBin(pMem);
    }

    if(FieldBits::NoField != (InventoryClassNameFieldMask & whichField))
    {
        _sfInventoryClassName.copyToBin(pMem);
    }

    if(FieldBits::NoField != (EventProducerFieldMask & whichField))
    {
        _sfEventProducer.copyToBin(pMem);
    }


}

void InventoryBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (InventoryItemsFieldMask & whichField))
    {
        _mfInventoryItems.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (RootInventoryFieldMask & whichField))
    {
        _sfRootInventory.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (InventoryClassesFieldMask & whichField))
    {
        _mfInventoryClasses.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (InventoryClassNameFieldMask & whichField))
    {
        _sfInventoryClassName.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (EventProducerFieldMask & whichField))
    {
        _sfEventProducer.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void InventoryBase::executeSyncImpl(      InventoryBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (InventoryItemsFieldMask & whichField))
        _mfInventoryItems.syncWith(pOther->_mfInventoryItems);

    if(FieldBits::NoField != (RootInventoryFieldMask & whichField))
        _sfRootInventory.syncWith(pOther->_sfRootInventory);

    if(FieldBits::NoField != (InventoryClassesFieldMask & whichField))
        _mfInventoryClasses.syncWith(pOther->_mfInventoryClasses);

    if(FieldBits::NoField != (InventoryClassNameFieldMask & whichField))
        _sfInventoryClassName.syncWith(pOther->_sfInventoryClassName);

    if(FieldBits::NoField != (EventProducerFieldMask & whichField))
        _sfEventProducer.syncWith(pOther->_sfEventProducer);


}
#else
void InventoryBase::executeSyncImpl(      InventoryBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (RootInventoryFieldMask & whichField))
        _sfRootInventory.syncWith(pOther->_sfRootInventory);

    if(FieldBits::NoField != (InventoryClassNameFieldMask & whichField))
        _sfInventoryClassName.syncWith(pOther->_sfInventoryClassName);


    if(FieldBits::NoField != (InventoryItemsFieldMask & whichField))
        _mfInventoryItems.syncWith(pOther->_mfInventoryItems, sInfo);

    if(FieldBits::NoField != (InventoryClassesFieldMask & whichField))
        _mfInventoryClasses.syncWith(pOther->_mfInventoryClasses, sInfo);


}

void InventoryBase::execBeginEditImpl (const BitVector &whichField, 
                                                 UInt32     uiAspect,
                                                 UInt32     uiContainerSize)
{
    Inherited::execBeginEditImpl(whichField, uiAspect, uiContainerSize);

    if(FieldBits::NoField != (InventoryItemsFieldMask & whichField))
        _mfInventoryItems.beginEdit(uiAspect, uiContainerSize);

    if(FieldBits::NoField != (InventoryClassesFieldMask & whichField))
        _mfInventoryClasses.beginEdit(uiAspect, uiContainerSize);

}
#endif



OSG_END_NAMESPACE

#include <OpenSG/OSGSFieldTypeDef.inl>
#include <OpenSG/OSGMFieldTypeDef.inl>

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldDataTraits<InventoryPtr>::_type("InventoryPtr", "AttachmentContainerPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(InventoryPtr, OSG_GAMELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(InventoryPtr, OSG_GAMELIB_DLLTMPLMAPPING);


OSG_END_NAMESPACE

