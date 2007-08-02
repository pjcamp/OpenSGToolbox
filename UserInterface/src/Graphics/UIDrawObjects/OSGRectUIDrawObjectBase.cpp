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
 **     class RectUIDrawObject!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILERECTUIDRAWOBJECTINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"
#include "OSGRectUIDrawObjectBase.h"
#include "OSGRectUIDrawObject.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  RectUIDrawObjectBase::TopLeftFieldMask = 
    (TypeTraits<BitVector>::One << RectUIDrawObjectBase::TopLeftFieldId);

const OSG::BitVector  RectUIDrawObjectBase::BottomRightFieldMask = 
    (TypeTraits<BitVector>::One << RectUIDrawObjectBase::BottomRightFieldId);

const OSG::BitVector  RectUIDrawObjectBase::ColorFieldMask = 
    (TypeTraits<BitVector>::One << RectUIDrawObjectBase::ColorFieldId);

const OSG::BitVector  RectUIDrawObjectBase::OpacityFieldMask = 
    (TypeTraits<BitVector>::One << RectUIDrawObjectBase::OpacityFieldId);

const OSG::BitVector RectUIDrawObjectBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var Pnt2s           RectUIDrawObjectBase::_sfTopLeft
    
*/
/*! \var Pnt2s           RectUIDrawObjectBase::_sfBottomRight
    
*/
/*! \var Color4f         RectUIDrawObjectBase::_sfColor
    
*/
/*! \var Real32          RectUIDrawObjectBase::_sfOpacity
    
*/

//! RectUIDrawObject description

FieldDescription *RectUIDrawObjectBase::_desc[] = 
{
    new FieldDescription(SFPnt2s::getClassType(), 
                     "TopLeft", 
                     TopLeftFieldId, TopLeftFieldMask,
                     false,
                     (FieldAccessMethod) &RectUIDrawObjectBase::getSFTopLeft),
    new FieldDescription(SFPnt2s::getClassType(), 
                     "BottomRight", 
                     BottomRightFieldId, BottomRightFieldMask,
                     false,
                     (FieldAccessMethod) &RectUIDrawObjectBase::getSFBottomRight),
    new FieldDescription(SFColor4f::getClassType(), 
                     "Color", 
                     ColorFieldId, ColorFieldMask,
                     false,
                     (FieldAccessMethod) &RectUIDrawObjectBase::getSFColor),
    new FieldDescription(SFReal32::getClassType(), 
                     "Opacity", 
                     OpacityFieldId, OpacityFieldMask,
                     false,
                     (FieldAccessMethod) &RectUIDrawObjectBase::getSFOpacity)
};


FieldContainerType RectUIDrawObjectBase::_type(
    "RectUIDrawObject",
    "UIDrawObject",
    NULL,
    (PrototypeCreateF) &RectUIDrawObjectBase::createEmpty,
    RectUIDrawObject::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(RectUIDrawObjectBase, RectUIDrawObjectPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &RectUIDrawObjectBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &RectUIDrawObjectBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr RectUIDrawObjectBase::shallowCopy(void) const 
{ 
    RectUIDrawObjectPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const RectUIDrawObject *>(this)); 

    return returnValue; 
}

UInt32 RectUIDrawObjectBase::getContainerSize(void) const 
{ 
    return sizeof(RectUIDrawObject); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void RectUIDrawObjectBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl((RectUIDrawObjectBase *) &other, whichField);
}
#else
void RectUIDrawObjectBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((RectUIDrawObjectBase *) &other, whichField, sInfo);
}
void RectUIDrawObjectBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void RectUIDrawObjectBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

RectUIDrawObjectBase::RectUIDrawObjectBase(void) :
    _sfTopLeft                (Pnt2s(0,0)), 
    _sfBottomRight            (Pnt2s(0,0)), 
    _sfColor                  (Color4f(1.0,1.0,1.0,1.0)), 
    _sfOpacity                (Real32(1.0)), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

RectUIDrawObjectBase::RectUIDrawObjectBase(const RectUIDrawObjectBase &source) :
    _sfTopLeft                (source._sfTopLeft                ), 
    _sfBottomRight            (source._sfBottomRight            ), 
    _sfColor                  (source._sfColor                  ), 
    _sfOpacity                (source._sfOpacity                ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

RectUIDrawObjectBase::~RectUIDrawObjectBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 RectUIDrawObjectBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (TopLeftFieldMask & whichField))
    {
        returnValue += _sfTopLeft.getBinSize();
    }

    if(FieldBits::NoField != (BottomRightFieldMask & whichField))
    {
        returnValue += _sfBottomRight.getBinSize();
    }

    if(FieldBits::NoField != (ColorFieldMask & whichField))
    {
        returnValue += _sfColor.getBinSize();
    }

    if(FieldBits::NoField != (OpacityFieldMask & whichField))
    {
        returnValue += _sfOpacity.getBinSize();
    }


    return returnValue;
}

void RectUIDrawObjectBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (TopLeftFieldMask & whichField))
    {
        _sfTopLeft.copyToBin(pMem);
    }

    if(FieldBits::NoField != (BottomRightFieldMask & whichField))
    {
        _sfBottomRight.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ColorFieldMask & whichField))
    {
        _sfColor.copyToBin(pMem);
    }

    if(FieldBits::NoField != (OpacityFieldMask & whichField))
    {
        _sfOpacity.copyToBin(pMem);
    }


}

void RectUIDrawObjectBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (TopLeftFieldMask & whichField))
    {
        _sfTopLeft.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (BottomRightFieldMask & whichField))
    {
        _sfBottomRight.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ColorFieldMask & whichField))
    {
        _sfColor.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (OpacityFieldMask & whichField))
    {
        _sfOpacity.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void RectUIDrawObjectBase::executeSyncImpl(      RectUIDrawObjectBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (TopLeftFieldMask & whichField))
        _sfTopLeft.syncWith(pOther->_sfTopLeft);

    if(FieldBits::NoField != (BottomRightFieldMask & whichField))
        _sfBottomRight.syncWith(pOther->_sfBottomRight);

    if(FieldBits::NoField != (ColorFieldMask & whichField))
        _sfColor.syncWith(pOther->_sfColor);

    if(FieldBits::NoField != (OpacityFieldMask & whichField))
        _sfOpacity.syncWith(pOther->_sfOpacity);


}
#else
void RectUIDrawObjectBase::executeSyncImpl(      RectUIDrawObjectBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (TopLeftFieldMask & whichField))
        _sfTopLeft.syncWith(pOther->_sfTopLeft);

    if(FieldBits::NoField != (BottomRightFieldMask & whichField))
        _sfBottomRight.syncWith(pOther->_sfBottomRight);

    if(FieldBits::NoField != (ColorFieldMask & whichField))
        _sfColor.syncWith(pOther->_sfColor);

    if(FieldBits::NoField != (OpacityFieldMask & whichField))
        _sfOpacity.syncWith(pOther->_sfOpacity);



}

void RectUIDrawObjectBase::execBeginEditImpl (const BitVector &whichField, 
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
DataType FieldDataTraits<RectUIDrawObjectPtr>::_type("RectUIDrawObjectPtr", "UIDrawObjectPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(RectUIDrawObjectPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(RectUIDrawObjectPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);


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
    static Char8 cvsid_hpp       [] = OSGRECTUIDRAWOBJECTBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGRECTUIDRAWOBJECTBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGRECTUIDRAWOBJECTFIELDS_HEADER_CVSID;
}

OSG_END_NAMESPACE

