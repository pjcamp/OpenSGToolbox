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


#ifndef _OSGTOOLBARFIELDS_H_
#define _OSGTOOLBARFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGContribUserInterfaceDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE

class Toolbar;

OSG_GEN_CONTAINERPTR(Toolbar);

/*! \ingroup GrpContribUserInterfaceFieldTraits
    \ingroup GrpLibOSGContribUserInterface
 */
template <>
struct FieldTraits<Toolbar *> :
    public FieldTraitsFCPtrBase<Toolbar *>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<Toolbar *>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_CONTRIBUSERINTERFACE_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFToolbarPtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFToolbarPtr"; }
};

template<> inline
const Char8 *FieldTraits<Toolbar *, 0>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecToolbarPtr"; 
}

template<> inline
const Char8 *FieldTraits<Toolbar *, 0>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecToolbarPtr"; 
}

template<> inline
const Char8 *FieldTraits<Toolbar *, 0>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakToolbarPtr"; 
}

template<> inline
const Char8 *FieldTraits<Toolbar *, 0>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdToolbarPtr"; 
}

template<> inline
const Char8 *FieldTraits<Toolbar *, 0>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecToolbarPtr"; 
}

template<> inline
const Char8 *FieldTraits<Toolbar *, 0>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecToolbarPtr"; 
}

template<> inline
const Char8 *FieldTraits<Toolbar *, 0>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakToolbarPtr"; 
}

template<> inline
const Char8 *FieldTraits<Toolbar *, 0>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdToolbarPtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<Toolbar *,
                      RecordedRefCountPolicy  > SFRecToolbarPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<Toolbar *,
                      UnrecordedRefCountPolicy> SFUnrecToolbarPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<Toolbar *,
                      WeakRefCountPolicy      > SFWeakToolbarPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<Toolbar *,
                      NoRefCountPolicy        > SFUncountedToolbarPtr;


/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<Toolbar *,
                      RecordedRefCountPolicy  > MFRecToolbarPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<Toolbar *,
                      UnrecordedRefCountPolicy> MFUnrecToolbarPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<Toolbar *,
                      WeakRefCountPolicy      > MFWeakToolbarPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<Toolbar *,
                      NoRefCountPolicy        > MFUncountedToolbarPtr;




#else // these are the doxygen hacks

/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFRecToolbarPtr : 
    public PointerSField<Toolbar *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUnrecToolbarPtr : 
    public PointerSField<Toolbar *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFWeakToolbarPtr :
    public PointerSField<Toolbar *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUncountedToolbarPtr :
    public PointerSField<Toolbar *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFRecToolbarPtr :
    public PointerMField<Toolbar *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUnrecToolbarPtr :
    public PointerMField<Toolbar *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFWeakToolbarPtr :
    public PointerMField<Toolbar *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUncountedToolbarPtr :
    public PointerMField<Toolbar *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGTOOLBARFIELDS_H_ */
