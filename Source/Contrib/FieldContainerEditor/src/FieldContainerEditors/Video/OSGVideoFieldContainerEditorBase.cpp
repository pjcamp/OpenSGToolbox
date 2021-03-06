/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 * contact: David Kabala (djkabala@gmail.com)                                *
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
 **     class VideoFieldContainerEditor!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGVideoFieldContainerEditorBase.h"
#include "OSGVideoFieldContainerEditor.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::VideoFieldContainerEditor
    Editor for OSG::VideoWrapper objects
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<VideoFieldContainerEditor *>::_type("VideoFieldContainerEditorPtr", "AbstractFieldContainerEditorPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(VideoFieldContainerEditor *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           VideoFieldContainerEditor *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           VideoFieldContainerEditor *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void VideoFieldContainerEditorBase::classDescInserter(TypeObject &oType)
{
}


VideoFieldContainerEditorBase::TypeObject VideoFieldContainerEditorBase::_type(
    VideoFieldContainerEditorBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&VideoFieldContainerEditorBase::createEmptyLocal),
    VideoFieldContainerEditor::initMethod,
    VideoFieldContainerEditor::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&VideoFieldContainerEditor::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "    name=\"VideoFieldContainerEditor\"\n"
    "    parent=\"AbstractFieldContainerEditor\"\n"
    "    library=\"ContribFieldContainerEditor\"\n"
    "    pointerfieldtypes=\"both\"\n"
    "    structure=\"concrete\"\n"
    "    systemcomponent=\"true\"\n"
    "    parentsystemcomponent=\"true\"\n"
    "    decoratable=\"false\"\n"
    "    useLocalIncludes=\"false\"\n"
    "    isNodeCore=\"false\"\n"
    "    authors=\"David Kabala (djkabala@gmail.com)\"\n"
    ">\n"
    "Editor for OSG::VideoWrapper objects\n"
    "</FieldContainer>\n",
    "Editor for OSG::VideoWrapper objects\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &VideoFieldContainerEditorBase::getType(void)
{
    return _type;
}

const FieldContainerType &VideoFieldContainerEditorBase::getType(void) const
{
    return _type;
}

UInt32 VideoFieldContainerEditorBase::getContainerSize(void) const
{
    return sizeof(VideoFieldContainerEditor);
}

/*------------------------- decorator get ------------------------------*/






/*------------------------------ access -----------------------------------*/

UInt32 VideoFieldContainerEditorBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);


    return returnValue;
}

void VideoFieldContainerEditorBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

}

void VideoFieldContainerEditorBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

}

//! create a new instance of the class
VideoFieldContainerEditorTransitPtr VideoFieldContainerEditorBase::createLocal(BitVector bFlags)
{
    VideoFieldContainerEditorTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<VideoFieldContainerEditor>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
VideoFieldContainerEditorTransitPtr VideoFieldContainerEditorBase::createDependent(BitVector bFlags)
{
    VideoFieldContainerEditorTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<VideoFieldContainerEditor>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
VideoFieldContainerEditorTransitPtr VideoFieldContainerEditorBase::create(void)
{
    VideoFieldContainerEditorTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<VideoFieldContainerEditor>(tmpPtr);
    }

    return fc;
}

VideoFieldContainerEditor *VideoFieldContainerEditorBase::createEmptyLocal(BitVector bFlags)
{
    VideoFieldContainerEditor *returnValue;

    newPtr<VideoFieldContainerEditor>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
VideoFieldContainerEditor *VideoFieldContainerEditorBase::createEmpty(void)
{
    VideoFieldContainerEditor *returnValue;

    newPtr<VideoFieldContainerEditor>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}

FieldContainerTransitPtr VideoFieldContainerEditorBase::shallowCopyLocal(
    BitVector bFlags) const
{
    VideoFieldContainerEditor *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const VideoFieldContainerEditor *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr VideoFieldContainerEditorBase::shallowCopyDependent(
    BitVector bFlags) const
{
    VideoFieldContainerEditor *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const VideoFieldContainerEditor *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr VideoFieldContainerEditorBase::shallowCopy(void) const
{
    VideoFieldContainerEditor *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const VideoFieldContainerEditor *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}



/*------------------------- constructors ----------------------------------*/

VideoFieldContainerEditorBase::VideoFieldContainerEditorBase(void) :
    Inherited()
{
}

VideoFieldContainerEditorBase::VideoFieldContainerEditorBase(const VideoFieldContainerEditorBase &source) :
    Inherited(source)
{
}


/*-------------------------- destructors ----------------------------------*/

VideoFieldContainerEditorBase::~VideoFieldContainerEditorBase(void)
{
}




#ifdef OSG_MT_CPTR_ASPECT
void VideoFieldContainerEditorBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    VideoFieldContainerEditor *pThis = static_cast<VideoFieldContainerEditor *>(this);

    pThis->execSync(static_cast<VideoFieldContainerEditor *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *VideoFieldContainerEditorBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    VideoFieldContainerEditor *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const VideoFieldContainerEditor *>(pRefAspect),
                  dynamic_cast<const VideoFieldContainerEditor *>(this));

    return returnValue;
}
#endif

void VideoFieldContainerEditorBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
