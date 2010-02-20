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
 **     class OverlayLayout!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGOverlayLayoutBase.h"
#include "OSGOverlayLayout.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::OverlayLayout
    A UI OverlayLayout.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<OverlayLayout *>::_type("OverlayLayoutPtr", "LayoutPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(OverlayLayout *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           OverlayLayout *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           OverlayLayout *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void OverlayLayoutBase::classDescInserter(TypeObject &oType)
{
}


OverlayLayoutBase::TypeObject OverlayLayoutBase::_type(
    OverlayLayoutBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&OverlayLayoutBase::createEmptyLocal),
    OverlayLayout::initMethod,
    OverlayLayout::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&OverlayLayout::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"OverlayLayout\"\n"
    "\tparent=\"Layout\"\n"
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
    "A UI OverlayLayout.\n"
    "</FieldContainer>\n",
    "A UI OverlayLayout.\n"
    );


/*------------------------------ get -----------------------------------*/

FieldContainerType &OverlayLayoutBase::getType(void)
{
    return _type;
}

const FieldContainerType &OverlayLayoutBase::getType(void) const
{
    return _type;
}

UInt32 OverlayLayoutBase::getContainerSize(void) const
{
    return sizeof(OverlayLayout);
}

/*------------------------- decorator get ------------------------------*/






/*------------------------------ access -----------------------------------*/

UInt32 OverlayLayoutBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);


    return returnValue;
}

void OverlayLayoutBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

}

void OverlayLayoutBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

}

//! create a new instance of the class
OverlayLayoutTransitPtr OverlayLayoutBase::createLocal(BitVector bFlags)
{
    OverlayLayoutTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<OverlayLayout>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
OverlayLayoutTransitPtr OverlayLayoutBase::createDependent(BitVector bFlags)
{
    OverlayLayoutTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<OverlayLayout>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
OverlayLayoutTransitPtr OverlayLayoutBase::create(void)
{
    OverlayLayoutTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<OverlayLayout>(tmpPtr);
    }

    return fc;
}

OverlayLayout *OverlayLayoutBase::createEmptyLocal(BitVector bFlags)
{
    OverlayLayout *returnValue;

    newPtr<OverlayLayout>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
OverlayLayout *OverlayLayoutBase::createEmpty(void)
{
    OverlayLayout *returnValue;

    newPtr<OverlayLayout>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr OverlayLayoutBase::shallowCopyLocal(
    BitVector bFlags) const
{
    OverlayLayout *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const OverlayLayout *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr OverlayLayoutBase::shallowCopyDependent(
    BitVector bFlags) const
{
    OverlayLayout *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const OverlayLayout *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr OverlayLayoutBase::shallowCopy(void) const
{
    OverlayLayout *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const OverlayLayout *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

OverlayLayoutBase::OverlayLayoutBase(void) :
    Inherited()
{
}

OverlayLayoutBase::OverlayLayoutBase(const OverlayLayoutBase &source) :
    Inherited(source)
{
}


/*-------------------------- destructors ----------------------------------*/

OverlayLayoutBase::~OverlayLayoutBase(void)
{
}



#ifdef OSG_MT_CPTR_ASPECT
void OverlayLayoutBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    OverlayLayout *pThis = static_cast<OverlayLayout *>(this);

    pThis->execSync(static_cast<OverlayLayout *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *OverlayLayoutBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    OverlayLayout *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const OverlayLayout *>(pRefAspect),
                  dynamic_cast<const OverlayLayout *>(this));

    return returnValue;
}
#endif

void OverlayLayoutBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
