/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 * contact: David Kabala (djkabala@gmail.com)                                *
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
 **     class GenericFieldContainerEditor!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGGenericFieldContainerEditorBase.h"
#include "OSGGenericFieldContainerEditor.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::GenericFieldContainerEditor
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var bool            GenericFieldContainerEditorBase::_sfShowFields
    Show the fields of the attached FieldContainer.
*/

/*! \var bool            GenericFieldContainerEditorBase::_sfShowEvents
    Show the produced events of the attached FieldContainer.
*/

/*! \var bool            GenericFieldContainerEditorBase::_sfShowConnectibleEvents
    Show the connectable events of the attached FieldContainer.
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<GenericFieldContainerEditor *>::_type("GenericFieldContainerEditorPtr", "FieldContainerEditorComponentPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(GenericFieldContainerEditor *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           GenericFieldContainerEditor *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           GenericFieldContainerEditor *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void GenericFieldContainerEditorBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "ShowFields",
        "Show the fields of the attached FieldContainer.\n",
        ShowFieldsFieldId, ShowFieldsFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&GenericFieldContainerEditor::editHandleShowFields),
        static_cast<FieldGetMethodSig >(&GenericFieldContainerEditor::getHandleShowFields));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "ShowEvents",
        "Show the produced events of the attached FieldContainer.\n",
        ShowEventsFieldId, ShowEventsFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&GenericFieldContainerEditor::editHandleShowEvents),
        static_cast<FieldGetMethodSig >(&GenericFieldContainerEditor::getHandleShowEvents));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "ShowConnectibleEvents",
        "Show the connectable events of the attached FieldContainer.\n",
        ShowConnectibleEventsFieldId, ShowConnectibleEventsFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&GenericFieldContainerEditor::editHandleShowConnectibleEvents),
        static_cast<FieldGetMethodSig >(&GenericFieldContainerEditor::getHandleShowConnectibleEvents));

    oType.addInitialDesc(pDesc);
}


GenericFieldContainerEditorBase::TypeObject GenericFieldContainerEditorBase::_type(
    GenericFieldContainerEditorBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&GenericFieldContainerEditorBase::createEmptyLocal),
    GenericFieldContainerEditor::initMethod,
    GenericFieldContainerEditor::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&GenericFieldContainerEditor::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "    name=\"GenericFieldContainerEditor\"\n"
    "    parent=\"FieldContainerEditorComponent\"\n"
    "    library=\"ContribFieldContainerEditor\"\n"
    "    pointerfieldtypes=\"both\"\n"
    "    structure=\"concrete\"\n"
    "    systemcomponent=\"true\"\n"
    "    parentsystemcomponent=\"true\"\n"
    "    decoratable=\"false\"\n"
    "    useLocalIncludes=\"false\"\n"
    "    isNodeCore=\"false\"\n"
    "    authors=\"David Kabala (djkabala@gmail.com)\"\n"
    "    >\n"
    "    <Field\n"
    "        name=\"ShowFields\"\n"
    "        type=\"bool\"\n"
    "        category=\"data\"\n"
    "        cardinality=\"single\"\n"
    "        visibility=\"external\"\n"
    "        defaultValue=\"true\"\n"
    "        access=\"public\"\n"
    "        >\n"
    "        Show the fields of the attached FieldContainer.\n"
    "    </Field>\n"
    "    <Field\n"
    "        name=\"ShowEvents\"\n"
    "        type=\"bool\"\n"
    "        category=\"data\"\n"
    "        cardinality=\"single\"\n"
    "        visibility=\"external\"\n"
    "        defaultValue=\"true\"\n"
    "        access=\"public\"\n"
    "        >\n"
    "        Show the produced events of the attached FieldContainer.\n"
    "    </Field>\n"
    "    <Field\n"
    "        name=\"ShowConnectibleEvents\"\n"
    "        type=\"bool\"\n"
    "        category=\"data\"\n"
    "        cardinality=\"single\"\n"
    "        visibility=\"external\"\n"
    "        defaultValue=\"true\"\n"
    "        access=\"public\"\n"
    "        >\n"
    "        Show the connectable events of the attached FieldContainer.\n"
    "    </Field>\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &GenericFieldContainerEditorBase::getType(void)
{
    return _type;
}

const FieldContainerType &GenericFieldContainerEditorBase::getType(void) const
{
    return _type;
}

UInt32 GenericFieldContainerEditorBase::getContainerSize(void) const
{
    return sizeof(GenericFieldContainerEditor);
}

/*------------------------- decorator get ------------------------------*/


SFBool *GenericFieldContainerEditorBase::editSFShowFields(void)
{
    editSField(ShowFieldsFieldMask);

    return &_sfShowFields;
}

const SFBool *GenericFieldContainerEditorBase::getSFShowFields(void) const
{
    return &_sfShowFields;
}


SFBool *GenericFieldContainerEditorBase::editSFShowEvents(void)
{
    editSField(ShowEventsFieldMask);

    return &_sfShowEvents;
}

const SFBool *GenericFieldContainerEditorBase::getSFShowEvents(void) const
{
    return &_sfShowEvents;
}


SFBool *GenericFieldContainerEditorBase::editSFShowConnectibleEvents(void)
{
    editSField(ShowConnectibleEventsFieldMask);

    return &_sfShowConnectibleEvents;
}

const SFBool *GenericFieldContainerEditorBase::getSFShowConnectibleEvents(void) const
{
    return &_sfShowConnectibleEvents;
}






/*------------------------------ access -----------------------------------*/

UInt32 GenericFieldContainerEditorBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ShowFieldsFieldMask & whichField))
    {
        returnValue += _sfShowFields.getBinSize();
    }
    if(FieldBits::NoField != (ShowEventsFieldMask & whichField))
    {
        returnValue += _sfShowEvents.getBinSize();
    }
    if(FieldBits::NoField != (ShowConnectibleEventsFieldMask & whichField))
    {
        returnValue += _sfShowConnectibleEvents.getBinSize();
    }

    return returnValue;
}

void GenericFieldContainerEditorBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ShowFieldsFieldMask & whichField))
    {
        _sfShowFields.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ShowEventsFieldMask & whichField))
    {
        _sfShowEvents.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ShowConnectibleEventsFieldMask & whichField))
    {
        _sfShowConnectibleEvents.copyToBin(pMem);
    }
}

void GenericFieldContainerEditorBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ShowFieldsFieldMask & whichField))
    {
        editSField(ShowFieldsFieldMask);
        _sfShowFields.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ShowEventsFieldMask & whichField))
    {
        editSField(ShowEventsFieldMask);
        _sfShowEvents.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ShowConnectibleEventsFieldMask & whichField))
    {
        editSField(ShowConnectibleEventsFieldMask);
        _sfShowConnectibleEvents.copyFromBin(pMem);
    }
}

//! create a new instance of the class
GenericFieldContainerEditorTransitPtr GenericFieldContainerEditorBase::createLocal(BitVector bFlags)
{
    GenericFieldContainerEditorTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<GenericFieldContainerEditor>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
GenericFieldContainerEditorTransitPtr GenericFieldContainerEditorBase::createDependent(BitVector bFlags)
{
    GenericFieldContainerEditorTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<GenericFieldContainerEditor>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
GenericFieldContainerEditorTransitPtr GenericFieldContainerEditorBase::create(void)
{
    GenericFieldContainerEditorTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<GenericFieldContainerEditor>(tmpPtr);
    }

    return fc;
}

GenericFieldContainerEditor *GenericFieldContainerEditorBase::createEmptyLocal(BitVector bFlags)
{
    GenericFieldContainerEditor *returnValue;

    newPtr<GenericFieldContainerEditor>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
GenericFieldContainerEditor *GenericFieldContainerEditorBase::createEmpty(void)
{
    GenericFieldContainerEditor *returnValue;

    newPtr<GenericFieldContainerEditor>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}

FieldContainerTransitPtr GenericFieldContainerEditorBase::shallowCopyLocal(
    BitVector bFlags) const
{
    GenericFieldContainerEditor *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const GenericFieldContainerEditor *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr GenericFieldContainerEditorBase::shallowCopyDependent(
    BitVector bFlags) const
{
    GenericFieldContainerEditor *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const GenericFieldContainerEditor *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr GenericFieldContainerEditorBase::shallowCopy(void) const
{
    GenericFieldContainerEditor *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const GenericFieldContainerEditor *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}



/*------------------------- constructors ----------------------------------*/

GenericFieldContainerEditorBase::GenericFieldContainerEditorBase(void) :
    Inherited(),
    _sfShowFields             (bool(true)),
    _sfShowEvents             (bool(true)),
    _sfShowConnectibleEvents  (bool(true))
{
}

GenericFieldContainerEditorBase::GenericFieldContainerEditorBase(const GenericFieldContainerEditorBase &source) :
    Inherited(source),
    _sfShowFields             (source._sfShowFields             ),
    _sfShowEvents             (source._sfShowEvents             ),
    _sfShowConnectibleEvents  (source._sfShowConnectibleEvents  )
{
}


/*-------------------------- destructors ----------------------------------*/

GenericFieldContainerEditorBase::~GenericFieldContainerEditorBase(void)
{
}


GetFieldHandlePtr GenericFieldContainerEditorBase::getHandleShowFields      (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfShowFields,
             this->getType().getFieldDesc(ShowFieldsFieldId),
             const_cast<GenericFieldContainerEditorBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr GenericFieldContainerEditorBase::editHandleShowFields     (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfShowFields,
             this->getType().getFieldDesc(ShowFieldsFieldId),
             this));


    editSField(ShowFieldsFieldMask);

    return returnValue;
}

GetFieldHandlePtr GenericFieldContainerEditorBase::getHandleShowEvents      (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfShowEvents,
             this->getType().getFieldDesc(ShowEventsFieldId),
             const_cast<GenericFieldContainerEditorBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr GenericFieldContainerEditorBase::editHandleShowEvents     (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfShowEvents,
             this->getType().getFieldDesc(ShowEventsFieldId),
             this));


    editSField(ShowEventsFieldMask);

    return returnValue;
}

GetFieldHandlePtr GenericFieldContainerEditorBase::getHandleShowConnectibleEvents (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfShowConnectibleEvents,
             this->getType().getFieldDesc(ShowConnectibleEventsFieldId),
             const_cast<GenericFieldContainerEditorBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr GenericFieldContainerEditorBase::editHandleShowConnectibleEvents(void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfShowConnectibleEvents,
             this->getType().getFieldDesc(ShowConnectibleEventsFieldId),
             this));


    editSField(ShowConnectibleEventsFieldMask);

    return returnValue;
}



#ifdef OSG_MT_CPTR_ASPECT
void GenericFieldContainerEditorBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    GenericFieldContainerEditor *pThis = static_cast<GenericFieldContainerEditor *>(this);

    pThis->execSync(static_cast<GenericFieldContainerEditor *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *GenericFieldContainerEditorBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    GenericFieldContainerEditor *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const GenericFieldContainerEditor *>(pRefAspect),
                  dynamic_cast<const GenericFieldContainerEditor *>(this));

    return returnValue;
}
#endif

void GenericFieldContainerEditorBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
