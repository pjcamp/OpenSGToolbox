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

#define OSG_COMPILESOUNDLIB

#include "OSGConfig.h"

#include "OSGStubSoundManager.h"
#include "OSGSound.h"
#include "OSGStubSound.h"

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class osg::StubSoundManager
A stub SoundManager Interface.
*/

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

StubSoundManager *StubSoundManager::_the = NULL;

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

StubSoundManager *StubSoundManager::the(void)
{
    if(_the == NULL)
    {
        _the = new StubSoundManager();
    }

    return _the;
}

/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

void StubSoundManager::update(const Time& ElapsedTime)
{
}

SoundTransitPtr StubSoundManager::createSound(void) const
{
    return SoundTransitPtr(StubSound::create());
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

StubSoundManager::StubSoundManager(void) :
    Inherited()
{
}

StubSoundManager::StubSoundManager(const StubSoundManager &source) :
    Inherited(source)
{
}

StubSoundManager::~StubSoundManager(void)
{
}

OSG_END_NAMESPACE

