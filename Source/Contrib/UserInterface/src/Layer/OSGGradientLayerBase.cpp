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
 **     class GradientLayer!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGGradientLayerBase.h"
#include "OSGGradientLayer.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::GradientLayer
    UI Gradient Background.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Pnt2f           GradientLayerBase::_sfStartPosition
    
*/

/*! \var Pnt2f           GradientLayerBase::_sfEndPosition
    
*/

/*! \var Color4f         GradientLayerBase::_mfColors
    
*/

/*! \var Real32          GradientLayerBase::_mfStops
    
*/

/*! \var UInt32          GradientLayerBase::_sfSpreadMethod
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<GradientLayer *>::_type("GradientLayerPtr", "LayerPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(GradientLayer *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           GradientLayer *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           GradientLayer *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void GradientLayerBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFPnt2f::Description(
        SFPnt2f::getClassType(),
        "StartPosition",
        "",
        StartPositionFieldId, StartPositionFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&GradientLayer::editHandleStartPosition),
        static_cast<FieldGetMethodSig >(&GradientLayer::getHandleStartPosition));

    oType.addInitialDesc(pDesc);


    pDesc = new SFPnt2f::Description(
        SFPnt2f::getClassType(),
        "EndPosition",
        "",
        EndPositionFieldId, EndPositionFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&GradientLayer::editHandleEndPosition),
        static_cast<FieldGetMethodSig >(&GradientLayer::getHandleEndPosition));

    oType.addInitialDesc(pDesc);


    pDesc = new MFColor4f::Description(
        MFColor4f::getClassType(),
        "Colors",
        "",
        ColorsFieldId, ColorsFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&GradientLayer::editHandleColors),
        static_cast<FieldGetMethodSig >(&GradientLayer::getHandleColors));

    oType.addInitialDesc(pDesc);


    pDesc = new MFReal32::Description(
        MFReal32::getClassType(),
        "Stops",
        "",
        StopsFieldId, StopsFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&GradientLayer::editHandleStops),
        static_cast<FieldGetMethodSig >(&GradientLayer::getHandleStops));

    oType.addInitialDesc(pDesc);


    pDesc = new SFUInt32::Description(
        SFUInt32::getClassType(),
        "SpreadMethod",
        "",
        SpreadMethodFieldId, SpreadMethodFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&GradientLayer::editHandleSpreadMethod),
        static_cast<FieldGetMethodSig >(&GradientLayer::getHandleSpreadMethod));

    oType.addInitialDesc(pDesc);

}


GradientLayerBase::TypeObject GradientLayerBase::_type(
    GradientLayerBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&GradientLayerBase::createEmptyLocal),
    GradientLayer::initMethod,
    GradientLayer::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&GradientLayer::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"GradientLayer\"\n"
    "\tparent=\"Layer\"\n"
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
    "UI Gradient Background.\n"
    "\t<Field\n"
    "\t\tname=\"StartPosition\"\n"
    "\t\ttype=\"Pnt2f\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"0.0,0.0\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"EndPosition\"\n"
    "\t\ttype=\"Pnt2f\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"1.0,0.0\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"Colors\"\n"
    "\t\ttype=\"Color4f\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"multi\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"Stops\"\n"
    "\t\ttype=\"Real32\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"multi\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"SpreadMethod\"\n"
    "\t\ttype=\"UInt32\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"GradientLayer::SPREAD_PAD\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "UI Gradient Background.\n"
    );


/*------------------------------ get -----------------------------------*/

FieldContainerType &GradientLayerBase::getType(void)
{
    return _type;
}

const FieldContainerType &GradientLayerBase::getType(void) const
{
    return _type;
}

UInt32 GradientLayerBase::getContainerSize(void) const
{
    return sizeof(GradientLayer);
}

/*------------------------- decorator get ------------------------------*/


SFPnt2f *GradientLayerBase::editSFStartPosition(void)
{
    editSField(StartPositionFieldMask);

    return &_sfStartPosition;
}

const SFPnt2f *GradientLayerBase::getSFStartPosition(void) const
{
    return &_sfStartPosition;
}


SFPnt2f *GradientLayerBase::editSFEndPosition(void)
{
    editSField(EndPositionFieldMask);

    return &_sfEndPosition;
}

const SFPnt2f *GradientLayerBase::getSFEndPosition(void) const
{
    return &_sfEndPosition;
}


MFColor4f *GradientLayerBase::editMFColors(void)
{
    editMField(ColorsFieldMask, _mfColors);

    return &_mfColors;
}

const MFColor4f *GradientLayerBase::getMFColors(void) const
{
    return &_mfColors;
}


MFReal32 *GradientLayerBase::editMFStops(void)
{
    editMField(StopsFieldMask, _mfStops);

    return &_mfStops;
}

const MFReal32 *GradientLayerBase::getMFStops(void) const
{
    return &_mfStops;
}


SFUInt32 *GradientLayerBase::editSFSpreadMethod(void)
{
    editSField(SpreadMethodFieldMask);

    return &_sfSpreadMethod;
}

const SFUInt32 *GradientLayerBase::getSFSpreadMethod(void) const
{
    return &_sfSpreadMethod;
}






/*------------------------------ access -----------------------------------*/

UInt32 GradientLayerBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (StartPositionFieldMask & whichField))
    {
        returnValue += _sfStartPosition.getBinSize();
    }
    if(FieldBits::NoField != (EndPositionFieldMask & whichField))
    {
        returnValue += _sfEndPosition.getBinSize();
    }
    if(FieldBits::NoField != (ColorsFieldMask & whichField))
    {
        returnValue += _mfColors.getBinSize();
    }
    if(FieldBits::NoField != (StopsFieldMask & whichField))
    {
        returnValue += _mfStops.getBinSize();
    }
    if(FieldBits::NoField != (SpreadMethodFieldMask & whichField))
    {
        returnValue += _sfSpreadMethod.getBinSize();
    }

    return returnValue;
}

void GradientLayerBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (StartPositionFieldMask & whichField))
    {
        _sfStartPosition.copyToBin(pMem);
    }
    if(FieldBits::NoField != (EndPositionFieldMask & whichField))
    {
        _sfEndPosition.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ColorsFieldMask & whichField))
    {
        _mfColors.copyToBin(pMem);
    }
    if(FieldBits::NoField != (StopsFieldMask & whichField))
    {
        _mfStops.copyToBin(pMem);
    }
    if(FieldBits::NoField != (SpreadMethodFieldMask & whichField))
    {
        _sfSpreadMethod.copyToBin(pMem);
    }
}

void GradientLayerBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (StartPositionFieldMask & whichField))
    {
        _sfStartPosition.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (EndPositionFieldMask & whichField))
    {
        _sfEndPosition.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ColorsFieldMask & whichField))
    {
        _mfColors.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (StopsFieldMask & whichField))
    {
        _mfStops.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (SpreadMethodFieldMask & whichField))
    {
        _sfSpreadMethod.copyFromBin(pMem);
    }
}

//! create a new instance of the class
GradientLayerTransitPtr GradientLayerBase::createLocal(BitVector bFlags)
{
    GradientLayerTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<GradientLayer>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
GradientLayerTransitPtr GradientLayerBase::createDependent(BitVector bFlags)
{
    GradientLayerTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<GradientLayer>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
GradientLayerTransitPtr GradientLayerBase::create(void)
{
    GradientLayerTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<GradientLayer>(tmpPtr);
    }

    return fc;
}

GradientLayer *GradientLayerBase::createEmptyLocal(BitVector bFlags)
{
    GradientLayer *returnValue;

    newPtr<GradientLayer>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
GradientLayer *GradientLayerBase::createEmpty(void)
{
    GradientLayer *returnValue;

    newPtr<GradientLayer>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr GradientLayerBase::shallowCopyLocal(
    BitVector bFlags) const
{
    GradientLayer *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const GradientLayer *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr GradientLayerBase::shallowCopyDependent(
    BitVector bFlags) const
{
    GradientLayer *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const GradientLayer *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr GradientLayerBase::shallowCopy(void) const
{
    GradientLayer *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const GradientLayer *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

GradientLayerBase::GradientLayerBase(void) :
    Inherited(),
    _sfStartPosition          (Pnt2f(0.0,0.0)),
    _sfEndPosition            (Pnt2f(1.0,0.0)),
    _mfColors                 (),
    _mfStops                  (),
    _sfSpreadMethod           (UInt32(GradientLayer::SPREAD_PAD))
{
}

GradientLayerBase::GradientLayerBase(const GradientLayerBase &source) :
    Inherited(source),
    _sfStartPosition          (source._sfStartPosition          ),
    _sfEndPosition            (source._sfEndPosition            ),
    _mfColors                 (source._mfColors                 ),
    _mfStops                  (source._mfStops                  ),
    _sfSpreadMethod           (source._sfSpreadMethod           )
{
}


/*-------------------------- destructors ----------------------------------*/

GradientLayerBase::~GradientLayerBase(void)
{
}


GetFieldHandlePtr GradientLayerBase::getHandleStartPosition   (void) const
{
    SFPnt2f::GetHandlePtr returnValue(
        new  SFPnt2f::GetHandle(
             &_sfStartPosition,
             this->getType().getFieldDesc(StartPositionFieldId),
             const_cast<GradientLayerBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr GradientLayerBase::editHandleStartPosition  (void)
{
    SFPnt2f::EditHandlePtr returnValue(
        new  SFPnt2f::EditHandle(
             &_sfStartPosition,
             this->getType().getFieldDesc(StartPositionFieldId),
             this));


    editSField(StartPositionFieldMask);

    return returnValue;
}

GetFieldHandlePtr GradientLayerBase::getHandleEndPosition     (void) const
{
    SFPnt2f::GetHandlePtr returnValue(
        new  SFPnt2f::GetHandle(
             &_sfEndPosition,
             this->getType().getFieldDesc(EndPositionFieldId),
             const_cast<GradientLayerBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr GradientLayerBase::editHandleEndPosition    (void)
{
    SFPnt2f::EditHandlePtr returnValue(
        new  SFPnt2f::EditHandle(
             &_sfEndPosition,
             this->getType().getFieldDesc(EndPositionFieldId),
             this));


    editSField(EndPositionFieldMask);

    return returnValue;
}

GetFieldHandlePtr GradientLayerBase::getHandleColors          (void) const
{
    MFColor4f::GetHandlePtr returnValue(
        new  MFColor4f::GetHandle(
             &_mfColors,
             this->getType().getFieldDesc(ColorsFieldId),
             const_cast<GradientLayerBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr GradientLayerBase::editHandleColors         (void)
{
    MFColor4f::EditHandlePtr returnValue(
        new  MFColor4f::EditHandle(
             &_mfColors,
             this->getType().getFieldDesc(ColorsFieldId),
             this));


    editMField(ColorsFieldMask, _mfColors);

    return returnValue;
}

GetFieldHandlePtr GradientLayerBase::getHandleStops           (void) const
{
    MFReal32::GetHandlePtr returnValue(
        new  MFReal32::GetHandle(
             &_mfStops,
             this->getType().getFieldDesc(StopsFieldId),
             const_cast<GradientLayerBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr GradientLayerBase::editHandleStops          (void)
{
    MFReal32::EditHandlePtr returnValue(
        new  MFReal32::EditHandle(
             &_mfStops,
             this->getType().getFieldDesc(StopsFieldId),
             this));


    editMField(StopsFieldMask, _mfStops);

    return returnValue;
}

GetFieldHandlePtr GradientLayerBase::getHandleSpreadMethod    (void) const
{
    SFUInt32::GetHandlePtr returnValue(
        new  SFUInt32::GetHandle(
             &_sfSpreadMethod,
             this->getType().getFieldDesc(SpreadMethodFieldId),
             const_cast<GradientLayerBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr GradientLayerBase::editHandleSpreadMethod   (void)
{
    SFUInt32::EditHandlePtr returnValue(
        new  SFUInt32::EditHandle(
             &_sfSpreadMethod,
             this->getType().getFieldDesc(SpreadMethodFieldId),
             this));


    editSField(SpreadMethodFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void GradientLayerBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    GradientLayer *pThis = static_cast<GradientLayer *>(this);

    pThis->execSync(static_cast<GradientLayer *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *GradientLayerBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    GradientLayer *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const GradientLayer *>(pRefAspect),
                  dynamic_cast<const GradientLayer *>(this));

    return returnValue;
}
#endif

void GradientLayerBase::resolveLinks(void)
{
    Inherited::resolveLinks();

#ifdef OSG_MT_CPTR_ASPECT
    AspectOffsetStore oOffsets;

    _pAspectStore->fillOffsetArray(oOffsets, this);
#endif

#ifdef OSG_MT_CPTR_ASPECT
    _mfColors.terminateShare(Thread::getCurrentAspect(),
                                      oOffsets);
#endif
#ifdef OSG_MT_CPTR_ASPECT
    _mfStops.terminateShare(Thread::getCurrentAspect(),
                                      oOffsets);
#endif
}


OSG_END_NAMESPACE
