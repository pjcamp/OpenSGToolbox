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
 **     class MouseEvent
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGMOUSEEVENTBASE_H_
#define _OSGMOUSEEVENTBASE_H_
#ifdef __sgi
#pragma once
#endif


#include <OpenSG/OSGConfig.h>
#include "OSGInputDef.h"

#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGRefPtr.h>
#include <OpenSG/OSGCoredNodePtr.h>

#include "OSGInputEvent.h" // Parent

#include <OpenSG/OSGUInt16Fields.h> // Button type
#include <OpenSG/OSGUInt16Fields.h> // ClickCount type
#include <OpenSG/OSGPnt2fFields.h> // Location type
#include <OpenSG/OSGVec2fFields.h> // Delta type
#include <OpenSG/OSGViewportFields.h> // Viewport type

#include "OSGMouseEventFields.h"

OSG_BEGIN_NAMESPACE

class MouseEvent;
class BinaryDataHandler;

//! \brief MouseEvent Base Class.

class OSG_INPUTLIB_DLLMAPPING MouseEventBase : public InputEvent
{
  private:

    typedef InputEvent    Inherited;

    /*==========================  PUBLIC  =================================*/
  public:

    typedef MouseEventPtr  Ptr;

    enum
    {
        ButtonFieldId     = Inherited::NextFieldId,
        ClickCountFieldId = ButtonFieldId     + 1,
        LocationFieldId   = ClickCountFieldId + 1,
        DeltaFieldId      = LocationFieldId   + 1,
        ViewportFieldId   = DeltaFieldId      + 1,
        NextFieldId       = ViewportFieldId   + 1
    };

    static const OSG::BitVector ButtonFieldMask;
    static const OSG::BitVector ClickCountFieldMask;
    static const OSG::BitVector LocationFieldMask;
    static const OSG::BitVector DeltaFieldMask;
    static const OSG::BitVector ViewportFieldMask;


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

     const SFUInt16            *getSFButton         (void) const;
     const SFUInt16            *getSFClickCount     (void) const;
     const SFPnt2f             *getSFLocation       (void) const;
     const SFVec2f             *getSFDelta          (void) const;
     const SFViewportPtr       *getSFViewport       (void) const;


     const UInt16              &getButton         (void) const;

     const UInt16              &getClickCount     (void) const;

     const Pnt2f               &getLocation       (void) const;

     const Vec2f               &getDelta          (void) const;

     const ViewportPtr         &getViewport       (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */


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

    static  MouseEventPtr      create          (void); 
    static  MouseEventPtr      createEmpty     (void); 

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

    SFUInt16            _sfButton;
    SFUInt16            _sfClickCount;
    SFPnt2f             _sfLocation;
    SFVec2f             _sfDelta;
    SFViewportPtr       _sfViewport;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    MouseEventBase(void);
    MouseEventBase(const MouseEventBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~MouseEventBase(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Get                                 */
    /*! \{                                                                 */

           SFUInt16            *editSFButton         (void);
           SFUInt16            *editSFClickCount     (void);
           SFPnt2f             *editSFLocation       (void);
           SFVec2f             *editSFDelta          (void);
           SFViewportPtr       *editSFViewport       (void);

           UInt16              &editButton         (void);
           UInt16              &editClickCount     (void);
           Pnt2f               &editLocation       (void);
           Vec2f               &editDelta          (void);
           ViewportPtr         &editViewport       (void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

     void setButton         (const UInt16 &value);
     void setClickCount     (const UInt16 &value);
     void setLocation       (const Pnt2f &value);
     void setDelta          (const Vec2f &value);
     void setViewport       (const ViewportPtr &value);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#if !defined(OSG_FIXED_MFIELDSYNC)
    void executeSyncImpl(      MouseEventBase *pOther,
                         const BitVector         &whichField);

    virtual void   executeSync(      FieldContainer    &other,
                               const BitVector         &whichField);
#else
    void executeSyncImpl(      MouseEventBase *pOther,
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
    void operator =(const MouseEventBase &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------


typedef MouseEventBase *MouseEventBaseP;

typedef osgIF<MouseEventBase::isNodeCore,
              CoredNodePtr<MouseEvent>,
              FieldContainer::attempt_to_create_CoredNodePtr_on_non_NodeCore_FC
              >::_IRet MouseEventNodePtr;

typedef RefPtr<MouseEventPtr> MouseEventRefPtr;

OSG_END_NAMESPACE

#endif /* _OSGMOUSEEVENTBASE_H_ */
