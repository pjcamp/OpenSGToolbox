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
 **     class AdjustmentEvent!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGAdjustmentEventBase.h"
#include "OSGAdjustmentEvent.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::AdjustmentEvent
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var UInt32          AdjustmentEventBase::_sfValue
    
*/

/*! \var bool            AdjustmentEventBase::_sfValueIsAdjusting
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<AdjustmentEvent *>::_type("AdjustmentEventPtr", "EventPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(AdjustmentEvent *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           AdjustmentEvent *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           AdjustmentEvent *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void AdjustmentEventBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFUInt32::Description(
        SFUInt32::getClassType(),
        "Value",
        "",
        ValueFieldId, ValueFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&AdjustmentEvent::editHandleValue),
        static_cast<FieldGetMethodSig >(&AdjustmentEvent::getHandleValue));

    oType.addInitialDesc(pDesc);


    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "ValueIsAdjusting",
        "",
        ValueIsAdjustingFieldId, ValueIsAdjustingFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&AdjustmentEvent::editHandleValueIsAdjusting),
        static_cast<FieldGetMethodSig >(&AdjustmentEvent::getHandleValueIsAdjusting));

    oType.addInitialDesc(pDesc);

}


AdjustmentEventBase::TypeObject AdjustmentEventBase::_type(
    AdjustmentEventBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&AdjustmentEventBase::createEmptyLocal),
    AdjustmentEvent::initMethod,
    AdjustmentEvent::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&AdjustmentEvent::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"AdjustmentEvent\"\n"
    "\tparent=\"Event\"\n"
    "    library=\"ContribUserInterface\"\n"
    "    pointerfieldtypes=\"both\"\n"
    "\tstructure=\"concrete\"\n"
    "    systemcomponent=\"true\"\n"
    "    parentsystemcomponent=\"true\"\n"
    "    decoratable=\"false\"\n"
    "    useLocalIncludes=\"false\"\n"
    "    isNodeCore=\"false\"\n"
    "    authors=\"David Kabala (djkabala@gmail.com)                             \"\n"
    ">\n"
    "\t<Field\n"
    "\t\tname=\"Value\"\n"
    "\t\ttype=\"UInt32\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"protected\"\n"
    "\t\tdefaultValue=\"0\"\n"
    "        publicRead=\"true\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"ValueIsAdjusting\"\n"
    "\t\ttype=\"bool\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"protected\"\n"
    "\t\tdefaultValue=\"false\"\n"
    "        publicRead=\"true\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    ""
    );


/*------------------------------ get -----------------------------------*/

FieldContainerType &AdjustmentEventBase::getType(void)
{
    return _type;
}

const FieldContainerType &AdjustmentEventBase::getType(void) const
{
    return _type;
}

UInt32 AdjustmentEventBase::getContainerSize(void) const
{
    return sizeof(AdjustmentEvent);
}

/*------------------------- decorator get ------------------------------*/


SFUInt32 *AdjustmentEventBase::editSFValue(void)
{
    editSField(ValueFieldMask);

    return &_sfValue;
}

const SFUInt32 *AdjustmentEventBase::getSFValue(void) const
{
    return &_sfValue;
}


SFBool *AdjustmentEventBase::editSFValueIsAdjusting(void)
{
    editSField(ValueIsAdjustingFieldMask);

    return &_sfValueIsAdjusting;
}

const SFBool *AdjustmentEventBase::getSFValueIsAdjusting(void) const
{
    return &_sfValueIsAdjusting;
}






/*------------------------------ access -----------------------------------*/

UInt32 AdjustmentEventBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ValueFieldMask & whichField))
    {
        returnValue += _sfValue.getBinSize();
    }
    if(FieldBits::NoField != (ValueIsAdjustingFieldMask & whichField))
    {
        returnValue += _sfValueIsAdjusting.getBinSize();
    }

    return returnValue;
}

void AdjustmentEventBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ValueFieldMask & whichField))
    {
        _sfValue.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ValueIsAdjustingFieldMask & whichField))
    {
        _sfValueIsAdjusting.copyToBin(pMem);
    }
}

void AdjustmentEventBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ValueFieldMask & whichField))
    {
        _sfValue.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ValueIsAdjustingFieldMask & whichField))
    {
        _sfValueIsAdjusting.copyFromBin(pMem);
    }
}

//! create a new instance of the class
AdjustmentEventTransitPtr AdjustmentEventBase::createLocal(BitVector bFlags)
{
    AdjustmentEventTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<AdjustmentEvent>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
AdjustmentEventTransitPtr AdjustmentEventBase::createDependent(BitVector bFlags)
{
    AdjustmentEventTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<AdjustmentEvent>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
AdjustmentEventTransitPtr AdjustmentEventBase::create(void)
{
    AdjustmentEventTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<AdjustmentEvent>(tmpPtr);
    }

    return fc;
}

AdjustmentEvent *AdjustmentEventBase::createEmptyLocal(BitVector bFlags)
{
    AdjustmentEvent *returnValue;

    newPtr<AdjustmentEvent>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
AdjustmentEvent *AdjustmentEventBase::createEmpty(void)
{
    AdjustmentEvent *returnValue;

    newPtr<AdjustmentEvent>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr AdjustmentEventBase::shallowCopyLocal(
    BitVector bFlags) const
{
    AdjustmentEvent *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const AdjustmentEvent *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr AdjustmentEventBase::shallowCopyDependent(
    BitVector bFlags) const
{
    AdjustmentEvent *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const AdjustmentEvent *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr AdjustmentEventBase::shallowCopy(void) const
{
    AdjustmentEvent *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const AdjustmentEvent *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

AdjustmentEventBase::AdjustmentEventBase(void) :
    Inherited(),
    _sfValue                  (UInt32(0)),
    _sfValueIsAdjusting       (bool(false))
{
}

AdjustmentEventBase::AdjustmentEventBase(const AdjustmentEventBase &source) :
    Inherited(source),
    _sfValue                  (source._sfValue                  ),
    _sfValueIsAdjusting       (source._sfValueIsAdjusting       )
{
}


/*-------------------------- destructors ----------------------------------*/

AdjustmentEventBase::~AdjustmentEventBase(void)
{
}


GetFieldHandlePtr AdjustmentEventBase::getHandleValue           (void) const
{
    SFUInt32::GetHandlePtr returnValue(
        new  SFUInt32::GetHandle(
             &_sfValue,
             this->getType().getFieldDesc(ValueFieldId),
             const_cast<AdjustmentEventBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr AdjustmentEventBase::editHandleValue          (void)
{
    SFUInt32::EditHandlePtr returnValue(
        new  SFUInt32::EditHandle(
             &_sfValue,
             this->getType().getFieldDesc(ValueFieldId),
             this));


    editSField(ValueFieldMask);

    return returnValue;
}

GetFieldHandlePtr AdjustmentEventBase::getHandleValueIsAdjusting (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfValueIsAdjusting,
             this->getType().getFieldDesc(ValueIsAdjustingFieldId),
             const_cast<AdjustmentEventBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr AdjustmentEventBase::editHandleValueIsAdjusting(void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfValueIsAdjusting,
             this->getType().getFieldDesc(ValueIsAdjustingFieldId),
             this));


    editSField(ValueIsAdjustingFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void AdjustmentEventBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    AdjustmentEvent *pThis = static_cast<AdjustmentEvent *>(this);

    pThis->execSync(static_cast<AdjustmentEvent *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *AdjustmentEventBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    AdjustmentEvent *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const AdjustmentEvent *>(pRefAspect),
                  dynamic_cast<const AdjustmentEvent *>(this));

    return returnValue;
}
#endif

void AdjustmentEventBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
