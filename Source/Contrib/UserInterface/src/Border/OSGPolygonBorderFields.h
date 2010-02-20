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


#ifndef _OSGPOLYGONBORDERFIELDS_H_
#define _OSGPOLYGONBORDERFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGContribUserInterfaceDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE

class PolygonBorder;

OSG_GEN_CONTAINERPTR(PolygonBorder);

/*! \ingroup GrpContribUserInterfaceFieldTraits
    \ingroup GrpLibOSGContribUserInterface
 */
template <>
struct FieldTraits<PolygonBorder *> :
    public FieldTraitsFCPtrBase<PolygonBorder *>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<PolygonBorder *>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_CONTRIBUSERINTERFACE_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFPolygonBorderPtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFPolygonBorderPtr"; }
};

template<> inline
const Char8 *FieldTraits<PolygonBorder *, 0>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecPolygonBorderPtr"; 
}

template<> inline
const Char8 *FieldTraits<PolygonBorder *, 0>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecPolygonBorderPtr"; 
}

template<> inline
const Char8 *FieldTraits<PolygonBorder *, 0>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakPolygonBorderPtr"; 
}

template<> inline
const Char8 *FieldTraits<PolygonBorder *, 0>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdPolygonBorderPtr"; 
}

template<> inline
const Char8 *FieldTraits<PolygonBorder *, 0>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecPolygonBorderPtr"; 
}

template<> inline
const Char8 *FieldTraits<PolygonBorder *, 0>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecPolygonBorderPtr"; 
}

template<> inline
const Char8 *FieldTraits<PolygonBorder *, 0>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakPolygonBorderPtr"; 
}

template<> inline
const Char8 *FieldTraits<PolygonBorder *, 0>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdPolygonBorderPtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<PolygonBorder *,
                      RecordedRefCountPolicy  > SFRecPolygonBorderPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<PolygonBorder *,
                      UnrecordedRefCountPolicy> SFUnrecPolygonBorderPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<PolygonBorder *,
                      WeakRefCountPolicy      > SFWeakPolygonBorderPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<PolygonBorder *,
                      NoRefCountPolicy        > SFUncountedPolygonBorderPtr;


/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<PolygonBorder *,
                      RecordedRefCountPolicy  > MFRecPolygonBorderPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<PolygonBorder *,
                      UnrecordedRefCountPolicy> MFUnrecPolygonBorderPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<PolygonBorder *,
                      WeakRefCountPolicy      > MFWeakPolygonBorderPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<PolygonBorder *,
                      NoRefCountPolicy        > MFUncountedPolygonBorderPtr;




#else // these are the doxygen hacks

/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFRecPolygonBorderPtr : 
    public PointerSField<PolygonBorder *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUnrecPolygonBorderPtr : 
    public PointerSField<PolygonBorder *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFWeakPolygonBorderPtr :
    public PointerSField<PolygonBorder *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUncountedPolygonBorderPtr :
    public PointerSField<PolygonBorder *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFRecPolygonBorderPtr :
    public PointerMField<PolygonBorder *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUnrecPolygonBorderPtr :
    public PointerMField<PolygonBorder *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFWeakPolygonBorderPtr :
    public PointerMField<PolygonBorder *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUncountedPolygonBorderPtr :
    public PointerMField<PolygonBorder *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGPOLYGONBORDERFIELDS_H_ */
