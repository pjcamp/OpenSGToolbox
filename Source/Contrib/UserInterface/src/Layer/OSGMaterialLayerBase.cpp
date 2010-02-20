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
 **     class MaterialLayer!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"



#include "OSGMaterial.h"                // Material Class

#include "OSGMaterialLayerBase.h"
#include "OSGMaterialLayer.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::MaterialLayer
    UI Material Background.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Material *      MaterialLayerBase::_sfMaterial
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<MaterialLayer *>::_type("MaterialLayerPtr", "LayerPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(MaterialLayer *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           MaterialLayer *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           MaterialLayer *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void MaterialLayerBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFUnrecMaterialPtr::Description(
        SFUnrecMaterialPtr::getClassType(),
        "Material",
        "",
        MaterialFieldId, MaterialFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&MaterialLayer::editHandleMaterial),
        static_cast<FieldGetMethodSig >(&MaterialLayer::getHandleMaterial));

    oType.addInitialDesc(pDesc);

}


MaterialLayerBase::TypeObject MaterialLayerBase::_type(
    MaterialLayerBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&MaterialLayerBase::createEmptyLocal),
    MaterialLayer::initMethod,
    MaterialLayer::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&MaterialLayer::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"MaterialLayer\"\n"
    "\tparent=\"Layer\"\n"
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
    "UI Material Background.\n"
    "\t<Field\n"
    "\t\tname=\"Material\"\n"
    "\t\ttype=\"Material\"\n"
    "        category=\"pointer\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "        defaultValue=\"NULL\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "UI Material Background.\n"
    );


/*------------------------------ get -----------------------------------*/

FieldContainerType &MaterialLayerBase::getType(void)
{
    return _type;
}

const FieldContainerType &MaterialLayerBase::getType(void) const
{
    return _type;
}

UInt32 MaterialLayerBase::getContainerSize(void) const
{
    return sizeof(MaterialLayer);
}

/*------------------------- decorator get ------------------------------*/


//! Get the MaterialLayer::_sfMaterial field.
const SFUnrecMaterialPtr *MaterialLayerBase::getSFMaterial(void) const
{
    return &_sfMaterial;
}

SFUnrecMaterialPtr  *MaterialLayerBase::editSFMaterial       (void)
{
    editSField(MaterialFieldMask);

    return &_sfMaterial;
}





/*------------------------------ access -----------------------------------*/

UInt32 MaterialLayerBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (MaterialFieldMask & whichField))
    {
        returnValue += _sfMaterial.getBinSize();
    }

    return returnValue;
}

void MaterialLayerBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (MaterialFieldMask & whichField))
    {
        _sfMaterial.copyToBin(pMem);
    }
}

void MaterialLayerBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (MaterialFieldMask & whichField))
    {
        _sfMaterial.copyFromBin(pMem);
    }
}

//! create a new instance of the class
MaterialLayerTransitPtr MaterialLayerBase::createLocal(BitVector bFlags)
{
    MaterialLayerTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<MaterialLayer>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
MaterialLayerTransitPtr MaterialLayerBase::createDependent(BitVector bFlags)
{
    MaterialLayerTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<MaterialLayer>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
MaterialLayerTransitPtr MaterialLayerBase::create(void)
{
    MaterialLayerTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<MaterialLayer>(tmpPtr);
    }

    return fc;
}

MaterialLayer *MaterialLayerBase::createEmptyLocal(BitVector bFlags)
{
    MaterialLayer *returnValue;

    newPtr<MaterialLayer>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
MaterialLayer *MaterialLayerBase::createEmpty(void)
{
    MaterialLayer *returnValue;

    newPtr<MaterialLayer>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr MaterialLayerBase::shallowCopyLocal(
    BitVector bFlags) const
{
    MaterialLayer *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const MaterialLayer *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr MaterialLayerBase::shallowCopyDependent(
    BitVector bFlags) const
{
    MaterialLayer *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const MaterialLayer *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr MaterialLayerBase::shallowCopy(void) const
{
    MaterialLayer *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const MaterialLayer *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

MaterialLayerBase::MaterialLayerBase(void) :
    Inherited(),
    _sfMaterial               (NULL)
{
}

MaterialLayerBase::MaterialLayerBase(const MaterialLayerBase &source) :
    Inherited(source),
    _sfMaterial               (NULL)
{
}


/*-------------------------- destructors ----------------------------------*/

MaterialLayerBase::~MaterialLayerBase(void)
{
}

void MaterialLayerBase::onCreate(const MaterialLayer *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        MaterialLayer *pThis = static_cast<MaterialLayer *>(this);

        pThis->setMaterial(source->getMaterial());
    }
}

GetFieldHandlePtr MaterialLayerBase::getHandleMaterial        (void) const
{
    SFUnrecMaterialPtr::GetHandlePtr returnValue(
        new  SFUnrecMaterialPtr::GetHandle(
             &_sfMaterial,
             this->getType().getFieldDesc(MaterialFieldId),
             const_cast<MaterialLayerBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr MaterialLayerBase::editHandleMaterial       (void)
{
    SFUnrecMaterialPtr::EditHandlePtr returnValue(
        new  SFUnrecMaterialPtr::EditHandle(
             &_sfMaterial,
             this->getType().getFieldDesc(MaterialFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&MaterialLayer::setMaterial,
                    static_cast<MaterialLayer *>(this), _1));

    editSField(MaterialFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void MaterialLayerBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    MaterialLayer *pThis = static_cast<MaterialLayer *>(this);

    pThis->execSync(static_cast<MaterialLayer *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *MaterialLayerBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    MaterialLayer *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const MaterialLayer *>(pRefAspect),
                  dynamic_cast<const MaterialLayer *>(this));

    return returnValue;
}
#endif

void MaterialLayerBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<MaterialLayer *>(this)->setMaterial(NULL);


}


OSG_END_NAMESPACE
