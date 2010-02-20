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


#ifndef _OSGLAYOUTCONSTRAINTSFIELDS_H_
#define _OSGLAYOUTCONSTRAINTSFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGContribUserInterfaceDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE

class LayoutConstraints;

OSG_GEN_CONTAINERPTR(LayoutConstraints);

/*! \ingroup GrpContribUserInterfaceFieldTraits
    \ingroup GrpLibOSGContribUserInterface
 */
template <>
struct FieldTraits<LayoutConstraints *> :
    public FieldTraitsFCPtrBase<LayoutConstraints *>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<LayoutConstraints *>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_CONTRIBUSERINTERFACE_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFLayoutConstraintsPtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFLayoutConstraintsPtr"; }
};

template<> inline
const Char8 *FieldTraits<LayoutConstraints *, 0>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecLayoutConstraintsPtr"; 
}

template<> inline
const Char8 *FieldTraits<LayoutConstraints *, 0>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecLayoutConstraintsPtr"; 
}

template<> inline
const Char8 *FieldTraits<LayoutConstraints *, 0>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakLayoutConstraintsPtr"; 
}

template<> inline
const Char8 *FieldTraits<LayoutConstraints *, 0>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdLayoutConstraintsPtr"; 
}

template<> inline
const Char8 *FieldTraits<LayoutConstraints *, 0>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecLayoutConstraintsPtr"; 
}

template<> inline
const Char8 *FieldTraits<LayoutConstraints *, 0>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecLayoutConstraintsPtr"; 
}

template<> inline
const Char8 *FieldTraits<LayoutConstraints *, 0>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakLayoutConstraintsPtr"; 
}

template<> inline
const Char8 *FieldTraits<LayoutConstraints *, 0>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdLayoutConstraintsPtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<LayoutConstraints *,
                      RecordedRefCountPolicy  > SFRecLayoutConstraintsPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<LayoutConstraints *,
                      UnrecordedRefCountPolicy> SFUnrecLayoutConstraintsPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<LayoutConstraints *,
                      WeakRefCountPolicy      > SFWeakLayoutConstraintsPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<LayoutConstraints *,
                      NoRefCountPolicy        > SFUncountedLayoutConstraintsPtr;


/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<LayoutConstraints *,
                      RecordedRefCountPolicy  > MFRecLayoutConstraintsPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<LayoutConstraints *,
                      UnrecordedRefCountPolicy> MFUnrecLayoutConstraintsPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<LayoutConstraints *,
                      WeakRefCountPolicy      > MFWeakLayoutConstraintsPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<LayoutConstraints *,
                      NoRefCountPolicy        > MFUncountedLayoutConstraintsPtr;




#else // these are the doxygen hacks

/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFRecLayoutConstraintsPtr : 
    public PointerSField<LayoutConstraints *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUnrecLayoutConstraintsPtr : 
    public PointerSField<LayoutConstraints *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFWeakLayoutConstraintsPtr :
    public PointerSField<LayoutConstraints *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUncountedLayoutConstraintsPtr :
    public PointerSField<LayoutConstraints *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFRecLayoutConstraintsPtr :
    public PointerMField<LayoutConstraints *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUnrecLayoutConstraintsPtr :
    public PointerMField<LayoutConstraints *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFWeakLayoutConstraintsPtr :
    public PointerMField<LayoutConstraints *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUncountedLayoutConstraintsPtr :
    public PointerMField<LayoutConstraints *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGLAYOUTCONSTRAINTSFIELDS_H_ */
