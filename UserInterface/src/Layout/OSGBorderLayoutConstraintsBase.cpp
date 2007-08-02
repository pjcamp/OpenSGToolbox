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
 **     class BorderLayoutConstraints!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEBORDERLAYOUTCONSTRAINTSINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGBorderLayoutConstraintsBase.h"
#include "OSGBorderLayoutConstraints.h"

#include <Layout/OSGBorderLayoutConstraints.h>   // Region default header

OSG_BEGIN_NAMESPACE

const OSG::BitVector  BorderLayoutConstraintsBase::RegionFieldMask = 
    (TypeTraits<BitVector>::One << BorderLayoutConstraintsBase::RegionFieldId);

const OSG::BitVector BorderLayoutConstraintsBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var UInt32          BorderLayoutConstraintsBase::_sfRegion
    
*/

//! BorderLayoutConstraints description

FieldDescription *BorderLayoutConstraintsBase::_desc[] = 
{
    new FieldDescription(SFUInt32::getClassType(), 
                     "Region", 
                     RegionFieldId, RegionFieldMask,
                     false,
                     (FieldAccessMethod) &BorderLayoutConstraintsBase::getSFRegion)
};


FieldContainerType BorderLayoutConstraintsBase::_type(
    "BorderLayoutConstraints",
    "LayoutConstraints",
    NULL,
    (PrototypeCreateF) &BorderLayoutConstraintsBase::createEmpty,
    BorderLayoutConstraints::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(BorderLayoutConstraintsBase, BorderLayoutConstraintsPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &BorderLayoutConstraintsBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &BorderLayoutConstraintsBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr BorderLayoutConstraintsBase::shallowCopy(void) const 
{ 
    BorderLayoutConstraintsPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const BorderLayoutConstraints *>(this)); 

    return returnValue; 
}

UInt32 BorderLayoutConstraintsBase::getContainerSize(void) const 
{ 
    return sizeof(BorderLayoutConstraints); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void BorderLayoutConstraintsBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl((BorderLayoutConstraintsBase *) &other, whichField);
}
#else
void BorderLayoutConstraintsBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((BorderLayoutConstraintsBase *) &other, whichField, sInfo);
}
void BorderLayoutConstraintsBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void BorderLayoutConstraintsBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

BorderLayoutConstraintsBase::BorderLayoutConstraintsBase(void) :
    _sfRegion                 (UInt32(BorderLayoutConstraints::BORDER_CENTER)), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

BorderLayoutConstraintsBase::BorderLayoutConstraintsBase(const BorderLayoutConstraintsBase &source) :
    _sfRegion                 (source._sfRegion                 ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

BorderLayoutConstraintsBase::~BorderLayoutConstraintsBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 BorderLayoutConstraintsBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (RegionFieldMask & whichField))
    {
        returnValue += _sfRegion.getBinSize();
    }


    return returnValue;
}

void BorderLayoutConstraintsBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (RegionFieldMask & whichField))
    {
        _sfRegion.copyToBin(pMem);
    }


}

void BorderLayoutConstraintsBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (RegionFieldMask & whichField))
    {
        _sfRegion.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void BorderLayoutConstraintsBase::executeSyncImpl(      BorderLayoutConstraintsBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (RegionFieldMask & whichField))
        _sfRegion.syncWith(pOther->_sfRegion);


}
#else
void BorderLayoutConstraintsBase::executeSyncImpl(      BorderLayoutConstraintsBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (RegionFieldMask & whichField))
        _sfRegion.syncWith(pOther->_sfRegion);



}

void BorderLayoutConstraintsBase::execBeginEditImpl (const BitVector &whichField, 
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
DataType FieldDataTraits<BorderLayoutConstraintsPtr>::_type("BorderLayoutConstraintsPtr", "LayoutConstraintsPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(BorderLayoutConstraintsPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(BorderLayoutConstraintsPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);


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
    static Char8 cvsid_hpp       [] = OSGBORDERLAYOUTCONSTRAINTSBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGBORDERLAYOUTCONSTRAINTSBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGBORDERLAYOUTCONSTRAINTSFIELDS_HEADER_CVSID;
}

OSG_END_NAMESPACE

