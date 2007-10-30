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
 **     class RadioButton
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGRADIOBUTTONBASE_H_
#define _OSGRADIOBUTTONBASE_H_
#ifdef __sgi
#pragma once
#endif


#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"

#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGRefPtr.h>
#include <OpenSG/OSGCoredNodePtr.h>

#include "OSGToggleButton.h" // Parent

#include "Component/Misc/OSGUIDrawObjectCanvas.h" // RadioDrawObject type
#include "Component/Misc/OSGUIDrawObjectCanvas.h" // SelectedRadioDrawObject type
#include "Component/Misc/OSGUIDrawObjectCanvas.h" // ActiveRadioDrawObject type
#include "Component/Misc/OSGUIDrawObjectCanvas.h" // ActiveSelectedRadioDrawObject type
#include "Component/Misc/OSGUIDrawObjectCanvas.h" // RolloverRadioDrawObject type
#include "Component/Misc/OSGUIDrawObjectCanvas.h" // RolloverSelectedRadioDrawObject type
#include "Component/Misc/OSGUIDrawObjectCanvas.h" // DisabledRadioDrawObject type
#include "Component/Misc/OSGUIDrawObjectCanvas.h" // DisabledSelectedRadioDrawObject type

#include "OSGRadioButtonFields.h"

OSG_BEGIN_NAMESPACE

class RadioButton;
class BinaryDataHandler;

//! \brief RadioButton Base Class.

class OSG_USERINTERFACELIB_DLLMAPPING RadioButtonBase : public ToggleButton
{
  private:

    typedef ToggleButton    Inherited;

    /*==========================  PUBLIC  =================================*/
  public:

    typedef RadioButtonPtr  Ptr;

    enum
    {
        RadioDrawObjectFieldId                 = Inherited::NextFieldId,
        SelectedRadioDrawObjectFieldId         = RadioDrawObjectFieldId                 + 1,
        ActiveRadioDrawObjectFieldId           = SelectedRadioDrawObjectFieldId         + 1,
        ActiveSelectedRadioDrawObjectFieldId   = ActiveRadioDrawObjectFieldId           + 1,
        RolloverRadioDrawObjectFieldId         = ActiveSelectedRadioDrawObjectFieldId   + 1,
        RolloverSelectedRadioDrawObjectFieldId = RolloverRadioDrawObjectFieldId         + 1,
        DisabledRadioDrawObjectFieldId         = RolloverSelectedRadioDrawObjectFieldId + 1,
        DisabledSelectedRadioDrawObjectFieldId = DisabledRadioDrawObjectFieldId         + 1,
        NextFieldId                            = DisabledSelectedRadioDrawObjectFieldId + 1
    };

    static const OSG::BitVector RadioDrawObjectFieldMask;
    static const OSG::BitVector SelectedRadioDrawObjectFieldMask;
    static const OSG::BitVector ActiveRadioDrawObjectFieldMask;
    static const OSG::BitVector ActiveSelectedRadioDrawObjectFieldMask;
    static const OSG::BitVector RolloverRadioDrawObjectFieldMask;
    static const OSG::BitVector RolloverSelectedRadioDrawObjectFieldMask;
    static const OSG::BitVector DisabledRadioDrawObjectFieldMask;
    static const OSG::BitVector DisabledSelectedRadioDrawObjectFieldMask;


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

           SFUIDrawObjectCanvasPtr *getSFRadioDrawObject(void);
           SFUIDrawObjectCanvasPtr *getSFSelectedRadioDrawObject(void);
           SFUIDrawObjectCanvasPtr *getSFActiveRadioDrawObject(void);
           SFUIDrawObjectCanvasPtr *getSFActiveSelectedRadioDrawObject(void);
           SFUIDrawObjectCanvasPtr *getSFRolloverRadioDrawObject(void);
           SFUIDrawObjectCanvasPtr *getSFRolloverSelectedRadioDrawObject(void);
           SFUIDrawObjectCanvasPtr *getSFDisabledRadioDrawObject(void);
           SFUIDrawObjectCanvasPtr *getSFDisabledSelectedRadioDrawObject(void);

           UIDrawObjectCanvasPtr &getRadioDrawObject(void);
     const UIDrawObjectCanvasPtr &getRadioDrawObject(void) const;
           UIDrawObjectCanvasPtr &getSelectedRadioDrawObject(void);
     const UIDrawObjectCanvasPtr &getSelectedRadioDrawObject(void) const;
           UIDrawObjectCanvasPtr &getActiveRadioDrawObject(void);
     const UIDrawObjectCanvasPtr &getActiveRadioDrawObject(void) const;
           UIDrawObjectCanvasPtr &getActiveSelectedRadioDrawObject(void);
     const UIDrawObjectCanvasPtr &getActiveSelectedRadioDrawObject(void) const;
           UIDrawObjectCanvasPtr &getRolloverRadioDrawObject(void);
     const UIDrawObjectCanvasPtr &getRolloverRadioDrawObject(void) const;
           UIDrawObjectCanvasPtr &getRolloverSelectedRadioDrawObject(void);
     const UIDrawObjectCanvasPtr &getRolloverSelectedRadioDrawObject(void) const;
           UIDrawObjectCanvasPtr &getDisabledRadioDrawObject(void);
     const UIDrawObjectCanvasPtr &getDisabledRadioDrawObject(void) const;
           UIDrawObjectCanvasPtr &getDisabledSelectedRadioDrawObject(void);
     const UIDrawObjectCanvasPtr &getDisabledSelectedRadioDrawObject(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

     void setRadioDrawObject( const UIDrawObjectCanvasPtr &value );
     void setSelectedRadioDrawObject( const UIDrawObjectCanvasPtr &value );
     void setActiveRadioDrawObject( const UIDrawObjectCanvasPtr &value );
     void setActiveSelectedRadioDrawObject( const UIDrawObjectCanvasPtr &value );
     void setRolloverRadioDrawObject( const UIDrawObjectCanvasPtr &value );
     void setRolloverSelectedRadioDrawObject( const UIDrawObjectCanvasPtr &value );
     void setDisabledRadioDrawObject( const UIDrawObjectCanvasPtr &value );
     void setDisabledSelectedRadioDrawObject( const UIDrawObjectCanvasPtr &value );

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

    static  RadioButtonPtr      create          (void); 
    static  RadioButtonPtr      createEmpty     (void); 

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

    SFUIDrawObjectCanvasPtr   _sfRadioDrawObject;
    SFUIDrawObjectCanvasPtr   _sfSelectedRadioDrawObject;
    SFUIDrawObjectCanvasPtr   _sfActiveRadioDrawObject;
    SFUIDrawObjectCanvasPtr   _sfActiveSelectedRadioDrawObject;
    SFUIDrawObjectCanvasPtr   _sfRolloverRadioDrawObject;
    SFUIDrawObjectCanvasPtr   _sfRolloverSelectedRadioDrawObject;
    SFUIDrawObjectCanvasPtr   _sfDisabledRadioDrawObject;
    SFUIDrawObjectCanvasPtr   _sfDisabledSelectedRadioDrawObject;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    RadioButtonBase(void);
    RadioButtonBase(const RadioButtonBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~RadioButtonBase(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#if !defined(OSG_FIXED_MFIELDSYNC)
    void executeSyncImpl(      RadioButtonBase *pOther,
                         const BitVector         &whichField);

    virtual void   executeSync(      FieldContainer    &other,
                               const BitVector         &whichField);
#else
    void executeSyncImpl(      RadioButtonBase *pOther,
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
    void operator =(const RadioButtonBase &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------


typedef RadioButtonBase *RadioButtonBaseP;

typedef osgIF<RadioButtonBase::isNodeCore,
              CoredNodePtr<RadioButton>,
              FieldContainer::attempt_to_create_CoredNodePtr_on_non_NodeCore_FC
              >::_IRet RadioButtonNodePtr;

typedef RefPtr<RadioButtonPtr> RadioButtonRefPtr;

OSG_END_NAMESPACE

#define OSGRADIOBUTTONBASE_HEADER_CVSID "@(#)$Id: FCBaseTemplate_h.h,v 1.40 2005/07/20 00:10:14 vossg Exp $"

#endif /* _OSGRADIOBUTTONBASE_H_ */
