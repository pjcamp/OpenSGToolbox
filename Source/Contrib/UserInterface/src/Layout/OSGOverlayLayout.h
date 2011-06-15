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

#ifndef _OSGOVERLAYLAYOUT_H_
#define _OSGOVERLAYLAYOUT_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGOverlayLayoutBase.h"
#include "OSGOverlayLayoutConstraints.h"

OSG_BEGIN_NAMESPACE

/*! \brief OverlayLayout class. See \ref
           PageContribUserInterfaceOverlayLayout for a description.
*/

class OSG_CONTRIBUSERINTERFACE_DLLMAPPING OverlayLayout : public OverlayLayoutBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef OverlayLayoutBase Inherited;
    typedef OverlayLayout     Self;

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
    virtual void updateLayout(const MFUnrecChildComponentPtr* Components, const Component* ParentComponent) const;
    
    virtual Vec2f minimumContentsLayoutSize(const MFUnrecChildComponentPtr* Components, const Component* ParentComponent) const;
    virtual Vec2f requestedContentsLayoutSize(const MFUnrecChildComponentPtr* Components, const Component* ParentComponent) const;
    virtual Vec2f preferredContentsLayoutSize(const MFUnrecChildComponentPtr* Components, const Component* ParentComponent) const;
    virtual Vec2f maximumContentsLayoutSize(const MFUnrecChildComponentPtr* Components, const Component* ParentComponent) const;
    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in OverlayLayoutBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    OverlayLayout(void);
    OverlayLayout(const OverlayLayout &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~OverlayLayout(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    
    virtual Vec2f layoutSize(const MFUnrecChildComponentPtr* Components, const Component* ParentComponent, SizeType TheSizeType) const;

    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class OverlayLayoutBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const OverlayLayout &source);
};

typedef OverlayLayout *OverlayLayoutP;

OSG_END_NAMESPACE

#include "OSGOverlayLayoutBase.inl"
#include "OSGOverlayLayout.inl"

#endif /* _OSGOVERLAYLAYOUT_H_ */
