/*---------------------------------------------------------------------------*\
 *                        OpenSG ToolBox Dynamics                            *
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

#ifndef _OSGGAUSSIANNORMALDISTRIBUTION3D_H_
#define _OSGGAUSSIANNORMALDISTRIBUTION3D_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGParticleSystemDef.h"

#include "OSGGaussianNormalDistribution3DBase.h"
#include <OpenSG/OSGVecFieldDataType.h>

OSG_BEGIN_NAMESPACE

class OSG_PARTICLESYSTEMLIB_DLLMAPPING GaussianNormalDistribution3D : public GaussianNormalDistribution3DBase
{
  private:

    typedef GaussianNormalDistribution3DBase Inherited;

    /*==========================  PUBLIC  =================================*/
  public:

    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    virtual void changed(BitVector  whichField, 
                         UInt32     origin    );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual void dump(      UInt32     uiIndent = 0, 
                      const BitVector  bvFlags  = 0) const;

    /*! \}                                                                 */
    virtual Vec3f generate(void) const;
    /*=========================  PROTECTED  ===============================*/
  protected:

    // Variables should all be in GaussianNormalDistribution3DBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    GaussianNormalDistribution3D(void);
    GaussianNormalDistribution3D(const GaussianNormalDistribution3D &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~GaussianNormalDistribution3D(void); 

    /*! \}                                                                 */
    
    /*==========================  PRIVATE  ================================*/
  private:

    friend class FieldContainer;
    friend class GaussianNormalDistribution3DBase;

    static void initMethod(void);

    // prohibit default functions (move to 'public' if you need one)

    void operator =(const GaussianNormalDistribution3D &source);
};

typedef GaussianNormalDistribution3D *GaussianNormalDistribution3DP;

OSG_END_NAMESPACE

#include "OSGGaussianNormalDistribution3DBase.inl"
#include "OSGGaussianNormalDistribution3D.inl"

#endif /* _OSGGAUSSIANNORMALDISTRIBUTION3D_H_ */