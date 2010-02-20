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


#ifndef _OSGCOMPONENTCONTAINERFIELDS_H_
#define _OSGCOMPONENTCONTAINERFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGContribUserInterfaceDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE

class ComponentContainer;

OSG_GEN_CONTAINERPTR(ComponentContainer);

/*! \ingroup GrpContribUserInterfaceFieldTraits
    \ingroup GrpLibOSGContribUserInterface
 */
template <>
struct FieldTraits<ComponentContainer *> :
    public FieldTraitsFCPtrBase<ComponentContainer *>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<ComponentContainer *>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_CONTRIBUSERINTERFACE_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFComponentContainerPtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFComponentContainerPtr"; }
};

template<> inline
const Char8 *FieldTraits<ComponentContainer *, 0>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecComponentContainerPtr"; 
}

template<> inline
const Char8 *FieldTraits<ComponentContainer *, 0>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecComponentContainerPtr"; 
}

template<> inline
const Char8 *FieldTraits<ComponentContainer *, 0>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakComponentContainerPtr"; 
}

template<> inline
const Char8 *FieldTraits<ComponentContainer *, 0>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdComponentContainerPtr"; 
}

template<> inline
const Char8 *FieldTraits<ComponentContainer *, 0>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecComponentContainerPtr"; 
}

template<> inline
const Char8 *FieldTraits<ComponentContainer *, 0>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecComponentContainerPtr"; 
}

template<> inline
const Char8 *FieldTraits<ComponentContainer *, 0>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakComponentContainerPtr"; 
}

template<> inline
const Char8 *FieldTraits<ComponentContainer *, 0>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdComponentContainerPtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<ComponentContainer *,
                      RecordedRefCountPolicy  > SFRecComponentContainerPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<ComponentContainer *,
                      UnrecordedRefCountPolicy> SFUnrecComponentContainerPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<ComponentContainer *,
                      WeakRefCountPolicy      > SFWeakComponentContainerPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<ComponentContainer *,
                      NoRefCountPolicy        > SFUncountedComponentContainerPtr;


/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<ComponentContainer *,
                      RecordedRefCountPolicy  > MFRecComponentContainerPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<ComponentContainer *,
                      UnrecordedRefCountPolicy> MFUnrecComponentContainerPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<ComponentContainer *,
                      WeakRefCountPolicy      > MFWeakComponentContainerPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<ComponentContainer *,
                      NoRefCountPolicy        > MFUncountedComponentContainerPtr;




#else // these are the doxygen hacks

/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFRecComponentContainerPtr : 
    public PointerSField<ComponentContainer *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUnrecComponentContainerPtr : 
    public PointerSField<ComponentContainer *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFWeakComponentContainerPtr :
    public PointerSField<ComponentContainer *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUncountedComponentContainerPtr :
    public PointerSField<ComponentContainer *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFRecComponentContainerPtr :
    public PointerMField<ComponentContainer *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUnrecComponentContainerPtr :
    public PointerMField<ComponentContainer *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFWeakComponentContainerPtr :
    public PointerMField<ComponentContainer *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUncountedComponentContainerPtr :
    public PointerMField<ComponentContainer *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGCOMPONENTCONTAINERFIELDS_H_ */
