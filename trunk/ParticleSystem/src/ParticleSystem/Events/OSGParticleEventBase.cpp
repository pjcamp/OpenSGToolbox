/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
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
 **     class ParticleEvent!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEPARTICLEEVENTINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGParticleEventBase.h"
#include "OSGParticleEvent.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  ParticleEventBase::ParticleIndexFieldMask = 
    (TypeTraits<BitVector>::One << ParticleEventBase::ParticleIndexFieldId);

const OSG::BitVector  ParticleEventBase::ParticlePositionFieldMask = 
    (TypeTraits<BitVector>::One << ParticleEventBase::ParticlePositionFieldId);

const OSG::BitVector  ParticleEventBase::ParticleSecPositionFieldMask = 
    (TypeTraits<BitVector>::One << ParticleEventBase::ParticleSecPositionFieldId);

const OSG::BitVector  ParticleEventBase::ParticleNormalFieldMask = 
    (TypeTraits<BitVector>::One << ParticleEventBase::ParticleNormalFieldId);

const OSG::BitVector  ParticleEventBase::ParticleColorFieldMask = 
    (TypeTraits<BitVector>::One << ParticleEventBase::ParticleColorFieldId);

const OSG::BitVector  ParticleEventBase::ParticleSizeFieldMask = 
    (TypeTraits<BitVector>::One << ParticleEventBase::ParticleSizeFieldId);

const OSG::BitVector  ParticleEventBase::ParticleLifespanFieldMask = 
    (TypeTraits<BitVector>::One << ParticleEventBase::ParticleLifespanFieldId);

const OSG::BitVector  ParticleEventBase::ParticleAgeFieldMask = 
    (TypeTraits<BitVector>::One << ParticleEventBase::ParticleAgeFieldId);

const OSG::BitVector  ParticleEventBase::ParticleVelocityFieldMask = 
    (TypeTraits<BitVector>::One << ParticleEventBase::ParticleVelocityFieldId);

const OSG::BitVector  ParticleEventBase::ParticleSecVelocityFieldMask = 
    (TypeTraits<BitVector>::One << ParticleEventBase::ParticleSecVelocityFieldId);

const OSG::BitVector  ParticleEventBase::ParticleAccelerationFieldMask = 
    (TypeTraits<BitVector>::One << ParticleEventBase::ParticleAccelerationFieldId);

const OSG::BitVector  ParticleEventBase::ParticleAttributesFieldMask = 
    (TypeTraits<BitVector>::One << ParticleEventBase::ParticleAttributesFieldId);

const OSG::BitVector ParticleEventBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var Int32           ParticleEventBase::_sfParticleIndex
    
*/
/*! \var Pnt3f           ParticleEventBase::_sfParticlePosition
    
*/
/*! \var Pnt3f           ParticleEventBase::_sfParticleSecPosition
    
*/
/*! \var Vec3f           ParticleEventBase::_sfParticleNormal
    
*/
/*! \var Color4f         ParticleEventBase::_sfParticleColor
    
*/
/*! \var Vec3f           ParticleEventBase::_sfParticleSize
    
*/
/*! \var Real32          ParticleEventBase::_sfParticleLifespan
    
*/
/*! \var Real32          ParticleEventBase::_sfParticleAge
    
*/
/*! \var Vec3f           ParticleEventBase::_sfParticleVelocity
    
*/
/*! \var Vec3f           ParticleEventBase::_sfParticleSecVelocity
    
*/
/*! \var Vec3f           ParticleEventBase::_sfParticleAcceleration
    
*/
/*! \var StringToUInt32Map ParticleEventBase::_sfParticleAttributes
    
*/

//! ParticleEvent description

FieldDescription *ParticleEventBase::_desc[] = 
{
    new FieldDescription(SFInt32::getClassType(), 
                     "ParticleIndex", 
                     ParticleIndexFieldId, ParticleIndexFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ParticleEventBase::editSFParticleIndex)),
    new FieldDescription(SFPnt3f::getClassType(), 
                     "ParticlePosition", 
                     ParticlePositionFieldId, ParticlePositionFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ParticleEventBase::editSFParticlePosition)),
    new FieldDescription(SFPnt3f::getClassType(), 
                     "ParticleSecPosition", 
                     ParticleSecPositionFieldId, ParticleSecPositionFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ParticleEventBase::editSFParticleSecPosition)),
    new FieldDescription(SFVec3f::getClassType(), 
                     "ParticleNormal", 
                     ParticleNormalFieldId, ParticleNormalFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ParticleEventBase::editSFParticleNormal)),
    new FieldDescription(SFColor4f::getClassType(), 
                     "ParticleColor", 
                     ParticleColorFieldId, ParticleColorFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ParticleEventBase::editSFParticleColor)),
    new FieldDescription(SFVec3f::getClassType(), 
                     "ParticleSize", 
                     ParticleSizeFieldId, ParticleSizeFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ParticleEventBase::editSFParticleSize)),
    new FieldDescription(SFReal32::getClassType(), 
                     "ParticleLifespan", 
                     ParticleLifespanFieldId, ParticleLifespanFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ParticleEventBase::editSFParticleLifespan)),
    new FieldDescription(SFReal32::getClassType(), 
                     "ParticleAge", 
                     ParticleAgeFieldId, ParticleAgeFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ParticleEventBase::editSFParticleAge)),
    new FieldDescription(SFVec3f::getClassType(), 
                     "ParticleVelocity", 
                     ParticleVelocityFieldId, ParticleVelocityFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ParticleEventBase::editSFParticleVelocity)),
    new FieldDescription(SFVec3f::getClassType(), 
                     "ParticleSecVelocity", 
                     ParticleSecVelocityFieldId, ParticleSecVelocityFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ParticleEventBase::editSFParticleSecVelocity)),
    new FieldDescription(SFVec3f::getClassType(), 
                     "ParticleAcceleration", 
                     ParticleAccelerationFieldId, ParticleAccelerationFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ParticleEventBase::editSFParticleAcceleration)),
    new FieldDescription(SFStringToUInt32Map::getClassType(), 
                     "ParticleAttributes", 
                     ParticleAttributesFieldId, ParticleAttributesFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ParticleEventBase::editSFParticleAttributes))
};


FieldContainerType ParticleEventBase::_type(
    "ParticleEvent",
    "Event",
    NULL,
    reinterpret_cast<PrototypeCreateF>(&ParticleEventBase::createEmpty),
    ParticleEvent::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(ParticleEventBase, ParticleEventPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &ParticleEventBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &ParticleEventBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr ParticleEventBase::shallowCopy(void) const 
{ 
    ParticleEventPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const ParticleEvent *>(this)); 

    return returnValue; 
}

UInt32 ParticleEventBase::getContainerSize(void) const 
{ 
    return sizeof(ParticleEvent); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void ParticleEventBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl(static_cast<ParticleEventBase *>(&other),
                          whichField);
}
#else
void ParticleEventBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((ParticleEventBase *) &other, whichField, sInfo);
}
void ParticleEventBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void ParticleEventBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

ParticleEventBase::ParticleEventBase(void) :
    _sfParticleIndex          (Int32(-1)), 
    _sfParticlePosition       (Pnt3f(0.0f,0.0f,0.0f)), 
    _sfParticleSecPosition    (Pnt3f(0.0f,0.0f,0.0f)), 
    _sfParticleNormal         (Vec3f(0.0f,0.0f,0.0f)), 
    _sfParticleColor          (Color4f(1.0f,1.0f,1.0f,1.0f)), 
    _sfParticleSize           (Vec3f(1.0f,1.0f,1.0f)), 
    _sfParticleLifespan       (Real32(0.0f)), 
    _sfParticleAge            (Real32(0.0f)), 
    _sfParticleVelocity       (Vec3f(0.0f,0.0f,0.0f)), 
    _sfParticleSecVelocity    (Vec3f(0.0f,0.0f,0.0f)), 
    _sfParticleAcceleration   (Vec3f(0.0f,0.0f,0.0f)), 
    _sfParticleAttributes     (), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

ParticleEventBase::ParticleEventBase(const ParticleEventBase &source) :
    _sfParticleIndex          (source._sfParticleIndex          ), 
    _sfParticlePosition       (source._sfParticlePosition       ), 
    _sfParticleSecPosition    (source._sfParticleSecPosition    ), 
    _sfParticleNormal         (source._sfParticleNormal         ), 
    _sfParticleColor          (source._sfParticleColor          ), 
    _sfParticleSize           (source._sfParticleSize           ), 
    _sfParticleLifespan       (source._sfParticleLifespan       ), 
    _sfParticleAge            (source._sfParticleAge            ), 
    _sfParticleVelocity       (source._sfParticleVelocity       ), 
    _sfParticleSecVelocity    (source._sfParticleSecVelocity    ), 
    _sfParticleAcceleration   (source._sfParticleAcceleration   ), 
    _sfParticleAttributes     (source._sfParticleAttributes     ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

ParticleEventBase::~ParticleEventBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 ParticleEventBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ParticleIndexFieldMask & whichField))
    {
        returnValue += _sfParticleIndex.getBinSize();
    }

    if(FieldBits::NoField != (ParticlePositionFieldMask & whichField))
    {
        returnValue += _sfParticlePosition.getBinSize();
    }

    if(FieldBits::NoField != (ParticleSecPositionFieldMask & whichField))
    {
        returnValue += _sfParticleSecPosition.getBinSize();
    }

    if(FieldBits::NoField != (ParticleNormalFieldMask & whichField))
    {
        returnValue += _sfParticleNormal.getBinSize();
    }

    if(FieldBits::NoField != (ParticleColorFieldMask & whichField))
    {
        returnValue += _sfParticleColor.getBinSize();
    }

    if(FieldBits::NoField != (ParticleSizeFieldMask & whichField))
    {
        returnValue += _sfParticleSize.getBinSize();
    }

    if(FieldBits::NoField != (ParticleLifespanFieldMask & whichField))
    {
        returnValue += _sfParticleLifespan.getBinSize();
    }

    if(FieldBits::NoField != (ParticleAgeFieldMask & whichField))
    {
        returnValue += _sfParticleAge.getBinSize();
    }

    if(FieldBits::NoField != (ParticleVelocityFieldMask & whichField))
    {
        returnValue += _sfParticleVelocity.getBinSize();
    }

    if(FieldBits::NoField != (ParticleSecVelocityFieldMask & whichField))
    {
        returnValue += _sfParticleSecVelocity.getBinSize();
    }

    if(FieldBits::NoField != (ParticleAccelerationFieldMask & whichField))
    {
        returnValue += _sfParticleAcceleration.getBinSize();
    }

    if(FieldBits::NoField != (ParticleAttributesFieldMask & whichField))
    {
        returnValue += _sfParticleAttributes.getBinSize();
    }


    return returnValue;
}

void ParticleEventBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ParticleIndexFieldMask & whichField))
    {
        _sfParticleIndex.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ParticlePositionFieldMask & whichField))
    {
        _sfParticlePosition.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ParticleSecPositionFieldMask & whichField))
    {
        _sfParticleSecPosition.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ParticleNormalFieldMask & whichField))
    {
        _sfParticleNormal.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ParticleColorFieldMask & whichField))
    {
        _sfParticleColor.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ParticleSizeFieldMask & whichField))
    {
        _sfParticleSize.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ParticleLifespanFieldMask & whichField))
    {
        _sfParticleLifespan.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ParticleAgeFieldMask & whichField))
    {
        _sfParticleAge.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ParticleVelocityFieldMask & whichField))
    {
        _sfParticleVelocity.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ParticleSecVelocityFieldMask & whichField))
    {
        _sfParticleSecVelocity.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ParticleAccelerationFieldMask & whichField))
    {
        _sfParticleAcceleration.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ParticleAttributesFieldMask & whichField))
    {
        _sfParticleAttributes.copyToBin(pMem);
    }


}

void ParticleEventBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ParticleIndexFieldMask & whichField))
    {
        _sfParticleIndex.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ParticlePositionFieldMask & whichField))
    {
        _sfParticlePosition.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ParticleSecPositionFieldMask & whichField))
    {
        _sfParticleSecPosition.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ParticleNormalFieldMask & whichField))
    {
        _sfParticleNormal.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ParticleColorFieldMask & whichField))
    {
        _sfParticleColor.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ParticleSizeFieldMask & whichField))
    {
        _sfParticleSize.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ParticleLifespanFieldMask & whichField))
    {
        _sfParticleLifespan.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ParticleAgeFieldMask & whichField))
    {
        _sfParticleAge.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ParticleVelocityFieldMask & whichField))
    {
        _sfParticleVelocity.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ParticleSecVelocityFieldMask & whichField))
    {
        _sfParticleSecVelocity.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ParticleAccelerationFieldMask & whichField))
    {
        _sfParticleAcceleration.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ParticleAttributesFieldMask & whichField))
    {
        _sfParticleAttributes.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void ParticleEventBase::executeSyncImpl(      ParticleEventBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (ParticleIndexFieldMask & whichField))
        _sfParticleIndex.syncWith(pOther->_sfParticleIndex);

    if(FieldBits::NoField != (ParticlePositionFieldMask & whichField))
        _sfParticlePosition.syncWith(pOther->_sfParticlePosition);

    if(FieldBits::NoField != (ParticleSecPositionFieldMask & whichField))
        _sfParticleSecPosition.syncWith(pOther->_sfParticleSecPosition);

    if(FieldBits::NoField != (ParticleNormalFieldMask & whichField))
        _sfParticleNormal.syncWith(pOther->_sfParticleNormal);

    if(FieldBits::NoField != (ParticleColorFieldMask & whichField))
        _sfParticleColor.syncWith(pOther->_sfParticleColor);

    if(FieldBits::NoField != (ParticleSizeFieldMask & whichField))
        _sfParticleSize.syncWith(pOther->_sfParticleSize);

    if(FieldBits::NoField != (ParticleLifespanFieldMask & whichField))
        _sfParticleLifespan.syncWith(pOther->_sfParticleLifespan);

    if(FieldBits::NoField != (ParticleAgeFieldMask & whichField))
        _sfParticleAge.syncWith(pOther->_sfParticleAge);

    if(FieldBits::NoField != (ParticleVelocityFieldMask & whichField))
        _sfParticleVelocity.syncWith(pOther->_sfParticleVelocity);

    if(FieldBits::NoField != (ParticleSecVelocityFieldMask & whichField))
        _sfParticleSecVelocity.syncWith(pOther->_sfParticleSecVelocity);

    if(FieldBits::NoField != (ParticleAccelerationFieldMask & whichField))
        _sfParticleAcceleration.syncWith(pOther->_sfParticleAcceleration);

    if(FieldBits::NoField != (ParticleAttributesFieldMask & whichField))
        _sfParticleAttributes.syncWith(pOther->_sfParticleAttributes);


}
#else
void ParticleEventBase::executeSyncImpl(      ParticleEventBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (ParticleIndexFieldMask & whichField))
        _sfParticleIndex.syncWith(pOther->_sfParticleIndex);

    if(FieldBits::NoField != (ParticlePositionFieldMask & whichField))
        _sfParticlePosition.syncWith(pOther->_sfParticlePosition);

    if(FieldBits::NoField != (ParticleSecPositionFieldMask & whichField))
        _sfParticleSecPosition.syncWith(pOther->_sfParticleSecPosition);

    if(FieldBits::NoField != (ParticleNormalFieldMask & whichField))
        _sfParticleNormal.syncWith(pOther->_sfParticleNormal);

    if(FieldBits::NoField != (ParticleColorFieldMask & whichField))
        _sfParticleColor.syncWith(pOther->_sfParticleColor);

    if(FieldBits::NoField != (ParticleSizeFieldMask & whichField))
        _sfParticleSize.syncWith(pOther->_sfParticleSize);

    if(FieldBits::NoField != (ParticleLifespanFieldMask & whichField))
        _sfParticleLifespan.syncWith(pOther->_sfParticleLifespan);

    if(FieldBits::NoField != (ParticleAgeFieldMask & whichField))
        _sfParticleAge.syncWith(pOther->_sfParticleAge);

    if(FieldBits::NoField != (ParticleVelocityFieldMask & whichField))
        _sfParticleVelocity.syncWith(pOther->_sfParticleVelocity);

    if(FieldBits::NoField != (ParticleSecVelocityFieldMask & whichField))
        _sfParticleSecVelocity.syncWith(pOther->_sfParticleSecVelocity);

    if(FieldBits::NoField != (ParticleAccelerationFieldMask & whichField))
        _sfParticleAcceleration.syncWith(pOther->_sfParticleAcceleration);

    if(FieldBits::NoField != (ParticleAttributesFieldMask & whichField))
        _sfParticleAttributes.syncWith(pOther->_sfParticleAttributes);



}

void ParticleEventBase::execBeginEditImpl (const BitVector &whichField, 
                                                 UInt32     uiAspect,
                                                 UInt32     uiContainerSize)
{
    Inherited::execBeginEditImpl(whichField, uiAspect, uiContainerSize);

}
#endif



OSG_END_NAMESPACE

#include <OpenSG/OSGSFieldTypeDef.inl>

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldDataTraits<ParticleEventPtr>::_type("ParticleEventPtr", "EventPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(ParticleEventPtr, OSG_PARTICLESYSTEMLIB_DLLTMPLMAPPING);


OSG_END_NAMESPACE

