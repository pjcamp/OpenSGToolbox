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
 **     class Toolbar!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGToolbarBase.h"
#include "OSGToolbar.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::Toolbar
    A UI Toolbar.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var bool            ToolbarBase::_sfFloatable
    
*/

/*! \var std::string     ToolbarBase::_sfFloatingTitle
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<Toolbar *>::_type("ToolbarPtr", "PanelPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(Toolbar *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           Toolbar *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           Toolbar *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void ToolbarBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "Floatable",
        "",
        FloatableFieldId, FloatableFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Toolbar::editHandleFloatable),
        static_cast<FieldGetMethodSig >(&Toolbar::getHandleFloatable));

    oType.addInitialDesc(pDesc);


    pDesc = new SFString::Description(
        SFString::getClassType(),
        "FloatingTitle",
        "",
        FloatingTitleFieldId, FloatingTitleFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Toolbar::editHandleFloatingTitle),
        static_cast<FieldGetMethodSig >(&Toolbar::getHandleFloatingTitle));

    oType.addInitialDesc(pDesc);

}


ToolbarBase::TypeObject ToolbarBase::_type(
    ToolbarBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&ToolbarBase::createEmptyLocal),
    Toolbar::initMethod,
    Toolbar::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&Toolbar::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"Toolbar\"\n"
    "\tparent=\"Panel\"\n"
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
    "A UI Toolbar.\n"
    "\t<Field\n"
    "\t\tname=\"Floatable\"\n"
    "\t\ttype=\"bool\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"false\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"FloatingTitle\"\n"
    "\t\ttype=\"std::string\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "A UI Toolbar.\n"
    );


/*------------------------------ get -----------------------------------*/

FieldContainerType &ToolbarBase::getType(void)
{
    return _type;
}

const FieldContainerType &ToolbarBase::getType(void) const
{
    return _type;
}

UInt32 ToolbarBase::getContainerSize(void) const
{
    return sizeof(Toolbar);
}

/*------------------------- decorator get ------------------------------*/


SFBool *ToolbarBase::editSFFloatable(void)
{
    editSField(FloatableFieldMask);

    return &_sfFloatable;
}

const SFBool *ToolbarBase::getSFFloatable(void) const
{
    return &_sfFloatable;
}


SFString *ToolbarBase::editSFFloatingTitle(void)
{
    editSField(FloatingTitleFieldMask);

    return &_sfFloatingTitle;
}

const SFString *ToolbarBase::getSFFloatingTitle(void) const
{
    return &_sfFloatingTitle;
}






/*------------------------------ access -----------------------------------*/

UInt32 ToolbarBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (FloatableFieldMask & whichField))
    {
        returnValue += _sfFloatable.getBinSize();
    }
    if(FieldBits::NoField != (FloatingTitleFieldMask & whichField))
    {
        returnValue += _sfFloatingTitle.getBinSize();
    }

    return returnValue;
}

void ToolbarBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (FloatableFieldMask & whichField))
    {
        _sfFloatable.copyToBin(pMem);
    }
    if(FieldBits::NoField != (FloatingTitleFieldMask & whichField))
    {
        _sfFloatingTitle.copyToBin(pMem);
    }
}

void ToolbarBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (FloatableFieldMask & whichField))
    {
        _sfFloatable.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (FloatingTitleFieldMask & whichField))
    {
        _sfFloatingTitle.copyFromBin(pMem);
    }
}

//! create a new instance of the class
ToolbarTransitPtr ToolbarBase::createLocal(BitVector bFlags)
{
    ToolbarTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<Toolbar>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
ToolbarTransitPtr ToolbarBase::createDependent(BitVector bFlags)
{
    ToolbarTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<Toolbar>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
ToolbarTransitPtr ToolbarBase::create(void)
{
    ToolbarTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<Toolbar>(tmpPtr);
    }

    return fc;
}

Toolbar *ToolbarBase::createEmptyLocal(BitVector bFlags)
{
    Toolbar *returnValue;

    newPtr<Toolbar>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
Toolbar *ToolbarBase::createEmpty(void)
{
    Toolbar *returnValue;

    newPtr<Toolbar>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr ToolbarBase::shallowCopyLocal(
    BitVector bFlags) const
{
    Toolbar *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const Toolbar *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr ToolbarBase::shallowCopyDependent(
    BitVector bFlags) const
{
    Toolbar *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const Toolbar *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr ToolbarBase::shallowCopy(void) const
{
    Toolbar *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const Toolbar *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

ToolbarBase::ToolbarBase(void) :
    Inherited(),
    _sfFloatable              (bool(false)),
    _sfFloatingTitle          ()
{
}

ToolbarBase::ToolbarBase(const ToolbarBase &source) :
    Inherited(source),
    _sfFloatable              (source._sfFloatable              ),
    _sfFloatingTitle          (source._sfFloatingTitle          )
{
}


/*-------------------------- destructors ----------------------------------*/

ToolbarBase::~ToolbarBase(void)
{
}


GetFieldHandlePtr ToolbarBase::getHandleFloatable       (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfFloatable,
             this->getType().getFieldDesc(FloatableFieldId),
             const_cast<ToolbarBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ToolbarBase::editHandleFloatable      (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfFloatable,
             this->getType().getFieldDesc(FloatableFieldId),
             this));


    editSField(FloatableFieldMask);

    return returnValue;
}

GetFieldHandlePtr ToolbarBase::getHandleFloatingTitle   (void) const
{
    SFString::GetHandlePtr returnValue(
        new  SFString::GetHandle(
             &_sfFloatingTitle,
             this->getType().getFieldDesc(FloatingTitleFieldId),
             const_cast<ToolbarBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ToolbarBase::editHandleFloatingTitle  (void)
{
    SFString::EditHandlePtr returnValue(
        new  SFString::EditHandle(
             &_sfFloatingTitle,
             this->getType().getFieldDesc(FloatingTitleFieldId),
             this));


    editSField(FloatingTitleFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void ToolbarBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Toolbar *pThis = static_cast<Toolbar *>(this);

    pThis->execSync(static_cast<Toolbar *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *ToolbarBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    Toolbar *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const Toolbar *>(pRefAspect),
                  dynamic_cast<const Toolbar *>(this));

    return returnValue;
}
#endif

void ToolbarBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
