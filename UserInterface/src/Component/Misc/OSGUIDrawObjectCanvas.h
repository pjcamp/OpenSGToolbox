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

#ifndef _OSGUIDRAWOBJECTCANVAS_H_
#define _OSGUIDRAWOBJECTCANVAS_H_
#ifdef __sgi
#pragma once
#endif

#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"
#include "OSGUIDrawObjectCanvasBase.h"

OSG_BEGIN_NAMESPACE

/*! \brief UIDrawObjectCanvas class. See \ref 
           PageUserInterfaceUIDrawObjectCanvas for a description.
*/

class OSG_USERINTERFACELIB_DLLMAPPING UIDrawObjectCanvas : public UIDrawObjectCanvasBase
{
  private:

    typedef UIDrawObjectCanvasBase Inherited;

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
	virtual void getDrawObjectBounds(Pnt2f& TopLeft, Pnt2f& BottomRight) const;
	virtual Vec2f getContentRequestedSize(void) const;
    /*=========================  PROTECTED  ===============================*/
  protected:

    // Variables should all be in UIDrawObjectCanvasBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    UIDrawObjectCanvas(void);
    UIDrawObjectCanvas(const UIDrawObjectCanvas &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~UIDrawObjectCanvas(void); 

    /*! \}                                                                 */
	virtual void drawInternal(const GraphicsPtr Graphics) const;
    
    /*==========================  PRIVATE  ================================*/
  private:

    friend class FieldContainer;
    friend class UIDrawObjectCanvasBase;

    static void initMethod(void);

    // prohibit default functions (move to 'public' if you need one)

    void operator =(const UIDrawObjectCanvas &source);
};

typedef UIDrawObjectCanvas *UIDrawObjectCanvasP;

OSG_END_NAMESPACE

#include "OSGUIDrawObjectCanvasBase.inl"
#include "OSGUIDrawObjectCanvas.inl"

#define OSGUIDRAWOBJECTCANVAS_HEADER_CVSID "@(#)$Id: FCTemplate_h.h,v 1.23 2005/03/05 11:27:26 dirk Exp $"

#endif /* _OSGUIDRAWOBJECTCANVAS_H_ */
