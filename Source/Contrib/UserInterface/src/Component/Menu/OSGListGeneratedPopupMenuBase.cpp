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
 **     class ListGeneratedPopupMenu!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"



#include "OSGListModel.h"               // Model Class
#include "OSGComponentGenerator.h"      // CellGenerator Class

#include "OSGListGeneratedPopupMenuBase.h"
#include "OSGListGeneratedPopupMenu.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::ListGeneratedPopupMenu
    A UI List Generated PopupMenu.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var ListModel *     ListGeneratedPopupMenuBase::_sfModel
    
*/

/*! \var ComponentGenerator * ListGeneratedPopupMenuBase::_sfCellGenerator
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<ListGeneratedPopupMenu *>::_type("ListGeneratedPopupMenuPtr", "PopupMenuPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(ListGeneratedPopupMenu *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           ListGeneratedPopupMenu *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           ListGeneratedPopupMenu *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void ListGeneratedPopupMenuBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFUnrecListModelPtr::Description(
        SFUnrecListModelPtr::getClassType(),
        "Model",
        "",
        ModelFieldId, ModelFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&ListGeneratedPopupMenu::editHandleModel),
        static_cast<FieldGetMethodSig >(&ListGeneratedPopupMenu::getHandleModel));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUnrecComponentGeneratorPtr::Description(
        SFUnrecComponentGeneratorPtr::getClassType(),
        "CellGenerator",
        "",
        CellGeneratorFieldId, CellGeneratorFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&ListGeneratedPopupMenu::editHandleCellGenerator),
        static_cast<FieldGetMethodSig >(&ListGeneratedPopupMenu::getHandleCellGenerator));

    oType.addInitialDesc(pDesc);
}


ListGeneratedPopupMenuBase::TypeObject ListGeneratedPopupMenuBase::_type(
    ListGeneratedPopupMenuBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&ListGeneratedPopupMenuBase::createEmptyLocal),
    ListGeneratedPopupMenu::initMethod,
    ListGeneratedPopupMenu::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&ListGeneratedPopupMenu::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"ListGeneratedPopupMenu\"\n"
    "\tparent=\"PopupMenu\"\n"
    "    library=\"ContribUserInterface\"\n"
    "    pointerfieldtypes=\"both\"\n"
    "\tstructure=\"concrete\"\n"
    "    systemcomponent=\"true\"\n"
    "    parentsystemcomponent=\"true\"\n"
    "    decoratable=\"false\"\n"
    "    useLocalIncludes=\"false\"\n"
    "    isNodeCore=\"false\"\n"
    "    authors=\"David Kabala (djkabala@gmail.com)                             \"\n"
    "\t>\n"
    "\tA UI List Generated PopupMenu.\n"
    "\t<Field\n"
    "\t\tname=\"Model\"\n"
    "\t\ttype=\"ListModel\"\n"
    "\t\tcategory=\"pointer\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"NULL\"\n"
    "\t\taccess=\"public\"\n"
    "\t\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"CellGenerator\"\n"
    "\t\ttype=\"ComponentGenerator\"\n"
    "\t\tcategory=\"pointer\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"NULL\"\n"
    "\t\taccess=\"public\"\n"
    "\t\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "A UI List Generated PopupMenu.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &ListGeneratedPopupMenuBase::getType(void)
{
    return _type;
}

const FieldContainerType &ListGeneratedPopupMenuBase::getType(void) const
{
    return _type;
}

UInt32 ListGeneratedPopupMenuBase::getContainerSize(void) const
{
    return sizeof(ListGeneratedPopupMenu);
}

/*------------------------- decorator get ------------------------------*/


//! Get the ListGeneratedPopupMenu::_sfModel field.
const SFUnrecListModelPtr *ListGeneratedPopupMenuBase::getSFModel(void) const
{
    return &_sfModel;
}

SFUnrecListModelPtr *ListGeneratedPopupMenuBase::editSFModel          (void)
{
    editSField(ModelFieldMask);

    return &_sfModel;
}

//! Get the ListGeneratedPopupMenu::_sfCellGenerator field.
const SFUnrecComponentGeneratorPtr *ListGeneratedPopupMenuBase::getSFCellGenerator(void) const
{
    return &_sfCellGenerator;
}

SFUnrecComponentGeneratorPtr *ListGeneratedPopupMenuBase::editSFCellGenerator  (void)
{
    editSField(CellGeneratorFieldMask);

    return &_sfCellGenerator;
}





/*------------------------------ access -----------------------------------*/

UInt32 ListGeneratedPopupMenuBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ModelFieldMask & whichField))
    {
        returnValue += _sfModel.getBinSize();
    }
    if(FieldBits::NoField != (CellGeneratorFieldMask & whichField))
    {
        returnValue += _sfCellGenerator.getBinSize();
    }

    return returnValue;
}

void ListGeneratedPopupMenuBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ModelFieldMask & whichField))
    {
        _sfModel.copyToBin(pMem);
    }
    if(FieldBits::NoField != (CellGeneratorFieldMask & whichField))
    {
        _sfCellGenerator.copyToBin(pMem);
    }
}

void ListGeneratedPopupMenuBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ModelFieldMask & whichField))
    {
        _sfModel.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (CellGeneratorFieldMask & whichField))
    {
        _sfCellGenerator.copyFromBin(pMem);
    }
}

//! create a new instance of the class
ListGeneratedPopupMenuTransitPtr ListGeneratedPopupMenuBase::createLocal(BitVector bFlags)
{
    ListGeneratedPopupMenuTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<ListGeneratedPopupMenu>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
ListGeneratedPopupMenuTransitPtr ListGeneratedPopupMenuBase::createDependent(BitVector bFlags)
{
    ListGeneratedPopupMenuTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<ListGeneratedPopupMenu>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
ListGeneratedPopupMenuTransitPtr ListGeneratedPopupMenuBase::create(void)
{
    ListGeneratedPopupMenuTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<ListGeneratedPopupMenu>(tmpPtr);
    }

    return fc;
}

ListGeneratedPopupMenu *ListGeneratedPopupMenuBase::createEmptyLocal(BitVector bFlags)
{
    ListGeneratedPopupMenu *returnValue;

    newPtr<ListGeneratedPopupMenu>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
ListGeneratedPopupMenu *ListGeneratedPopupMenuBase::createEmpty(void)
{
    ListGeneratedPopupMenu *returnValue;

    newPtr<ListGeneratedPopupMenu>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr ListGeneratedPopupMenuBase::shallowCopyLocal(
    BitVector bFlags) const
{
    ListGeneratedPopupMenu *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const ListGeneratedPopupMenu *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr ListGeneratedPopupMenuBase::shallowCopyDependent(
    BitVector bFlags) const
{
    ListGeneratedPopupMenu *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const ListGeneratedPopupMenu *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr ListGeneratedPopupMenuBase::shallowCopy(void) const
{
    ListGeneratedPopupMenu *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const ListGeneratedPopupMenu *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

ListGeneratedPopupMenuBase::ListGeneratedPopupMenuBase(void) :
    Inherited(),
    _sfModel                  (NULL),
    _sfCellGenerator          (NULL)
{
}

ListGeneratedPopupMenuBase::ListGeneratedPopupMenuBase(const ListGeneratedPopupMenuBase &source) :
    Inherited(source),
    _sfModel                  (NULL),
    _sfCellGenerator          (NULL)
{
}


/*-------------------------- destructors ----------------------------------*/

ListGeneratedPopupMenuBase::~ListGeneratedPopupMenuBase(void)
{
}

void ListGeneratedPopupMenuBase::onCreate(const ListGeneratedPopupMenu *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        ListGeneratedPopupMenu *pThis = static_cast<ListGeneratedPopupMenu *>(this);

        pThis->setModel(source->getModel());

        pThis->setCellGenerator(source->getCellGenerator());
    }
}

GetFieldHandlePtr ListGeneratedPopupMenuBase::getHandleModel           (void) const
{
    SFUnrecListModelPtr::GetHandlePtr returnValue(
        new  SFUnrecListModelPtr::GetHandle(
             &_sfModel,
             this->getType().getFieldDesc(ModelFieldId),
             const_cast<ListGeneratedPopupMenuBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ListGeneratedPopupMenuBase::editHandleModel          (void)
{
    SFUnrecListModelPtr::EditHandlePtr returnValue(
        new  SFUnrecListModelPtr::EditHandle(
             &_sfModel,
             this->getType().getFieldDesc(ModelFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&ListGeneratedPopupMenu::setModel,
                    static_cast<ListGeneratedPopupMenu *>(this), _1));

    editSField(ModelFieldMask);

    return returnValue;
}

GetFieldHandlePtr ListGeneratedPopupMenuBase::getHandleCellGenerator   (void) const
{
    SFUnrecComponentGeneratorPtr::GetHandlePtr returnValue(
        new  SFUnrecComponentGeneratorPtr::GetHandle(
             &_sfCellGenerator,
             this->getType().getFieldDesc(CellGeneratorFieldId),
             const_cast<ListGeneratedPopupMenuBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ListGeneratedPopupMenuBase::editHandleCellGenerator  (void)
{
    SFUnrecComponentGeneratorPtr::EditHandlePtr returnValue(
        new  SFUnrecComponentGeneratorPtr::EditHandle(
             &_sfCellGenerator,
             this->getType().getFieldDesc(CellGeneratorFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&ListGeneratedPopupMenu::setCellGenerator,
                    static_cast<ListGeneratedPopupMenu *>(this), _1));

    editSField(CellGeneratorFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void ListGeneratedPopupMenuBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    ListGeneratedPopupMenu *pThis = static_cast<ListGeneratedPopupMenu *>(this);

    pThis->execSync(static_cast<ListGeneratedPopupMenu *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *ListGeneratedPopupMenuBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    ListGeneratedPopupMenu *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const ListGeneratedPopupMenu *>(pRefAspect),
                  dynamic_cast<const ListGeneratedPopupMenu *>(this));

    return returnValue;
}
#endif

void ListGeneratedPopupMenuBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<ListGeneratedPopupMenu *>(this)->setModel(NULL);

    static_cast<ListGeneratedPopupMenu *>(this)->setCellGenerator(NULL);


}


OSG_END_NAMESPACE
