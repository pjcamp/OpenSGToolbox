/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
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
 **     class WindowEventProducer
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGWINDOWEVENTPRODUCERBASE_H_
#define _OSGWINDOWEVENTPRODUCERBASE_H_
#ifdef __sgi
#pragma once
#endif


#include "OSGConfig.h"
#include "OSGSystemDef.h"

//#include "OSGBaseTypes.h"

#include "OSGWindow.h" // Parent

#include "OSGSysFields.h"               // Enabled type
#include "OSGBaseFields.h"              // LastUpdateTime type

#include "OSGWindowEventProducerFields.h"

//Event Producer Headers
#include "OSGEventProducer.h"
#include "OSGEventProducerType.h"
#include "OSGMethodDescription.h"
#include "OSGEventProducerPtrType.h"


OSG_BEGIN_NAMESPACE

class WindowEventProducer;

//! \brief WindowEventProducer Base Class.

class OSG_SYSTEM_DLLMAPPING WindowEventProducerBase : public Window
{
  public:

    typedef Window Inherited;
    typedef Window ParentContainer;

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    OSG_GEN_INTERNALPTR(WindowEventProducer);

    /*==========================  PUBLIC  =================================*/

  public:

    enum
    {
        EnabledFieldId = Inherited::NextFieldId,
        UseCallbackForDrawFieldId = EnabledFieldId + 1,
        UseCallbackForReshapeFieldId = UseCallbackForDrawFieldId + 1,
        LastUpdateTimeFieldId = UseCallbackForReshapeFieldId + 1,
        LockCursorFieldId = LastUpdateTimeFieldId + 1,
        EventProducerFieldId = LockCursorFieldId + 1,
        NextFieldId = EventProducerFieldId + 1
    };

    static const OSG::BitVector EnabledFieldMask =
        (TypeTraits<BitVector>::One << EnabledFieldId);
    static const OSG::BitVector UseCallbackForDrawFieldMask =
        (TypeTraits<BitVector>::One << UseCallbackForDrawFieldId);
    static const OSG::BitVector UseCallbackForReshapeFieldMask =
        (TypeTraits<BitVector>::One << UseCallbackForReshapeFieldId);
    static const OSG::BitVector LastUpdateTimeFieldMask =
        (TypeTraits<BitVector>::One << LastUpdateTimeFieldId);
    static const OSG::BitVector LockCursorFieldMask =
        (TypeTraits<BitVector>::One << LockCursorFieldId);
    static const OSG::BitVector EventProducerFieldMask =
        (TypeTraits<BitVector>::One << EventProducerFieldId);
    static const OSG::BitVector NextFieldMask =
        (TypeTraits<BitVector>::One << NextFieldId);
        
    typedef SFBool            SFEnabledType;
    typedef SFBool            SFUseCallbackForDrawType;
    typedef SFBool            SFUseCallbackForReshapeType;
    typedef SFTime            SFLastUpdateTimeType;
    typedef SFBool            SFLockCursorType;
    typedef SFEventProducerPtr          SFEventProducerType;

    enum
    {
        WindowOpenedMethodId = 1,
        WindowClosingMethodId = WindowOpenedMethodId + 1,
        WindowClosedMethodId = WindowClosingMethodId + 1,
        WindowIconifiedMethodId = WindowClosedMethodId + 1,
        WindowDeiconifiedMethodId = WindowIconifiedMethodId + 1,
        WindowActivatedMethodId = WindowDeiconifiedMethodId + 1,
        WindowDeactivatedMethodId = WindowActivatedMethodId + 1,
        WindowEnteredMethodId = WindowDeactivatedMethodId + 1,
        WindowExitedMethodId = WindowEnteredMethodId + 1,
        MouseClickedMethodId = WindowExitedMethodId + 1,
        MouseEnteredMethodId = MouseClickedMethodId + 1,
        MouseExitedMethodId = MouseEnteredMethodId + 1,
        MousePressedMethodId = MouseExitedMethodId + 1,
        MouseReleasedMethodId = MousePressedMethodId + 1,
        MouseMovedMethodId = MouseReleasedMethodId + 1,
        MouseDraggedMethodId = MouseMovedMethodId + 1,
        MouseWheelMovedMethodId = MouseDraggedMethodId + 1,
        KeyPressedMethodId = MouseWheelMovedMethodId + 1,
        KeyReleasedMethodId = KeyPressedMethodId + 1,
        KeyTypedMethodId = KeyReleasedMethodId + 1,
        UpdateMethodId = KeyTypedMethodId + 1,
        NextProducedMethodId = UpdateMethodId + 1
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


                  SFBool              *editSFEnabled        (void);
            const SFBool              *getSFEnabled         (void) const;

                  SFBool              *editSFUseCallbackForDraw(void);
            const SFBool              *getSFUseCallbackForDraw (void) const;

                  SFBool              *editSFUseCallbackForReshape(void);
            const SFBool              *getSFUseCallbackForReshape (void) const;

                  SFTime              *editSFLastUpdateTime (void);
            const SFTime              *getSFLastUpdateTime  (void) const;

                  SFBool              *editSFLockCursor     (void);
            const SFBool              *getSFLockCursor      (void) const;


                  bool                &editEnabled        (void);
                  bool                 getEnabled         (void) const;

                  bool                &editUseCallbackForDraw(void);
                  bool                 getUseCallbackForDraw (void) const;

                  bool                &editUseCallbackForReshape(void);
                  bool                 getUseCallbackForReshape (void) const;

                  Time                &editLastUpdateTime (void);
            const Time                &getLastUpdateTime  (void) const;

                  bool                &editLockCursor     (void);
                  bool                 getLockCursor      (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

            void setEnabled        (const bool value);
            void setUseCallbackForDraw(const bool value);
            void setUseCallbackForReshape(const bool value);
            void setLastUpdateTime (const Time &value);
            void setLockCursor     (const bool value);

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
    /*! \name                Method Produced Get                           */
    /*! \{                                                                 */

    virtual const EventProducerType &getProducerType(void) const; 

    EventConnection          attachActivity             (ActivityRefPtr TheActivity,
                                                         UInt32 ProducedEventId);
    bool                     isActivityAttached         (ActivityRefPtr TheActivity,
                                                         UInt32 ProducedEventId) const;
    UInt32                   getNumActivitiesAttached   (UInt32 ProducedEventId) const;
    ActivityRefPtr           getAttachedActivity        (UInt32 ProducedEventId,
                                                         UInt32 ActivityIndex) const;
    void                     detachActivity             (ActivityRefPtr TheActivity,
                                                         UInt32 ProducedEventId);
    UInt32                   getNumProducedEvents       (void) const;
    const MethodDescription *getProducedEventDescription(const std::string &ProducedEventName) const;
    const MethodDescription *getProducedEventDescription(UInt32 ProducedEventId) const;
    UInt32                   getProducedEventId         (const std::string &ProducedEventName) const;

    SFEventProducerPtr *editSFEventProducer(void);
    EventProducerPtr   &editEventProducer  (void);

    /*! \}                                                                 */

    /*=========================  PROTECTED  ===============================*/

  protected:
    /*---------------------------------------------------------------------*/
    /*! \name                    Event Producer                            */
    /*! \{                                                                 */
    EventProducer _Producer;

    /*! \}                                                                 */

    static TypeObject _type;

    static       void   classDescInserter(TypeObject &oType);
    static const Char8 *getClassname     (void             );

    /*---------------------------------------------------------------------*/
    /*! \name                      Fields                                  */
    /*! \{                                                                 */

    SFBool            _sfEnabled;
    SFBool            _sfUseCallbackForDraw;
    SFBool            _sfUseCallbackForReshape;
    SFTime            _sfLastUpdateTime;
    SFBool            _sfLockCursor;
    SFEventProducerPtr _sfEventProducer;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    WindowEventProducerBase(void);
    WindowEventProducerBase(const WindowEventProducerBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~WindowEventProducerBase(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
    /*! \{                                                                 */


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Generic Field Access                      */
    /*! \{                                                                 */

    GetFieldHandlePtr  getHandleEnabled         (void) const;
    EditFieldHandlePtr editHandleEnabled        (void);
    GetFieldHandlePtr  getHandleUseCallbackForDraw (void) const;
    EditFieldHandlePtr editHandleUseCallbackForDraw(void);
    GetFieldHandlePtr  getHandleUseCallbackForReshape (void) const;
    EditFieldHandlePtr editHandleUseCallbackForReshape(void);
    GetFieldHandlePtr  getHandleLastUpdateTime  (void) const;
    EditFieldHandlePtr editHandleLastUpdateTime (void);
    GetFieldHandlePtr  getHandleLockCursor      (void) const;
    EditFieldHandlePtr editHandleLockCursor     (void);

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

            void execSync (      WindowEventProducerBase *pFrom,
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
    static MethodDescription   *_methodDesc[];
    static EventProducerType _producerType;


    // prohibit default functions (move to 'public' if you need one)
    void operator =(const WindowEventProducerBase &source);
};

typedef WindowEventProducerBase *WindowEventProducerBaseP;

OSG_END_NAMESPACE

#endif /* _OSGWINDOWEVENTPRODUCERBASE_H_ */
