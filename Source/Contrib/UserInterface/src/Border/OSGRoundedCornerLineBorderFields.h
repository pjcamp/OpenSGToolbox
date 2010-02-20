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


#ifndef _OSGROUNDEDCORNERLINEBORDERFIELDS_H_
#define _OSGROUNDEDCORNERLINEBORDERFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGContribUserInterfaceDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE

class RoundedCornerLineBorder;

OSG_GEN_CONTAINERPTR(RoundedCornerLineBorder);

/*! \ingroup GrpContribUserInterfaceFieldTraits
    \ingroup GrpLibOSGContribUserInterface
 */
template <>
struct FieldTraits<RoundedCornerLineBorder *> :
    public FieldTraitsFCPtrBase<RoundedCornerLineBorder *>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<RoundedCornerLineBorder *>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_CONTRIBUSERINTERFACE_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFRoundedCornerLineBorderPtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFRoundedCornerLineBorderPtr"; }
};

template<> inline
const Char8 *FieldTraits<RoundedCornerLineBorder *, 0>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecRoundedCornerLineBorderPtr"; 
}

template<> inline
const Char8 *FieldTraits<RoundedCornerLineBorder *, 0>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecRoundedCornerLineBorderPtr"; 
}

template<> inline
const Char8 *FieldTraits<RoundedCornerLineBorder *, 0>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakRoundedCornerLineBorderPtr"; 
}

template<> inline
const Char8 *FieldTraits<RoundedCornerLineBorder *, 0>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdRoundedCornerLineBorderPtr"; 
}

template<> inline
const Char8 *FieldTraits<RoundedCornerLineBorder *, 0>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecRoundedCornerLineBorderPtr"; 
}

template<> inline
const Char8 *FieldTraits<RoundedCornerLineBorder *, 0>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecRoundedCornerLineBorderPtr"; 
}

template<> inline
const Char8 *FieldTraits<RoundedCornerLineBorder *, 0>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakRoundedCornerLineBorderPtr"; 
}

template<> inline
const Char8 *FieldTraits<RoundedCornerLineBorder *, 0>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdRoundedCornerLineBorderPtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<RoundedCornerLineBorder *,
                      RecordedRefCountPolicy  > SFRecRoundedCornerLineBorderPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<RoundedCornerLineBorder *,
                      UnrecordedRefCountPolicy> SFUnrecRoundedCornerLineBorderPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<RoundedCornerLineBorder *,
                      WeakRefCountPolicy      > SFWeakRoundedCornerLineBorderPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<RoundedCornerLineBorder *,
                      NoRefCountPolicy        > SFUncountedRoundedCornerLineBorderPtr;


/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<RoundedCornerLineBorder *,
                      RecordedRefCountPolicy  > MFRecRoundedCornerLineBorderPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<RoundedCornerLineBorder *,
                      UnrecordedRefCountPolicy> MFUnrecRoundedCornerLineBorderPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<RoundedCornerLineBorder *,
                      WeakRefCountPolicy      > MFWeakRoundedCornerLineBorderPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<RoundedCornerLineBorder *,
                      NoRefCountPolicy        > MFUncountedRoundedCornerLineBorderPtr;




#else // these are the doxygen hacks

/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFRecRoundedCornerLineBorderPtr : 
    public PointerSField<RoundedCornerLineBorder *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUnrecRoundedCornerLineBorderPtr : 
    public PointerSField<RoundedCornerLineBorder *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFWeakRoundedCornerLineBorderPtr :
    public PointerSField<RoundedCornerLineBorder *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUncountedRoundedCornerLineBorderPtr :
    public PointerSField<RoundedCornerLineBorder *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFRecRoundedCornerLineBorderPtr :
    public PointerMField<RoundedCornerLineBorder *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUnrecRoundedCornerLineBorderPtr :
    public PointerMField<RoundedCornerLineBorder *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFWeakRoundedCornerLineBorderPtr :
    public PointerMField<RoundedCornerLineBorder *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUncountedRoundedCornerLineBorderPtr :
    public PointerMField<RoundedCornerLineBorder *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGROUNDEDCORNERLINEBORDERFIELDS_H_ */
