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
 **     class Table
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGTABLEBASE_H_
#define _OSGTABLEBASE_H_
#ifdef __sgi
#pragma once
#endif


#include "OSGConfig.h"
#include "OSGContribUserInterfaceDef.h"

//#include "OSGBaseTypes.h"

#include "OSGComponentContainer.h" // Parent

#include "OSGTableHeaderFields.h"       // Header type
#include "OSGTableModelFields.h"        // Model type
#include "OSGTableColumnModelFields.h"  // ColumnModel type
#include "OSGComponentFields.h"         // Table type
#include "OSGSysFields.h"               // AutoCreateColumnsFromModel type
#include "OSGBaseFields.h"              // GridColor type
#include "OSGCellEditorFields.h"        // GlobalCellEditor type
#include "OSGListSelectionModelFields.h" // RowSelectionModel type

#include "OSGTableFields.h"

OSG_BEGIN_NAMESPACE

class Table;

//! \brief Table Base Class.

class OSG_CONTRIBUSERINTERFACE_DLLMAPPING TableBase : public ComponentContainer
{
  public:

    typedef ComponentContainer Inherited;
    typedef ComponentContainer ParentContainer;

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    OSG_GEN_INTERNALPTR(Table);
    
    

    /*==========================  PUBLIC  =================================*/

  public:

    enum
    {
        HeaderFieldId = Inherited::NextFieldId,
        ModelFieldId = HeaderFieldId + 1,
        ColumnModelFieldId = ModelFieldId + 1,
        TableFieldId = ColumnModelFieldId + 1,
        AutoCreateColumnsFromModelFieldId = TableFieldId + 1,
        AutoResizeModeFieldId = AutoCreateColumnsFromModelFieldId + 1,
        RowHeightFieldId = AutoResizeModeFieldId + 1,
        RowMarginFieldId = RowHeightFieldId + 1,
        RowSelectionAllowedFieldId = RowMarginFieldId + 1,
        ShowHorizontalLinesFieldId = RowSelectionAllowedFieldId + 1,
        ShowVerticalLinesFieldId = ShowHorizontalLinesFieldId + 1,
        GridColorFieldId = ShowVerticalLinesFieldId + 1,
        GlobalCellEditorFieldId = GridColorFieldId + 1,
        RowSelectionModelFieldId = GlobalCellEditorFieldId + 1,
        NextFieldId = RowSelectionModelFieldId + 1
    };

    static const OSG::BitVector HeaderFieldMask =
        (TypeTraits<BitVector>::One << HeaderFieldId);
    static const OSG::BitVector ModelFieldMask =
        (TypeTraits<BitVector>::One << ModelFieldId);
    static const OSG::BitVector ColumnModelFieldMask =
        (TypeTraits<BitVector>::One << ColumnModelFieldId);
    static const OSG::BitVector TableFieldMask =
        (TypeTraits<BitVector>::One << TableFieldId);
    static const OSG::BitVector AutoCreateColumnsFromModelFieldMask =
        (TypeTraits<BitVector>::One << AutoCreateColumnsFromModelFieldId);
    static const OSG::BitVector AutoResizeModeFieldMask =
        (TypeTraits<BitVector>::One << AutoResizeModeFieldId);
    static const OSG::BitVector RowHeightFieldMask =
        (TypeTraits<BitVector>::One << RowHeightFieldId);
    static const OSG::BitVector RowMarginFieldMask =
        (TypeTraits<BitVector>::One << RowMarginFieldId);
    static const OSG::BitVector RowSelectionAllowedFieldMask =
        (TypeTraits<BitVector>::One << RowSelectionAllowedFieldId);
    static const OSG::BitVector ShowHorizontalLinesFieldMask =
        (TypeTraits<BitVector>::One << ShowHorizontalLinesFieldId);
    static const OSG::BitVector ShowVerticalLinesFieldMask =
        (TypeTraits<BitVector>::One << ShowVerticalLinesFieldId);
    static const OSG::BitVector GridColorFieldMask =
        (TypeTraits<BitVector>::One << GridColorFieldId);
    static const OSG::BitVector GlobalCellEditorFieldMask =
        (TypeTraits<BitVector>::One << GlobalCellEditorFieldId);
    static const OSG::BitVector RowSelectionModelFieldMask =
        (TypeTraits<BitVector>::One << RowSelectionModelFieldId);
    static const OSG::BitVector NextFieldMask =
        (TypeTraits<BitVector>::One << NextFieldId);
        
    typedef SFUnrecChildTableHeaderPtr SFHeaderType;
    typedef SFUnrecTableModelPtr SFModelType;
    typedef SFUnrecTableColumnModelPtr SFColumnModelType;
    typedef MFUnrecComponentPtr MFTableType;
    typedef SFBool            SFAutoCreateColumnsFromModelType;
    typedef SFUInt32          SFAutoResizeModeType;
    typedef SFUInt32          SFRowHeightType;
    typedef SFUInt32          SFRowMarginType;
    typedef SFBool            SFRowSelectionAllowedType;
    typedef SFBool            SFShowHorizontalLinesType;
    typedef SFBool            SFShowVerticalLinesType;
    typedef SFColor4f         SFGridColorType;
    typedef SFUnrecCellEditorPtr SFGlobalCellEditorType;
    typedef SFUnrecListSelectionModelPtr SFRowSelectionModelType;

    /*---------------------------------------------------------------------*/
    /*! \name                    Class Get                                 */
    /*! \{                                                                 */

    static FieldContainerType &getClassType   (void);
    static UInt32              getClassTypeId (void);
    static UInt16              getClassGroupId(void);

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

            const SFUnrecChildTableHeaderPtr *getSFHeader         (void) const;
                  SFUnrecChildTableHeaderPtr *editSFHeader         (void);
            const SFUnrecTableModelPtr *getSFModel          (void) const;
                  SFUnrecTableModelPtr *editSFModel          (void);
            const SFUnrecTableColumnModelPtr *getSFColumnModel    (void) const;
                  SFUnrecTableColumnModelPtr *editSFColumnModel    (void);

                  SFBool              *editSFAutoCreateColumnsFromModel(void);
            const SFBool              *getSFAutoCreateColumnsFromModel (void) const;

                  SFUInt32            *editSFAutoResizeMode (void);
            const SFUInt32            *getSFAutoResizeMode  (void) const;

                  SFUInt32            *editSFRowHeight      (void);
            const SFUInt32            *getSFRowHeight       (void) const;

                  SFUInt32            *editSFRowMargin      (void);
            const SFUInt32            *getSFRowMargin       (void) const;

                  SFBool              *editSFRowSelectionAllowed(void);
            const SFBool              *getSFRowSelectionAllowed (void) const;

                  SFBool              *editSFShowHorizontalLines(void);
            const SFBool              *getSFShowHorizontalLines (void) const;

                  SFBool              *editSFShowVerticalLines(void);
            const SFBool              *getSFShowVerticalLines (void) const;

                  SFColor4f           *editSFGridColor      (void);
            const SFColor4f           *getSFGridColor       (void) const;
            const SFUnrecCellEditorPtr *getSFGlobalCellEditor(void) const;
                  SFUnrecCellEditorPtr *editSFGlobalCellEditor(void);
            const SFUnrecListSelectionModelPtr *getSFRowSelectionModel(void) const;
                  SFUnrecListSelectionModelPtr *editSFRowSelectionModel(void);


                  TableHeader * getHeader         (void) const;

                  TableModel * getModel          (void) const;

                  TableColumnModel * getColumnModel    (void) const;

                  bool                &editAutoCreateColumnsFromModel(void);
                  bool                 getAutoCreateColumnsFromModel (void) const;

                  UInt32              &editAutoResizeMode (void);
                  UInt32               getAutoResizeMode  (void) const;

                  UInt32              &editRowHeight      (void);
                  UInt32               getRowHeight       (void) const;

                  UInt32              &editRowMargin      (void);
                  UInt32               getRowMargin       (void) const;

                  bool                &editRowSelectionAllowed(void);
                  bool                 getRowSelectionAllowed (void) const;

                  bool                &editShowHorizontalLines(void);
                  bool                 getShowHorizontalLines (void) const;

                  bool                &editShowVerticalLines(void);
                  bool                 getShowVerticalLines (void) const;

                  Color4f             &editGridColor      (void);
            const Color4f             &getGridColor       (void) const;

                  CellEditor * getGlobalCellEditor(void) const;

                  ListSelectionModel * getRowSelectionModel(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

            void setHeader         (TableHeader * const value);
            void setModel          (TableModel * const value);
            void setColumnModel    (TableColumnModel * const value);
            void setAutoCreateColumnsFromModel(const bool value);
            void setAutoResizeMode (const UInt32 value);
            void setRowHeight      (const UInt32 value);
            void setRowMargin      (const UInt32 value);
            void setRowSelectionAllowed(const bool value);
            void setShowHorizontalLines(const bool value);
            void setShowVerticalLines(const bool value);
            void setGridColor      (const Color4f &value);
            void setGlobalCellEditor(CellEditor * const value);
            void setRowSelectionModel(ListSelectionModel * const value);

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
    /*! \name                   Construction                               */
    /*! \{                                                                 */

    static  TableTransitPtr  create          (void);
    static  Table           *createEmpty     (void);

    static  TableTransitPtr  createLocal     (
                                               BitVector bFlags = FCLocal::All);

    static  Table            *createEmptyLocal(
                                              BitVector bFlags = FCLocal::All);

    static  TableTransitPtr  createDependent  (BitVector bFlags);

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

    static TypeObject _type;

    static       void   classDescInserter(TypeObject &oType);
    static const Char8 *getClassname     (void             );

    /*---------------------------------------------------------------------*/
    /*! \name                      Fields                                  */
    /*! \{                                                                 */

    SFUnrecChildTableHeaderPtr _sfHeader;
    SFUnrecTableModelPtr _sfModel;
    SFUnrecTableColumnModelPtr _sfColumnModel;
    MFUnrecComponentPtr _mfTable;
    SFBool            _sfAutoCreateColumnsFromModel;
    SFUInt32          _sfAutoResizeMode;
    SFUInt32          _sfRowHeight;
    SFUInt32          _sfRowMargin;
    SFBool            _sfRowSelectionAllowed;
    SFBool            _sfShowHorizontalLines;
    SFBool            _sfShowVerticalLines;
    SFColor4f         _sfGridColor;
    SFUnrecCellEditorPtr _sfGlobalCellEditor;
    SFUnrecListSelectionModelPtr _sfRowSelectionModel;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    TableBase(void);
    TableBase(const TableBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~TableBase(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
    /*! \{                                                                 */

    void onCreate(const Table *source = NULL);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Child linking                                                */
    /*! \{                                                                 */

    virtual bool unlinkChild(FieldContainer * const pChild,
                             UInt16           const childFieldId);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Generic Field Access                      */
    /*! \{                                                                 */

    GetFieldHandlePtr  getHandleHeader          (void) const;
    EditFieldHandlePtr editHandleHeader         (void);
    GetFieldHandlePtr  getHandleModel           (void) const;
    EditFieldHandlePtr editHandleModel          (void);
    GetFieldHandlePtr  getHandleColumnModel     (void) const;
    EditFieldHandlePtr editHandleColumnModel    (void);
    GetFieldHandlePtr  getHandleTable           (void) const;
    EditFieldHandlePtr editHandleTable          (void);
    GetFieldHandlePtr  getHandleAutoCreateColumnsFromModel (void) const;
    EditFieldHandlePtr editHandleAutoCreateColumnsFromModel(void);
    GetFieldHandlePtr  getHandleAutoResizeMode  (void) const;
    EditFieldHandlePtr editHandleAutoResizeMode (void);
    GetFieldHandlePtr  getHandleRowHeight       (void) const;
    EditFieldHandlePtr editHandleRowHeight      (void);
    GetFieldHandlePtr  getHandleRowMargin       (void) const;
    EditFieldHandlePtr editHandleRowMargin      (void);
    GetFieldHandlePtr  getHandleRowSelectionAllowed (void) const;
    EditFieldHandlePtr editHandleRowSelectionAllowed(void);
    GetFieldHandlePtr  getHandleShowHorizontalLines (void) const;
    EditFieldHandlePtr editHandleShowHorizontalLines(void);
    GetFieldHandlePtr  getHandleShowVerticalLines (void) const;
    EditFieldHandlePtr editHandleShowVerticalLines(void);
    GetFieldHandlePtr  getHandleGridColor       (void) const;
    EditFieldHandlePtr editHandleGridColor      (void);
    GetFieldHandlePtr  getHandleGlobalCellEditor (void) const;
    EditFieldHandlePtr editHandleGlobalCellEditor(void);
    GetFieldHandlePtr  getHandleRowSelectionModel (void) const;
    EditFieldHandlePtr editHandleRowSelectionModel(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Get                                 */
    /*! \{                                                                 */

            const MFUnrecComponentPtr *getMFTable           (void) const;
                  MFUnrecComponentPtr *editMFTable          (void);


                  Component * getTable          (const UInt32 index) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr MField Set                                */
    /*! \{                                                                 */

    void pushToTable               (Component * const value   );
    void assignTable               (const MFUnrecComponentPtr &value);
    void removeFromTable (UInt32                uiIndex );
    void removeObjFromTable(Component * const value   );
    void clearTable                 (void                          );

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

            void execSync (      TableBase *pFrom,
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

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const TableBase &source);
};

typedef TableBase *TableBaseP;

OSG_END_NAMESPACE

#endif /* _OSGTABLEBASE_H_ */
