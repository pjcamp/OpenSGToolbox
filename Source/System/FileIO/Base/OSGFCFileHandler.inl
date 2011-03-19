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
#include "OSGConfig.h"

OSG_BEGIN_NAMESPACE

inline 
void FCFileHandlerBase::operator =(const FCFileHandlerBase& source)
{
    SWARNING << "In FCFileHandler operator =" << std::endl;
}

inline
const BoostPath& FCFileHandlerBase::getRootFilePath(void) const
{
    return _RootFilePath;
}

inline
FCFileHandlerBase::FCPtrStore FCFileHandlerBase::read(std::istream &InputStream, const std::string& Extension)
{
    //Get the FileType for this extension
    FCFileTypeP TheFileType(getFileType(Extension, FCFileType::OSG_READ_SUPPORTED));
    
    if(TheFileType == NULL)
    {
        SWARNING << "FCFileHandlerBase::read(): Cannot read Field Container stream, because no File types support " 
                 << Extension <<  " extension." << std::endl;
        return FCPtrStore();
    }
    else
    {
        return read(InputStream, TheFileType, Extension);
    }
}

inline
bool FCFileHandlerBase::write(const FCPtrStore Containers, 
                              std::ostream &OutputStream, 
                              const std::string& Extension, 
                              const FCFileType::FCTypeVector& IgnoreTypes, 
                              bool Compress)
{
    //Get the FileType for this extension
    FCFileTypeP TheFileType(getFileType(Extension, FCFileType::OSG_WRITE_SUPPORTED));

    if(TheFileType == NULL)
    {
        SWARNING << "FCFileHandlerBase::read(): Cannot write Field Container stream, because no File types support " 
                 << Extension <<  " extension." << std::endl;
        return false;
    }
    else
    {
        return write(Containers, OutputStream, TheFileType, Extension, IgnoreTypes, Compress);
    }
}
OSG_END_NAMESPACE
