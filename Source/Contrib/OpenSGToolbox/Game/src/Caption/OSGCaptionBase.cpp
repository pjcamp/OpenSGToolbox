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
 **     class Caption!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILECAPTIONINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGCaptionBase.h"
#include "OSGCaption.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  CaptionBase::SegmentFieldMask = 
    (TypeTraits<BitVector>::One << CaptionBase::SegmentFieldId);

const OSG::BitVector  CaptionBase::StartStampsFieldMask = 
    (TypeTraits<BitVector>::One << CaptionBase::StartStampsFieldId);

const OSG::BitVector  CaptionBase::EndStampsFieldMask = 
    (TypeTraits<BitVector>::One << CaptionBase::EndStampsFieldId);

const OSG::BitVector  CaptionBase::CurrentSegmentIndexFieldMask = 
    (TypeTraits<BitVector>::One << CaptionBase::CurrentSegmentIndexFieldId);

const OSG::BitVector  CaptionBase::CaptionDialogSoundFieldMask = 
    (TypeTraits<BitVector>::One << CaptionBase::CaptionDialogSoundFieldId);

const OSG::BitVector  CaptionBase::ParentContainerFieldMask = 
    (TypeTraits<BitVector>::One << CaptionBase::ParentContainerFieldId);

const OSG::BitVector  CaptionBase::ChildIndexFieldMask = 
    (TypeTraits<BitVector>::One << CaptionBase::ChildIndexFieldId);

const OSG::BitVector  CaptionBase::ComponentGeneratorFieldMask = 
    (TypeTraits<BitVector>::One << CaptionBase::ComponentGeneratorFieldId);

const OSG::BitVector  CaptionBase::EventProducerFieldMask =
    (TypeTraits<BitVector>::One << CaptionBase::EventProducerFieldId);

const OSG::BitVector CaptionBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var std::string     CaptionBase::_mfSegment
    
*/
/*! \var Real32          CaptionBase::_mfStartStamps
    
*/
/*! \var Real32          CaptionBase::_mfEndStamps
    
*/
/*! \var Int32           CaptionBase::_sfCurrentSegmentIndex
    
*/
/*! \var SoundPtr        CaptionBase::_sfCaptionDialogSound
    
*/
/*! \var ContainerPtr    CaptionBase::_sfParentContainer
    
*/
/*! \var UInt32          CaptionBase::_sfChildIndex
    
*/
/*! \var CaptionComponentGeneratorPtr CaptionBase::_sfComponentGenerator
    
*/

//! Caption description

FieldDescription *CaptionBase::_desc[] = 
{
    new FieldDescription(MFString::getClassType(), 
                     "Segment", 
                     SegmentFieldId, SegmentFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&CaptionBase::editMFSegment)),
    new FieldDescription(MFReal32::getClassType(), 
                     "StartStamps", 
                     StartStampsFieldId, StartStampsFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&CaptionBase::editMFStartStamps)),
    new FieldDescription(MFReal32::getClassType(), 
                     "EndStamps", 
                     EndStampsFieldId, EndStampsFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&CaptionBase::editMFEndStamps)),
    new FieldDescription(SFInt32::getClassType(), 
                     "CurrentSegmentIndex", 
                     CurrentSegmentIndexFieldId, CurrentSegmentIndexFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&CaptionBase::editSFCurrentSegmentIndex)),
    new FieldDescription(SFSoundPtr::getClassType(), 
                     "CaptionDialogSound", 
                     CaptionDialogSoundFieldId, CaptionDialogSoundFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&CaptionBase::editSFCaptionDialogSound)),
    new FieldDescription(SFContainerPtr::getClassType(), 
                     "ParentContainer", 
                     ParentContainerFieldId, ParentContainerFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&CaptionBase::editSFParentContainer)),
    new FieldDescription(SFUInt32::getClassType(), 
                     "ChildIndex", 
                     ChildIndexFieldId, ChildIndexFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&CaptionBase::editSFChildIndex)),
    new FieldDescription(SFCaptionComponentGeneratorPtr::getClassType(), 
                     "ComponentGenerator", 
                     ComponentGeneratorFieldId, ComponentGeneratorFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&CaptionBase::editSFComponentGenerator))
    , 
    new FieldDescription(SFEventProducerPtr::getClassType(), 
                     "EventProducer", 
                     EventProducerFieldId,EventProducerFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&CaptionBase::editSFEventProducer))
};


FieldContainerType CaptionBase::_type(
    "Caption",
    "AttachmentContainer",
    NULL,
    reinterpret_cast<PrototypeCreateF>(&CaptionBase::createEmpty),
    Caption::initMethod,
    _desc,
    sizeof(_desc));

//! Caption Produced Methods

MethodDescription *CaptionBase::_methodDesc[] =
{
    new MethodDescription("SegmentActivated", 
                     SegmentActivatedMethodId, 
                     SFEventPtr::getClassType(),
                     FunctorAccessMethod()),
    new MethodDescription("CaptionStarted", 
                     CaptionStartedMethodId, 
                     SFEventPtr::getClassType(),
                     FunctorAccessMethod()),
    new MethodDescription("CaptionEnded", 
                     CaptionEndedMethodId, 
                     SFEventPtr::getClassType(),
                     FunctorAccessMethod())
};

EventProducerType CaptionBase::_producerType(
    "CaptionProducerType",
    "EventProducerType",
    NULL,
    InitEventProducerFunctor(),
    _methodDesc,
    sizeof(_methodDesc));
//OSG_FIELD_CONTAINER_DEF(CaptionBase, CaptionPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &CaptionBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &CaptionBase::getType(void) const 
{
    return _type;
} 

const EventProducerType &CaptionBase::getProducerType(void) const
{
    return _producerType;
}


FieldContainerPtr CaptionBase::shallowCopy(void) const 
{ 
    CaptionPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const Caption *>(this)); 

    return returnValue; 
}

UInt32 CaptionBase::getContainerSize(void) const 
{ 
    return sizeof(Caption); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void CaptionBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl(static_cast<CaptionBase *>(&other),
                          whichField);
}
#else
void CaptionBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((CaptionBase *) &other, whichField, sInfo);
}
void CaptionBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void CaptionBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

    _mfSegment.terminateShare(uiAspect, this->getContainerSize());
    _mfStartStamps.terminateShare(uiAspect, this->getContainerSize());
    _mfEndStamps.terminateShare(uiAspect, this->getContainerSize());
}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

CaptionBase::CaptionBase(void) :
    _Producer(&getProducerType()),
    _mfSegment                (), 
    _mfStartStamps            (), 
    _mfEndStamps              (), 
    _sfCurrentSegmentIndex    (Int32(-1)), 
    _sfCaptionDialogSound     (), 
    _sfParentContainer        (), 
    _sfChildIndex             (UInt32(0)), 
    _sfComponentGenerator     (CaptionComponentGeneratorPtr(NullFC)), 
    _sfEventProducer(&_Producer),
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

CaptionBase::CaptionBase(const CaptionBase &source) :
    _Producer(&source.getProducerType()),
    _mfSegment                (source._mfSegment                ), 
    _mfStartStamps            (source._mfStartStamps            ), 
    _mfEndStamps              (source._mfEndStamps              ), 
    _sfCurrentSegmentIndex    (source._sfCurrentSegmentIndex    ), 
    _sfCaptionDialogSound     (source._sfCaptionDialogSound     ), 
    _sfParentContainer        (source._sfParentContainer        ), 
    _sfChildIndex             (source._sfChildIndex             ), 
    _sfComponentGenerator     (source._sfComponentGenerator     ), 
    _sfEventProducer(&_Producer),
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

CaptionBase::~CaptionBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 CaptionBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (SegmentFieldMask & whichField))
    {
        returnValue += _mfSegment.getBinSize();
    }

    if(FieldBits::NoField != (StartStampsFieldMask & whichField))
    {
        returnValue += _mfStartStamps.getBinSize();
    }

    if(FieldBits::NoField != (EndStampsFieldMask & whichField))
    {
        returnValue += _mfEndStamps.getBinSize();
    }

    if(FieldBits::NoField != (CurrentSegmentIndexFieldMask & whichField))
    {
        returnValue += _sfCurrentSegmentIndex.getBinSize();
    }

    if(FieldBits::NoField != (CaptionDialogSoundFieldMask & whichField))
    {
        returnValue += _sfCaptionDialogSound.getBinSize();
    }

    if(FieldBits::NoField != (ParentContainerFieldMask & whichField))
    {
        returnValue += _sfParentContainer.getBinSize();
    }

    if(FieldBits::NoField != (ChildIndexFieldMask & whichField))
    {
        returnValue += _sfChildIndex.getBinSize();
    }

    if(FieldBits::NoField != (ComponentGeneratorFieldMask & whichField))
    {
        returnValue += _sfComponentGenerator.getBinSize();
    }

    if(FieldBits::NoField != (EventProducerFieldMask & whichField))
    {
        returnValue += _sfEventProducer.getBinSize();
    }


    return returnValue;
}

void CaptionBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (SegmentFieldMask & whichField))
    {
        _mfSegment.copyToBin(pMem);
    }

    if(FieldBits::NoField != (StartStampsFieldMask & whichField))
    {
        _mfStartStamps.copyToBin(pMem);
    }

    if(FieldBits::NoField != (EndStampsFieldMask & whichField))
    {
        _mfEndStamps.copyToBin(pMem);
    }

    if(FieldBits::NoField != (CurrentSegmentIndexFieldMask & whichField))
    {
        _sfCurrentSegmentIndex.copyToBin(pMem);
    }

    if(FieldBits::NoField != (CaptionDialogSoundFieldMask & whichField))
    {
        _sfCaptionDialogSound.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ParentContainerFieldMask & whichField))
    {
        _sfParentContainer.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ChildIndexFieldMask & whichField))
    {
        _sfChildIndex.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ComponentGeneratorFieldMask & whichField))
    {
        _sfComponentGenerator.copyToBin(pMem);
    }

    if(FieldBits::NoField != (EventProducerFieldMask & whichField))
    {
        _sfEventProducer.copyToBin(pMem);
    }


}

void CaptionBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (SegmentFieldMask & whichField))
    {
        _mfSegment.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (StartStampsFieldMask & whichField))
    {
        _mfStartStamps.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (EndStampsFieldMask & whichField))
    {
        _mfEndStamps.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (CurrentSegmentIndexFieldMask & whichField))
    {
        _sfCurrentSegmentIndex.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (CaptionDialogSoundFieldMask & whichField))
    {
        _sfCaptionDialogSound.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ParentContainerFieldMask & whichField))
    {
        _sfParentContainer.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ChildIndexFieldMask & whichField))
    {
        _sfChildIndex.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ComponentGeneratorFieldMask & whichField))
    {
        _sfComponentGenerator.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (EventProducerFieldMask & whichField))
    {
        _sfEventProducer.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void CaptionBase::executeSyncImpl(      CaptionBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (SegmentFieldMask & whichField))
        _mfSegment.syncWith(pOther->_mfSegment);

    if(FieldBits::NoField != (StartStampsFieldMask & whichField))
        _mfStartStamps.syncWith(pOther->_mfStartStamps);

    if(FieldBits::NoField != (EndStampsFieldMask & whichField))
        _mfEndStamps.syncWith(pOther->_mfEndStamps);

    if(FieldBits::NoField != (CurrentSegmentIndexFieldMask & whichField))
        _sfCurrentSegmentIndex.syncWith(pOther->_sfCurrentSegmentIndex);

    if(FieldBits::NoField != (CaptionDialogSoundFieldMask & whichField))
        _sfCaptionDialogSound.syncWith(pOther->_sfCaptionDialogSound);

    if(FieldBits::NoField != (ParentContainerFieldMask & whichField))
        _sfParentContainer.syncWith(pOther->_sfParentContainer);

    if(FieldBits::NoField != (ChildIndexFieldMask & whichField))
        _sfChildIndex.syncWith(pOther->_sfChildIndex);

    if(FieldBits::NoField != (ComponentGeneratorFieldMask & whichField))
        _sfComponentGenerator.syncWith(pOther->_sfComponentGenerator);

    if(FieldBits::NoField != (EventProducerFieldMask & whichField))
        _sfEventProducer.syncWith(pOther->_sfEventProducer);


}
#else
void CaptionBase::executeSyncImpl(      CaptionBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (CurrentSegmentIndexFieldMask & whichField))
        _sfCurrentSegmentIndex.syncWith(pOther->_sfCurrentSegmentIndex);

    if(FieldBits::NoField != (CaptionDialogSoundFieldMask & whichField))
        _sfCaptionDialogSound.syncWith(pOther->_sfCaptionDialogSound);

    if(FieldBits::NoField != (ParentContainerFieldMask & whichField))
        _sfParentContainer.syncWith(pOther->_sfParentContainer);

    if(FieldBits::NoField != (ChildIndexFieldMask & whichField))
        _sfChildIndex.syncWith(pOther->_sfChildIndex);

    if(FieldBits::NoField != (ComponentGeneratorFieldMask & whichField))
        _sfComponentGenerator.syncWith(pOther->_sfComponentGenerator);


    if(FieldBits::NoField != (SegmentFieldMask & whichField))
        _mfSegment.syncWith(pOther->_mfSegment, sInfo);

    if(FieldBits::NoField != (StartStampsFieldMask & whichField))
        _mfStartStamps.syncWith(pOther->_mfStartStamps, sInfo);

    if(FieldBits::NoField != (EndStampsFieldMask & whichField))
        _mfEndStamps.syncWith(pOther->_mfEndStamps, sInfo);


}

void CaptionBase::execBeginEditImpl (const BitVector &whichField, 
                                                 UInt32     uiAspect,
                                                 UInt32     uiContainerSize)
{
    Inherited::execBeginEditImpl(whichField, uiAspect, uiContainerSize);

    if(FieldBits::NoField != (SegmentFieldMask & whichField))
        _mfSegment.beginEdit(uiAspect, uiContainerSize);

    if(FieldBits::NoField != (StartStampsFieldMask & whichField))
        _mfStartStamps.beginEdit(uiAspect, uiContainerSize);

    if(FieldBits::NoField != (EndStampsFieldMask & whichField))
        _mfEndStamps.beginEdit(uiAspect, uiContainerSize);

}
#endif



OSG_END_NAMESPACE

#include <OpenSG/OSGSFieldTypeDef.inl>
#include <OpenSG/OSGMFieldTypeDef.inl>

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldDataTraits<CaptionPtr>::_type("CaptionPtr", "AttachmentContainerPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(CaptionPtr, OSG_GAMELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(CaptionPtr, OSG_GAMELIB_DLLTMPLMAPPING);


OSG_END_NAMESPACE

