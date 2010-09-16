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
 **     class LuaIntrospectionTreeModel!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGLuaIntrospectionTreeModelBase.h"
#include "OSGLuaIntrospectionTreeModel.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::LuaIntrospectionTreeModel
    A UI ComponentTreeModel.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var std::string     LuaIntrospectionTreeModelBase::_mfInternalRoot
    
*/

/*! \var bool            LuaIntrospectionTreeModelBase::_sfShowTable
    
*/

/*! \var bool            LuaIntrospectionTreeModelBase::_sfShowFunction
    
*/

/*! \var bool            LuaIntrospectionTreeModelBase::_sfShowNil
    
*/

/*! \var bool            LuaIntrospectionTreeModelBase::_sfShowBoolean
    
*/

/*! \var bool            LuaIntrospectionTreeModelBase::_sfShowNumber
    
*/

/*! \var bool            LuaIntrospectionTreeModelBase::_sfShowString
    
*/

/*! \var bool            LuaIntrospectionTreeModelBase::_sfShowThread
    
*/

/*! \var bool            LuaIntrospectionTreeModelBase::_sfShowUserData
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<LuaIntrospectionTreeModel *>::_type("LuaIntrospectionTreeModelPtr", "AbstractTreeModelPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(LuaIntrospectionTreeModel *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           LuaIntrospectionTreeModel *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           LuaIntrospectionTreeModel *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void LuaIntrospectionTreeModelBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new MFString::Description(
        MFString::getClassType(),
        "InternalRoot",
        "",
        InternalRootFieldId, InternalRootFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&LuaIntrospectionTreeModel::editHandleInternalRoot),
        static_cast<FieldGetMethodSig >(&LuaIntrospectionTreeModel::getHandleInternalRoot));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "ShowTable",
        "",
        ShowTableFieldId, ShowTableFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&LuaIntrospectionTreeModel::editHandleShowTable),
        static_cast<FieldGetMethodSig >(&LuaIntrospectionTreeModel::getHandleShowTable));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "ShowFunction",
        "",
        ShowFunctionFieldId, ShowFunctionFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&LuaIntrospectionTreeModel::editHandleShowFunction),
        static_cast<FieldGetMethodSig >(&LuaIntrospectionTreeModel::getHandleShowFunction));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "ShowNil",
        "",
        ShowNilFieldId, ShowNilFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&LuaIntrospectionTreeModel::editHandleShowNil),
        static_cast<FieldGetMethodSig >(&LuaIntrospectionTreeModel::getHandleShowNil));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "ShowBoolean",
        "",
        ShowBooleanFieldId, ShowBooleanFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&LuaIntrospectionTreeModel::editHandleShowBoolean),
        static_cast<FieldGetMethodSig >(&LuaIntrospectionTreeModel::getHandleShowBoolean));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "ShowNumber",
        "",
        ShowNumberFieldId, ShowNumberFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&LuaIntrospectionTreeModel::editHandleShowNumber),
        static_cast<FieldGetMethodSig >(&LuaIntrospectionTreeModel::getHandleShowNumber));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "ShowString",
        "",
        ShowStringFieldId, ShowStringFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&LuaIntrospectionTreeModel::editHandleShowString),
        static_cast<FieldGetMethodSig >(&LuaIntrospectionTreeModel::getHandleShowString));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "ShowThread",
        "",
        ShowThreadFieldId, ShowThreadFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&LuaIntrospectionTreeModel::editHandleShowThread),
        static_cast<FieldGetMethodSig >(&LuaIntrospectionTreeModel::getHandleShowThread));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "ShowUserData",
        "",
        ShowUserDataFieldId, ShowUserDataFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&LuaIntrospectionTreeModel::editHandleShowUserData),
        static_cast<FieldGetMethodSig >(&LuaIntrospectionTreeModel::getHandleShowUserData));

    oType.addInitialDesc(pDesc);
}


LuaIntrospectionTreeModelBase::TypeObject LuaIntrospectionTreeModelBase::_type(
    LuaIntrospectionTreeModelBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&LuaIntrospectionTreeModelBase::createEmptyLocal),
    LuaIntrospectionTreeModel::initMethod,
    LuaIntrospectionTreeModel::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&LuaIntrospectionTreeModel::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"LuaIntrospectionTreeModel\"\n"
    "\tparent=\"AbstractTreeModel\"\n"
    "    library=\"ContribLuaToolbox\"\n"
    "    pointerfieldtypes=\"both\"\n"
    "\tstructure=\"concrete\"\n"
    "    systemcomponent=\"true\"\n"
    "    parentsystemcomponent=\"true\"\n"
    "    decoratable=\"false\"\n"
    "    useLocalIncludes=\"false\"\n"
    "    isNodeCore=\"false\"\n"
    "    authors=\"David Kabala (djkabala@gmail.com)                             \"\n"
    ">\n"
    "A UI ComponentTreeModel.\n"
    "\t<Field\n"
    "\t\tname=\"InternalRoot\"\n"
    "\t\ttype=\"std::string\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"multi\"\n"
    "        visibility=\"external\"\n"
    "\t\tdefaultValue=\"\"\n"
    "\t\taccess=\"protected\"\n"
    "\t>\n"
    "   </Field>\n"
    "\t<Field\n"
    "\t\tname=\"ShowTable\"\n"
    "\t\ttype=\"bool\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "        visibility=\"external\"\n"
    "\t\tdefaultValue=\"true\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "   </Field>\n"
    "\t<Field\n"
    "\t\tname=\"ShowFunction\"\n"
    "\t\ttype=\"bool\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "        visibility=\"external\"\n"
    "\t\tdefaultValue=\"true\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "   </Field>\n"
    "\t<Field\n"
    "\t\tname=\"ShowNil\"\n"
    "\t\ttype=\"bool\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "        visibility=\"external\"\n"
    "\t\tdefaultValue=\"true\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "   </Field>\n"
    "\t<Field\n"
    "\t\tname=\"ShowBoolean\"\n"
    "\t\ttype=\"bool\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "        visibility=\"external\"\n"
    "\t\tdefaultValue=\"true\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "   </Field>\n"
    "\t<Field\n"
    "\t\tname=\"ShowNumber\"\n"
    "\t\ttype=\"bool\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "        visibility=\"external\"\n"
    "\t\tdefaultValue=\"true\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "   </Field>\n"
    "\t<Field\n"
    "\t\tname=\"ShowString\"\n"
    "\t\ttype=\"bool\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "        visibility=\"external\"\n"
    "\t\tdefaultValue=\"true\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "   </Field>\n"
    "\t<Field\n"
    "\t\tname=\"ShowThread\"\n"
    "\t\ttype=\"bool\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "        visibility=\"external\"\n"
    "\t\tdefaultValue=\"true\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "   </Field>\n"
    "\t<Field\n"
    "\t\tname=\"ShowUserData\"\n"
    "\t\ttype=\"bool\"\n"
    "        category=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "        visibility=\"external\"\n"
    "\t\tdefaultValue=\"true\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "   </Field>\n"
    "</FieldContainer>\n",
    "A UI ComponentTreeModel.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &LuaIntrospectionTreeModelBase::getType(void)
{
    return _type;
}

const FieldContainerType &LuaIntrospectionTreeModelBase::getType(void) const
{
    return _type;
}

UInt32 LuaIntrospectionTreeModelBase::getContainerSize(void) const
{
    return sizeof(LuaIntrospectionTreeModel);
}

/*------------------------- decorator get ------------------------------*/


MFString *LuaIntrospectionTreeModelBase::editMFInternalRoot(void)
{
    editMField(InternalRootFieldMask, _mfInternalRoot);

    return &_mfInternalRoot;
}

const MFString *LuaIntrospectionTreeModelBase::getMFInternalRoot(void) const
{
    return &_mfInternalRoot;
}


SFBool *LuaIntrospectionTreeModelBase::editSFShowTable(void)
{
    editSField(ShowTableFieldMask);

    return &_sfShowTable;
}

const SFBool *LuaIntrospectionTreeModelBase::getSFShowTable(void) const
{
    return &_sfShowTable;
}


SFBool *LuaIntrospectionTreeModelBase::editSFShowFunction(void)
{
    editSField(ShowFunctionFieldMask);

    return &_sfShowFunction;
}

const SFBool *LuaIntrospectionTreeModelBase::getSFShowFunction(void) const
{
    return &_sfShowFunction;
}


SFBool *LuaIntrospectionTreeModelBase::editSFShowNil(void)
{
    editSField(ShowNilFieldMask);

    return &_sfShowNil;
}

const SFBool *LuaIntrospectionTreeModelBase::getSFShowNil(void) const
{
    return &_sfShowNil;
}


SFBool *LuaIntrospectionTreeModelBase::editSFShowBoolean(void)
{
    editSField(ShowBooleanFieldMask);

    return &_sfShowBoolean;
}

const SFBool *LuaIntrospectionTreeModelBase::getSFShowBoolean(void) const
{
    return &_sfShowBoolean;
}


SFBool *LuaIntrospectionTreeModelBase::editSFShowNumber(void)
{
    editSField(ShowNumberFieldMask);

    return &_sfShowNumber;
}

const SFBool *LuaIntrospectionTreeModelBase::getSFShowNumber(void) const
{
    return &_sfShowNumber;
}


SFBool *LuaIntrospectionTreeModelBase::editSFShowString(void)
{
    editSField(ShowStringFieldMask);

    return &_sfShowString;
}

const SFBool *LuaIntrospectionTreeModelBase::getSFShowString(void) const
{
    return &_sfShowString;
}


SFBool *LuaIntrospectionTreeModelBase::editSFShowThread(void)
{
    editSField(ShowThreadFieldMask);

    return &_sfShowThread;
}

const SFBool *LuaIntrospectionTreeModelBase::getSFShowThread(void) const
{
    return &_sfShowThread;
}


SFBool *LuaIntrospectionTreeModelBase::editSFShowUserData(void)
{
    editSField(ShowUserDataFieldMask);

    return &_sfShowUserData;
}

const SFBool *LuaIntrospectionTreeModelBase::getSFShowUserData(void) const
{
    return &_sfShowUserData;
}






/*------------------------------ access -----------------------------------*/

UInt32 LuaIntrospectionTreeModelBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (InternalRootFieldMask & whichField))
    {
        returnValue += _mfInternalRoot.getBinSize();
    }
    if(FieldBits::NoField != (ShowTableFieldMask & whichField))
    {
        returnValue += _sfShowTable.getBinSize();
    }
    if(FieldBits::NoField != (ShowFunctionFieldMask & whichField))
    {
        returnValue += _sfShowFunction.getBinSize();
    }
    if(FieldBits::NoField != (ShowNilFieldMask & whichField))
    {
        returnValue += _sfShowNil.getBinSize();
    }
    if(FieldBits::NoField != (ShowBooleanFieldMask & whichField))
    {
        returnValue += _sfShowBoolean.getBinSize();
    }
    if(FieldBits::NoField != (ShowNumberFieldMask & whichField))
    {
        returnValue += _sfShowNumber.getBinSize();
    }
    if(FieldBits::NoField != (ShowStringFieldMask & whichField))
    {
        returnValue += _sfShowString.getBinSize();
    }
    if(FieldBits::NoField != (ShowThreadFieldMask & whichField))
    {
        returnValue += _sfShowThread.getBinSize();
    }
    if(FieldBits::NoField != (ShowUserDataFieldMask & whichField))
    {
        returnValue += _sfShowUserData.getBinSize();
    }

    return returnValue;
}

void LuaIntrospectionTreeModelBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (InternalRootFieldMask & whichField))
    {
        _mfInternalRoot.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ShowTableFieldMask & whichField))
    {
        _sfShowTable.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ShowFunctionFieldMask & whichField))
    {
        _sfShowFunction.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ShowNilFieldMask & whichField))
    {
        _sfShowNil.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ShowBooleanFieldMask & whichField))
    {
        _sfShowBoolean.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ShowNumberFieldMask & whichField))
    {
        _sfShowNumber.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ShowStringFieldMask & whichField))
    {
        _sfShowString.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ShowThreadFieldMask & whichField))
    {
        _sfShowThread.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ShowUserDataFieldMask & whichField))
    {
        _sfShowUserData.copyToBin(pMem);
    }
}

void LuaIntrospectionTreeModelBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (InternalRootFieldMask & whichField))
    {
        _mfInternalRoot.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ShowTableFieldMask & whichField))
    {
        _sfShowTable.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ShowFunctionFieldMask & whichField))
    {
        _sfShowFunction.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ShowNilFieldMask & whichField))
    {
        _sfShowNil.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ShowBooleanFieldMask & whichField))
    {
        _sfShowBoolean.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ShowNumberFieldMask & whichField))
    {
        _sfShowNumber.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ShowStringFieldMask & whichField))
    {
        _sfShowString.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ShowThreadFieldMask & whichField))
    {
        _sfShowThread.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ShowUserDataFieldMask & whichField))
    {
        _sfShowUserData.copyFromBin(pMem);
    }
}

//! create a new instance of the class
LuaIntrospectionTreeModelTransitPtr LuaIntrospectionTreeModelBase::createLocal(BitVector bFlags)
{
    LuaIntrospectionTreeModelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<LuaIntrospectionTreeModel>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
LuaIntrospectionTreeModelTransitPtr LuaIntrospectionTreeModelBase::createDependent(BitVector bFlags)
{
    LuaIntrospectionTreeModelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<LuaIntrospectionTreeModel>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
LuaIntrospectionTreeModelTransitPtr LuaIntrospectionTreeModelBase::create(void)
{
    LuaIntrospectionTreeModelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<LuaIntrospectionTreeModel>(tmpPtr);
    }

    return fc;
}

LuaIntrospectionTreeModel *LuaIntrospectionTreeModelBase::createEmptyLocal(BitVector bFlags)
{
    LuaIntrospectionTreeModel *returnValue;

    newPtr<LuaIntrospectionTreeModel>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
LuaIntrospectionTreeModel *LuaIntrospectionTreeModelBase::createEmpty(void)
{
    LuaIntrospectionTreeModel *returnValue;

    newPtr<LuaIntrospectionTreeModel>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr LuaIntrospectionTreeModelBase::shallowCopyLocal(
    BitVector bFlags) const
{
    LuaIntrospectionTreeModel *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const LuaIntrospectionTreeModel *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr LuaIntrospectionTreeModelBase::shallowCopyDependent(
    BitVector bFlags) const
{
    LuaIntrospectionTreeModel *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const LuaIntrospectionTreeModel *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr LuaIntrospectionTreeModelBase::shallowCopy(void) const
{
    LuaIntrospectionTreeModel *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const LuaIntrospectionTreeModel *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}



/*------------------------- constructors ----------------------------------*/

LuaIntrospectionTreeModelBase::LuaIntrospectionTreeModelBase(void) :
    Inherited(),
    _mfInternalRoot           (),
    _sfShowTable              (bool(true)),
    _sfShowFunction           (bool(true)),
    _sfShowNil                (bool(true)),
    _sfShowBoolean            (bool(true)),
    _sfShowNumber             (bool(true)),
    _sfShowString             (bool(true)),
    _sfShowThread             (bool(true)),
    _sfShowUserData           (bool(true))
{
}

LuaIntrospectionTreeModelBase::LuaIntrospectionTreeModelBase(const LuaIntrospectionTreeModelBase &source) :
    Inherited(source),
    _mfInternalRoot           (source._mfInternalRoot           ),
    _sfShowTable              (source._sfShowTable              ),
    _sfShowFunction           (source._sfShowFunction           ),
    _sfShowNil                (source._sfShowNil                ),
    _sfShowBoolean            (source._sfShowBoolean            ),
    _sfShowNumber             (source._sfShowNumber             ),
    _sfShowString             (source._sfShowString             ),
    _sfShowThread             (source._sfShowThread             ),
    _sfShowUserData           (source._sfShowUserData           )
{
}


/*-------------------------- destructors ----------------------------------*/

LuaIntrospectionTreeModelBase::~LuaIntrospectionTreeModelBase(void)
{
}


GetFieldHandlePtr LuaIntrospectionTreeModelBase::getHandleInternalRoot    (void) const
{
    MFString::GetHandlePtr returnValue(
        new  MFString::GetHandle(
             &_mfInternalRoot,
             this->getType().getFieldDesc(InternalRootFieldId),
             const_cast<LuaIntrospectionTreeModelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr LuaIntrospectionTreeModelBase::editHandleInternalRoot   (void)
{
    MFString::EditHandlePtr returnValue(
        new  MFString::EditHandle(
             &_mfInternalRoot,
             this->getType().getFieldDesc(InternalRootFieldId),
             this));


    editMField(InternalRootFieldMask, _mfInternalRoot);

    return returnValue;
}

GetFieldHandlePtr LuaIntrospectionTreeModelBase::getHandleShowTable       (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfShowTable,
             this->getType().getFieldDesc(ShowTableFieldId),
             const_cast<LuaIntrospectionTreeModelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr LuaIntrospectionTreeModelBase::editHandleShowTable      (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfShowTable,
             this->getType().getFieldDesc(ShowTableFieldId),
             this));


    editSField(ShowTableFieldMask);

    return returnValue;
}

GetFieldHandlePtr LuaIntrospectionTreeModelBase::getHandleShowFunction    (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfShowFunction,
             this->getType().getFieldDesc(ShowFunctionFieldId),
             const_cast<LuaIntrospectionTreeModelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr LuaIntrospectionTreeModelBase::editHandleShowFunction   (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfShowFunction,
             this->getType().getFieldDesc(ShowFunctionFieldId),
             this));


    editSField(ShowFunctionFieldMask);

    return returnValue;
}

GetFieldHandlePtr LuaIntrospectionTreeModelBase::getHandleShowNil         (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfShowNil,
             this->getType().getFieldDesc(ShowNilFieldId),
             const_cast<LuaIntrospectionTreeModelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr LuaIntrospectionTreeModelBase::editHandleShowNil        (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfShowNil,
             this->getType().getFieldDesc(ShowNilFieldId),
             this));


    editSField(ShowNilFieldMask);

    return returnValue;
}

GetFieldHandlePtr LuaIntrospectionTreeModelBase::getHandleShowBoolean     (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfShowBoolean,
             this->getType().getFieldDesc(ShowBooleanFieldId),
             const_cast<LuaIntrospectionTreeModelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr LuaIntrospectionTreeModelBase::editHandleShowBoolean    (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfShowBoolean,
             this->getType().getFieldDesc(ShowBooleanFieldId),
             this));


    editSField(ShowBooleanFieldMask);

    return returnValue;
}

GetFieldHandlePtr LuaIntrospectionTreeModelBase::getHandleShowNumber      (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfShowNumber,
             this->getType().getFieldDesc(ShowNumberFieldId),
             const_cast<LuaIntrospectionTreeModelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr LuaIntrospectionTreeModelBase::editHandleShowNumber     (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfShowNumber,
             this->getType().getFieldDesc(ShowNumberFieldId),
             this));


    editSField(ShowNumberFieldMask);

    return returnValue;
}

GetFieldHandlePtr LuaIntrospectionTreeModelBase::getHandleShowString      (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfShowString,
             this->getType().getFieldDesc(ShowStringFieldId),
             const_cast<LuaIntrospectionTreeModelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr LuaIntrospectionTreeModelBase::editHandleShowString     (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfShowString,
             this->getType().getFieldDesc(ShowStringFieldId),
             this));


    editSField(ShowStringFieldMask);

    return returnValue;
}

GetFieldHandlePtr LuaIntrospectionTreeModelBase::getHandleShowThread      (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfShowThread,
             this->getType().getFieldDesc(ShowThreadFieldId),
             const_cast<LuaIntrospectionTreeModelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr LuaIntrospectionTreeModelBase::editHandleShowThread     (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfShowThread,
             this->getType().getFieldDesc(ShowThreadFieldId),
             this));


    editSField(ShowThreadFieldMask);

    return returnValue;
}

GetFieldHandlePtr LuaIntrospectionTreeModelBase::getHandleShowUserData    (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfShowUserData,
             this->getType().getFieldDesc(ShowUserDataFieldId),
             const_cast<LuaIntrospectionTreeModelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr LuaIntrospectionTreeModelBase::editHandleShowUserData   (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfShowUserData,
             this->getType().getFieldDesc(ShowUserDataFieldId),
             this));


    editSField(ShowUserDataFieldMask);

    return returnValue;
}



#ifdef OSG_MT_CPTR_ASPECT
void LuaIntrospectionTreeModelBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    LuaIntrospectionTreeModel *pThis = static_cast<LuaIntrospectionTreeModel *>(this);

    pThis->execSync(static_cast<LuaIntrospectionTreeModel *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *LuaIntrospectionTreeModelBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    LuaIntrospectionTreeModel *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const LuaIntrospectionTreeModel *>(pRefAspect),
                  dynamic_cast<const LuaIntrospectionTreeModel *>(this));

    return returnValue;
}
#endif

void LuaIntrospectionTreeModelBase::resolveLinks(void)
{
    Inherited::resolveLinks();

#ifdef OSG_MT_CPTR_ASPECT
    AspectOffsetStore oOffsets;

    _pAspectStore->fillOffsetArray(oOffsets, this);
#endif

#ifdef OSG_MT_CPTR_ASPECT
    _mfInternalRoot.terminateShare(Thread::getCurrentAspect(),
                                      oOffsets);
#endif
}


OSG_END_NAMESPACE
