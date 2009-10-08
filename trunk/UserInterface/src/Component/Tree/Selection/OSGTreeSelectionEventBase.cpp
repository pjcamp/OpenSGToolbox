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
 **     class TreeSelectionEvent!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILETREESELECTIONEVENTINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGTreeSelectionEventBase.h"
#include "OSGTreeSelectionEvent.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  TreeSelectionEventBase::NewLeadSelectionPathFieldMask = 
    (TypeTraits<BitVector>::One << TreeSelectionEventBase::NewLeadSelectionPathFieldId);

const OSG::BitVector  TreeSelectionEventBase::OldLeadSelectionPathFieldMask = 
    (TypeTraits<BitVector>::One << TreeSelectionEventBase::OldLeadSelectionPathFieldId);

const OSG::BitVector  TreeSelectionEventBase::ElementsChangedFieldMask = 
    (TypeTraits<BitVector>::One << TreeSelectionEventBase::ElementsChangedFieldId);

const OSG::BitVector TreeSelectionEventBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var Int32           TreeSelectionEventBase::_sfNewLeadSelectionPath
    
*/
/*! \var Int32           TreeSelectionEventBase::_sfOldLeadSelectionPath
    
*/
/*! \var Vec2s           TreeSelectionEventBase::_mfElementsChanged
    
*/

//! TreeSelectionEvent description

FieldDescription *TreeSelectionEventBase::_desc[] = 
{
    new FieldDescription(SFInt32::getClassType(), 
                     "NewLeadSelectionPath", 
                     NewLeadSelectionPathFieldId, NewLeadSelectionPathFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&TreeSelectionEventBase::editSFNewLeadSelectionPath)),
    new FieldDescription(SFInt32::getClassType(), 
                     "OldLeadSelectionPath", 
                     OldLeadSelectionPathFieldId, OldLeadSelectionPathFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&TreeSelectionEventBase::editSFOldLeadSelectionPath)),
    new FieldDescription(MFVec2s::getClassType(), 
                     "ElementsChanged", 
                     ElementsChangedFieldId, ElementsChangedFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&TreeSelectionEventBase::editMFElementsChanged))
};


FieldContainerType TreeSelectionEventBase::_type(
    "TreeSelectionEvent",
    "Event",
    NULL,
    reinterpret_cast<PrototypeCreateF>(&TreeSelectionEventBase::createEmpty),
    TreeSelectionEvent::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(TreeSelectionEventBase, TreeSelectionEventPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &TreeSelectionEventBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &TreeSelectionEventBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr TreeSelectionEventBase::shallowCopy(void) const 
{ 
    TreeSelectionEventPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const TreeSelectionEvent *>(this)); 

    return returnValue; 
}

UInt32 TreeSelectionEventBase::getContainerSize(void) const 
{ 
    return sizeof(TreeSelectionEvent); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void TreeSelectionEventBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl(static_cast<TreeSelectionEventBase *>(&other),
                          whichField);
}
#else
void TreeSelectionEventBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((TreeSelectionEventBase *) &other, whichField, sInfo);
}
void TreeSelectionEventBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void TreeSelectionEventBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

    _mfElementsChanged.terminateShare(uiAspect, this->getContainerSize());
}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

TreeSelectionEventBase::TreeSelectionEventBase(void) :
    _sfNewLeadSelectionPath   (Int32(-1)), 
    _sfOldLeadSelectionPath   (Int32(-1)), 
    _mfElementsChanged        (), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

TreeSelectionEventBase::TreeSelectionEventBase(const TreeSelectionEventBase &source) :
    _sfNewLeadSelectionPath   (source._sfNewLeadSelectionPath   ), 
    _sfOldLeadSelectionPath   (source._sfOldLeadSelectionPath   ), 
    _mfElementsChanged        (source._mfElementsChanged        ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

TreeSelectionEventBase::~TreeSelectionEventBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 TreeSelectionEventBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (NewLeadSelectionPathFieldMask & whichField))
    {
        returnValue += _sfNewLeadSelectionPath.getBinSize();
    }

    if(FieldBits::NoField != (OldLeadSelectionPathFieldMask & whichField))
    {
        returnValue += _sfOldLeadSelectionPath.getBinSize();
    }

    if(FieldBits::NoField != (ElementsChangedFieldMask & whichField))
    {
        returnValue += _mfElementsChanged.getBinSize();
    }


    return returnValue;
}

void TreeSelectionEventBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (NewLeadSelectionPathFieldMask & whichField))
    {
        _sfNewLeadSelectionPath.copyToBin(pMem);
    }

    if(FieldBits::NoField != (OldLeadSelectionPathFieldMask & whichField))
    {
        _sfOldLeadSelectionPath.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ElementsChangedFieldMask & whichField))
    {
        _mfElementsChanged.copyToBin(pMem);
    }


}

void TreeSelectionEventBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (NewLeadSelectionPathFieldMask & whichField))
    {
        _sfNewLeadSelectionPath.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (OldLeadSelectionPathFieldMask & whichField))
    {
        _sfOldLeadSelectionPath.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ElementsChangedFieldMask & whichField))
    {
        _mfElementsChanged.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void TreeSelectionEventBase::executeSyncImpl(      TreeSelectionEventBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (NewLeadSelectionPathFieldMask & whichField))
        _sfNewLeadSelectionPath.syncWith(pOther->_sfNewLeadSelectionPath);

    if(FieldBits::NoField != (OldLeadSelectionPathFieldMask & whichField))
        _sfOldLeadSelectionPath.syncWith(pOther->_sfOldLeadSelectionPath);

    if(FieldBits::NoField != (ElementsChangedFieldMask & whichField))
        _mfElementsChanged.syncWith(pOther->_mfElementsChanged);


}
#else
void TreeSelectionEventBase::executeSyncImpl(      TreeSelectionEventBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (NewLeadSelectionPathFieldMask & whichField))
        _sfNewLeadSelectionPath.syncWith(pOther->_sfNewLeadSelectionPath);

    if(FieldBits::NoField != (OldLeadSelectionPathFieldMask & whichField))
        _sfOldLeadSelectionPath.syncWith(pOther->_sfOldLeadSelectionPath);


    if(FieldBits::NoField != (ElementsChangedFieldMask & whichField))
        _mfElementsChanged.syncWith(pOther->_mfElementsChanged, sInfo);


}

void TreeSelectionEventBase::execBeginEditImpl (const BitVector &whichField, 
                                                 UInt32     uiAspect,
                                                 UInt32     uiContainerSize)
{
    Inherited::execBeginEditImpl(whichField, uiAspect, uiContainerSize);

    if(FieldBits::NoField != (ElementsChangedFieldMask & whichField))
        _mfElementsChanged.beginEdit(uiAspect, uiContainerSize);

}
#endif



OSG_END_NAMESPACE

#include <OpenSG/OSGSFieldTypeDef.inl>

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldDataTraits<TreeSelectionEventPtr>::_type("TreeSelectionEventPtr", "EventPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(TreeSelectionEventPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);


OSG_END_NAMESPACE
