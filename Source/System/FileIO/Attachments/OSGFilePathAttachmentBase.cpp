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
 **     class FilePathAttachment!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGFilePathAttachmentBase.h"
#include "OSGFilePathAttachment.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::FilePathAttachment
    A UI Component Interface.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var BoostPath       FilePathAttachmentBase::_sfPath
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<FilePathAttachment *>::_type("FilePathAttachmentPtr", "AttachmentPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(FilePathAttachment *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           FilePathAttachment *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           FilePathAttachment *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void FilePathAttachmentBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFBoostPath::Description(
        SFBoostPath::getClassType(),
        "Path",
        "",
        PathFieldId, PathFieldMask,
        true,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&FilePathAttachment::editHandlePath),
        static_cast<FieldGetMethodSig >(&FilePathAttachment::getHandlePath));

    oType.addInitialDesc(pDesc);
}


FilePathAttachmentBase::TypeObject FilePathAttachmentBase::_type(
    FilePathAttachmentBase::getClassname(),
    Inherited::getClassname(),
    "FilePathAttachment",
    0,
    reinterpret_cast<PrototypeCreateF>(&FilePathAttachmentBase::createEmptyLocal),
    FilePathAttachment::initMethod,
    FilePathAttachment::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&FilePathAttachment::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"FilePathAttachment\"\n"
    "\tparent=\"Attachment\"\n"
    "    library=\"FileIO\"\n"
    "\tpointerfieldtypes=\"both\"\n"
    "\tstructure=\"concrete\"\n"
    "\tsystemcomponent=\"true\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"false\"\n"
    "    isNodeCore=\"false\"\n"
    "    authors=\"David Kabala (djkabala@gmail.com)                             \"\n"
    ">\n"
    "A UI Component Interface.\n"
    "\t<Field\n"
    "\t\tname=\"Path\"\n"
    "\t\ttype=\"BoostPath\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\tdefaultValue=\"\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "A UI Component Interface.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &FilePathAttachmentBase::getType(void)
{
    return _type;
}

const FieldContainerType &FilePathAttachmentBase::getType(void) const
{
    return _type;
}

UInt32 FilePathAttachmentBase::getContainerSize(void) const
{
    return sizeof(FilePathAttachment);
}

/*------------------------- decorator get ------------------------------*/


SFBoostPath *FilePathAttachmentBase::editSFPath(void)
{
    editSField(PathFieldMask);

    return &_sfPath;
}

const SFBoostPath *FilePathAttachmentBase::getSFPath(void) const
{
    return &_sfPath;
}






/*------------------------------ access -----------------------------------*/

UInt32 FilePathAttachmentBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (PathFieldMask & whichField))
    {
        returnValue += _sfPath.getBinSize();
    }

    return returnValue;
}

void FilePathAttachmentBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (PathFieldMask & whichField))
    {
        _sfPath.copyToBin(pMem);
    }
}

void FilePathAttachmentBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (PathFieldMask & whichField))
    {
        _sfPath.copyFromBin(pMem);
    }
}

//! create a new instance of the class
FilePathAttachmentTransitPtr FilePathAttachmentBase::createLocal(BitVector bFlags)
{
    FilePathAttachmentTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<FilePathAttachment>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
FilePathAttachmentTransitPtr FilePathAttachmentBase::createDependent(BitVector bFlags)
{
    FilePathAttachmentTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<FilePathAttachment>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
FilePathAttachmentTransitPtr FilePathAttachmentBase::create(void)
{
    FilePathAttachmentTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<FilePathAttachment>(tmpPtr);
    }

    return fc;
}

FilePathAttachment *FilePathAttachmentBase::createEmptyLocal(BitVector bFlags)
{
    FilePathAttachment *returnValue;

    newPtr<FilePathAttachment>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
FilePathAttachment *FilePathAttachmentBase::createEmpty(void)
{
    FilePathAttachment *returnValue;

    newPtr<FilePathAttachment>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr FilePathAttachmentBase::shallowCopyLocal(
    BitVector bFlags) const
{
    FilePathAttachment *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const FilePathAttachment *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr FilePathAttachmentBase::shallowCopyDependent(
    BitVector bFlags) const
{
    FilePathAttachment *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const FilePathAttachment *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr FilePathAttachmentBase::shallowCopy(void) const
{
    FilePathAttachment *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const FilePathAttachment *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

FilePathAttachmentBase::FilePathAttachmentBase(void) :
    Inherited(),
    _sfPath                   ()
{
}

FilePathAttachmentBase::FilePathAttachmentBase(const FilePathAttachmentBase &source) :
    Inherited(source),
    _sfPath                   (source._sfPath                   )
{
}


/*-------------------------- destructors ----------------------------------*/

FilePathAttachmentBase::~FilePathAttachmentBase(void)
{
}


GetFieldHandlePtr FilePathAttachmentBase::getHandlePath            (void) const
{
    SFBoostPath::GetHandlePtr returnValue(
        new  SFBoostPath::GetHandle(
             &_sfPath,
             this->getType().getFieldDesc(PathFieldId),
             const_cast<FilePathAttachmentBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr FilePathAttachmentBase::editHandlePath           (void)
{
    SFBoostPath::EditHandlePtr returnValue(
        new  SFBoostPath::EditHandle(
             &_sfPath,
             this->getType().getFieldDesc(PathFieldId),
             this));


    editSField(PathFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void FilePathAttachmentBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    FilePathAttachment *pThis = static_cast<FilePathAttachment *>(this);

    pThis->execSync(static_cast<FilePathAttachment *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *FilePathAttachmentBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    FilePathAttachment *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const FilePathAttachment *>(pRefAspect),
                  dynamic_cast<const FilePathAttachment *>(this));

    return returnValue;
}
#endif

void FilePathAttachmentBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
