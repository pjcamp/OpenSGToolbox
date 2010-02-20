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
 **     class Graphics2D
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGGRAPHICS2DBASE_H_
#define _OSGGRAPHICS2DBASE_H_
#ifdef __sgi
#pragma once
#endif


#include "OSGConfig.h"
#include "OSGContribUserInterfaceDef.h"

//#include "OSGBaseTypes.h"

#include "OSGGraphics.h" // Parent

#include "OSGDepthChunkFields.h"        // UIDepth type
#include "OSGColorMaskChunkFields.h"    // ColorMask type
#include "OSGStencilChunkFields.h"      // StenciledAreaSetup type

#include "OSGGraphics2DFields.h"

OSG_BEGIN_NAMESPACE

class Graphics2D;

//! \brief Graphics2D Base Class.

class OSG_CONTRIBUSERINTERFACE_DLLMAPPING Graphics2DBase : public Graphics
{
  public:

    typedef Graphics Inherited;
    typedef Graphics ParentContainer;

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    OSG_GEN_INTERNALPTR(Graphics2D);

    /*==========================  PUBLIC  =================================*/

  public:

    enum
    {
        UIDepthFieldId = Inherited::NextFieldId,
        ColorMaskFieldId = UIDepthFieldId + 1,
        StenciledAreaSetupFieldId = ColorMaskFieldId + 1,
        StenciledAreaCleanupFieldId = StenciledAreaSetupFieldId + 1,
        StenciledAreaTestFieldId = StenciledAreaCleanupFieldId + 1,
        NextFieldId = StenciledAreaTestFieldId + 1
    };

    static const OSG::BitVector UIDepthFieldMask =
        (TypeTraits<BitVector>::One << UIDepthFieldId);
    static const OSG::BitVector ColorMaskFieldMask =
        (TypeTraits<BitVector>::One << ColorMaskFieldId);
    static const OSG::BitVector StenciledAreaSetupFieldMask =
        (TypeTraits<BitVector>::One << StenciledAreaSetupFieldId);
    static const OSG::BitVector StenciledAreaCleanupFieldMask =
        (TypeTraits<BitVector>::One << StenciledAreaCleanupFieldId);
    static const OSG::BitVector StenciledAreaTestFieldMask =
        (TypeTraits<BitVector>::One << StenciledAreaTestFieldId);
    static const OSG::BitVector NextFieldMask =
        (TypeTraits<BitVector>::One << NextFieldId);
        
    typedef SFUnrecDepthChunkPtr SFUIDepthType;
    typedef SFUnrecColorMaskChunkPtr SFColorMaskType;
    typedef SFUnrecStencilChunkPtr SFStenciledAreaSetupType;
    typedef SFUnrecStencilChunkPtr SFStenciledAreaCleanupType;
    typedef SFUnrecStencilChunkPtr SFStenciledAreaTestType;

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

    static  Graphics2DTransitPtr  create          (void);
    static  Graphics2D           *createEmpty     (void);

    static  Graphics2DTransitPtr  createLocal     (
                                               BitVector bFlags = FCLocal::All);

    static  Graphics2D            *createEmptyLocal(
                                              BitVector bFlags = FCLocal::All);

    static  Graphics2DTransitPtr  createDependent  (BitVector bFlags);

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

    SFUnrecDepthChunkPtr _sfUIDepth;
    SFUnrecColorMaskChunkPtr _sfColorMask;
    SFUnrecStencilChunkPtr _sfStenciledAreaSetup;
    SFUnrecStencilChunkPtr _sfStenciledAreaCleanup;
    SFUnrecStencilChunkPtr _sfStenciledAreaTest;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    Graphics2DBase(void);
    Graphics2DBase(const Graphics2DBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~Graphics2DBase(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
    /*! \{                                                                 */

    void onCreate(const Graphics2D *source = NULL);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Generic Field Access                      */
    /*! \{                                                                 */

    GetFieldHandlePtr  getHandleUIDepth         (void) const;
    EditFieldHandlePtr editHandleUIDepth        (void);
    GetFieldHandlePtr  getHandleColorMask       (void) const;
    EditFieldHandlePtr editHandleColorMask      (void);
    GetFieldHandlePtr  getHandleStenciledAreaSetup (void) const;
    EditFieldHandlePtr editHandleStenciledAreaSetup(void);
    GetFieldHandlePtr  getHandleStenciledAreaCleanup (void) const;
    EditFieldHandlePtr editHandleStenciledAreaCleanup(void);
    GetFieldHandlePtr  getHandleStenciledAreaTest (void) const;
    EditFieldHandlePtr editHandleStenciledAreaTest(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Get                                 */
    /*! \{                                                                 */

            const SFUnrecDepthChunkPtr *getSFUIDepth         (void) const;
                  SFUnrecDepthChunkPtr *editSFUIDepth        (void);
            const SFUnrecColorMaskChunkPtr *getSFColorMask       (void) const;
                  SFUnrecColorMaskChunkPtr *editSFColorMask      (void);
            const SFUnrecStencilChunkPtr *getSFStenciledAreaSetup (void) const;
                  SFUnrecStencilChunkPtr *editSFStenciledAreaSetup(void);
            const SFUnrecStencilChunkPtr *getSFStenciledAreaCleanup (void) const;
                  SFUnrecStencilChunkPtr *editSFStenciledAreaCleanup(void);
            const SFUnrecStencilChunkPtr *getSFStenciledAreaTest (void) const;
                  SFUnrecStencilChunkPtr *editSFStenciledAreaTest(void);


                  DepthChunk * getUIDepth        (void) const;

                  ColorMaskChunk * getColorMask      (void) const;

                  StencilChunk * getStenciledAreaSetup(void) const;

                  StencilChunk * getStenciledAreaCleanup(void) const;

                  StencilChunk * getStenciledAreaTest(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

            void setUIDepth        (DepthChunk * const value);
            void setColorMask      (ColorMaskChunk * const value);
            void setStenciledAreaSetup(StencilChunk * const value);
            void setStenciledAreaCleanup(StencilChunk * const value);
            void setStenciledAreaTest(StencilChunk * const value);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr MField Set                                */
    /*! \{                                                                 */

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

            void execSync (      Graphics2DBase *pFrom,
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
    void operator =(const Graphics2DBase &source);
};

typedef Graphics2DBase *Graphics2DBaseP;

OSG_END_NAMESPACE

#endif /* _OSGGRAPHICS2DBASE_H_ */
