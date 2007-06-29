/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2002 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 *   contact: dirk@opensg.org, gerrit.voss@vossg.org, jbehr@zgdv.de          *
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
 **     Do not change this file, changes should be done in the derived      **
 **     class GradientUIBackground
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGGRADIENTUIBACKGROUNDBASE_H_
#define _OSGGRADIENTUIBACKGROUNDBASE_H_
#ifdef __sgi
#pragma once
#endif


#include "OSGUserInterfaceConfig.h"

#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGRefPtr.h>
#include <OpenSG/OSGCoredNodePtr.h>

#include "OSGUIBackground.h" // Parent

#include <OpenSG/OSGColor4fFields.h> // ColorStart type
#include <OpenSG/OSGColor4fFields.h> // ColorEnd type
#include <OpenSG/OSGUInt32Fields.h> // Alignment type

#include "OSGGradientUIBackgroundFields.h"

OSG_BEGIN_NAMESPACE

class GradientUIBackground;
class BinaryDataHandler;

//! \brief GradientUIBackground Base Class.

class OSG_USER_INTERFACE_CLASS_API GradientUIBackgroundBase : public UIBackground
{
  private:

    typedef UIBackground    Inherited;

    /*==========================  PUBLIC  =================================*/
  public:

    typedef GradientUIBackgroundPtr  Ptr;

    enum
    {
        ColorStartFieldId = Inherited::NextFieldId,
        ColorEndFieldId   = ColorStartFieldId + 1,
        AlignmentFieldId  = ColorEndFieldId   + 1,
        NextFieldId       = AlignmentFieldId  + 1
    };

    static const OSG::BitVector ColorStartFieldMask;
    static const OSG::BitVector ColorEndFieldMask;
    static const OSG::BitVector AlignmentFieldMask;


    static const OSG::BitVector MTInfluenceMask;

    /*---------------------------------------------------------------------*/
    /*! \name                    Class Get                                 */
    /*! \{                                                                 */

    static        FieldContainerType &getClassType    (void); 
    static        UInt32              getClassTypeId  (void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                FieldContainer Get                            */
    /*! \{                                                                 */

    virtual       FieldContainerType &getType  (void); 
    virtual const FieldContainerType &getType  (void) const; 

    virtual       UInt32              getContainerSize(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Get                                 */
    /*! \{                                                                 */

           SFColor4f           *getSFColorStart     (void);
           SFColor4f           *getSFColorEnd       (void);
           SFUInt32            *getSFAlignment      (void);

           Color4f             &getColorStart     (void);
     const Color4f             &getColorStart     (void) const;
           Color4f             &getColorEnd       (void);
     const Color4f             &getColorEnd       (void) const;
           UInt32              &getAlignment      (void);
     const UInt32              &getAlignment      (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

     void setColorStart     ( const Color4f &value );
     void setColorEnd       ( const Color4f &value );
     void setAlignment      ( const UInt32 &value );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Binary Access                              */
    /*! \{                                                                 */

    virtual UInt32 getBinSize (const BitVector         &whichField);
    virtual void   copyToBin  (      BinaryDataHandler &pMem,
                               const BitVector         &whichField);
    virtual void   copyFromBin(      BinaryDataHandler &pMem,
                               const BitVector         &whichField);


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Construction                               */
    /*! \{                                                                 */

    static  GradientUIBackgroundPtr      create          (void); 
    static  GradientUIBackgroundPtr      createEmpty     (void); 

    /*! \}                                                                 */

    /*---------------------------------------------------------------------*/
    /*! \name                       Copy                                   */
    /*! \{                                                                 */

    virtual FieldContainerPtr     shallowCopy     (void) const; 

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/
  protected:

    /*---------------------------------------------------------------------*/
    /*! \name                      Fields                                  */
    /*! \{                                                                 */

    SFColor4f           _sfColorStart;
    SFColor4f           _sfColorEnd;
    SFUInt32            _sfAlignment;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    GradientUIBackgroundBase(void);
    GradientUIBackgroundBase(const GradientUIBackgroundBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~GradientUIBackgroundBase(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#if !defined(OSG_FIXED_MFIELDSYNC)
    void executeSyncImpl(      GradientUIBackgroundBase *pOther,
                         const BitVector         &whichField);

    virtual void   executeSync(      FieldContainer    &other,
                               const BitVector         &whichField);
#else
    void executeSyncImpl(      GradientUIBackgroundBase *pOther,
                         const BitVector         &whichField,
                         const SyncInfo          &sInfo     );

    virtual void   executeSync(      FieldContainer    &other,
                               const BitVector         &whichField,
                               const SyncInfo          &sInfo);

    virtual void execBeginEdit     (const BitVector &whichField,
                                          UInt32     uiAspect,
                                          UInt32     uiContainerSize);

            void execBeginEditImpl (const BitVector &whichField,
                                          UInt32     uiAspect,
                                          UInt32     uiContainerSize);

    virtual void onDestroyAspect(UInt32 uiId, UInt32 uiAspect);
#endif

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/
  private:

    friend class FieldContainer;

    static FieldDescription   *_desc[];
    static FieldContainerType  _type;


    // prohibit default functions (move to 'public' if you need one)
    void operator =(const GradientUIBackgroundBase &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------


typedef GradientUIBackgroundBase *GradientUIBackgroundBaseP;

typedef osgIF<GradientUIBackgroundBase::isNodeCore,
              CoredNodePtr<GradientUIBackground>,
              FieldContainer::attempt_to_create_CoredNodePtr_on_non_NodeCore_FC
              >::_IRet GradientUIBackgroundNodePtr;

typedef RefPtr<GradientUIBackgroundPtr> GradientUIBackgroundRefPtr;

OSG_END_NAMESPACE

#define OSGGRADIENTUIBACKGROUNDBASE_HEADER_CVSID "@(#)$Id: FCBaseTemplate_h.h,v 1.40 2005/07/20 00:10:14 vossg Exp $"

#endif /* _OSGGRADIENTUIBACKGROUNDBASE_H_ */
