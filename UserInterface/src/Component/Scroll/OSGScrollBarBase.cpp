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
 **     class Scrollbar!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILESCROLLBARINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGScrollbarBase.h"
#include "OSGScrollbar.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  ScrollbarBase::OrientationFieldMask = 
    (TypeTraits<BitVector>::One << ScrollbarBase::OrientationFieldId);

const OSG::BitVector  ScrollbarBase::UnitIncrementFieldMask = 
    (TypeTraits<BitVector>::One << ScrollbarBase::UnitIncrementFieldId);

const OSG::BitVector  ScrollbarBase::BlockIncrementFieldMask = 
    (TypeTraits<BitVector>::One << ScrollbarBase::BlockIncrementFieldId);

const OSG::BitVector  ScrollbarBase::MinButtonFieldMask = 
    (TypeTraits<BitVector>::One << ScrollbarBase::MinButtonFieldId);

const OSG::BitVector  ScrollbarBase::MaxButtonFieldMask = 
    (TypeTraits<BitVector>::One << ScrollbarBase::MaxButtonFieldId);

const OSG::BitVector  ScrollbarBase::ScrollbarFieldMask = 
    (TypeTraits<BitVector>::One << ScrollbarBase::ScrollbarFieldId);

const OSG::BitVector  ScrollbarBase::ScrollFieldFieldMask = 
    (TypeTraits<BitVector>::One << ScrollbarBase::ScrollFieldFieldId);

const OSG::BitVector ScrollbarBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var UInt32          ScrollbarBase::_sfOrientation
    
*/
/*! \var UInt32          ScrollbarBase::_sfUnitIncrement
    
*/
/*! \var UInt32          ScrollbarBase::_sfBlockIncrement
    
*/
/*! \var ButtonPtr       ScrollbarBase::_sfMinButton
    
*/
/*! \var ButtonPtr       ScrollbarBase::_sfMaxButton
    
*/
/*! \var UIDrawObjectCanvasPtr ScrollbarBase::_sfScrollbar
    
*/
/*! \var UIDrawObjectCanvasPtr ScrollbarBase::_sfScrollField
    
*/

//! Scrollbar description

FieldDescription *ScrollbarBase::_desc[] = 
{
    new FieldDescription(SFUInt32::getClassType(), 
                     "Orientation", 
                     OrientationFieldId, OrientationFieldMask,
                     false,
                     (FieldAccessMethod) &ScrollbarBase::getSFOrientation),
    new FieldDescription(SFUInt32::getClassType(), 
                     "UnitIncrement", 
                     UnitIncrementFieldId, UnitIncrementFieldMask,
                     false,
                     (FieldAccessMethod) &ScrollbarBase::getSFUnitIncrement),
    new FieldDescription(SFUInt32::getClassType(), 
                     "BlockIncrement", 
                     BlockIncrementFieldId, BlockIncrementFieldMask,
                     false,
                     (FieldAccessMethod) &ScrollbarBase::getSFBlockIncrement),
    new FieldDescription(SFButtonPtr::getClassType(), 
                     "MinButton", 
                     MinButtonFieldId, MinButtonFieldMask,
                     false,
                     (FieldAccessMethod) &ScrollbarBase::getSFMinButton),
    new FieldDescription(SFButtonPtr::getClassType(), 
                     "MaxButton", 
                     MaxButtonFieldId, MaxButtonFieldMask,
                     false,
                     (FieldAccessMethod) &ScrollbarBase::getSFMaxButton),
    new FieldDescription(SFUIDrawObjectCanvasPtr::getClassType(), 
                     "Scrollbar", 
                     ScrollbarFieldId, ScrollbarFieldMask,
                     false,
                     (FieldAccessMethod) &ScrollbarBase::getSFScrollbar),
    new FieldDescription(SFUIDrawObjectCanvasPtr::getClassType(), 
                     "ScrollField", 
                     ScrollFieldFieldId, ScrollFieldFieldMask,
                     false,
                     (FieldAccessMethod) &ScrollbarBase::getSFScrollField)
};


FieldContainerType ScrollbarBase::_type(
    "Scrollbar",
    "Container",
    NULL,
    (PrototypeCreateF) &ScrollbarBase::createEmpty,
    Scrollbar::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(ScrollbarBase, ScrollbarPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &ScrollbarBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &ScrollbarBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr ScrollbarBase::shallowCopy(void) const 
{ 
    ScrollbarPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const Scrollbar *>(this)); 

    return returnValue; 
}

UInt32 ScrollbarBase::getContainerSize(void) const 
{ 
    return sizeof(Scrollbar); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void ScrollbarBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl((ScrollbarBase *) &other, whichField);
}
#else
void ScrollbarBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((ScrollbarBase *) &other, whichField, sInfo);
}
void ScrollbarBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void ScrollbarBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

ScrollbarBase::ScrollbarBase(void) :
    _sfOrientation            (UInt32(VERTICAL_ALIGNMENT)), 
    _sfUnitIncrement          (UInt32(1)), 
    _sfBlockIncrement         (UInt32(2)), 
    _sfMinButton              (ButtonPtr(NullFC)), 
    _sfMaxButton              (ButtonPtr(NullFC)), 
    _sfScrollbar              (UIDrawObjectCanvasPtr(NullFC)), 
    _sfScrollField            (UIDrawObjectCanvasPtr(NullFC)), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

ScrollbarBase::ScrollbarBase(const ScrollbarBase &source) :
    _sfOrientation            (source._sfOrientation            ), 
    _sfUnitIncrement          (source._sfUnitIncrement          ), 
    _sfBlockIncrement         (source._sfBlockIncrement         ), 
    _sfMinButton              (source._sfMinButton              ), 
    _sfMaxButton              (source._sfMaxButton              ), 
    _sfScrollbar              (source._sfScrollbar              ), 
    _sfScrollField            (source._sfScrollField            ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

ScrollbarBase::~ScrollbarBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 ScrollbarBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (OrientationFieldMask & whichField))
    {
        returnValue += _sfOrientation.getBinSize();
    }

    if(FieldBits::NoField != (UnitIncrementFieldMask & whichField))
    {
        returnValue += _sfUnitIncrement.getBinSize();
    }

    if(FieldBits::NoField != (BlockIncrementFieldMask & whichField))
    {
        returnValue += _sfBlockIncrement.getBinSize();
    }

    if(FieldBits::NoField != (MinButtonFieldMask & whichField))
    {
        returnValue += _sfMinButton.getBinSize();
    }

    if(FieldBits::NoField != (MaxButtonFieldMask & whichField))
    {
        returnValue += _sfMaxButton.getBinSize();
    }

    if(FieldBits::NoField != (ScrollbarFieldMask & whichField))
    {
        returnValue += _sfScrollbar.getBinSize();
    }

    if(FieldBits::NoField != (ScrollFieldFieldMask & whichField))
    {
        returnValue += _sfScrollField.getBinSize();
    }


    return returnValue;
}

void ScrollbarBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (OrientationFieldMask & whichField))
    {
        _sfOrientation.copyToBin(pMem);
    }

    if(FieldBits::NoField != (UnitIncrementFieldMask & whichField))
    {
        _sfUnitIncrement.copyToBin(pMem);
    }

    if(FieldBits::NoField != (BlockIncrementFieldMask & whichField))
    {
        _sfBlockIncrement.copyToBin(pMem);
    }

    if(FieldBits::NoField != (MinButtonFieldMask & whichField))
    {
        _sfMinButton.copyToBin(pMem);
    }

    if(FieldBits::NoField != (MaxButtonFieldMask & whichField))
    {
        _sfMaxButton.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ScrollbarFieldMask & whichField))
    {
        _sfScrollbar.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ScrollFieldFieldMask & whichField))
    {
        _sfScrollField.copyToBin(pMem);
    }


}

void ScrollbarBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (OrientationFieldMask & whichField))
    {
        _sfOrientation.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (UnitIncrementFieldMask & whichField))
    {
        _sfUnitIncrement.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (BlockIncrementFieldMask & whichField))
    {
        _sfBlockIncrement.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (MinButtonFieldMask & whichField))
    {
        _sfMinButton.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (MaxButtonFieldMask & whichField))
    {
        _sfMaxButton.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ScrollbarFieldMask & whichField))
    {
        _sfScrollbar.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ScrollFieldFieldMask & whichField))
    {
        _sfScrollField.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void ScrollbarBase::executeSyncImpl(      ScrollbarBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (OrientationFieldMask & whichField))
        _sfOrientation.syncWith(pOther->_sfOrientation);

    if(FieldBits::NoField != (UnitIncrementFieldMask & whichField))
        _sfUnitIncrement.syncWith(pOther->_sfUnitIncrement);

    if(FieldBits::NoField != (BlockIncrementFieldMask & whichField))
        _sfBlockIncrement.syncWith(pOther->_sfBlockIncrement);

    if(FieldBits::NoField != (MinButtonFieldMask & whichField))
        _sfMinButton.syncWith(pOther->_sfMinButton);

    if(FieldBits::NoField != (MaxButtonFieldMask & whichField))
        _sfMaxButton.syncWith(pOther->_sfMaxButton);

    if(FieldBits::NoField != (ScrollbarFieldMask & whichField))
        _sfScrollbar.syncWith(pOther->_sfScrollbar);

    if(FieldBits::NoField != (ScrollFieldFieldMask & whichField))
        _sfScrollField.syncWith(pOther->_sfScrollField);


}
#else
void ScrollbarBase::executeSyncImpl(      ScrollbarBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (OrientationFieldMask & whichField))
        _sfOrientation.syncWith(pOther->_sfOrientation);

    if(FieldBits::NoField != (UnitIncrementFieldMask & whichField))
        _sfUnitIncrement.syncWith(pOther->_sfUnitIncrement);

    if(FieldBits::NoField != (BlockIncrementFieldMask & whichField))
        _sfBlockIncrement.syncWith(pOther->_sfBlockIncrement);

    if(FieldBits::NoField != (MinButtonFieldMask & whichField))
        _sfMinButton.syncWith(pOther->_sfMinButton);

    if(FieldBits::NoField != (MaxButtonFieldMask & whichField))
        _sfMaxButton.syncWith(pOther->_sfMaxButton);

    if(FieldBits::NoField != (ScrollbarFieldMask & whichField))
        _sfScrollbar.syncWith(pOther->_sfScrollbar);

    if(FieldBits::NoField != (ScrollFieldFieldMask & whichField))
        _sfScrollField.syncWith(pOther->_sfScrollField);



}

void ScrollbarBase::execBeginEditImpl (const BitVector &whichField, 
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
DataType FieldDataTraits<ScrollbarPtr>::_type("ScrollbarPtr", "ContainerPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(ScrollbarPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(ScrollbarPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);


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
    static Char8 cvsid_hpp       [] = OSGSCROLLBARBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGSCROLLBARBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGSCROLLBARFIELDS_HEADER_CVSID;
}

OSG_END_NAMESPACE

