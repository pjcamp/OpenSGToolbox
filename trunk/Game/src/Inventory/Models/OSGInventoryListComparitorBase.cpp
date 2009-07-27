/*---------------------------------------------------------------------------*\
 *                        OpenSG ToolBox Game                                *
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
 **     class InventoryListComparitor!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEINVENTORYLISTCOMPARITORINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGInventoryListComparitorBase.h"
#include "OSGInventoryListComparitor.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  InventoryListComparitorBase::ClassToDisplayFieldMask = 
    (TypeTraits<BitVector>::One << InventoryListComparitorBase::ClassToDisplayFieldId);

const OSG::BitVector  InventoryListComparitorBase::AscendingFieldMask = 
    (TypeTraits<BitVector>::One << InventoryListComparitorBase::AscendingFieldId);

const OSG::BitVector InventoryListComparitorBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var std::string     InventoryListComparitorBase::_mfClassToDisplay
    
*/
/*! \var bool            InventoryListComparitorBase::_sfAscending
    
*/

//! InventoryListComparitor description

FieldDescription *InventoryListComparitorBase::_desc[] = 
{
    new FieldDescription(MFString::getClassType(), 
                     "ClassToDisplay", 
                     ClassToDisplayFieldId, ClassToDisplayFieldMask,
                     false,
                     (FieldAccessMethod) &InventoryListComparitorBase::getMFClassToDisplay),
    new FieldDescription(SFBool::getClassType(), 
                     "Ascending", 
                     AscendingFieldId, AscendingFieldMask,
                     false,
                     (FieldAccessMethod) &InventoryListComparitorBase::getSFAscending)
};


FieldContainerType InventoryListComparitorBase::_type(
    "InventoryListComparitor",
    "AttachmentContainer",
    NULL,
    (PrototypeCreateF) &InventoryListComparitorBase::createEmpty,
    InventoryListComparitor::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(InventoryListComparitorBase, InventoryListComparitorPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &InventoryListComparitorBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &InventoryListComparitorBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr InventoryListComparitorBase::shallowCopy(void) const 
{ 
    InventoryListComparitorPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const InventoryListComparitor *>(this)); 

    return returnValue; 
}

UInt32 InventoryListComparitorBase::getContainerSize(void) const 
{ 
    return sizeof(InventoryListComparitor); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void InventoryListComparitorBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl((InventoryListComparitorBase *) &other, whichField);
}
#else
void InventoryListComparitorBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((InventoryListComparitorBase *) &other, whichField, sInfo);
}
void InventoryListComparitorBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void InventoryListComparitorBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

    _mfClassToDisplay.terminateShare(uiAspect, this->getContainerSize());
}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

InventoryListComparitorBase::InventoryListComparitorBase(void) :
    _mfClassToDisplay         (), 
    _sfAscending              (bool(false)), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

InventoryListComparitorBase::InventoryListComparitorBase(const InventoryListComparitorBase &source) :
    _mfClassToDisplay         (source._mfClassToDisplay         ), 
    _sfAscending              (source._sfAscending              ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

InventoryListComparitorBase::~InventoryListComparitorBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 InventoryListComparitorBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ClassToDisplayFieldMask & whichField))
    {
        returnValue += _mfClassToDisplay.getBinSize();
    }

    if(FieldBits::NoField != (AscendingFieldMask & whichField))
    {
        returnValue += _sfAscending.getBinSize();
    }


    return returnValue;
}

void InventoryListComparitorBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ClassToDisplayFieldMask & whichField))
    {
        _mfClassToDisplay.copyToBin(pMem);
    }

    if(FieldBits::NoField != (AscendingFieldMask & whichField))
    {
        _sfAscending.copyToBin(pMem);
    }


}

void InventoryListComparitorBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ClassToDisplayFieldMask & whichField))
    {
        _mfClassToDisplay.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (AscendingFieldMask & whichField))
    {
        _sfAscending.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void InventoryListComparitorBase::executeSyncImpl(      InventoryListComparitorBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (ClassToDisplayFieldMask & whichField))
        _mfClassToDisplay.syncWith(pOther->_mfClassToDisplay);

    if(FieldBits::NoField != (AscendingFieldMask & whichField))
        _sfAscending.syncWith(pOther->_sfAscending);


}
#else
void InventoryListComparitorBase::executeSyncImpl(      InventoryListComparitorBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (AscendingFieldMask & whichField))
        _sfAscending.syncWith(pOther->_sfAscending);


    if(FieldBits::NoField != (ClassToDisplayFieldMask & whichField))
        _mfClassToDisplay.syncWith(pOther->_mfClassToDisplay, sInfo);


}

void InventoryListComparitorBase::execBeginEditImpl (const BitVector &whichField, 
                                                 UInt32     uiAspect,
                                                 UInt32     uiContainerSize)
{
    Inherited::execBeginEditImpl(whichField, uiAspect, uiContainerSize);

    if(FieldBits::NoField != (ClassToDisplayFieldMask & whichField))
        _mfClassToDisplay.beginEdit(uiAspect, uiContainerSize);

}
#endif



OSG_END_NAMESPACE

#include <OpenSG/OSGSFieldTypeDef.inl>
#include <OpenSG/OSGMFieldTypeDef.inl>

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldDataTraits<InventoryListComparitorPtr>::_type("InventoryListComparitorPtr", "AttachmentContainerPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(InventoryListComparitorPtr, OSG_GAMELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(InventoryListComparitorPtr, OSG_GAMELIB_DLLTMPLMAPPING);


/*------------------------------------------------------------------------*/
/*                              cvs id's                                  */

#ifdef OSG_SGI_CC
#pragma set woff 1174
#endif

#ifdef OSG_LINUX_ICC
#pragma warning( disable : 177 )
#endif

namespace
{
    static Char8 cvsid_cpp       [] = "@(#)$Id: FCBaseTemplate_cpp.h,v 1.47 2006/03/17 17:03:19 pdaehne Exp $";
    static Char8 cvsid_hpp       [] = OSGINVENTORYLISTCOMPARITORBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGINVENTORYLISTCOMPARITORBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGINVENTORYLISTCOMPARITORFIELDS_HEADER_CVSID;
}

OSG_END_NAMESPACE

