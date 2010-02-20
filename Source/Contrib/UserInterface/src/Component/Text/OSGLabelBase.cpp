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
 **     class Label!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGLabelBase.h"
#include "OSGLabel.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::Label
    A UI Label.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Vec2f           LabelBase::_sfAlignment
    
*/

/*! \var bool            LabelBase::_sfTextSelectable
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<Label *>::_type("LabelPtr", "TextComponentPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(Label *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           Label *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           Label *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void LabelBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFVec2f::Description(
        SFVec2f::getClassType(),
        "Alignment",
        "",
        AlignmentFieldId, AlignmentFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Label::editHandleAlignment),
        static_cast<FieldGetMethodSig >(&Label::getHandleAlignment));

    oType.addInitialDesc(pDesc);


    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "TextSelectable",
        "",
        TextSelectableFieldId, TextSelectableFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Label::editHandleTextSelectable),
        static_cast<FieldGetMethodSig >(&Label::getHandleTextSelectable));

    oType.addInitialDesc(pDesc);

}


LabelBase::TypeObject LabelBase::_type(
    LabelBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&LabelBase::createEmptyLocal),
    Label::initMethod,
    Label::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&Label::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"Label\"\n"
    "\tparent=\"TextComponent\"\n"
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
    "A UI Label.\n"
    "\t<Field\n"
    "\t\tname=\"Alignment\"\n"
    "\t\ttype=\"Vec2f\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"0.0f, 0.5f\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"TextSelectable\"\n"
    "\t\ttype=\"bool\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"false\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "A UI Label.\n"
    );


/*------------------------------ get -----------------------------------*/

FieldContainerType &LabelBase::getType(void)
{
    return _type;
}

const FieldContainerType &LabelBase::getType(void) const
{
    return _type;
}

UInt32 LabelBase::getContainerSize(void) const
{
    return sizeof(Label);
}

/*------------------------- decorator get ------------------------------*/


SFVec2f *LabelBase::editSFAlignment(void)
{
    editSField(AlignmentFieldMask);

    return &_sfAlignment;
}

const SFVec2f *LabelBase::getSFAlignment(void) const
{
    return &_sfAlignment;
}


SFBool *LabelBase::editSFTextSelectable(void)
{
    editSField(TextSelectableFieldMask);

    return &_sfTextSelectable;
}

const SFBool *LabelBase::getSFTextSelectable(void) const
{
    return &_sfTextSelectable;
}






/*------------------------------ access -----------------------------------*/

UInt32 LabelBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (AlignmentFieldMask & whichField))
    {
        returnValue += _sfAlignment.getBinSize();
    }
    if(FieldBits::NoField != (TextSelectableFieldMask & whichField))
    {
        returnValue += _sfTextSelectable.getBinSize();
    }

    return returnValue;
}

void LabelBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (AlignmentFieldMask & whichField))
    {
        _sfAlignment.copyToBin(pMem);
    }
    if(FieldBits::NoField != (TextSelectableFieldMask & whichField))
    {
        _sfTextSelectable.copyToBin(pMem);
    }
}

void LabelBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (AlignmentFieldMask & whichField))
    {
        _sfAlignment.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (TextSelectableFieldMask & whichField))
    {
        _sfTextSelectable.copyFromBin(pMem);
    }
}

//! create a new instance of the class
LabelTransitPtr LabelBase::createLocal(BitVector bFlags)
{
    LabelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<Label>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
LabelTransitPtr LabelBase::createDependent(BitVector bFlags)
{
    LabelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<Label>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
LabelTransitPtr LabelBase::create(void)
{
    LabelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<Label>(tmpPtr);
    }

    return fc;
}

Label *LabelBase::createEmptyLocal(BitVector bFlags)
{
    Label *returnValue;

    newPtr<Label>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
Label *LabelBase::createEmpty(void)
{
    Label *returnValue;

    newPtr<Label>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr LabelBase::shallowCopyLocal(
    BitVector bFlags) const
{
    Label *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const Label *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr LabelBase::shallowCopyDependent(
    BitVector bFlags) const
{
    Label *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const Label *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr LabelBase::shallowCopy(void) const
{
    Label *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const Label *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

LabelBase::LabelBase(void) :
    Inherited(),
    _sfAlignment              (Vec2f(0.0f, 0.5f)),
    _sfTextSelectable         (bool(false))
{
}

LabelBase::LabelBase(const LabelBase &source) :
    Inherited(source),
    _sfAlignment              (source._sfAlignment              ),
    _sfTextSelectable         (source._sfTextSelectable         )
{
}


/*-------------------------- destructors ----------------------------------*/

LabelBase::~LabelBase(void)
{
}


GetFieldHandlePtr LabelBase::getHandleAlignment       (void) const
{
    SFVec2f::GetHandlePtr returnValue(
        new  SFVec2f::GetHandle(
             &_sfAlignment,
             this->getType().getFieldDesc(AlignmentFieldId),
             const_cast<LabelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr LabelBase::editHandleAlignment      (void)
{
    SFVec2f::EditHandlePtr returnValue(
        new  SFVec2f::EditHandle(
             &_sfAlignment,
             this->getType().getFieldDesc(AlignmentFieldId),
             this));


    editSField(AlignmentFieldMask);

    return returnValue;
}

GetFieldHandlePtr LabelBase::getHandleTextSelectable  (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfTextSelectable,
             this->getType().getFieldDesc(TextSelectableFieldId),
             const_cast<LabelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr LabelBase::editHandleTextSelectable (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfTextSelectable,
             this->getType().getFieldDesc(TextSelectableFieldId),
             this));


    editSField(TextSelectableFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void LabelBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Label *pThis = static_cast<Label *>(this);

    pThis->execSync(static_cast<Label *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *LabelBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    Label *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const Label *>(pRefAspect),
                  dynamic_cast<const Label *>(this));

    return returnValue;
}
#endif

void LabelBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
