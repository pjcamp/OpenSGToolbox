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
 **     class DiscDistribution2D
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGDISCDISTRIBUTION2DBASE_H_
#define _OSGDISCDISTRIBUTION2DBASE_H_
#ifdef __sgi
#pragma once
#endif


#include "OSGConfig.h"
#include "OSGContribParticleSystemDef.h"

//#include "OSGBaseTypes.h"

#include "OSGDistribution2D.h" // Parent

#include "OSGVecFields.h"               // Center type
#include "OSGSysFields.h"               // MinRadius type

#include "OSGDiscDistribution2DFields.h"


OSG_BEGIN_NAMESPACE

class DiscDistribution2D;

//! \brief DiscDistribution2D Base Class.

class OSG_CONTRIBPARTICLESYSTEM_DLLMAPPING DiscDistribution2DBase : public Distribution2D
{
  public:

    typedef Distribution2D Inherited;
    typedef Distribution2D ParentContainer;

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    OSG_GEN_INTERNALPTR(DiscDistribution2D);

    /*==========================  PUBLIC  =================================*/

  public:

    enum
    {
        CenterFieldId = Inherited::NextFieldId,
        MinRadiusFieldId = CenterFieldId + 1,
        MaxRadiusFieldId = MinRadiusFieldId + 1,
        MinThetaFieldId = MaxRadiusFieldId + 1,
        MaxThetaFieldId = MinThetaFieldId + 1,
        SurfaceOrEdgeFieldId = MaxThetaFieldId + 1,
        NextFieldId = SurfaceOrEdgeFieldId + 1
    };

    static const OSG::BitVector CenterFieldMask =
        (TypeTraits<BitVector>::One << CenterFieldId);
    static const OSG::BitVector MinRadiusFieldMask =
        (TypeTraits<BitVector>::One << MinRadiusFieldId);
    static const OSG::BitVector MaxRadiusFieldMask =
        (TypeTraits<BitVector>::One << MaxRadiusFieldId);
    static const OSG::BitVector MinThetaFieldMask =
        (TypeTraits<BitVector>::One << MinThetaFieldId);
    static const OSG::BitVector MaxThetaFieldMask =
        (TypeTraits<BitVector>::One << MaxThetaFieldId);
    static const OSG::BitVector SurfaceOrEdgeFieldMask =
        (TypeTraits<BitVector>::One << SurfaceOrEdgeFieldId);
    static const OSG::BitVector NextFieldMask =
        (TypeTraits<BitVector>::One << NextFieldId);
        
    typedef SFPnt2f           SFCenterType;
    typedef SFReal32          SFMinRadiusType;
    typedef SFReal32          SFMaxRadiusType;
    typedef SFReal32          SFMinThetaType;
    typedef SFReal32          SFMaxThetaType;
    typedef SFUInt32          SFSurfaceOrEdgeType;


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


                  SFPnt2f             *editSFCenter         (void);
            const SFPnt2f             *getSFCenter          (void) const;

                  SFReal32            *editSFMinRadius      (void);
            const SFReal32            *getSFMinRadius       (void) const;

                  SFReal32            *editSFMaxRadius      (void);
            const SFReal32            *getSFMaxRadius       (void) const;

                  SFReal32            *editSFMinTheta       (void);
            const SFReal32            *getSFMinTheta        (void) const;

                  SFReal32            *editSFMaxTheta       (void);
            const SFReal32            *getSFMaxTheta        (void) const;

                  SFUInt32            *editSFSurfaceOrEdge  (void);
            const SFUInt32            *getSFSurfaceOrEdge   (void) const;


                  Pnt2f               &editCenter         (void);
            const Pnt2f               &getCenter          (void) const;

                  Real32              &editMinRadius      (void);
                  Real32               getMinRadius       (void) const;

                  Real32              &editMaxRadius      (void);
                  Real32               getMaxRadius       (void) const;

                  Real32              &editMinTheta       (void);
                  Real32               getMinTheta        (void) const;

                  Real32              &editMaxTheta       (void);
                  Real32               getMaxTheta        (void) const;

                  UInt32              &editSurfaceOrEdge  (void);
                  UInt32               getSurfaceOrEdge   (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

            void setCenter         (const Pnt2f &value);
            void setMinRadius      (const Real32 value);
            void setMaxRadius      (const Real32 value);
            void setMinTheta       (const Real32 value);
            void setMaxTheta       (const Real32 value);
            void setSurfaceOrEdge  (const UInt32 value);

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

    static  DiscDistribution2DTransitPtr  create          (void);
    static  DiscDistribution2D           *createEmpty     (void);

    static  DiscDistribution2DTransitPtr  createLocal     (
                                               BitVector bFlags = FCLocal::All);

    static  DiscDistribution2D            *createEmptyLocal(
                                              BitVector bFlags = FCLocal::All);

    static  DiscDistribution2DTransitPtr  createDependent  (BitVector bFlags);

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

    SFPnt2f           _sfCenter;
    SFReal32          _sfMinRadius;
    SFReal32          _sfMaxRadius;
    SFReal32          _sfMinTheta;
    SFReal32          _sfMaxTheta;
    SFUInt32          _sfSurfaceOrEdge;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    DiscDistribution2DBase(void);
    DiscDistribution2DBase(const DiscDistribution2DBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~DiscDistribution2DBase(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
    /*! \{                                                                 */


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Generic Field Access                      */
    /*! \{                                                                 */

    GetFieldHandlePtr  getHandleCenter          (void) const;
    EditFieldHandlePtr editHandleCenter         (void);
    GetFieldHandlePtr  getHandleMinRadius       (void) const;
    EditFieldHandlePtr editHandleMinRadius      (void);
    GetFieldHandlePtr  getHandleMaxRadius       (void) const;
    EditFieldHandlePtr editHandleMaxRadius      (void);
    GetFieldHandlePtr  getHandleMinTheta        (void) const;
    EditFieldHandlePtr editHandleMinTheta       (void);
    GetFieldHandlePtr  getHandleMaxTheta        (void) const;
    EditFieldHandlePtr editHandleMaxTheta       (void);
    GetFieldHandlePtr  getHandleSurfaceOrEdge   (void) const;
    EditFieldHandlePtr editHandleSurfaceOrEdge  (void);

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

            void execSync (      DiscDistribution2DBase *pFrom,
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
    void operator =(const DiscDistribution2DBase &source);
};

typedef DiscDistribution2DBase *DiscDistribution2DBaseP;

OSG_END_NAMESPACE

#endif /* _OSGDISCDISTRIBUTION2DBASE_H_ */