/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox Particle System                        *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                         www.vrac.iastate.edu                              *
 *                                                                           *
 *   Authors: David Kabala, David Oluwatimi                                  *
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

#ifndef _OSGGEOMETRYCOLLISIONPARTICLESYSTEMAFFECTOR_H_
#define _OSGGEOMETRYCOLLISIONPARTICLESYSTEMAFFECTOR_H_
#ifdef __sgi
#pragma once
#endif

#include <OpenSG/OSGConfig.h>
#include "OSGParticleSystemDef.h"
#include <OpenSG/OSGIntersectAction.h>

#include <set>
#include "ParticleSystem/Events/OSGParticleGeometryCollisionListener.h"

#include "OSGGeometryCollisionParticleSystemAffectorBase.h"

OSG_BEGIN_NAMESPACE

/*! \brief GeometryCollisionParticleSystemAffector class. See \ref 
           PageParticleSystemGeometryCollisionParticleSystemAffector for a description.
*/

class OSG_PARTICLESYSTEMLIB_DLLMAPPING GeometryCollisionParticleSystemAffector : public GeometryCollisionParticleSystemAffectorBase
{
  private:

    typedef GeometryCollisionParticleSystemAffectorBase Inherited;

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
    virtual void affect(ParticleSystemPtr System, const Time& elps);
	
    void addParticleGeometryCollisionListener(ParticleGeometryCollisionListenerPtr Listener);
    void removeParticleGeometryCollisionListener(ParticleGeometryCollisionListenerPtr Listener);
    /*=========================  PROTECTED  ===============================*/
  protected:

    // Variables should all be in GeometryCollisionParticleSystemAffectorBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    GeometryCollisionParticleSystemAffector(void);
    GeometryCollisionParticleSystemAffector(const GeometryCollisionParticleSystemAffector &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~GeometryCollisionParticleSystemAffector(void); 

    /*! \}                                                                 */
    
	typedef std::set<ParticleGeometryCollisionListenerPtr> ParticleGeometryCollisionListenerSet;
    typedef ParticleGeometryCollisionListenerSet::iterator ParticleGeometryCollisionListenerSetItor;

    ParticleGeometryCollisionListenerSet       _ParticleGeometryCollisionListeners;

    void produceCollision(ParticleSystemPtr System,Int32 ParticleIndex, IntersectAction* Action);
    /*==========================  PRIVATE  ================================*/
  private:

    friend class FieldContainer;
    friend class GeometryCollisionParticleSystemAffectorBase;

    static void initMethod(void);

    // prohibit default functions (move to 'public' if you need one)

    void operator =(const GeometryCollisionParticleSystemAffector &source);
};

typedef GeometryCollisionParticleSystemAffector *GeometryCollisionParticleSystemAffectorP;

OSG_END_NAMESPACE

#include "OSGGeometryCollisionParticleSystemAffectorBase.inl"
#include "OSGGeometryCollisionParticleSystemAffector.inl"

#endif /* _OSGGEOMETRYCOLLISIONPARTICLESYSTEMAFFECTOR_H_ */