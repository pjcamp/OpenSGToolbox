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
 **     class PhysicsCore!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEPHYSICSCOREINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGPhysicsCoreBase.h"
#include "OSGPhysicsCore.h"


OSG_USING_NAMESPACE

const OSG::BitVector  PhysicsCoreBase::TransformationFieldMask = 
    (TypeTraits<BitVector>::One << PhysicsCoreBase::TransformationFieldId);

const OSG::BitVector  PhysicsCoreBase::AttributesFieldMask = 
    (TypeTraits<BitVector>::One << PhysicsCoreBase::AttributesFieldId);

const OSG::BitVector  PhysicsCoreBase::IntegrationFieldMask = 
    (TypeTraits<BitVector>::One << PhysicsCoreBase::IntegrationFieldId);

const OSG::BitVector  PhysicsCoreBase::SystemsFieldMask = 
    (TypeTraits<BitVector>::One << PhysicsCoreBase::SystemsFieldId);

const OSG::BitVector PhysicsCoreBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var Matrix          PhysicsCoreBase::_sfTransformation
    
*/
/*! \var AttachmentMap   PhysicsCoreBase::_sfAttributes
    
*/
/*! \var IntegrationPtr  PhysicsCoreBase::_sfIntegration
    
*/
/*! \var PhysicsSystemPtr PhysicsCoreBase::_mfSystems
    
*/

//! PhysicsCore description

FieldDescription *PhysicsCoreBase::_desc[] = 
{
    new FieldDescription(SFMatrix::getClassType(), 
                     "Transformation", 
                     TransformationFieldId, TransformationFieldMask,
                     false,
                     (FieldAccessMethod) &PhysicsCoreBase::getSFTransformation),
    new FieldDescription(SFAttachmentMap::getClassType(), 
                     "Attributes", 
                     AttributesFieldId, AttributesFieldMask,
                     false,
                     (FieldAccessMethod) &PhysicsCoreBase::getSFAttributes),
    new FieldDescription(SFIntegrationPtr::getClassType(), 
                     "Integration", 
                     IntegrationFieldId, IntegrationFieldMask,
                     false,
                     (FieldAccessMethod) &PhysicsCoreBase::getSFIntegration),
    new FieldDescription(MFPhysicsSystemPtr::getClassType(), 
                     "Systems", 
                     SystemsFieldId, SystemsFieldMask,
                     false,
                     (FieldAccessMethod) &PhysicsCoreBase::getMFSystems)
};


FieldContainerType PhysicsCoreBase::_type(
    "PhysicsCore",
    "Drawable",
    NULL,
    (PrototypeCreateF) &PhysicsCoreBase::createEmpty,
    PhysicsCore::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(PhysicsCoreBase, PhysicsCorePtr)

/*-------------------------------------------------------------------------*/
/*                          Handle Attachments                             */

void PhysicsCoreBase::addAttribute(const PhysicsObjectAttributePtr &fieldContainerP,
                                              UInt16         binding)
{
    UInt32 key;

    if(fieldContainerP == NullFC)
        return;

   if( !fieldContainerP->getType().isDerivedFrom(osg::PhysicsObjectAttribute::getClassType()) )
    {
       SWARNING << "Can only add Attributes to a Physics core that are derived from PhysicsObjectAttribute; Attempted to add an Attachment of type" << fieldContainerP->getTypeName() << "." << std::endl;
       return;
    }

    key = (UInt32 (fieldContainerP->getType().getGroupId()) << 16) | binding;

    addRefCP(fieldContainerP);

    beginEditCP(fieldContainerP, Attachment::ParentsFieldMask);
    {
        fieldContainerP->addParent(getPtr());
    }
    endEditCP  (fieldContainerP, Attachment::ParentsFieldMask);

    AttachmentMap::iterator fcI = _sfAttributes.getValue().find(key);

    if(fcI != _sfAttributes.getValue().end())
    {
        beginEditCP((*fcI).second, Attachment::ParentsFieldMask);
        {
            (*fcI).second->subParent(getPtr());
        }
        endEditCP  ((*fcI).second, Attachment::ParentsFieldMask);

        subRefCP((*fcI).second);

        (*fcI).second = fieldContainerP;
    }
    else
    {
        _sfAttributes.getValue()[key] = fieldContainerP;
    }
}

void PhysicsCoreBase::subAttribute(const PhysicsObjectAttributePtr &fieldContainerP,
                                              UInt16         binding)
{
    UInt32 key;

    AttachmentMap::iterator fcI;

    if(fieldContainerP == NullFC)
        return;

    key = (UInt32(fieldContainerP->getType().getGroupId()) << 16) | binding;

    fcI = _sfAttributes.getValue().find(key);

    if(fcI != _sfAttributes.getValue().end())
    {
        beginEditCP(fieldContainerP, Attachment::ParentsFieldMask);
        {
            (*fcI).second->subParent(getPtr());
        }
        endEditCP  (fieldContainerP, Attachment::ParentsFieldMask);

        subRefCP((*fcI).second);

        _sfAttributes.getValue().erase(fcI);
    }
}

PhysicsObjectAttributePtr PhysicsCoreBase::findAttribute(UInt32 groupId,
                                                  UInt16 binding)
{
    UInt32 key = (UInt32(groupId) << 16) | binding;

    AttachmentMap::iterator fcI = _sfAttributes.getValue().find(key);

    if(fcI == _sfAttributes.getValue().end())
    {
        return NullFC;
    }
    else
    {
       return osg::PhysicsObjectAttribute::Ptr::dcast( (*fcI).second );
    }
}

/*------------------------------ get -----------------------------------*/

FieldContainerType &PhysicsCoreBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &PhysicsCoreBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr PhysicsCoreBase::shallowCopy(void) const 
{ 
    PhysicsCorePtr returnValue; 

    newPtr(returnValue, dynamic_cast<const PhysicsCore *>(this)); 

    return returnValue; 
}

UInt32 PhysicsCoreBase::getContainerSize(void) const 
{ 
    return sizeof(PhysicsCore); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void PhysicsCoreBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl((PhysicsCoreBase *) &other, whichField);
}
#else
void PhysicsCoreBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((PhysicsCoreBase *) &other, whichField, sInfo);
}
void PhysicsCoreBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void PhysicsCoreBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

    _mfSystems.terminateShare(uiAspect, this->getContainerSize());
}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

PhysicsCoreBase::PhysicsCoreBase(void) :
    _sfTransformation         (), 
    _sfAttributes             (), 
    _sfIntegration            (), 
    _mfSystems                (), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

PhysicsCoreBase::PhysicsCoreBase(const PhysicsCoreBase &source) :
    _sfTransformation         (source._sfTransformation         ), 
    _sfAttributes             (source._sfAttributes             ), 
    _sfIntegration            (source._sfIntegration            ), 
    _mfSystems                (source._mfSystems                ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

PhysicsCoreBase::~PhysicsCoreBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 PhysicsCoreBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (TransformationFieldMask & whichField))
    {
        returnValue += _sfTransformation.getBinSize();
    }

    if(FieldBits::NoField != (AttributesFieldMask & whichField))
    {
        returnValue += _sfAttributes.getBinSize();
    }

    if(FieldBits::NoField != (IntegrationFieldMask & whichField))
    {
        returnValue += _sfIntegration.getBinSize();
    }

    if(FieldBits::NoField != (SystemsFieldMask & whichField))
    {
        returnValue += _mfSystems.getBinSize();
    }


    return returnValue;
}

void PhysicsCoreBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (TransformationFieldMask & whichField))
    {
        _sfTransformation.copyToBin(pMem);
    }

    if(FieldBits::NoField != (AttributesFieldMask & whichField))
    {
        _sfAttributes.copyToBin(pMem);
    }

    if(FieldBits::NoField != (IntegrationFieldMask & whichField))
    {
        _sfIntegration.copyToBin(pMem);
    }

    if(FieldBits::NoField != (SystemsFieldMask & whichField))
    {
        _mfSystems.copyToBin(pMem);
    }


}

void PhysicsCoreBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (TransformationFieldMask & whichField))
    {
        _sfTransformation.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (AttributesFieldMask & whichField))
    {
        _sfAttributes.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (IntegrationFieldMask & whichField))
    {
        _sfIntegration.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (SystemsFieldMask & whichField))
    {
        _mfSystems.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void PhysicsCoreBase::executeSyncImpl(      PhysicsCoreBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (TransformationFieldMask & whichField))
        _sfTransformation.syncWith(pOther->_sfTransformation);

    if(FieldBits::NoField != (AttributesFieldMask & whichField))
        _sfAttributes.syncWith(pOther->_sfAttributes);

    if(FieldBits::NoField != (IntegrationFieldMask & whichField))
        _sfIntegration.syncWith(pOther->_sfIntegration);

    if(FieldBits::NoField != (SystemsFieldMask & whichField))
        _mfSystems.syncWith(pOther->_mfSystems);


}
#else
void PhysicsCoreBase::executeSyncImpl(      PhysicsCoreBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (TransformationFieldMask & whichField))
        _sfTransformation.syncWith(pOther->_sfTransformation);

    if(FieldBits::NoField != (AttributesFieldMask & whichField))
        _sfAttributes.syncWith(pOther->_sfAttributes);

    if(FieldBits::NoField != (IntegrationFieldMask & whichField))
        _sfIntegration.syncWith(pOther->_sfIntegration);


    if(FieldBits::NoField != (SystemsFieldMask & whichField))
        _mfSystems.syncWith(pOther->_mfSystems, sInfo);


}

void PhysicsCoreBase::execBeginEditImpl (const BitVector &whichField, 
                                                 UInt32     uiAspect,
                                                 UInt32     uiContainerSize)
{
    Inherited::execBeginEditImpl(whichField, uiAspect, uiContainerSize);

    if(FieldBits::NoField != (SystemsFieldMask & whichField))
        _mfSystems.beginEdit(uiAspect, uiContainerSize);

}
#endif



#include <OpenSG/OSGSFieldTypeDef.inl>
#include <OpenSG/OSGMFieldTypeDef.inl>

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldDataTraits<PhysicsCorePtr>::_type("PhysicsCorePtr", "DrawablePtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(PhysicsCorePtr, );
OSG_DLLEXPORT_MFIELD_DEF1(PhysicsCorePtr, );

OSG_END_NAMESPACE


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
    static Char8 cvsid_cpp       [] = "@(#)$Id: FCBaseTemplate_cpp.h,v 1.45 2005/07/20 00:10:14 vossg Exp $";
    static Char8 cvsid_hpp       [] = OSGPHYSICSCOREBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGPHYSICSCOREBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGPHYSICSCOREFIELDS_HEADER_CVSID;
}
