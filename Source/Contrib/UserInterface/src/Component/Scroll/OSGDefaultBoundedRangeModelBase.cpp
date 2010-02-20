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
 **     class DefaultBoundedRangeModel!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGDefaultBoundedRangeModelBase.h"
#include "OSGDefaultBoundedRangeModel.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::DefaultBoundedRangeModel
    A UI DefaultBoundedRangeModel.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Int32           DefaultBoundedRangeModelBase::_sfInternalMinimum
    
*/

/*! \var Int32           DefaultBoundedRangeModelBase::_sfInternalMaximum
    
*/

/*! \var Int32           DefaultBoundedRangeModelBase::_sfInternalValue
    
*/

/*! \var UInt32          DefaultBoundedRangeModelBase::_sfInternalExtent
    
*/

/*! \var bool            DefaultBoundedRangeModelBase::_sfInternalValueIsAdjusting
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<DefaultBoundedRangeModel *>::_type("DefaultBoundedRangeModelPtr", "BoundedRangeModelPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(DefaultBoundedRangeModel *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           DefaultBoundedRangeModel *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           DefaultBoundedRangeModel *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void DefaultBoundedRangeModelBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFInt32::Description(
        SFInt32::getClassType(),
        "InternalMinimum",
        "",
        InternalMinimumFieldId, InternalMinimumFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&DefaultBoundedRangeModel::editHandleInternalMinimum),
        static_cast<FieldGetMethodSig >(&DefaultBoundedRangeModel::getHandleInternalMinimum));

    oType.addInitialDesc(pDesc);

    pDesc = new SFInt32::Description(
        SFInt32::getClassType(),
        "InternalMaximum",
        "",
        InternalMaximumFieldId, InternalMaximumFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&DefaultBoundedRangeModel::editHandleInternalMaximum),
        static_cast<FieldGetMethodSig >(&DefaultBoundedRangeModel::getHandleInternalMaximum));

    oType.addInitialDesc(pDesc);

    pDesc = new SFInt32::Description(
        SFInt32::getClassType(),
        "InternalValue",
        "",
        InternalValueFieldId, InternalValueFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&DefaultBoundedRangeModel::editHandleInternalValue),
        static_cast<FieldGetMethodSig >(&DefaultBoundedRangeModel::getHandleInternalValue));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUInt32::Description(
        SFUInt32::getClassType(),
        "InternalExtent",
        "",
        InternalExtentFieldId, InternalExtentFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&DefaultBoundedRangeModel::editHandleInternalExtent),
        static_cast<FieldGetMethodSig >(&DefaultBoundedRangeModel::getHandleInternalExtent));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "InternalValueIsAdjusting",
        "",
        InternalValueIsAdjustingFieldId, InternalValueIsAdjustingFieldMask,
        true,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&DefaultBoundedRangeModel::editHandleInternalValueIsAdjusting),
        static_cast<FieldGetMethodSig >(&DefaultBoundedRangeModel::getHandleInternalValueIsAdjusting));

    oType.addInitialDesc(pDesc);
}


DefaultBoundedRangeModelBase::TypeObject DefaultBoundedRangeModelBase::_type(
    DefaultBoundedRangeModelBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&DefaultBoundedRangeModelBase::createEmptyLocal),
    DefaultBoundedRangeModel::initMethod,
    DefaultBoundedRangeModel::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&DefaultBoundedRangeModel::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"DefaultBoundedRangeModel\"\n"
    "\tparent=\"BoundedRangeModel\"\n"
    "    library=\"ContribUserInterface\"\n"
    "    pointerfieldtypes=\"both\"\n"
    "\tstructure=\"concrete\"\n"
    "    systemcomponent=\"true\"\n"
    "    parentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"false\"\n"
    "    useLocalIncludes=\"false\"\n"
    "    isNodeCore=\"false\"\n"
    "    authors=\"David Kabala (djkabala@gmail.com)                             \"\n"
    ">\n"
    "A UI DefaultBoundedRangeModel.\n"
    "\t<Field\n"
    "\t\tname=\"InternalMinimum\"\n"
    "\t\ttype=\"Int32\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"0\"\n"
    "\t\taccess=\"protected\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"InternalMaximum\"\n"
    "\t\ttype=\"Int32\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"1\"\n"
    "\t\taccess=\"protected\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"InternalValue\"\n"
    "\t\ttype=\"Int32\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"0\"\n"
    "\t\taccess=\"protected\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"InternalExtent\"\n"
    "\t\ttype=\"UInt32\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"1\"\n"
    "\t\taccess=\"protected\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"InternalValueIsAdjusting\"\n"
    "\t\ttype=\"bool\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\tdefaultValue=\"false\"\n"
    "\t\taccess=\"protected\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "A UI DefaultBoundedRangeModel.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &DefaultBoundedRangeModelBase::getType(void)
{
    return _type;
}

const FieldContainerType &DefaultBoundedRangeModelBase::getType(void) const
{
    return _type;
}

UInt32 DefaultBoundedRangeModelBase::getContainerSize(void) const
{
    return sizeof(DefaultBoundedRangeModel);
}

/*------------------------- decorator get ------------------------------*/


SFInt32 *DefaultBoundedRangeModelBase::editSFInternalMinimum(void)
{
    editSField(InternalMinimumFieldMask);

    return &_sfInternalMinimum;
}

const SFInt32 *DefaultBoundedRangeModelBase::getSFInternalMinimum(void) const
{
    return &_sfInternalMinimum;
}


SFInt32 *DefaultBoundedRangeModelBase::editSFInternalMaximum(void)
{
    editSField(InternalMaximumFieldMask);

    return &_sfInternalMaximum;
}

const SFInt32 *DefaultBoundedRangeModelBase::getSFInternalMaximum(void) const
{
    return &_sfInternalMaximum;
}


SFInt32 *DefaultBoundedRangeModelBase::editSFInternalValue(void)
{
    editSField(InternalValueFieldMask);

    return &_sfInternalValue;
}

const SFInt32 *DefaultBoundedRangeModelBase::getSFInternalValue(void) const
{
    return &_sfInternalValue;
}


SFUInt32 *DefaultBoundedRangeModelBase::editSFInternalExtent(void)
{
    editSField(InternalExtentFieldMask);

    return &_sfInternalExtent;
}

const SFUInt32 *DefaultBoundedRangeModelBase::getSFInternalExtent(void) const
{
    return &_sfInternalExtent;
}


SFBool *DefaultBoundedRangeModelBase::editSFInternalValueIsAdjusting(void)
{
    editSField(InternalValueIsAdjustingFieldMask);

    return &_sfInternalValueIsAdjusting;
}

const SFBool *DefaultBoundedRangeModelBase::getSFInternalValueIsAdjusting(void) const
{
    return &_sfInternalValueIsAdjusting;
}






/*------------------------------ access -----------------------------------*/

UInt32 DefaultBoundedRangeModelBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (InternalMinimumFieldMask & whichField))
    {
        returnValue += _sfInternalMinimum.getBinSize();
    }
    if(FieldBits::NoField != (InternalMaximumFieldMask & whichField))
    {
        returnValue += _sfInternalMaximum.getBinSize();
    }
    if(FieldBits::NoField != (InternalValueFieldMask & whichField))
    {
        returnValue += _sfInternalValue.getBinSize();
    }
    if(FieldBits::NoField != (InternalExtentFieldMask & whichField))
    {
        returnValue += _sfInternalExtent.getBinSize();
    }
    if(FieldBits::NoField != (InternalValueIsAdjustingFieldMask & whichField))
    {
        returnValue += _sfInternalValueIsAdjusting.getBinSize();
    }

    return returnValue;
}

void DefaultBoundedRangeModelBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (InternalMinimumFieldMask & whichField))
    {
        _sfInternalMinimum.copyToBin(pMem);
    }
    if(FieldBits::NoField != (InternalMaximumFieldMask & whichField))
    {
        _sfInternalMaximum.copyToBin(pMem);
    }
    if(FieldBits::NoField != (InternalValueFieldMask & whichField))
    {
        _sfInternalValue.copyToBin(pMem);
    }
    if(FieldBits::NoField != (InternalExtentFieldMask & whichField))
    {
        _sfInternalExtent.copyToBin(pMem);
    }
    if(FieldBits::NoField != (InternalValueIsAdjustingFieldMask & whichField))
    {
        _sfInternalValueIsAdjusting.copyToBin(pMem);
    }
}

void DefaultBoundedRangeModelBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (InternalMinimumFieldMask & whichField))
    {
        _sfInternalMinimum.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (InternalMaximumFieldMask & whichField))
    {
        _sfInternalMaximum.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (InternalValueFieldMask & whichField))
    {
        _sfInternalValue.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (InternalExtentFieldMask & whichField))
    {
        _sfInternalExtent.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (InternalValueIsAdjustingFieldMask & whichField))
    {
        _sfInternalValueIsAdjusting.copyFromBin(pMem);
    }
}

//! create a new instance of the class
DefaultBoundedRangeModelTransitPtr DefaultBoundedRangeModelBase::createLocal(BitVector bFlags)
{
    DefaultBoundedRangeModelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<DefaultBoundedRangeModel>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
DefaultBoundedRangeModelTransitPtr DefaultBoundedRangeModelBase::createDependent(BitVector bFlags)
{
    DefaultBoundedRangeModelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<DefaultBoundedRangeModel>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
DefaultBoundedRangeModelTransitPtr DefaultBoundedRangeModelBase::create(void)
{
    DefaultBoundedRangeModelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<DefaultBoundedRangeModel>(tmpPtr);
    }

    return fc;
}

DefaultBoundedRangeModel *DefaultBoundedRangeModelBase::createEmptyLocal(BitVector bFlags)
{
    DefaultBoundedRangeModel *returnValue;

    newPtr<DefaultBoundedRangeModel>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
DefaultBoundedRangeModel *DefaultBoundedRangeModelBase::createEmpty(void)
{
    DefaultBoundedRangeModel *returnValue;

    newPtr<DefaultBoundedRangeModel>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr DefaultBoundedRangeModelBase::shallowCopyLocal(
    BitVector bFlags) const
{
    DefaultBoundedRangeModel *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const DefaultBoundedRangeModel *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr DefaultBoundedRangeModelBase::shallowCopyDependent(
    BitVector bFlags) const
{
    DefaultBoundedRangeModel *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const DefaultBoundedRangeModel *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr DefaultBoundedRangeModelBase::shallowCopy(void) const
{
    DefaultBoundedRangeModel *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const DefaultBoundedRangeModel *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

DefaultBoundedRangeModelBase::DefaultBoundedRangeModelBase(void) :
    Inherited(),
    _sfInternalMinimum        (Int32(0)),
    _sfInternalMaximum        (Int32(1)),
    _sfInternalValue          (Int32(0)),
    _sfInternalExtent         (UInt32(1)),
    _sfInternalValueIsAdjusting(bool(false))
{
}

DefaultBoundedRangeModelBase::DefaultBoundedRangeModelBase(const DefaultBoundedRangeModelBase &source) :
    Inherited(source),
    _sfInternalMinimum        (source._sfInternalMinimum        ),
    _sfInternalMaximum        (source._sfInternalMaximum        ),
    _sfInternalValue          (source._sfInternalValue          ),
    _sfInternalExtent         (source._sfInternalExtent         ),
    _sfInternalValueIsAdjusting(source._sfInternalValueIsAdjusting)
{
}


/*-------------------------- destructors ----------------------------------*/

DefaultBoundedRangeModelBase::~DefaultBoundedRangeModelBase(void)
{
}


GetFieldHandlePtr DefaultBoundedRangeModelBase::getHandleInternalMinimum (void) const
{
    SFInt32::GetHandlePtr returnValue(
        new  SFInt32::GetHandle(
             &_sfInternalMinimum,
             this->getType().getFieldDesc(InternalMinimumFieldId),
             const_cast<DefaultBoundedRangeModelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr DefaultBoundedRangeModelBase::editHandleInternalMinimum(void)
{
    SFInt32::EditHandlePtr returnValue(
        new  SFInt32::EditHandle(
             &_sfInternalMinimum,
             this->getType().getFieldDesc(InternalMinimumFieldId),
             this));


    editSField(InternalMinimumFieldMask);

    return returnValue;
}

GetFieldHandlePtr DefaultBoundedRangeModelBase::getHandleInternalMaximum (void) const
{
    SFInt32::GetHandlePtr returnValue(
        new  SFInt32::GetHandle(
             &_sfInternalMaximum,
             this->getType().getFieldDesc(InternalMaximumFieldId),
             const_cast<DefaultBoundedRangeModelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr DefaultBoundedRangeModelBase::editHandleInternalMaximum(void)
{
    SFInt32::EditHandlePtr returnValue(
        new  SFInt32::EditHandle(
             &_sfInternalMaximum,
             this->getType().getFieldDesc(InternalMaximumFieldId),
             this));


    editSField(InternalMaximumFieldMask);

    return returnValue;
}

GetFieldHandlePtr DefaultBoundedRangeModelBase::getHandleInternalValue   (void) const
{
    SFInt32::GetHandlePtr returnValue(
        new  SFInt32::GetHandle(
             &_sfInternalValue,
             this->getType().getFieldDesc(InternalValueFieldId),
             const_cast<DefaultBoundedRangeModelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr DefaultBoundedRangeModelBase::editHandleInternalValue  (void)
{
    SFInt32::EditHandlePtr returnValue(
        new  SFInt32::EditHandle(
             &_sfInternalValue,
             this->getType().getFieldDesc(InternalValueFieldId),
             this));


    editSField(InternalValueFieldMask);

    return returnValue;
}

GetFieldHandlePtr DefaultBoundedRangeModelBase::getHandleInternalExtent  (void) const
{
    SFUInt32::GetHandlePtr returnValue(
        new  SFUInt32::GetHandle(
             &_sfInternalExtent,
             this->getType().getFieldDesc(InternalExtentFieldId),
             const_cast<DefaultBoundedRangeModelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr DefaultBoundedRangeModelBase::editHandleInternalExtent (void)
{
    SFUInt32::EditHandlePtr returnValue(
        new  SFUInt32::EditHandle(
             &_sfInternalExtent,
             this->getType().getFieldDesc(InternalExtentFieldId),
             this));


    editSField(InternalExtentFieldMask);

    return returnValue;
}

GetFieldHandlePtr DefaultBoundedRangeModelBase::getHandleInternalValueIsAdjusting (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfInternalValueIsAdjusting,
             this->getType().getFieldDesc(InternalValueIsAdjustingFieldId),
             const_cast<DefaultBoundedRangeModelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr DefaultBoundedRangeModelBase::editHandleInternalValueIsAdjusting(void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfInternalValueIsAdjusting,
             this->getType().getFieldDesc(InternalValueIsAdjustingFieldId),
             this));


    editSField(InternalValueIsAdjustingFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void DefaultBoundedRangeModelBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    DefaultBoundedRangeModel *pThis = static_cast<DefaultBoundedRangeModel *>(this);

    pThis->execSync(static_cast<DefaultBoundedRangeModel *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *DefaultBoundedRangeModelBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    DefaultBoundedRangeModel *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const DefaultBoundedRangeModel *>(pRefAspect),
                  dynamic_cast<const DefaultBoundedRangeModel *>(this));

    return returnValue;
}
#endif

void DefaultBoundedRangeModelBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
