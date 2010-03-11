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


#ifndef _OSGPROGRESSBARFIELDS_H_
#define _OSGPROGRESSBARFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGContribUserInterfaceDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE

class ProgressBar;

OSG_GEN_CONTAINERPTR(ProgressBar);

/*! \ingroup GrpContribUserInterfaceFieldTraits
    \ingroup GrpLibOSGContribUserInterface
 */
template <>
struct FieldTraits<ProgressBar *> :
    public FieldTraitsFCPtrBase<ProgressBar *>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<ProgressBar *>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_CONTRIBUSERINTERFACE_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFProgressBarPtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFProgressBarPtr"; }
};

template<> inline
const Char8 *FieldTraits<ProgressBar *, 0>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecProgressBarPtr"; 
}

template<> inline
const Char8 *FieldTraits<ProgressBar *, 0>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecProgressBarPtr"; 
}

template<> inline
const Char8 *FieldTraits<ProgressBar *, 0>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakProgressBarPtr"; 
}

template<> inline
const Char8 *FieldTraits<ProgressBar *, 0>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdProgressBarPtr"; 
}

template<> inline
const Char8 *FieldTraits<ProgressBar *, 0>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecProgressBarPtr"; 
}

template<> inline
const Char8 *FieldTraits<ProgressBar *, 0>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecProgressBarPtr"; 
}

template<> inline
const Char8 *FieldTraits<ProgressBar *, 0>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakProgressBarPtr"; 
}

template<> inline
const Char8 *FieldTraits<ProgressBar *, 0>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdProgressBarPtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<ProgressBar *,
                      RecordedRefCountPolicy  > SFRecProgressBarPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<ProgressBar *,
                      UnrecordedRefCountPolicy> SFUnrecProgressBarPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<ProgressBar *,
                      WeakRefCountPolicy      > SFWeakProgressBarPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<ProgressBar *,
                      NoRefCountPolicy        > SFUncountedProgressBarPtr;


/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<ProgressBar *,
                      RecordedRefCountPolicy  > MFRecProgressBarPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<ProgressBar *,
                      UnrecordedRefCountPolicy> MFUnrecProgressBarPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<ProgressBar *,
                      WeakRefCountPolicy      > MFWeakProgressBarPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<ProgressBar *,
                      NoRefCountPolicy        > MFUncountedProgressBarPtr;




#else // these are the doxygen hacks

/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFRecProgressBarPtr : 
    public PointerSField<ProgressBar *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUnrecProgressBarPtr : 
    public PointerSField<ProgressBar *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFWeakProgressBarPtr :
    public PointerSField<ProgressBar *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUncountedProgressBarPtr :
    public PointerSField<ProgressBar *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFRecProgressBarPtr :
    public PointerMField<ProgressBar *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUnrecProgressBarPtr :
    public PointerMField<ProgressBar *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFWeakProgressBarPtr :
    public PointerMField<ProgressBar *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUncountedProgressBarPtr :
    public PointerMField<ProgressBar *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGPROGRESSBARFIELDS_H_ */
