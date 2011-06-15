/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 *   contact:  David Kabala (djkabala@gmail.com)                             *
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

#define OSG_COMPILEUSERINTERFACELIB

#include "OSGConfig.h"

#include "OSGFCFileType.h"
#include "OSGFCFileHandler.h"
#include "OSGLog.h"

#ifndef OSG_EMBEDDED
#include "OSGFCFileHandler.h"
#endif
#include "OSGBaseInitFunctions.h"

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class osg::FCFileType
A FCFileType. 
*/

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

 FCFileType::FCPtrStore FCFileType::read(std::istream &is,
                         const std::string& fileNameOrExtension) const
{
    FWARNING (("STREAM INTERFACE NOT IMPLEMENTED!\n"));
    FCPtrStore Result;

    return Result;
}

bool FCFileType::write(const FCPtrStore &Containers, std::ostream &os,
        const std::string& fileNameOrExtension, const FCTypeVector& IgnoreTypes) const
{
    FWARNING (("STREAM INTERFACE NOT IMPLEMENTED!\n"));

    return false;
}

/*! Print supported suffixes to osgLog. */
void FCFileType::print(void)
{
    std::vector<std::string>::iterator sI;

    osgLog() << getName();

    if (_suffixList.empty())
    {
        osgLog() << "NONE";
    }
    else
    {
        for (sI = _suffixList.begin(); sI != _suffixList.end(); sI++)
        {
            osgLog().stream(OSG::LOG_DEBUG) << sI->c_str() << " ";
        }
    }
    osgLog() << std::endl;
}

//---------------------------------------------------------

bool FCFileType::doOverride(void)
{
    return _override;
}

//---------------------------------------------------------

UInt32 FCFileType::getOverridePriority(void)
{
    return _overridePriority;
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

/**
 * Constructor for FCFileType.
 *
 * \param suffixArray     Raw char buffer of supported suffix values.
 * \param suffixByteCount Length of suffix strings to extract.
 * \param override
 * \param overridePriority Priority of this file handler in overload resolution.
 * \param flags    Combination of OSG_READ_SUPPORTED and OSG_WRITE_SUPPORTED to say what
 *                 this handler supports.
 */
FCFileType::FCFileType(const ExtensionVector&  suffixArray,
                        bool    override,
                        UInt32  overridePriority,
                        UInt32  flags)
    : Inherited        (flags           ),
      _suffixList      (suffixArray     ),
      _override        (override        ),
      _overridePriority(overridePriority)
{
    SINFO << "Init FieldContainer File Type " <<  _suffixList[0] << std::endl;

#ifndef OSG_EMBEDDED 
    FCFileHandler::the()->addFCFileType(FCFileTypeP(this));
#endif
}

FCFileType::FCFileType(const FCFileType &obj)
    : Inherited        (obj           )
{
    SWARNING << "In FCFileType copy constructor" << std::endl;
}

FCFileType::~FCFileType(void)
{
#ifndef OSG_EMBEDDED
    if(GlobalSystemState < OSG::Shutdown)
        FCFileHandler::the()->subFCFileType(FCFileTypeP(this));
#endif
}

void FCFileType::terminate(void)
{
}

/*----------------------------- class specific ----------------------------*/

/*------------------------------------------------------------------------*/
/*                              cvs id's                                  */

#ifdef OSG_SGI_CC
#pragma set woff 1174
#endif

#ifdef OSG_LINUX_ICC
#pragma warning( disable : 177 )
#endif

#ifdef __sgi
#pragma reset woff 1174
#endif

OSG_END_NAMESPACE

