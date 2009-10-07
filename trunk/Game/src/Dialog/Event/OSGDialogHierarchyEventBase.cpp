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
 **     class DialogHierarchyEvent!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEDIALOGHIERARCHYEVENTINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGDialogHierarchyEventBase.h"
#include "OSGDialogHierarchyEvent.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector DialogHierarchyEventBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 



FieldContainerType DialogHierarchyEventBase::_type(
    "DialogHierarchyEvent",
    "Event",
    NULL,
    reinterpret_cast<PrototypeCreateF>(&DialogHierarchyEventBase::createEmpty),
    DialogHierarchyEvent::initMethod,
    NULL,
    0);

//OSG_FIELD_CONTAINER_DEF(DialogHierarchyEventBase, DialogHierarchyEventPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &DialogHierarchyEventBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &DialogHierarchyEventBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr DialogHierarchyEventBase::shallowCopy(void) const 
{ 
    DialogHierarchyEventPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const DialogHierarchyEvent *>(this)); 

    return returnValue; 
}

UInt32 DialogHierarchyEventBase::getContainerSize(void) const 
{ 
    return sizeof(DialogHierarchyEvent); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void DialogHierarchyEventBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl(static_cast<DialogHierarchyEventBase *>(&other),
                          whichField);
}
#else
void DialogHierarchyEventBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((DialogHierarchyEventBase *) &other, whichField, sInfo);
}
void DialogHierarchyEventBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void DialogHierarchyEventBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

DialogHierarchyEventBase::DialogHierarchyEventBase(void) :
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

DialogHierarchyEventBase::DialogHierarchyEventBase(const DialogHierarchyEventBase &source) :
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

DialogHierarchyEventBase::~DialogHierarchyEventBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 DialogHierarchyEventBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);


    return returnValue;
}

void DialogHierarchyEventBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);


}

void DialogHierarchyEventBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void DialogHierarchyEventBase::executeSyncImpl(      DialogHierarchyEventBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);


}
#else
void DialogHierarchyEventBase::executeSyncImpl(      DialogHierarchyEventBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);



}

void DialogHierarchyEventBase::execBeginEditImpl (const BitVector &whichField, 
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
DataType FieldDataTraits<DialogHierarchyEventPtr>::_type("DialogHierarchyEventPtr", "EventPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(DialogHierarchyEventPtr, OSG_GAMELIB_DLLTMPLMAPPING);


OSG_END_NAMESPACE

