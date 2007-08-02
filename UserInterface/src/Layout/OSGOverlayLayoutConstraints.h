/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                         www.vrac.iastate.edu                              *
 *                                                                           *
 *   Authors: David Kabala, Alden Peterson, Lee Zaniewski, Jonathan Flory    *
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

#ifndef _OSGOVERLAYLAYOUTCONSTRAINTS_H_
#define _OSGOVERLAYLAYOUTCONSTRAINTS_H_
#ifdef __sgi
#pragma once
#endif

#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"

#include "OSGOverlayLayoutConstraintsBase.h"

OSG_BEGIN_NAMESPACE

class OSG_USERINTERFACELIB_DLLMAPPING OverlayLayoutConstraints : public OverlayLayoutConstraintsBase
{
  private:

    typedef OverlayLayoutConstraintsBase Inherited;

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
    /*=========================  PROTECTED  ===============================*/
  protected:

    // Variables should all be in OverlayLayoutConstraintsBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    OverlayLayoutConstraints(void);
    OverlayLayoutConstraints(const OverlayLayoutConstraints &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~OverlayLayoutConstraints(void); 

    /*! \}                                                                 */
    
    /*==========================  PRIVATE  ================================*/
  private:

    friend class FieldContainer;
    friend class OverlayLayoutConstraintsBase;

    static void initMethod(void);

    // prohibit default functions (move to 'public' if you need one)

    void operator =(const OverlayLayoutConstraints &source);
};

typedef OverlayLayoutConstraints *OverlayLayoutConstraintsP;

OSG_END_NAMESPACE

#include "OSGOverlayLayoutConstraintsBase.inl"
#include "OSGOverlayLayoutConstraints.inl"

#define OSGOVERLAYLAYOUTCONSTRAINTS_HEADER_CVSID "@(#)$Id: FCTemplate_h.h,v 1.23 2005/03/05 11:27:26 dirk Exp $"

#endif /* _OSGOVERLAYLAYOUTCONSTRAINTS_H_ */
