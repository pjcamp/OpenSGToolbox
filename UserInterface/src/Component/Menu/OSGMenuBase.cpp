/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                         www.vrac.iastate.edu                              *
 *                                                                           *
 *   Authors: David Kabala, Alden Peterson, Lee Zaniewski, Jonathan Flory    *
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
 **     class Menu!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEMENUINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGMenuBase.h"
#include "OSGMenu.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  MenuBase::InternalPopupMenuFieldMask = 
    (TypeTraits<BitVector>::One << MenuBase::InternalPopupMenuFieldId);

const OSG::BitVector  MenuBase::SubMenuDelayFieldMask = 
    (TypeTraits<BitVector>::One << MenuBase::SubMenuDelayFieldId);

const OSG::BitVector  MenuBase::TopLevelMenuFieldMask = 
    (TypeTraits<BitVector>::One << MenuBase::TopLevelMenuFieldId);

const OSG::BitVector  MenuBase::ExpandDrawObjectFieldMask = 
    (TypeTraits<BitVector>::One << MenuBase::ExpandDrawObjectFieldId);

const OSG::BitVector  MenuBase::MenuItemsFieldMask = 
    (TypeTraits<BitVector>::One << MenuBase::MenuItemsFieldId);

const OSG::BitVector MenuBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var PopupMenuPtr    MenuBase::_sfInternalPopupMenu
    
*/
/*! \var Real32          MenuBase::_sfSubMenuDelay
    
*/
/*! \var bool            MenuBase::_sfTopLevelMenu
    
*/
/*! \var UIDrawObjectCanvasPtr MenuBase::_sfExpandDrawObject
    
*/
/*! \var MenuItemPtr     MenuBase::_mfMenuItems
    
*/

//! Menu description

FieldDescription *MenuBase::_desc[] = 
{
    new FieldDescription(SFPopupMenuPtr::getClassType(), 
                     "InternalPopupMenu", 
                     InternalPopupMenuFieldId, InternalPopupMenuFieldMask,
                     false,
                     (FieldAccessMethod) &MenuBase::getSFInternalPopupMenu),
    new FieldDescription(SFReal32::getClassType(), 
                     "SubMenuDelay", 
                     SubMenuDelayFieldId, SubMenuDelayFieldMask,
                     false,
                     (FieldAccessMethod) &MenuBase::getSFSubMenuDelay),
    new FieldDescription(SFBool::getClassType(), 
                     "TopLevelMenu", 
                     TopLevelMenuFieldId, TopLevelMenuFieldMask,
                     false,
                     (FieldAccessMethod) &MenuBase::getSFTopLevelMenu),
    new FieldDescription(SFUIDrawObjectCanvasPtr::getClassType(), 
                     "ExpandDrawObject", 
                     ExpandDrawObjectFieldId, ExpandDrawObjectFieldMask,
                     false,
                     (FieldAccessMethod) &MenuBase::getSFExpandDrawObject),
    new FieldDescription(MFMenuItemPtr::getClassType(), 
                     "MenuItems", 
                     MenuItemsFieldId, MenuItemsFieldMask,
                     false,
                     (FieldAccessMethod) &MenuBase::getMFMenuItems)
};


FieldContainerType MenuBase::_type(
    "Menu",
    "MenuItem",
    NULL,
    (PrototypeCreateF) &MenuBase::createEmpty,
    Menu::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(MenuBase, MenuPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &MenuBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &MenuBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr MenuBase::shallowCopy(void) const 
{ 
    MenuPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const Menu *>(this)); 

    return returnValue; 
}

UInt32 MenuBase::getContainerSize(void) const 
{ 
    return sizeof(Menu); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void MenuBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl((MenuBase *) &other, whichField);
}
#else
void MenuBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((MenuBase *) &other, whichField, sInfo);
}
void MenuBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void MenuBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

    _mfMenuItems.terminateShare(uiAspect, this->getContainerSize());
}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

MenuBase::MenuBase(void) :
    _sfInternalPopupMenu      (), 
    _sfSubMenuDelay           (Real32(0.5)), 
    _sfTopLevelMenu           (bool(false)), 
    _sfExpandDrawObject       (), 
    _mfMenuItems              (), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

MenuBase::MenuBase(const MenuBase &source) :
    _sfInternalPopupMenu      (source._sfInternalPopupMenu      ), 
    _sfSubMenuDelay           (source._sfSubMenuDelay           ), 
    _sfTopLevelMenu           (source._sfTopLevelMenu           ), 
    _sfExpandDrawObject       (source._sfExpandDrawObject       ), 
    _mfMenuItems              (source._mfMenuItems              ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

MenuBase::~MenuBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 MenuBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (InternalPopupMenuFieldMask & whichField))
    {
        returnValue += _sfInternalPopupMenu.getBinSize();
    }

    if(FieldBits::NoField != (SubMenuDelayFieldMask & whichField))
    {
        returnValue += _sfSubMenuDelay.getBinSize();
    }

    if(FieldBits::NoField != (TopLevelMenuFieldMask & whichField))
    {
        returnValue += _sfTopLevelMenu.getBinSize();
    }

    if(FieldBits::NoField != (ExpandDrawObjectFieldMask & whichField))
    {
        returnValue += _sfExpandDrawObject.getBinSize();
    }

    if(FieldBits::NoField != (MenuItemsFieldMask & whichField))
    {
        returnValue += _mfMenuItems.getBinSize();
    }


    return returnValue;
}

void MenuBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (InternalPopupMenuFieldMask & whichField))
    {
        _sfInternalPopupMenu.copyToBin(pMem);
    }

    if(FieldBits::NoField != (SubMenuDelayFieldMask & whichField))
    {
        _sfSubMenuDelay.copyToBin(pMem);
    }

    if(FieldBits::NoField != (TopLevelMenuFieldMask & whichField))
    {
        _sfTopLevelMenu.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ExpandDrawObjectFieldMask & whichField))
    {
        _sfExpandDrawObject.copyToBin(pMem);
    }

    if(FieldBits::NoField != (MenuItemsFieldMask & whichField))
    {
        _mfMenuItems.copyToBin(pMem);
    }


}

void MenuBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (InternalPopupMenuFieldMask & whichField))
    {
        _sfInternalPopupMenu.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (SubMenuDelayFieldMask & whichField))
    {
        _sfSubMenuDelay.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (TopLevelMenuFieldMask & whichField))
    {
        _sfTopLevelMenu.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ExpandDrawObjectFieldMask & whichField))
    {
        _sfExpandDrawObject.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (MenuItemsFieldMask & whichField))
    {
        _mfMenuItems.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void MenuBase::executeSyncImpl(      MenuBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (InternalPopupMenuFieldMask & whichField))
        _sfInternalPopupMenu.syncWith(pOther->_sfInternalPopupMenu);

    if(FieldBits::NoField != (SubMenuDelayFieldMask & whichField))
        _sfSubMenuDelay.syncWith(pOther->_sfSubMenuDelay);

    if(FieldBits::NoField != (TopLevelMenuFieldMask & whichField))
        _sfTopLevelMenu.syncWith(pOther->_sfTopLevelMenu);

    if(FieldBits::NoField != (ExpandDrawObjectFieldMask & whichField))
        _sfExpandDrawObject.syncWith(pOther->_sfExpandDrawObject);

    if(FieldBits::NoField != (MenuItemsFieldMask & whichField))
        _mfMenuItems.syncWith(pOther->_mfMenuItems);


}
#else
void MenuBase::executeSyncImpl(      MenuBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (InternalPopupMenuFieldMask & whichField))
        _sfInternalPopupMenu.syncWith(pOther->_sfInternalPopupMenu);

    if(FieldBits::NoField != (SubMenuDelayFieldMask & whichField))
        _sfSubMenuDelay.syncWith(pOther->_sfSubMenuDelay);

    if(FieldBits::NoField != (TopLevelMenuFieldMask & whichField))
        _sfTopLevelMenu.syncWith(pOther->_sfTopLevelMenu);

    if(FieldBits::NoField != (ExpandDrawObjectFieldMask & whichField))
        _sfExpandDrawObject.syncWith(pOther->_sfExpandDrawObject);


    if(FieldBits::NoField != (MenuItemsFieldMask & whichField))
        _mfMenuItems.syncWith(pOther->_mfMenuItems, sInfo);


}

void MenuBase::execBeginEditImpl (const BitVector &whichField, 
                                                 UInt32     uiAspect,
                                                 UInt32     uiContainerSize)
{
    Inherited::execBeginEditImpl(whichField, uiAspect, uiContainerSize);

    if(FieldBits::NoField != (MenuItemsFieldMask & whichField))
        _mfMenuItems.beginEdit(uiAspect, uiContainerSize);

}
#endif



OSG_END_NAMESPACE

#include <OpenSG/OSGSFieldTypeDef.inl>
#include <OpenSG/OSGMFieldTypeDef.inl>

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldDataTraits<MenuPtr>::_type("MenuPtr", "MenuItemPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(MenuPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(MenuPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);


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
    static Char8 cvsid_hpp       [] = OSGMENUBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGMENUBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGMENUFIELDS_HEADER_CVSID;
}

OSG_END_NAMESPACE

