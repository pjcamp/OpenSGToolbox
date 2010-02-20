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


#ifndef _OSGTOOLTIPFIELDS_H_
#define _OSGTOOLTIPFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGContribUserInterfaceDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE

class ToolTip;

OSG_GEN_CONTAINERPTR(ToolTip);

/*! \ingroup GrpContribUserInterfaceFieldTraits
    \ingroup GrpLibOSGContribUserInterface
 */
template <>
struct FieldTraits<ToolTip *> :
    public FieldTraitsFCPtrBase<ToolTip *>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<ToolTip *>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_CONTRIBUSERINTERFACE_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFToolTipPtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFToolTipPtr"; }
};

template<> inline
const Char8 *FieldTraits<ToolTip *, 0>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecToolTipPtr"; 
}

template<> inline
const Char8 *FieldTraits<ToolTip *, 0>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecToolTipPtr"; 
}

template<> inline
const Char8 *FieldTraits<ToolTip *, 0>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakToolTipPtr"; 
}

template<> inline
const Char8 *FieldTraits<ToolTip *, 0>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdToolTipPtr"; 
}

template<> inline
const Char8 *FieldTraits<ToolTip *, 0>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecToolTipPtr"; 
}

template<> inline
const Char8 *FieldTraits<ToolTip *, 0>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecToolTipPtr"; 
}

template<> inline
const Char8 *FieldTraits<ToolTip *, 0>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakToolTipPtr"; 
}

template<> inline
const Char8 *FieldTraits<ToolTip *, 0>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdToolTipPtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<ToolTip *,
                      RecordedRefCountPolicy  > SFRecToolTipPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<ToolTip *,
                      UnrecordedRefCountPolicy> SFUnrecToolTipPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<ToolTip *,
                      WeakRefCountPolicy      > SFWeakToolTipPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<ToolTip *,
                      NoRefCountPolicy        > SFUncountedToolTipPtr;


/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<ToolTip *,
                      RecordedRefCountPolicy  > MFRecToolTipPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<ToolTip *,
                      UnrecordedRefCountPolicy> MFUnrecToolTipPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<ToolTip *,
                      WeakRefCountPolicy      > MFWeakToolTipPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<ToolTip *,
                      NoRefCountPolicy        > MFUncountedToolTipPtr;




#else // these are the doxygen hacks

/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFRecToolTipPtr : 
    public PointerSField<ToolTip *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUnrecToolTipPtr : 
    public PointerSField<ToolTip *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFWeakToolTipPtr :
    public PointerSField<ToolTip *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUncountedToolTipPtr :
    public PointerSField<ToolTip *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFRecToolTipPtr :
    public PointerMField<ToolTip *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUnrecToolTipPtr :
    public PointerMField<ToolTip *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFWeakToolTipPtr :
    public PointerMField<ToolTip *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUncountedToolTipPtr :
    public PointerMField<ToolTip *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGTOOLTIPFIELDS_H_ */
