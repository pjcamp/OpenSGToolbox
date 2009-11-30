/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox Particle System                        *
 *                                                                           *
 *                                                                           *
 *                                                                           *
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
 **     class CylinderDistribution3D!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <OpenSG/OSGConfig.h>

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &CylinderDistribution3DBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 CylinderDistribution3DBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

//! create a new instance of the class
inline
CylinderDistribution3DPtr CylinderDistribution3DBase::create(void) 
{
    CylinderDistribution3DPtr fc; 

    if(getClassType().getPrototype() != OSG::NullFC) 
    {
        fc = CylinderDistribution3DPtr::dcast(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

//! create an empty new instance of the class, do not copy the prototype
inline
CylinderDistribution3DPtr CylinderDistribution3DBase::createEmpty(void) 
{ 
    CylinderDistribution3DPtr returnValue; 
    
    newPtr(returnValue); 

    return returnValue; 
}


/*------------------------------ get -----------------------------------*/

//! Get the CylinderDistribution3D::_sfHeight field.
inline
const SFReal32 *CylinderDistribution3DBase::getSFHeight(void) const
{
    return &_sfHeight;
}

//! Get the CylinderDistribution3D::_sfHeight field.
inline
SFReal32 *CylinderDistribution3DBase::editSFHeight(void)
{
    return &_sfHeight;
}

//! Get the CylinderDistribution3D::_sfCenter field.
inline
const SFPnt3f *CylinderDistribution3DBase::getSFCenter(void) const
{
    return &_sfCenter;
}

//! Get the CylinderDistribution3D::_sfCenter field.
inline
SFPnt3f *CylinderDistribution3DBase::editSFCenter(void)
{
    return &_sfCenter;
}

//! Get the CylinderDistribution3D::_sfNormal field.
inline
const SFVec3f *CylinderDistribution3DBase::getSFNormal(void) const
{
    return &_sfNormal;
}

//! Get the CylinderDistribution3D::_sfNormal field.
inline
SFVec3f *CylinderDistribution3DBase::editSFNormal(void)
{
    return &_sfNormal;
}

//! Get the CylinderDistribution3D::_sfTangent field.
inline
const SFVec3f *CylinderDistribution3DBase::getSFTangent(void) const
{
    return &_sfTangent;
}

//! Get the CylinderDistribution3D::_sfTangent field.
inline
SFVec3f *CylinderDistribution3DBase::editSFTangent(void)
{
    return &_sfTangent;
}

//! Get the CylinderDistribution3D::_sfBinormal field.
inline
const SFVec3f *CylinderDistribution3DBase::getSFBinormal(void) const
{
    return &_sfBinormal;
}

//! Get the CylinderDistribution3D::_sfBinormal field.
inline
SFVec3f *CylinderDistribution3DBase::editSFBinormal(void)
{
    return &_sfBinormal;
}

//! Get the CylinderDistribution3D::_sfInnerRadius field.
inline
const SFReal32 *CylinderDistribution3DBase::getSFInnerRadius(void) const
{
    return &_sfInnerRadius;
}

//! Get the CylinderDistribution3D::_sfInnerRadius field.
inline
SFReal32 *CylinderDistribution3DBase::editSFInnerRadius(void)
{
    return &_sfInnerRadius;
}

//! Get the CylinderDistribution3D::_sfOuterRadius field.
inline
const SFReal32 *CylinderDistribution3DBase::getSFOuterRadius(void) const
{
    return &_sfOuterRadius;
}

//! Get the CylinderDistribution3D::_sfOuterRadius field.
inline
SFReal32 *CylinderDistribution3DBase::editSFOuterRadius(void)
{
    return &_sfOuterRadius;
}

//! Get the CylinderDistribution3D::_sfMinTheta field.
inline
const SFReal32 *CylinderDistribution3DBase::getSFMinTheta(void) const
{
    return &_sfMinTheta;
}

//! Get the CylinderDistribution3D::_sfMinTheta field.
inline
SFReal32 *CylinderDistribution3DBase::editSFMinTheta(void)
{
    return &_sfMinTheta;
}

//! Get the CylinderDistribution3D::_sfMaxTheta field.
inline
const SFReal32 *CylinderDistribution3DBase::getSFMaxTheta(void) const
{
    return &_sfMaxTheta;
}

//! Get the CylinderDistribution3D::_sfMaxTheta field.
inline
SFReal32 *CylinderDistribution3DBase::editSFMaxTheta(void)
{
    return &_sfMaxTheta;
}

//! Get the CylinderDistribution3D::_sfSurfaceOrVolume field.
inline
const SFUInt32 *CylinderDistribution3DBase::getSFSurfaceOrVolume(void) const
{
    return &_sfSurfaceOrVolume;
}

//! Get the CylinderDistribution3D::_sfSurfaceOrVolume field.
inline
SFUInt32 *CylinderDistribution3DBase::editSFSurfaceOrVolume(void)
{
    return &_sfSurfaceOrVolume;
}


//! Get the value of the CylinderDistribution3D::_sfHeight field.
inline
Real32 &CylinderDistribution3DBase::editHeight(void)
{
    return _sfHeight.getValue();
}

//! Get the value of the CylinderDistribution3D::_sfHeight field.
inline
const Real32 &CylinderDistribution3DBase::getHeight(void) const
{
    return _sfHeight.getValue();
}

//! Set the value of the CylinderDistribution3D::_sfHeight field.
inline
void CylinderDistribution3DBase::setHeight(const Real32 &value)
{
    _sfHeight.setValue(value);
}

//! Get the value of the CylinderDistribution3D::_sfCenter field.
inline
Pnt3f &CylinderDistribution3DBase::editCenter(void)
{
    return _sfCenter.getValue();
}

//! Get the value of the CylinderDistribution3D::_sfCenter field.
inline
const Pnt3f &CylinderDistribution3DBase::getCenter(void) const
{
    return _sfCenter.getValue();
}

//! Set the value of the CylinderDistribution3D::_sfCenter field.
inline
void CylinderDistribution3DBase::setCenter(const Pnt3f &value)
{
    _sfCenter.setValue(value);
}

//! Get the value of the CylinderDistribution3D::_sfNormal field.
inline
Vec3f &CylinderDistribution3DBase::editNormal(void)
{
    return _sfNormal.getValue();
}

//! Get the value of the CylinderDistribution3D::_sfNormal field.
inline
const Vec3f &CylinderDistribution3DBase::getNormal(void) const
{
    return _sfNormal.getValue();
}

//! Set the value of the CylinderDistribution3D::_sfNormal field.
inline
void CylinderDistribution3DBase::setNormal(const Vec3f &value)
{
    _sfNormal.setValue(value);
}

//! Get the value of the CylinderDistribution3D::_sfTangent field.
inline
Vec3f &CylinderDistribution3DBase::editTangent(void)
{
    return _sfTangent.getValue();
}

//! Get the value of the CylinderDistribution3D::_sfTangent field.
inline
const Vec3f &CylinderDistribution3DBase::getTangent(void) const
{
    return _sfTangent.getValue();
}

//! Set the value of the CylinderDistribution3D::_sfTangent field.
inline
void CylinderDistribution3DBase::setTangent(const Vec3f &value)
{
    _sfTangent.setValue(value);
}

//! Get the value of the CylinderDistribution3D::_sfBinormal field.
inline
Vec3f &CylinderDistribution3DBase::editBinormal(void)
{
    return _sfBinormal.getValue();
}

//! Get the value of the CylinderDistribution3D::_sfBinormal field.
inline
const Vec3f &CylinderDistribution3DBase::getBinormal(void) const
{
    return _sfBinormal.getValue();
}

//! Set the value of the CylinderDistribution3D::_sfBinormal field.
inline
void CylinderDistribution3DBase::setBinormal(const Vec3f &value)
{
    _sfBinormal.setValue(value);
}

//! Get the value of the CylinderDistribution3D::_sfInnerRadius field.
inline
Real32 &CylinderDistribution3DBase::editInnerRadius(void)
{
    return _sfInnerRadius.getValue();
}

//! Get the value of the CylinderDistribution3D::_sfInnerRadius field.
inline
const Real32 &CylinderDistribution3DBase::getInnerRadius(void) const
{
    return _sfInnerRadius.getValue();
}

//! Set the value of the CylinderDistribution3D::_sfInnerRadius field.
inline
void CylinderDistribution3DBase::setInnerRadius(const Real32 &value)
{
    _sfInnerRadius.setValue(value);
}

//! Get the value of the CylinderDistribution3D::_sfOuterRadius field.
inline
Real32 &CylinderDistribution3DBase::editOuterRadius(void)
{
    return _sfOuterRadius.getValue();
}

//! Get the value of the CylinderDistribution3D::_sfOuterRadius field.
inline
const Real32 &CylinderDistribution3DBase::getOuterRadius(void) const
{
    return _sfOuterRadius.getValue();
}

//! Set the value of the CylinderDistribution3D::_sfOuterRadius field.
inline
void CylinderDistribution3DBase::setOuterRadius(const Real32 &value)
{
    _sfOuterRadius.setValue(value);
}

//! Get the value of the CylinderDistribution3D::_sfMinTheta field.
inline
Real32 &CylinderDistribution3DBase::editMinTheta(void)
{
    return _sfMinTheta.getValue();
}

//! Get the value of the CylinderDistribution3D::_sfMinTheta field.
inline
const Real32 &CylinderDistribution3DBase::getMinTheta(void) const
{
    return _sfMinTheta.getValue();
}

//! Set the value of the CylinderDistribution3D::_sfMinTheta field.
inline
void CylinderDistribution3DBase::setMinTheta(const Real32 &value)
{
    _sfMinTheta.setValue(value);
}

//! Get the value of the CylinderDistribution3D::_sfMaxTheta field.
inline
Real32 &CylinderDistribution3DBase::editMaxTheta(void)
{
    return _sfMaxTheta.getValue();
}

//! Get the value of the CylinderDistribution3D::_sfMaxTheta field.
inline
const Real32 &CylinderDistribution3DBase::getMaxTheta(void) const
{
    return _sfMaxTheta.getValue();
}

//! Set the value of the CylinderDistribution3D::_sfMaxTheta field.
inline
void CylinderDistribution3DBase::setMaxTheta(const Real32 &value)
{
    _sfMaxTheta.setValue(value);
}

//! Get the value of the CylinderDistribution3D::_sfSurfaceOrVolume field.
inline
UInt32 &CylinderDistribution3DBase::editSurfaceOrVolume(void)
{
    return _sfSurfaceOrVolume.getValue();
}

//! Get the value of the CylinderDistribution3D::_sfSurfaceOrVolume field.
inline
const UInt32 &CylinderDistribution3DBase::getSurfaceOrVolume(void) const
{
    return _sfSurfaceOrVolume.getValue();
}

//! Set the value of the CylinderDistribution3D::_sfSurfaceOrVolume field.
inline
void CylinderDistribution3DBase::setSurfaceOrVolume(const UInt32 &value)
{
    _sfSurfaceOrVolume.setValue(value);
}


OSG_END_NAMESPACE