/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                         www.vrac.iastate.edu                              *
 *                                                                           *
 *   Authors: David Kabala, Alden Peterson, Lee Zaniewski, Jonathan Flory    *
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

/*****************************************************************************\
 *****************************************************************************
 **                                                                         **
 **                  This file is automatically generated.                  **
 **                                                                         **
 **          Any changes made to this file WILL be lost when it is          **
 **           regenerated, which can become necessary at any time.          **
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGLAYOUTCONSTRAINTSFIELDS_H_
#define _OSGLAYOUTCONSTRAINTSFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include <OpenSG/OSGConfig.h>

#include <OpenSG/OSGFieldContainerPtr.h>
#include <OpenSG/OSGNodeCoreFieldDataType.h>
#include "OSGUserInterfaceDef.h"

#include <OpenSG/OSGAttachmentContainerFields.h>

OSG_BEGIN_NAMESPACE

class LayoutConstraints;

#if !defined(OSG_DO_DOC)   // created as a dummy class, remove to prevent doubles
//! LayoutConstraintsPtr

typedef FCPtr<AttachmentContainerPtr, LayoutConstraints> LayoutConstraintsPtr;

#endif

#if !defined(OSG_DO_DOC) || (OSG_DOC_LEVEL >= 3)
/*! \ingroup GrpUserInterfaceFieldTraits
 */
#if !defined(OSG_DOC_DEV_TRAITS)
/*! \hideinhierarchy */
#endif

template <>
struct FieldDataTraits<LayoutConstraintsPtr> : 
    public FieldTraitsRecurseMapper<LayoutConstraintsPtr, true>
{
    static DataType             _type;                       

    enum                        { StringConvertable = 0x00 };
    enum                        { bHasParent        = 0x01 };

    static DataType   &getType (void) { return _type;        }

    static const char *getSName(void) { return "SFLayoutConstraintsPtr"; }
    static const char *getMName(void) { return "MFLayoutConstraintsPtr"; }
};

#if !defined(OSG_DOC_DEV_TRAITS)
/*! \class  FieldTraitsRecurseMapper<LayoutConstraintsPtr, true>
    \hideinhierarchy
 */
#endif

#endif // !defined(OSG_DO_DOC) || (OSG_DOC_LEVEL >= 3)


#if !defined(OSG_DO_DOC) || defined(OSG_DOC_FIELD_TYPEDEFS)
/*! \ingroup GrpUserInterfaceFieldSingle */

typedef SField<LayoutConstraintsPtr> SFLayoutConstraintsPtr;
#endif

#ifndef OSG_COMPILELAYOUTCONSTRAINTSINST
OSG_DLLEXPORT_DECL1(SField, LayoutConstraintsPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING)
#endif

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_FIELD_TYPEDEFS)
/*! \ingroup GrpUserInterfaceFieldMulti */

typedef MField<LayoutConstraintsPtr> MFLayoutConstraintsPtr;
#endif

#ifndef OSG_COMPILELAYOUTCONSTRAINTSINST
OSG_DLLEXPORT_DECL1(MField, LayoutConstraintsPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING)
#endif

OSG_END_NAMESPACE

#define OSGLAYOUTCONSTRAINTSFIELDS_HEADER_CVSID "@(#)$Id: FCFieldsTemplate_h.h,v 1.26 2006/02/20 16:55:35 dirk Exp $"

#endif /* _OSGLAYOUTCONSTRAINTSFIELDS_H_ */
