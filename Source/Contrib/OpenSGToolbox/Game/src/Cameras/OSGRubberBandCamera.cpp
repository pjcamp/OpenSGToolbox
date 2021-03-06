/*---------------------------------------------------------------------------*\
 *                        OpenSG ToolBox Game                                *
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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>
#include <OpenSG/OSGQuaternion.h>

#include "OSGRubberBandCamera.h"
#include "OpenSG/Toolbox/OSGQuatOperations.h"

OSG_USING_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class osg::RubberBandCamera
Rubber Band Camera.
*/

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void RubberBandCamera::initMethod (void)
{
}

void RubberBandCamera::getViewing              (Matrix        &result, 
                                       UInt32 width, UInt32 height)
{
   if(getDecoratee() != osg::NullFC)
   {
      result.mult(_Matrix);
   }
   else
   {
      Matrix InvertedMat = _Matrix;
      InvertedMat.invert();
      result.mult(InvertedMat);
   }
}

void RubberBandCamera::update(const Real32& Elps)
{
   if (getBeacon() == NullFC)
   {
      SWARNING << "RubberBandCamera::update: no beacon!" << std::endl;
      return;
   }
   //Get Transformation
   osg::Matrix BeaconTransformation;
   if(getDecoratee() != osg::NullFC)
   {
      getDecoratee()->getViewing(BeaconTransformation, 0, 0);
   }
   else
   {
      BeaconTransformation = getBeacon()->getToWorld();
   }

   //Get Beacon Position and Orientation
   Vec3f ToPosition;
   Quaternion ToOrientation;
   Vec3f Scale;
   Quaternion ScaleOrientation;
   BeaconTransformation.getTransform(ToPosition, ToOrientation, Scale, ScaleOrientation);

   //Get Current Position and Orientation
   Vec3f FromPosition;
   Quaternion FromOrientation;
   _Matrix.getTransform(FromPosition, FromOrientation, Scale, ScaleOrientation);

   //Position
   Vec3f Direction = (ToPosition - FromPosition);
   Real32 DirLength = Direction.length();
   Real32 PullLength = (getPositionCoefficients()[0] + DirLength*getPositionCoefficients()[1] + DirLength*DirLength*getPositionCoefficients()[2]) * Elps;
   //Real32 DistanceTraveling = getPositionConstant() + Elps*getPositionLinear() + Elps*Elps*getPositionQuadratic();
   Vec3f Position;

   if(PullLength < DirLength)
   {
      Position = FromPosition + PullLength * (Direction*(1.0/DirLength));
   }
   else
   {
      Position = ToPosition;
   }

   //Get Beacon Orientation
   Quaternion RotDirection = (ToOrientation/FromOrientation);
   Real32 RotDirLength, Garbage;
   RotDirection.getValueAsAxisRad(Garbage, Garbage, Garbage, RotDirLength);
   
   Real32 RotPullLength = (getOrientationCoefficients()[0] + RotDirLength*getOrientationCoefficients()[1] + RotDirLength*RotDirLength*getOrientationCoefficients()[2]) * Elps;

   Quaternion Orientation;

   if(RotPullLength < RotDirLength)
   {
      Orientation = slerp(FromOrientation, ToOrientation, (RotPullLength/RotDirLength));
   }
   else
   {
      Orientation = ToOrientation;
   }
   _Matrix.setTransform(Position, Orientation);
}

void RubberBandCamera::setToBeacon(void)
{
   //Get Transformation
   osg::Matrix BeaconTransformation;
   if(getDecoratee() != osg::NullFC)
   {
      getDecoratee()->getViewing(BeaconTransformation, 0, 0);
   }
   else
   {
      BeaconTransformation = getBeacon()->getToWorld();
   }

   //Get Beacon Position and Orientation
   Vec3f ToPosition;
   Quaternion ToOrientation;
   Vec3f Scale;
   Quaternion ScaleOrientation;
   BeaconTransformation.getTransform(ToPosition, ToOrientation, Scale, ScaleOrientation);

   _Matrix.setTransform(ToPosition, ToOrientation);
}

/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

RubberBandCamera::RubberBandCamera(void) :
    Inherited()
{
}

RubberBandCamera::RubberBandCamera(const RubberBandCamera &source) :
    Inherited(source)
{
}

RubberBandCamera::~RubberBandCamera(void)
{
}

/*----------------------------- class specific ----------------------------*/

void RubberBandCamera::changed(BitVector whichField, UInt32 origin)
{
    Inherited::changed(whichField, origin);
}

void RubberBandCamera::dump(      UInt32    , 
                         const BitVector ) const
{
    SLOG << "Dump RubberBandCamera NI" << std::endl;
}


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
    static Char8 cvsid_cpp       [] = "@(#)$Id: FCTemplate_cpp.h,v 1.19 2003/05/05 10:05:28 dirk Exp $";
    static Char8 cvsid_hpp       [] = OSGRUBBERBANDCAMERABASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGRUBBERBANDCAMERABASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGRUBBERBANDCAMERAFIELDS_HEADER_CVSID;
}

#ifdef __sgi
#pragma reset woff 1174
#endif

