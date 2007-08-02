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
 **     class ShadowBorder!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILESHADOWBORDERINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGShadowBorderBase.h"
#include "OSGShadowBorder.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  ShadowBorderBase::VerticalOffsetFieldMask = 
    (TypeTraits<BitVector>::One << ShadowBorderBase::VerticalOffsetFieldId);

const OSG::BitVector  ShadowBorderBase::HorizontalOffsetFieldMask = 
    (TypeTraits<BitVector>::One << ShadowBorderBase::HorizontalOffsetFieldId);

const OSG::BitVector  ShadowBorderBase::ColorFieldMask = 
    (TypeTraits<BitVector>::One << ShadowBorderBase::ColorFieldId);

const OSG::BitVector  ShadowBorderBase::InsideBorderFieldMask = 
    (TypeTraits<BitVector>::One << ShadowBorderBase::InsideBorderFieldId);

const OSG::BitVector ShadowBorderBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var UInt32          ShadowBorderBase::_sfVerticalOffset
    
*/
/*! \var UInt32          ShadowBorderBase::_sfHorizontalOffset
    
*/
/*! \var Color4f         ShadowBorderBase::_sfColor
    
*/
/*! \var BorderPtr       ShadowBorderBase::_sfInsideBorder
    
*/

//! ShadowBorder description

FieldDescription *ShadowBorderBase::_desc[] = 
{
    new FieldDescription(SFUInt32::getClassType(), 
                     "VerticalOffset", 
                     VerticalOffsetFieldId, VerticalOffsetFieldMask,
                     false,
                     (FieldAccessMethod) &ShadowBorderBase::getSFVerticalOffset),
    new FieldDescription(SFUInt32::getClassType(), 
                     "HorizontalOffset", 
                     HorizontalOffsetFieldId, HorizontalOffsetFieldMask,
                     false,
                     (FieldAccessMethod) &ShadowBorderBase::getSFHorizontalOffset),
    new FieldDescription(SFColor4f::getClassType(), 
                     "Color", 
                     ColorFieldId, ColorFieldMask,
                     false,
                     (FieldAccessMethod) &ShadowBorderBase::getSFColor),
    new FieldDescription(SFBorderPtr::getClassType(), 
                     "InsideBorder", 
                     InsideBorderFieldId, InsideBorderFieldMask,
                     false,
                     (FieldAccessMethod) &ShadowBorderBase::getSFInsideBorder)
};


FieldContainerType ShadowBorderBase::_type(
    "ShadowBorder",
    "Border",
    NULL,
    (PrototypeCreateF) &ShadowBorderBase::createEmpty,
    ShadowBorder::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(ShadowBorderBase, ShadowBorderPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &ShadowBorderBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &ShadowBorderBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr ShadowBorderBase::shallowCopy(void) const 
{ 
    ShadowBorderPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const ShadowBorder *>(this)); 

    return returnValue; 
}

UInt32 ShadowBorderBase::getContainerSize(void) const 
{ 
    return sizeof(ShadowBorder); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void ShadowBorderBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl((ShadowBorderBase *) &other, whichField);
}
#else
void ShadowBorderBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((ShadowBorderBase *) &other, whichField, sInfo);
}
void ShadowBorderBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void ShadowBorderBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

ShadowBorderBase::ShadowBorderBase(void) :
    _sfVerticalOffset         (UInt32(5)), 
    _sfHorizontalOffset       (UInt32(5)), 
    _sfColor                  (Color4f(0.0,0.0,0.0,1.0)), 
    _sfInsideBorder           (BorderPtr(NullFC)), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

ShadowBorderBase::ShadowBorderBase(const ShadowBorderBase &source) :
    _sfVerticalOffset         (source._sfVerticalOffset         ), 
    _sfHorizontalOffset       (source._sfHorizontalOffset       ), 
    _sfColor                  (source._sfColor                  ), 
    _sfInsideBorder           (source._sfInsideBorder           ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

ShadowBorderBase::~ShadowBorderBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 ShadowBorderBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (VerticalOffsetFieldMask & whichField))
    {
        returnValue += _sfVerticalOffset.getBinSize();
    }

    if(FieldBits::NoField != (HorizontalOffsetFieldMask & whichField))
    {
        returnValue += _sfHorizontalOffset.getBinSize();
    }

    if(FieldBits::NoField != (ColorFieldMask & whichField))
    {
        returnValue += _sfColor.getBinSize();
    }

    if(FieldBits::NoField != (InsideBorderFieldMask & whichField))
    {
        returnValue += _sfInsideBorder.getBinSize();
    }


    return returnValue;
}

void ShadowBorderBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (VerticalOffsetFieldMask & whichField))
    {
        _sfVerticalOffset.copyToBin(pMem);
    }

    if(FieldBits::NoField != (HorizontalOffsetFieldMask & whichField))
    {
        _sfHorizontalOffset.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ColorFieldMask & whichField))
    {
        _sfColor.copyToBin(pMem);
    }

    if(FieldBits::NoField != (InsideBorderFieldMask & whichField))
    {
        _sfInsideBorder.copyToBin(pMem);
    }


}

void ShadowBorderBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (VerticalOffsetFieldMask & whichField))
    {
        _sfVerticalOffset.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (HorizontalOffsetFieldMask & whichField))
    {
        _sfHorizontalOffset.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ColorFieldMask & whichField))
    {
        _sfColor.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (InsideBorderFieldMask & whichField))
    {
        _sfInsideBorder.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void ShadowBorderBase::executeSyncImpl(      ShadowBorderBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (VerticalOffsetFieldMask & whichField))
        _sfVerticalOffset.syncWith(pOther->_sfVerticalOffset);

    if(FieldBits::NoField != (HorizontalOffsetFieldMask & whichField))
        _sfHorizontalOffset.syncWith(pOther->_sfHorizontalOffset);

    if(FieldBits::NoField != (ColorFieldMask & whichField))
        _sfColor.syncWith(pOther->_sfColor);

    if(FieldBits::NoField != (InsideBorderFieldMask & whichField))
        _sfInsideBorder.syncWith(pOther->_sfInsideBorder);


}
#else
void ShadowBorderBase::executeSyncImpl(      ShadowBorderBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (VerticalOffsetFieldMask & whichField))
        _sfVerticalOffset.syncWith(pOther->_sfVerticalOffset);

    if(FieldBits::NoField != (HorizontalOffsetFieldMask & whichField))
        _sfHorizontalOffset.syncWith(pOther->_sfHorizontalOffset);

    if(FieldBits::NoField != (ColorFieldMask & whichField))
        _sfColor.syncWith(pOther->_sfColor);

    if(FieldBits::NoField != (InsideBorderFieldMask & whichField))
        _sfInsideBorder.syncWith(pOther->_sfInsideBorder);



}

void ShadowBorderBase::execBeginEditImpl (const BitVector &whichField, 
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
DataType FieldDataTraits<ShadowBorderPtr>::_type("ShadowBorderPtr", "BorderPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(ShadowBorderPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(ShadowBorderPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);


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
    static Char8 cvsid_hpp       [] = OSGSHADOWBORDERBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGSHADOWBORDERBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGSHADOWBORDERFIELDS_HEADER_CVSID;
}

OSG_END_NAMESPACE

