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
 **     class ComponentContainer!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"



#include "OSGComponent.h"               // Children Class
#include "OSGLayout.h"                  // Layout Class

#include "OSGComponentContainerBase.h"
#include "OSGComponentContainer.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::ComponentContainer
    A UI Container.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Component *     ComponentContainerBase::_mfChildren
    
*/

/*! \var Layout *        ComponentContainerBase::_sfLayout
    
*/

/*! \var Vec4f           ComponentContainerBase::_sfInset
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<ComponentContainer *>::_type("ComponentContainerPtr", "ComponentPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(ComponentContainer *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           ComponentContainer *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           ComponentContainer *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void ComponentContainerBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new MFUnrecChildComponentPtr::Description(
        MFUnrecChildComponentPtr::getClassType(),
        "Children",
        "",
        ChildrenFieldId, ChildrenFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FNullCheckAccess),
        static_cast<FieldEditMethodSig>(&ComponentContainer::editHandleChildren),
        static_cast<FieldGetMethodSig >(&ComponentContainer::getHandleChildren));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUnrecChildLayoutPtr::Description(
        SFUnrecChildLayoutPtr::getClassType(),
        "Layout",
        "",
        LayoutFieldId, LayoutFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FNullCheckAccess),
        static_cast<FieldEditMethodSig>(&ComponentContainer::editHandleLayout),
        static_cast<FieldGetMethodSig >(&ComponentContainer::getHandleLayout));

    oType.addInitialDesc(pDesc);

    pDesc = new SFVec4f::Description(
        SFVec4f::getClassType(),
        "Inset",
        "",
        InsetFieldId, InsetFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&ComponentContainer::editHandleInset),
        static_cast<FieldGetMethodSig >(&ComponentContainer::getHandleInset));

    oType.addInitialDesc(pDesc);
}


ComponentContainerBase::TypeObject ComponentContainerBase::_type(
    ComponentContainerBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    NULL,
    ComponentContainer::initMethod,
    ComponentContainer::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&ComponentContainer::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"ComponentContainer\"\n"
    "\tparent=\"Component\"\n"
    "    library=\"ContribUserInterface\"\n"
    "    pointerfieldtypes=\"both\"\n"
    "\tstructure=\"abstract\"\n"
    "    systemcomponent=\"true\"\n"
    "    parentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"false\"\n"
    "    useLocalIncludes=\"false\"\n"
    "    isNodeCore=\"false\"\n"
    "    authors=\"David Kabala (djkabala@gmail.com)                             \"\n"
    ">\n"
    "A UI Container.\n"
    "\t<Field\n"
    "\t\tname=\"Children\"\n"
    "\t\ttype=\"Component\"\n"
    "\t\tcardinality=\"multi\"\n"
    "        category=\"childpointer\"\n"
    "        childParentType=\"FieldContainer\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "        ptrFieldAccess = \"nullCheck\"\n"
    "        linkParentField=\"ParentContainer\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"Layout\"\n"
    "\t\ttype=\"Layout\"\n"
    "\t\tcardinality=\"single\"\n"
    "        category=\"childpointer\"\n"
    "        childParentType=\"FieldContainer\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "        ptrFieldAccess = \"nullCheck\"\n"
    "        linkParentField=\"ParentContainer\"\n"
    "\t\tdefaultValue=\"NULL\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"Inset\"\n"
    "\t\ttype=\"Vec4f\"\n"
    "\t\tcategory=\"data\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"0.0f,0.0f,0.0f,0.0f\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "A UI Container.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &ComponentContainerBase::getType(void)
{
    return _type;
}

const FieldContainerType &ComponentContainerBase::getType(void) const
{
    return _type;
}

UInt32 ComponentContainerBase::getContainerSize(void) const
{
    return sizeof(ComponentContainer);
}

/*------------------------- decorator get ------------------------------*/


//! Get the ComponentContainer::_mfChildren field.
const MFUnrecChildComponentPtr *ComponentContainerBase::getMFChildren(void) const
{
    return &_mfChildren;
}

//! Get the ComponentContainer::_sfLayout field.
const SFUnrecChildLayoutPtr *ComponentContainerBase::getSFLayout(void) const
{
    return &_sfLayout;
}

SFUnrecChildLayoutPtr *ComponentContainerBase::editSFLayout         (void)
{
    editSField(LayoutFieldMask);

    return &_sfLayout;
}

SFVec4f *ComponentContainerBase::editSFInset(void)
{
    editSField(InsetFieldMask);

    return &_sfInset;
}

const SFVec4f *ComponentContainerBase::getSFInset(void) const
{
    return &_sfInset;
}




void ComponentContainerBase::pushToChildren(Component * const value)
{
    if(value == NULL)
        return;

    editMField(ChildrenFieldMask, _mfChildren);

    _mfChildren.push_back(value);
}

void ComponentContainerBase::assignChildren (const MFUnrecChildComponentPtr &value)
{
    MFUnrecChildComponentPtr::const_iterator elemIt  =
        value.begin();
    MFUnrecChildComponentPtr::const_iterator elemEnd =
        value.end  ();

    static_cast<ComponentContainer *>(this)->clearChildren();

    while(elemIt != elemEnd)
    {
        this->pushToChildren(*elemIt);

        ++elemIt;
    }
}

void ComponentContainerBase::insertIntoChildren(UInt32               uiIndex,
                                                   Component * const value   )
{
    if(value == NULL)
        return;

    editMField(ChildrenFieldMask, _mfChildren);

    MFUnrecChildComponentPtr::iterator fieldIt = _mfChildren.begin_nc();

    fieldIt += uiIndex;

    _mfChildren.insert(fieldIt, value);
}

void ComponentContainerBase::replaceInChildren(UInt32               uiIndex,
                                                       Component * const value   )
{
    if(value == NULL)
        return;

    if(uiIndex >= _mfChildren.size())
        return;

    editMField(ChildrenFieldMask, _mfChildren);

    _mfChildren.replace(uiIndex, value);
}

void ComponentContainerBase::replaceObjInChildren(Component * const pOldElem,
                                                        Component * const pNewElem)
{
    if(pNewElem == NULL)
        return;

    Int32  elemIdx = _mfChildren.findIndex(pOldElem);

    if(elemIdx != -1)
    {
        editMField(ChildrenFieldMask, _mfChildren);

        _mfChildren.replace(elemIdx, pNewElem);
    }
}

void ComponentContainerBase::removeFromChildren(UInt32 uiIndex)
{
    if(uiIndex < _mfChildren.size())
    {
        editMField(ChildrenFieldMask, _mfChildren);

        _mfChildren.erase(uiIndex);
    }
}

void ComponentContainerBase::removeObjFromChildren(Component * const value)
{
    Int32 iElemIdx = _mfChildren.findIndex(value);

    if(iElemIdx != -1)
    {
        editMField(ChildrenFieldMask, _mfChildren);

        _mfChildren.erase(iElemIdx);
    }
}
void ComponentContainerBase::clearChildren(void)
{
    editMField(ChildrenFieldMask, _mfChildren);


    _mfChildren.clear();
}



/*------------------------------ access -----------------------------------*/

UInt32 ComponentContainerBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ChildrenFieldMask & whichField))
    {
        returnValue += _mfChildren.getBinSize();
    }
    if(FieldBits::NoField != (LayoutFieldMask & whichField))
    {
        returnValue += _sfLayout.getBinSize();
    }
    if(FieldBits::NoField != (InsetFieldMask & whichField))
    {
        returnValue += _sfInset.getBinSize();
    }

    return returnValue;
}

void ComponentContainerBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ChildrenFieldMask & whichField))
    {
        _mfChildren.copyToBin(pMem);
    }
    if(FieldBits::NoField != (LayoutFieldMask & whichField))
    {
        _sfLayout.copyToBin(pMem);
    }
    if(FieldBits::NoField != (InsetFieldMask & whichField))
    {
        _sfInset.copyToBin(pMem);
    }
}

void ComponentContainerBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ChildrenFieldMask & whichField))
    {
        _mfChildren.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (LayoutFieldMask & whichField))
    {
        _sfLayout.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (InsetFieldMask & whichField))
    {
        _sfInset.copyFromBin(pMem);
    }
}




/*------------------------- constructors ----------------------------------*/

ComponentContainerBase::ComponentContainerBase(void) :
    Inherited(),
    _mfChildren               (this,
                          ChildrenFieldId,
                          Component::ParentContainerFieldId),
    _sfLayout                 (this,
                          LayoutFieldId,
                          Layout::ParentContainersFieldId),
    _sfInset                  (Vec4f(0.0f,0.0f,0.0f,0.0f))
{
}

ComponentContainerBase::ComponentContainerBase(const ComponentContainerBase &source) :
    Inherited(source),
    _mfChildren               (this,
                          ChildrenFieldId,
                          Component::ParentContainerFieldId),
    _sfLayout                 (this,
                          LayoutFieldId,
                          Layout::ParentContainersFieldId),
    _sfInset                  (source._sfInset                  )
{
}


/*-------------------------- destructors ----------------------------------*/

ComponentContainerBase::~ComponentContainerBase(void)
{
}

/*-------------------------------------------------------------------------*/
/* Child linking                                                           */

bool ComponentContainerBase::unlinkChild(
    FieldContainer * const pChild,
    UInt16           const childFieldId)
{
    if(childFieldId == ChildrenFieldId)
    {
        Component * pTypedChild =
            dynamic_cast<Component *>(pChild);

        if(pTypedChild != NULL)
        {
            Int32 iChildIdx = _mfChildren.findIndex(pTypedChild);

            if(iChildIdx != -1)
            {
                editMField(ChildrenFieldMask, _mfChildren);

                _mfChildren.erase(iChildIdx);

                return true;
            }

            FWARNING(("ComponentContainerBase::unlinkParent: Child <-> "
                      "Parent link inconsistent.\n"));

            return false;
        }

        return false;
    }

    if(childFieldId == LayoutFieldId)
    {
        Layout * pTypedChild =
            dynamic_cast<Layout *>(pChild);

        if(pTypedChild != NULL)
        {
            if(pTypedChild == _sfLayout.getValue())
            {
                editSField(LayoutFieldMask);

                _sfLayout.setValue(NULL);

                return true;
            }

            FWARNING(("ComponentContainerBase::unlinkParent: Child <-> "
                      "Parent link inconsistent.\n"));

            return false;
        }

        return false;
    }


    return Inherited::unlinkChild(pChild, childFieldId);
}

void ComponentContainerBase::onCreate(const ComponentContainer *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        ComponentContainer *pThis = static_cast<ComponentContainer *>(this);

        MFUnrecChildComponentPtr::const_iterator ChildrenIt  =
            source->_mfChildren.begin();
        MFUnrecChildComponentPtr::const_iterator ChildrenEnd =
            source->_mfChildren.end  ();

        while(ChildrenIt != ChildrenEnd)
        {
            ComponentUnrecPtr copy(dynamic_pointer_cast<Component>((*ChildrenIt)->shallowCopy()));
            pThis->pushToChildren(copy);

            ++ChildrenIt;
        }

        pThis->setLayout(source->getLayout());
    }
}

GetFieldHandlePtr ComponentContainerBase::getHandleChildren        (void) const
{
    MFUnrecChildComponentPtr::GetHandlePtr returnValue(
        new  MFUnrecChildComponentPtr::GetHandle(
             &_mfChildren,
             this->getType().getFieldDesc(ChildrenFieldId),
             const_cast<ComponentContainerBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ComponentContainerBase::editHandleChildren       (void)
{
    MFUnrecChildComponentPtr::EditHandlePtr returnValue(
        new  MFUnrecChildComponentPtr::EditHandle(
             &_mfChildren,
             this->getType().getFieldDesc(ChildrenFieldId),
             this));

    returnValue->setAddMethod(
        boost::bind(&ComponentContainer::pushToChildren,
                    static_cast<ComponentContainer *>(this), _1));
    returnValue->setInsertMethod(
        boost::bind(&ComponentContainer::insertIntoChildren,
                    static_cast<ComponentContainer *>(this), _1, _2));
    returnValue->setReplaceMethod(
        boost::bind(&ComponentContainer::replaceInChildren,
                    static_cast<ComponentContainer *>(this), _1, _2));
    returnValue->setReplaceObjMethod(
        boost::bind(&ComponentContainer::replaceObjInChildren,
                    static_cast<ComponentContainer *>(this), _1, _2));
    returnValue->setRemoveMethod(
        boost::bind(&ComponentContainer::removeFromChildren,
                    static_cast<ComponentContainer *>(this), _1));
    returnValue->setRemoveObjMethod(
        boost::bind(&ComponentContainer::removeObjFromChildren,
                    static_cast<ComponentContainer *>(this), _1));
    returnValue->setClearMethod(
        boost::bind(&ComponentContainer::clearChildren,
                    static_cast<ComponentContainer *>(this)));

    editMField(ChildrenFieldMask, _mfChildren);

    return returnValue;
}

GetFieldHandlePtr ComponentContainerBase::getHandleLayout          (void) const
{
    SFUnrecChildLayoutPtr::GetHandlePtr returnValue(
        new  SFUnrecChildLayoutPtr::GetHandle(
             &_sfLayout,
             this->getType().getFieldDesc(LayoutFieldId),
             const_cast<ComponentContainerBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ComponentContainerBase::editHandleLayout         (void)
{
    SFUnrecChildLayoutPtr::EditHandlePtr returnValue(
        new  SFUnrecChildLayoutPtr::EditHandle(
             &_sfLayout,
             this->getType().getFieldDesc(LayoutFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&ComponentContainer::setLayout,
                    static_cast<ComponentContainer *>(this), _1));

    editSField(LayoutFieldMask);

    return returnValue;
}

GetFieldHandlePtr ComponentContainerBase::getHandleInset           (void) const
{
    SFVec4f::GetHandlePtr returnValue(
        new  SFVec4f::GetHandle(
             &_sfInset,
             this->getType().getFieldDesc(InsetFieldId),
             const_cast<ComponentContainerBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ComponentContainerBase::editHandleInset          (void)
{
    SFVec4f::EditHandlePtr returnValue(
        new  SFVec4f::EditHandle(
             &_sfInset,
             this->getType().getFieldDesc(InsetFieldId),
             this));


    editSField(InsetFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void ComponentContainerBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    ComponentContainer *pThis = static_cast<ComponentContainer *>(this);

    pThis->execSync(static_cast<ComponentContainer *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif



void ComponentContainerBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<ComponentContainer *>(this)->clearChildren();

    static_cast<ComponentContainer *>(this)->setLayout(NULL);


}


OSG_END_NAMESPACE
