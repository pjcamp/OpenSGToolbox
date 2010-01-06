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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>

#define OSG_COMPILEUSERINTERFACELIB

#include <OpenSG/OSGConfig.h>

#include "OSGMenuBar.h"
#include "Models/SelectionModels/OSGDefaultSingleSelectionModel.h"

#include "Component/Container/Window/OSGInternalWindow.h"
#include "UIDrawingSurface/OSGUIDrawingSurface.h"
#include "Util/OSGUIDrawUtils.h"

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class osg::MenuBar
A UI MenuBar. 	
*/

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void MenuBar::initMethod (void)
{
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

void MenuBar::updateLayout(void)
{
	//Determine the Max Preferred Height of my MenuItems
	Real32 MaxHeight(0);
	Real32 TotalWidth(0);
    for(UInt32 i(0) ; i<getChildren().size() ; ++i)
    {
        if(MaxHeight < getChildren()[i]->getPreferredSize().y())
        {
            MaxHeight = getChildren()[i]->getPreferredSize().y();
	    }
	    TotalWidth += getChildren()[i]->getPreferredSize().x();
	}

    //Set My preferred Size
	Pnt2f TopLeft, BottomRight;
	Pnt2f InsetsTopLeft, InsetsBottomRight;
	getBounds(TopLeft, BottomRight);
	getInsideInsetsBounds(InsetsTopLeft, InsetsBottomRight);

	Vec2f InsetSize( (BottomRight-TopLeft) - (InsetsBottomRight-InsetsTopLeft) );

    Vec2f NewSize( TotalWidth+InsetSize.x(), MaxHeight+InsetSize.y());
    if(getPreferredSize() != NewSize)
    {
        beginEditCP(MenuBarPtr(this), PreferredSizeFieldMask);
            setPreferredSize(NewSize);
            //Sneakily set my size
            //setSize(NewSize);
        endEditCP(MenuBarPtr(this), PreferredSizeFieldMask);
    }
    
	getInsideInsetsBounds(InsetsTopLeft, InsetsBottomRight);
	
	//Now position and size the Items
	Real32 LeftOffset(InsetsTopLeft.x());
    for(UInt32 i(0) ; i<getChildren().size() ; ++i)
    {
        beginEditCP(getChildren()[i], SizeFieldMask | PositionFieldMask);
            getChildren()[i]->setSize(Vec2f(getChildren()[i]->getPreferredSize().x(), MaxHeight));
            getChildren()[i]->setPosition(Pnt2f(LeftOffset, InsetsTopLeft.y()));
        endEditCP(getChildren()[i], SizeFieldMask | PositionFieldMask);

        LeftOffset += getChildren()[i]->getPreferredSize().x();
    }
}

void MenuBar::updateClipBounds(void)
{
	Pnt2f TopLeft, BottomRight;
	if(getParentContainer() == NullFC)
	{
		//If I have no parent container use my bounds
		getBounds(TopLeft, BottomRight);
	}
	else
	{
		//Get the intersection of:
		     //My Bounds
		     //My Parent Containers Clip Bounds
		     //My Parent Containers Inset Bounds
        Pnt2f MyTopLeft,MyBottomRight;
        getBounds(MyTopLeft,MyBottomRight);

		//Update my Parent Container's Clip Bounds
		//Container::Ptr::dcast(getParentContainer())->updateClipBounds();

		//Get Parent Container's Clip Bounds
		Pnt2f ContainerClipTopLeft, ContainerClipBottomRight;
		InternalWindow::Ptr::dcast(getParentContainer())->getMenuBarBounds(ContainerClipTopLeft,ContainerClipBottomRight);
		
        //Parent Container's Clip Bounds are in the Parent Container's Coordinate space
        //We need to convert them to this Components Coordinate space
        ContainerClipTopLeft -= Vec2f(getPosition());
		ContainerClipBottomRight -= Vec2f(getPosition());

		//Get Parent Container's MenuBar Bounds
		Pnt2f ContainerInsetTopLeft, ContainerInsetBottomRight;
		InternalWindow::Ptr::dcast(getParentContainer())->getMenuBarBounds(ContainerInsetTopLeft, ContainerInsetBottomRight);
		
        //Parent Container's Inset Bounds are in the Parent Container's Coordinate space
        //We need to convert them to this Components Coordinate space
        ContainerInsetTopLeft -= Vec2f(getPosition());
		ContainerInsetBottomRight -= Vec2f(getPosition());

		//Get the intersection of my bounds with my parent containers clip bounds
		quadIntersection(MyTopLeft,MyBottomRight,
			ContainerClipTopLeft,ContainerClipBottomRight,
			TopLeft, BottomRight);

		quadIntersection(TopLeft,BottomRight,
			ContainerInsetTopLeft,ContainerInsetBottomRight,
			TopLeft, BottomRight);
	}
	//The Clip Bounds calculated are in my Parent Containers coordinate space
	//Translate these bounds into my own coordinate space
	beginEditCP(ComponentPtr(this), Component::ClipBoundsFieldMask);
		setClipTopLeft(TopLeft);
		setClipBottomRight(BottomRight);
	endEditCP(ComponentPtr(this), Component::ClipBoundsFieldMask);
}

void MenuBar::addMenu(MenuPtr Menu)
{
    beginEditCP(MenuBarPtr(this), ChildrenFieldMask);
        getChildren().push_back(Menu);
    endEditCP(MenuBarPtr(this), ChildrenFieldMask);
    beginEditCP(Menu, Menu::TopLevelMenuFieldMask);
        Menu->setTopLevelMenu(true);
    endEditCP(Menu, Menu::TopLevelMenuFieldMask);
    Menu->getInternalPopupMenu()->addPopupMenuListener(&_MenuSelectionListener);
}

void MenuBar::addMenu(MenuPtr Menu, const UInt32& Index)
{
    if(Index < getChildren().size())
    {
        MFComponentPtr::iterator Itor;
        for(UInt32 i(0) ; i<Index ; ++i){++Itor;}
        beginEditCP(MenuBarPtr(this), ChildrenFieldMask);
            getChildren().insert(Itor, Menu);
        endEditCP(MenuBarPtr(this), ChildrenFieldMask);
        beginEditCP(Menu, Menu::TopLevelMenuFieldMask);
            Menu->setTopLevelMenu(true);
        endEditCP(Menu, Menu::TopLevelMenuFieldMask);
        Menu->getInternalPopupMenu()->addPopupMenuListener(&_MenuSelectionListener);
    }
}

void MenuBar::removeMenu(MenuPtr Menu)
{
    MFComponentPtr::iterator FindResult = getChildren().find(Menu);
    if(FindResult != getChildren().end())
    {
        beginEditCP(MenuBarPtr(this), ChildrenFieldMask);
            getChildren().erase(FindResult);
        endEditCP(MenuBarPtr(this), ChildrenFieldMask);
        beginEditCP(Menu, Menu::TopLevelMenuFieldMask);
            Menu->setTopLevelMenu(false);
        endEditCP(Menu, Menu::TopLevelMenuFieldMask);
        Menu->getInternalPopupMenu()->removePopupMenuListener(&_MenuSelectionListener);
    }
}

void MenuBar::removeMenu(const UInt32& Index)
{
    if(Index < getChildren().size())
    {
        MFComponentPtr::iterator Itor;
        for(UInt32 i(0) ; i<Index ; ++i){++Itor;}
        beginEditCP(MenuBarPtr(this), ChildrenFieldMask);
            getChildren().erase(Itor);
        endEditCP(MenuBarPtr(this), ChildrenFieldMask);

        beginEditCP((*Itor), Menu::TopLevelMenuFieldMask);
            Menu::Ptr::dcast( (*Itor) )->setTopLevelMenu(false);
        endEditCP((*Itor), Menu::TopLevelMenuFieldMask);
        Menu::Ptr::dcast( (*Itor) )->getInternalPopupMenu()->removePopupMenuListener(&_MenuSelectionListener);
    }
}

void MenuBar::mousePressed(const MouseEventPtr e)
{
    UInt32 i(0);
    while (i<getChildren().size())
    {
        if(getChildren()[i]->isContained(e->getLocation(), true))
        {
            getSelectionModel()->setSelectedIndex(i);
            _SelectionMouseEventConnection = getParentWindow()->getDrawingSurface()->getEventProducer()->addMouseMotionListener(&_MenuSelectionListener);
            break;
        }
        ++i;
    }
    Container::mousePressed(e);
}

void MenuBar::detachFromEventProducer(void)
{
    Inherited::detachFromEventProducer();
    _SelectionMouseEventConnection.disconnect();
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

MenuBar::MenuBar(void) :
    Inherited(),
    _MenuSelectionListener(MenuBarPtr(this))
{
}

MenuBar::MenuBar(const MenuBar &source) :
    Inherited(source),
    _MenuSelectionListener(MenuBarPtr(this))
{
    if(getSelectionModel() != NullFC)
    {
        beginEditCP(MenuBarPtr(this), MenuBar::SelectionModelFieldMask);
            setSelectionModel(SingleSelectionModel::Ptr::dcast(getSelectionModel()->shallowCopy()));
        endEditCP(MenuBarPtr(this), MenuBar::SelectionModelFieldMask);
    }
}

MenuBar::~MenuBar(void)
{
}

/*----------------------------- class specific ----------------------------*/

void MenuBar::changed(BitVector whichField, UInt32 origin)
{
    Inherited::changed(whichField, origin);

    if((whichField & ParentWindowFieldMask) && getParentWindow() != NullFC)
    {
        getParentWindow()->addKeyListener(&_MenuSelectionListener);
    }

    if(whichField & SelectionModelFieldMask && getSelectionModel() != NullFC)
    {
        getSelectionModel()->addSelectionListener(&_MenuSelectionListener);
    }
}

void MenuBar::dump(      UInt32    , 
                         const BitVector ) const
{
    SLOG << "Dump MenuBar NI" << std::endl;
}

void MenuBar::MenuSelectionListener::selectionChanged(const SelectionEventPtr e)
{
    for(UInt32 i(0) ; i<e->getMFPreviouslySelected()->size() ; ++i)
    {
        if(MenuItem::Ptr::dcast(_MenuBar->getChildren()[e->getPreviouslySelected(i)])->getSelected())
        {
            beginEditCP(_MenuBar->getChildren()[e->getPreviouslySelected(i)], MenuItem::SelectedFieldMask);
                MenuItem::Ptr::dcast(_MenuBar->getChildren()[e->getPreviouslySelected(i)])->setSelected(false);
            endEditCP(_MenuBar->getChildren()[e->getPreviouslySelected(i)], MenuItem::SelectedFieldMask);
        }
    }

    for(UInt32 i(0) ; i<e->getMFSelected()->size() ; ++i)
    {
        if(!MenuItem::Ptr::dcast(_MenuBar->getChildren()[e->getSelected(i)])->getSelected())
        {
            beginEditCP(_MenuBar->getChildren()[e->getSelected(i)], MenuItem::SelectedFieldMask);
                MenuItem::Ptr::dcast(_MenuBar->getChildren()[e->getSelected(i)])->setSelected(true);
            endEditCP(_MenuBar->getChildren()[e->getSelected(i)], MenuItem::SelectedFieldMask);
        }
    }
}

void MenuBar::MenuSelectionListener::mouseMoved(const MouseEventPtr e)
{
    UInt32 i(0);
    while (i<_MenuBar->getChildren().size())
    {
        if(_MenuBar->getChildren()[i]->isContained(e->getLocation(), true))
        {
            _MenuBar->getSelectionModel()->setSelectedIndex(i);
            break;
        }
        ++i;
    }
}

void MenuBar::MenuSelectionListener::mouseDragged(const MouseEventPtr e)
{
    UInt32 i(0);
    while (i<_MenuBar->getChildren().size())
    {
        if(_MenuBar->getChildren()[i]->isContained(e->getLocation(), true))
        {
            _MenuBar->getSelectionModel()->setSelectedIndex(i);
            break;
        }
        ++i;
    }
}

void MenuBar::MenuSelectionListener::popupMenuCanceled(const PopupMenuEventPtr e)
{
	if(_MenuBar->getParentWindow()->getDrawingSurface()->getEventProducer() != NullFC)
	{
		_MenuBar->getParentWindow()->getDrawingSurface()->getEventProducer()->removeMouseMotionListener(this);
	}
    
    _MenuBar->getSelectionModel()->clearSelection();
}

void MenuBar::MenuSelectionListener::popupMenuWillBecomeInvisible(const PopupMenuEventPtr e)
{
    //Do Nothing
}

void MenuBar::MenuSelectionListener::popupMenuWillBecomeVisible(const PopupMenuEventPtr e)
{
    //Do Nothing
}

void MenuBar::MenuSelectionListener::popupMenuContentsChanged(const PopupMenuEventPtr e)
{
    //Do Nothing
}

void MenuBar::MenuSelectionListener::keyTyped(const KeyEventPtr e)
{
    //UInt32 RelevantModifiers = (e->getModifiers() & KeyEvent::KEY_MODIFIER_ALT) |
    //                           (e->getModifiers() & KeyEvent::KEY_MODIFIER_CONTROL) |
    //                           (e->getModifiers() & KeyEvent::KEY_MODIFIER_SHIFT) |
    //                           (e->getModifiers() & KeyEvent::KEY_MODIFIER_META);

    if(e->getModifiers() & KeyEvent::KEY_MODIFIER_ALT)
    {
        for(UInt32 i(0) ; i<_MenuBar->getChildren().size() ; ++i)
        {
            if(MenuItem::Ptr::dcast(_MenuBar->getChildren()[i])->getMnemonicKey() == e->getKey() )
            {
                std::cout << e->getKeyChar() << std::endl;
            }
        }
    }
}

/*------------------------------------------------------------------------*/
/*                              cvs id's                                  */

#ifdef OSG_SGI_CC
#pragma set woff 1174
#endif

#ifdef OSG_LINUX_ICC
#pragma warning( disable : 177 )
#endif

namespace
{
    static Char8 cvsid_cpp       [] = "@(#)$Id: FCTemplate_cpp.h,v 1.20 2006/03/16 17:01:53 dirk Exp $";
    static Char8 cvsid_hpp       [] = OSGMENUBARBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGMENUBARBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGMENUBARFIELDS_HEADER_CVSID;
}

#ifdef __sgi
#pragma reset woff 1174
#endif

OSG_END_NAMESPACE
