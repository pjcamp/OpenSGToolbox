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
 **     class MultiColorMatteBorder
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGMULTICOLORMATTEBORDERBASE_H_
#define _OSGMULTICOLORMATTEBORDERBASE_H_
#ifdef __sgi
#pragma once
#endif


#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"

#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGRefPtr.h>
#include <OpenSG/OSGCoredNodePtr.h>

#include "OSGBorder.h" // Parent

#include <OpenSG/OSGUInt32Fields.h> // LeftWidth type
#include <OpenSG/OSGUInt32Fields.h> // RightWidth type
#include <OpenSG/OSGUInt32Fields.h> // TopWidth type
#include <OpenSG/OSGUInt32Fields.h> // BottomWidth type
#include <OpenSG/OSGColor4fFields.h> // LeftLineTopColor type
#include <OpenSG/OSGColor4fFields.h> // LeftLineBottomColor type
#include <OpenSG/OSGColor4fFields.h> // TopLineLeftColor type
#include <OpenSG/OSGColor4fFields.h> // TopLineRightColor type
#include <OpenSG/OSGColor4fFields.h> // RightLineTopColor type
#include <OpenSG/OSGColor4fFields.h> // RightLineBottomColor type
#include <OpenSG/OSGColor4fFields.h> // BottomLineLeftColor type
#include <OpenSG/OSGColor4fFields.h> // BottomLineRightColor type

#include "OSGMultiColorMatteBorderFields.h"

OSG_BEGIN_NAMESPACE

class MultiColorMatteBorder;
class BinaryDataHandler;

//! \brief MultiColorMatteBorder Base Class.

class OSG_USERINTERFACELIB_DLLMAPPING MultiColorMatteBorderBase : public Border
{
  private:

    typedef Border    Inherited;

    /*==========================  PUBLIC  =================================*/
  public:

    typedef MultiColorMatteBorderPtr  Ptr;

    enum
    {
        LeftWidthFieldId            = Inherited::NextFieldId,
        RightWidthFieldId           = LeftWidthFieldId            + 1,
        TopWidthFieldId             = RightWidthFieldId           + 1,
        BottomWidthFieldId          = TopWidthFieldId             + 1,
        LeftLineTopColorFieldId     = BottomWidthFieldId          + 1,
        LeftLineBottomColorFieldId  = LeftLineTopColorFieldId     + 1,
        TopLineLeftColorFieldId     = LeftLineBottomColorFieldId  + 1,
        TopLineRightColorFieldId    = TopLineLeftColorFieldId     + 1,
        RightLineTopColorFieldId    = TopLineRightColorFieldId    + 1,
        RightLineBottomColorFieldId = RightLineTopColorFieldId    + 1,
        BottomLineLeftColorFieldId  = RightLineBottomColorFieldId + 1,
        BottomLineRightColorFieldId = BottomLineLeftColorFieldId  + 1,
        NextFieldId                 = BottomLineRightColorFieldId + 1
    };

    static const OSG::BitVector LeftWidthFieldMask;
    static const OSG::BitVector RightWidthFieldMask;
    static const OSG::BitVector TopWidthFieldMask;
    static const OSG::BitVector BottomWidthFieldMask;
    static const OSG::BitVector LeftLineTopColorFieldMask;
    static const OSG::BitVector LeftLineBottomColorFieldMask;
    static const OSG::BitVector TopLineLeftColorFieldMask;
    static const OSG::BitVector TopLineRightColorFieldMask;
    static const OSG::BitVector RightLineTopColorFieldMask;
    static const OSG::BitVector RightLineBottomColorFieldMask;
    static const OSG::BitVector BottomLineLeftColorFieldMask;
    static const OSG::BitVector BottomLineRightColorFieldMask;


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

           SFUInt32            *getSFLeftWidth      (void);
           SFUInt32            *getSFRightWidth     (void);
           SFUInt32            *getSFTopWidth       (void);
           SFUInt32            *getSFBottomWidth    (void);
           SFColor4f           *getSFLeftLineTopColor(void);
           SFColor4f           *getSFLeftLineBottomColor(void);
           SFColor4f           *getSFTopLineLeftColor(void);
           SFColor4f           *getSFTopLineRightColor(void);
           SFColor4f           *getSFRightLineTopColor(void);
           SFColor4f           *getSFRightLineBottomColor(void);
           SFColor4f           *getSFBottomLineLeftColor(void);
           SFColor4f           *getSFBottomLineRightColor(void);

           UInt32              &getLeftWidth      (void);
     const UInt32              &getLeftWidth      (void) const;
           UInt32              &getRightWidth     (void);
     const UInt32              &getRightWidth     (void) const;
           UInt32              &getTopWidth       (void);
     const UInt32              &getTopWidth       (void) const;
           UInt32              &getBottomWidth    (void);
     const UInt32              &getBottomWidth    (void) const;
           Color4f             &getLeftLineTopColor(void);
     const Color4f             &getLeftLineTopColor(void) const;
           Color4f             &getLeftLineBottomColor(void);
     const Color4f             &getLeftLineBottomColor(void) const;
           Color4f             &getTopLineLeftColor(void);
     const Color4f             &getTopLineLeftColor(void) const;
           Color4f             &getTopLineRightColor(void);
     const Color4f             &getTopLineRightColor(void) const;
           Color4f             &getRightLineTopColor(void);
     const Color4f             &getRightLineTopColor(void) const;
           Color4f             &getRightLineBottomColor(void);
     const Color4f             &getRightLineBottomColor(void) const;
           Color4f             &getBottomLineLeftColor(void);
     const Color4f             &getBottomLineLeftColor(void) const;
           Color4f             &getBottomLineRightColor(void);
     const Color4f             &getBottomLineRightColor(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

     void setLeftWidth      ( const UInt32 &value );
     void setRightWidth     ( const UInt32 &value );
     void setTopWidth       ( const UInt32 &value );
     void setBottomWidth    ( const UInt32 &value );
     void setLeftLineTopColor( const Color4f &value );
     void setLeftLineBottomColor( const Color4f &value );
     void setTopLineLeftColor( const Color4f &value );
     void setTopLineRightColor( const Color4f &value );
     void setRightLineTopColor( const Color4f &value );
     void setRightLineBottomColor( const Color4f &value );
     void setBottomLineLeftColor( const Color4f &value );
     void setBottomLineRightColor( const Color4f &value );

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

    static  MultiColorMatteBorderPtr      create          (void); 
    static  MultiColorMatteBorderPtr      createEmpty     (void); 

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

    SFUInt32            _sfLeftWidth;
    SFUInt32            _sfRightWidth;
    SFUInt32            _sfTopWidth;
    SFUInt32            _sfBottomWidth;
    SFColor4f           _sfLeftLineTopColor;
    SFColor4f           _sfLeftLineBottomColor;
    SFColor4f           _sfTopLineLeftColor;
    SFColor4f           _sfTopLineRightColor;
    SFColor4f           _sfRightLineTopColor;
    SFColor4f           _sfRightLineBottomColor;
    SFColor4f           _sfBottomLineLeftColor;
    SFColor4f           _sfBottomLineRightColor;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    MultiColorMatteBorderBase(void);
    MultiColorMatteBorderBase(const MultiColorMatteBorderBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~MultiColorMatteBorderBase(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#if !defined(OSG_FIXED_MFIELDSYNC)
    void executeSyncImpl(      MultiColorMatteBorderBase *pOther,
                         const BitVector         &whichField);

    virtual void   executeSync(      FieldContainer    &other,
                               const BitVector         &whichField);
#else
    void executeSyncImpl(      MultiColorMatteBorderBase *pOther,
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
    void operator =(const MultiColorMatteBorderBase &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------


typedef MultiColorMatteBorderBase *MultiColorMatteBorderBaseP;

typedef osgIF<MultiColorMatteBorderBase::isNodeCore,
              CoredNodePtr<MultiColorMatteBorder>,
              FieldContainer::attempt_to_create_CoredNodePtr_on_non_NodeCore_FC
              >::_IRet MultiColorMatteBorderNodePtr;

typedef RefPtr<MultiColorMatteBorderPtr> MultiColorMatteBorderRefPtr;

OSG_END_NAMESPACE

#define OSGMULTICOLORMATTEBORDERBASE_HEADER_CVSID "@(#)$Id: FCBaseTemplate_h.h,v 1.40 2005/07/20 00:10:14 vossg Exp $"

#endif /* _OSGMULTICOLORMATTEBORDERBASE_H_ */
