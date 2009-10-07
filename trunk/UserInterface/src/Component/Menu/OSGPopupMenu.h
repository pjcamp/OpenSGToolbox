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

#ifndef _OSGPOPUPMENU_H_
#define _OSGPOPUPMENU_H_
#ifdef __sgi
#pragma once
#endif

#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"

#include "OSGPopupMenuBase.h"
#include "OSGMenuItemFields.h"
#include "Models/SelectionModels/OSGSelectionListener.h"
#include "Event/OSGPopupMenuListener.h"

#include <OpenSG/Toolbox/OSGEventConnection.h>

OSG_BEGIN_NAMESPACE

/*! \brief PopupMenu class. See \ref 
           PageUserInterfacePopupMenu for a description.
*/

class OSG_USERINTERFACELIB_DLLMAPPING PopupMenu : public PopupMenuBase
{
  private:

    typedef PopupMenuBase Inherited;

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

    virtual void addItem(MenuItemPtr Item);
    virtual void addItem(MenuItemPtr Item, const UInt32& Index);
    virtual void removeItem(MenuItemPtr Item);
    virtual void removeItem(const UInt32& Index);
    virtual void removeAllItems(void);
    virtual MenuItemPtr getItem(const UInt32& Index);
    virtual UInt32 getNumItems(void) const;

    void addSeparator(void);
    void addSeparator(SeparatorPtr TheSeparator);
    void removeSeparator(const UInt32&  Index);
    void removeSeparator(SeparatorPtr TheSeparator);
    void removeAllSeparators(void);
    UInt32 getNumSeparators(void) const;
    
	virtual void updateClipBounds(void);
    
	//Mouse Motion Events
    virtual void mouseMoved(const MouseEventPtr e);
    virtual void mouseDragged(const MouseEventPtr e);
    
    EventConnection addPopupMenuListener(PopupMenuListenerPtr Listener);
	bool isPopupMenuListenerAttached(PopupMenuListenerPtr Listener) const;
    void removePopupMenuListener(PopupMenuListenerPtr Listener);

    void cancel(void);

    void clearSelection(void);
    void setSelection(const Int32& Index);
    Int32 getSelectionIndex(void) const;
    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/
  protected:

    // Variables should all be in PopupMenuBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    PopupMenu(void);
    PopupMenu(const PopupMenu &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~PopupMenu(void); 
    /*! \}                                                                 */
    
    virtual void updateLayout(void);
    
	class MenuSelectionListener : public SelectionListener
	{
	public:
		MenuSelectionListener(PopupMenuPtr ThePopupMenu);
        virtual void selectionChanged(const SelectionEventPtr e);
	private:
		PopupMenuPtr _PopupMenu;
	};

	friend class MenuSelectionListener;

	MenuSelectionListener _MenuSelectionListener;
	
	typedef std::set<PopupMenuListenerPtr> PopupMenuListenerSet;
    typedef PopupMenuListenerSet::iterator PopupMenuListenerSetItor;
    typedef PopupMenuListenerSet::const_iterator PopupMenuListenerSetConstItor;
	
    PopupMenuListenerSet       _PopupMenuListeners;
    void producePopupMenuWillBecomeVisible(const PopupMenuEventPtr e);
    void producePopupMenuWillBecomeInvisible(const PopupMenuEventPtr e);
    void producePopupMenuCanceled(const PopupMenuEventPtr e);
    void producePopupMenuContentsChanged(const PopupMenuEventPtr e);
    
    void updateSeparatorSizes(void);
    /*==========================  PRIVATE  ================================*/
  private:

    friend class FieldContainer;
    friend class PopupMenuBase;

    static void initMethod(void);

    // prohibit default functions (move to 'public' if you need one)

    void operator =(const PopupMenu &source);
};

typedef PopupMenu *PopupMenuP;

OSG_END_NAMESPACE

#include "OSGPopupMenuBase.inl"
#include "OSGPopupMenu.inl"

#define OSGPOPUPMENU_HEADER_CVSID "@(#)$Id: FCTemplate_h.h,v 1.23 2005/03/05 11:27:26 dirk Exp $"

#endif /* _OSGPOPUPMENU_H_ */
