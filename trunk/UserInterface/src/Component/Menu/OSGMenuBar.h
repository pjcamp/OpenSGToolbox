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

#ifndef _OSGMENUBAR_H_
#define _OSGMENUBAR_H_
#ifdef __sgi
#pragma once
#endif

#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"

#include "OSGMenuBarBase.h"
#include "OSGMenu.h"

#include "Event/OSGPopupMenuListener.h"
#include <OpenSG/Input/OSGKeyAdapter.h>

OSG_BEGIN_NAMESPACE

/*! \brief MenuBar class. See \ref 
           PageUserInterfaceMenuBar for a description.
*/

class OSG_USERINTERFACELIB_DLLMAPPING MenuBar : public MenuBarBase
{
  private:

    typedef MenuBarBase Inherited;

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

    void addMenu(MenuPtr Menu);
    void addMenu(MenuPtr Menu, const UInt32& Index);
    void removeMenu(MenuPtr Menu);
    void removeMenu(const UInt32& Index);
    MenuPtr getMenu(const UInt32& Index);
    UInt32 getNumMenus(void) const;
    
    virtual void mousePressed(const MouseEventPtr e);
    
    virtual void updateLayout(void);
	virtual void updateClipBounds(void);
    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/
  protected:

    // Variables should all be in MenuBarBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    MenuBar(void);
    MenuBar(const MenuBar &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~MenuBar(void); 
    
	class MenuSelectionListener : public SelectionListener, 
                                  public MouseMotionListener, 
                                  public PopupMenuListener,
                                  public KeyAdapter
	{
	public:
		MenuSelectionListener(MenuBarPtr ThePopupMenu);
        virtual void selectionChanged(const SelectionEventPtr e);
        virtual void mouseMoved(const MouseEventPtr e);
        virtual void mouseDragged(const MouseEventPtr e);
        virtual void popupMenuCanceled(const PopupMenuEventPtr e);
        virtual void popupMenuWillBecomeInvisible(const PopupMenuEventPtr e);
        virtual void popupMenuWillBecomeVisible(const PopupMenuEventPtr e);
		virtual void popupMenuContentsChanged(const PopupMenuEventPtr e);
        virtual void keyTyped(const KeyEventPtr e);
	private:
		MenuBarPtr _MenuBar;
	};

	friend class MenuSelectionListener;

	MenuSelectionListener _MenuSelectionListener;
    /*! \}                                                                 */
    
    /*==========================  PRIVATE  ================================*/
  private:

    friend class FieldContainer;
    friend class MenuBarBase;

    static void initMethod(void);

    // prohibit default functions (move to 'public' if you need one)

    void operator =(const MenuBar &source);
};

typedef MenuBar *MenuBarP;

OSG_END_NAMESPACE

#include "OSGMenuBarBase.inl"
#include "OSGMenuBar.inl"

#define OSGMENUBAR_HEADER_CVSID "@(#)$Id: FCTemplate_h.h,v 1.23 2005/03/05 11:27:26 dirk Exp $"

#endif /* _OSGMENUBAR_H_ */
