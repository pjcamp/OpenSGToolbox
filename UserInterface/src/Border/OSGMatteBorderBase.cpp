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
 **     class MatteBorder!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEMATTEBORDERINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGMatteBorderBase.h"
#include "OSGMatteBorder.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  MatteBorderBase::LeftWidthFieldMask = 
    (TypeTraits<BitVector>::One << MatteBorderBase::LeftWidthFieldId);

const OSG::BitVector  MatteBorderBase::RightWidthFieldMask = 
    (TypeTraits<BitVector>::One << MatteBorderBase::RightWidthFieldId);

const OSG::BitVector  MatteBorderBase::TopWidthFieldMask = 
    (TypeTraits<BitVector>::One << MatteBorderBase::TopWidthFieldId);

const OSG::BitVector  MatteBorderBase::BottomWidthFieldMask = 
    (TypeTraits<BitVector>::One << MatteBorderBase::BottomWidthFieldId);

const OSG::BitVector  MatteBorderBase::ColorFieldMask = 
    (TypeTraits<BitVector>::One << MatteBorderBase::ColorFieldId);

const OSG::BitVector  MatteBorderBase::MaterialFieldMask = 
    (TypeTraits<BitVector>::One << MatteBorderBase::MaterialFieldId);

const OSG::BitVector MatteBorderBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var UInt32          MatteBorderBase::_sfLeftWidth
    
*/
/*! \var UInt32          MatteBorderBase::_sfRightWidth
    
*/
/*! \var UInt32          MatteBorderBase::_sfTopWidth
    
*/
/*! \var UInt32          MatteBorderBase::_sfBottomWidth
    
*/
/*! \var Color4f         MatteBorderBase::_sfColor
    
*/
/*! \var MaterialPtr     MatteBorderBase::_sfMaterial
    
*/

//! MatteBorder description

FieldDescription *MatteBorderBase::_desc[] = 
{
    new FieldDescription(SFUInt32::getClassType(), 
                     "LeftWidth", 
                     LeftWidthFieldId, LeftWidthFieldMask,
                     false,
                     (FieldAccessMethod) &MatteBorderBase::getSFLeftWidth),
    new FieldDescription(SFUInt32::getClassType(), 
                     "RightWidth", 
                     RightWidthFieldId, RightWidthFieldMask,
                     false,
                     (FieldAccessMethod) &MatteBorderBase::getSFRightWidth),
    new FieldDescription(SFUInt32::getClassType(), 
                     "TopWidth", 
                     TopWidthFieldId, TopWidthFieldMask,
                     false,
                     (FieldAccessMethod) &MatteBorderBase::getSFTopWidth),
    new FieldDescription(SFUInt32::getClassType(), 
                     "BottomWidth", 
                     BottomWidthFieldId, BottomWidthFieldMask,
                     false,
                     (FieldAccessMethod) &MatteBorderBase::getSFBottomWidth),
    new FieldDescription(SFColor4f::getClassType(), 
                     "Color", 
                     ColorFieldId, ColorFieldMask,
                     false,
                     (FieldAccessMethod) &MatteBorderBase::getSFColor),
    new FieldDescription(SFMaterialPtr::getClassType(), 
                     "Material", 
                     MaterialFieldId, MaterialFieldMask,
                     false,
                     (FieldAccessMethod) &MatteBorderBase::getSFMaterial)
};


FieldContainerType MatteBorderBase::_type(
    "MatteBorder",
    "Border",
    NULL,
    (PrototypeCreateF) &MatteBorderBase::createEmpty,
    MatteBorder::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(MatteBorderBase, MatteBorderPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &MatteBorderBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &MatteBorderBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr MatteBorderBase::shallowCopy(void) const 
{ 
    MatteBorderPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const MatteBorder *>(this)); 

    return returnValue; 
}

UInt32 MatteBorderBase::getContainerSize(void) const 
{ 
    return sizeof(MatteBorder); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void MatteBorderBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl((MatteBorderBase *) &other, whichField);
}
#else
void MatteBorderBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((MatteBorderBase *) &other, whichField, sInfo);
}
void MatteBorderBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void MatteBorderBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

MatteBorderBase::MatteBorderBase(void) :
    _sfLeftWidth              (UInt32(1)), 
    _sfRightWidth             (UInt32(1)), 
    _sfTopWidth               (UInt32(1)), 
    _sfBottomWidth            (UInt32(1)), 
    _sfColor                  (Color4f(0.0,0.0,0.0,1.0)), 
    _sfMaterial               (), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

MatteBorderBase::MatteBorderBase(const MatteBorderBase &source) :
    _sfLeftWidth              (source._sfLeftWidth              ), 
    _sfRightWidth             (source._sfRightWidth             ), 
    _sfTopWidth               (source._sfTopWidth               ), 
    _sfBottomWidth            (source._sfBottomWidth            ), 
    _sfColor                  (source._sfColor                  ), 
    _sfMaterial               (source._sfMaterial               ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

MatteBorderBase::~MatteBorderBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 MatteBorderBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (LeftWidthFieldMask & whichField))
    {
        returnValue += _sfLeftWidth.getBinSize();
    }

    if(FieldBits::NoField != (RightWidthFieldMask & whichField))
    {
        returnValue += _sfRightWidth.getBinSize();
    }

    if(FieldBits::NoField != (TopWidthFieldMask & whichField))
    {
        returnValue += _sfTopWidth.getBinSize();
    }

    if(FieldBits::NoField != (BottomWidthFieldMask & whichField))
    {
        returnValue += _sfBottomWidth.getBinSize();
    }

    if(FieldBits::NoField != (ColorFieldMask & whichField))
    {
        returnValue += _sfColor.getBinSize();
    }

    if(FieldBits::NoField != (MaterialFieldMask & whichField))
    {
        returnValue += _sfMaterial.getBinSize();
    }


    return returnValue;
}

void MatteBorderBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (LeftWidthFieldMask & whichField))
    {
        _sfLeftWidth.copyToBin(pMem);
    }

    if(FieldBits::NoField != (RightWidthFieldMask & whichField))
    {
        _sfRightWidth.copyToBin(pMem);
    }

    if(FieldBits::NoField != (TopWidthFieldMask & whichField))
    {
        _sfTopWidth.copyToBin(pMem);
    }

    if(FieldBits::NoField != (BottomWidthFieldMask & whichField))
    {
        _sfBottomWidth.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ColorFieldMask & whichField))
    {
        _sfColor.copyToBin(pMem);
    }

    if(FieldBits::NoField != (MaterialFieldMask & whichField))
    {
        _sfMaterial.copyToBin(pMem);
    }


}

void MatteBorderBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (LeftWidthFieldMask & whichField))
    {
        _sfLeftWidth.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (RightWidthFieldMask & whichField))
    {
        _sfRightWidth.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (TopWidthFieldMask & whichField))
    {
        _sfTopWidth.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (BottomWidthFieldMask & whichField))
    {
        _sfBottomWidth.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ColorFieldMask & whichField))
    {
        _sfColor.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (MaterialFieldMask & whichField))
    {
        _sfMaterial.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void MatteBorderBase::executeSyncImpl(      MatteBorderBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (LeftWidthFieldMask & whichField))
        _sfLeftWidth.syncWith(pOther->_sfLeftWidth);

    if(FieldBits::NoField != (RightWidthFieldMask & whichField))
        _sfRightWidth.syncWith(pOther->_sfRightWidth);

    if(FieldBits::NoField != (TopWidthFieldMask & whichField))
        _sfTopWidth.syncWith(pOther->_sfTopWidth);

    if(FieldBits::NoField != (BottomWidthFieldMask & whichField))
        _sfBottomWidth.syncWith(pOther->_sfBottomWidth);

    if(FieldBits::NoField != (ColorFieldMask & whichField))
        _sfColor.syncWith(pOther->_sfColor);

    if(FieldBits::NoField != (MaterialFieldMask & whichField))
        _sfMaterial.syncWith(pOther->_sfMaterial);


}
#else
void MatteBorderBase::executeSyncImpl(      MatteBorderBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (LeftWidthFieldMask & whichField))
        _sfLeftWidth.syncWith(pOther->_sfLeftWidth);

    if(FieldBits::NoField != (RightWidthFieldMask & whichField))
        _sfRightWidth.syncWith(pOther->_sfRightWidth);

    if(FieldBits::NoField != (TopWidthFieldMask & whichField))
        _sfTopWidth.syncWith(pOther->_sfTopWidth);

    if(FieldBits::NoField != (BottomWidthFieldMask & whichField))
        _sfBottomWidth.syncWith(pOther->_sfBottomWidth);

    if(FieldBits::NoField != (ColorFieldMask & whichField))
        _sfColor.syncWith(pOther->_sfColor);

    if(FieldBits::NoField != (MaterialFieldMask & whichField))
        _sfMaterial.syncWith(pOther->_sfMaterial);



}

void MatteBorderBase::execBeginEditImpl (const BitVector &whichField, 
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
DataType FieldDataTraits<MatteBorderPtr>::_type("MatteBorderPtr", "BorderPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(MatteBorderPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(MatteBorderPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);


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
    static Char8 cvsid_hpp       [] = OSGMATTEBORDERBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGMATTEBORDERBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGMATTEBORDERFIELDS_HEADER_CVSID;
}

OSG_END_NAMESPACE

