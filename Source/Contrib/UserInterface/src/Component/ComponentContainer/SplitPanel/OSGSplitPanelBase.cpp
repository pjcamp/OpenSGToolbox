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
 **     class SplitPanel!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"



#include "OSGComponent.h"               // MinComponent Class
#include "OSGUIDrawObjectCanvas.h"      // DividerDrawObject Class

#include "OSGSplitPanelBase.h"
#include "OSGSplitPanel.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::SplitPanel
    A UI Split Panel.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Component *     SplitPanelBase::_sfMinComponent
    
*/

/*! \var Component *     SplitPanelBase::_sfMaxComponent
    
*/

/*! \var UInt32          SplitPanelBase::_sfDividerSize
    
*/

/*! \var Real32          SplitPanelBase::_sfDividerPosition
    
*/

/*! \var Real32          SplitPanelBase::_sfMinDividerPosition
    
*/

/*! \var Real32          SplitPanelBase::_sfMaxDividerPosition
    
*/

/*! \var UIDrawObjectCanvas * SplitPanelBase::_sfDividerDrawObject
    
*/

/*! \var bool            SplitPanelBase::_sfExpandable
    
*/

/*! \var UInt32          SplitPanelBase::_sfOrientation
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<SplitPanel *>::_type("SplitPanelPtr", "ComponentContainerPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(SplitPanel *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           SplitPanel *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           SplitPanel *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void SplitPanelBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFUnrecComponentPtr::Description(
        SFUnrecComponentPtr::getClassType(),
        "MinComponent",
        "",
        MinComponentFieldId, MinComponentFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SplitPanel::editHandleMinComponent),
        static_cast<FieldGetMethodSig >(&SplitPanel::getHandleMinComponent));

    oType.addInitialDesc(pDesc);


    pDesc = new SFUnrecComponentPtr::Description(
        SFUnrecComponentPtr::getClassType(),
        "MaxComponent",
        "",
        MaxComponentFieldId, MaxComponentFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SplitPanel::editHandleMaxComponent),
        static_cast<FieldGetMethodSig >(&SplitPanel::getHandleMaxComponent));

    oType.addInitialDesc(pDesc);


    pDesc = new SFUInt32::Description(
        SFUInt32::getClassType(),
        "DividerSize",
        "",
        DividerSizeFieldId, DividerSizeFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SplitPanel::editHandleDividerSize),
        static_cast<FieldGetMethodSig >(&SplitPanel::getHandleDividerSize));

    oType.addInitialDesc(pDesc);


    pDesc = new SFReal32::Description(
        SFReal32::getClassType(),
        "DividerPosition",
        "",
        DividerPositionFieldId, DividerPositionFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SplitPanel::editHandleDividerPosition),
        static_cast<FieldGetMethodSig >(&SplitPanel::getHandleDividerPosition));

    oType.addInitialDesc(pDesc);


    pDesc = new SFReal32::Description(
        SFReal32::getClassType(),
        "MinDividerPosition",
        "",
        MinDividerPositionFieldId, MinDividerPositionFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SplitPanel::editHandleMinDividerPosition),
        static_cast<FieldGetMethodSig >(&SplitPanel::getHandleMinDividerPosition));

    oType.addInitialDesc(pDesc);


    pDesc = new SFReal32::Description(
        SFReal32::getClassType(),
        "MaxDividerPosition",
        "",
        MaxDividerPositionFieldId, MaxDividerPositionFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SplitPanel::editHandleMaxDividerPosition),
        static_cast<FieldGetMethodSig >(&SplitPanel::getHandleMaxDividerPosition));

    oType.addInitialDesc(pDesc);


    pDesc = new SFUnrecUIDrawObjectCanvasPtr::Description(
        SFUnrecUIDrawObjectCanvasPtr::getClassType(),
        "DividerDrawObject",
        "",
        DividerDrawObjectFieldId, DividerDrawObjectFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SplitPanel::editHandleDividerDrawObject),
        static_cast<FieldGetMethodSig >(&SplitPanel::getHandleDividerDrawObject));

    oType.addInitialDesc(pDesc);


    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "Expandable",
        "",
        ExpandableFieldId, ExpandableFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SplitPanel::editHandleExpandable),
        static_cast<FieldGetMethodSig >(&SplitPanel::getHandleExpandable));

    oType.addInitialDesc(pDesc);


    pDesc = new SFUInt32::Description(
        SFUInt32::getClassType(),
        "Orientation",
        "",
        OrientationFieldId, OrientationFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SplitPanel::editHandleOrientation),
        static_cast<FieldGetMethodSig >(&SplitPanel::getHandleOrientation));

    oType.addInitialDesc(pDesc);

}


SplitPanelBase::TypeObject SplitPanelBase::_type(
    SplitPanelBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&SplitPanelBase::createEmptyLocal),
    SplitPanel::initMethod,
    SplitPanel::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&SplitPanel::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"SplitPanel\"\n"
    "\tparent=\"ComponentContainer\"\n"
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
    "A UI Split Panel.\n"
    "\t<Field\n"
    "\t\tname=\"MinComponent\"\n"
    "\t\ttype=\"Component\"\n"
    "\t\tcategory=\"pointer\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"NULL\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"MaxComponent\"\n"
    "\t\ttype=\"Component\"\n"
    "\t\tcategory=\"pointer\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"NULL\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"DividerSize\"\n"
    "\t\ttype=\"UInt32\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"3\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"DividerPosition\"\n"
    "\t\ttype=\"Real32\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"0.5\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"MinDividerPosition\"\n"
    "\t\ttype=\"Real32\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"0.0\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"MaxDividerPosition\"\n"
    "\t\ttype=\"Real32\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"1.0\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"DividerDrawObject\"\n"
    "\t\ttype=\"UIDrawObjectCanvas\"\n"
    "\t\tcategory=\"pointer\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"NULL\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"Expandable\"\n"
    "\t\ttype=\"bool\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"true\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"Orientation\"\n"
    "\t\ttype=\"UInt32\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"SplitPanel::HORIZONTAL_ORIENTATION\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "A UI Split Panel.\n"
    );


/*------------------------------ get -----------------------------------*/

FieldContainerType &SplitPanelBase::getType(void)
{
    return _type;
}

const FieldContainerType &SplitPanelBase::getType(void) const
{
    return _type;
}

UInt32 SplitPanelBase::getContainerSize(void) const
{
    return sizeof(SplitPanel);
}

/*------------------------- decorator get ------------------------------*/


//! Get the SplitPanel::_sfMinComponent field.
const SFUnrecComponentPtr *SplitPanelBase::getSFMinComponent(void) const
{
    return &_sfMinComponent;
}

SFUnrecComponentPtr *SplitPanelBase::editSFMinComponent   (void)
{
    editSField(MinComponentFieldMask);

    return &_sfMinComponent;
}

//! Get the SplitPanel::_sfMaxComponent field.
const SFUnrecComponentPtr *SplitPanelBase::getSFMaxComponent(void) const
{
    return &_sfMaxComponent;
}

SFUnrecComponentPtr *SplitPanelBase::editSFMaxComponent   (void)
{
    editSField(MaxComponentFieldMask);

    return &_sfMaxComponent;
}

SFUInt32 *SplitPanelBase::editSFDividerSize(void)
{
    editSField(DividerSizeFieldMask);

    return &_sfDividerSize;
}

const SFUInt32 *SplitPanelBase::getSFDividerSize(void) const
{
    return &_sfDividerSize;
}


SFReal32 *SplitPanelBase::editSFDividerPosition(void)
{
    editSField(DividerPositionFieldMask);

    return &_sfDividerPosition;
}

const SFReal32 *SplitPanelBase::getSFDividerPosition(void) const
{
    return &_sfDividerPosition;
}


SFReal32 *SplitPanelBase::editSFMinDividerPosition(void)
{
    editSField(MinDividerPositionFieldMask);

    return &_sfMinDividerPosition;
}

const SFReal32 *SplitPanelBase::getSFMinDividerPosition(void) const
{
    return &_sfMinDividerPosition;
}


SFReal32 *SplitPanelBase::editSFMaxDividerPosition(void)
{
    editSField(MaxDividerPositionFieldMask);

    return &_sfMaxDividerPosition;
}

const SFReal32 *SplitPanelBase::getSFMaxDividerPosition(void) const
{
    return &_sfMaxDividerPosition;
}


//! Get the SplitPanel::_sfDividerDrawObject field.
const SFUnrecUIDrawObjectCanvasPtr *SplitPanelBase::getSFDividerDrawObject(void) const
{
    return &_sfDividerDrawObject;
}

SFUnrecUIDrawObjectCanvasPtr *SplitPanelBase::editSFDividerDrawObject(void)
{
    editSField(DividerDrawObjectFieldMask);

    return &_sfDividerDrawObject;
}

SFBool *SplitPanelBase::editSFExpandable(void)
{
    editSField(ExpandableFieldMask);

    return &_sfExpandable;
}

const SFBool *SplitPanelBase::getSFExpandable(void) const
{
    return &_sfExpandable;
}


SFUInt32 *SplitPanelBase::editSFOrientation(void)
{
    editSField(OrientationFieldMask);

    return &_sfOrientation;
}

const SFUInt32 *SplitPanelBase::getSFOrientation(void) const
{
    return &_sfOrientation;
}






/*------------------------------ access -----------------------------------*/

UInt32 SplitPanelBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (MinComponentFieldMask & whichField))
    {
        returnValue += _sfMinComponent.getBinSize();
    }
    if(FieldBits::NoField != (MaxComponentFieldMask & whichField))
    {
        returnValue += _sfMaxComponent.getBinSize();
    }
    if(FieldBits::NoField != (DividerSizeFieldMask & whichField))
    {
        returnValue += _sfDividerSize.getBinSize();
    }
    if(FieldBits::NoField != (DividerPositionFieldMask & whichField))
    {
        returnValue += _sfDividerPosition.getBinSize();
    }
    if(FieldBits::NoField != (MinDividerPositionFieldMask & whichField))
    {
        returnValue += _sfMinDividerPosition.getBinSize();
    }
    if(FieldBits::NoField != (MaxDividerPositionFieldMask & whichField))
    {
        returnValue += _sfMaxDividerPosition.getBinSize();
    }
    if(FieldBits::NoField != (DividerDrawObjectFieldMask & whichField))
    {
        returnValue += _sfDividerDrawObject.getBinSize();
    }
    if(FieldBits::NoField != (ExpandableFieldMask & whichField))
    {
        returnValue += _sfExpandable.getBinSize();
    }
    if(FieldBits::NoField != (OrientationFieldMask & whichField))
    {
        returnValue += _sfOrientation.getBinSize();
    }

    return returnValue;
}

void SplitPanelBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (MinComponentFieldMask & whichField))
    {
        _sfMinComponent.copyToBin(pMem);
    }
    if(FieldBits::NoField != (MaxComponentFieldMask & whichField))
    {
        _sfMaxComponent.copyToBin(pMem);
    }
    if(FieldBits::NoField != (DividerSizeFieldMask & whichField))
    {
        _sfDividerSize.copyToBin(pMem);
    }
    if(FieldBits::NoField != (DividerPositionFieldMask & whichField))
    {
        _sfDividerPosition.copyToBin(pMem);
    }
    if(FieldBits::NoField != (MinDividerPositionFieldMask & whichField))
    {
        _sfMinDividerPosition.copyToBin(pMem);
    }
    if(FieldBits::NoField != (MaxDividerPositionFieldMask & whichField))
    {
        _sfMaxDividerPosition.copyToBin(pMem);
    }
    if(FieldBits::NoField != (DividerDrawObjectFieldMask & whichField))
    {
        _sfDividerDrawObject.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ExpandableFieldMask & whichField))
    {
        _sfExpandable.copyToBin(pMem);
    }
    if(FieldBits::NoField != (OrientationFieldMask & whichField))
    {
        _sfOrientation.copyToBin(pMem);
    }
}

void SplitPanelBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (MinComponentFieldMask & whichField))
    {
        _sfMinComponent.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (MaxComponentFieldMask & whichField))
    {
        _sfMaxComponent.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (DividerSizeFieldMask & whichField))
    {
        _sfDividerSize.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (DividerPositionFieldMask & whichField))
    {
        _sfDividerPosition.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (MinDividerPositionFieldMask & whichField))
    {
        _sfMinDividerPosition.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (MaxDividerPositionFieldMask & whichField))
    {
        _sfMaxDividerPosition.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (DividerDrawObjectFieldMask & whichField))
    {
        _sfDividerDrawObject.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ExpandableFieldMask & whichField))
    {
        _sfExpandable.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (OrientationFieldMask & whichField))
    {
        _sfOrientation.copyFromBin(pMem);
    }
}

//! create a new instance of the class
SplitPanelTransitPtr SplitPanelBase::createLocal(BitVector bFlags)
{
    SplitPanelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<SplitPanel>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
SplitPanelTransitPtr SplitPanelBase::createDependent(BitVector bFlags)
{
    SplitPanelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<SplitPanel>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
SplitPanelTransitPtr SplitPanelBase::create(void)
{
    SplitPanelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<SplitPanel>(tmpPtr);
    }

    return fc;
}

SplitPanel *SplitPanelBase::createEmptyLocal(BitVector bFlags)
{
    SplitPanel *returnValue;

    newPtr<SplitPanel>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
SplitPanel *SplitPanelBase::createEmpty(void)
{
    SplitPanel *returnValue;

    newPtr<SplitPanel>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr SplitPanelBase::shallowCopyLocal(
    BitVector bFlags) const
{
    SplitPanel *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const SplitPanel *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr SplitPanelBase::shallowCopyDependent(
    BitVector bFlags) const
{
    SplitPanel *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const SplitPanel *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr SplitPanelBase::shallowCopy(void) const
{
    SplitPanel *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const SplitPanel *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

SplitPanelBase::SplitPanelBase(void) :
    Inherited(),
    _sfMinComponent           (NULL),
    _sfMaxComponent           (NULL),
    _sfDividerSize            (UInt32(3)),
    _sfDividerPosition        (Real32(0.5)),
    _sfMinDividerPosition     (Real32(0.0)),
    _sfMaxDividerPosition     (Real32(1.0)),
    _sfDividerDrawObject      (NULL),
    _sfExpandable             (bool(true)),
    _sfOrientation            (UInt32(SplitPanel::HORIZONTAL_ORIENTATION))
{
}

SplitPanelBase::SplitPanelBase(const SplitPanelBase &source) :
    Inherited(source),
    _sfMinComponent           (NULL),
    _sfMaxComponent           (NULL),
    _sfDividerSize            (source._sfDividerSize            ),
    _sfDividerPosition        (source._sfDividerPosition        ),
    _sfMinDividerPosition     (source._sfMinDividerPosition     ),
    _sfMaxDividerPosition     (source._sfMaxDividerPosition     ),
    _sfDividerDrawObject      (NULL),
    _sfExpandable             (source._sfExpandable             ),
    _sfOrientation            (source._sfOrientation            )
{
}


/*-------------------------- destructors ----------------------------------*/

SplitPanelBase::~SplitPanelBase(void)
{
}

void SplitPanelBase::onCreate(const SplitPanel *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        SplitPanel *pThis = static_cast<SplitPanel *>(this);

        pThis->setMinComponent(source->getMinComponent());

        pThis->setMaxComponent(source->getMaxComponent());

        pThis->setDividerDrawObject(source->getDividerDrawObject());
    }
}

GetFieldHandlePtr SplitPanelBase::getHandleMinComponent    (void) const
{
    SFUnrecComponentPtr::GetHandlePtr returnValue(
        new  SFUnrecComponentPtr::GetHandle(
             &_sfMinComponent,
             this->getType().getFieldDesc(MinComponentFieldId),
             const_cast<SplitPanelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SplitPanelBase::editHandleMinComponent   (void)
{
    SFUnrecComponentPtr::EditHandlePtr returnValue(
        new  SFUnrecComponentPtr::EditHandle(
             &_sfMinComponent,
             this->getType().getFieldDesc(MinComponentFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&SplitPanel::setMinComponent,
                    static_cast<SplitPanel *>(this), _1));

    editSField(MinComponentFieldMask);

    return returnValue;
}

GetFieldHandlePtr SplitPanelBase::getHandleMaxComponent    (void) const
{
    SFUnrecComponentPtr::GetHandlePtr returnValue(
        new  SFUnrecComponentPtr::GetHandle(
             &_sfMaxComponent,
             this->getType().getFieldDesc(MaxComponentFieldId),
             const_cast<SplitPanelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SplitPanelBase::editHandleMaxComponent   (void)
{
    SFUnrecComponentPtr::EditHandlePtr returnValue(
        new  SFUnrecComponentPtr::EditHandle(
             &_sfMaxComponent,
             this->getType().getFieldDesc(MaxComponentFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&SplitPanel::setMaxComponent,
                    static_cast<SplitPanel *>(this), _1));

    editSField(MaxComponentFieldMask);

    return returnValue;
}

GetFieldHandlePtr SplitPanelBase::getHandleDividerSize     (void) const
{
    SFUInt32::GetHandlePtr returnValue(
        new  SFUInt32::GetHandle(
             &_sfDividerSize,
             this->getType().getFieldDesc(DividerSizeFieldId),
             const_cast<SplitPanelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SplitPanelBase::editHandleDividerSize    (void)
{
    SFUInt32::EditHandlePtr returnValue(
        new  SFUInt32::EditHandle(
             &_sfDividerSize,
             this->getType().getFieldDesc(DividerSizeFieldId),
             this));


    editSField(DividerSizeFieldMask);

    return returnValue;
}

GetFieldHandlePtr SplitPanelBase::getHandleDividerPosition (void) const
{
    SFReal32::GetHandlePtr returnValue(
        new  SFReal32::GetHandle(
             &_sfDividerPosition,
             this->getType().getFieldDesc(DividerPositionFieldId),
             const_cast<SplitPanelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SplitPanelBase::editHandleDividerPosition(void)
{
    SFReal32::EditHandlePtr returnValue(
        new  SFReal32::EditHandle(
             &_sfDividerPosition,
             this->getType().getFieldDesc(DividerPositionFieldId),
             this));


    editSField(DividerPositionFieldMask);

    return returnValue;
}

GetFieldHandlePtr SplitPanelBase::getHandleMinDividerPosition (void) const
{
    SFReal32::GetHandlePtr returnValue(
        new  SFReal32::GetHandle(
             &_sfMinDividerPosition,
             this->getType().getFieldDesc(MinDividerPositionFieldId),
             const_cast<SplitPanelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SplitPanelBase::editHandleMinDividerPosition(void)
{
    SFReal32::EditHandlePtr returnValue(
        new  SFReal32::EditHandle(
             &_sfMinDividerPosition,
             this->getType().getFieldDesc(MinDividerPositionFieldId),
             this));


    editSField(MinDividerPositionFieldMask);

    return returnValue;
}

GetFieldHandlePtr SplitPanelBase::getHandleMaxDividerPosition (void) const
{
    SFReal32::GetHandlePtr returnValue(
        new  SFReal32::GetHandle(
             &_sfMaxDividerPosition,
             this->getType().getFieldDesc(MaxDividerPositionFieldId),
             const_cast<SplitPanelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SplitPanelBase::editHandleMaxDividerPosition(void)
{
    SFReal32::EditHandlePtr returnValue(
        new  SFReal32::EditHandle(
             &_sfMaxDividerPosition,
             this->getType().getFieldDesc(MaxDividerPositionFieldId),
             this));


    editSField(MaxDividerPositionFieldMask);

    return returnValue;
}

GetFieldHandlePtr SplitPanelBase::getHandleDividerDrawObject (void) const
{
    SFUnrecUIDrawObjectCanvasPtr::GetHandlePtr returnValue(
        new  SFUnrecUIDrawObjectCanvasPtr::GetHandle(
             &_sfDividerDrawObject,
             this->getType().getFieldDesc(DividerDrawObjectFieldId),
             const_cast<SplitPanelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SplitPanelBase::editHandleDividerDrawObject(void)
{
    SFUnrecUIDrawObjectCanvasPtr::EditHandlePtr returnValue(
        new  SFUnrecUIDrawObjectCanvasPtr::EditHandle(
             &_sfDividerDrawObject,
             this->getType().getFieldDesc(DividerDrawObjectFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&SplitPanel::setDividerDrawObject,
                    static_cast<SplitPanel *>(this), _1));

    editSField(DividerDrawObjectFieldMask);

    return returnValue;
}

GetFieldHandlePtr SplitPanelBase::getHandleExpandable      (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfExpandable,
             this->getType().getFieldDesc(ExpandableFieldId),
             const_cast<SplitPanelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SplitPanelBase::editHandleExpandable     (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfExpandable,
             this->getType().getFieldDesc(ExpandableFieldId),
             this));


    editSField(ExpandableFieldMask);

    return returnValue;
}

GetFieldHandlePtr SplitPanelBase::getHandleOrientation     (void) const
{
    SFUInt32::GetHandlePtr returnValue(
        new  SFUInt32::GetHandle(
             &_sfOrientation,
             this->getType().getFieldDesc(OrientationFieldId),
             const_cast<SplitPanelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SplitPanelBase::editHandleOrientation    (void)
{
    SFUInt32::EditHandlePtr returnValue(
        new  SFUInt32::EditHandle(
             &_sfOrientation,
             this->getType().getFieldDesc(OrientationFieldId),
             this));


    editSField(OrientationFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void SplitPanelBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    SplitPanel *pThis = static_cast<SplitPanel *>(this);

    pThis->execSync(static_cast<SplitPanel *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *SplitPanelBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    SplitPanel *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const SplitPanel *>(pRefAspect),
                  dynamic_cast<const SplitPanel *>(this));

    return returnValue;
}
#endif

void SplitPanelBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<SplitPanel *>(this)->setMinComponent(NULL);

    static_cast<SplitPanel *>(this)->setMaxComponent(NULL);

    static_cast<SplitPanel *>(this)->setDividerDrawObject(NULL);


}


OSG_END_NAMESPACE
