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

#ifndef _OSGLIST_H_
#define _OSGLIST_H_
#ifdef __sgi
#pragma once
#endif

#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"

#include "OSGListBase.h"
#include "Event/OSGFocusListener.h"
#include "OSGListDataListener.h"
#include "OSGListSelectionListener.h"
#include "OSGListSelectionModel.h"
#include <boost/any.hpp>

#include <deque>

OSG_BEGIN_NAMESPACE

class OSG_USERINTERFACELIB_DLLMAPPING List : public ListBase, public ListSelectionListener, public ListDataListener, public FocusListener
{
  private:

    typedef ListBase Inherited;

    /*==========================  PUBLIC  =================================*/
  public:
      enum Orientation{VERTICAL_ORIENTATION=0, HORIZONTAL_ORIENTATION};

	//Focus Events
	virtual void focusGained(const FocusEventPtr e);
	virtual void focusLost(const FocusEventPtr e);

    //Selection Event
	virtual void selectionChanged(const ListSelectionEventPtr e);

	//List Data Events
	virtual void contentsChanged(const ListDataEventPtr e);
	virtual void intervalAdded(const ListDataEventPtr e);
	virtual void intervalRemoved(const ListDataEventPtr e);
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
   
    virtual void updateLayout(void);

    void setSelectionModel(ListSelectionModelPtr SelectionModel);

    ListSelectionModelPtr getSelectionModel(void) const;
	
    virtual void mousePressed(const MouseEventPtr e);
	virtual void keyTyped(const KeyEventPtr e);

    ComponentPtr getComponentAtPoint(const MouseEventPtr e);
    boost::any getValueAtPoint(const MouseEventPtr e);

    //Returns the row for the specified location.
	//The Location should be in Component space
    Int32 getIndexForLocation(const Pnt2f& Location) const;

	
    Int32 getIndexClosestToLocation(const Pnt2f& Location) const;

    ComponentPtr getComponentAtIndex(const UInt32& Index);
    boost::any getValueAtIndex(const UInt32& Index);
    
	
	//Scrollable Interface
    //Returns the preferred size of the viewport for a view component.
    virtual Vec2f getPreferredScrollableViewportSize(void);

    //Components that display logical rows or columns should compute the scroll increment that will completely expose one block of rows or columns, depending on the value of orientation.
    virtual Int32 getScrollableBlockIncrement(const Pnt2f& VisibleRectTopLeft, const Pnt2f& VisibleRectBottomRight, const UInt32& orientation, const Int32& direction);

    //Return true if a viewport should always force the height of this Scrollable to match the height of the viewport.
    virtual bool getScrollableTracksViewportHeight(void);

    //Return true if a viewport should always force the width of this Scrollable to match the width of the viewport.
    virtual bool getScrollableTracksViewportWidth(void);

    //Components that display logical rows or columns should compute the scroll increment that will completely expose one new row or column, depending on the value of orientation.
    virtual Int32 getScrollableUnitIncrement(const Pnt2f& VisibleRectTopLeft, const Pnt2f& VisibleRectBottomRight, const UInt32& orientation, const Int32& direction);
    
	void scrollToIndex(const UInt32& Index);

	void scrollToFocused(void);

	void scrollToSelection(void);
	/*=========================  PROTECTED  ===============================*/
  protected:

    // Variables should all be in ListBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    List(void);
    List(const List &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~List(void); 

    /*! \}                                                                 */

    ListSelectionModelPtr _SelectionModel;


	void updateIndiciesDrawnFromModel(void);

	//Updates the drawn Indices.  Called when the ClipBounds of the List
	//changes
    void updateIndicesDrawn(void);

	//Determines the indicies of the Indices that will be seen
	//taking the clip bounds into account
    void getDrawnIndices(Int32& Beginning, Int32& End) const;

	Int32 getListIndexFromDrawnIndex(const Int32& Index) const;

	Int32 getDrawnIndexFromListIndex(const Int32& Index) const;
	
    void updatePreferredSize(void);

	void focusIndex(const Int32& Index);
	
	//Creates the component for the given Index
    ComponentPtr createIndexComponent(const UInt32& Index);

	
	void updateItem(const UInt32& Index);

	void cleanItem(const UInt32& Index);

	void initItem(const UInt32& Index);
	
    Int32 _TopDrawnIndex,
          _BottomDrawnIndex;
	Int32 _FocusedIndex;

    std::deque<ComponentPtr> _DrawnIndices;

    /*==========================  PRIVATE  ================================*/
  private:

    friend class FieldContainer;
    friend class ListBase;

    static void initMethod(void);

    // prohibit default functions (move to 'public' if you need one)

    void operator =(const List &source);
};

typedef List *ListP;

OSG_END_NAMESPACE

#include "OSGListBase.inl"
#include "OSGList.inl"

#define OSGLIST_HEADER_CVSID "@(#)$Id: FCTemplate_h.h,v 1.23 2005/03/05 11:27:26 dirk Exp $"

#endif /* _OSGLIST_H_ */
