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
 **     class AbstractTreeModelLayout
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGABSTRACTTREEMODELLAYOUTBASE_H_
#define _OSGABSTRACTTREEMODELLAYOUTBASE_H_
#ifdef __sgi
#pragma once
#endif


#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"

#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGRefPtr.h>
#include <OpenSG/OSGCoredNodePtr.h>

#include "OSGTreeModelLayout.h" // Parent

#include <OpenSG/OSGBoolFields.h> // RootVisibleInternal type
#include <OpenSG/OSGReal32Fields.h> // RowHeightInternal type
#include <OpenSG/OSGReal32Fields.h> // DepthOffsetInternal type

#include "OSGAbstractTreeModelLayoutFields.h"

OSG_BEGIN_NAMESPACE

class AbstractTreeModelLayout;
class BinaryDataHandler;

//! \brief AbstractTreeModelLayout Base Class.

class OSG_USERINTERFACELIB_DLLMAPPING AbstractTreeModelLayoutBase : public TreeModelLayout
{
  private:

    typedef TreeModelLayout    Inherited;

    /*==========================  PUBLIC  =================================*/
  public:

    typedef AbstractTreeModelLayoutPtr  Ptr;

    enum
    {
        RootVisibleInternalFieldId = Inherited::NextFieldId,
        RowHeightInternalFieldId   = RootVisibleInternalFieldId + 1,
        DepthOffsetInternalFieldId = RowHeightInternalFieldId   + 1,
        NextFieldId                = DepthOffsetInternalFieldId + 1
    };

    static const OSG::BitVector RootVisibleInternalFieldMask;
    static const OSG::BitVector RowHeightInternalFieldMask;
    static const OSG::BitVector DepthOffsetInternalFieldMask;


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
    /*=========================  PROTECTED  ===============================*/
  protected:

    /*---------------------------------------------------------------------*/
    /*! \name                      Fields                                  */
    /*! \{                                                                 */

    SFBool              _sfRootVisibleInternal;
    SFReal32            _sfRowHeightInternal;
    SFReal32            _sfDepthOffsetInternal;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    AbstractTreeModelLayoutBase(void);
    AbstractTreeModelLayoutBase(const AbstractTreeModelLayoutBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~AbstractTreeModelLayoutBase(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Get                                 */
    /*! \{                                                                 */

           SFBool              *getSFRootVisibleInternal(void);
           SFReal32            *getSFRowHeightInternal(void);
           SFReal32            *getSFDepthOffsetInternal(void);

           bool                &getRootVisibleInternal(void);
     const bool                &getRootVisibleInternal(void) const;
           Real32              &getRowHeightInternal(void);
     const Real32              &getRowHeightInternal(void) const;
           Real32              &getDepthOffsetInternal(void);
     const Real32              &getDepthOffsetInternal(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

     void setRootVisibleInternal(const bool &value);
     void setRowHeightInternal(const Real32 &value);
     void setDepthOffsetInternal(const Real32 &value);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#if !defined(OSG_FIXED_MFIELDSYNC)
    void executeSyncImpl(      AbstractTreeModelLayoutBase *pOther,
                         const BitVector         &whichField);

    virtual void   executeSync(      FieldContainer    &other,
                               const BitVector         &whichField);
#else
    void executeSyncImpl(      AbstractTreeModelLayoutBase *pOther,
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
    void operator =(const AbstractTreeModelLayoutBase &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------


typedef AbstractTreeModelLayoutBase *AbstractTreeModelLayoutBaseP;

typedef osgIF<AbstractTreeModelLayoutBase::isNodeCore,
              CoredNodePtr<AbstractTreeModelLayout>,
              FieldContainer::attempt_to_create_CoredNodePtr_on_non_NodeCore_FC
              >::_IRet AbstractTreeModelLayoutNodePtr;

typedef RefPtr<AbstractTreeModelLayoutPtr> AbstractTreeModelLayoutRefPtr;

OSG_END_NAMESPACE

#define OSGABSTRACTTREEMODELLAYOUTBASE_HEADER_CVSID "@(#)$Id: FCBaseTemplate_h.h,v 1.40 2005/07/20 00:10:14 vossg Exp $"

#endif /* _OSGABSTRACTTREEMODELLAYOUTBASE_H_ */
