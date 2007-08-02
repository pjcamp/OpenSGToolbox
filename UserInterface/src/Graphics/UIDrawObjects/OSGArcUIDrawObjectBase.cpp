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
 **     class ArcUIDrawObject!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEARCUIDRAWOBJECTINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"
#include "OSGArcUIDrawObjectBase.h"
#include "OSGArcUIDrawObject.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  ArcUIDrawObjectBase::CenterFieldMask = 
    (TypeTraits<BitVector>::One << ArcUIDrawObjectBase::CenterFieldId);

const OSG::BitVector  ArcUIDrawObjectBase::WidthFieldMask = 
    (TypeTraits<BitVector>::One << ArcUIDrawObjectBase::WidthFieldId);

const OSG::BitVector  ArcUIDrawObjectBase::HeightFieldMask = 
    (TypeTraits<BitVector>::One << ArcUIDrawObjectBase::HeightFieldId);

const OSG::BitVector  ArcUIDrawObjectBase::StartAngleRadFieldMask = 
    (TypeTraits<BitVector>::One << ArcUIDrawObjectBase::StartAngleRadFieldId);

const OSG::BitVector  ArcUIDrawObjectBase::EndAngleRadFieldMask = 
    (TypeTraits<BitVector>::One << ArcUIDrawObjectBase::EndAngleRadFieldId);

const OSG::BitVector  ArcUIDrawObjectBase::SubDivisionsFieldMask = 
    (TypeTraits<BitVector>::One << ArcUIDrawObjectBase::SubDivisionsFieldId);

const OSG::BitVector  ArcUIDrawObjectBase::ColorFieldMask = 
    (TypeTraits<BitVector>::One << ArcUIDrawObjectBase::ColorFieldId);

const OSG::BitVector  ArcUIDrawObjectBase::LineWidthFieldMask = 
    (TypeTraits<BitVector>::One << ArcUIDrawObjectBase::LineWidthFieldId);

const OSG::BitVector  ArcUIDrawObjectBase::OpacityFieldMask = 
    (TypeTraits<BitVector>::One << ArcUIDrawObjectBase::OpacityFieldId);

const OSG::BitVector ArcUIDrawObjectBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var Pnt2s           ArcUIDrawObjectBase::_sfCenter
    
*/
/*! \var Int16           ArcUIDrawObjectBase::_sfWidth
    
*/
/*! \var Int16           ArcUIDrawObjectBase::_sfHeight
    
*/
/*! \var Real32          ArcUIDrawObjectBase::_sfStartAngleRad
    
*/
/*! \var Real32          ArcUIDrawObjectBase::_sfEndAngleRad
    
*/
/*! \var UInt16          ArcUIDrawObjectBase::_sfSubDivisions
    
*/
/*! \var Color4f         ArcUIDrawObjectBase::_sfColor
    
*/
/*! \var Real32          ArcUIDrawObjectBase::_sfLineWidth
    
*/
/*! \var Real32          ArcUIDrawObjectBase::_sfOpacity
    
*/

//! ArcUIDrawObject description

FieldDescription *ArcUIDrawObjectBase::_desc[] = 
{
    new FieldDescription(SFPnt2s::getClassType(), 
                     "Center", 
                     CenterFieldId, CenterFieldMask,
                     false,
                     (FieldAccessMethod) &ArcUIDrawObjectBase::getSFCenter),
    new FieldDescription(SFInt16::getClassType(), 
                     "Width", 
                     WidthFieldId, WidthFieldMask,
                     false,
                     (FieldAccessMethod) &ArcUIDrawObjectBase::getSFWidth),
    new FieldDescription(SFInt16::getClassType(), 
                     "Height", 
                     HeightFieldId, HeightFieldMask,
                     false,
                     (FieldAccessMethod) &ArcUIDrawObjectBase::getSFHeight),
    new FieldDescription(SFReal32::getClassType(), 
                     "StartAngleRad", 
                     StartAngleRadFieldId, StartAngleRadFieldMask,
                     false,
                     (FieldAccessMethod) &ArcUIDrawObjectBase::getSFStartAngleRad),
    new FieldDescription(SFReal32::getClassType(), 
                     "EndAngleRad", 
                     EndAngleRadFieldId, EndAngleRadFieldMask,
                     false,
                     (FieldAccessMethod) &ArcUIDrawObjectBase::getSFEndAngleRad),
    new FieldDescription(SFUInt16::getClassType(), 
                     "SubDivisions", 
                     SubDivisionsFieldId, SubDivisionsFieldMask,
                     false,
                     (FieldAccessMethod) &ArcUIDrawObjectBase::getSFSubDivisions),
    new FieldDescription(SFColor4f::getClassType(), 
                     "Color", 
                     ColorFieldId, ColorFieldMask,
                     false,
                     (FieldAccessMethod) &ArcUIDrawObjectBase::getSFColor),
    new FieldDescription(SFReal32::getClassType(), 
                     "LineWidth", 
                     LineWidthFieldId, LineWidthFieldMask,
                     false,
                     (FieldAccessMethod) &ArcUIDrawObjectBase::getSFLineWidth),
    new FieldDescription(SFReal32::getClassType(), 
                     "Opacity", 
                     OpacityFieldId, OpacityFieldMask,
                     false,
                     (FieldAccessMethod) &ArcUIDrawObjectBase::getSFOpacity)
};


FieldContainerType ArcUIDrawObjectBase::_type(
    "ArcUIDrawObject",
    "UIDrawObject",
    NULL,
    (PrototypeCreateF) &ArcUIDrawObjectBase::createEmpty,
    ArcUIDrawObject::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(ArcUIDrawObjectBase, ArcUIDrawObjectPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &ArcUIDrawObjectBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &ArcUIDrawObjectBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr ArcUIDrawObjectBase::shallowCopy(void) const 
{ 
    ArcUIDrawObjectPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const ArcUIDrawObject *>(this)); 

    return returnValue; 
}

UInt32 ArcUIDrawObjectBase::getContainerSize(void) const 
{ 
    return sizeof(ArcUIDrawObject); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void ArcUIDrawObjectBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl((ArcUIDrawObjectBase *) &other, whichField);
}
#else
void ArcUIDrawObjectBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((ArcUIDrawObjectBase *) &other, whichField, sInfo);
}
void ArcUIDrawObjectBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void ArcUIDrawObjectBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

ArcUIDrawObjectBase::ArcUIDrawObjectBase(void) :
    _sfCenter                 (Pnt2s(0,0)), 
    _sfWidth                  (Int16(1)), 
    _sfHeight                 (Int16(1)), 
    _sfStartAngleRad          (Real32(0.0)), 
    _sfEndAngleRad            (Real32(6.283185307)), 
    _sfSubDivisions           (UInt16(24)), 
    _sfColor                  (Color4f(1.0,1.0,1.0,1.0)), 
    _sfLineWidth              (Real32(1.0)), 
    _sfOpacity                (Real32(1.0)), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

ArcUIDrawObjectBase::ArcUIDrawObjectBase(const ArcUIDrawObjectBase &source) :
    _sfCenter                 (source._sfCenter                 ), 
    _sfWidth                  (source._sfWidth                  ), 
    _sfHeight                 (source._sfHeight                 ), 
    _sfStartAngleRad          (source._sfStartAngleRad          ), 
    _sfEndAngleRad            (source._sfEndAngleRad            ), 
    _sfSubDivisions           (source._sfSubDivisions           ), 
    _sfColor                  (source._sfColor                  ), 
    _sfLineWidth              (source._sfLineWidth              ), 
    _sfOpacity                (source._sfOpacity                ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

ArcUIDrawObjectBase::~ArcUIDrawObjectBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 ArcUIDrawObjectBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (CenterFieldMask & whichField))
    {
        returnValue += _sfCenter.getBinSize();
    }

    if(FieldBits::NoField != (WidthFieldMask & whichField))
    {
        returnValue += _sfWidth.getBinSize();
    }

    if(FieldBits::NoField != (HeightFieldMask & whichField))
    {
        returnValue += _sfHeight.getBinSize();
    }

    if(FieldBits::NoField != (StartAngleRadFieldMask & whichField))
    {
        returnValue += _sfStartAngleRad.getBinSize();
    }

    if(FieldBits::NoField != (EndAngleRadFieldMask & whichField))
    {
        returnValue += _sfEndAngleRad.getBinSize();
    }

    if(FieldBits::NoField != (SubDivisionsFieldMask & whichField))
    {
        returnValue += _sfSubDivisions.getBinSize();
    }

    if(FieldBits::NoField != (ColorFieldMask & whichField))
    {
        returnValue += _sfColor.getBinSize();
    }

    if(FieldBits::NoField != (LineWidthFieldMask & whichField))
    {
        returnValue += _sfLineWidth.getBinSize();
    }

    if(FieldBits::NoField != (OpacityFieldMask & whichField))
    {
        returnValue += _sfOpacity.getBinSize();
    }


    return returnValue;
}

void ArcUIDrawObjectBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (CenterFieldMask & whichField))
    {
        _sfCenter.copyToBin(pMem);
    }

    if(FieldBits::NoField != (WidthFieldMask & whichField))
    {
        _sfWidth.copyToBin(pMem);
    }

    if(FieldBits::NoField != (HeightFieldMask & whichField))
    {
        _sfHeight.copyToBin(pMem);
    }

    if(FieldBits::NoField != (StartAngleRadFieldMask & whichField))
    {
        _sfStartAngleRad.copyToBin(pMem);
    }

    if(FieldBits::NoField != (EndAngleRadFieldMask & whichField))
    {
        _sfEndAngleRad.copyToBin(pMem);
    }

    if(FieldBits::NoField != (SubDivisionsFieldMask & whichField))
    {
        _sfSubDivisions.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ColorFieldMask & whichField))
    {
        _sfColor.copyToBin(pMem);
    }

    if(FieldBits::NoField != (LineWidthFieldMask & whichField))
    {
        _sfLineWidth.copyToBin(pMem);
    }

    if(FieldBits::NoField != (OpacityFieldMask & whichField))
    {
        _sfOpacity.copyToBin(pMem);
    }


}

void ArcUIDrawObjectBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (CenterFieldMask & whichField))
    {
        _sfCenter.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (WidthFieldMask & whichField))
    {
        _sfWidth.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (HeightFieldMask & whichField))
    {
        _sfHeight.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (StartAngleRadFieldMask & whichField))
    {
        _sfStartAngleRad.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (EndAngleRadFieldMask & whichField))
    {
        _sfEndAngleRad.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (SubDivisionsFieldMask & whichField))
    {
        _sfSubDivisions.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ColorFieldMask & whichField))
    {
        _sfColor.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (LineWidthFieldMask & whichField))
    {
        _sfLineWidth.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (OpacityFieldMask & whichField))
    {
        _sfOpacity.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void ArcUIDrawObjectBase::executeSyncImpl(      ArcUIDrawObjectBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (CenterFieldMask & whichField))
        _sfCenter.syncWith(pOther->_sfCenter);

    if(FieldBits::NoField != (WidthFieldMask & whichField))
        _sfWidth.syncWith(pOther->_sfWidth);

    if(FieldBits::NoField != (HeightFieldMask & whichField))
        _sfHeight.syncWith(pOther->_sfHeight);

    if(FieldBits::NoField != (StartAngleRadFieldMask & whichField))
        _sfStartAngleRad.syncWith(pOther->_sfStartAngleRad);

    if(FieldBits::NoField != (EndAngleRadFieldMask & whichField))
        _sfEndAngleRad.syncWith(pOther->_sfEndAngleRad);

    if(FieldBits::NoField != (SubDivisionsFieldMask & whichField))
        _sfSubDivisions.syncWith(pOther->_sfSubDivisions);

    if(FieldBits::NoField != (ColorFieldMask & whichField))
        _sfColor.syncWith(pOther->_sfColor);

    if(FieldBits::NoField != (LineWidthFieldMask & whichField))
        _sfLineWidth.syncWith(pOther->_sfLineWidth);

    if(FieldBits::NoField != (OpacityFieldMask & whichField))
        _sfOpacity.syncWith(pOther->_sfOpacity);


}
#else
void ArcUIDrawObjectBase::executeSyncImpl(      ArcUIDrawObjectBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (CenterFieldMask & whichField))
        _sfCenter.syncWith(pOther->_sfCenter);

    if(FieldBits::NoField != (WidthFieldMask & whichField))
        _sfWidth.syncWith(pOther->_sfWidth);

    if(FieldBits::NoField != (HeightFieldMask & whichField))
        _sfHeight.syncWith(pOther->_sfHeight);

    if(FieldBits::NoField != (StartAngleRadFieldMask & whichField))
        _sfStartAngleRad.syncWith(pOther->_sfStartAngleRad);

    if(FieldBits::NoField != (EndAngleRadFieldMask & whichField))
        _sfEndAngleRad.syncWith(pOther->_sfEndAngleRad);

    if(FieldBits::NoField != (SubDivisionsFieldMask & whichField))
        _sfSubDivisions.syncWith(pOther->_sfSubDivisions);

    if(FieldBits::NoField != (ColorFieldMask & whichField))
        _sfColor.syncWith(pOther->_sfColor);

    if(FieldBits::NoField != (LineWidthFieldMask & whichField))
        _sfLineWidth.syncWith(pOther->_sfLineWidth);

    if(FieldBits::NoField != (OpacityFieldMask & whichField))
        _sfOpacity.syncWith(pOther->_sfOpacity);



}

void ArcUIDrawObjectBase::execBeginEditImpl (const BitVector &whichField, 
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
DataType FieldDataTraits<ArcUIDrawObjectPtr>::_type("ArcUIDrawObjectPtr", "UIDrawObjectPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(ArcUIDrawObjectPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(ArcUIDrawObjectPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);


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
    static Char8 cvsid_hpp       [] = OSGARCUIDRAWOBJECTBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGARCUIDRAWOBJECTBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGARCUIDRAWOBJECTFIELDS_HEADER_CVSID;
}

OSG_END_NAMESPACE

