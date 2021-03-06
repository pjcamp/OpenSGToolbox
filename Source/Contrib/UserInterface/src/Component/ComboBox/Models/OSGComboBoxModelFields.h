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


#ifndef _OSGCOMBOBOXMODELFIELDS_H_
#define _OSGCOMBOBOXMODELFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGContribUserInterfaceDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE

class ComboBoxModel;

OSG_GEN_CONTAINERPTR(ComboBoxModel);

/*! \ingroup GrpContribUserInterfaceFieldTraits
    \ingroup GrpLibOSGContribUserInterface
 */
template <>
struct FieldTraits<ComboBoxModel *> :
    public FieldTraitsFCPtrBase<ComboBoxModel *>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<ComboBoxModel *>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_CONTRIBUSERINTERFACE_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFComboBoxModelPtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFComboBoxModelPtr"; }
};

template<> inline
const Char8 *FieldTraits<ComboBoxModel *, 0>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecComboBoxModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<ComboBoxModel *, 0>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecComboBoxModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<ComboBoxModel *, 0>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakComboBoxModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<ComboBoxModel *, 0>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdComboBoxModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<ComboBoxModel *, 0>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecComboBoxModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<ComboBoxModel *, 0>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecComboBoxModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<ComboBoxModel *, 0>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakComboBoxModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<ComboBoxModel *, 0>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdComboBoxModelPtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<ComboBoxModel *,
                      RecordedRefCountPolicy  > SFRecComboBoxModelPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<ComboBoxModel *,
                      UnrecordedRefCountPolicy> SFUnrecComboBoxModelPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<ComboBoxModel *,
                      WeakRefCountPolicy      > SFWeakComboBoxModelPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<ComboBoxModel *,
                      NoRefCountPolicy        > SFUncountedComboBoxModelPtr;


/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<ComboBoxModel *,
                      RecordedRefCountPolicy  > MFRecComboBoxModelPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<ComboBoxModel *,
                      UnrecordedRefCountPolicy> MFUnrecComboBoxModelPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<ComboBoxModel *,
                      WeakRefCountPolicy      > MFWeakComboBoxModelPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<ComboBoxModel *,
                      NoRefCountPolicy        > MFUncountedComboBoxModelPtr;




#else // these are the doxygen hacks

/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFRecComboBoxModelPtr : 
    public PointerSField<ComboBoxModel *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUnrecComboBoxModelPtr : 
    public PointerSField<ComboBoxModel *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFWeakComboBoxModelPtr :
    public PointerSField<ComboBoxModel *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUncountedComboBoxModelPtr :
    public PointerSField<ComboBoxModel *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFRecComboBoxModelPtr :
    public PointerMField<ComboBoxModel *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUnrecComboBoxModelPtr :
    public PointerMField<ComboBoxModel *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFWeakComboBoxModelPtr :
    public PointerMField<ComboBoxModel *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUncountedComboBoxModelPtr :
    public PointerMField<ComboBoxModel *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGCOMBOBOXMODELFIELDS_H_ */
