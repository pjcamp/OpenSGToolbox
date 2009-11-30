/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox Particle System                        *
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
 **     class QuadDistribution2D
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGQUADDISTRIBUTION2DBASE_H_
#define _OSGQUADDISTRIBUTION2DBASE_H_
#ifdef __sgi
#pragma once
#endif


#include <OpenSG/OSGConfig.h>
#include "OSGParticleSystemDef.h"

#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGRefPtr.h>
#include <OpenSG/OSGCoredNodePtr.h>

#include "OSGDistribution2D.h" // Parent

#include <OpenSG/OSGPnt2fFields.h> // Point1 type
#include <OpenSG/OSGPnt2fFields.h> // Point2 type
#include <OpenSG/OSGPnt2fFields.h> // Point3 type
#include <OpenSG/OSGPnt2fFields.h> // Point4 type
#include <OpenSG/OSGUInt32Fields.h> // SurfaceOrEdge type

#include "OSGQuadDistribution2DFields.h"
OSG_BEGIN_NAMESPACE

class QuadDistribution2D;
class BinaryDataHandler;

//! \brief QuadDistribution2D Base Class.

class OSG_PARTICLESYSTEMLIB_DLLMAPPING QuadDistribution2DBase : public Distribution2D
{
  private:

    typedef Distribution2D    Inherited;

    /*==========================  PUBLIC  =================================*/
  public:

    typedef QuadDistribution2DPtr  Ptr;

    enum
    {
        Point1FieldId        = Inherited::NextFieldId,
        Point2FieldId        = Point1FieldId        + 1,
        Point3FieldId        = Point2FieldId        + 1,
        Point4FieldId        = Point3FieldId        + 1,
        SurfaceOrEdgeFieldId = Point4FieldId        + 1,
        NextFieldId          = SurfaceOrEdgeFieldId + 1
    };

    static const OSG::BitVector Point1FieldMask;
    static const OSG::BitVector Point2FieldMask;
    static const OSG::BitVector Point3FieldMask;
    static const OSG::BitVector Point4FieldMask;
    static const OSG::BitVector SurfaceOrEdgeFieldMask;


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


           SFPnt2f             *editSFPoint1         (void);
     const SFPnt2f             *getSFPoint1         (void) const;

           SFPnt2f             *editSFPoint2         (void);
     const SFPnt2f             *getSFPoint2         (void) const;

           SFPnt2f             *editSFPoint3         (void);
     const SFPnt2f             *getSFPoint3         (void) const;

           SFPnt2f             *editSFPoint4         (void);
     const SFPnt2f             *getSFPoint4         (void) const;

           SFUInt32            *editSFSurfaceOrEdge  (void);
     const SFUInt32            *getSFSurfaceOrEdge  (void) const;


           Pnt2f               &editPoint1         (void);
     const Pnt2f               &getPoint1         (void) const;

           Pnt2f               &editPoint2         (void);
     const Pnt2f               &getPoint2         (void) const;

           Pnt2f               &editPoint3         (void);
     const Pnt2f               &getPoint3         (void) const;

           Pnt2f               &editPoint4         (void);
     const Pnt2f               &getPoint4         (void) const;

           UInt32              &editSurfaceOrEdge  (void);
     const UInt32              &getSurfaceOrEdge  (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

     void setPoint1         ( const Pnt2f &value );
     void setPoint2         ( const Pnt2f &value );
     void setPoint3         ( const Pnt2f &value );
     void setPoint4         ( const Pnt2f &value );
     void setSurfaceOrEdge  ( const UInt32 &value );

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

    static  QuadDistribution2DPtr      create          (void); 
    static  QuadDistribution2DPtr      createEmpty     (void); 

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

    SFPnt2f             _sfPoint1;
    SFPnt2f             _sfPoint2;
    SFPnt2f             _sfPoint3;
    SFPnt2f             _sfPoint4;
    SFUInt32            _sfSurfaceOrEdge;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    QuadDistribution2DBase(void);
    QuadDistribution2DBase(const QuadDistribution2DBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~QuadDistribution2DBase(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#if !defined(OSG_FIXED_MFIELDSYNC)
    void executeSyncImpl(      QuadDistribution2DBase *pOther,
                         const BitVector         &whichField);

    virtual void   executeSync(      FieldContainer    &other,
                               const BitVector         &whichField);
#else
    void executeSyncImpl(      QuadDistribution2DBase *pOther,
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
    void operator =(const QuadDistribution2DBase &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------


typedef QuadDistribution2DBase *QuadDistribution2DBaseP;

typedef osgIF<QuadDistribution2DBase::isNodeCore,
              CoredNodePtr<QuadDistribution2D>,
              FieldContainer::attempt_to_create_CoredNodePtr_on_non_NodeCore_FC
              >::_IRet QuadDistribution2DNodePtr;

typedef RefPtr<QuadDistribution2DPtr> QuadDistribution2DRefPtr;

OSG_END_NAMESPACE

#endif /* _OSGQUADDISTRIBUTION2DBASE_H_ */