/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2002 by the OpenSG Forum                 *
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
 **     class GridBagLayout
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGGRIDBAGLAYOUTBASE_H_
#define _OSGGRIDBAGLAYOUTBASE_H_
#ifdef __sgi
#pragma once
#endif


#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"

#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGRefPtr.h>
#include <OpenSG/OSGCoredNodePtr.h>

#include "OSGLayout.h" // Parent

#include <OpenSG/OSGReal32Fields.h> // ColumnWeights type
#include <OpenSG/OSGUInt16Fields.h> // ColumnHeights type
#include <OpenSG/OSGReal32Fields.h> // RowWeights type
#include <OpenSG/OSGUInt16Fields.h> // RowWidths type

#include "OSGGridBagLayoutFields.h"

OSG_BEGIN_NAMESPACE

class GridBagLayout;
class BinaryDataHandler;

//! \brief GridBagLayout Base Class.

class OSG_USERINTERFACELIB_DLLMAPPING GridBagLayoutBase : public Layout
{
  private:

    typedef Layout    Inherited;

    /*==========================  PUBLIC  =================================*/
  public:

    typedef GridBagLayoutPtr  Ptr;

    enum
    {
        ColumnWeightsFieldId = Inherited::NextFieldId,
        ColumnHeightsFieldId = ColumnWeightsFieldId + 1,
        RowWeightsFieldId    = ColumnHeightsFieldId + 1,
        RowWidthsFieldId     = RowWeightsFieldId    + 1,
        NextFieldId          = RowWidthsFieldId     + 1
    };

    static const OSG::BitVector ColumnWeightsFieldMask;
    static const OSG::BitVector ColumnHeightsFieldMask;
    static const OSG::BitVector RowWeightsFieldMask;
    static const OSG::BitVector RowWidthsFieldMask;


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

           MFReal32            *getMFColumnWeights  (void);
           MFUInt16            *getMFColumnHeights  (void);
           MFReal32            *getMFRowWeights     (void);
           MFUInt16            *getMFRowWidths      (void);

           Real32              &getColumnWeights  (const UInt32 index);
           MFReal32            &getColumnWeights  (void);
     const MFReal32            &getColumnWeights  (void) const;
           UInt16              &getColumnHeights  (const UInt32 index);
           MFUInt16            &getColumnHeights  (void);
     const MFUInt16            &getColumnHeights  (void) const;
           Real32              &getRowWeights     (const UInt32 index);
           MFReal32            &getRowWeights     (void);
     const MFReal32            &getRowWeights     (void) const;
           UInt16              &getRowWidths      (const UInt32 index);
           MFUInt16            &getRowWidths      (void);
     const MFUInt16            &getRowWidths      (void) const;

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

    static  GridBagLayoutPtr      create          (void); 
    static  GridBagLayoutPtr      createEmpty     (void); 

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

    MFReal32            _mfColumnWeights;
    MFUInt16            _mfColumnHeights;
    MFReal32            _mfRowWeights;
    MFUInt16            _mfRowWidths;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    GridBagLayoutBase(void);
    GridBagLayoutBase(const GridBagLayoutBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~GridBagLayoutBase(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#if !defined(OSG_FIXED_MFIELDSYNC)
    void executeSyncImpl(      GridBagLayoutBase *pOther,
                         const BitVector         &whichField);

    virtual void   executeSync(      FieldContainer    &other,
                               const BitVector         &whichField);
#else
    void executeSyncImpl(      GridBagLayoutBase *pOther,
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
    void operator =(const GridBagLayoutBase &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------


typedef GridBagLayoutBase *GridBagLayoutBaseP;

typedef osgIF<GridBagLayoutBase::isNodeCore,
              CoredNodePtr<GridBagLayout>,
              FieldContainer::attempt_to_create_CoredNodePtr_on_non_NodeCore_FC
              >::_IRet GridBagLayoutNodePtr;

typedef RefPtr<GridBagLayoutPtr> GridBagLayoutRefPtr;

OSG_END_NAMESPACE

#define OSGGRIDBAGLAYOUTBASE_HEADER_CVSID "@(#)$Id: FCBaseTemplate_h.h,v 1.40 2005/07/20 00:10:14 vossg Exp $"

#endif /* _OSGGRIDBAGLAYOUTBASE_H_ */
