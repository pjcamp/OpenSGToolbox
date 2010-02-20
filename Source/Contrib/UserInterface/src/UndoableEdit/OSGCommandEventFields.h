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


#ifndef _OSGCOMMANDEVENTFIELDS_H_
#define _OSGCOMMANDEVENTFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGContribUserInterfaceDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE

class CommandEvent;

OSG_GEN_CONTAINERPTR(CommandEvent);

/*! \ingroup GrpContribUserInterfaceFieldTraits
    \ingroup GrpLibOSGContribUserInterface
 */
template <>
struct FieldTraits<CommandEvent *> :
    public FieldTraitsFCPtrBase<CommandEvent *>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<CommandEvent *>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_CONTRIBUSERINTERFACE_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFCommandEventPtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFCommandEventPtr"; }
};

template<> inline
const Char8 *FieldTraits<CommandEvent *, 0>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecCommandEventPtr"; 
}

template<> inline
const Char8 *FieldTraits<CommandEvent *, 0>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecCommandEventPtr"; 
}

template<> inline
const Char8 *FieldTraits<CommandEvent *, 0>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakCommandEventPtr"; 
}

template<> inline
const Char8 *FieldTraits<CommandEvent *, 0>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdCommandEventPtr"; 
}

template<> inline
const Char8 *FieldTraits<CommandEvent *, 0>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecCommandEventPtr"; 
}

template<> inline
const Char8 *FieldTraits<CommandEvent *, 0>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecCommandEventPtr"; 
}

template<> inline
const Char8 *FieldTraits<CommandEvent *, 0>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakCommandEventPtr"; 
}

template<> inline
const Char8 *FieldTraits<CommandEvent *, 0>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdCommandEventPtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<CommandEvent *,
                      RecordedRefCountPolicy  > SFRecCommandEventPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<CommandEvent *,
                      UnrecordedRefCountPolicy> SFUnrecCommandEventPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<CommandEvent *,
                      WeakRefCountPolicy      > SFWeakCommandEventPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<CommandEvent *,
                      NoRefCountPolicy        > SFUncountedCommandEventPtr;


/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<CommandEvent *,
                      RecordedRefCountPolicy  > MFRecCommandEventPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<CommandEvent *,
                      UnrecordedRefCountPolicy> MFUnrecCommandEventPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<CommandEvent *,
                      WeakRefCountPolicy      > MFWeakCommandEventPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<CommandEvent *,
                      NoRefCountPolicy        > MFUncountedCommandEventPtr;




#else // these are the doxygen hacks

/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFRecCommandEventPtr : 
    public PointerSField<CommandEvent *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUnrecCommandEventPtr : 
    public PointerSField<CommandEvent *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFWeakCommandEventPtr :
    public PointerSField<CommandEvent *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUncountedCommandEventPtr :
    public PointerSField<CommandEvent *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFRecCommandEventPtr :
    public PointerMField<CommandEvent *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUnrecCommandEventPtr :
    public PointerMField<CommandEvent *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFWeakCommandEventPtr :
    public PointerMField<CommandEvent *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUncountedCommandEventPtr :
    public PointerMField<CommandEvent *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGCOMMANDEVENTFIELDS_H_ */
