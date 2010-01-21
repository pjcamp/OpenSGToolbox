/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 *   contact:  David Kabala (djkabala@gmail.com)                             *
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
 **     class InputEvent!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGInputEventBase.h"
#include "OSGInputEvent.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::InputEvent
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var bool            InputEventBase::_sfConsumed
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<InputEvent *>::_type("InputEventPtr", "EventPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(InputEvent *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           InputEvent *,
                           0);


/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void InputEventBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "Consumed",
        "",
        ConsumedFieldId, ConsumedFieldMask,
        true,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&InputEvent::editHandleConsumed),
        static_cast<FieldGetMethodSig >(&InputEvent::getHandleConsumed));

    oType.addInitialDesc(pDesc);
}


InputEventBase::TypeObject InputEventBase::_type(
    InputEventBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&InputEventBase::createEmptyLocal),
    InputEvent::initMethod,
    InputEvent::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&InputEvent::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"InputEvent\"\n"
    "\tparent=\"Event\"\n"
    "    library=\"Base\"\n"
    "\tpointerfieldtypes=\"single\"\n"
    "\tstructure=\"concrete\"\n"
    "\tsystemcomponent=\"true\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"false\"\n"
    "    isNodeCore=\"false\"\n"
    "    authors=\"David Kabala (djkabala@gmail.com)                             \"\n"
    ">\n"
    "\t<Field\n"
    "\t\tname=\"Consumed\"\n"
    "\t\ttype=\"bool\"\n"
    "        publicRead=\"true\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"false\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &InputEventBase::getType(void)
{
    return _type;
}

const FieldContainerType &InputEventBase::getType(void) const
{
    return _type;
}

UInt32 InputEventBase::getContainerSize(void) const
{
    return sizeof(InputEvent);
}

/*------------------------- decorator get ------------------------------*/


SFBool *InputEventBase::editSFConsumed(void)
{
    editSField(ConsumedFieldMask);

    return &_sfConsumed;
}

const SFBool *InputEventBase::getSFConsumed(void) const
{
    return &_sfConsumed;
}






/*------------------------------ access -----------------------------------*/

UInt32 InputEventBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ConsumedFieldMask & whichField))
    {
        returnValue += _sfConsumed.getBinSize();
    }

    return returnValue;
}

void InputEventBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ConsumedFieldMask & whichField))
    {
        _sfConsumed.copyToBin(pMem);
    }
}

void InputEventBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ConsumedFieldMask & whichField))
    {
        _sfConsumed.copyFromBin(pMem);
    }
}

//! create a new instance of the class
InputEventTransitPtr InputEventBase::createLocal(BitVector bFlags)
{
    InputEventTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<InputEvent>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
InputEventTransitPtr InputEventBase::createDependent(BitVector bFlags)
{
    InputEventTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<InputEvent>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
InputEventTransitPtr InputEventBase::create(void)
{
    InputEventTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<InputEvent>(tmpPtr);
    }

    return fc;
}

InputEvent *InputEventBase::createEmptyLocal(BitVector bFlags)
{
    InputEvent *returnValue;

    newPtr<InputEvent>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
InputEvent *InputEventBase::createEmpty(void)
{
    InputEvent *returnValue;

    newPtr<InputEvent>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr InputEventBase::shallowCopyLocal(
    BitVector bFlags) const
{
    InputEvent *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const InputEvent *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr InputEventBase::shallowCopyDependent(
    BitVector bFlags) const
{
    InputEvent *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const InputEvent *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr InputEventBase::shallowCopy(void) const
{
    InputEvent *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const InputEvent *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

InputEventBase::InputEventBase(void) :
    Inherited(),
    _sfConsumed               (bool(false))
{
}

InputEventBase::InputEventBase(const InputEventBase &source) :
    Inherited(source),
    _sfConsumed               (source._sfConsumed               )
{
}


/*-------------------------- destructors ----------------------------------*/

InputEventBase::~InputEventBase(void)
{
}


GetFieldHandlePtr InputEventBase::getHandleConsumed        (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfConsumed,
             this->getType().getFieldDesc(ConsumedFieldId),
             const_cast<InputEventBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr InputEventBase::editHandleConsumed       (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfConsumed,
             this->getType().getFieldDesc(ConsumedFieldId),
             this));


    editSField(ConsumedFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void InputEventBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    InputEvent *pThis = static_cast<InputEvent *>(this);

    pThis->execSync(static_cast<InputEvent *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *InputEventBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    InputEvent *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const InputEvent *>(pRefAspect),
                  dynamic_cast<const InputEvent *>(this));

    return returnValue;
}
#endif

void InputEventBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
