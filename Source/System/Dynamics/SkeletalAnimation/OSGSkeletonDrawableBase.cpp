/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 *   contact:  David Kabala (djkabala@gmail.com), David Naylor               *
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
 **     class SkeletonDrawable!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"



#include "OSGSkeleton.h"                // Skeleton Class

#include "OSGSkeletonDrawableBase.h"
#include "OSGSkeletonDrawable.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::SkeletonDrawable
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Skeleton *      SkeletonDrawableBase::_sfSkeleton
    
*/

/*! \var bool            SkeletonDrawableBase::_sfDrawBindPose
    
*/

/*! \var bool            SkeletonDrawableBase::_sfDrawPose
    
*/

/*! \var Color4f         SkeletonDrawableBase::_sfBindPoseColor
    
*/

/*! \var Color4f         SkeletonDrawableBase::_sfPoseColor
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<SkeletonDrawable *>::_type("SkeletonDrawablePtr", "MaterialDrawablePtr");
#endif

OSG_FIELDTRAITS_GETTYPE(SkeletonDrawable *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           SkeletonDrawable *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           SkeletonDrawable *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void SkeletonDrawableBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFUnrecSkeletonPtr::Description(
        SFUnrecSkeletonPtr::getClassType(),
        "Skeleton",
        "",
        SkeletonFieldId, SkeletonFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SkeletonDrawable::editHandleSkeleton),
        static_cast<FieldGetMethodSig >(&SkeletonDrawable::getHandleSkeleton));

    oType.addInitialDesc(pDesc);


    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "DrawBindPose",
        "",
        DrawBindPoseFieldId, DrawBindPoseFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SkeletonDrawable::editHandleDrawBindPose),
        static_cast<FieldGetMethodSig >(&SkeletonDrawable::getHandleDrawBindPose));

    oType.addInitialDesc(pDesc);


    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "DrawPose",
        "",
        DrawPoseFieldId, DrawPoseFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SkeletonDrawable::editHandleDrawPose),
        static_cast<FieldGetMethodSig >(&SkeletonDrawable::getHandleDrawPose));

    oType.addInitialDesc(pDesc);


    pDesc = new SFColor4f::Description(
        SFColor4f::getClassType(),
        "BindPoseColor",
        "",
        BindPoseColorFieldId, BindPoseColorFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SkeletonDrawable::editHandleBindPoseColor),
        static_cast<FieldGetMethodSig >(&SkeletonDrawable::getHandleBindPoseColor));

    oType.addInitialDesc(pDesc);


    pDesc = new SFColor4f::Description(
        SFColor4f::getClassType(),
        "PoseColor",
        "",
        PoseColorFieldId, PoseColorFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SkeletonDrawable::editHandlePoseColor),
        static_cast<FieldGetMethodSig >(&SkeletonDrawable::getHandlePoseColor));

    oType.addInitialDesc(pDesc);

}


SkeletonDrawableBase::TypeObject SkeletonDrawableBase::_type(
    SkeletonDrawableBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&SkeletonDrawableBase::createEmptyLocal),
    SkeletonDrawable::initMethod,
    SkeletonDrawable::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&SkeletonDrawable::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"SkeletonDrawable\"\n"
    "\tparent=\"MaterialDrawable\"\n"
    "    library=\"Dynamics\"\n"
    "\tpointerfieldtypes=\"both\"\n"
    "\tstructure=\"concrete\"\n"
    "\tsystemcomponent=\"true\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"false\"\n"
    "    isNodeCore=\"false\"\n"
    "    authors=\"David Kabala (djkabala@gmail.com), David Naylor               \"\n"
    ">\n"
    "\t<Field\n"
    "\t\tname=\"Skeleton\"\n"
    "\t\ttype=\"Skeleton\"\n"
    "        category=\"pointer\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"NULL\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"DrawBindPose\"\n"
    "\t\ttype=\"bool\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"false\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"DrawPose\"\n"
    "\t\ttype=\"bool\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"true\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"BindPoseColor\"\n"
    "\t\ttype=\"Color4f\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"1.0,1.0,1.0,1.0\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"PoseColor\"\n"
    "\t\ttype=\"Color4f\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"1.0,1.0,1.0,1.0\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    ""
    );


/*------------------------------ get -----------------------------------*/

FieldContainerType &SkeletonDrawableBase::getType(void)
{
    return _type;
}

const FieldContainerType &SkeletonDrawableBase::getType(void) const
{
    return _type;
}

UInt32 SkeletonDrawableBase::getContainerSize(void) const
{
    return sizeof(SkeletonDrawable);
}

/*------------------------- decorator get ------------------------------*/


//! Get the SkeletonDrawable::_sfSkeleton field.
const SFUnrecSkeletonPtr *SkeletonDrawableBase::getSFSkeleton(void) const
{
    return &_sfSkeleton;
}

SFUnrecSkeletonPtr  *SkeletonDrawableBase::editSFSkeleton       (void)
{
    editSField(SkeletonFieldMask);

    return &_sfSkeleton;
}

SFBool *SkeletonDrawableBase::editSFDrawBindPose(void)
{
    editSField(DrawBindPoseFieldMask);

    return &_sfDrawBindPose;
}

const SFBool *SkeletonDrawableBase::getSFDrawBindPose(void) const
{
    return &_sfDrawBindPose;
}


SFBool *SkeletonDrawableBase::editSFDrawPose(void)
{
    editSField(DrawPoseFieldMask);

    return &_sfDrawPose;
}

const SFBool *SkeletonDrawableBase::getSFDrawPose(void) const
{
    return &_sfDrawPose;
}


SFColor4f *SkeletonDrawableBase::editSFBindPoseColor(void)
{
    editSField(BindPoseColorFieldMask);

    return &_sfBindPoseColor;
}

const SFColor4f *SkeletonDrawableBase::getSFBindPoseColor(void) const
{
    return &_sfBindPoseColor;
}


SFColor4f *SkeletonDrawableBase::editSFPoseColor(void)
{
    editSField(PoseColorFieldMask);

    return &_sfPoseColor;
}

const SFColor4f *SkeletonDrawableBase::getSFPoseColor(void) const
{
    return &_sfPoseColor;
}






/*------------------------------ access -----------------------------------*/

UInt32 SkeletonDrawableBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (SkeletonFieldMask & whichField))
    {
        returnValue += _sfSkeleton.getBinSize();
    }
    if(FieldBits::NoField != (DrawBindPoseFieldMask & whichField))
    {
        returnValue += _sfDrawBindPose.getBinSize();
    }
    if(FieldBits::NoField != (DrawPoseFieldMask & whichField))
    {
        returnValue += _sfDrawPose.getBinSize();
    }
    if(FieldBits::NoField != (BindPoseColorFieldMask & whichField))
    {
        returnValue += _sfBindPoseColor.getBinSize();
    }
    if(FieldBits::NoField != (PoseColorFieldMask & whichField))
    {
        returnValue += _sfPoseColor.getBinSize();
    }

    return returnValue;
}

void SkeletonDrawableBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (SkeletonFieldMask & whichField))
    {
        _sfSkeleton.copyToBin(pMem);
    }
    if(FieldBits::NoField != (DrawBindPoseFieldMask & whichField))
    {
        _sfDrawBindPose.copyToBin(pMem);
    }
    if(FieldBits::NoField != (DrawPoseFieldMask & whichField))
    {
        _sfDrawPose.copyToBin(pMem);
    }
    if(FieldBits::NoField != (BindPoseColorFieldMask & whichField))
    {
        _sfBindPoseColor.copyToBin(pMem);
    }
    if(FieldBits::NoField != (PoseColorFieldMask & whichField))
    {
        _sfPoseColor.copyToBin(pMem);
    }
}

void SkeletonDrawableBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (SkeletonFieldMask & whichField))
    {
        _sfSkeleton.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (DrawBindPoseFieldMask & whichField))
    {
        _sfDrawBindPose.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (DrawPoseFieldMask & whichField))
    {
        _sfDrawPose.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (BindPoseColorFieldMask & whichField))
    {
        _sfBindPoseColor.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (PoseColorFieldMask & whichField))
    {
        _sfPoseColor.copyFromBin(pMem);
    }
}

//! create a new instance of the class
SkeletonDrawableTransitPtr SkeletonDrawableBase::createLocal(BitVector bFlags)
{
    SkeletonDrawableTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<SkeletonDrawable>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
SkeletonDrawableTransitPtr SkeletonDrawableBase::createDependent(BitVector bFlags)
{
    SkeletonDrawableTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<SkeletonDrawable>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
SkeletonDrawableTransitPtr SkeletonDrawableBase::create(void)
{
    SkeletonDrawableTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<SkeletonDrawable>(tmpPtr);
    }

    return fc;
}

SkeletonDrawable *SkeletonDrawableBase::createEmptyLocal(BitVector bFlags)
{
    SkeletonDrawable *returnValue;

    newPtr<SkeletonDrawable>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
SkeletonDrawable *SkeletonDrawableBase::createEmpty(void)
{
    SkeletonDrawable *returnValue;

    newPtr<SkeletonDrawable>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr SkeletonDrawableBase::shallowCopyLocal(
    BitVector bFlags) const
{
    SkeletonDrawable *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const SkeletonDrawable *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr SkeletonDrawableBase::shallowCopyDependent(
    BitVector bFlags) const
{
    SkeletonDrawable *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const SkeletonDrawable *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr SkeletonDrawableBase::shallowCopy(void) const
{
    SkeletonDrawable *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const SkeletonDrawable *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

SkeletonDrawableBase::SkeletonDrawableBase(void) :
    Inherited(),
    _sfSkeleton               (NULL),
    _sfDrawBindPose           (bool(false)),
    _sfDrawPose               (bool(true)),
    _sfBindPoseColor          (Color4f(1.0,1.0,1.0,1.0)),
    _sfPoseColor              (Color4f(1.0,1.0,1.0,1.0))
{
}

SkeletonDrawableBase::SkeletonDrawableBase(const SkeletonDrawableBase &source) :
    Inherited(source),
    _sfSkeleton               (NULL),
    _sfDrawBindPose           (source._sfDrawBindPose           ),
    _sfDrawPose               (source._sfDrawPose               ),
    _sfBindPoseColor          (source._sfBindPoseColor          ),
    _sfPoseColor              (source._sfPoseColor              )
{
}


/*-------------------------- destructors ----------------------------------*/

SkeletonDrawableBase::~SkeletonDrawableBase(void)
{
}

void SkeletonDrawableBase::onCreate(const SkeletonDrawable *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        SkeletonDrawable *pThis = static_cast<SkeletonDrawable *>(this);

        pThis->setSkeleton(source->getSkeleton());
    }
}

GetFieldHandlePtr SkeletonDrawableBase::getHandleSkeleton        (void) const
{
    SFUnrecSkeletonPtr::GetHandlePtr returnValue(
        new  SFUnrecSkeletonPtr::GetHandle(
             &_sfSkeleton,
             this->getType().getFieldDesc(SkeletonFieldId),
             const_cast<SkeletonDrawableBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SkeletonDrawableBase::editHandleSkeleton       (void)
{
    SFUnrecSkeletonPtr::EditHandlePtr returnValue(
        new  SFUnrecSkeletonPtr::EditHandle(
             &_sfSkeleton,
             this->getType().getFieldDesc(SkeletonFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&SkeletonDrawable::setSkeleton,
                    static_cast<SkeletonDrawable *>(this), _1));

    editSField(SkeletonFieldMask);

    return returnValue;
}

GetFieldHandlePtr SkeletonDrawableBase::getHandleDrawBindPose    (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfDrawBindPose,
             this->getType().getFieldDesc(DrawBindPoseFieldId),
             const_cast<SkeletonDrawableBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SkeletonDrawableBase::editHandleDrawBindPose   (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfDrawBindPose,
             this->getType().getFieldDesc(DrawBindPoseFieldId),
             this));


    editSField(DrawBindPoseFieldMask);

    return returnValue;
}

GetFieldHandlePtr SkeletonDrawableBase::getHandleDrawPose        (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfDrawPose,
             this->getType().getFieldDesc(DrawPoseFieldId),
             const_cast<SkeletonDrawableBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SkeletonDrawableBase::editHandleDrawPose       (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfDrawPose,
             this->getType().getFieldDesc(DrawPoseFieldId),
             this));


    editSField(DrawPoseFieldMask);

    return returnValue;
}

GetFieldHandlePtr SkeletonDrawableBase::getHandleBindPoseColor   (void) const
{
    SFColor4f::GetHandlePtr returnValue(
        new  SFColor4f::GetHandle(
             &_sfBindPoseColor,
             this->getType().getFieldDesc(BindPoseColorFieldId),
             const_cast<SkeletonDrawableBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SkeletonDrawableBase::editHandleBindPoseColor  (void)
{
    SFColor4f::EditHandlePtr returnValue(
        new  SFColor4f::EditHandle(
             &_sfBindPoseColor,
             this->getType().getFieldDesc(BindPoseColorFieldId),
             this));


    editSField(BindPoseColorFieldMask);

    return returnValue;
}

GetFieldHandlePtr SkeletonDrawableBase::getHandlePoseColor       (void) const
{
    SFColor4f::GetHandlePtr returnValue(
        new  SFColor4f::GetHandle(
             &_sfPoseColor,
             this->getType().getFieldDesc(PoseColorFieldId),
             const_cast<SkeletonDrawableBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SkeletonDrawableBase::editHandlePoseColor      (void)
{
    SFColor4f::EditHandlePtr returnValue(
        new  SFColor4f::EditHandle(
             &_sfPoseColor,
             this->getType().getFieldDesc(PoseColorFieldId),
             this));


    editSField(PoseColorFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void SkeletonDrawableBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    SkeletonDrawable *pThis = static_cast<SkeletonDrawable *>(this);

    pThis->execSync(static_cast<SkeletonDrawable *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *SkeletonDrawableBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    SkeletonDrawable *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const SkeletonDrawable *>(pRefAspect),
                  dynamic_cast<const SkeletonDrawable *>(this));

    return returnValue;
}
#endif

void SkeletonDrawableBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<SkeletonDrawable *>(this)->setSkeleton(NULL);


}


OSG_END_NAMESPACE
