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
 **     Do not change this file, changes should be done in the derived      **
 **     class MenuButton
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGMENUBUTTONBASE_H_
#define _OSGMENUBUTTONBASE_H_
#ifdef __sgi
#pragma once
#endif


#include "OSGConfig.h"
#include "OSGContribUserInterfaceDef.h"

//#include "OSGBaseTypes.h"

#include "OSGToggleButton.h" // Parent

#include "OSGListModelFields.h"         // Model type
#include "OSGComponentGeneratorFields.h" // CellGenerator type
#include "OSGListGeneratedPopupMenuFields.h" // MenuButtonPopupMenu type

#include "OSGMenuButtonFields.h"

#include "OSGActionEventDetailsFields.h"

OSG_BEGIN_NAMESPACE

class MenuButton;

//! \brief MenuButton Base Class.

class OSG_CONTRIBUSERINTERFACE_DLLMAPPING MenuButtonBase : public ToggleButton
{
  public:

    typedef ToggleButton Inherited;
    typedef ToggleButton ParentContainer;

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    OSG_GEN_INTERNALPTR(MenuButton);
    
    
    typedef ActionEventDetails MenuActionPerformedEventDetailsType;

    typedef boost::signals2::signal<void (ActionEventDetails* const, UInt32), ConsumableEventCombiner> MenuActionPerformedEventType;

    /*==========================  PUBLIC  =================================*/

  public:

    enum
    {
        ModelFieldId = Inherited::NextFieldId,
        CellGeneratorFieldId = ModelFieldId + 1,
        MenuButtonPopupMenuFieldId = CellGeneratorFieldId + 1,
        NextFieldId = MenuButtonPopupMenuFieldId + 1
    };

    static const OSG::BitVector ModelFieldMask =
        (TypeTraits<BitVector>::One << ModelFieldId);
    static const OSG::BitVector CellGeneratorFieldMask =
        (TypeTraits<BitVector>::One << CellGeneratorFieldId);
    static const OSG::BitVector MenuButtonPopupMenuFieldMask =
        (TypeTraits<BitVector>::One << MenuButtonPopupMenuFieldId);
    static const OSG::BitVector NextFieldMask =
        (TypeTraits<BitVector>::One << NextFieldId);
        
    typedef SFUnrecListModelPtr SFModelType;
    typedef SFUnrecComponentGeneratorPtr SFCellGeneratorType;
    typedef SFUnrecListGeneratedPopupMenuPtr SFMenuButtonPopupMenuType;

    enum
    {
        MenuActionPerformedEventId = Inherited::NextProducedEventId,
        NextProducedEventId = MenuActionPerformedEventId + 1
    };

    /*---------------------------------------------------------------------*/
    /*! \name                    Class Get                                 */
    /*! \{                                                                 */

    static FieldContainerType &getClassType   (void);
    static UInt32              getClassTypeId (void);
    static UInt16              getClassGroupId(void);
    static const  EventProducerType  &getProducerClassType  (void);
    static        UInt32              getProducerClassTypeId(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                FieldContainer Get                            */
    /*! \{                                                                 */

    virtual       FieldContainerType &getType         (void);
    virtual const FieldContainerType &getType         (void) const;

    virtual       UInt32              getContainerSize(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Get                                 */
    /*! \{                                                                 */

            const SFUnrecListModelPtr *getSFModel          (void) const;
                  SFUnrecListModelPtr *editSFModel          (void);
            const SFUnrecComponentGeneratorPtr *getSFCellGenerator  (void) const;
                  SFUnrecComponentGeneratorPtr *editSFCellGenerator  (void);


                  ListModel * getModel          (void) const;

                  ComponentGenerator * getCellGenerator  (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

            void setModel          (ListModel * const value);
            void setCellGenerator  (ComponentGenerator * const value);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr Field Set                                 */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr MField Set                                */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Binary Access                              */
    /*! \{                                                                 */

    virtual UInt32 getBinSize (ConstFieldMaskArg  whichField);
    virtual void   copyToBin  (BinaryDataHandler &pMem,
                               ConstFieldMaskArg  whichField);
    virtual void   copyFromBin(BinaryDataHandler &pMem,
                               ConstFieldMaskArg  whichField);


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Event Produced Get                           */
    /*! \{                                                                 */

    virtual const EventProducerType &getProducerType(void) const; 

    
    virtual boost::signals2::connection connectEvent(UInt32 eventId, 
                                              const BaseEventType::slot_type &listener,
                                              boost::signals2::connect_position at= boost::signals2::at_back);
                                              
    virtual boost::signals2::connection connectEvent(UInt32 eventId, 
                                              const BaseEventType::group_type &group,
                                              const BaseEventType::slot_type &listener,
                                              boost::signals2::connect_position at= boost::signals2::at_back);
    
    virtual void   disconnectEvent        (UInt32 eventId, const BaseEventType::group_type &group);
    virtual void   disconnectAllSlotsEvent(UInt32 eventId);
    virtual bool   isEmptyEvent           (UInt32 eventId) const;
    virtual UInt32 numSlotsEvent          (UInt32 eventId) const;

    /*! \}                                                                 */
    /*! \name                Event Access                                 */
    /*! \{                                                                 */
    
    //MenuActionPerformed
    boost::signals2::connection connectMenuActionPerformed(const MenuActionPerformedEventType::slot_type &listener,
                                                       boost::signals2::connect_position at= boost::signals2::at_back);
    boost::signals2::connection connectMenuActionPerformed(const MenuActionPerformedEventType::group_type &group,
                                                       const MenuActionPerformedEventType::slot_type &listener,
                                                       boost::signals2::connect_position at= boost::signals2::at_back);
    void   disconnectMenuActionPerformed    (const MenuActionPerformedEventType::group_type &group);
    void   disconnectAllSlotsMenuActionPerformed(void);
    bool   isEmptyMenuActionPerformed       (void) const;
    UInt32 numSlotsMenuActionPerformed      (void) const;
    
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Construction                               */
    /*! \{                                                                 */

    static  MenuButtonTransitPtr  create          (void);
    static  MenuButton           *createEmpty     (void);

    static  MenuButtonTransitPtr  createLocal     (
                                               BitVector bFlags = FCLocal::All);

    static  MenuButton            *createEmptyLocal(
                                              BitVector bFlags = FCLocal::All);

    static  MenuButtonTransitPtr  createDependent  (BitVector bFlags);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Copy                                   */
    /*! \{                                                                 */

    virtual FieldContainerTransitPtr shallowCopy     (void) const;
    virtual FieldContainerTransitPtr shallowCopyLocal(
                                       BitVector bFlags = FCLocal::All) const;
    virtual FieldContainerTransitPtr shallowCopyDependent(
                                                      BitVector bFlags) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:
    /*---------------------------------------------------------------------*/
    /*! \name                    Produced Event Signals                   */
    /*! \{                                                                 */

    //Event Event producers
    MenuActionPerformedEventType _MenuActionPerformedEvent;
    /*! \}                                                                 */

    static TypeObject _type;

    static       void   classDescInserter(TypeObject &oType);
    static const Char8 *getClassname     (void             );

    /*---------------------------------------------------------------------*/
    /*! \name                      Fields                                  */
    /*! \{                                                                 */

    SFUnrecListModelPtr _sfModel;
    SFUnrecComponentGeneratorPtr _sfCellGenerator;
    SFUnrecListGeneratedPopupMenuPtr _sfMenuButtonPopupMenu;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    MenuButtonBase(void);
    MenuButtonBase(const MenuButtonBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~MenuButtonBase(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
    /*! \{                                                                 */

    void onCreate(const MenuButton *source = NULL);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Generic Field Access                      */
    /*! \{                                                                 */

    GetFieldHandlePtr  getHandleModel           (void) const;
    EditFieldHandlePtr editHandleModel          (void);
    GetFieldHandlePtr  getHandleCellGenerator   (void) const;
    EditFieldHandlePtr editHandleCellGenerator  (void);
    GetFieldHandlePtr  getHandleMenuButtonPopupMenu (void) const;
    EditFieldHandlePtr editHandleMenuButtonPopupMenu(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Generic Event Access                     */
    /*! \{                                                                 */

    GetEventHandlePtr getHandleMenuActionPerformedSignal(void) const;
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Get                                 */
    /*! \{                                                                 */

            const SFUnrecListGeneratedPopupMenuPtr *getSFMenuButtonPopupMenu (void) const;
                  SFUnrecListGeneratedPopupMenuPtr *editSFMenuButtonPopupMenu(void);


                  ListGeneratedPopupMenu * getMenuButtonPopupMenu(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

            void setMenuButtonPopupMenu(ListGeneratedPopupMenu * const value);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr MField Set                                */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Event Producer Firing                    */
    /*! \{                                                                 */

    virtual void produceEvent       (UInt32 eventId, EventDetails* const e);
    
    void produceMenuActionPerformed  (MenuActionPerformedEventDetailsType* const e);
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#ifdef OSG_MT_CPTR_ASPECT
    virtual void execSyncV(      FieldContainer    &oFrom,
                                 ConstFieldMaskArg  whichField,
                                 AspectOffsetStore &oOffsets,
                                 ConstFieldMaskArg  syncMode  ,
                           const UInt32             uiSyncInfo);

            void execSync (      MenuButtonBase *pFrom,
                                 ConstFieldMaskArg  whichField,
                                 AspectOffsetStore &oOffsets,
                                 ConstFieldMaskArg  syncMode  ,
                           const UInt32             uiSyncInfo);
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Edit                                   */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Aspect Create                            */
    /*! \{                                                                 */

#ifdef OSG_MT_CPTR_ASPECT
    virtual FieldContainer *createAspectCopy(
                                    const FieldContainer *pRefAspect) const;
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Edit                                   */
    /*! \{                                                                 */
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

    virtual void resolveLinks(void);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:
    /*---------------------------------------------------------------------*/
    static EventDescription   *_eventDesc[];
    static EventProducerType _producerType;


    // prohibit default functions (move to 'public' if you need one)
    void operator =(const MenuButtonBase &source);
};

typedef MenuButtonBase *MenuButtonBaseP;

OSG_END_NAMESPACE

#endif /* _OSGMENUBUTTONBASE_H_ */
