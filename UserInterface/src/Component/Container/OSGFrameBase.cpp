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
 **     class Frame!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEFRAMEINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGFrameBase.h"
#include "OSGFrame.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  FrameBase::FocusedComponentFieldMask = 
    (TypeTraits<BitVector>::One << FrameBase::FocusedComponentFieldId);

const OSG::BitVector  FrameBase::DrawingSurfaceFieldMask = 
    (TypeTraits<BitVector>::One << FrameBase::DrawingSurfaceFieldId);

const OSG::BitVector  FrameBase::ActivePopupMenuFieldMask = 
    (TypeTraits<BitVector>::One << FrameBase::ActivePopupMenuFieldId);

const OSG::BitVector FrameBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var ComponentPtr    FrameBase::_sfFocusedComponent
    
*/
/*! \var UIDrawingSurfacePtr FrameBase::_sfDrawingSurface
    
*/
/*! \var PopupMenuPtr    FrameBase::_sfActivePopupMenu
    
*/

//! Frame description

FieldDescription *FrameBase::_desc[] = 
{
    new FieldDescription(SFComponentPtr::getClassType(), 
                     "FocusedComponent", 
                     FocusedComponentFieldId, FocusedComponentFieldMask,
                     false,
                     (FieldAccessMethod) &FrameBase::getSFFocusedComponent),
    new FieldDescription(SFUIDrawingSurfacePtr::getClassType(), 
                     "DrawingSurface", 
                     DrawingSurfaceFieldId, DrawingSurfaceFieldMask,
                     false,
                     (FieldAccessMethod) &FrameBase::getSFDrawingSurface),
    new FieldDescription(SFPopupMenuPtr::getClassType(), 
                     "ActivePopupMenu", 
                     ActivePopupMenuFieldId, ActivePopupMenuFieldMask,
                     true,
                     (FieldAccessMethod) &FrameBase::getSFActivePopupMenu)
};


FieldContainerType FrameBase::_type(
    "Frame",
    "Container",
    NULL,
    (PrototypeCreateF) &FrameBase::createEmpty,
    Frame::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(FrameBase, FramePtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &FrameBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &FrameBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr FrameBase::shallowCopy(void) const 
{ 
    FramePtr returnValue; 

    newPtr(returnValue, dynamic_cast<const Frame *>(this)); 

    return returnValue; 
}

UInt32 FrameBase::getContainerSize(void) const 
{ 
    return sizeof(Frame); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void FrameBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl((FrameBase *) &other, whichField);
}
#else
void FrameBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((FrameBase *) &other, whichField, sInfo);
}
void FrameBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void FrameBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

FrameBase::FrameBase(void) :
    _sfFocusedComponent       (ComponentPtr(NullFC)), 
    _sfDrawingSurface         (UIDrawingSurfacePtr(NullFC)), 
    _sfActivePopupMenu        (PopupMenuPtr(NullFC)), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

FrameBase::FrameBase(const FrameBase &source) :
    _sfFocusedComponent       (source._sfFocusedComponent       ), 
    _sfDrawingSurface         (source._sfDrawingSurface         ), 
    _sfActivePopupMenu        (source._sfActivePopupMenu        ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

FrameBase::~FrameBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 FrameBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (FocusedComponentFieldMask & whichField))
    {
        returnValue += _sfFocusedComponent.getBinSize();
    }

    if(FieldBits::NoField != (DrawingSurfaceFieldMask & whichField))
    {
        returnValue += _sfDrawingSurface.getBinSize();
    }

    if(FieldBits::NoField != (ActivePopupMenuFieldMask & whichField))
    {
        returnValue += _sfActivePopupMenu.getBinSize();
    }


    return returnValue;
}

void FrameBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (FocusedComponentFieldMask & whichField))
    {
        _sfFocusedComponent.copyToBin(pMem);
    }

    if(FieldBits::NoField != (DrawingSurfaceFieldMask & whichField))
    {
        _sfDrawingSurface.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ActivePopupMenuFieldMask & whichField))
    {
        _sfActivePopupMenu.copyToBin(pMem);
    }


}

void FrameBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (FocusedComponentFieldMask & whichField))
    {
        _sfFocusedComponent.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (DrawingSurfaceFieldMask & whichField))
    {
        _sfDrawingSurface.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ActivePopupMenuFieldMask & whichField))
    {
        _sfActivePopupMenu.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void FrameBase::executeSyncImpl(      FrameBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (FocusedComponentFieldMask & whichField))
        _sfFocusedComponent.syncWith(pOther->_sfFocusedComponent);

    if(FieldBits::NoField != (DrawingSurfaceFieldMask & whichField))
        _sfDrawingSurface.syncWith(pOther->_sfDrawingSurface);

    if(FieldBits::NoField != (ActivePopupMenuFieldMask & whichField))
        _sfActivePopupMenu.syncWith(pOther->_sfActivePopupMenu);


}
#else
void FrameBase::executeSyncImpl(      FrameBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (FocusedComponentFieldMask & whichField))
        _sfFocusedComponent.syncWith(pOther->_sfFocusedComponent);

    if(FieldBits::NoField != (DrawingSurfaceFieldMask & whichField))
        _sfDrawingSurface.syncWith(pOther->_sfDrawingSurface);

    if(FieldBits::NoField != (ActivePopupMenuFieldMask & whichField))
        _sfActivePopupMenu.syncWith(pOther->_sfActivePopupMenu);



}

void FrameBase::execBeginEditImpl (const BitVector &whichField, 
                                                 UInt32     uiAspect,
                                                 UInt32     uiContainerSize)
{
    Inherited::execBeginEditImpl(whichField, uiAspect, uiContainerSize);

}
#endif



OSG_END_NAMESPACE

#include <OpenSG/OSGSFieldTypeDef.inl>
#include <OpenSG/OSGMFieldTypeDef.inl>

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldDataTraits<FramePtr>::_type("FramePtr", "ContainerPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(FramePtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(FramePtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);


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
    static Char8 cvsid_hpp       [] = OSGFRAMEBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGFRAMEBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGFRAMEFIELDS_HEADER_CVSID;
}

OSG_END_NAMESPACE

