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
 **     class UIForegroundMouseTransformFunctor!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"



#include "OSGUIForeground.h"            // Parent Class

#include "OSGUIForegroundMouseTransformFunctorBase.h"
#include "OSGUIForegroundMouseTransformFunctor.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::UIForegroundMouseTransformFunctor
    A UI UIDrawingSurfaceMouseTransformFunctor.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var UIForeground *  UIForegroundMouseTransformFunctorBase::_sfParent
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<UIForegroundMouseTransformFunctor *>::_type("UIForegroundMouseTransformFunctorPtr", "UIDrawingSurfaceMouseTransformFunctorPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(UIForegroundMouseTransformFunctor *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           UIForegroundMouseTransformFunctor *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           UIForegroundMouseTransformFunctor *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void UIForegroundMouseTransformFunctorBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFUnrecUIForegroundPtr::Description(
        SFUnrecUIForegroundPtr::getClassType(),
        "Parent",
        "",
        ParentFieldId, ParentFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&UIForegroundMouseTransformFunctor::editHandleParent),
        static_cast<FieldGetMethodSig >(&UIForegroundMouseTransformFunctor::getHandleParent));

    oType.addInitialDesc(pDesc);
}


UIForegroundMouseTransformFunctorBase::TypeObject UIForegroundMouseTransformFunctorBase::_type(
    UIForegroundMouseTransformFunctorBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&UIForegroundMouseTransformFunctorBase::createEmptyLocal),
    UIForegroundMouseTransformFunctor::initMethod,
    UIForegroundMouseTransformFunctor::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&UIForegroundMouseTransformFunctor::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"UIForegroundMouseTransformFunctor\"\n"
    "\tparent=\"UIDrawingSurfaceMouseTransformFunctor\"\n"
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
    "A UI UIDrawingSurfaceMouseTransformFunctor.\n"
    "\t<Field\n"
    "\t\tname=\"Parent\"\n"
    "\t\ttype=\"UIForeground\"\n"
    "\t\tcategory=\"pointer\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"NULL\"\n"
    "\t\taccess=\"protected\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "A UI UIDrawingSurfaceMouseTransformFunctor.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &UIForegroundMouseTransformFunctorBase::getType(void)
{
    return _type;
}

const FieldContainerType &UIForegroundMouseTransformFunctorBase::getType(void) const
{
    return _type;
}

UInt32 UIForegroundMouseTransformFunctorBase::getContainerSize(void) const
{
    return sizeof(UIForegroundMouseTransformFunctor);
}

/*------------------------- decorator get ------------------------------*/


//! Get the UIForegroundMouseTransformFunctor::_sfParent field.
const SFUnrecUIForegroundPtr *UIForegroundMouseTransformFunctorBase::getSFParent(void) const
{
    return &_sfParent;
}

SFUnrecUIForegroundPtr *UIForegroundMouseTransformFunctorBase::editSFParent         (void)
{
    editSField(ParentFieldMask);

    return &_sfParent;
}





/*------------------------------ access -----------------------------------*/

UInt32 UIForegroundMouseTransformFunctorBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ParentFieldMask & whichField))
    {
        returnValue += _sfParent.getBinSize();
    }

    return returnValue;
}

void UIForegroundMouseTransformFunctorBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ParentFieldMask & whichField))
    {
        _sfParent.copyToBin(pMem);
    }
}

void UIForegroundMouseTransformFunctorBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ParentFieldMask & whichField))
    {
        _sfParent.copyFromBin(pMem);
    }
}

//! create a new instance of the class
UIForegroundMouseTransformFunctorTransitPtr UIForegroundMouseTransformFunctorBase::createLocal(BitVector bFlags)
{
    UIForegroundMouseTransformFunctorTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<UIForegroundMouseTransformFunctor>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
UIForegroundMouseTransformFunctorTransitPtr UIForegroundMouseTransformFunctorBase::createDependent(BitVector bFlags)
{
    UIForegroundMouseTransformFunctorTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<UIForegroundMouseTransformFunctor>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
UIForegroundMouseTransformFunctorTransitPtr UIForegroundMouseTransformFunctorBase::create(void)
{
    UIForegroundMouseTransformFunctorTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<UIForegroundMouseTransformFunctor>(tmpPtr);
    }

    return fc;
}

UIForegroundMouseTransformFunctor *UIForegroundMouseTransformFunctorBase::createEmptyLocal(BitVector bFlags)
{
    UIForegroundMouseTransformFunctor *returnValue;

    newPtr<UIForegroundMouseTransformFunctor>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
UIForegroundMouseTransformFunctor *UIForegroundMouseTransformFunctorBase::createEmpty(void)
{
    UIForegroundMouseTransformFunctor *returnValue;

    newPtr<UIForegroundMouseTransformFunctor>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr UIForegroundMouseTransformFunctorBase::shallowCopyLocal(
    BitVector bFlags) const
{
    UIForegroundMouseTransformFunctor *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const UIForegroundMouseTransformFunctor *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr UIForegroundMouseTransformFunctorBase::shallowCopyDependent(
    BitVector bFlags) const
{
    UIForegroundMouseTransformFunctor *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const UIForegroundMouseTransformFunctor *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr UIForegroundMouseTransformFunctorBase::shallowCopy(void) const
{
    UIForegroundMouseTransformFunctor *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const UIForegroundMouseTransformFunctor *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

UIForegroundMouseTransformFunctorBase::UIForegroundMouseTransformFunctorBase(void) :
    Inherited(),
    _sfParent                 (NULL)
{
}

UIForegroundMouseTransformFunctorBase::UIForegroundMouseTransformFunctorBase(const UIForegroundMouseTransformFunctorBase &source) :
    Inherited(source),
    _sfParent                 (NULL)
{
}


/*-------------------------- destructors ----------------------------------*/

UIForegroundMouseTransformFunctorBase::~UIForegroundMouseTransformFunctorBase(void)
{
}

void UIForegroundMouseTransformFunctorBase::onCreate(const UIForegroundMouseTransformFunctor *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        UIForegroundMouseTransformFunctor *pThis = static_cast<UIForegroundMouseTransformFunctor *>(this);

        pThis->setParent(source->getParent());
    }
}

GetFieldHandlePtr UIForegroundMouseTransformFunctorBase::getHandleParent          (void) const
{
    SFUnrecUIForegroundPtr::GetHandlePtr returnValue(
        new  SFUnrecUIForegroundPtr::GetHandle(
             &_sfParent,
             this->getType().getFieldDesc(ParentFieldId),
             const_cast<UIForegroundMouseTransformFunctorBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr UIForegroundMouseTransformFunctorBase::editHandleParent         (void)
{
    SFUnrecUIForegroundPtr::EditHandlePtr returnValue(
        new  SFUnrecUIForegroundPtr::EditHandle(
             &_sfParent,
             this->getType().getFieldDesc(ParentFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&UIForegroundMouseTransformFunctor::setParent,
                    static_cast<UIForegroundMouseTransformFunctor *>(this), _1));

    editSField(ParentFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void UIForegroundMouseTransformFunctorBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    UIForegroundMouseTransformFunctor *pThis = static_cast<UIForegroundMouseTransformFunctor *>(this);

    pThis->execSync(static_cast<UIForegroundMouseTransformFunctor *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *UIForegroundMouseTransformFunctorBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    UIForegroundMouseTransformFunctor *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const UIForegroundMouseTransformFunctor *>(pRefAspect),
                  dynamic_cast<const UIForegroundMouseTransformFunctor *>(this));

    return returnValue;
}
#endif

void UIForegroundMouseTransformFunctorBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<UIForegroundMouseTransformFunctor *>(this)->setParent(NULL);


}


OSG_END_NAMESPACE
