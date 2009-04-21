/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                         www.vrac.iastate.edu                              *
 *                                                                           *
 *                          Authors: David Kabala                            *
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
 **     class DirectionalIndicatorMiniMapOverlay!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEDIRECTIONALINDICATORMINIMAPOVERLAYINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGDirectionalIndicatorMiniMapOverlayBase.h"
#include "OSGDirectionalIndicatorMiniMapOverlay.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  DirectionalIndicatorMiniMapOverlayBase::IndicatorsFieldMask = 
    (TypeTraits<BitVector>::One << DirectionalIndicatorMiniMapOverlayBase::IndicatorsFieldId);

const OSG::BitVector  DirectionalIndicatorMiniMapOverlayBase::IndicatorComponentsFieldMask = 
    (TypeTraits<BitVector>::One << DirectionalIndicatorMiniMapOverlayBase::IndicatorComponentsFieldId);

const OSG::BitVector  DirectionalIndicatorMiniMapOverlayBase::DirectionComponentGeneratorFieldMask = 
    (TypeTraits<BitVector>::One << DirectionalIndicatorMiniMapOverlayBase::DirectionComponentGeneratorFieldId);

const OSG::BitVector  DirectionalIndicatorMiniMapOverlayBase::OverlayPanelFieldMask = 
    (TypeTraits<BitVector>::One << DirectionalIndicatorMiniMapOverlayBase::OverlayPanelFieldId);

const OSG::BitVector DirectionalIndicatorMiniMapOverlayBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var MiniMapIndicatorPtr DirectionalIndicatorMiniMapOverlayBase::_mfIndicators
    
*/
/*! \var ComponentPtr    DirectionalIndicatorMiniMapOverlayBase::_mfIndicatorComponents
    
*/
/*! \var ComponentGeneratorPtr DirectionalIndicatorMiniMapOverlayBase::_sfDirectionComponentGenerator
    
*/
/*! \var PanelPtr        DirectionalIndicatorMiniMapOverlayBase::_sfOverlayPanel
    
*/

//! DirectionalIndicatorMiniMapOverlay description

FieldDescription *DirectionalIndicatorMiniMapOverlayBase::_desc[] = 
{
    new FieldDescription(MFMiniMapIndicatorPtr::getClassType(), 
                     "Indicators", 
                     IndicatorsFieldId, IndicatorsFieldMask,
                     false,
                     (FieldAccessMethod) &DirectionalIndicatorMiniMapOverlayBase::getMFIndicators),
    new FieldDescription(MFComponentPtr::getClassType(), 
                     "IndicatorComponents", 
                     IndicatorComponentsFieldId, IndicatorComponentsFieldMask,
                     true,
                     (FieldAccessMethod) &DirectionalIndicatorMiniMapOverlayBase::getMFIndicatorComponents),
    new FieldDescription(SFComponentGeneratorPtr::getClassType(), 
                     "DirectionComponentGenerator", 
                     DirectionComponentGeneratorFieldId, DirectionComponentGeneratorFieldMask,
                     false,
                     (FieldAccessMethod) &DirectionalIndicatorMiniMapOverlayBase::getSFDirectionComponentGenerator),
    new FieldDescription(SFPanelPtr::getClassType(), 
                     "OverlayPanel", 
                     OverlayPanelFieldId, OverlayPanelFieldMask,
                     false,
                     (FieldAccessMethod) &DirectionalIndicatorMiniMapOverlayBase::getSFOverlayPanel)
};


FieldContainerType DirectionalIndicatorMiniMapOverlayBase::_type(
    "DirectionalIndicatorMiniMapOverlay",
    "MiniMapOverlay",
    NULL,
    (PrototypeCreateF) &DirectionalIndicatorMiniMapOverlayBase::createEmpty,
    DirectionalIndicatorMiniMapOverlay::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(DirectionalIndicatorMiniMapOverlayBase, DirectionalIndicatorMiniMapOverlayPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &DirectionalIndicatorMiniMapOverlayBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &DirectionalIndicatorMiniMapOverlayBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr DirectionalIndicatorMiniMapOverlayBase::shallowCopy(void) const 
{ 
    DirectionalIndicatorMiniMapOverlayPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const DirectionalIndicatorMiniMapOverlay *>(this)); 

    return returnValue; 
}

UInt32 DirectionalIndicatorMiniMapOverlayBase::getContainerSize(void) const 
{ 
    return sizeof(DirectionalIndicatorMiniMapOverlay); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void DirectionalIndicatorMiniMapOverlayBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl((DirectionalIndicatorMiniMapOverlayBase *) &other, whichField);
}
#else
void DirectionalIndicatorMiniMapOverlayBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((DirectionalIndicatorMiniMapOverlayBase *) &other, whichField, sInfo);
}
void DirectionalIndicatorMiniMapOverlayBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void DirectionalIndicatorMiniMapOverlayBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

    _mfIndicators.terminateShare(uiAspect, this->getContainerSize());
    _mfIndicatorComponents.terminateShare(uiAspect, this->getContainerSize());
}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

DirectionalIndicatorMiniMapOverlayBase::DirectionalIndicatorMiniMapOverlayBase(void) :
    _mfIndicators             (), 
    _mfIndicatorComponents    (), 
    _sfDirectionComponentGenerator(ComponentGeneratorPtr(NullFC)), 
    _sfOverlayPanel           (PanelPtr(NullFC)), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

DirectionalIndicatorMiniMapOverlayBase::DirectionalIndicatorMiniMapOverlayBase(const DirectionalIndicatorMiniMapOverlayBase &source) :
    _mfIndicators             (source._mfIndicators             ), 
    _mfIndicatorComponents    (source._mfIndicatorComponents    ), 
    _sfDirectionComponentGenerator(source._sfDirectionComponentGenerator), 
    _sfOverlayPanel           (source._sfOverlayPanel           ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

DirectionalIndicatorMiniMapOverlayBase::~DirectionalIndicatorMiniMapOverlayBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 DirectionalIndicatorMiniMapOverlayBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (IndicatorsFieldMask & whichField))
    {
        returnValue += _mfIndicators.getBinSize();
    }

    if(FieldBits::NoField != (IndicatorComponentsFieldMask & whichField))
    {
        returnValue += _mfIndicatorComponents.getBinSize();
    }

    if(FieldBits::NoField != (DirectionComponentGeneratorFieldMask & whichField))
    {
        returnValue += _sfDirectionComponentGenerator.getBinSize();
    }

    if(FieldBits::NoField != (OverlayPanelFieldMask & whichField))
    {
        returnValue += _sfOverlayPanel.getBinSize();
    }


    return returnValue;
}

void DirectionalIndicatorMiniMapOverlayBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (IndicatorsFieldMask & whichField))
    {
        _mfIndicators.copyToBin(pMem);
    }

    if(FieldBits::NoField != (IndicatorComponentsFieldMask & whichField))
    {
        _mfIndicatorComponents.copyToBin(pMem);
    }

    if(FieldBits::NoField != (DirectionComponentGeneratorFieldMask & whichField))
    {
        _sfDirectionComponentGenerator.copyToBin(pMem);
    }

    if(FieldBits::NoField != (OverlayPanelFieldMask & whichField))
    {
        _sfOverlayPanel.copyToBin(pMem);
    }


}

void DirectionalIndicatorMiniMapOverlayBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (IndicatorsFieldMask & whichField))
    {
        _mfIndicators.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (IndicatorComponentsFieldMask & whichField))
    {
        _mfIndicatorComponents.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (DirectionComponentGeneratorFieldMask & whichField))
    {
        _sfDirectionComponentGenerator.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (OverlayPanelFieldMask & whichField))
    {
        _sfOverlayPanel.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void DirectionalIndicatorMiniMapOverlayBase::executeSyncImpl(      DirectionalIndicatorMiniMapOverlayBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (IndicatorsFieldMask & whichField))
        _mfIndicators.syncWith(pOther->_mfIndicators);

    if(FieldBits::NoField != (IndicatorComponentsFieldMask & whichField))
        _mfIndicatorComponents.syncWith(pOther->_mfIndicatorComponents);

    if(FieldBits::NoField != (DirectionComponentGeneratorFieldMask & whichField))
        _sfDirectionComponentGenerator.syncWith(pOther->_sfDirectionComponentGenerator);

    if(FieldBits::NoField != (OverlayPanelFieldMask & whichField))
        _sfOverlayPanel.syncWith(pOther->_sfOverlayPanel);


}
#else
void DirectionalIndicatorMiniMapOverlayBase::executeSyncImpl(      DirectionalIndicatorMiniMapOverlayBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (DirectionComponentGeneratorFieldMask & whichField))
        _sfDirectionComponentGenerator.syncWith(pOther->_sfDirectionComponentGenerator);

    if(FieldBits::NoField != (OverlayPanelFieldMask & whichField))
        _sfOverlayPanel.syncWith(pOther->_sfOverlayPanel);


    if(FieldBits::NoField != (IndicatorsFieldMask & whichField))
        _mfIndicators.syncWith(pOther->_mfIndicators, sInfo);

    if(FieldBits::NoField != (IndicatorComponentsFieldMask & whichField))
        _mfIndicatorComponents.syncWith(pOther->_mfIndicatorComponents, sInfo);


}

void DirectionalIndicatorMiniMapOverlayBase::execBeginEditImpl (const BitVector &whichField, 
                                                 UInt32     uiAspect,
                                                 UInt32     uiContainerSize)
{
    Inherited::execBeginEditImpl(whichField, uiAspect, uiContainerSize);

    if(FieldBits::NoField != (IndicatorsFieldMask & whichField))
        _mfIndicators.beginEdit(uiAspect, uiContainerSize);

    if(FieldBits::NoField != (IndicatorComponentsFieldMask & whichField))
        _mfIndicatorComponents.beginEdit(uiAspect, uiContainerSize);

}
#endif



OSG_END_NAMESPACE

#include <OpenSG/OSGSFieldTypeDef.inl>
#include <OpenSG/OSGMFieldTypeDef.inl>

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldDataTraits<DirectionalIndicatorMiniMapOverlayPtr>::_type("DirectionalIndicatorMiniMapOverlayPtr", "MiniMapOverlayPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(DirectionalIndicatorMiniMapOverlayPtr, OSG_GAMELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(DirectionalIndicatorMiniMapOverlayPtr, OSG_GAMELIB_DLLTMPLMAPPING);


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
    static Char8 cvsid_hpp       [] = OSGDIRECTIONALINDICATORMINIMAPOVERLAYBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGDIRECTIONALINDICATORMINIMAPOVERLAYBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGDIRECTIONALINDICATORMINIMAPOVERLAYFIELDS_HEADER_CVSID;
}

OSG_END_NAMESPACE

