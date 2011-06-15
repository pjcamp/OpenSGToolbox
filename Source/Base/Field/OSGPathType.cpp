/*---------------------------------------------------------------------------*\
 *                        OpenSG ToolBox Toolbox                             *
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

// Source file for new Field type

// This define is only set in this source file. It switches the
// Windows-specific declarations in the header for compiling the Field, 
// not for using it.
#define OSG_COMPILEPATHTYPEINST

// You need this in every OpenSG file
#include "OSGPathType.h"
#include "OSGSField.ins"
#include "OSGMField.ins"

// The new field type include
#include "OSGFieldContainer.h"
#include "OSGFieldType.h"
#include "OSGBaseFieldTraits.h"
#include "OSGDataType.h"

OSG_BEGIN_NAMESPACE

// This is where the DataType for the new Fieldtype is defined.
// The parameters are the name of the type and the name of the parent type
DataType FieldTraits<BoostPath>::_type("Path", "BaseType");

// These macros instantiate the necessary template methods for the fields
OSG_FIELDTRAITS_GETTYPE (        BoostPath)
OSG_FIELD_DLLEXPORT_DEF1(SField, BoostPath)
OSG_FIELD_DLLEXPORT_DEF1(MField, BoostPath)

// Output inVal into outVal
// the exact mapping doesn't matter, 
// Our recommendation is to output as a string, 
// i.e. start and stop with ", as this simplifies integration into the
// OSG Loader.
void FieldTraits<BoostPath>::putToStream(const BoostPath   &inVal,
                                         OutStream &outVal)
{
    outVal << inVal.string();
}

// Setup outVal from the contents of inVal
// For complicated classes it makes sense to implement this function
// as a class method and just call that from here  
bool FieldTraits<BoostPath>::getFromCString(      BoostPath  &outVal,
                                                  const Char8     *&inVal)
{
    std::string PathString("");
    if( FieldTraits<std::string>::getFromCString(PathString, inVal) )
    {
        try
        {
            outVal = PathString;
            return true;
        }
        catch(boost::filesystem::filesystem_error& error)
        {
            SWARNING <<
                "ERROR in creating file path from string:" << error.what() <<
                std::endl;
            return false;
        }
    }
    else
    {
        return false;
    }

}

// Binary conversion

// Return the size of the binary version in byte   
// There are two versions of this function, one for a single object, 
// one for an array of objects
UInt32 FieldTraits<BoostPath>::getBinSize(const BoostPath & obj)
{
    return FieldTraits<std::string>::getBinSize(obj.string());
}

UInt32 FieldTraits<BoostPath>::getBinSize (const BoostPath *obj, UInt32 num)
{
    //Size:
    //Sum of all the objs
    UInt32 SizeSum(0);
    for(UInt32 i = 0; i < num; ++i)
    {
        SizeSum += FieldTraits<std::string>::getBinSize(obj[i].string());
    }
    return SizeSum;
}

// Copy the object into the BinaryDataHandler
// the BDH has a number of methods to add a simple type to the stream
// just use those and use the same order to read them back in.
// Again there are two versions, one for a single object, one for an 
// array of objects
void FieldTraits<BoostPath>::copyToBin(      BinaryDataHandler &bdh, 
                                             const BoostPath         &obj)
{
    FieldTraits<std::string>::copyToBin(bdh, obj.string());
}

void FieldTraits<BoostPath>::copyToBin(      BinaryDataHandler &bdh,
                                             const BoostPath         *objs,
                                             UInt32             num)
{
    for(UInt32 i = 0; i < num; ++i)
    {
        copyToBin(bdh, objs[i]);
    }
}


// Copy the object from the BinaryDataHandler
// the BDH has a number of methods to get a simple type from the stream
// just use those and use the same order you used to write them out.
// Again there are two versions, one for a single object, one for an 
// array of objects
void FieldTraits<BoostPath>::copyFromBin(BinaryDataHandler &bdh, 
                                         BoostPath         &obj)
{
    std::string PathString("");
    FieldTraits<std::string>::copyFromBin(bdh, PathString);
    try
    {
        obj = PathString;
    }
    catch(boost::filesystem::filesystem_error& error)
    {
        SWARNING <<
            "ERROR in creating file path from binary:" << error.what() <<
            std::endl;
    }
}
void FieldTraits<BoostPath>::copyFromBin(BinaryDataHandler &bdh,
                                         BoostPath         *objs,
                                         UInt32             num)
{
    for(UInt32 i = 0; i < num; ++i)
    {
        copyFromBin(bdh, objs[i]);
    }
}

OSG_END_NAMESPACE


