/*---------------------------------------------------------------------------*\
 *                        OpenSG ToolBox Video                               *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                         www.vrac.iastate.edu                              *
 *                                                                           *
 *                 Authors: David Kabala, David Naylor                       *
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
#include "OSGVLCManager.h"
#include "OSGVLCVideoWrapper.h"

#ifdef OSG_WITH_VLC


OSG_BEGIN_NAMESPACE

VLCManager *VLCManager::_the = NULL;

VideoManager *VLCManager::the(void)
{
    if(_the == NULL)
    {
        _the = new VLCManager;
    }

    return _the;
}

VideoWrapperTransitPtr VLCManager::createVideoWrapper(void) const
{
    return VideoWrapperTransitPtr(VLCVideoWrapper::create());
}

bool VLCManager::init(int   argc, char *argv[])
{
}

bool VLCManager::exit(void)
{
}

/*-------------------------------------------------------------------------*/
/*                            Constructors                                 */

VLCManager::VLCManager(void)
{
}
    
/*-------------------------------------------------------------------------*/
/*                             Destructor                                  */

VLCManager::~VLCManager(void)
{
}

OSG_END_NAMESPACE

#endif

