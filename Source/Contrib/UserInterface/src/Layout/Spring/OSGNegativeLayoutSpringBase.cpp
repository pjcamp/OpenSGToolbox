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
 **     class NegativeLayoutSpring!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"



#include "OSGLayoutSpring.h"            // Spring Class

#include "OSGNegativeLayoutSpringBase.h"
#include "OSGNegativeLayoutSpring.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::NegativeLayoutSpring
    A UI Negative LayoutSpring.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var LayoutSpring *  NegativeLayoutSpringBase::_sfSpring
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<NegativeLayoutSpring *>::_type("NegativeLayoutSpringPtr", "LayoutSpringPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(NegativeLayoutSpring *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           NegativeLayoutSpring *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           NegativeLayoutSpring *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void NegativeLayoutSpringBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFUnrecLayoutSpringPtr::Description(
        SFUnrecLayoutSpringPtr::getClassType(),
        "Spring",
        "",
        SpringFieldId, SpringFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&NegativeLayoutSpring::editHandleSpring),
        static_cast<FieldGetMethodSig >(&NegativeLayoutSpring::getHandleSpring));

    oType.addInitialDesc(pDesc);

}


NegativeLayoutSpringBase::TypeObject NegativeLayoutSpringBase::_type(
    NegativeLayoutSpringBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&NegativeLayoutSpringBase::createEmptyLocal),
    NegativeLayoutSpring::initMethod,
    NegativeLayoutSpring::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&NegativeLayoutSpring::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"NegativeLayoutSpring\"\n"
    "\tparent=\"LayoutSpring\"\n"
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
    "A UI Negative LayoutSpring.\n"
    "\t<Field\n"
    "\t\tname=\"Spring\"\n"
    "\t\ttype=\"LayoutSpring\"\n"
    "        category=\"pointer\"\n"
    "\t\tcardinality=\"single\"\n"
    "      visibility=\"external\"\n"
    "\t\tdefaultValue=\"NULL\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "   </Field>\n"
    "</FieldContainer>\n",
    "A UI Negative LayoutSpring.\n"
    );


/*------------------------------ get -----------------------------------*/

FieldContainerType &NegativeLayoutSpringBase::getType(void)
{
    return _type;
}

const FieldContainerType &NegativeLayoutSpringBase::getType(void) const
{
    return _type;
}

UInt32 NegativeLayoutSpringBase::getContainerSize(void) const
{
    return sizeof(NegativeLayoutSpring);
}

/*------------------------- decorator get ------------------------------*/


//! Get the NegativeLayoutSpring::_sfSpring field.
const SFUnrecLayoutSpringPtr *NegativeLayoutSpringBase::getSFSpring(void) const
{
    return &_sfSpring;
}

SFUnrecLayoutSpringPtr *NegativeLayoutSpringBase::editSFSpring         (void)
{
    editSField(SpringFieldMask);

    return &_sfSpring;
}





/*------------------------------ access -----------------------------------*/

UInt32 NegativeLayoutSpringBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (SpringFieldMask & whichField))
    {
        returnValue += _sfSpring.getBinSize();
    }

    return returnValue;
}

void NegativeLayoutSpringBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (SpringFieldMask & whichField))
    {
        _sfSpring.copyToBin(pMem);
    }
}

void NegativeLayoutSpringBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (SpringFieldMask & whichField))
    {
        _sfSpring.copyFromBin(pMem);
    }
}

//! create a new instance of the class
NegativeLayoutSpringTransitPtr NegativeLayoutSpringBase::createLocal(BitVector bFlags)
{
    NegativeLayoutSpringTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<NegativeLayoutSpring>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
NegativeLayoutSpringTransitPtr NegativeLayoutSpringBase::createDependent(BitVector bFlags)
{
    NegativeLayoutSpringTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<NegativeLayoutSpring>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
NegativeLayoutSpringTransitPtr NegativeLayoutSpringBase::create(void)
{
    NegativeLayoutSpringTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<NegativeLayoutSpring>(tmpPtr);
    }

    return fc;
}

NegativeLayoutSpring *NegativeLayoutSpringBase::createEmptyLocal(BitVector bFlags)
{
    NegativeLayoutSpring *returnValue;

    newPtr<NegativeLayoutSpring>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
NegativeLayoutSpring *NegativeLayoutSpringBase::createEmpty(void)
{
    NegativeLayoutSpring *returnValue;

    newPtr<NegativeLayoutSpring>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr NegativeLayoutSpringBase::shallowCopyLocal(
    BitVector bFlags) const
{
    NegativeLayoutSpring *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const NegativeLayoutSpring *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr NegativeLayoutSpringBase::shallowCopyDependent(
    BitVector bFlags) const
{
    NegativeLayoutSpring *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const NegativeLayoutSpring *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr NegativeLayoutSpringBase::shallowCopy(void) const
{
    NegativeLayoutSpring *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const NegativeLayoutSpring *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

NegativeLayoutSpringBase::NegativeLayoutSpringBase(void) :
    Inherited(),
    _sfSpring                 (NULL)
{
}

NegativeLayoutSpringBase::NegativeLayoutSpringBase(const NegativeLayoutSpringBase &source) :
    Inherited(source),
    _sfSpring                 (NULL)
{
}


/*-------------------------- destructors ----------------------------------*/

NegativeLayoutSpringBase::~NegativeLayoutSpringBase(void)
{
}

void NegativeLayoutSpringBase::onCreate(const NegativeLayoutSpring *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        NegativeLayoutSpring *pThis = static_cast<NegativeLayoutSpring *>(this);

        pThis->setSpring(source->getSpring());
    }
}

GetFieldHandlePtr NegativeLayoutSpringBase::getHandleSpring          (void) const
{
    SFUnrecLayoutSpringPtr::GetHandlePtr returnValue(
        new  SFUnrecLayoutSpringPtr::GetHandle(
             &_sfSpring,
             this->getType().getFieldDesc(SpringFieldId),
             const_cast<NegativeLayoutSpringBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr NegativeLayoutSpringBase::editHandleSpring         (void)
{
    SFUnrecLayoutSpringPtr::EditHandlePtr returnValue(
        new  SFUnrecLayoutSpringPtr::EditHandle(
             &_sfSpring,
             this->getType().getFieldDesc(SpringFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&NegativeLayoutSpring::setSpring,
                    static_cast<NegativeLayoutSpring *>(this), _1));

    editSField(SpringFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void NegativeLayoutSpringBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    NegativeLayoutSpring *pThis = static_cast<NegativeLayoutSpring *>(this);

    pThis->execSync(static_cast<NegativeLayoutSpring *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *NegativeLayoutSpringBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    NegativeLayoutSpring *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const NegativeLayoutSpring *>(pRefAspect),
                  dynamic_cast<const NegativeLayoutSpring *>(this));

    return returnValue;
}
#endif

void NegativeLayoutSpringBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<NegativeLayoutSpring *>(this)->setSpring(NULL);


}


OSG_END_NAMESPACE
