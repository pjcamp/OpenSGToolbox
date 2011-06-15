/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 *   contact:  David Kabala (djkabala@gmail.com),  Behboud Kalantary         *
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

#include "OSGPhysicsSphereGeom.h"

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGPhysicsSphereGeomBase.cpp file.
// To modify it, please change the .fcd file (OSGPhysicsSphereGeom.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void PhysicsSphereGeom::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
    }
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

Real32 PhysicsSphereGeom::getPointDepth(const Vec3f& p) const
{
    return (Real32)dGeomSpherePointDepth(_GeomID, p.x(), p.y(), p.z());
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

void PhysicsSphereGeom::onCreate(const PhysicsSphereGeom *)
{
    _GeomID = dCreateSphere(0, getRadius());
    setCategoryBits(dGeomGetCategoryBits(_GeomID));
    setCollideBits(dGeomGetCollideBits(_GeomID));
}

void PhysicsSphereGeom::onDestroy()
{
    //empty
}

/*----------------------- constructors & destructors ----------------------*/

PhysicsSphereGeom::PhysicsSphereGeom(void) :
    Inherited()
{
}

PhysicsSphereGeom::PhysicsSphereGeom(const PhysicsSphereGeom &source) :
    Inherited(source)
{
}

PhysicsSphereGeom::~PhysicsSphereGeom(void)
{
}

/*----------------------------- class specific ----------------------------*/

void PhysicsSphereGeom::changed(ConstFieldMaskArg whichField, 
                            UInt32            origin,
                            BitVector         details)
{
    Inherited::changed(whichField, origin, details);

    //Do not respond to changes that have a Sync origin
    if(origin & ChangedOrigin::Sync)
    {
        return;
    }

    if(whichField & RadiusFieldMask)
    {
        dGeomSphereSetRadius(_GeomID, getRadius());
    }
}

void PhysicsSphereGeom::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump PhysicsSphereGeom NI" << std::endl;
}

OSG_END_NAMESPACE
