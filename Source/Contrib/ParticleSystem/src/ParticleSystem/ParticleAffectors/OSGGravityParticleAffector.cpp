/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 *   contact:  David Kabala (djkabala@gmail.com), Daniel Guilliams           *
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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <cstdlib>
#include <cstdio>

#include <OSGConfig.h>

#include "OSGGravityParticleAffector.h"
#include "OSGMatrix.h"
#include "OSGQuaternion.h"

#include "OSGParticleSystem.h"

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGGravityParticleAffectorBase.cpp file.
// To modify it, please change the .fcd file (OSGGravityParticleAffector.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void GravityParticleAffector::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
    }
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

bool GravityParticleAffector::affect(ParticleSystemRefPtr System, Int32 ParticleIndex, const Time& elps)
{
    // getting affector's translation.  No affect is applied if the beacon cannot be found
    if(getBeacon() != NULL)
    {
        Matrix BeaconToWorld(getBeacon()->getToWorld());
        Vec3f translation, tmp;
        Quaternion tmp2;
        BeaconToWorld.getTransform(translation,tmp2,tmp,tmp2);

        //distance from affector to particle
        Real32 distanceFromAffector = System->getPosition(ParticleIndex).dist(Pnt3f(translation.x(),translation.y(),translation.z())); 

        if((getMaxDistance() < 0.0) || (distanceFromAffector <= getMaxDistance())) //only affect the particle if it is in range
        {    
            // calculate gravitational affect
            Vec3f grav(getDirection());
            grav.normalize();
            grav = grav * ((getMagnitude() *
                            elps)/(OSG::osgClamp<Real32>(1.0f,std::pow(distanceFromAffector,getAttenuation()),TypeTraits<Real32>::getMax())));
            // set new particle velocity
            System->setVelocity(grav + System->getVelocity(ParticleIndex),ParticleIndex);
        }
    }

    return false;
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

GravityParticleAffector::GravityParticleAffector(void) :
    Inherited()
{
}

GravityParticleAffector::GravityParticleAffector(const GravityParticleAffector &source) :
    Inherited(source)
{
}

GravityParticleAffector::~GravityParticleAffector(void)
{
}

/*----------------------------- class specific ----------------------------*/

void GravityParticleAffector::changed(ConstFieldMaskArg whichField, 
                            UInt32            origin,
                            BitVector         details)
{
    Inherited::changed(whichField, origin, details);
}

void GravityParticleAffector::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump GravityParticleAffector NI" << std::endl;
}

OSG_END_NAMESPACE
