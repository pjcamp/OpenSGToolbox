/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2002 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 *   contact: dirk@opensg.org, gerrit.voss@vossg.org, jbehr@zgdv.de          *
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

#define OSG_COMPILEUSERINTERFACELIB

#include <OpenSG/OSGConfig.h>

#include "OSGRoundedCornerLineBorder.h"
#include "Graphics/OSGGraphics2d.h"

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class osg::RoundedCornerLineBorder
UI Line Border. 	
*/

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void RoundedCornerLineBorder::initMethod (void)
{
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

void RoundedCornerLineBorder::draw(const GraphicsPtr g, const Int16 x, const Int16 y , const UInt16 Width, const UInt16 Height, const Real32 Opacity) const
{
	//draw corners
	g->drawComplexDisc(Pnt2s(x+getCornerRadius(), y+getCornerRadius()), getCornerRadius()-getWidth(), getCornerRadius(), 3.14159265, 4.71238898, 10, getColor(), getColor(), Opacity);
	g->drawComplexDisc(Pnt2s(x+getCornerRadius(), y+Height-getCornerRadius()), getCornerRadius()-getWidth(), getCornerRadius(), 1.57079633, 3.14159265, 10, getColor(), getColor(), Opacity);
	g->drawComplexDisc(Pnt2s(x+Width-getCornerRadius(), y+Height-getCornerRadius()), getCornerRadius()-getWidth(), getCornerRadius(), 0, 1.57079633, 10, getColor(), getColor(), Opacity);
	g->drawComplexDisc(Pnt2s(x+Width-getCornerRadius(), y+getCornerRadius()), getCornerRadius()-getWidth(), getCornerRadius(), 4.71238898,6.28318531, 10, getColor(), getColor(), Opacity);

	//draw sides
	g->drawRect(Pnt2s(x, y+getCornerRadius()), Pnt2s(x+getWidth(), y+Height-getCornerRadius()), getColor(), Opacity);
	g->drawRect(Pnt2s(x+getCornerRadius(), y), Pnt2s(x+Width-getCornerRadius(), y+getWidth()), getColor(), Opacity);
	g->drawRect(Pnt2s(x+Width-getWidth(), y+getCornerRadius()), Pnt2s(x+Width, y+Height-getCornerRadius()), getColor(), Opacity);
	g->drawRect(Pnt2s(x+getCornerRadius(), y+Height-getWidth()), Pnt2s(x+Width-getCornerRadius(), y+Height), getColor(), Opacity);
}

void RoundedCornerLineBorder::getInsets(UInt16& Left, UInt16& Right,UInt16& Top,UInt16& Bottom) const
{
	//TODO:Implement
	Left=Right=Top=Bottom = getWidth(); //wrong, but what else are you supposed to do?
}
/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

RoundedCornerLineBorder::RoundedCornerLineBorder(void) :
    Inherited()
{
}

RoundedCornerLineBorder::RoundedCornerLineBorder(const RoundedCornerLineBorder &source) :
    Inherited(source)
{
}

RoundedCornerLineBorder::~RoundedCornerLineBorder(void)
{
}

/*----------------------------- class specific ----------------------------*/

void RoundedCornerLineBorder::changed(BitVector whichField, UInt32 origin)
{
    Inherited::changed(whichField, origin);
}

void RoundedCornerLineBorder::dump(      UInt32    , 
                         const BitVector ) const
{
    SLOG << "Dump RoundedCornerLineBorder NI" << std::endl;
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
    static Char8 cvsid_cpp       [] = "@(#)$Id: FCTemplate_cpp.h,v 1.20 2006/03/16 17:01:53 dirk Exp $";
    static Char8 cvsid_hpp       [] = OSGROUNDEDCORNERLINEBORDERBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGROUNDEDCORNERLINEBORDERBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGROUNDEDCORNERLINEBORDERFIELDS_HEADER_CVSID;
}

#ifdef __sgi
#pragma reset woff 1174
#endif

OSG_END_NAMESPACE
