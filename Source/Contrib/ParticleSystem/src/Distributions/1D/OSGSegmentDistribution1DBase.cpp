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
 **     class SegmentDistribution1D!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGSegmentDistribution1DBase.h"
#include "OSGSegmentDistribution1D.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::SegmentDistribution1D
    An SegmentDistribution1D.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Vec2f           SegmentDistribution1DBase::_sfSegment
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<SegmentDistribution1D *>::_type("SegmentDistribution1DPtr", "Distribution1DPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(SegmentDistribution1D *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           SegmentDistribution1D *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           SegmentDistribution1D *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void SegmentDistribution1DBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFVec2f::Description(
        SFVec2f::getClassType(),
        "Segment",
        "",
        SegmentFieldId, SegmentFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SegmentDistribution1D::editHandleSegment),
        static_cast<FieldGetMethodSig >(&SegmentDistribution1D::getHandleSegment));

    oType.addInitialDesc(pDesc);

}


SegmentDistribution1DBase::TypeObject SegmentDistribution1DBase::_type(
    SegmentDistribution1DBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&SegmentDistribution1DBase::createEmptyLocal),
    SegmentDistribution1D::initMethod,
    SegmentDistribution1D::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&SegmentDistribution1D::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"SegmentDistribution1D\"\n"
    "\tparent=\"Distribution1D\"\n"
    "    library=\"ContribParticleSystem\"\n"
    "    pointerfieldtypes=\"both\"\n"
    "\tstructure=\"concrete\"\n"
    "    systemcomponent=\"true\"\n"
    "    parentsystemcomponent=\"true\"\n"
    "    decoratable=\"false\"\n"
    "    useLocalIncludes=\"false\"\n"
    "    isNodeCore=\"false\"\n"
    "    authors=\"David Kabala (djkabala@gmail.com)                             \"\n"
    ">\n"
    "An SegmentDistribution1D.\n"
    "\t<Field\n"
    "\t\tname=\"Segment\"\n"
    "\t\ttype=\"Vec2f\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"0.0,1.0\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "An SegmentDistribution1D.\n"
    );


/*------------------------------ get -----------------------------------*/

FieldContainerType &SegmentDistribution1DBase::getType(void)
{
    return _type;
}

const FieldContainerType &SegmentDistribution1DBase::getType(void) const
{
    return _type;
}

UInt32 SegmentDistribution1DBase::getContainerSize(void) const
{
    return sizeof(SegmentDistribution1D);
}

/*------------------------- decorator get ------------------------------*/


SFVec2f *SegmentDistribution1DBase::editSFSegment(void)
{
    editSField(SegmentFieldMask);

    return &_sfSegment;
}

const SFVec2f *SegmentDistribution1DBase::getSFSegment(void) const
{
    return &_sfSegment;
}






/*------------------------------ access -----------------------------------*/

UInt32 SegmentDistribution1DBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (SegmentFieldMask & whichField))
    {
        returnValue += _sfSegment.getBinSize();
    }

    return returnValue;
}

void SegmentDistribution1DBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (SegmentFieldMask & whichField))
    {
        _sfSegment.copyToBin(pMem);
    }
}

void SegmentDistribution1DBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (SegmentFieldMask & whichField))
    {
        _sfSegment.copyFromBin(pMem);
    }
}

//! create a new instance of the class
SegmentDistribution1DTransitPtr SegmentDistribution1DBase::createLocal(BitVector bFlags)
{
    SegmentDistribution1DTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<SegmentDistribution1D>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
SegmentDistribution1DTransitPtr SegmentDistribution1DBase::createDependent(BitVector bFlags)
{
    SegmentDistribution1DTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<SegmentDistribution1D>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
SegmentDistribution1DTransitPtr SegmentDistribution1DBase::create(void)
{
    SegmentDistribution1DTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<SegmentDistribution1D>(tmpPtr);
    }

    return fc;
}

SegmentDistribution1D *SegmentDistribution1DBase::createEmptyLocal(BitVector bFlags)
{
    SegmentDistribution1D *returnValue;

    newPtr<SegmentDistribution1D>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
SegmentDistribution1D *SegmentDistribution1DBase::createEmpty(void)
{
    SegmentDistribution1D *returnValue;

    newPtr<SegmentDistribution1D>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr SegmentDistribution1DBase::shallowCopyLocal(
    BitVector bFlags) const
{
    SegmentDistribution1D *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const SegmentDistribution1D *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr SegmentDistribution1DBase::shallowCopyDependent(
    BitVector bFlags) const
{
    SegmentDistribution1D *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const SegmentDistribution1D *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr SegmentDistribution1DBase::shallowCopy(void) const
{
    SegmentDistribution1D *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const SegmentDistribution1D *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

SegmentDistribution1DBase::SegmentDistribution1DBase(void) :
    Inherited(),
    _sfSegment                (Vec2f(0.0,1.0))
{
}

SegmentDistribution1DBase::SegmentDistribution1DBase(const SegmentDistribution1DBase &source) :
    Inherited(source),
    _sfSegment                (source._sfSegment                )
{
}


/*-------------------------- destructors ----------------------------------*/

SegmentDistribution1DBase::~SegmentDistribution1DBase(void)
{
}


GetFieldHandlePtr SegmentDistribution1DBase::getHandleSegment         (void) const
{
    SFVec2f::GetHandlePtr returnValue(
        new  SFVec2f::GetHandle(
             &_sfSegment,
             this->getType().getFieldDesc(SegmentFieldId),
             const_cast<SegmentDistribution1DBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SegmentDistribution1DBase::editHandleSegment        (void)
{
    SFVec2f::EditHandlePtr returnValue(
        new  SFVec2f::EditHandle(
             &_sfSegment,
             this->getType().getFieldDesc(SegmentFieldId),
             this));


    editSField(SegmentFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void SegmentDistribution1DBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    SegmentDistribution1D *pThis = static_cast<SegmentDistribution1D *>(this);

    pThis->execSync(static_cast<SegmentDistribution1D *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *SegmentDistribution1DBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    SegmentDistribution1D *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const SegmentDistribution1D *>(pRefAspect),
                  dynamic_cast<const SegmentDistribution1D *>(this));

    return returnValue;
}
#endif

void SegmentDistribution1DBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE