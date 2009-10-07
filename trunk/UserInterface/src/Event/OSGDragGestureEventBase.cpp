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
 **     class DragGestureEvent!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEDRAGGESTUREEVENTINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGDragGestureEventBase.h"
#include "OSGDragGestureEvent.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  DragGestureEventBase::DragLocationFieldMask = 
    (TypeTraits<BitVector>::One << DragGestureEventBase::DragLocationFieldId);

const OSG::BitVector DragGestureEventBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var Pnt2f           DragGestureEventBase::_sfDragLocation
    
*/

//! DragGestureEvent description

FieldDescription *DragGestureEventBase::_desc[] = 
{
    new FieldDescription(SFPnt2f::getClassType(), 
                     "DragLocation", 
                     DragLocationFieldId, DragLocationFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&DragGestureEventBase::editSFDragLocation))
};


FieldContainerType DragGestureEventBase::_type(
    "DragGestureEvent",
    "Event",
    NULL,
    reinterpret_cast<PrototypeCreateF>(&DragGestureEventBase::createEmpty),
    DragGestureEvent::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(DragGestureEventBase, DragGestureEventPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &DragGestureEventBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &DragGestureEventBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr DragGestureEventBase::shallowCopy(void) const 
{ 
    DragGestureEventPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const DragGestureEvent *>(this)); 

    return returnValue; 
}

UInt32 DragGestureEventBase::getContainerSize(void) const 
{ 
    return sizeof(DragGestureEvent); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void DragGestureEventBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl(static_cast<DragGestureEventBase *>(&other),
                          whichField);
}
#else
void DragGestureEventBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((DragGestureEventBase *) &other, whichField, sInfo);
}
void DragGestureEventBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void DragGestureEventBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

DragGestureEventBase::DragGestureEventBase(void) :
    _sfDragLocation           (Pnt2f(0.0f,0.0f)), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

DragGestureEventBase::DragGestureEventBase(const DragGestureEventBase &source) :
    _sfDragLocation           (source._sfDragLocation           ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

DragGestureEventBase::~DragGestureEventBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 DragGestureEventBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (DragLocationFieldMask & whichField))
    {
        returnValue += _sfDragLocation.getBinSize();
    }


    return returnValue;
}

void DragGestureEventBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (DragLocationFieldMask & whichField))
    {
        _sfDragLocation.copyToBin(pMem);
    }


}

void DragGestureEventBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (DragLocationFieldMask & whichField))
    {
        _sfDragLocation.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void DragGestureEventBase::executeSyncImpl(      DragGestureEventBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (DragLocationFieldMask & whichField))
        _sfDragLocation.syncWith(pOther->_sfDragLocation);


}
#else
void DragGestureEventBase::executeSyncImpl(      DragGestureEventBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (DragLocationFieldMask & whichField))
        _sfDragLocation.syncWith(pOther->_sfDragLocation);



}

void DragGestureEventBase::execBeginEditImpl (const BitVector &whichField, 
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
DataType FieldDataTraits<DragGestureEventPtr>::_type("DragGestureEventPtr", "EventPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(DragGestureEventPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);


OSG_END_NAMESPACE

