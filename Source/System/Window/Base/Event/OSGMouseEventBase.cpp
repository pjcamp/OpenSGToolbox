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
 **     class MouseEvent!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"



#include "OSGViewport.h"                // Viewport Class

#include "OSGMouseEventBase.h"
#include "OSGMouseEvent.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::MouseEvent
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var UInt16          MouseEventBase::_sfButton
    
*/

/*! \var UInt16          MouseEventBase::_sfClickCount
    
*/

/*! \var Pnt2f           MouseEventBase::_sfLocation
    
*/

/*! \var Vec2f           MouseEventBase::_sfDelta
    
*/

/*! \var Viewport *      MouseEventBase::_sfViewport
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<MouseEvent *>::_type("MouseEventPtr", "InputEventPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(MouseEvent *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           MouseEvent *,
                           0);


/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void MouseEventBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFUInt16::Description(
        SFUInt16::getClassType(),
        "Button",
        "",
        ButtonFieldId, ButtonFieldMask,
        true,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&MouseEvent::editHandleButton),
        static_cast<FieldGetMethodSig >(&MouseEvent::getHandleButton));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUInt16::Description(
        SFUInt16::getClassType(),
        "ClickCount",
        "",
        ClickCountFieldId, ClickCountFieldMask,
        true,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&MouseEvent::editHandleClickCount),
        static_cast<FieldGetMethodSig >(&MouseEvent::getHandleClickCount));

    oType.addInitialDesc(pDesc);

    pDesc = new SFPnt2f::Description(
        SFPnt2f::getClassType(),
        "Location",
        "",
        LocationFieldId, LocationFieldMask,
        true,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&MouseEvent::editHandleLocation),
        static_cast<FieldGetMethodSig >(&MouseEvent::getHandleLocation));

    oType.addInitialDesc(pDesc);

    pDesc = new SFVec2f::Description(
        SFVec2f::getClassType(),
        "Delta",
        "",
        DeltaFieldId, DeltaFieldMask,
        true,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&MouseEvent::editHandleDelta),
        static_cast<FieldGetMethodSig >(&MouseEvent::getHandleDelta));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUnrecViewportPtr::Description(
        SFUnrecViewportPtr::getClassType(),
        "Viewport",
        "",
        ViewportFieldId, ViewportFieldMask,
        true,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&MouseEvent::editHandleViewport),
        static_cast<FieldGetMethodSig >(&MouseEvent::getHandleViewport));

    oType.addInitialDesc(pDesc);
}


MouseEventBase::TypeObject MouseEventBase::_type(
    MouseEventBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&MouseEventBase::createEmptyLocal),
    MouseEvent::initMethod,
    MouseEvent::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&MouseEvent::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"MouseEvent\"\n"
    "\tparent=\"InputEvent\"\n"
    "    library=\"System\"\n"
    "\tpointerfieldtypes=\"single\"\n"
    "\tstructure=\"concrete\"\n"
    "\tsystemcomponent=\"true\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"false\"\n"
    "    isNodeCore=\"false\"\n"
    "    authors=\"David Kabala (djkabala@gmail.com)                             \"\n"
    ">\n"
    "\t<Field\n"
    "\t\tname=\"Button\"\n"
    "\t\ttype=\"UInt16\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\taccess=\"protected\"\n"
    "\t\tdefaultValue=\"MouseEvent::NO_BUTTON\"\n"
    "        publicRead=\"true\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"ClickCount\"\n"
    "\t\ttype=\"UInt16\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\taccess=\"protected\"\n"
    "\t\tdefaultValue=\"0\"\n"
    "        publicRead=\"true\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"Location\"\n"
    "\t\ttype=\"Pnt2f\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\taccess=\"protected\"\n"
    "\t\tdefaultValue=\"0.0f, 0.0f\"\n"
    "        publicRead=\"true\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"Delta\"\n"
    "\t\ttype=\"Vec2f\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\taccess=\"protected\"\n"
    "\t\tdefaultValue=\"0.0f, 0.0f\"\n"
    "        publicRead=\"true\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"Viewport\"\n"
    "\t\ttype=\"Viewport\"\n"
    "        category=\"pointer\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\taccess=\"protected\"\n"
    "\t\tdefaultValue=\"NULL\"\n"
    "        publicRead=\"true\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &MouseEventBase::getType(void)
{
    return _type;
}

const FieldContainerType &MouseEventBase::getType(void) const
{
    return _type;
}

UInt32 MouseEventBase::getContainerSize(void) const
{
    return sizeof(MouseEvent);
}

/*------------------------- decorator get ------------------------------*/


SFUInt16 *MouseEventBase::editSFButton(void)
{
    editSField(ButtonFieldMask);

    return &_sfButton;
}

const SFUInt16 *MouseEventBase::getSFButton(void) const
{
    return &_sfButton;
}


SFUInt16 *MouseEventBase::editSFClickCount(void)
{
    editSField(ClickCountFieldMask);

    return &_sfClickCount;
}

const SFUInt16 *MouseEventBase::getSFClickCount(void) const
{
    return &_sfClickCount;
}


SFPnt2f *MouseEventBase::editSFLocation(void)
{
    editSField(LocationFieldMask);

    return &_sfLocation;
}

const SFPnt2f *MouseEventBase::getSFLocation(void) const
{
    return &_sfLocation;
}


SFVec2f *MouseEventBase::editSFDelta(void)
{
    editSField(DeltaFieldMask);

    return &_sfDelta;
}

const SFVec2f *MouseEventBase::getSFDelta(void) const
{
    return &_sfDelta;
}


//! Get the MouseEvent::_sfViewport field.
const SFUnrecViewportPtr *MouseEventBase::getSFViewport(void) const
{
    return &_sfViewport;
}

SFUnrecViewportPtr  *MouseEventBase::editSFViewport       (void)
{
    editSField(ViewportFieldMask);

    return &_sfViewport;
}





/*------------------------------ access -----------------------------------*/

UInt32 MouseEventBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ButtonFieldMask & whichField))
    {
        returnValue += _sfButton.getBinSize();
    }
    if(FieldBits::NoField != (ClickCountFieldMask & whichField))
    {
        returnValue += _sfClickCount.getBinSize();
    }
    if(FieldBits::NoField != (LocationFieldMask & whichField))
    {
        returnValue += _sfLocation.getBinSize();
    }
    if(FieldBits::NoField != (DeltaFieldMask & whichField))
    {
        returnValue += _sfDelta.getBinSize();
    }
    if(FieldBits::NoField != (ViewportFieldMask & whichField))
    {
        returnValue += _sfViewport.getBinSize();
    }

    return returnValue;
}

void MouseEventBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ButtonFieldMask & whichField))
    {
        _sfButton.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ClickCountFieldMask & whichField))
    {
        _sfClickCount.copyToBin(pMem);
    }
    if(FieldBits::NoField != (LocationFieldMask & whichField))
    {
        _sfLocation.copyToBin(pMem);
    }
    if(FieldBits::NoField != (DeltaFieldMask & whichField))
    {
        _sfDelta.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ViewportFieldMask & whichField))
    {
        _sfViewport.copyToBin(pMem);
    }
}

void MouseEventBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ButtonFieldMask & whichField))
    {
        _sfButton.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ClickCountFieldMask & whichField))
    {
        _sfClickCount.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (LocationFieldMask & whichField))
    {
        _sfLocation.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (DeltaFieldMask & whichField))
    {
        _sfDelta.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ViewportFieldMask & whichField))
    {
        _sfViewport.copyFromBin(pMem);
    }
}

//! create a new instance of the class
MouseEventTransitPtr MouseEventBase::createLocal(BitVector bFlags)
{
    MouseEventTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<MouseEvent>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
MouseEventTransitPtr MouseEventBase::createDependent(BitVector bFlags)
{
    MouseEventTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<MouseEvent>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
MouseEventTransitPtr MouseEventBase::create(void)
{
    MouseEventTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<MouseEvent>(tmpPtr);
    }

    return fc;
}

MouseEvent *MouseEventBase::createEmptyLocal(BitVector bFlags)
{
    MouseEvent *returnValue;

    newPtr<MouseEvent>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
MouseEvent *MouseEventBase::createEmpty(void)
{
    MouseEvent *returnValue;

    newPtr<MouseEvent>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr MouseEventBase::shallowCopyLocal(
    BitVector bFlags) const
{
    MouseEvent *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const MouseEvent *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr MouseEventBase::shallowCopyDependent(
    BitVector bFlags) const
{
    MouseEvent *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const MouseEvent *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr MouseEventBase::shallowCopy(void) const
{
    MouseEvent *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const MouseEvent *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

MouseEventBase::MouseEventBase(void) :
    Inherited(),
    _sfButton                 (UInt16(MouseEvent::NO_BUTTON)),
    _sfClickCount             (UInt16(0)),
    _sfLocation               (Pnt2f(0.0f, 0.0f)),
    _sfDelta                  (Vec2f(0.0f, 0.0f)),
    _sfViewport               (NULL)
{
}

MouseEventBase::MouseEventBase(const MouseEventBase &source) :
    Inherited(source),
    _sfButton                 (source._sfButton                 ),
    _sfClickCount             (source._sfClickCount             ),
    _sfLocation               (source._sfLocation               ),
    _sfDelta                  (source._sfDelta                  ),
    _sfViewport               (NULL)
{
}


/*-------------------------- destructors ----------------------------------*/

MouseEventBase::~MouseEventBase(void)
{
}

void MouseEventBase::onCreate(const MouseEvent *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        MouseEvent *pThis = static_cast<MouseEvent *>(this);

        pThis->setViewport(source->getViewport());
    }
}

GetFieldHandlePtr MouseEventBase::getHandleButton          (void) const
{
    SFUInt16::GetHandlePtr returnValue(
        new  SFUInt16::GetHandle(
             &_sfButton,
             this->getType().getFieldDesc(ButtonFieldId),
             const_cast<MouseEventBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr MouseEventBase::editHandleButton         (void)
{
    SFUInt16::EditHandlePtr returnValue(
        new  SFUInt16::EditHandle(
             &_sfButton,
             this->getType().getFieldDesc(ButtonFieldId),
             this));


    editSField(ButtonFieldMask);

    return returnValue;
}

GetFieldHandlePtr MouseEventBase::getHandleClickCount      (void) const
{
    SFUInt16::GetHandlePtr returnValue(
        new  SFUInt16::GetHandle(
             &_sfClickCount,
             this->getType().getFieldDesc(ClickCountFieldId),
             const_cast<MouseEventBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr MouseEventBase::editHandleClickCount     (void)
{
    SFUInt16::EditHandlePtr returnValue(
        new  SFUInt16::EditHandle(
             &_sfClickCount,
             this->getType().getFieldDesc(ClickCountFieldId),
             this));


    editSField(ClickCountFieldMask);

    return returnValue;
}

GetFieldHandlePtr MouseEventBase::getHandleLocation        (void) const
{
    SFPnt2f::GetHandlePtr returnValue(
        new  SFPnt2f::GetHandle(
             &_sfLocation,
             this->getType().getFieldDesc(LocationFieldId),
             const_cast<MouseEventBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr MouseEventBase::editHandleLocation       (void)
{
    SFPnt2f::EditHandlePtr returnValue(
        new  SFPnt2f::EditHandle(
             &_sfLocation,
             this->getType().getFieldDesc(LocationFieldId),
             this));


    editSField(LocationFieldMask);

    return returnValue;
}

GetFieldHandlePtr MouseEventBase::getHandleDelta           (void) const
{
    SFVec2f::GetHandlePtr returnValue(
        new  SFVec2f::GetHandle(
             &_sfDelta,
             this->getType().getFieldDesc(DeltaFieldId),
             const_cast<MouseEventBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr MouseEventBase::editHandleDelta          (void)
{
    SFVec2f::EditHandlePtr returnValue(
        new  SFVec2f::EditHandle(
             &_sfDelta,
             this->getType().getFieldDesc(DeltaFieldId),
             this));


    editSField(DeltaFieldMask);

    return returnValue;
}

GetFieldHandlePtr MouseEventBase::getHandleViewport        (void) const
{
    SFUnrecViewportPtr::GetHandlePtr returnValue(
        new  SFUnrecViewportPtr::GetHandle(
             &_sfViewport,
             this->getType().getFieldDesc(ViewportFieldId),
             const_cast<MouseEventBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr MouseEventBase::editHandleViewport       (void)
{
    SFUnrecViewportPtr::EditHandlePtr returnValue(
        new  SFUnrecViewportPtr::EditHandle(
             &_sfViewport,
             this->getType().getFieldDesc(ViewportFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&MouseEvent::setViewport,
                    static_cast<MouseEvent *>(this), _1));

    editSField(ViewportFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void MouseEventBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    MouseEvent *pThis = static_cast<MouseEvent *>(this);

    pThis->execSync(static_cast<MouseEvent *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *MouseEventBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    MouseEvent *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const MouseEvent *>(pRefAspect),
                  dynamic_cast<const MouseEvent *>(this));

    return returnValue;
}
#endif

void MouseEventBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<MouseEvent *>(this)->setViewport(NULL);


}


OSG_END_NAMESPACE
