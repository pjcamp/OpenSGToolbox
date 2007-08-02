/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                         www.vrac.iastate.edu                              *
 *                                                                           *
 *   Authors: David Kabala, Alden Peterson, Lee Zaniewski, Jonathan Flory    *
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
 **     class ShadowBorder
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGSHADOWBORDERBASE_H_
#define _OSGSHADOWBORDERBASE_H_
#ifdef __sgi
#pragma once
#endif


#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"

#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGRefPtr.h>
#include <OpenSG/OSGCoredNodePtr.h>

#include "OSGBorder.h" // Parent

#include <OpenSG/OSGUInt32Fields.h> // VerticalOffset type
#include <OpenSG/OSGUInt32Fields.h> // HorizontalOffset type
#include <OpenSG/OSGColor4fFields.h> // Color type
#include "OSGBorder.h" // InsideBorder type

#include "OSGShadowBorderFields.h"

OSG_BEGIN_NAMESPACE

class ShadowBorder;
class BinaryDataHandler;

//! \brief ShadowBorder Base Class.

class OSG_USERINTERFACELIB_DLLMAPPING ShadowBorderBase : public Border
{
  private:

    typedef Border    Inherited;

    /*==========================  PUBLIC  =================================*/
  public:

    typedef ShadowBorderPtr  Ptr;

    enum
    {
        VerticalOffsetFieldId   = Inherited::NextFieldId,
        HorizontalOffsetFieldId = VerticalOffsetFieldId   + 1,
        ColorFieldId            = HorizontalOffsetFieldId + 1,
        InsideBorderFieldId     = ColorFieldId            + 1,
        NextFieldId             = InsideBorderFieldId     + 1
    };

    static const OSG::BitVector VerticalOffsetFieldMask;
    static const OSG::BitVector HorizontalOffsetFieldMask;
    static const OSG::BitVector ColorFieldMask;
    static const OSG::BitVector InsideBorderFieldMask;


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

           SFUInt32            *getSFVerticalOffset (void);
           SFUInt32            *getSFHorizontalOffset(void);
           SFColor4f           *getSFColor          (void);
           SFBorderPtr         *getSFInsideBorder   (void);

           UInt32              &getVerticalOffset (void);
     const UInt32              &getVerticalOffset (void) const;
           UInt32              &getHorizontalOffset(void);
     const UInt32              &getHorizontalOffset(void) const;
           Color4f             &getColor          (void);
     const Color4f             &getColor          (void) const;
           BorderPtr           &getInsideBorder   (void);
     const BorderPtr           &getInsideBorder   (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

     void setVerticalOffset ( const UInt32 &value );
     void setHorizontalOffset( const UInt32 &value );
     void setColor          ( const Color4f &value );
     void setInsideBorder   ( const BorderPtr &value );

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

    static  ShadowBorderPtr      create          (void); 
    static  ShadowBorderPtr      createEmpty     (void); 

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

    SFUInt32            _sfVerticalOffset;
    SFUInt32            _sfHorizontalOffset;
    SFColor4f           _sfColor;
    SFBorderPtr         _sfInsideBorder;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    ShadowBorderBase(void);
    ShadowBorderBase(const ShadowBorderBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~ShadowBorderBase(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#if !defined(OSG_FIXED_MFIELDSYNC)
    void executeSyncImpl(      ShadowBorderBase *pOther,
                         const BitVector         &whichField);

    virtual void   executeSync(      FieldContainer    &other,
                               const BitVector         &whichField);
#else
    void executeSyncImpl(      ShadowBorderBase *pOther,
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
    void operator =(const ShadowBorderBase &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------


typedef ShadowBorderBase *ShadowBorderBaseP;

typedef osgIF<ShadowBorderBase::isNodeCore,
              CoredNodePtr<ShadowBorder>,
              FieldContainer::attempt_to_create_CoredNodePtr_on_non_NodeCore_FC
              >::_IRet ShadowBorderNodePtr;

typedef RefPtr<ShadowBorderPtr> ShadowBorderRefPtr;

OSG_END_NAMESPACE

#define OSGSHADOWBORDERBASE_HEADER_CVSID "@(#)$Id: FCBaseTemplate_h.h,v 1.40 2005/07/20 00:10:14 vossg Exp $"

#endif /* _OSGSHADOWBORDERBASE_H_ */
