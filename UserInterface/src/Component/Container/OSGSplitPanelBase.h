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
 **     class SplitPanel
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGSPLITPANELBASE_H_
#define _OSGSPLITPANELBASE_H_
#ifdef __sgi
#pragma once
#endif


#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"

#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGRefPtr.h>
#include <OpenSG/OSGCoredNodePtr.h>

#include "OSGContainer.h" // Parent

#include "Component/OSGComponent.h" // MinComponent type
#include "Component/OSGComponent.h" // MaxComponent type
#include <OpenSG/OSGUInt32Fields.h> // DividerSize type
#include <OpenSG/OSGReal32Fields.h> // DividerPosition type
#include <OpenSG/OSGReal32Fields.h> // MinDividerPosition type
#include <OpenSG/OSGReal32Fields.h> // MaxDividerPosition type
#include "Component/OSGUIDrawObjectCanvas.h" // DividerDrawObject type
#include <OpenSG/OSGBoolFields.h> // Expandable type
#include <OpenSG/OSGUInt32Fields.h> // Alignment type

#include "OSGSplitPanelFields.h"

OSG_BEGIN_NAMESPACE

class SplitPanel;
class BinaryDataHandler;

//! \brief SplitPanel Base Class.

class OSG_USERINTERFACELIB_DLLMAPPING SplitPanelBase : public Container
{
  private:

    typedef Container    Inherited;

    /*==========================  PUBLIC  =================================*/
  public:

    typedef SplitPanelPtr  Ptr;

    enum
    {
        MinComponentFieldId       = Inherited::NextFieldId,
        MaxComponentFieldId       = MinComponentFieldId       + 1,
        DividerSizeFieldId        = MaxComponentFieldId       + 1,
        DividerPositionFieldId    = DividerSizeFieldId        + 1,
        MinDividerPositionFieldId = DividerPositionFieldId    + 1,
        MaxDividerPositionFieldId = MinDividerPositionFieldId + 1,
        DividerDrawObjectFieldId  = MaxDividerPositionFieldId + 1,
        ExpandableFieldId         = DividerDrawObjectFieldId  + 1,
        AlignmentFieldId          = ExpandableFieldId         + 1,
        NextFieldId               = AlignmentFieldId          + 1
    };

    static const OSG::BitVector MinComponentFieldMask;
    static const OSG::BitVector MaxComponentFieldMask;
    static const OSG::BitVector DividerSizeFieldMask;
    static const OSG::BitVector DividerPositionFieldMask;
    static const OSG::BitVector MinDividerPositionFieldMask;
    static const OSG::BitVector MaxDividerPositionFieldMask;
    static const OSG::BitVector DividerDrawObjectFieldMask;
    static const OSG::BitVector ExpandableFieldMask;
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

           SFComponentPtr      *getSFMinComponent   (void);
           SFComponentPtr      *getSFMaxComponent   (void);
           SFUInt32            *getSFDividerSize    (void);
           SFReal32            *getSFDividerPosition(void);
           SFReal32            *getSFMinDividerPosition(void);
           SFReal32            *getSFMaxDividerPosition(void);
           SFUIDrawObjectCanvasPtr *getSFDividerDrawObject(void);
           SFBool              *getSFExpandable     (void);
           SFUInt32            *getSFAlignment      (void);

           ComponentPtr        &getMinComponent   (void);
     const ComponentPtr        &getMinComponent   (void) const;
           ComponentPtr        &getMaxComponent   (void);
     const ComponentPtr        &getMaxComponent   (void) const;
           UInt32              &getDividerSize    (void);
     const UInt32              &getDividerSize    (void) const;
           Real32              &getDividerPosition(void);
     const Real32              &getDividerPosition(void) const;
           Real32              &getMinDividerPosition(void);
     const Real32              &getMinDividerPosition(void) const;
           Real32              &getMaxDividerPosition(void);
     const Real32              &getMaxDividerPosition(void) const;
           UIDrawObjectCanvasPtr &getDividerDrawObject(void);
     const UIDrawObjectCanvasPtr &getDividerDrawObject(void) const;
           bool                &getExpandable     (void);
     const bool                &getExpandable     (void) const;
           UInt32              &getAlignment      (void);
     const UInt32              &getAlignment      (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

     void setMinComponent   ( const ComponentPtr &value );
     void setMaxComponent   ( const ComponentPtr &value );
     void setDividerSize    ( const UInt32 &value );
     void setDividerPosition( const Real32 &value );
     void setMinDividerPosition( const Real32 &value );
     void setMaxDividerPosition( const Real32 &value );
     virtual void setDividerDrawObject( const UIDrawObjectCanvasPtr &value );
     void setExpandable     ( const bool &value );
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

    static  SplitPanelPtr      create          (void); 
    static  SplitPanelPtr      createEmpty     (void); 

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

    SFComponentPtr      _sfMinComponent;
    SFComponentPtr      _sfMaxComponent;
    SFUInt32            _sfDividerSize;
    SFReal32            _sfDividerPosition;
    SFReal32            _sfMinDividerPosition;
    SFReal32            _sfMaxDividerPosition;
    SFUIDrawObjectCanvasPtr   _sfDividerDrawObject;
    SFBool              _sfExpandable;
    SFUInt32            _sfAlignment;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    SplitPanelBase(void);
    SplitPanelBase(const SplitPanelBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~SplitPanelBase(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#if !defined(OSG_FIXED_MFIELDSYNC)
    void executeSyncImpl(      SplitPanelBase *pOther,
                         const BitVector         &whichField);

    virtual void   executeSync(      FieldContainer    &other,
                               const BitVector         &whichField);
#else
    void executeSyncImpl(      SplitPanelBase *pOther,
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
    void operator =(const SplitPanelBase &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------


typedef SplitPanelBase *SplitPanelBaseP;

typedef osgIF<SplitPanelBase::isNodeCore,
              CoredNodePtr<SplitPanel>,
              FieldContainer::attempt_to_create_CoredNodePtr_on_non_NodeCore_FC
              >::_IRet SplitPanelNodePtr;

typedef RefPtr<SplitPanelPtr> SplitPanelRefPtr;

OSG_END_NAMESPACE

#define OSGSPLITPANELBASE_HEADER_CVSID "@(#)$Id: FCBaseTemplate_h.h,v 1.40 2005/07/20 00:10:14 vossg Exp $"

#endif /* _OSGSPLITPANELBASE_H_ */
