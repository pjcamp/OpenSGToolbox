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
 **     class UndoableEditEventDetails!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"





#include "OSGUndoableEditEventDetailsBase.h"
#include "OSGUndoableEditEventDetails.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::UndoableEditEventDetails
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<UndoableEditEventDetails *>::_type("UndoableEditEventDetailsPtr", "EventDetailsPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(UndoableEditEventDetails *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           UndoableEditEventDetails *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           UndoableEditEventDetails *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void UndoableEditEventDetailsBase::classDescInserter(TypeObject &oType)
{
}


UndoableEditEventDetailsBase::TypeObject UndoableEditEventDetailsBase::_type(
    UndoableEditEventDetailsBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&UndoableEditEventDetailsBase::createEmptyLocal),
    UndoableEditEventDetails::initMethod,
    UndoableEditEventDetails::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&UndoableEditEventDetails::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"UndoableEditEventDetails\"\n"
    "\tparent=\"EventDetails\"\n"
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
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &UndoableEditEventDetailsBase::getType(void)
{
    return _type;
}

const FieldContainerType &UndoableEditEventDetailsBase::getType(void) const
{
    return _type;
}

UInt32 UndoableEditEventDetailsBase::getContainerSize(void) const
{
    return sizeof(UndoableEditEventDetails);
}

/*------------------------- decorator get ------------------------------*/






/*------------------------------ access -----------------------------------*/

UInt32 UndoableEditEventDetailsBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);


    return returnValue;
}

void UndoableEditEventDetailsBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

}

void UndoableEditEventDetailsBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

}

//! create a new instance of the class
UndoableEditEventDetailsTransitPtr UndoableEditEventDetailsBase::createLocal(BitVector bFlags)
{
    UndoableEditEventDetailsTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<UndoableEditEventDetails>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
UndoableEditEventDetailsTransitPtr UndoableEditEventDetailsBase::createDependent(BitVector bFlags)
{
    UndoableEditEventDetailsTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<UndoableEditEventDetails>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
UndoableEditEventDetailsTransitPtr UndoableEditEventDetailsBase::create(void)
{
    UndoableEditEventDetailsTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<UndoableEditEventDetails>(tmpPtr);
    }

    return fc;
}

UndoableEditEventDetails *UndoableEditEventDetailsBase::createEmptyLocal(BitVector bFlags)
{
    UndoableEditEventDetails *returnValue;

    newPtr<UndoableEditEventDetails>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
UndoableEditEventDetails *UndoableEditEventDetailsBase::createEmpty(void)
{
    UndoableEditEventDetails *returnValue;

    newPtr<UndoableEditEventDetails>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr UndoableEditEventDetailsBase::shallowCopyLocal(
    BitVector bFlags) const
{
    UndoableEditEventDetails *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const UndoableEditEventDetails *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr UndoableEditEventDetailsBase::shallowCopyDependent(
    BitVector bFlags) const
{
    UndoableEditEventDetails *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const UndoableEditEventDetails *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr UndoableEditEventDetailsBase::shallowCopy(void) const
{
    UndoableEditEventDetails *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const UndoableEditEventDetails *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}



/*------------------------- constructors ----------------------------------*/

UndoableEditEventDetailsBase::UndoableEditEventDetailsBase(void) :
    Inherited()
{
}

UndoableEditEventDetailsBase::UndoableEditEventDetailsBase(const UndoableEditEventDetailsBase &source) :
    Inherited(source)
{
}


/*-------------------------- destructors ----------------------------------*/

UndoableEditEventDetailsBase::~UndoableEditEventDetailsBase(void)
{
}




#ifdef OSG_MT_CPTR_ASPECT
void UndoableEditEventDetailsBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    UndoableEditEventDetails *pThis = static_cast<UndoableEditEventDetails *>(this);

    pThis->execSync(static_cast<UndoableEditEventDetails *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *UndoableEditEventDetailsBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    UndoableEditEventDetails *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const UndoableEditEventDetails *>(pRefAspect),
                  dynamic_cast<const UndoableEditEventDetails *>(this));

    return returnValue;
}
#endif

void UndoableEditEventDetailsBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
