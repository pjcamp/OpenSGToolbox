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


#ifndef _OSGDOCUMENTFIELDS_H_
#define _OSGDOCUMENTFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGContribUserInterfaceDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE

class Document;

OSG_GEN_CONTAINERPTR(Document);

/*! \ingroup GrpContribUserInterfaceFieldTraits
    \ingroup GrpLibOSGContribUserInterface
 */
template <>
struct FieldTraits<Document *> :
    public FieldTraitsFCPtrBase<Document *>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<Document *>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_CONTRIBUSERINTERFACE_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFDocumentPtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFDocumentPtr"; }
};

template<> inline
const Char8 *FieldTraits<Document *, 0>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecDocumentPtr"; 
}

template<> inline
const Char8 *FieldTraits<Document *, 0>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecDocumentPtr"; 
}

template<> inline
const Char8 *FieldTraits<Document *, 0>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakDocumentPtr"; 
}

template<> inline
const Char8 *FieldTraits<Document *, 0>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdDocumentPtr"; 
}

template<> inline
const Char8 *FieldTraits<Document *, 0>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecDocumentPtr"; 
}

template<> inline
const Char8 *FieldTraits<Document *, 0>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecDocumentPtr"; 
}

template<> inline
const Char8 *FieldTraits<Document *, 0>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakDocumentPtr"; 
}

template<> inline
const Char8 *FieldTraits<Document *, 0>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdDocumentPtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<Document *,
                      RecordedRefCountPolicy  > SFRecDocumentPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<Document *,
                      UnrecordedRefCountPolicy> SFUnrecDocumentPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<Document *,
                      WeakRefCountPolicy      > SFWeakDocumentPtr;
/*! \ingroup GrpContribUserInterfaceFieldSFields */
typedef PointerSField<Document *,
                      NoRefCountPolicy        > SFUncountedDocumentPtr;


/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<Document *,
                      RecordedRefCountPolicy  > MFRecDocumentPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<Document *,
                      UnrecordedRefCountPolicy> MFUnrecDocumentPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<Document *,
                      WeakRefCountPolicy      > MFWeakDocumentPtr;
/*! \ingroup GrpContribUserInterfaceFieldMFields */
typedef PointerMField<Document *,
                      NoRefCountPolicy        > MFUncountedDocumentPtr;




#else // these are the doxygen hacks

/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFRecDocumentPtr : 
    public PointerSField<Document *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUnrecDocumentPtr : 
    public PointerSField<Document *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFWeakDocumentPtr :
    public PointerSField<Document *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldSFields \ingroup GrpLibOSGContribUserInterface */
struct SFUncountedDocumentPtr :
    public PointerSField<Document *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFRecDocumentPtr :
    public PointerMField<Document *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUnrecDocumentPtr :
    public PointerMField<Document *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFWeakDocumentPtr :
    public PointerMField<Document *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpContribUserInterfaceFieldMFields \ingroup GrpLibOSGContribUserInterface */
struct MFUncountedDocumentPtr :
    public PointerMField<Document *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGDOCUMENTFIELDS_H_ */
