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
 **     class Dialog!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEDIALOGINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGDialogBase.h"
#include "OSGDialog.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  DialogBase::ResponseFieldMask = 
    (TypeTraits<BitVector>::One << DialogBase::ResponseFieldId);

const OSG::BitVector  DialogBase::ResponsePresentationDelayFieldMask = 
    (TypeTraits<BitVector>::One << DialogBase::ResponsePresentationDelayFieldId);

const OSG::BitVector  DialogBase::InteractiveFieldMask = 
    (TypeTraits<BitVector>::One << DialogBase::InteractiveFieldId);

const OSG::BitVector  DialogBase::ResponsesFieldMask = 
    (TypeTraits<BitVector>::One << DialogBase::ResponsesFieldId);

const OSG::BitVector  DialogBase::DialogSoundFieldMask = 
    (TypeTraits<BitVector>::One << DialogBase::DialogSoundFieldId);

const OSG::BitVector  DialogBase::ParentDialogHierarchyFieldMask = 
    (TypeTraits<BitVector>::One << DialogBase::ParentDialogHierarchyFieldId);

const OSG::BitVector  DialogBase::EventProducerFieldMask =
    (TypeTraits<BitVector>::One << DialogBase::EventProducerFieldId);

const OSG::BitVector DialogBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var std::string     DialogBase::_sfResponse
    
*/
/*! \var Real32          DialogBase::_sfResponsePresentationDelay
    
*/
/*! \var bool            DialogBase::_sfInteractive
    
*/
/*! \var DialogPtr       DialogBase::_mfResponses
    
*/
/*! \var SoundPtr        DialogBase::_sfDialogSound
    
*/
/*! \var DialogHierarchyPtr DialogBase::_sfParentDialogHierarchy
    
*/

//! Dialog description

FieldDescription *DialogBase::_desc[] = 
{
    new FieldDescription(SFString::getClassType(), 
                     "Response", 
                     ResponseFieldId, ResponseFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&DialogBase::editSFResponse)),
    new FieldDescription(SFReal32::getClassType(), 
                     "ResponsePresentationDelay", 
                     ResponsePresentationDelayFieldId, ResponsePresentationDelayFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&DialogBase::editSFResponsePresentationDelay)),
    new FieldDescription(SFBool::getClassType(), 
                     "Interactive", 
                     InteractiveFieldId, InteractiveFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&DialogBase::editSFInteractive)),
    new FieldDescription(MFDialogPtr::getClassType(), 
                     "Responses", 
                     ResponsesFieldId, ResponsesFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&DialogBase::editMFResponses)),
    new FieldDescription(SFSoundPtr::getClassType(), 
                     "DialogSound", 
                     DialogSoundFieldId, DialogSoundFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&DialogBase::editSFDialogSound)),
    new FieldDescription(SFDialogHierarchyPtr::getClassType(), 
                     "ParentDialogHierarchy", 
                     ParentDialogHierarchyFieldId, ParentDialogHierarchyFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&DialogBase::editSFParentDialogHierarchy))
    , 
    new FieldDescription(SFEventProducerPtr::getClassType(), 
                     "EventProducer", 
                     EventProducerFieldId,EventProducerFieldMask,
                     true,
                     FieldAccessMethod(NULL))
};


FieldContainerType DialogBase::_type(
    "Dialog",
    "AttachmentContainer",
    NULL,
    reinterpret_cast<PrototypeCreateF>(&DialogBase::createEmpty),
    Dialog::initMethod,
    _desc,
    sizeof(_desc));

//! Dialog Produced Methods

MethodDescription *DialogBase::_methodDesc[] =
{
    new MethodDescription("Started", 
                     StartedMethodId, 
                     SFEventPtr::getClassType(),
                     FunctorAccessMethod()),
    new MethodDescription("Ended", 
                     EndedMethodId, 
                     SFEventPtr::getClassType(),
                     FunctorAccessMethod()),
    new MethodDescription("ResponseSelected", 
                     ResponseSelectedMethodId, 
                     SFEventPtr::getClassType(),
                     FunctorAccessMethod()),
    new MethodDescription("ResponsesReady", 
                     ResponsesReadyMethodId, 
                     SFEventPtr::getClassType(),
                     FunctorAccessMethod()),
    new MethodDescription("Terminated", 
                     TerminatedMethodId, 
                     SFEventPtr::getClassType(),
                     FunctorAccessMethod())
};

EventProducerType DialogBase::_producerType(
    "DialogProducerType",
    "EventProducerType",
    NULL,
    InitEventProducerFunctor(),
    _methodDesc,
    sizeof(_methodDesc));
//OSG_FIELD_CONTAINER_DEF(DialogBase, DialogPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &DialogBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &DialogBase::getType(void) const 
{
    return _type;
} 

const EventProducerType &DialogBase::getProducerType(void) const
{
    return _producerType;
}


FieldContainerPtr DialogBase::shallowCopy(void) const 
{ 
    DialogPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const Dialog *>(this)); 

    return returnValue; 
}

UInt32 DialogBase::getContainerSize(void) const 
{ 
    return sizeof(Dialog); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void DialogBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl(static_cast<DialogBase *>(&other),
                          whichField);
}
#else
void DialogBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((DialogBase *) &other, whichField, sInfo);
}
void DialogBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void DialogBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

    _mfResponses.terminateShare(uiAspect, this->getContainerSize());
}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

DialogBase::DialogBase(void) :
    _Producer(&getProducerType()),
    _sfResponse               (), 
    _sfResponsePresentationDelay(), 
    _sfInteractive            (), 
    _mfResponses              (), 
    _sfDialogSound            (), 
    _sfParentDialogHierarchy  (), 
    _sfEventProducer(&_Producer),
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

DialogBase::DialogBase(const DialogBase &source) :
    _Producer(&getProducerType()),
    _sfResponse               (source._sfResponse               ), 
    _sfResponsePresentationDelay(source._sfResponsePresentationDelay), 
    _sfInteractive            (source._sfInteractive            ), 
    _mfResponses              (source._mfResponses              ), 
    _sfDialogSound            (source._sfDialogSound            ), 
    _sfParentDialogHierarchy  (source._sfParentDialogHierarchy  ), 
    _sfEventProducer(&_Producer),
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

DialogBase::~DialogBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 DialogBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ResponseFieldMask & whichField))
    {
        returnValue += _sfResponse.getBinSize();
    }

    if(FieldBits::NoField != (ResponsePresentationDelayFieldMask & whichField))
    {
        returnValue += _sfResponsePresentationDelay.getBinSize();
    }

    if(FieldBits::NoField != (InteractiveFieldMask & whichField))
    {
        returnValue += _sfInteractive.getBinSize();
    }

    if(FieldBits::NoField != (ResponsesFieldMask & whichField))
    {
        returnValue += _mfResponses.getBinSize();
    }

    if(FieldBits::NoField != (DialogSoundFieldMask & whichField))
    {
        returnValue += _sfDialogSound.getBinSize();
    }

    if(FieldBits::NoField != (ParentDialogHierarchyFieldMask & whichField))
    {
        returnValue += _sfParentDialogHierarchy.getBinSize();
    }

    if(FieldBits::NoField != (EventProducerFieldMask & whichField))
    {
        returnValue += _sfEventProducer.getBinSize();
    }


    return returnValue;
}

void DialogBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ResponseFieldMask & whichField))
    {
        _sfResponse.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ResponsePresentationDelayFieldMask & whichField))
    {
        _sfResponsePresentationDelay.copyToBin(pMem);
    }

    if(FieldBits::NoField != (InteractiveFieldMask & whichField))
    {
        _sfInteractive.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ResponsesFieldMask & whichField))
    {
        _mfResponses.copyToBin(pMem);
    }

    if(FieldBits::NoField != (DialogSoundFieldMask & whichField))
    {
        _sfDialogSound.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ParentDialogHierarchyFieldMask & whichField))
    {
        _sfParentDialogHierarchy.copyToBin(pMem);
    }

    if(FieldBits::NoField != (EventProducerFieldMask & whichField))
    {
        _sfEventProducer.copyToBin(pMem);
    }


}

void DialogBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ResponseFieldMask & whichField))
    {
        _sfResponse.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ResponsePresentationDelayFieldMask & whichField))
    {
        _sfResponsePresentationDelay.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (InteractiveFieldMask & whichField))
    {
        _sfInteractive.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ResponsesFieldMask & whichField))
    {
        _mfResponses.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (DialogSoundFieldMask & whichField))
    {
        _sfDialogSound.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ParentDialogHierarchyFieldMask & whichField))
    {
        _sfParentDialogHierarchy.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (EventProducerFieldMask & whichField))
    {
        _sfEventProducer.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void DialogBase::executeSyncImpl(      DialogBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (ResponseFieldMask & whichField))
        _sfResponse.syncWith(pOther->_sfResponse);

    if(FieldBits::NoField != (ResponsePresentationDelayFieldMask & whichField))
        _sfResponsePresentationDelay.syncWith(pOther->_sfResponsePresentationDelay);

    if(FieldBits::NoField != (InteractiveFieldMask & whichField))
        _sfInteractive.syncWith(pOther->_sfInteractive);

    if(FieldBits::NoField != (ResponsesFieldMask & whichField))
        _mfResponses.syncWith(pOther->_mfResponses);

    if(FieldBits::NoField != (DialogSoundFieldMask & whichField))
        _sfDialogSound.syncWith(pOther->_sfDialogSound);

    if(FieldBits::NoField != (ParentDialogHierarchyFieldMask & whichField))
        _sfParentDialogHierarchy.syncWith(pOther->_sfParentDialogHierarchy);

    if(FieldBits::NoField != (EventProducerFieldMask & whichField))
        _sfEventProducer.syncWith(pOther->_sfEventProducer);


}
#else
void DialogBase::executeSyncImpl(      DialogBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (ResponseFieldMask & whichField))
        _sfResponse.syncWith(pOther->_sfResponse);

    if(FieldBits::NoField != (ResponsePresentationDelayFieldMask & whichField))
        _sfResponsePresentationDelay.syncWith(pOther->_sfResponsePresentationDelay);

    if(FieldBits::NoField != (InteractiveFieldMask & whichField))
        _sfInteractive.syncWith(pOther->_sfInteractive);

    if(FieldBits::NoField != (DialogSoundFieldMask & whichField))
        _sfDialogSound.syncWith(pOther->_sfDialogSound);

    if(FieldBits::NoField != (ParentDialogHierarchyFieldMask & whichField))
        _sfParentDialogHierarchy.syncWith(pOther->_sfParentDialogHierarchy);


    if(FieldBits::NoField != (ResponsesFieldMask & whichField))
        _mfResponses.syncWith(pOther->_mfResponses, sInfo);


}

void DialogBase::execBeginEditImpl (const BitVector &whichField, 
                                                 UInt32     uiAspect,
                                                 UInt32     uiContainerSize)
{
    Inherited::execBeginEditImpl(whichField, uiAspect, uiContainerSize);

    if(FieldBits::NoField != (ResponsesFieldMask & whichField))
        _mfResponses.beginEdit(uiAspect, uiContainerSize);

}
#endif



OSG_END_NAMESPACE

#include <OpenSG/OSGSFieldTypeDef.inl>
#include <OpenSG/OSGMFieldTypeDef.inl>

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldDataTraits<DialogPtr>::_type("DialogPtr", "AttachmentContainerPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(DialogPtr, OSG_GAMELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(DialogPtr, OSG_GAMELIB_DLLTMPLMAPPING);


OSG_END_NAMESPACE

