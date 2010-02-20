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
 **     class TextEvent!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGTextEventBase.h"
#include "OSGTextEvent.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::TextEvent
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<TextEvent *>::_type("TextEventPtr", "EventPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(TextEvent *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           TextEvent *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           TextEvent *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void TextEventBase::classDescInserter(TypeObject &oType)
{
}


TextEventBase::TypeObject TextEventBase::_type(
    TextEventBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&TextEventBase::createEmptyLocal),
    TextEvent::initMethod,
    TextEvent::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&TextEvent::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"TextEvent\"\n"
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

FieldContainerType &TextEventBase::getType(void)
{
    return _type;
}

const FieldContainerType &TextEventBase::getType(void) const
{
    return _type;
}

UInt32 TextEventBase::getContainerSize(void) const
{
    return sizeof(TextEvent);
}

/*------------------------- decorator get ------------------------------*/






/*------------------------------ access -----------------------------------*/

UInt32 TextEventBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);


    return returnValue;
}

void TextEventBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

}

void TextEventBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

}

//! create a new instance of the class
TextEventTransitPtr TextEventBase::createLocal(BitVector bFlags)
{
    TextEventTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<TextEvent>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
TextEventTransitPtr TextEventBase::createDependent(BitVector bFlags)
{
    TextEventTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<TextEvent>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
TextEventTransitPtr TextEventBase::create(void)
{
    TextEventTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<TextEvent>(tmpPtr);
    }

    return fc;
}

TextEvent *TextEventBase::createEmptyLocal(BitVector bFlags)
{
    TextEvent *returnValue;

    newPtr<TextEvent>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
TextEvent *TextEventBase::createEmpty(void)
{
    TextEvent *returnValue;

    newPtr<TextEvent>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr TextEventBase::shallowCopyLocal(
    BitVector bFlags) const
{
    TextEvent *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const TextEvent *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr TextEventBase::shallowCopyDependent(
    BitVector bFlags) const
{
    TextEvent *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const TextEvent *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr TextEventBase::shallowCopy(void) const
{
    TextEvent *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const TextEvent *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

TextEventBase::TextEventBase(void) :
    Inherited()
{
}

TextEventBase::TextEventBase(const TextEventBase &source) :
    Inherited(source)
{
}


/*-------------------------- destructors ----------------------------------*/

TextEventBase::~TextEventBase(void)
{
}



#ifdef OSG_MT_CPTR_ASPECT
void TextEventBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    TextEvent *pThis = static_cast<TextEvent *>(this);

    pThis->execSync(static_cast<TextEvent *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *TextEventBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    TextEvent *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const TextEvent *>(pRefAspect),
                  dynamic_cast<const TextEvent *>(this));

    return returnValue;
}
#endif

void TextEventBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
