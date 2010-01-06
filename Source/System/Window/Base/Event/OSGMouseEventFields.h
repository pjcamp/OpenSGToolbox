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


#ifndef _OSGMOUSEEVENTFIELDS_H_
#define _OSGMOUSEEVENTFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGSystemDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE

class MouseEvent;

OSG_GEN_CONTAINERPTR(MouseEvent);

/*! \ingroup GrpSystemFieldTraits
    \ingroup GrpLibOSGSystem
 */
template <>
struct FieldTraits<MouseEvent *> :
    public FieldTraitsFCPtrBase<MouseEvent *>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<MouseEvent *>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_SYSTEM_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFMouseEventPtr"; }
};

template<> inline
const Char8 *FieldTraits<MouseEvent *, 0>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecMouseEventPtr"; 
}

template<> inline
const Char8 *FieldTraits<MouseEvent *, 0>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecMouseEventPtr"; 
}

template<> inline
const Char8 *FieldTraits<MouseEvent *, 0>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakMouseEventPtr"; 
}

template<> inline
const Char8 *FieldTraits<MouseEvent *, 0>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdMouseEventPtr"; 
}



#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpSystemFieldSFields */
typedef PointerSField<MouseEvent *,
                      RecordedRefCountPolicy  > SFRecMouseEventPtr;
/*! \ingroup GrpSystemFieldSFields */
typedef PointerSField<MouseEvent *,
                      UnrecordedRefCountPolicy> SFUnrecMouseEventPtr;
/*! \ingroup GrpSystemFieldSFields */
typedef PointerSField<MouseEvent *,
                      WeakRefCountPolicy      > SFWeakMouseEventPtr;
/*! \ingroup GrpSystemFieldSFields */
typedef PointerSField<MouseEvent *,
                      NoRefCountPolicy        > SFUncountedMouseEventPtr;




#else // these are the doxygen hacks

/*! \ingroup GrpSystemFieldSFields \ingroup GrpLibOSGSystem */
struct SFRecMouseEventPtr : 
    public PointerSField<MouseEvent *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpSystemFieldSFields \ingroup GrpLibOSGSystem */
struct SFUnrecMouseEventPtr : 
    public PointerSField<MouseEvent *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpSystemFieldSFields \ingroup GrpLibOSGSystem */
struct SFWeakMouseEventPtr :
    public PointerSField<MouseEvent *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpSystemFieldSFields \ingroup GrpLibOSGSystem */
struct SFUncountedMouseEventPtr :
    public PointerSField<MouseEvent *,
                         NoRefCountPolicy> {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGMOUSEEVENTFIELDS_H_ */