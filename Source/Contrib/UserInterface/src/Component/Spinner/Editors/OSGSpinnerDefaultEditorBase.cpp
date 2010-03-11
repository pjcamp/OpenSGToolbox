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
 **     class SpinnerDefaultEditor!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"



#include "OSGTextField.h"               // TextField Class
#include "OSGSpinner.h"                 // Spinner Class

#include "OSGSpinnerDefaultEditorBase.h"
#include "OSGSpinnerDefaultEditor.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::SpinnerDefaultEditor
    A UI SpinnerDefaultEditor.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var TextField *     SpinnerDefaultEditorBase::_sfTextField
    
*/

/*! \var Spinner *       SpinnerDefaultEditorBase::_sfSpinner
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<SpinnerDefaultEditor *>::_type("SpinnerDefaultEditorPtr", "SpinnerEditorPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(SpinnerDefaultEditor *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           SpinnerDefaultEditor *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           SpinnerDefaultEditor *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void SpinnerDefaultEditorBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFUnrecTextFieldPtr::Description(
        SFUnrecTextFieldPtr::getClassType(),
        "TextField",
        "",
        TextFieldFieldId, TextFieldFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SpinnerDefaultEditor::editHandleTextField),
        static_cast<FieldGetMethodSig >(&SpinnerDefaultEditor::getHandleTextField));

    oType.addInitialDesc(pDesc);


    pDesc = new SFUnrecSpinnerPtr::Description(
        SFUnrecSpinnerPtr::getClassType(),
        "Spinner",
        "",
        SpinnerFieldId, SpinnerFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SpinnerDefaultEditor::editHandleSpinner),
        static_cast<FieldGetMethodSig >(&SpinnerDefaultEditor::getHandleSpinner));

    oType.addInitialDesc(pDesc);

}


SpinnerDefaultEditorBase::TypeObject SpinnerDefaultEditorBase::_type(
    SpinnerDefaultEditorBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&SpinnerDefaultEditorBase::createEmptyLocal),
    SpinnerDefaultEditor::initMethod,
    SpinnerDefaultEditor::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&SpinnerDefaultEditor::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"SpinnerDefaultEditor\"\n"
    "\tparent=\"SpinnerEditor\"\n"
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
    "A UI SpinnerDefaultEditor.\n"
    "\t<Field\n"
    "\t\tname=\"TextField\"\n"
    "\t\ttype=\"TextField\"\n"
    "\t\tcategory=\"pointer\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"NULL\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"Spinner\"\n"
    "\t\ttype=\"Spinner\"\n"
    "\t\tcategory=\"pointer\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"NULL\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "A UI SpinnerDefaultEditor.\n"
    );


/*------------------------------ get -----------------------------------*/

FieldContainerType &SpinnerDefaultEditorBase::getType(void)
{
    return _type;
}

const FieldContainerType &SpinnerDefaultEditorBase::getType(void) const
{
    return _type;
}

UInt32 SpinnerDefaultEditorBase::getContainerSize(void) const
{
    return sizeof(SpinnerDefaultEditor);
}

/*------------------------- decorator get ------------------------------*/


//! Get the SpinnerDefaultEditor::_sfTextField field.
const SFUnrecTextFieldPtr *SpinnerDefaultEditorBase::getSFTextField(void) const
{
    return &_sfTextField;
}

SFUnrecTextFieldPtr *SpinnerDefaultEditorBase::editSFTextField      (void)
{
    editSField(TextFieldFieldMask);

    return &_sfTextField;
}

//! Get the SpinnerDefaultEditor::_sfSpinner field.
const SFUnrecSpinnerPtr *SpinnerDefaultEditorBase::getSFSpinner(void) const
{
    return &_sfSpinner;
}

SFUnrecSpinnerPtr   *SpinnerDefaultEditorBase::editSFSpinner        (void)
{
    editSField(SpinnerFieldMask);

    return &_sfSpinner;
}





/*------------------------------ access -----------------------------------*/

UInt32 SpinnerDefaultEditorBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (TextFieldFieldMask & whichField))
    {
        returnValue += _sfTextField.getBinSize();
    }
    if(FieldBits::NoField != (SpinnerFieldMask & whichField))
    {
        returnValue += _sfSpinner.getBinSize();
    }

    return returnValue;
}

void SpinnerDefaultEditorBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (TextFieldFieldMask & whichField))
    {
        _sfTextField.copyToBin(pMem);
    }
    if(FieldBits::NoField != (SpinnerFieldMask & whichField))
    {
        _sfSpinner.copyToBin(pMem);
    }
}

void SpinnerDefaultEditorBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (TextFieldFieldMask & whichField))
    {
        _sfTextField.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (SpinnerFieldMask & whichField))
    {
        _sfSpinner.copyFromBin(pMem);
    }
}

//! create a new instance of the class
SpinnerDefaultEditorTransitPtr SpinnerDefaultEditorBase::createLocal(BitVector bFlags)
{
    SpinnerDefaultEditorTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<SpinnerDefaultEditor>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
SpinnerDefaultEditorTransitPtr SpinnerDefaultEditorBase::createDependent(BitVector bFlags)
{
    SpinnerDefaultEditorTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<SpinnerDefaultEditor>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
SpinnerDefaultEditorTransitPtr SpinnerDefaultEditorBase::create(void)
{
    SpinnerDefaultEditorTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<SpinnerDefaultEditor>(tmpPtr);
    }

    return fc;
}

SpinnerDefaultEditor *SpinnerDefaultEditorBase::createEmptyLocal(BitVector bFlags)
{
    SpinnerDefaultEditor *returnValue;

    newPtr<SpinnerDefaultEditor>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
SpinnerDefaultEditor *SpinnerDefaultEditorBase::createEmpty(void)
{
    SpinnerDefaultEditor *returnValue;

    newPtr<SpinnerDefaultEditor>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr SpinnerDefaultEditorBase::shallowCopyLocal(
    BitVector bFlags) const
{
    SpinnerDefaultEditor *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const SpinnerDefaultEditor *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr SpinnerDefaultEditorBase::shallowCopyDependent(
    BitVector bFlags) const
{
    SpinnerDefaultEditor *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const SpinnerDefaultEditor *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr SpinnerDefaultEditorBase::shallowCopy(void) const
{
    SpinnerDefaultEditor *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const SpinnerDefaultEditor *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

SpinnerDefaultEditorBase::SpinnerDefaultEditorBase(void) :
    Inherited(),
    _sfTextField              (NULL),
    _sfSpinner                (NULL)
{
}

SpinnerDefaultEditorBase::SpinnerDefaultEditorBase(const SpinnerDefaultEditorBase &source) :
    Inherited(source),
    _sfTextField              (NULL),
    _sfSpinner                (NULL)
{
}


/*-------------------------- destructors ----------------------------------*/

SpinnerDefaultEditorBase::~SpinnerDefaultEditorBase(void)
{
}

void SpinnerDefaultEditorBase::onCreate(const SpinnerDefaultEditor *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        SpinnerDefaultEditor *pThis = static_cast<SpinnerDefaultEditor *>(this);

        pThis->setTextField(source->getTextField());

        pThis->setSpinner(source->getSpinner());
    }
}

GetFieldHandlePtr SpinnerDefaultEditorBase::getHandleTextField       (void) const
{
    SFUnrecTextFieldPtr::GetHandlePtr returnValue(
        new  SFUnrecTextFieldPtr::GetHandle(
             &_sfTextField,
             this->getType().getFieldDesc(TextFieldFieldId),
             const_cast<SpinnerDefaultEditorBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SpinnerDefaultEditorBase::editHandleTextField      (void)
{
    SFUnrecTextFieldPtr::EditHandlePtr returnValue(
        new  SFUnrecTextFieldPtr::EditHandle(
             &_sfTextField,
             this->getType().getFieldDesc(TextFieldFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&SpinnerDefaultEditor::setTextField,
                    static_cast<SpinnerDefaultEditor *>(this), _1));

    editSField(TextFieldFieldMask);

    return returnValue;
}

GetFieldHandlePtr SpinnerDefaultEditorBase::getHandleSpinner         (void) const
{
    SFUnrecSpinnerPtr::GetHandlePtr returnValue(
        new  SFUnrecSpinnerPtr::GetHandle(
             &_sfSpinner,
             this->getType().getFieldDesc(SpinnerFieldId),
             const_cast<SpinnerDefaultEditorBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SpinnerDefaultEditorBase::editHandleSpinner        (void)
{
    SFUnrecSpinnerPtr::EditHandlePtr returnValue(
        new  SFUnrecSpinnerPtr::EditHandle(
             &_sfSpinner,
             this->getType().getFieldDesc(SpinnerFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&SpinnerDefaultEditor::setSpinner,
                    static_cast<SpinnerDefaultEditor *>(this), _1));

    editSField(SpinnerFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void SpinnerDefaultEditorBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    SpinnerDefaultEditor *pThis = static_cast<SpinnerDefaultEditor *>(this);

    pThis->execSync(static_cast<SpinnerDefaultEditor *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *SpinnerDefaultEditorBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    SpinnerDefaultEditor *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const SpinnerDefaultEditor *>(pRefAspect),
                  dynamic_cast<const SpinnerDefaultEditor *>(this));

    return returnValue;
}
#endif

void SpinnerDefaultEditorBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<SpinnerDefaultEditor *>(this)->setTextField(NULL);

    static_cast<SpinnerDefaultEditor *>(this)->setSpinner(NULL);


}


OSG_END_NAMESPACE
