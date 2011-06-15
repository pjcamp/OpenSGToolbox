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

#include "OSGPhysicsRayGeom.h"

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGPhysicsRayGeomBase.cpp file.
// To modify it, please change the .fcd file (OSGPhysicsRayGeom.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void PhysicsRayGeom::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
    }
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

void PhysicsRayGeom::onCreate(const PhysicsRayGeom *)
{
    _GeomID = dCreateRay(0, getLength());
    setCategoryBits(dGeomGetCategoryBits(_GeomID));
    setCollideBits(dGeomGetCollideBits(_GeomID));
}

void PhysicsRayGeom::onDestroy()
{
    //empty
}

/*----------------------- constructors & destructors ----------------------*/

PhysicsRayGeom::PhysicsRayGeom(void) :
    Inherited()
{
}

PhysicsRayGeom::PhysicsRayGeom(const PhysicsRayGeom &source) :
    Inherited(source)
{
}

PhysicsRayGeom::~PhysicsRayGeom(void)
{
}

/*----------------------------- class specific ----------------------------*/

void PhysicsRayGeom::changed(ConstFieldMaskArg whichField, 
                            UInt32            origin,
                            BitVector         details)
{
    Inherited::changed(whichField, origin, details);

    //Do not respond to changes that have a Sync origin
    if(origin & ChangedOrigin::Sync)
    {
        return;
    }

    if(whichField & LengthFieldMask)
    {
        dGeomRaySetLength(_GeomID, getLength());
    }
    if((whichField & RayPositionFieldMask) || (whichField & DirectionFieldMask))
    {
        dGeomRaySet(_GeomID, getRayPosition().x(), getRayPosition().y(), getRayPosition().z(), getDirection().x(), getDirection().y(), getDirection().z() );
    }
    
    if(whichField & ClosestHitFieldMask)
    {
        dGeomRaySetClosestHit(_GeomID, getClosestHit() ? 1:0);
    }
}

void PhysicsRayGeom::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump PhysicsRayGeom NI" << std::endl;
}

OSG_END_NAMESPACE
