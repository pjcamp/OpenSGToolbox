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
 **     class CaptionEvent!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILECAPTIONEVENTINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGCaptionEventBase.h"
#include "OSGCaptionEvent.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector CaptionEventBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 



FieldContainerType CaptionEventBase::_type(
    "CaptionEvent",
    "Event",
    NULL,
    reinterpret_cast<PrototypeCreateF>(&CaptionEventBase::createEmpty),
    CaptionEvent::initMethod,
    NULL,
    0);

//OSG_FIELD_CONTAINER_DEF(CaptionEventBase, CaptionEventPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &CaptionEventBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &CaptionEventBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr CaptionEventBase::shallowCopy(void) const 
{ 
    CaptionEventPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const CaptionEvent *>(this)); 

    return returnValue; 
}

UInt32 CaptionEventBase::getContainerSize(void) const 
{ 
    return sizeof(CaptionEvent); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void CaptionEventBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl(static_cast<CaptionEventBase *>(&other),
                          whichField);
}
#else
void CaptionEventBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((CaptionEventBase *) &other, whichField, sInfo);
}
void CaptionEventBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void CaptionEventBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

CaptionEventBase::CaptionEventBase(void) :
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

CaptionEventBase::CaptionEventBase(const CaptionEventBase &source) :
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

CaptionEventBase::~CaptionEventBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 CaptionEventBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);


    return returnValue;
}

void CaptionEventBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);


}

void CaptionEventBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void CaptionEventBase::executeSyncImpl(      CaptionEventBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);


}
#else
void CaptionEventBase::executeSyncImpl(      CaptionEventBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);



}

void CaptionEventBase::execBeginEditImpl (const BitVector &whichField, 
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
DataType FieldDataTraits<CaptionEventPtr>::_type("CaptionEventPtr", "EventPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(CaptionEventPtr, OSG_GAMELIB_DLLTMPLMAPPING);


OSG_END_NAMESPACE
