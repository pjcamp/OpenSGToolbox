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

#ifndef _OSGCOMPOUNDBORDER_H_
#define _OSGCOMPOUNDBORDER_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGCompoundBorderBase.h"

OSG_BEGIN_NAMESPACE

/*! \brief CompoundBorder class. See \ref
           PageContribUserInterfaceCompoundBorder for a description.
*/

class OSG_CONTRIBUSERINTERFACE_DLLMAPPING CompoundBorder : public CompoundBorderBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef CompoundBorderBase Inherited;
    typedef CompoundBorder     Self;

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

	virtual void draw(Graphics* const g,
                      const Real32 x,
                      const Real32 y ,
                      const Real32 Width,
                      const Real32 Height,
                      const Real32 Opacity,
                      bool Clipping = true) const;

	virtual void getInsets(Real32& Left,
                           Real32& Right,
                           Real32& Top,
                           Real32& Bottom) const;

	virtual void activateInternalDrawConstraints(Graphics* const g,
                                                 const Real32& x,
                                                 const Real32& y ,
                                                 const Real32& Width,
                                                 const Real32& Height) const;

	virtual bool isContained(const Pnt2f& p,
                             const Real32& x,
                             const Real32& y ,
                             const Real32& Width,
                             const Real32& Height) const;

    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in CompoundBorderBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    CompoundBorder(void);
    CompoundBorder(const CompoundBorder &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~CompoundBorder(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class CompoundBorderBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const CompoundBorder &source);
};

typedef CompoundBorder *CompoundBorderP;

OSG_END_NAMESPACE

#include "OSGCompoundBorderBase.inl"
#include "OSGCompoundBorder.inl"

#endif /* _OSGCOMPOUNDBORDER_H_ */
