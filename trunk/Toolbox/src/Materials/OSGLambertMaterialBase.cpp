/*---------------------------------------------------------------------------*\
 *                        OpenSG ToolBox Toolbox                             *
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
 **     class LambertMaterial!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILELAMBERTMATERIALINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGLambertMaterialBase.h"
#include "OSGLambertMaterial.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  LambertMaterialBase::ColorFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::ColorFieldId);

const OSG::BitVector  LambertMaterialBase::ColorImageFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::ColorImageFieldId);

const OSG::BitVector  LambertMaterialBase::TransparencyFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::TransparencyFieldId);

const OSG::BitVector  LambertMaterialBase::TransparencyImageFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::TransparencyImageFieldId);

const OSG::BitVector  LambertMaterialBase::AmbientColorFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::AmbientColorFieldId);

const OSG::BitVector  LambertMaterialBase::AmbientColorImageFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::AmbientColorImageFieldId);

const OSG::BitVector  LambertMaterialBase::IncandescenceFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::IncandescenceFieldId);

const OSG::BitVector  LambertMaterialBase::IncandescenceImageFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::IncandescenceImageFieldId);

const OSG::BitVector  LambertMaterialBase::NormalMapImageFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::NormalMapImageFieldId);

const OSG::BitVector  LambertMaterialBase::BumpDepthFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::BumpDepthFieldId);

const OSG::BitVector  LambertMaterialBase::BumpDepthImageFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::BumpDepthImageFieldId);

const OSG::BitVector  LambertMaterialBase::DiffuseFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::DiffuseFieldId);

const OSG::BitVector  LambertMaterialBase::DiffuseImageFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::DiffuseImageFieldId);

const OSG::BitVector  LambertMaterialBase::TransleucenceFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::TransleucenceFieldId);

const OSG::BitVector  LambertMaterialBase::TransleucenceImageFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::TransleucenceImageFieldId);

const OSG::BitVector  LambertMaterialBase::TransleucenceDepthFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::TransleucenceDepthFieldId);

const OSG::BitVector  LambertMaterialBase::TransleucenceDepthImageFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::TransleucenceDepthImageFieldId);

const OSG::BitVector  LambertMaterialBase::TransleucenceFocusFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::TransleucenceFocusFieldId);

const OSG::BitVector  LambertMaterialBase::TransleucenceFocusImageFieldMask = 
    (TypeTraits<BitVector>::One << LambertMaterialBase::TransleucenceFocusImageFieldId);

const OSG::BitVector LambertMaterialBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var Color3f         LambertMaterialBase::_sfColor
    
*/
/*! \var ImagePtr        LambertMaterialBase::_sfColorImage
    
*/
/*! \var Color3f         LambertMaterialBase::_sfTransparency
    
*/
/*! \var ImagePtr        LambertMaterialBase::_sfTransparencyImage
    
*/
/*! \var Color3f         LambertMaterialBase::_sfAmbientColor
    
*/
/*! \var ImagePtr        LambertMaterialBase::_sfAmbientColorImage
    
*/
/*! \var Color3f         LambertMaterialBase::_sfIncandescence
    
*/
/*! \var ImagePtr        LambertMaterialBase::_sfIncandescenceImage
    
*/
/*! \var ImagePtr        LambertMaterialBase::_sfNormalMapImage
    
*/
/*! \var Real32          LambertMaterialBase::_sfBumpDepth
    
*/
/*! \var ImagePtr        LambertMaterialBase::_sfBumpDepthImage
    
*/
/*! \var Real32          LambertMaterialBase::_sfDiffuse
    
*/
/*! \var ImagePtr        LambertMaterialBase::_sfDiffuseImage
    
*/
/*! \var Real32          LambertMaterialBase::_sfTransleucence
    
*/
/*! \var ImagePtr        LambertMaterialBase::_sfTransleucenceImage
    
*/
/*! \var Real32          LambertMaterialBase::_sfTransleucenceDepth
    
*/
/*! \var ImagePtr        LambertMaterialBase::_sfTransleucenceDepthImage
    
*/
/*! \var Real32          LambertMaterialBase::_sfTransleucenceFocus
    
*/
/*! \var ImagePtr        LambertMaterialBase::_sfTransleucenceFocusImage
    
*/

//! LambertMaterial description

FieldDescription *LambertMaterialBase::_desc[] = 
{
    new FieldDescription(SFColor3f::getClassType(), 
                     "Color", 
                     ColorFieldId, ColorFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFColor)),
    new FieldDescription(SFImagePtr::getClassType(), 
                     "ColorImage", 
                     ColorImageFieldId, ColorImageFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFColorImage)),
    new FieldDescription(SFColor3f::getClassType(), 
                     "Transparency", 
                     TransparencyFieldId, TransparencyFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFTransparency)),
    new FieldDescription(SFImagePtr::getClassType(), 
                     "TransparencyImage", 
                     TransparencyImageFieldId, TransparencyImageFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFTransparencyImage)),
    new FieldDescription(SFColor3f::getClassType(), 
                     "AmbientColor", 
                     AmbientColorFieldId, AmbientColorFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFAmbientColor)),
    new FieldDescription(SFImagePtr::getClassType(), 
                     "AmbientColorImage", 
                     AmbientColorImageFieldId, AmbientColorImageFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFAmbientColorImage)),
    new FieldDescription(SFColor3f::getClassType(), 
                     "Incandescence", 
                     IncandescenceFieldId, IncandescenceFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFIncandescence)),
    new FieldDescription(SFImagePtr::getClassType(), 
                     "IncandescenceImage", 
                     IncandescenceImageFieldId, IncandescenceImageFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFIncandescenceImage)),
    new FieldDescription(SFImagePtr::getClassType(), 
                     "NormalMapImage", 
                     NormalMapImageFieldId, NormalMapImageFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFNormalMapImage)),
    new FieldDescription(SFReal32::getClassType(), 
                     "BumpDepth", 
                     BumpDepthFieldId, BumpDepthFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFBumpDepth)),
    new FieldDescription(SFImagePtr::getClassType(), 
                     "BumpDepthImage", 
                     BumpDepthImageFieldId, BumpDepthImageFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFBumpDepthImage)),
    new FieldDescription(SFReal32::getClassType(), 
                     "Diffuse", 
                     DiffuseFieldId, DiffuseFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFDiffuse)),
    new FieldDescription(SFImagePtr::getClassType(), 
                     "DiffuseImage", 
                     DiffuseImageFieldId, DiffuseImageFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFDiffuseImage)),
    new FieldDescription(SFReal32::getClassType(), 
                     "Transleucence", 
                     TransleucenceFieldId, TransleucenceFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFTransleucence)),
    new FieldDescription(SFImagePtr::getClassType(), 
                     "TransleucenceImage", 
                     TransleucenceImageFieldId, TransleucenceImageFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFTransleucenceImage)),
    new FieldDescription(SFReal32::getClassType(), 
                     "TransleucenceDepth", 
                     TransleucenceDepthFieldId, TransleucenceDepthFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFTransleucenceDepth)),
    new FieldDescription(SFImagePtr::getClassType(), 
                     "TransleucenceDepthImage", 
                     TransleucenceDepthImageFieldId, TransleucenceDepthImageFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFTransleucenceDepthImage)),
    new FieldDescription(SFReal32::getClassType(), 
                     "TransleucenceFocus", 
                     TransleucenceFocusFieldId, TransleucenceFocusFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFTransleucenceFocus)),
    new FieldDescription(SFImagePtr::getClassType(), 
                     "TransleucenceFocusImage", 
                     TransleucenceFocusImageFieldId, TransleucenceFocusImageFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&LambertMaterialBase::editSFTransleucenceFocusImage))
};


FieldContainerType LambertMaterialBase::_type(
    "LambertMaterial",
    "ChunkMaterial",
    NULL,
    reinterpret_cast<PrototypeCreateF>(&LambertMaterialBase::createEmpty),
    LambertMaterial::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(LambertMaterialBase, LambertMaterialPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &LambertMaterialBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &LambertMaterialBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr LambertMaterialBase::shallowCopy(void) const 
{ 
    LambertMaterialPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const LambertMaterial *>(this)); 

    return returnValue; 
}

UInt32 LambertMaterialBase::getContainerSize(void) const 
{ 
    return sizeof(LambertMaterial); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void LambertMaterialBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl(static_cast<LambertMaterialBase *>(&other),
                          whichField);
}
#else
void LambertMaterialBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((LambertMaterialBase *) &other, whichField, sInfo);
}
void LambertMaterialBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void LambertMaterialBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

LambertMaterialBase::LambertMaterialBase(void) :
    _sfColor                  (), 
    _sfColorImage             (ImagePtr(NullFC)), 
    _sfTransparency           (), 
    _sfTransparencyImage      (ImagePtr(NullFC)), 
    _sfAmbientColor           (), 
    _sfAmbientColorImage      (ImagePtr(NullFC)), 
    _sfIncandescence          (), 
    _sfIncandescenceImage     (ImagePtr(NullFC)), 
    _sfNormalMapImage         (ImagePtr(NullFC)), 
    _sfBumpDepth              (), 
    _sfBumpDepthImage         (ImagePtr(NullFC)), 
    _sfDiffuse                (), 
    _sfDiffuseImage           (ImagePtr(NullFC)), 
    _sfTransleucence          (), 
    _sfTransleucenceImage     (ImagePtr(NullFC)), 
    _sfTransleucenceDepth     (), 
    _sfTransleucenceDepthImage(ImagePtr(NullFC)), 
    _sfTransleucenceFocus     (), 
    _sfTransleucenceFocusImage(ImagePtr(NullFC)), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

LambertMaterialBase::LambertMaterialBase(const LambertMaterialBase &source) :
    _sfColor                  (source._sfColor                  ), 
    _sfColorImage             (source._sfColorImage             ), 
    _sfTransparency           (source._sfTransparency           ), 
    _sfTransparencyImage      (source._sfTransparencyImage      ), 
    _sfAmbientColor           (source._sfAmbientColor           ), 
    _sfAmbientColorImage      (source._sfAmbientColorImage      ), 
    _sfIncandescence          (source._sfIncandescence          ), 
    _sfIncandescenceImage     (source._sfIncandescenceImage     ), 
    _sfNormalMapImage         (source._sfNormalMapImage         ), 
    _sfBumpDepth              (source._sfBumpDepth              ), 
    _sfBumpDepthImage         (source._sfBumpDepthImage         ), 
    _sfDiffuse                (source._sfDiffuse                ), 
    _sfDiffuseImage           (source._sfDiffuseImage           ), 
    _sfTransleucence          (source._sfTransleucence          ), 
    _sfTransleucenceImage     (source._sfTransleucenceImage     ), 
    _sfTransleucenceDepth     (source._sfTransleucenceDepth     ), 
    _sfTransleucenceDepthImage(source._sfTransleucenceDepthImage), 
    _sfTransleucenceFocus     (source._sfTransleucenceFocus     ), 
    _sfTransleucenceFocusImage(source._sfTransleucenceFocusImage), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

LambertMaterialBase::~LambertMaterialBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 LambertMaterialBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ColorFieldMask & whichField))
    {
        returnValue += _sfColor.getBinSize();
    }

    if(FieldBits::NoField != (ColorImageFieldMask & whichField))
    {
        returnValue += _sfColorImage.getBinSize();
    }

    if(FieldBits::NoField != (TransparencyFieldMask & whichField))
    {
        returnValue += _sfTransparency.getBinSize();
    }

    if(FieldBits::NoField != (TransparencyImageFieldMask & whichField))
    {
        returnValue += _sfTransparencyImage.getBinSize();
    }

    if(FieldBits::NoField != (AmbientColorFieldMask & whichField))
    {
        returnValue += _sfAmbientColor.getBinSize();
    }

    if(FieldBits::NoField != (AmbientColorImageFieldMask & whichField))
    {
        returnValue += _sfAmbientColorImage.getBinSize();
    }

    if(FieldBits::NoField != (IncandescenceFieldMask & whichField))
    {
        returnValue += _sfIncandescence.getBinSize();
    }

    if(FieldBits::NoField != (IncandescenceImageFieldMask & whichField))
    {
        returnValue += _sfIncandescenceImage.getBinSize();
    }

    if(FieldBits::NoField != (NormalMapImageFieldMask & whichField))
    {
        returnValue += _sfNormalMapImage.getBinSize();
    }

    if(FieldBits::NoField != (BumpDepthFieldMask & whichField))
    {
        returnValue += _sfBumpDepth.getBinSize();
    }

    if(FieldBits::NoField != (BumpDepthImageFieldMask & whichField))
    {
        returnValue += _sfBumpDepthImage.getBinSize();
    }

    if(FieldBits::NoField != (DiffuseFieldMask & whichField))
    {
        returnValue += _sfDiffuse.getBinSize();
    }

    if(FieldBits::NoField != (DiffuseImageFieldMask & whichField))
    {
        returnValue += _sfDiffuseImage.getBinSize();
    }

    if(FieldBits::NoField != (TransleucenceFieldMask & whichField))
    {
        returnValue += _sfTransleucence.getBinSize();
    }

    if(FieldBits::NoField != (TransleucenceImageFieldMask & whichField))
    {
        returnValue += _sfTransleucenceImage.getBinSize();
    }

    if(FieldBits::NoField != (TransleucenceDepthFieldMask & whichField))
    {
        returnValue += _sfTransleucenceDepth.getBinSize();
    }

    if(FieldBits::NoField != (TransleucenceDepthImageFieldMask & whichField))
    {
        returnValue += _sfTransleucenceDepthImage.getBinSize();
    }

    if(FieldBits::NoField != (TransleucenceFocusFieldMask & whichField))
    {
        returnValue += _sfTransleucenceFocus.getBinSize();
    }

    if(FieldBits::NoField != (TransleucenceFocusImageFieldMask & whichField))
    {
        returnValue += _sfTransleucenceFocusImage.getBinSize();
    }


    return returnValue;
}

void LambertMaterialBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ColorFieldMask & whichField))
    {
        _sfColor.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ColorImageFieldMask & whichField))
    {
        _sfColorImage.copyToBin(pMem);
    }

    if(FieldBits::NoField != (TransparencyFieldMask & whichField))
    {
        _sfTransparency.copyToBin(pMem);
    }

    if(FieldBits::NoField != (TransparencyImageFieldMask & whichField))
    {
        _sfTransparencyImage.copyToBin(pMem);
    }

    if(FieldBits::NoField != (AmbientColorFieldMask & whichField))
    {
        _sfAmbientColor.copyToBin(pMem);
    }

    if(FieldBits::NoField != (AmbientColorImageFieldMask & whichField))
    {
        _sfAmbientColorImage.copyToBin(pMem);
    }

    if(FieldBits::NoField != (IncandescenceFieldMask & whichField))
    {
        _sfIncandescence.copyToBin(pMem);
    }

    if(FieldBits::NoField != (IncandescenceImageFieldMask & whichField))
    {
        _sfIncandescenceImage.copyToBin(pMem);
    }

    if(FieldBits::NoField != (NormalMapImageFieldMask & whichField))
    {
        _sfNormalMapImage.copyToBin(pMem);
    }

    if(FieldBits::NoField != (BumpDepthFieldMask & whichField))
    {
        _sfBumpDepth.copyToBin(pMem);
    }

    if(FieldBits::NoField != (BumpDepthImageFieldMask & whichField))
    {
        _sfBumpDepthImage.copyToBin(pMem);
    }

    if(FieldBits::NoField != (DiffuseFieldMask & whichField))
    {
        _sfDiffuse.copyToBin(pMem);
    }

    if(FieldBits::NoField != (DiffuseImageFieldMask & whichField))
    {
        _sfDiffuseImage.copyToBin(pMem);
    }

    if(FieldBits::NoField != (TransleucenceFieldMask & whichField))
    {
        _sfTransleucence.copyToBin(pMem);
    }

    if(FieldBits::NoField != (TransleucenceImageFieldMask & whichField))
    {
        _sfTransleucenceImage.copyToBin(pMem);
    }

    if(FieldBits::NoField != (TransleucenceDepthFieldMask & whichField))
    {
        _sfTransleucenceDepth.copyToBin(pMem);
    }

    if(FieldBits::NoField != (TransleucenceDepthImageFieldMask & whichField))
    {
        _sfTransleucenceDepthImage.copyToBin(pMem);
    }

    if(FieldBits::NoField != (TransleucenceFocusFieldMask & whichField))
    {
        _sfTransleucenceFocus.copyToBin(pMem);
    }

    if(FieldBits::NoField != (TransleucenceFocusImageFieldMask & whichField))
    {
        _sfTransleucenceFocusImage.copyToBin(pMem);
    }


}

void LambertMaterialBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ColorFieldMask & whichField))
    {
        _sfColor.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ColorImageFieldMask & whichField))
    {
        _sfColorImage.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (TransparencyFieldMask & whichField))
    {
        _sfTransparency.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (TransparencyImageFieldMask & whichField))
    {
        _sfTransparencyImage.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (AmbientColorFieldMask & whichField))
    {
        _sfAmbientColor.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (AmbientColorImageFieldMask & whichField))
    {
        _sfAmbientColorImage.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (IncandescenceFieldMask & whichField))
    {
        _sfIncandescence.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (IncandescenceImageFieldMask & whichField))
    {
        _sfIncandescenceImage.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (NormalMapImageFieldMask & whichField))
    {
        _sfNormalMapImage.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (BumpDepthFieldMask & whichField))
    {
        _sfBumpDepth.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (BumpDepthImageFieldMask & whichField))
    {
        _sfBumpDepthImage.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (DiffuseFieldMask & whichField))
    {
        _sfDiffuse.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (DiffuseImageFieldMask & whichField))
    {
        _sfDiffuseImage.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (TransleucenceFieldMask & whichField))
    {
        _sfTransleucence.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (TransleucenceImageFieldMask & whichField))
    {
        _sfTransleucenceImage.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (TransleucenceDepthFieldMask & whichField))
    {
        _sfTransleucenceDepth.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (TransleucenceDepthImageFieldMask & whichField))
    {
        _sfTransleucenceDepthImage.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (TransleucenceFocusFieldMask & whichField))
    {
        _sfTransleucenceFocus.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (TransleucenceFocusImageFieldMask & whichField))
    {
        _sfTransleucenceFocusImage.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void LambertMaterialBase::executeSyncImpl(      LambertMaterialBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (ColorFieldMask & whichField))
        _sfColor.syncWith(pOther->_sfColor);

    if(FieldBits::NoField != (ColorImageFieldMask & whichField))
        _sfColorImage.syncWith(pOther->_sfColorImage);

    if(FieldBits::NoField != (TransparencyFieldMask & whichField))
        _sfTransparency.syncWith(pOther->_sfTransparency);

    if(FieldBits::NoField != (TransparencyImageFieldMask & whichField))
        _sfTransparencyImage.syncWith(pOther->_sfTransparencyImage);

    if(FieldBits::NoField != (AmbientColorFieldMask & whichField))
        _sfAmbientColor.syncWith(pOther->_sfAmbientColor);

    if(FieldBits::NoField != (AmbientColorImageFieldMask & whichField))
        _sfAmbientColorImage.syncWith(pOther->_sfAmbientColorImage);

    if(FieldBits::NoField != (IncandescenceFieldMask & whichField))
        _sfIncandescence.syncWith(pOther->_sfIncandescence);

    if(FieldBits::NoField != (IncandescenceImageFieldMask & whichField))
        _sfIncandescenceImage.syncWith(pOther->_sfIncandescenceImage);

    if(FieldBits::NoField != (NormalMapImageFieldMask & whichField))
        _sfNormalMapImage.syncWith(pOther->_sfNormalMapImage);

    if(FieldBits::NoField != (BumpDepthFieldMask & whichField))
        _sfBumpDepth.syncWith(pOther->_sfBumpDepth);

    if(FieldBits::NoField != (BumpDepthImageFieldMask & whichField))
        _sfBumpDepthImage.syncWith(pOther->_sfBumpDepthImage);

    if(FieldBits::NoField != (DiffuseFieldMask & whichField))
        _sfDiffuse.syncWith(pOther->_sfDiffuse);

    if(FieldBits::NoField != (DiffuseImageFieldMask & whichField))
        _sfDiffuseImage.syncWith(pOther->_sfDiffuseImage);

    if(FieldBits::NoField != (TransleucenceFieldMask & whichField))
        _sfTransleucence.syncWith(pOther->_sfTransleucence);

    if(FieldBits::NoField != (TransleucenceImageFieldMask & whichField))
        _sfTransleucenceImage.syncWith(pOther->_sfTransleucenceImage);

    if(FieldBits::NoField != (TransleucenceDepthFieldMask & whichField))
        _sfTransleucenceDepth.syncWith(pOther->_sfTransleucenceDepth);

    if(FieldBits::NoField != (TransleucenceDepthImageFieldMask & whichField))
        _sfTransleucenceDepthImage.syncWith(pOther->_sfTransleucenceDepthImage);

    if(FieldBits::NoField != (TransleucenceFocusFieldMask & whichField))
        _sfTransleucenceFocus.syncWith(pOther->_sfTransleucenceFocus);

    if(FieldBits::NoField != (TransleucenceFocusImageFieldMask & whichField))
        _sfTransleucenceFocusImage.syncWith(pOther->_sfTransleucenceFocusImage);


}
#else
void LambertMaterialBase::executeSyncImpl(      LambertMaterialBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (ColorFieldMask & whichField))
        _sfColor.syncWith(pOther->_sfColor);

    if(FieldBits::NoField != (ColorImageFieldMask & whichField))
        _sfColorImage.syncWith(pOther->_sfColorImage);

    if(FieldBits::NoField != (TransparencyFieldMask & whichField))
        _sfTransparency.syncWith(pOther->_sfTransparency);

    if(FieldBits::NoField != (TransparencyImageFieldMask & whichField))
        _sfTransparencyImage.syncWith(pOther->_sfTransparencyImage);

    if(FieldBits::NoField != (AmbientColorFieldMask & whichField))
        _sfAmbientColor.syncWith(pOther->_sfAmbientColor);

    if(FieldBits::NoField != (AmbientColorImageFieldMask & whichField))
        _sfAmbientColorImage.syncWith(pOther->_sfAmbientColorImage);

    if(FieldBits::NoField != (IncandescenceFieldMask & whichField))
        _sfIncandescence.syncWith(pOther->_sfIncandescence);

    if(FieldBits::NoField != (IncandescenceImageFieldMask & whichField))
        _sfIncandescenceImage.syncWith(pOther->_sfIncandescenceImage);

    if(FieldBits::NoField != (NormalMapImageFieldMask & whichField))
        _sfNormalMapImage.syncWith(pOther->_sfNormalMapImage);

    if(FieldBits::NoField != (BumpDepthFieldMask & whichField))
        _sfBumpDepth.syncWith(pOther->_sfBumpDepth);

    if(FieldBits::NoField != (BumpDepthImageFieldMask & whichField))
        _sfBumpDepthImage.syncWith(pOther->_sfBumpDepthImage);

    if(FieldBits::NoField != (DiffuseFieldMask & whichField))
        _sfDiffuse.syncWith(pOther->_sfDiffuse);

    if(FieldBits::NoField != (DiffuseImageFieldMask & whichField))
        _sfDiffuseImage.syncWith(pOther->_sfDiffuseImage);

    if(FieldBits::NoField != (TransleucenceFieldMask & whichField))
        _sfTransleucence.syncWith(pOther->_sfTransleucence);

    if(FieldBits::NoField != (TransleucenceImageFieldMask & whichField))
        _sfTransleucenceImage.syncWith(pOther->_sfTransleucenceImage);

    if(FieldBits::NoField != (TransleucenceDepthFieldMask & whichField))
        _sfTransleucenceDepth.syncWith(pOther->_sfTransleucenceDepth);

    if(FieldBits::NoField != (TransleucenceDepthImageFieldMask & whichField))
        _sfTransleucenceDepthImage.syncWith(pOther->_sfTransleucenceDepthImage);

    if(FieldBits::NoField != (TransleucenceFocusFieldMask & whichField))
        _sfTransleucenceFocus.syncWith(pOther->_sfTransleucenceFocus);

    if(FieldBits::NoField != (TransleucenceFocusImageFieldMask & whichField))
        _sfTransleucenceFocusImage.syncWith(pOther->_sfTransleucenceFocusImage);



}

void LambertMaterialBase::execBeginEditImpl (const BitVector &whichField, 
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
DataType FieldDataTraits<LambertMaterialPtr>::_type("LambertMaterialPtr", "ChunkMaterialPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(LambertMaterialPtr, OSG_TOOLBOXLIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(LambertMaterialPtr, OSG_TOOLBOXLIB_DLLTMPLMAPPING);


OSG_END_NAMESPACE

