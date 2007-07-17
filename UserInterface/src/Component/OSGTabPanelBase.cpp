/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2002 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 *   contact: dirk@opensg.org, gerrit.voss@vossg.org, jbehr@zgdv.de          *
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
 **     class TabPanel!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILETABPANELINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"
#include "OSGTabPanelBase.h"
#include "OSGTabPanel.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  TabPanelBase::TabsFieldMask = 
    (TypeTraits<BitVector>::One << TabPanelBase::TabsFieldId);

const OSG::BitVector  TabPanelBase::TabContentsFieldMask = 
    (TypeTraits<BitVector>::One << TabPanelBase::TabContentsFieldId);

const OSG::BitVector  TabPanelBase::ActiveTabFieldMask = 
    (TypeTraits<BitVector>::One << TabPanelBase::ActiveTabFieldId);

const OSG::BitVector  TabPanelBase::TabPlacementFieldMask = 
    (TypeTraits<BitVector>::One << TabPanelBase::TabPlacementFieldId);

const OSG::BitVector  TabPanelBase::TabAlignmentFieldMask = 
    (TypeTraits<BitVector>::One << TabPanelBase::TabAlignmentFieldId);

const OSG::BitVector  TabPanelBase::TabRotationFieldMask = 
    (TypeTraits<BitVector>::One << TabPanelBase::TabRotationFieldId);

const OSG::BitVector TabPanelBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var ComponentPtr    TabPanelBase::_mfTabs
    
*/
/*! \var ComponentPtr    TabPanelBase::_mfTabContents
    
*/
/*! \var UInt32          TabPanelBase::_sfActiveTab
    
*/
/*! \var UInt32          TabPanelBase::_sfTabPlacement
    
*/
/*! \var UInt32          TabPanelBase::_sfTabAlignment
    
*/
/*! \var UInt32          TabPanelBase::_sfTabRotation
    
*/

//! TabPanel description

FieldDescription *TabPanelBase::_desc[] = 
{
    new FieldDescription(MFComponentPtr::getClassType(), 
                     "Tabs", 
                     TabsFieldId, TabsFieldMask,
                     false,
                     (FieldAccessMethod) &TabPanelBase::getMFTabs),
    new FieldDescription(MFComponentPtr::getClassType(), 
                     "TabContents", 
                     TabContentsFieldId, TabContentsFieldMask,
                     false,
                     (FieldAccessMethod) &TabPanelBase::getMFTabContents),
    new FieldDescription(SFUInt32::getClassType(), 
                     "ActiveTab", 
                     ActiveTabFieldId, ActiveTabFieldMask,
                     false,
                     (FieldAccessMethod) &TabPanelBase::getSFActiveTab),
    new FieldDescription(SFUInt32::getClassType(), 
                     "TabPlacement", 
                     TabPlacementFieldId, TabPlacementFieldMask,
                     false,
                     (FieldAccessMethod) &TabPanelBase::getSFTabPlacement),
    new FieldDescription(SFUInt32::getClassType(), 
                     "TabAlignment", 
                     TabAlignmentFieldId, TabAlignmentFieldMask,
                     false,
                     (FieldAccessMethod) &TabPanelBase::getSFTabAlignment),
    new FieldDescription(SFUInt32::getClassType(), 
                     "TabRotation", 
                     TabRotationFieldId, TabRotationFieldMask,
                     false,
                     (FieldAccessMethod) &TabPanelBase::getSFTabRotation)
};


FieldContainerType TabPanelBase::_type(
    "TabPanel",
    "Component",
    NULL,
    (PrototypeCreateF) &TabPanelBase::createEmpty,
    TabPanel::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(TabPanelBase, TabPanelPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &TabPanelBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &TabPanelBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr TabPanelBase::shallowCopy(void) const 
{ 
    TabPanelPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const TabPanel *>(this)); 

    return returnValue; 
}

UInt32 TabPanelBase::getContainerSize(void) const 
{ 
    return sizeof(TabPanel); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void TabPanelBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl((TabPanelBase *) &other, whichField);
}
#else
void TabPanelBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((TabPanelBase *) &other, whichField, sInfo);
}
void TabPanelBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void TabPanelBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

    _mfTabs.terminateShare(uiAspect, this->getContainerSize());
    _mfTabContents.terminateShare(uiAspect, this->getContainerSize());
}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

TabPanelBase::TabPanelBase(void) :
    _mfTabs                   (), 
    _mfTabContents            (), 
    _sfActiveTab              (UInt32(0)), 
    _sfTabPlacement           (UInt32(0)), 
    _sfTabAlignment           (UInt32(0)), 
    _sfTabRotation            (UInt32(0)), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

TabPanelBase::TabPanelBase(const TabPanelBase &source) :
    _mfTabs                   (source._mfTabs                   ), 
    _mfTabContents            (source._mfTabContents            ), 
    _sfActiveTab              (source._sfActiveTab              ), 
    _sfTabPlacement           (source._sfTabPlacement           ), 
    _sfTabAlignment           (source._sfTabAlignment           ), 
    _sfTabRotation            (source._sfTabRotation            ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

TabPanelBase::~TabPanelBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 TabPanelBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (TabsFieldMask & whichField))
    {
        returnValue += _mfTabs.getBinSize();
    }

    if(FieldBits::NoField != (TabContentsFieldMask & whichField))
    {
        returnValue += _mfTabContents.getBinSize();
    }

    if(FieldBits::NoField != (ActiveTabFieldMask & whichField))
    {
        returnValue += _sfActiveTab.getBinSize();
    }

    if(FieldBits::NoField != (TabPlacementFieldMask & whichField))
    {
        returnValue += _sfTabPlacement.getBinSize();
    }

    if(FieldBits::NoField != (TabAlignmentFieldMask & whichField))
    {
        returnValue += _sfTabAlignment.getBinSize();
    }

    if(FieldBits::NoField != (TabRotationFieldMask & whichField))
    {
        returnValue += _sfTabRotation.getBinSize();
    }


    return returnValue;
}

void TabPanelBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (TabsFieldMask & whichField))
    {
        _mfTabs.copyToBin(pMem);
    }

    if(FieldBits::NoField != (TabContentsFieldMask & whichField))
    {
        _mfTabContents.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ActiveTabFieldMask & whichField))
    {
        _sfActiveTab.copyToBin(pMem);
    }

    if(FieldBits::NoField != (TabPlacementFieldMask & whichField))
    {
        _sfTabPlacement.copyToBin(pMem);
    }

    if(FieldBits::NoField != (TabAlignmentFieldMask & whichField))
    {
        _sfTabAlignment.copyToBin(pMem);
    }

    if(FieldBits::NoField != (TabRotationFieldMask & whichField))
    {
        _sfTabRotation.copyToBin(pMem);
    }


}

void TabPanelBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (TabsFieldMask & whichField))
    {
        _mfTabs.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (TabContentsFieldMask & whichField))
    {
        _mfTabContents.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ActiveTabFieldMask & whichField))
    {
        _sfActiveTab.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (TabPlacementFieldMask & whichField))
    {
        _sfTabPlacement.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (TabAlignmentFieldMask & whichField))
    {
        _sfTabAlignment.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (TabRotationFieldMask & whichField))
    {
        _sfTabRotation.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void TabPanelBase::executeSyncImpl(      TabPanelBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (TabsFieldMask & whichField))
        _mfTabs.syncWith(pOther->_mfTabs);

    if(FieldBits::NoField != (TabContentsFieldMask & whichField))
        _mfTabContents.syncWith(pOther->_mfTabContents);

    if(FieldBits::NoField != (ActiveTabFieldMask & whichField))
        _sfActiveTab.syncWith(pOther->_sfActiveTab);

    if(FieldBits::NoField != (TabPlacementFieldMask & whichField))
        _sfTabPlacement.syncWith(pOther->_sfTabPlacement);

    if(FieldBits::NoField != (TabAlignmentFieldMask & whichField))
        _sfTabAlignment.syncWith(pOther->_sfTabAlignment);

    if(FieldBits::NoField != (TabRotationFieldMask & whichField))
        _sfTabRotation.syncWith(pOther->_sfTabRotation);


}
#else
void TabPanelBase::executeSyncImpl(      TabPanelBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (ActiveTabFieldMask & whichField))
        _sfActiveTab.syncWith(pOther->_sfActiveTab);

    if(FieldBits::NoField != (TabPlacementFieldMask & whichField))
        _sfTabPlacement.syncWith(pOther->_sfTabPlacement);

    if(FieldBits::NoField != (TabAlignmentFieldMask & whichField))
        _sfTabAlignment.syncWith(pOther->_sfTabAlignment);

    if(FieldBits::NoField != (TabRotationFieldMask & whichField))
        _sfTabRotation.syncWith(pOther->_sfTabRotation);


    if(FieldBits::NoField != (TabsFieldMask & whichField))
        _mfTabs.syncWith(pOther->_mfTabs, sInfo);

    if(FieldBits::NoField != (TabContentsFieldMask & whichField))
        _mfTabContents.syncWith(pOther->_mfTabContents, sInfo);


}

void TabPanelBase::execBeginEditImpl (const BitVector &whichField, 
                                                 UInt32     uiAspect,
                                                 UInt32     uiContainerSize)
{
    Inherited::execBeginEditImpl(whichField, uiAspect, uiContainerSize);

    if(FieldBits::NoField != (TabsFieldMask & whichField))
        _mfTabs.beginEdit(uiAspect, uiContainerSize);

    if(FieldBits::NoField != (TabContentsFieldMask & whichField))
        _mfTabContents.beginEdit(uiAspect, uiContainerSize);

}
#endif



OSG_END_NAMESPACE

#include <OpenSG/OSGSFieldTypeDef.inl>
#include <OpenSG/OSGMFieldTypeDef.inl>

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldDataTraits<TabPanelPtr>::_type("TabPanelPtr", "ComponentPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(TabPanelPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(TabPanelPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);


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
    static Char8 cvsid_hpp       [] = OSGTABPANELBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGTABPANELBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGTABPANELFIELDS_HEADER_CVSID;
}

OSG_END_NAMESPACE

