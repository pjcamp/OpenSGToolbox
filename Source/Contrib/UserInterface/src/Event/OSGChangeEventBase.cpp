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
 **     class ChangeEvent!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGChangeEventBase.h"
#include "OSGChangeEvent.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::ChangeEvent
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<ChangeEvent *>::_type("ChangeEventPtr", "EventPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(ChangeEvent *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           ChangeEvent *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           ChangeEvent *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void ChangeEventBase::classDescInserter(TypeObject &oType)
{
}


ChangeEventBase::TypeObject ChangeEventBase::_type(
    ChangeEventBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&ChangeEventBase::createEmptyLocal),
    ChangeEvent::initMethod,
    ChangeEvent::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&ChangeEvent::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"ChangeEvent\"\n"
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
    "</FieldContainer>\n",
    ""
    );


/*------------------------------ get -----------------------------------*/

FieldContainerType &ChangeEventBase::getType(void)
{
    return _type;
}

const FieldContainerType &ChangeEventBase::getType(void) const
{
    return _type;
}

UInt32 ChangeEventBase::getContainerSize(void) const
{
    return sizeof(ChangeEvent);
}

/*------------------------- decorator get ------------------------------*/






/*------------------------------ access -----------------------------------*/

UInt32 ChangeEventBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);


    return returnValue;
}

void ChangeEventBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

}

void ChangeEventBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

}

//! create a new instance of the class
ChangeEventTransitPtr ChangeEventBase::createLocal(BitVector bFlags)
{
    ChangeEventTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<ChangeEvent>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
ChangeEventTransitPtr ChangeEventBase::createDependent(BitVector bFlags)
{
    ChangeEventTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<ChangeEvent>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
ChangeEventTransitPtr ChangeEventBase::create(void)
{
    ChangeEventTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<ChangeEvent>(tmpPtr);
    }

    return fc;
}

ChangeEvent *ChangeEventBase::createEmptyLocal(BitVector bFlags)
{
    ChangeEvent *returnValue;

    newPtr<ChangeEvent>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
ChangeEvent *ChangeEventBase::createEmpty(void)
{
    ChangeEvent *returnValue;

    newPtr<ChangeEvent>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr ChangeEventBase::shallowCopyLocal(
    BitVector bFlags) const
{
    ChangeEvent *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const ChangeEvent *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr ChangeEventBase::shallowCopyDependent(
    BitVector bFlags) const
{
    ChangeEvent *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const ChangeEvent *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr ChangeEventBase::shallowCopy(void) const
{
    ChangeEvent *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const ChangeEvent *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

ChangeEventBase::ChangeEventBase(void) :
    Inherited()
{
}

ChangeEventBase::ChangeEventBase(const ChangeEventBase &source) :
    Inherited(source)
{
}


/*-------------------------- destructors ----------------------------------*/

ChangeEventBase::~ChangeEventBase(void)
{
}



#ifdef OSG_MT_CPTR_ASPECT
void ChangeEventBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    ChangeEvent *pThis = static_cast<ChangeEvent *>(this);

    pThis->execSync(static_cast<ChangeEvent *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *ChangeEventBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    ChangeEvent *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const ChangeEvent *>(pRefAspect),
                  dynamic_cast<const ChangeEvent *>(this));

    return returnValue;
}
#endif

void ChangeEventBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
