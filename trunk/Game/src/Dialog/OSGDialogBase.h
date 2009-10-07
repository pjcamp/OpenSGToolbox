/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                         www.vrac.iastate.edu                              *
 *                                                                           *
 *                          Authors: David Kabala                            *
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
 **     class Dialog
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGDIALOGBASE_H_
#define _OSGDIALOGBASE_H_
#ifdef __sgi
#pragma once
#endif


#include <OpenSG/OSGConfig.h>
#include "OSGGameDef.h"

#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGRefPtr.h>
#include <OpenSG/OSGCoredNodePtr.h>

#include <OpenSG/OSGAttachmentContainer.h> // Parent

#include <OpenSG/OSGStringFields.h> // Response type
#include <OpenSG/OSGReal32Fields.h> // ResponsePresentationDelay type
#include <OpenSG/OSGBoolFields.h> // Interactive type
#include "Dialog/OSGDialogFields.h" // Responses type
#include <OpenSG/Sound/OSGSoundFields.h> // DialogSound type
#include "Dialog/OSGDialogHierarchyFields.h" // ParentDialogHierarchy type

#include "OSGDialogFields.h"
#include <OpenSG/Toolbox/OSGEventProducer.h>
#include <OpenSG/Toolbox/OSGEventProducerType.h>
#include <OpenSG/Toolbox/OSGMethodDescription.h>

OSG_BEGIN_NAMESPACE

class Dialog;
class BinaryDataHandler;

//! \brief Dialog Base Class.

class OSG_GAMELIB_DLLMAPPING DialogBase : public AttachmentContainer, public EventProducer
{
  private:

    typedef AttachmentContainer    Inherited;
    typedef EventProducer    ProducerInherited;

    /*==========================  PUBLIC  =================================*/
  public:

    typedef DialogPtr  Ptr;

    enum
    {
        ResponseFieldId                  = Inherited::NextFieldId,
        ResponsePresentationDelayFieldId = ResponseFieldId                  + 1,
        InteractiveFieldId               = ResponsePresentationDelayFieldId + 1,
        ResponsesFieldId                 = InteractiveFieldId               + 1,
        DialogSoundFieldId               = ResponsesFieldId                 + 1,
        ParentDialogHierarchyFieldId     = DialogSoundFieldId               + 1,
        NextFieldId                      = ParentDialogHierarchyFieldId     + 1
    };

    static const OSG::BitVector ResponseFieldMask;
    static const OSG::BitVector ResponsePresentationDelayFieldMask;
    static const OSG::BitVector InteractiveFieldMask;
    static const OSG::BitVector ResponsesFieldMask;
    static const OSG::BitVector DialogSoundFieldMask;
    static const OSG::BitVector ParentDialogHierarchyFieldMask;


    enum
    {
        StartedMethodId          = ProducerInherited::NextMethodId,
        EndedMethodId            = StartedMethodId          + 1,
        ResponseSelectedMethodId = EndedMethodId            + 1,
        ResponsesReadyMethodId   = ResponseSelectedMethodId + 1,
        TerminatedMethodId       = ResponsesReadyMethodId   + 1,
        NextMethodId             = TerminatedMethodId       + 1
    };



    static const OSG::BitVector MTInfluenceMask;

    /*---------------------------------------------------------------------*/
    /*! \name                    Class Get                                 */
    /*! \{                                                                 */

    static        FieldContainerType &getClassType    (void); 
    static        UInt32              getClassTypeId  (void); 
    static const  EventProducerType  &getProducerClassType  (void); 
    static        UInt32              getProducerClassTypeId(void); 

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


           SFString            *editSFResponse       (void);
     const SFString            *getSFResponse       (void) const;

           SFReal32            *editSFResponsePresentationDelay(void);
     const SFReal32            *getSFResponsePresentationDelay(void) const;

           SFBool              *editSFInteractive    (void);
     const SFBool              *getSFInteractive    (void) const;

           MFDialogPtr         *editMFResponses      (void);
     const MFDialogPtr         *getMFResponses      (void) const;

           SFSoundPtr          *editSFDialogSound    (void);
     const SFSoundPtr          *getSFDialogSound    (void) const;

           SFDialogHierarchyPtr *editSFParentDialogHierarchy(void);
     const SFDialogHierarchyPtr *getSFParentDialogHierarchy(void) const;


           std::string         &editResponse       (void);
     const std::string         &getResponse       (void) const;

           Real32              &editResponsePresentationDelay(void);
     const Real32              &getResponsePresentationDelay(void) const;

           bool                &editInteractive    (void);
     const bool                &getInteractive    (void) const;

           SoundPtr            &editDialogSound    (void);
     const SoundPtr            &getDialogSound    (void) const;

           DialogHierarchyPtr  &editParentDialogHierarchy(void);
     const DialogHierarchyPtr  &getParentDialogHierarchy(void) const;

           DialogPtr           &editResponses      (const UInt32 index);
     const DialogPtr           &getResponses      (const UInt32 index) const;
#ifndef OSG_2_PREP
           MFDialogPtr         &getResponses      (void);
     const MFDialogPtr         &getResponses      (void) const;
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

     void setResponse       ( const std::string &value );
     void setResponsePresentationDelay( const Real32 &value );
     void setInteractive    ( const bool &value );
     void setDialogSound    ( const SoundPtr &value );
     void setParentDialogHierarchy( const DialogHierarchyPtr &value );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Method Produced Get                           */
    /*! \{                                                                 */

    virtual const EventProducerType &getProducerType(void) const; 

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

    static  DialogPtr      create          (void); 
    static  DialogPtr      createEmpty     (void); 

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

    SFString            _sfResponse;
    SFReal32            _sfResponsePresentationDelay;
    SFBool              _sfInteractive;
    MFDialogPtr         _mfResponses;
    SFSoundPtr          _sfDialogSound;
    SFDialogHierarchyPtr   _sfParentDialogHierarchy;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    DialogBase(void);
    DialogBase(const DialogBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~DialogBase(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#if !defined(OSG_FIXED_MFIELDSYNC)
    void executeSyncImpl(      DialogBase *pOther,
                         const BitVector         &whichField);

    virtual void   executeSync(      FieldContainer    &other,
                               const BitVector         &whichField);
#else
    void executeSyncImpl(      DialogBase *pOther,
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

    static MethodDescription   *_methodDesc[];
    static EventProducerType _producerType;

    static FieldDescription   *_desc[];
    static FieldContainerType  _type;


    // prohibit default functions (move to 'public' if you need one)
    void operator =(const DialogBase &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------


typedef DialogBase *DialogBaseP;

typedef osgIF<DialogBase::isNodeCore,
              CoredNodePtr<Dialog>,
              FieldContainer::attempt_to_create_CoredNodePtr_on_non_NodeCore_FC
              >::_IRet DialogNodePtr;

typedef RefPtr<DialogPtr> DialogRefPtr;

OSG_END_NAMESPACE

#endif /* _OSGDIALOGBASE_H_ */
