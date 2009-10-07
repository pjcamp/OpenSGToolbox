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
 **     class MenuButton!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEMENUBUTTONINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGMenuButtonBase.h"
#include "OSGMenuButton.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  MenuButtonBase::ModelFieldMask = 
    (TypeTraits<BitVector>::One << MenuButtonBase::ModelFieldId);

const OSG::BitVector  MenuButtonBase::CellGeneratorFieldMask = 
    (TypeTraits<BitVector>::One << MenuButtonBase::CellGeneratorFieldId);

const OSG::BitVector  MenuButtonBase::MenuButtonPopupMenuFieldMask = 
    (TypeTraits<BitVector>::One << MenuButtonBase::MenuButtonPopupMenuFieldId);

const OSG::BitVector MenuButtonBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var ListModelPtr    MenuButtonBase::_sfModel
    
*/
/*! \var ComponentGeneratorPtr MenuButtonBase::_sfCellGenerator
    
*/
/*! \var ListGeneratedPopupMenuPtr MenuButtonBase::_sfMenuButtonPopupMenu
    
*/

//! MenuButton description

FieldDescription *MenuButtonBase::_desc[] = 
{
    new FieldDescription(SFListModelPtr::getClassType(), 
                     "Model", 
                     ModelFieldId, ModelFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&MenuButtonBase::editSFModel)),
    new FieldDescription(SFComponentGeneratorPtr::getClassType(), 
                     "CellGenerator", 
                     CellGeneratorFieldId, CellGeneratorFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&MenuButtonBase::editSFCellGenerator)),
    new FieldDescription(SFListGeneratedPopupMenuPtr::getClassType(), 
                     "MenuButtonPopupMenu", 
                     MenuButtonPopupMenuFieldId, MenuButtonPopupMenuFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&MenuButtonBase::editSFMenuButtonPopupMenu))
};


FieldContainerType MenuButtonBase::_type(
    "MenuButton",
    "ToggleButton",
    NULL,
    reinterpret_cast<PrototypeCreateF>(&MenuButtonBase::createEmpty),
    MenuButton::initMethod,
    _desc,
    sizeof(_desc));

//! MenuButton Produced Methods

MethodDescription *MenuButtonBase::_methodDesc[] =
{
    new MethodDescription("MenuActionPerformed", 
                     MenuActionPerformedMethodId, 
                     SFEventPtr::getClassType(),
                     FunctorAccessMethod())
};

EventProducerType MenuButtonBase::_producerType(
    "MenuButtonProducerType",
    "ToggleButtonProducerType",
    NULL,
    InitEventProducerFunctor(),
    _methodDesc,
    sizeof(_methodDesc));
//OSG_FIELD_CONTAINER_DEF(MenuButtonBase, MenuButtonPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &MenuButtonBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &MenuButtonBase::getType(void) const 
{
    return _type;
} 

const EventProducerType &MenuButtonBase::getProducerType(void) const
{
    return _producerType;
}


FieldContainerPtr MenuButtonBase::shallowCopy(void) const 
{ 
    MenuButtonPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const MenuButton *>(this)); 

    return returnValue; 
}

UInt32 MenuButtonBase::getContainerSize(void) const 
{ 
    return sizeof(MenuButton); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void MenuButtonBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl(static_cast<MenuButtonBase *>(&other),
                          whichField);
}
#else
void MenuButtonBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((MenuButtonBase *) &other, whichField, sInfo);
}
void MenuButtonBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void MenuButtonBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

MenuButtonBase::MenuButtonBase(void) :
    _sfModel                  (ListModelPtr(NullFC)), 
    _sfCellGenerator          (ComponentGeneratorPtr(NullFC)), 
    _sfMenuButtonPopupMenu    (ListGeneratedPopupMenuPtr(NullFC)), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

MenuButtonBase::MenuButtonBase(const MenuButtonBase &source) :
    _sfModel                  (source._sfModel                  ), 
    _sfCellGenerator          (source._sfCellGenerator          ), 
    _sfMenuButtonPopupMenu    (source._sfMenuButtonPopupMenu    ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

MenuButtonBase::~MenuButtonBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 MenuButtonBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ModelFieldMask & whichField))
    {
        returnValue += _sfModel.getBinSize();
    }

    if(FieldBits::NoField != (CellGeneratorFieldMask & whichField))
    {
        returnValue += _sfCellGenerator.getBinSize();
    }

    if(FieldBits::NoField != (MenuButtonPopupMenuFieldMask & whichField))
    {
        returnValue += _sfMenuButtonPopupMenu.getBinSize();
    }


    return returnValue;
}

void MenuButtonBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ModelFieldMask & whichField))
    {
        _sfModel.copyToBin(pMem);
    }

    if(FieldBits::NoField != (CellGeneratorFieldMask & whichField))
    {
        _sfCellGenerator.copyToBin(pMem);
    }

    if(FieldBits::NoField != (MenuButtonPopupMenuFieldMask & whichField))
    {
        _sfMenuButtonPopupMenu.copyToBin(pMem);
    }


}

void MenuButtonBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ModelFieldMask & whichField))
    {
        _sfModel.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (CellGeneratorFieldMask & whichField))
    {
        _sfCellGenerator.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (MenuButtonPopupMenuFieldMask & whichField))
    {
        _sfMenuButtonPopupMenu.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void MenuButtonBase::executeSyncImpl(      MenuButtonBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (ModelFieldMask & whichField))
        _sfModel.syncWith(pOther->_sfModel);

    if(FieldBits::NoField != (CellGeneratorFieldMask & whichField))
        _sfCellGenerator.syncWith(pOther->_sfCellGenerator);

    if(FieldBits::NoField != (MenuButtonPopupMenuFieldMask & whichField))
        _sfMenuButtonPopupMenu.syncWith(pOther->_sfMenuButtonPopupMenu);


}
#else
void MenuButtonBase::executeSyncImpl(      MenuButtonBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (ModelFieldMask & whichField))
        _sfModel.syncWith(pOther->_sfModel);

    if(FieldBits::NoField != (CellGeneratorFieldMask & whichField))
        _sfCellGenerator.syncWith(pOther->_sfCellGenerator);

    if(FieldBits::NoField != (MenuButtonPopupMenuFieldMask & whichField))
        _sfMenuButtonPopupMenu.syncWith(pOther->_sfMenuButtonPopupMenu);



}

void MenuButtonBase::execBeginEditImpl (const BitVector &whichField, 
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
DataType FieldDataTraits<MenuButtonPtr>::_type("MenuButtonPtr", "ToggleButtonPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(MenuButtonPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(MenuButtonPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);


OSG_END_NAMESPACE

