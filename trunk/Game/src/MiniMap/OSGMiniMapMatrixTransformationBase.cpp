/*---------------------------------------------------------------------------*\
 *                        OpenSG ToolBox Game                                *
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
 **     class MiniMapMatrixTransformation!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEMINIMAPMATRIXTRANSFORMATIONINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGMiniMapMatrixTransformationBase.h"
#include "OSGMiniMapMatrixTransformation.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  MiniMapMatrixTransformationBase::TransformationFieldMask = 
    (TypeTraits<BitVector>::One << MiniMapMatrixTransformationBase::TransformationFieldId);

const OSG::BitVector MiniMapMatrixTransformationBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var Matrix          MiniMapMatrixTransformationBase::_sfTransformation
    
*/

//! MiniMapMatrixTransformation description

FieldDescription *MiniMapMatrixTransformationBase::_desc[] = 
{
    new FieldDescription(SFMatrix::getClassType(), 
                     "Transformation", 
                     TransformationFieldId, TransformationFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&MiniMapMatrixTransformationBase::editSFTransformation))
};


FieldContainerType MiniMapMatrixTransformationBase::_type(
    "MiniMapMatrixTransformation",
    "MiniMapTransformation",
    NULL,
    reinterpret_cast<PrototypeCreateF>(&MiniMapMatrixTransformationBase::createEmpty),
    MiniMapMatrixTransformation::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(MiniMapMatrixTransformationBase, MiniMapMatrixTransformationPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &MiniMapMatrixTransformationBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &MiniMapMatrixTransformationBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr MiniMapMatrixTransformationBase::shallowCopy(void) const 
{ 
    MiniMapMatrixTransformationPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const MiniMapMatrixTransformation *>(this)); 

    return returnValue; 
}

UInt32 MiniMapMatrixTransformationBase::getContainerSize(void) const 
{ 
    return sizeof(MiniMapMatrixTransformation); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void MiniMapMatrixTransformationBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl(static_cast<MiniMapMatrixTransformationBase *>(&other),
                          whichField);
}
#else
void MiniMapMatrixTransformationBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((MiniMapMatrixTransformationBase *) &other, whichField, sInfo);
}
void MiniMapMatrixTransformationBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void MiniMapMatrixTransformationBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

MiniMapMatrixTransformationBase::MiniMapMatrixTransformationBase(void) :
    _sfTransformation         (), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

MiniMapMatrixTransformationBase::MiniMapMatrixTransformationBase(const MiniMapMatrixTransformationBase &source) :
    _sfTransformation         (source._sfTransformation         ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

MiniMapMatrixTransformationBase::~MiniMapMatrixTransformationBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 MiniMapMatrixTransformationBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (TransformationFieldMask & whichField))
    {
        returnValue += _sfTransformation.getBinSize();
    }


    return returnValue;
}

void MiniMapMatrixTransformationBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (TransformationFieldMask & whichField))
    {
        _sfTransformation.copyToBin(pMem);
    }


}

void MiniMapMatrixTransformationBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (TransformationFieldMask & whichField))
    {
        _sfTransformation.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void MiniMapMatrixTransformationBase::executeSyncImpl(      MiniMapMatrixTransformationBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (TransformationFieldMask & whichField))
        _sfTransformation.syncWith(pOther->_sfTransformation);


}
#else
void MiniMapMatrixTransformationBase::executeSyncImpl(      MiniMapMatrixTransformationBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (TransformationFieldMask & whichField))
        _sfTransformation.syncWith(pOther->_sfTransformation);



}

void MiniMapMatrixTransformationBase::execBeginEditImpl (const BitVector &whichField, 
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
DataType FieldDataTraits<MiniMapMatrixTransformationPtr>::_type("MiniMapMatrixTransformationPtr", "MiniMapTransformationPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(MiniMapMatrixTransformationPtr, OSG_GAMELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(MiniMapMatrixTransformationPtr, OSG_GAMELIB_DLLTMPLMAPPING);


OSG_END_NAMESPACE

