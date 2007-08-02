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
 **     class ColorUIBackground!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILECOLORUIBACKGROUNDINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGColorUIBackgroundBase.h"
#include "OSGColorUIBackground.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  ColorUIBackgroundBase::ColorFieldMask = 
    (TypeTraits<BitVector>::One << ColorUIBackgroundBase::ColorFieldId);

const OSG::BitVector ColorUIBackgroundBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var Color4f         ColorUIBackgroundBase::_sfColor
    
*/

//! ColorUIBackground description

FieldDescription *ColorUIBackgroundBase::_desc[] = 
{
    new FieldDescription(SFColor4f::getClassType(), 
                     "Color", 
                     ColorFieldId, ColorFieldMask,
                     false,
                     (FieldAccessMethod) &ColorUIBackgroundBase::getSFColor)
};


FieldContainerType ColorUIBackgroundBase::_type(
    "ColorUIBackground",
    "UIBackground",
    NULL,
    (PrototypeCreateF) &ColorUIBackgroundBase::createEmpty,
    ColorUIBackground::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(ColorUIBackgroundBase, ColorUIBackgroundPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &ColorUIBackgroundBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &ColorUIBackgroundBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr ColorUIBackgroundBase::shallowCopy(void) const 
{ 
    ColorUIBackgroundPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const ColorUIBackground *>(this)); 

    return returnValue; 
}

UInt32 ColorUIBackgroundBase::getContainerSize(void) const 
{ 
    return sizeof(ColorUIBackground); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void ColorUIBackgroundBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl((ColorUIBackgroundBase *) &other, whichField);
}
#else
void ColorUIBackgroundBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((ColorUIBackgroundBase *) &other, whichField, sInfo);
}
void ColorUIBackgroundBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void ColorUIBackgroundBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

ColorUIBackgroundBase::ColorUIBackgroundBase(void) :
    _sfColor                  (Color4f(0.0,0.0,0.0,1.0)), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

ColorUIBackgroundBase::ColorUIBackgroundBase(const ColorUIBackgroundBase &source) :
    _sfColor                  (source._sfColor                  ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

ColorUIBackgroundBase::~ColorUIBackgroundBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 ColorUIBackgroundBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ColorFieldMask & whichField))
    {
        returnValue += _sfColor.getBinSize();
    }


    return returnValue;
}

void ColorUIBackgroundBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ColorFieldMask & whichField))
    {
        _sfColor.copyToBin(pMem);
    }


}

void ColorUIBackgroundBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ColorFieldMask & whichField))
    {
        _sfColor.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void ColorUIBackgroundBase::executeSyncImpl(      ColorUIBackgroundBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (ColorFieldMask & whichField))
        _sfColor.syncWith(pOther->_sfColor);


}
#else
void ColorUIBackgroundBase::executeSyncImpl(      ColorUIBackgroundBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (ColorFieldMask & whichField))
        _sfColor.syncWith(pOther->_sfColor);



}

void ColorUIBackgroundBase::execBeginEditImpl (const BitVector &whichField, 
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
DataType FieldDataTraits<ColorUIBackgroundPtr>::_type("ColorUIBackgroundPtr", "UIBackgroundPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(ColorUIBackgroundPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(ColorUIBackgroundPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);


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
    static Char8 cvsid_hpp       [] = OSGCOLORUIBACKGROUNDBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGCOLORUIBACKGROUNDBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGCOLORUIBACKGROUNDFIELDS_HEADER_CVSID;
}

OSG_END_NAMESPACE

