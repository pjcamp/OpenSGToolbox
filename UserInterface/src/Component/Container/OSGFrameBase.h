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
 **     class Frame
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGFRAMEBASE_H_
#define _OSGFRAMEBASE_H_
#ifdef __sgi
#pragma once
#endif


#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"

#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGRefPtr.h>
#include <OpenSG/OSGCoredNodePtr.h>

#include "OSGContainer.h" // Parent

#include "Component/OSGComponentFields.h" // FocusedComponent type
#include "UIDrawingSurface/OSGUIDrawingSurfaceFields.h" // DrawingSurface type
#include "Component/Menu/OSGPopupMenuFields.h" // ActivePopupMenus type
#include "Component/Misc/OSGToolTipFields.h" // ActiveToolTip type
#include <OpenSG/OSGBoolFields.h> // LockInput type

#include "OSGFrameFields.h"

OSG_BEGIN_NAMESPACE

class Frame;
class BinaryDataHandler;

//! \brief Frame Base Class.

class OSG_USERINTERFACELIB_DLLMAPPING FrameBase : public Container
{
  private:

    typedef Container    Inherited;

    /*==========================  PUBLIC  =================================*/
  public:

    typedef FramePtr  Ptr;

    enum
    {
        FocusedComponentFieldId = Inherited::NextFieldId,
        DrawingSurfaceFieldId   = FocusedComponentFieldId + 1,
        ActivePopupMenusFieldId = DrawingSurfaceFieldId   + 1,
        ActiveToolTipFieldId    = ActivePopupMenusFieldId + 1,
        LockInputFieldId        = ActiveToolTipFieldId    + 1,
        NextFieldId             = LockInputFieldId        + 1
    };

    static const OSG::BitVector FocusedComponentFieldMask;
    static const OSG::BitVector DrawingSurfaceFieldMask;
    static const OSG::BitVector ActivePopupMenusFieldMask;
    static const OSG::BitVector ActiveToolTipFieldMask;
    static const OSG::BitVector LockInputFieldMask;


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

           SFComponentPtr      *getSFFocusedComponent(void);
           SFUIDrawingSurfacePtr *getSFDrawingSurface (void);
           MFPopupMenuPtr      *getMFActivePopupMenus(void);
           SFToolTipPtr        *getSFActiveToolTip  (void);
           SFBool              *getSFLockInput      (void);

           ComponentPtr        &getFocusedComponent(void);
     const ComponentPtr        &getFocusedComponent(void) const;
           UIDrawingSurfacePtr &getDrawingSurface (void);
     const UIDrawingSurfacePtr &getDrawingSurface (void) const;
           ToolTipPtr          &getActiveToolTip  (void);
     const ToolTipPtr          &getActiveToolTip  (void) const;
           bool                &getLockInput      (void);
     const bool                &getLockInput      (void) const;
           PopupMenuPtr        &getActivePopupMenus(const UInt32 index);
           MFPopupMenuPtr      &getActivePopupMenus(void);
     const MFPopupMenuPtr      &getActivePopupMenus(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

     void setFocusedComponent( const ComponentPtr &value );
     void setDrawingSurface ( const UIDrawingSurfacePtr &value );
     void setActiveToolTip  ( const ToolTipPtr &value );
     void setLockInput      ( const bool &value );

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

    static  FramePtr      create          (void); 
    static  FramePtr      createEmpty     (void); 

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

    SFComponentPtr      _sfFocusedComponent;
    SFUIDrawingSurfacePtr   _sfDrawingSurface;
    MFPopupMenuPtr      _mfActivePopupMenus;
    SFToolTipPtr        _sfActiveToolTip;
    SFBool              _sfLockInput;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    FrameBase(void);
    FrameBase(const FrameBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~FrameBase(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#if !defined(OSG_FIXED_MFIELDSYNC)
    void executeSyncImpl(      FrameBase *pOther,
                         const BitVector         &whichField);

    virtual void   executeSync(      FieldContainer    &other,
                               const BitVector         &whichField);
#else
    void executeSyncImpl(      FrameBase *pOther,
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
    void operator =(const FrameBase &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------


typedef FrameBase *FrameBaseP;

typedef osgIF<FrameBase::isNodeCore,
              CoredNodePtr<Frame>,
              FieldContainer::attempt_to_create_CoredNodePtr_on_non_NodeCore_FC
              >::_IRet FrameNodePtr;

typedef RefPtr<FramePtr> FrameRefPtr;

OSG_END_NAMESPACE

#define OSGFRAMEBASE_HEADER_CVSID "@(#)$Id: FCBaseTemplate_h.h,v 1.40 2005/07/20 00:10:14 vossg Exp $"

#endif /* _OSGFRAMEBASE_H_ */
