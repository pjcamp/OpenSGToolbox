/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
 *                                                                           *
 *                                                                           *
 *                                                                           *
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
 **     class LayeredImageMiniMap!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <OpenSG/OSGConfig.h>

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &LayeredImageMiniMapBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 LayeredImageMiniMapBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

//! create a new instance of the class
inline
LayeredImageMiniMapPtr LayeredImageMiniMapBase::create(void) 
{
    LayeredImageMiniMapPtr fc; 

    if(getClassType().getPrototype() != OSG::NullFC) 
    {
        fc = LayeredImageMiniMapPtr::dcast(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

//! create an empty new instance of the class, do not copy the prototype
inline
LayeredImageMiniMapPtr LayeredImageMiniMapBase::createEmpty(void) 
{ 
    LayeredImageMiniMapPtr returnValue; 
    
    newPtr(returnValue); 

    return returnValue; 
}


/*------------------------------ get -----------------------------------*/

//! Get the LayeredImageMiniMap::_mfOverlay field.
inline
MFMiniMapOverlayPtr *LayeredImageMiniMapBase::getMFOverlay(void)
{
    return &_mfOverlay;
}

//! Get the LayeredImageMiniMap::_mfLayerTextures field.
inline
MFTextureChunkPtr *LayeredImageMiniMapBase::getMFLayerTextures(void)
{
    return &_mfLayerTextures;
}

//! Get the LayeredImageMiniMap::_sfMapScaleX field.
inline
SFUInt32 *LayeredImageMiniMapBase::getSFMapScaleX(void)
{
    return &_sfMapScaleX;
}

//! Get the LayeredImageMiniMap::_sfMapScaleY field.
inline
SFUInt32 *LayeredImageMiniMapBase::getSFMapScaleY(void)
{
    return &_sfMapScaleY;
}

//! Get the LayeredImageMiniMap::_sfMapLocationPtr field.
inline
SFPnt2f *LayeredImageMiniMapBase::getSFMapLocationPtr(void)
{
    return &_sfMapLocationPtr;
}


//! Get the value of the LayeredImageMiniMap::_sfMapScaleX field.
inline
UInt32 &LayeredImageMiniMapBase::getMapScaleX(void)
{
    return _sfMapScaleX.getValue();
}

//! Get the value of the LayeredImageMiniMap::_sfMapScaleX field.
inline
const UInt32 &LayeredImageMiniMapBase::getMapScaleX(void) const
{
    return _sfMapScaleX.getValue();
}

//! Set the value of the LayeredImageMiniMap::_sfMapScaleX field.
inline
void LayeredImageMiniMapBase::setMapScaleX(const UInt32 &value)
{
    _sfMapScaleX.setValue(value);
}

//! Get the value of the LayeredImageMiniMap::_sfMapScaleY field.
inline
UInt32 &LayeredImageMiniMapBase::getMapScaleY(void)
{
    return _sfMapScaleY.getValue();
}

//! Get the value of the LayeredImageMiniMap::_sfMapScaleY field.
inline
const UInt32 &LayeredImageMiniMapBase::getMapScaleY(void) const
{
    return _sfMapScaleY.getValue();
}

//! Set the value of the LayeredImageMiniMap::_sfMapScaleY field.
inline
void LayeredImageMiniMapBase::setMapScaleY(const UInt32 &value)
{
    _sfMapScaleY.setValue(value);
}

//! Get the value of the LayeredImageMiniMap::_sfMapLocationPtr field.
inline
Pnt2f &LayeredImageMiniMapBase::getMapLocationPtr(void)
{
    return _sfMapLocationPtr.getValue();
}

//! Get the value of the LayeredImageMiniMap::_sfMapLocationPtr field.
inline
const Pnt2f &LayeredImageMiniMapBase::getMapLocationPtr(void) const
{
    return _sfMapLocationPtr.getValue();
}

//! Set the value of the LayeredImageMiniMap::_sfMapLocationPtr field.
inline
void LayeredImageMiniMapBase::setMapLocationPtr(const Pnt2f &value)
{
    _sfMapLocationPtr.setValue(value);
}


//! Get the value of the \a index element the LayeredImageMiniMap::_mfOverlay field.
inline
MiniMapOverlayPtr &LayeredImageMiniMapBase::getOverlay(const UInt32 index)
{
    return _mfOverlay[index];
}

//! Get the LayeredImageMiniMap::_mfOverlay field.
inline
MFMiniMapOverlayPtr &LayeredImageMiniMapBase::getOverlay(void)
{
    return _mfOverlay;
}

//! Get the LayeredImageMiniMap::_mfOverlay field.
inline
const MFMiniMapOverlayPtr &LayeredImageMiniMapBase::getOverlay(void) const
{
    return _mfOverlay;
}

//! Get the value of the \a index element the LayeredImageMiniMap::_mfLayerTextures field.
inline
TextureChunkPtr &LayeredImageMiniMapBase::getLayerTextures(const UInt32 index)
{
    return _mfLayerTextures[index];
}

//! Get the LayeredImageMiniMap::_mfLayerTextures field.
inline
MFTextureChunkPtr &LayeredImageMiniMapBase::getLayerTextures(void)
{
    return _mfLayerTextures;
}

//! Get the LayeredImageMiniMap::_mfLayerTextures field.
inline
const MFTextureChunkPtr &LayeredImageMiniMapBase::getLayerTextures(void) const
{
    return _mfLayerTextures;
}

OSG_END_NAMESPACE

#define OSGLAYEREDIMAGEMINIMAPBASE_INLINE_CVSID "@(#)$Id: FCBaseTemplate_inl.h,v 1.20 2002/12/04 14:22:22 dirk Exp $"

