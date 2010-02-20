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
 **     class FlowLayoutConstraints!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGFlowLayoutConstraintsBase.h"
#include "OSGFlowLayoutConstraints.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::FlowLayoutConstraints
    A UI FlowLayout.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<FlowLayoutConstraints *>::_type("FlowLayoutConstraintsPtr", "LayoutConstraintsPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(FlowLayoutConstraints *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           FlowLayoutConstraints *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           FlowLayoutConstraints *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void FlowLayoutConstraintsBase::classDescInserter(TypeObject &oType)
{
}


FlowLayoutConstraintsBase::TypeObject FlowLayoutConstraintsBase::_type(
    FlowLayoutConstraintsBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&FlowLayoutConstraintsBase::createEmptyLocal),
    FlowLayoutConstraints::initMethod,
    FlowLayoutConstraints::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&FlowLayoutConstraints::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"FlowLayoutConstraints\"\n"
    "\tparent=\"LayoutConstraints\"\n"
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
    "A UI FlowLayout.\n"
    "</FieldContainer>\n",
    "A UI FlowLayout.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &FlowLayoutConstraintsBase::getType(void)
{
    return _type;
}

const FieldContainerType &FlowLayoutConstraintsBase::getType(void) const
{
    return _type;
}

UInt32 FlowLayoutConstraintsBase::getContainerSize(void) const
{
    return sizeof(FlowLayoutConstraints);
}

/*------------------------- decorator get ------------------------------*/






/*------------------------------ access -----------------------------------*/

UInt32 FlowLayoutConstraintsBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);


    return returnValue;
}

void FlowLayoutConstraintsBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

}

void FlowLayoutConstraintsBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

}

//! create a new instance of the class
FlowLayoutConstraintsTransitPtr FlowLayoutConstraintsBase::createLocal(BitVector bFlags)
{
    FlowLayoutConstraintsTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<FlowLayoutConstraints>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
FlowLayoutConstraintsTransitPtr FlowLayoutConstraintsBase::createDependent(BitVector bFlags)
{
    FlowLayoutConstraintsTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<FlowLayoutConstraints>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
FlowLayoutConstraintsTransitPtr FlowLayoutConstraintsBase::create(void)
{
    FlowLayoutConstraintsTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<FlowLayoutConstraints>(tmpPtr);
    }

    return fc;
}

FlowLayoutConstraints *FlowLayoutConstraintsBase::createEmptyLocal(BitVector bFlags)
{
    FlowLayoutConstraints *returnValue;

    newPtr<FlowLayoutConstraints>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
FlowLayoutConstraints *FlowLayoutConstraintsBase::createEmpty(void)
{
    FlowLayoutConstraints *returnValue;

    newPtr<FlowLayoutConstraints>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr FlowLayoutConstraintsBase::shallowCopyLocal(
    BitVector bFlags) const
{
    FlowLayoutConstraints *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const FlowLayoutConstraints *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr FlowLayoutConstraintsBase::shallowCopyDependent(
    BitVector bFlags) const
{
    FlowLayoutConstraints *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const FlowLayoutConstraints *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr FlowLayoutConstraintsBase::shallowCopy(void) const
{
    FlowLayoutConstraints *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const FlowLayoutConstraints *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

FlowLayoutConstraintsBase::FlowLayoutConstraintsBase(void) :
    Inherited()
{
}

FlowLayoutConstraintsBase::FlowLayoutConstraintsBase(const FlowLayoutConstraintsBase &source) :
    Inherited(source)
{
}


/*-------------------------- destructors ----------------------------------*/

FlowLayoutConstraintsBase::~FlowLayoutConstraintsBase(void)
{
}



#ifdef OSG_MT_CPTR_ASPECT
void FlowLayoutConstraintsBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    FlowLayoutConstraints *pThis = static_cast<FlowLayoutConstraints *>(this);

    pThis->execSync(static_cast<FlowLayoutConstraints *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *FlowLayoutConstraintsBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    FlowLayoutConstraints *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const FlowLayoutConstraints *>(pRefAspect),
                  dynamic_cast<const FlowLayoutConstraints *>(this));

    return returnValue;
}
#endif

void FlowLayoutConstraintsBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
