/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 *   contact: dirk@opensg.org, gerrit.voss@vossg.org, jbehr@zgdv.de          *
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
 **     class CgfxMaterial!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"



#include "OSGState.h"                   // RenderPassStates Class

#include "OSGCgfxMaterialBase.h"
#include "OSGCgfxMaterial.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::CgfxMaterial
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var State *         CgfxMaterialBase::_mfRenderPassStates
    
*/

/*! \var BitVector       CgfxMaterialBase::_sfSemanticParameters
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<CgfxMaterial *>::_type("CgfxMaterialPtr", "PrimeMaterialPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(CgfxMaterial *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           CgfxMaterial *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           CgfxMaterial *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void CgfxMaterialBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new MFUnrecStatePtr::Description(
        MFUnrecStatePtr::getClassType(),
        "RenderPassStates",
        "",
        RenderPassStatesFieldId, RenderPassStatesFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FNullCheckAccess),
        static_cast<FieldEditMethodSig>(&CgfxMaterial::editHandleRenderPassStates),
        static_cast<FieldGetMethodSig >(&CgfxMaterial::getHandleRenderPassStates));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBitVector::Description(
        SFBitVector::getClassType(),
        "SemanticParameters",
        "",
        SemanticParametersFieldId, SemanticParametersFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&CgfxMaterial::editHandleSemanticParameters),
        static_cast<FieldGetMethodSig >(&CgfxMaterial::getHandleSemanticParameters));

    oType.addInitialDesc(pDesc);
}


CgfxMaterialBase::TypeObject CgfxMaterialBase::_type(
    CgfxMaterialBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&CgfxMaterialBase::createEmptyLocal),
    CgfxMaterial::initMethod,
    CgfxMaterial::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&CgfxMaterial::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"CgfxMaterial\"\n"
    "\tparent=\"PrimeMaterial\"\n"
    "\tlibrary=\"State\"\n"
    "\tpointerfieldtypes=\"both\"\n"
    "\tstructure=\"concrete\"\n"
    "\tsystemcomponent=\"true\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"false\"\n"
    "\tuseLocalIncludes=\"false\"\n"
    ">\n"
    "  <Field\n"
    "\t\tname=\"RenderPassStates\"\n"
    "\t\ttype=\"State\"\n"
    "\t\tcategory=\"pointer\"\n"
    "\t\tcardinality=\"multi\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"protected\"\n"
    "        pushToFieldAs=\"addPassState\"\n"
    "        insertIntoMFieldAs=\"insertPassState\"\n"
    "        replaceInMFieldIndexAs=\"replacePassState\"\n"
    "        replaceInMFieldObjectAs=\"replacePassStateByObj\"\n"
    "        removeFromMFieldIndexAs=\"subPassState\"\n"
    "        removeFromMFieldObjectAs=\"subPassStateByObj\"\n"
    "        clearFieldAs=\"clearPassStates\"\n"
    "        ptrFieldAccess = \"nullCheck\"\n"
    "\t>\n"
    "  </Field>\n"
    "  <Field\n"
    "\tname=\"SemanticParameters\"\n"
    "\ttype=\"BitVector\"\n"
    "\tcategory=\"data\"\n"
    "\tcardinality=\"single\"\n"
    "\tvisibility=\"external\"\n"
    "\taccess=\"protected\"\n"
    "\tdefaultValue=\"0\"\n"
    "\t>\n"
    "  </Field>\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &CgfxMaterialBase::getType(void)
{
    return _type;
}

const FieldContainerType &CgfxMaterialBase::getType(void) const
{
    return _type;
}

UInt32 CgfxMaterialBase::getContainerSize(void) const
{
    return sizeof(CgfxMaterial);
}

/*------------------------- decorator get ------------------------------*/


//! Get the CgfxMaterial::_mfRenderPassStates field.
const MFUnrecStatePtr *CgfxMaterialBase::getMFRenderPassStates(void) const
{
    return &_mfRenderPassStates;
}

SFBitVector *CgfxMaterialBase::editSFSemanticParameters(void)
{
    editSField(SemanticParametersFieldMask);

    return &_sfSemanticParameters;
}

const SFBitVector *CgfxMaterialBase::getSFSemanticParameters(void) const
{
    return &_sfSemanticParameters;
}




void CgfxMaterialBase::addPassState(State * const value)
{
    if(value == NULL)
        return;

    editMField(RenderPassStatesFieldMask, _mfRenderPassStates);

    _mfRenderPassStates.push_back(value);
}

void CgfxMaterialBase::assignRenderPassStates(const MFUnrecStatePtr   &value)
{
    MFUnrecStatePtr  ::const_iterator elemIt  =
        value.begin();
    MFUnrecStatePtr  ::const_iterator elemEnd =
        value.end  ();

    static_cast<CgfxMaterial *>(this)->clearPassStates();

    while(elemIt != elemEnd)
    {
        this->addPassState(*elemIt);

        ++elemIt;
    }
}

void CgfxMaterialBase::insertPassState(UInt32               uiIndex,
                                                   State * const value   )
{
    if(value == NULL)
        return;

    editMField(RenderPassStatesFieldMask, _mfRenderPassStates);

    MFUnrecStatePtr::iterator fieldIt = _mfRenderPassStates.begin_nc();

    fieldIt += uiIndex;

    _mfRenderPassStates.insert(fieldIt, value);
}

void CgfxMaterialBase::replacePassState(UInt32               uiIndex,
                                                       State * const value   )
{
    if(value == NULL)
        return;

    if(uiIndex >= _mfRenderPassStates.size())
        return;

    editMField(RenderPassStatesFieldMask, _mfRenderPassStates);

    _mfRenderPassStates.replace(uiIndex, value);
}

void CgfxMaterialBase::replacePassStateByObj(State * const pOldElem,
                                                        State * const pNewElem)
{
    if(pNewElem == NULL)
        return;

    Int32  elemIdx = _mfRenderPassStates.findIndex(pOldElem);

    if(elemIdx != -1)
    {
        editMField(RenderPassStatesFieldMask, _mfRenderPassStates);

        _mfRenderPassStates.replace(elemIdx, pNewElem);
    }
}

void CgfxMaterialBase::subPassState(UInt32 uiIndex)
{
    if(uiIndex < _mfRenderPassStates.size())
    {
        editMField(RenderPassStatesFieldMask, _mfRenderPassStates);

        _mfRenderPassStates.erase(uiIndex);
    }
}

void CgfxMaterialBase::subPassStateByObj(State * const value)
{
    Int32 iElemIdx = _mfRenderPassStates.findIndex(value);

    if(iElemIdx != -1)
    {
        editMField(RenderPassStatesFieldMask, _mfRenderPassStates);

        _mfRenderPassStates.erase(iElemIdx);
    }
}
void CgfxMaterialBase::clearPassStates(void)
{
    editMField(RenderPassStatesFieldMask, _mfRenderPassStates);


    _mfRenderPassStates.clear();
}



/*------------------------------ access -----------------------------------*/

UInt32 CgfxMaterialBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (RenderPassStatesFieldMask & whichField))
    {
        returnValue += _mfRenderPassStates.getBinSize();
    }
    if(FieldBits::NoField != (SemanticParametersFieldMask & whichField))
    {
        returnValue += _sfSemanticParameters.getBinSize();
    }

    return returnValue;
}

void CgfxMaterialBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (RenderPassStatesFieldMask & whichField))
    {
        _mfRenderPassStates.copyToBin(pMem);
    }
    if(FieldBits::NoField != (SemanticParametersFieldMask & whichField))
    {
        _sfSemanticParameters.copyToBin(pMem);
    }
}

void CgfxMaterialBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (RenderPassStatesFieldMask & whichField))
    {
        _mfRenderPassStates.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (SemanticParametersFieldMask & whichField))
    {
        _sfSemanticParameters.copyFromBin(pMem);
    }
}

//! create a new instance of the class
CgfxMaterialTransitPtr CgfxMaterialBase::createLocal(BitVector bFlags)
{
    CgfxMaterialTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<CgfxMaterial>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
CgfxMaterialTransitPtr CgfxMaterialBase::createDependent(BitVector bFlags)
{
    CgfxMaterialTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<CgfxMaterial>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
CgfxMaterialTransitPtr CgfxMaterialBase::create(void)
{
    CgfxMaterialTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<CgfxMaterial>(tmpPtr);
    }

    return fc;
}

CgfxMaterial *CgfxMaterialBase::createEmptyLocal(BitVector bFlags)
{
    CgfxMaterial *returnValue;

    newPtr<CgfxMaterial>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
CgfxMaterial *CgfxMaterialBase::createEmpty(void)
{
    CgfxMaterial *returnValue;

    newPtr<CgfxMaterial>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr CgfxMaterialBase::shallowCopyLocal(
    BitVector bFlags) const
{
    CgfxMaterial *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const CgfxMaterial *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr CgfxMaterialBase::shallowCopyDependent(
    BitVector bFlags) const
{
    CgfxMaterial *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const CgfxMaterial *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr CgfxMaterialBase::shallowCopy(void) const
{
    CgfxMaterial *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const CgfxMaterial *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

CgfxMaterialBase::CgfxMaterialBase(void) :
    Inherited(),
    _mfRenderPassStates       (),
    _sfSemanticParameters     (BitVector(0))
{
}

CgfxMaterialBase::CgfxMaterialBase(const CgfxMaterialBase &source) :
    Inherited(source),
    _mfRenderPassStates       (),
    _sfSemanticParameters     (source._sfSemanticParameters     )
{
}


/*-------------------------- destructors ----------------------------------*/

CgfxMaterialBase::~CgfxMaterialBase(void)
{
}

void CgfxMaterialBase::onCreate(const CgfxMaterial *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        CgfxMaterial *pThis = static_cast<CgfxMaterial *>(this);

        MFUnrecStatePtr::const_iterator RenderPassStatesIt  =
            source->_mfRenderPassStates.begin();
        MFUnrecStatePtr::const_iterator RenderPassStatesEnd =
            source->_mfRenderPassStates.end  ();

        while(RenderPassStatesIt != RenderPassStatesEnd)
        {
            pThis->addPassState(*RenderPassStatesIt);

            ++RenderPassStatesIt;
        }
    }
}

GetFieldHandlePtr CgfxMaterialBase::getHandleRenderPassStates (void) const
{
    MFUnrecStatePtr::GetHandlePtr returnValue(
        new  MFUnrecStatePtr::GetHandle(
             &_mfRenderPassStates,
             this->getType().getFieldDesc(RenderPassStatesFieldId),
             const_cast<CgfxMaterialBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr CgfxMaterialBase::editHandleRenderPassStates(void)
{
    MFUnrecStatePtr::EditHandlePtr returnValue(
        new  MFUnrecStatePtr::EditHandle(
             &_mfRenderPassStates,
             this->getType().getFieldDesc(RenderPassStatesFieldId),
             this));

    returnValue->setAddMethod(
        boost::bind(&CgfxMaterial::addPassState,
                    static_cast<CgfxMaterial *>(this), _1));
    returnValue->setInsertMethod(
        boost::bind(&CgfxMaterial::insertPassState,
                    static_cast<CgfxMaterial *>(this), _1, _2));
    returnValue->setReplaceMethod(
        boost::bind(&CgfxMaterial::replacePassState,
                    static_cast<CgfxMaterial *>(this), _1, _2));
    returnValue->setReplaceObjMethod(
        boost::bind(&CgfxMaterial::replacePassStateByObj,
                    static_cast<CgfxMaterial *>(this), _1, _2));
    returnValue->setRemoveMethod(
        boost::bind(&CgfxMaterial::subPassState,
                    static_cast<CgfxMaterial *>(this), _1));
    returnValue->setRemoveObjMethod(
        boost::bind(&CgfxMaterial::subPassStateByObj,
                    static_cast<CgfxMaterial *>(this), _1));
    returnValue->setClearMethod(
        boost::bind(&CgfxMaterial::clearPassStates,
                    static_cast<CgfxMaterial *>(this)));

    editMField(RenderPassStatesFieldMask, _mfRenderPassStates);

    return returnValue;
}

GetFieldHandlePtr CgfxMaterialBase::getHandleSemanticParameters (void) const
{
    SFBitVector::GetHandlePtr returnValue(
        new  SFBitVector::GetHandle(
             &_sfSemanticParameters,
             this->getType().getFieldDesc(SemanticParametersFieldId),
             const_cast<CgfxMaterialBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr CgfxMaterialBase::editHandleSemanticParameters(void)
{
    SFBitVector::EditHandlePtr returnValue(
        new  SFBitVector::EditHandle(
             &_sfSemanticParameters,
             this->getType().getFieldDesc(SemanticParametersFieldId),
             this));


    editSField(SemanticParametersFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void CgfxMaterialBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    CgfxMaterial *pThis = static_cast<CgfxMaterial *>(this);

    pThis->execSync(static_cast<CgfxMaterial *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *CgfxMaterialBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    CgfxMaterial *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const CgfxMaterial *>(pRefAspect),
                  dynamic_cast<const CgfxMaterial *>(this));

    return returnValue;
}
#endif

void CgfxMaterialBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<CgfxMaterial *>(this)->clearPassStates();


}


OSG_END_NAMESPACE