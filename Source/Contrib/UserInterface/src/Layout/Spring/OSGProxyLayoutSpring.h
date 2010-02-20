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

#ifndef _OSGPROXYLAYOUTSPRING_H_
#define _OSGPROXYLAYOUTSPRING_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGProxyLayoutSpringBase.h"
#include "OSGComponent.h"

OSG_BEGIN_NAMESPACE

/*! \brief ProxyLayoutSpring class. See \ref
           PageContribUserInterfaceProxyLayoutSpring for a description.
*/

class OSG_CONTRIBUSERINTERFACE_DLLMAPPING ProxyLayoutSpring : public ProxyLayoutSpringBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef ProxyLayoutSpringBase Inherited;
    typedef ProxyLayoutSpring     Self;

    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    virtual void changed(ConstFieldMaskArg whichField,
                         UInt32            origin,
                         BitVector         details    );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual void dump(      UInt32     uiIndent = 0,
                      const BitVector  bvFlags  = 0) const;

    /*! \}                                                                 */

    static  ProxyLayoutSpringTransitPtr create (const UInt32& Edge, 
                                                Component* TheComponent,
                                                SpringLayout* TheLayout); 
    
    //Returns the maximum value of this LayoutSpringRefPtr.
    virtual Real32 getMinimumValue(void) const;

    //Returns the Preferred value of this LayoutSpringRefPtr.
    virtual Real32 getPreferredValue(void) const;

    //Returns the minimum value of this LayoutSpringRefPtr.
    virtual Real32 getMaximumValue(void) const;

    //Returns the current value of this LayoutSpringRefPtr.
    virtual Real32 getValue(void) const;

    //Sets the current value of this LayoutSpringRefPtr.
    virtual void setValue(const Real32& value);
    
    virtual bool isCyclic(const SpringLayout* l) const;

    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in ProxyLayoutSpringBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    ProxyLayoutSpring(void);
    ProxyLayoutSpring(const ProxyLayoutSpring &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~ProxyLayoutSpring(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class ProxyLayoutSpringBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const ProxyLayoutSpring &source);
    
    LayoutSpringRefPtr getConstraint(void) const;
};

typedef ProxyLayoutSpring *ProxyLayoutSpringP;

OSG_END_NAMESPACE

#include "OSGSpringLayout.h"
#include "OSGSpringLayoutConstraints.h"

#include "OSGProxyLayoutSpringBase.inl"
#include "OSGProxyLayoutSpring.inl"

#endif /* _OSGPROXYLAYOUTSPRING_H_ */
