/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                         www.vrac.iastate.edu                              *
 *                                                                           *
 *   Authors: David Kabala, Alden Peterson, Lee Zaniewski, Jonathan Flory    *
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
 **     class UIDrawObjectCanvas!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEUIDRAWOBJECTCANVASINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"
#include "OSGUIDrawObjectCanvasBase.h"
#include "OSGUIDrawObjectCanvas.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  UIDrawObjectCanvasBase::DrawObjectsFieldMask = 
    (TypeTraits<BitVector>::One << UIDrawObjectCanvasBase::DrawObjectsFieldId);

const OSG::BitVector UIDrawObjectCanvasBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var UIDrawObjectPtr UIDrawObjectCanvasBase::_mfDrawObjects
    
*/

//! UIDrawObjectCanvas description

FieldDescription *UIDrawObjectCanvasBase::_desc[] = 
{
    new FieldDescription(MFUIDrawObjectPtr::getClassType(), 
                     "DrawObjects", 
                     DrawObjectsFieldId, DrawObjectsFieldMask,
                     false,
                     (FieldAccessMethod) &UIDrawObjectCanvasBase::getMFDrawObjects)
};


FieldContainerType UIDrawObjectCanvasBase::_type(
    "UIDrawObjectCanvas",
    "Component",
    NULL,
    (PrototypeCreateF) &UIDrawObjectCanvasBase::createEmpty,
    UIDrawObjectCanvas::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(UIDrawObjectCanvasBase, UIDrawObjectCanvasPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &UIDrawObjectCanvasBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &UIDrawObjectCanvasBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr UIDrawObjectCanvasBase::shallowCopy(void) const 
{ 
    UIDrawObjectCanvasPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const UIDrawObjectCanvas *>(this)); 

    return returnValue; 
}

UInt32 UIDrawObjectCanvasBase::getContainerSize(void) const 
{ 
    return sizeof(UIDrawObjectCanvas); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void UIDrawObjectCanvasBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl((UIDrawObjectCanvasBase *) &other, whichField);
}
#else
void UIDrawObjectCanvasBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((UIDrawObjectCanvasBase *) &other, whichField, sInfo);
}
void UIDrawObjectCanvasBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void UIDrawObjectCanvasBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

    _mfDrawObjects.terminateShare(uiAspect, this->getContainerSize());
}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

UIDrawObjectCanvasBase::UIDrawObjectCanvasBase(void) :
    _mfDrawObjects            (), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

UIDrawObjectCanvasBase::UIDrawObjectCanvasBase(const UIDrawObjectCanvasBase &source) :
    _mfDrawObjects            (source._mfDrawObjects            ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

UIDrawObjectCanvasBase::~UIDrawObjectCanvasBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 UIDrawObjectCanvasBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (DrawObjectsFieldMask & whichField))
    {
        returnValue += _mfDrawObjects.getBinSize();
    }


    return returnValue;
}

void UIDrawObjectCanvasBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (DrawObjectsFieldMask & whichField))
    {
        _mfDrawObjects.copyToBin(pMem);
    }


}

void UIDrawObjectCanvasBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (DrawObjectsFieldMask & whichField))
    {
        _mfDrawObjects.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void UIDrawObjectCanvasBase::executeSyncImpl(      UIDrawObjectCanvasBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (DrawObjectsFieldMask & whichField))
        _mfDrawObjects.syncWith(pOther->_mfDrawObjects);


}
#else
void UIDrawObjectCanvasBase::executeSyncImpl(      UIDrawObjectCanvasBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);


    if(FieldBits::NoField != (DrawObjectsFieldMask & whichField))
        _mfDrawObjects.syncWith(pOther->_mfDrawObjects, sInfo);


}

void UIDrawObjectCanvasBase::execBeginEditImpl (const BitVector &whichField, 
                                                 UInt32     uiAspect,
                                                 UInt32     uiContainerSize)
{
    Inherited::execBeginEditImpl(whichField, uiAspect, uiContainerSize);

    if(FieldBits::NoField != (DrawObjectsFieldMask & whichField))
        _mfDrawObjects.beginEdit(uiAspect, uiContainerSize);

}
#endif



OSG_END_NAMESPACE

#include <OpenSG/OSGSFieldTypeDef.inl>
#include <OpenSG/OSGMFieldTypeDef.inl>

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldDataTraits<UIDrawObjectCanvasPtr>::_type("UIDrawObjectCanvasPtr", "ComponentPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(UIDrawObjectCanvasPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(UIDrawObjectCanvasPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);


/*------------------------------------------------------------------------*/
/*                              cvs id's                                  */

#ifdef OSG_SGI_CC
#pragma set woff 1174
#endif

#ifdef OSG_LINUX_ICC
#pragma warning( disable : 177 )
#endif

namespace
{
    static Char8 cvsid_cpp       [] = "@(#)$Id: FCBaseTemplate_cpp.h,v 1.47 2006/03/17 17:03:19 pdaehne Exp $";
    static Char8 cvsid_hpp       [] = OSGUIDRAWOBJECTCANVASBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGUIDRAWOBJECTCANVASBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGUIDRAWOBJECTCANVASFIELDS_HEADER_CVSID;
}

OSG_END_NAMESPACE

