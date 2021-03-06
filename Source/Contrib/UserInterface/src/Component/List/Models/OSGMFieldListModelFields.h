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


#ifndef _OSGMFIELDLISTMODELFIELDS_H_
#define _OSGMFIELDLISTMODELFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGContribUserInterfaceDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE

class MFieldListModel;

OSG_GEN_CONTAINERPTR(MFieldListModel);

/*! \ingroup GrpContribUserInterfaceFieldTraits
    \ingroup GrpLibOSGContribUserInterface
 */
template <>
struct FieldTraits<MFieldListModel *> :
    public FieldTraitsFCPtrBase<MFieldListModel *>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<MFieldListModel *>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_CONTRIBUSERINTERFACE_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFMFieldListModelPtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFMFieldListModelPtr"; }
};

template<> inline
const Char8 *FieldTraits<MFieldListModel *, 0>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecMFieldListModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<MFieldListModel *, 0>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecMFieldListModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<MFieldListModel *, 0>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakMFieldListModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<MFieldListModel *, 0>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdMFieldListModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<MFieldListModel *, 0>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecMFieldListModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<MFieldListModel *, 0>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecMFieldListModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<MFieldListModel *, 0>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakMFieldListModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<MFieldListModel *, 0>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdMFieldListModelPtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<MFieldListModel *,
                      RecordedRefCountPolicy  > SFRecMFieldListModelPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<MFieldListModel *,
                      UnrecordedRefCountPolicy> SFUnrecMFieldListModelPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<MFieldListModel *,
                      WeakRefCountPolicy      > SFWeakMFieldListModelPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<MFieldListModel *,
                      NoRefCountPolicy        > SFUncountedMFieldListModelPtr;


/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<MFieldListModel *,
                      RecordedRefCountPolicy  > MFRecMFieldListModelPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<MFieldListModel *,
                      UnrecordedRefCountPolicy> MFUnrecMFieldListModelPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<MFieldListModel *,
                      WeakRefCountPolicy      > MFWeakMFieldListModelPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<MFieldListModel *,
                      NoRefCountPolicy        > MFUncountedMFieldListModelPtr;




#else // these are the doxygen hacks

/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFRecMFieldListModelPtr : 
    public PointerSField<MFieldListModel *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUnrecMFieldListModelPtr : 
    public PointerSField<MFieldListModel *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFWeakMFieldListModelPtr :
    public PointerSField<MFieldListModel *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUncountedMFieldListModelPtr :
    public PointerSField<MFieldListModel *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFRecMFieldListModelPtr :
    public PointerMField<MFieldListModel *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUnrecMFieldListModelPtr :
    public PointerMField<MFieldListModel *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFWeakMFieldListModelPtr :
    public PointerMField<MFieldListModel *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUncountedMFieldListModelPtr :
    public PointerMField<MFieldListModel *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGMFIELDLISTMODELFIELDS_H_ */
