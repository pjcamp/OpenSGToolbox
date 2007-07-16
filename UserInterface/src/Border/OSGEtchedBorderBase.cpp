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
 **     class EtchedBorder!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEETCHEDBORDERINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGEtchedBorderBase.h"
#include "OSGEtchedBorder.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  EtchedBorderBase::HighlightFieldMask = 
    (TypeTraits<BitVector>::One << EtchedBorderBase::HighlightFieldId);

const OSG::BitVector  EtchedBorderBase::ShadowFieldMask = 
    (TypeTraits<BitVector>::One << EtchedBorderBase::ShadowFieldId);

const OSG::BitVector  EtchedBorderBase::RaisedFieldMask = 
    (TypeTraits<BitVector>::One << EtchedBorderBase::RaisedFieldId);

const OSG::BitVector  EtchedBorderBase::WidthFieldMask = 
    (TypeTraits<BitVector>::One << EtchedBorderBase::WidthFieldId);

const OSG::BitVector EtchedBorderBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var Color4f         EtchedBorderBase::_sfHighlight
    
*/
/*! \var Color4f         EtchedBorderBase::_sfShadow
    
*/
/*! \var bool            EtchedBorderBase::_sfRaised
    
*/
/*! \var UInt32          EtchedBorderBase::_sfWidth
    
*/

//! EtchedBorder description

FieldDescription *EtchedBorderBase::_desc[] = 
{
    new FieldDescription(SFColor4f::getClassType(), 
                     "Highlight", 
                     HighlightFieldId, HighlightFieldMask,
                     false,
                     (FieldAccessMethod) &EtchedBorderBase::getSFHighlight),
    new FieldDescription(SFColor4f::getClassType(), 
                     "Shadow", 
                     ShadowFieldId, ShadowFieldMask,
                     false,
                     (FieldAccessMethod) &EtchedBorderBase::getSFShadow),
    new FieldDescription(SFBool::getClassType(), 
                     "Raised", 
                     RaisedFieldId, RaisedFieldMask,
                     false,
                     (FieldAccessMethod) &EtchedBorderBase::getSFRaised),
    new FieldDescription(SFUInt32::getClassType(), 
                     "Width", 
                     WidthFieldId, WidthFieldMask,
                     false,
                     (FieldAccessMethod) &EtchedBorderBase::getSFWidth)
};


FieldContainerType EtchedBorderBase::_type(
    "EtchedBorder",
    "Border",
    NULL,
    (PrototypeCreateF) &EtchedBorderBase::createEmpty,
    EtchedBorder::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(EtchedBorderBase, EtchedBorderPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &EtchedBorderBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &EtchedBorderBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr EtchedBorderBase::shallowCopy(void) const 
{ 
    EtchedBorderPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const EtchedBorder *>(this)); 

    return returnValue; 
}

UInt32 EtchedBorderBase::getContainerSize(void) const 
{ 
    return sizeof(EtchedBorder); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void EtchedBorderBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl((EtchedBorderBase *) &other, whichField);
}
#else
void EtchedBorderBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((EtchedBorderBase *) &other, whichField, sInfo);
}
void EtchedBorderBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void EtchedBorderBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

EtchedBorderBase::EtchedBorderBase(void) :
    _sfHighlight              (), 
    _sfShadow                 (), 
    _sfRaised                 (bool(true)), 
    _sfWidth                  (UInt32(1)), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

EtchedBorderBase::EtchedBorderBase(const EtchedBorderBase &source) :
    _sfHighlight              (source._sfHighlight              ), 
    _sfShadow                 (source._sfShadow                 ), 
    _sfRaised                 (source._sfRaised                 ), 
    _sfWidth                  (source._sfWidth                  ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

EtchedBorderBase::~EtchedBorderBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 EtchedBorderBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (HighlightFieldMask & whichField))
    {
        returnValue += _sfHighlight.getBinSize();
    }

    if(FieldBits::NoField != (ShadowFieldMask & whichField))
    {
        returnValue += _sfShadow.getBinSize();
    }

    if(FieldBits::NoField != (RaisedFieldMask & whichField))
    {
        returnValue += _sfRaised.getBinSize();
    }

    if(FieldBits::NoField != (WidthFieldMask & whichField))
    {
        returnValue += _sfWidth.getBinSize();
    }


    return returnValue;
}

void EtchedBorderBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (HighlightFieldMask & whichField))
    {
        _sfHighlight.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ShadowFieldMask & whichField))
    {
        _sfShadow.copyToBin(pMem);
    }

    if(FieldBits::NoField != (RaisedFieldMask & whichField))
    {
        _sfRaised.copyToBin(pMem);
    }

    if(FieldBits::NoField != (WidthFieldMask & whichField))
    {
        _sfWidth.copyToBin(pMem);
    }


}

void EtchedBorderBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (HighlightFieldMask & whichField))
    {
        _sfHighlight.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ShadowFieldMask & whichField))
    {
        _sfShadow.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (RaisedFieldMask & whichField))
    {
        _sfRaised.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (WidthFieldMask & whichField))
    {
        _sfWidth.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void EtchedBorderBase::executeSyncImpl(      EtchedBorderBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (HighlightFieldMask & whichField))
        _sfHighlight.syncWith(pOther->_sfHighlight);

    if(FieldBits::NoField != (ShadowFieldMask & whichField))
        _sfShadow.syncWith(pOther->_sfShadow);

    if(FieldBits::NoField != (RaisedFieldMask & whichField))
        _sfRaised.syncWith(pOther->_sfRaised);

    if(FieldBits::NoField != (WidthFieldMask & whichField))
        _sfWidth.syncWith(pOther->_sfWidth);


}
#else
void EtchedBorderBase::executeSyncImpl(      EtchedBorderBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (HighlightFieldMask & whichField))
        _sfHighlight.syncWith(pOther->_sfHighlight);

    if(FieldBits::NoField != (ShadowFieldMask & whichField))
        _sfShadow.syncWith(pOther->_sfShadow);

    if(FieldBits::NoField != (RaisedFieldMask & whichField))
        _sfRaised.syncWith(pOther->_sfRaised);

    if(FieldBits::NoField != (WidthFieldMask & whichField))
        _sfWidth.syncWith(pOther->_sfWidth);



}

void EtchedBorderBase::execBeginEditImpl (const BitVector &whichField, 
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
DataType FieldDataTraits<EtchedBorderPtr>::_type("EtchedBorderPtr", "BorderPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(EtchedBorderPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(EtchedBorderPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);


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
    static Char8 cvsid_hpp       [] = OSGETCHEDBORDERBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGETCHEDBORDERBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGETCHEDBORDERFIELDS_HEADER_CVSID;
}

OSG_END_NAMESPACE

