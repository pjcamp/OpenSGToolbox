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


#ifndef _OSGDEFAULTLISTSELECTIONMODELFIELDS_H_
#define _OSGDEFAULTLISTSELECTIONMODELFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGContribUserInterfaceDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE

class DefaultListSelectionModel;

OSG_GEN_CONTAINERPTR(DefaultListSelectionModel);

/*! \ingroup GrpContribUserInterfaceFieldTraits
    \ingroup GrpLibOSGContribUserInterface
 */
template <>
struct FieldTraits<DefaultListSelectionModel *> :
    public FieldTraitsFCPtrBase<DefaultListSelectionModel *>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<DefaultListSelectionModel *>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_CONTRIBUSERINTERFACE_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFDefaultListSelectionModelPtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFDefaultListSelectionModelPtr"; }
};

template<> inline
const Char8 *FieldTraits<DefaultListSelectionModel *, 0>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecDefaultListSelectionModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<DefaultListSelectionModel *, 0>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecDefaultListSelectionModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<DefaultListSelectionModel *, 0>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakDefaultListSelectionModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<DefaultListSelectionModel *, 0>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdDefaultListSelectionModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<DefaultListSelectionModel *, 0>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecDefaultListSelectionModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<DefaultListSelectionModel *, 0>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecDefaultListSelectionModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<DefaultListSelectionModel *, 0>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakDefaultListSelectionModelPtr"; 
}

template<> inline
const Char8 *FieldTraits<DefaultListSelectionModel *, 0>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdDefaultListSelectionModelPtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<DefaultListSelectionModel *,
                      RecordedRefCountPolicy  > SFRecDefaultListSelectionModelPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<DefaultListSelectionModel *,
                      UnrecordedRefCountPolicy> SFUnrecDefaultListSelectionModelPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<DefaultListSelectionModel *,
                      WeakRefCountPolicy      > SFWeakDefaultListSelectionModelPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<DefaultListSelectionModel *,
                      NoRefCountPolicy        > SFUncountedDefaultListSelectionModelPtr;


/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<DefaultListSelectionModel *,
                      RecordedRefCountPolicy  > MFRecDefaultListSelectionModelPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<DefaultListSelectionModel *,
                      UnrecordedRefCountPolicy> MFUnrecDefaultListSelectionModelPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<DefaultListSelectionModel *,
                      WeakRefCountPolicy      > MFWeakDefaultListSelectionModelPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<DefaultListSelectionModel *,
                      NoRefCountPolicy        > MFUncountedDefaultListSelectionModelPtr;




#else // these are the doxygen hacks

/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFRecDefaultListSelectionModelPtr : 
    public PointerSField<DefaultListSelectionModel *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUnrecDefaultListSelectionModelPtr : 
    public PointerSField<DefaultListSelectionModel *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFWeakDefaultListSelectionModelPtr :
    public PointerSField<DefaultListSelectionModel *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUncountedDefaultListSelectionModelPtr :
    public PointerSField<DefaultListSelectionModel *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFRecDefaultListSelectionModelPtr :
    public PointerMField<DefaultListSelectionModel *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUnrecDefaultListSelectionModelPtr :
    public PointerMField<DefaultListSelectionModel *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFWeakDefaultListSelectionModelPtr :
    public PointerMField<DefaultListSelectionModel *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUncountedDefaultListSelectionModelPtr :
    public PointerMField<DefaultListSelectionModel *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGDEFAULTLISTSELECTIONMODELFIELDS_H_ */
