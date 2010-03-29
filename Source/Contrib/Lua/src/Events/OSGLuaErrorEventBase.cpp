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
 **     class LuaErrorEvent!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGLuaErrorEventBase.h"
#include "OSGLuaErrorEvent.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::LuaErrorEvent
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var VoidP           LuaErrorEventBase::_sfLuaStateVoidP
    
*/

/*! \var Int32           LuaErrorEventBase::_sfStatus
    
*/

/*! \var std::string     LuaErrorEventBase::_mfStackTrace
    
*/

/*! \var bool            LuaErrorEventBase::_sfStackTraceEnabled
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<LuaErrorEvent *>::_type("LuaErrorEventPtr", "EventPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(LuaErrorEvent *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           LuaErrorEvent *,
                           0);


/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void LuaErrorEventBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFVoidP::Description(
        SFVoidP::getClassType(),
        "LuaStateVoidP",
        "",
        LuaStateVoidPFieldId, LuaStateVoidPFieldMask,
        true,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&LuaErrorEvent::editHandleLuaStateVoidP),
        static_cast<FieldGetMethodSig >(&LuaErrorEvent::getHandleLuaStateVoidP));

    oType.addInitialDesc(pDesc);

    pDesc = new SFInt32::Description(
        SFInt32::getClassType(),
        "Status",
        "",
        StatusFieldId, StatusFieldMask,
        true,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&LuaErrorEvent::editHandleStatus),
        static_cast<FieldGetMethodSig >(&LuaErrorEvent::getHandleStatus));

    oType.addInitialDesc(pDesc);

    pDesc = new MFString::Description(
        MFString::getClassType(),
        "StackTrace",
        "",
        StackTraceFieldId, StackTraceFieldMask,
        true,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&LuaErrorEvent::editHandleStackTrace),
        static_cast<FieldGetMethodSig >(&LuaErrorEvent::getHandleStackTrace));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "StackTraceEnabled",
        "",
        StackTraceEnabledFieldId, StackTraceEnabledFieldMask,
        true,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&LuaErrorEvent::editHandleStackTraceEnabled),
        static_cast<FieldGetMethodSig >(&LuaErrorEvent::getHandleStackTraceEnabled));

    oType.addInitialDesc(pDesc);
}


LuaErrorEventBase::TypeObject LuaErrorEventBase::_type(
    LuaErrorEventBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&LuaErrorEventBase::createEmptyLocal),
    LuaErrorEvent::initMethod,
    LuaErrorEvent::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&LuaErrorEvent::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"LuaErrorEvent\"\n"
    "\tparent=\"Event\"\n"
    "    library=\"ContribLua\"\n"
    "    pointerfieldtypes=\"single\"\n"
    "    structure=\"concrete\"\n"
    "    systemcomponent=\"true\"\n"
    "    parentsystemcomponent=\"true\"\n"
    "    decoratable=\"false\"\n"
    "    useLocalIncludes=\"false\"\n"
    "    isNodeCore=\"false\"\n"
    "    isBundle=\"true\"\n"
    "    authors=\"David Kabala (djkabala@gmail.com)                             \"\n"
    ">\n"
    "    <Field\n"
    "        name=\"LuaStateVoidP\"\n"
    "        type=\"VoidP\"\n"
    "\t\tcategory=\"data\"\n"
    "        cardinality=\"single\"\n"
    "        visibility=\"internal\"\n"
    "        access=\"protected\"\n"
    "        defaultValue=\"NULL\"\n"
    "        publicRead=\"true\"\n"
    "    >\n"
    "    </Field>\n"
    "\t<Field\n"
    "\t\tname=\"Status\"\n"
    "\t\ttype=\"Int32\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\taccess=\"protected\"\n"
    "\t\tdefaultValue=\"0\"\n"
    "        publicRead=\"true\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"StackTrace\"\n"
    "\t\ttype=\"std::string\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"multi\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\taccess=\"protected\"\n"
    "        publicRead=\"true\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"StackTraceEnabled\"\n"
    "\t\ttype=\"bool\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\taccess=\"protected\"\n"
    "\t\tdefaultValue=\"false\"\n"
    "        publicRead=\"true\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &LuaErrorEventBase::getType(void)
{
    return _type;
}

const FieldContainerType &LuaErrorEventBase::getType(void) const
{
    return _type;
}

UInt32 LuaErrorEventBase::getContainerSize(void) const
{
    return sizeof(LuaErrorEvent);
}

/*------------------------- decorator get ------------------------------*/


SFVoidP *LuaErrorEventBase::editSFLuaStateVoidP(void)
{
    editSField(LuaStateVoidPFieldMask);

    return &_sfLuaStateVoidP;
}

const SFVoidP *LuaErrorEventBase::getSFLuaStateVoidP(void) const
{
    return &_sfLuaStateVoidP;
}


SFInt32 *LuaErrorEventBase::editSFStatus(void)
{
    editSField(StatusFieldMask);

    return &_sfStatus;
}

const SFInt32 *LuaErrorEventBase::getSFStatus(void) const
{
    return &_sfStatus;
}


MFString *LuaErrorEventBase::editMFStackTrace(void)
{
    editMField(StackTraceFieldMask, _mfStackTrace);

    return &_mfStackTrace;
}

const MFString *LuaErrorEventBase::getMFStackTrace(void) const
{
    return &_mfStackTrace;
}


SFBool *LuaErrorEventBase::editSFStackTraceEnabled(void)
{
    editSField(StackTraceEnabledFieldMask);

    return &_sfStackTraceEnabled;
}

const SFBool *LuaErrorEventBase::getSFStackTraceEnabled(void) const
{
    return &_sfStackTraceEnabled;
}






/*------------------------------ access -----------------------------------*/

UInt32 LuaErrorEventBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (LuaStateVoidPFieldMask & whichField))
    {
        returnValue += _sfLuaStateVoidP.getBinSize();
    }
    if(FieldBits::NoField != (StatusFieldMask & whichField))
    {
        returnValue += _sfStatus.getBinSize();
    }
    if(FieldBits::NoField != (StackTraceFieldMask & whichField))
    {
        returnValue += _mfStackTrace.getBinSize();
    }
    if(FieldBits::NoField != (StackTraceEnabledFieldMask & whichField))
    {
        returnValue += _sfStackTraceEnabled.getBinSize();
    }

    return returnValue;
}

void LuaErrorEventBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (LuaStateVoidPFieldMask & whichField))
    {
        _sfLuaStateVoidP.copyToBin(pMem);
    }
    if(FieldBits::NoField != (StatusFieldMask & whichField))
    {
        _sfStatus.copyToBin(pMem);
    }
    if(FieldBits::NoField != (StackTraceFieldMask & whichField))
    {
        _mfStackTrace.copyToBin(pMem);
    }
    if(FieldBits::NoField != (StackTraceEnabledFieldMask & whichField))
    {
        _sfStackTraceEnabled.copyToBin(pMem);
    }
}

void LuaErrorEventBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (LuaStateVoidPFieldMask & whichField))
    {
        _sfLuaStateVoidP.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (StatusFieldMask & whichField))
    {
        _sfStatus.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (StackTraceFieldMask & whichField))
    {
        _mfStackTrace.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (StackTraceEnabledFieldMask & whichField))
    {
        _sfStackTraceEnabled.copyFromBin(pMem);
    }
}

//! create a new instance of the class
LuaErrorEventTransitPtr LuaErrorEventBase::createLocal(BitVector bFlags)
{
    LuaErrorEventTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<LuaErrorEvent>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
LuaErrorEventTransitPtr LuaErrorEventBase::createDependent(BitVector bFlags)
{
    LuaErrorEventTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<LuaErrorEvent>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
LuaErrorEventTransitPtr LuaErrorEventBase::create(void)
{
    return createLocal();
}

LuaErrorEvent *LuaErrorEventBase::createEmptyLocal(BitVector bFlags)
{
    LuaErrorEvent *returnValue;

    newPtr<LuaErrorEvent>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
LuaErrorEvent *LuaErrorEventBase::createEmpty(void)
{
    return createEmptyLocal();
}


FieldContainerTransitPtr LuaErrorEventBase::shallowCopyLocal(
    BitVector bFlags) const
{
    LuaErrorEvent *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const LuaErrorEvent *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr LuaErrorEventBase::shallowCopyDependent(
    BitVector bFlags) const
{
    LuaErrorEvent *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const LuaErrorEvent *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr LuaErrorEventBase::shallowCopy(void) const
{
    return shallowCopyLocal();
}




/*------------------------- constructors ----------------------------------*/

LuaErrorEventBase::LuaErrorEventBase(void) :
    Inherited(),
    _sfLuaStateVoidP          (VoidP(NULL)),
    _sfStatus                 (Int32(0)),
    _mfStackTrace             (),
    _sfStackTraceEnabled      (bool(false))
{
}

LuaErrorEventBase::LuaErrorEventBase(const LuaErrorEventBase &source) :
    Inherited(source),
    _sfLuaStateVoidP          (source._sfLuaStateVoidP          ),
    _sfStatus                 (source._sfStatus                 ),
    _mfStackTrace             (source._mfStackTrace             ),
    _sfStackTraceEnabled      (source._sfStackTraceEnabled      )
{
}


/*-------------------------- destructors ----------------------------------*/

LuaErrorEventBase::~LuaErrorEventBase(void)
{
}


GetFieldHandlePtr LuaErrorEventBase::getHandleLuaStateVoidP   (void) const
{
    SFVoidP::GetHandlePtr returnValue(
        new  SFVoidP::GetHandle(
             &_sfLuaStateVoidP,
             this->getType().getFieldDesc(LuaStateVoidPFieldId),
             const_cast<LuaErrorEventBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr LuaErrorEventBase::editHandleLuaStateVoidP  (void)
{
    SFVoidP::EditHandlePtr returnValue(
        new  SFVoidP::EditHandle(
             &_sfLuaStateVoidP,
             this->getType().getFieldDesc(LuaStateVoidPFieldId),
             this));


    editSField(LuaStateVoidPFieldMask);

    return returnValue;
}

GetFieldHandlePtr LuaErrorEventBase::getHandleStatus          (void) const
{
    SFInt32::GetHandlePtr returnValue(
        new  SFInt32::GetHandle(
             &_sfStatus,
             this->getType().getFieldDesc(StatusFieldId),
             const_cast<LuaErrorEventBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr LuaErrorEventBase::editHandleStatus         (void)
{
    SFInt32::EditHandlePtr returnValue(
        new  SFInt32::EditHandle(
             &_sfStatus,
             this->getType().getFieldDesc(StatusFieldId),
             this));


    editSField(StatusFieldMask);

    return returnValue;
}

GetFieldHandlePtr LuaErrorEventBase::getHandleStackTrace      (void) const
{
    MFString::GetHandlePtr returnValue(
        new  MFString::GetHandle(
             &_mfStackTrace,
             this->getType().getFieldDesc(StackTraceFieldId),
             const_cast<LuaErrorEventBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr LuaErrorEventBase::editHandleStackTrace     (void)
{
    MFString::EditHandlePtr returnValue(
        new  MFString::EditHandle(
             &_mfStackTrace,
             this->getType().getFieldDesc(StackTraceFieldId),
             this));


    editMField(StackTraceFieldMask, _mfStackTrace);

    return returnValue;
}

GetFieldHandlePtr LuaErrorEventBase::getHandleStackTraceEnabled (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfStackTraceEnabled,
             this->getType().getFieldDesc(StackTraceEnabledFieldId),
             const_cast<LuaErrorEventBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr LuaErrorEventBase::editHandleStackTraceEnabled(void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfStackTraceEnabled,
             this->getType().getFieldDesc(StackTraceEnabledFieldId),
             this));


    editSField(StackTraceEnabledFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void LuaErrorEventBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    LuaErrorEvent *pThis = static_cast<LuaErrorEvent *>(this);

    pThis->execSync(static_cast<LuaErrorEvent *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *LuaErrorEventBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    LuaErrorEvent *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const LuaErrorEvent *>(pRefAspect),
                  dynamic_cast<const LuaErrorEvent *>(this));

    return returnValue;
}
#endif

void LuaErrorEventBase::resolveLinks(void)
{
    Inherited::resolveLinks();

#ifdef OSG_MT_CPTR_ASPECT
    AspectOffsetStore oOffsets;

    _pAspectStore->fillOffsetArray(oOffsets, this);
#endif

#ifdef OSG_MT_CPTR_ASPECT
    _mfStackTrace.terminateShare(Thread::getCurrentAspect(),
                                      oOffsets);
#endif
}


OSG_END_NAMESPACE
