/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 * contact: Achyuthan Vasanth (vasanth.achyuthan@gmail.com)                  *
 *          David Kabala (djkabala@gmail.com)                                *
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

#include <cstdlib>
#include <cstdio>

//#define OSG_COMPILECONTRIBTEXTDOMLIB

#include <OSGConfig.h>

#include "OSGTextEditor.h"

#include "OSGDocument.h"
#include "OSGAdvancedTextDomArea.h"
#include "OSGUIDrawingSurface.h"
#include "OSGSearchWindow.h"
#include "OSGList.h"
#include "OSGDefaultListModel.h"
#include "OSGScrollPanel.h"
#include "OSGSplitPanel.h"
#include "OSGTabPanel.h"
#include "OSGTextArea.h"
#include "OSGTextDomArea.h"
#include "OSGSpringLayout.h"
#include "OSGSpringLayoutConstraints.h"
#include "OSGBorderLayout.h"
#include "OSGBorderLayoutConstraints.h"
#include "OSGDefaultListSelectionModel.h"
#include "OSGTextDomLayoutManager.h"
#include "OSGTextDomArea.h"
#include "OSGGlyphView.h"

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/convenience.hpp>
#include <boost/algorithm/string.hpp>

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGTextEditorBase.cpp file.
// To modify it, please change the .fcd file (OSGTextEditor.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void TextEditor::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
    }
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

void TextEditor::keyTyped(KeyEventDetails* const details)
{
    if(details->getModifiers() & KeyEventDetails::KEY_MODIFIER_COMMAND)
    {
        switch(details->getKey())
        {
            case KeyEventDetails::KEY_F:
                if(_SearchDialog == NULL)
                {
                    _SearchDialog = SearchWindow::create("Search Window");
                    _SearchDialog->setIconable(false);
                    _SearchDialog->setAllwaysOnTop(true);
                    _SearchButtonClickedConnection = _SearchDialog->connectSearchButtonClicked(boost::bind(&TextEditor::handleSearchButtonClicked, this, _1));
                    _ReplaceButtonClickedConnection = _SearchDialog->connectReplaceButtonClicked(boost::bind(&TextEditor::handleReplaceButtonClicked, this, _1));
                    _ReplaceAllButtonClickedConnection = _SearchDialog->connectReplaceAllButtonClicked(boost::bind(&TextEditor::handleReplaceAllButtonClicked, this, _1));
                    _BookmarkAllButtonClickedConnection = _SearchDialog->connectBookmarkAllButtonClicked(boost::bind(&TextEditor::handleBookmarkAllButtonClicked, this, _1));

                    _SearchDialog->setPosition(getParentWindow()->getPosition());
                    getParentWindow()->getParentDrawingSurface()->openWindow(_SearchDialog);
                }

                if(!_SearchDialog->isOpen())
                {
                    getParentWindow()->getParentDrawingSurface()->openWindow(_SearchDialog);
                }
                else
                {
                    //getParentWindow()->setFocused(false);
                    //_SearchDialog->setFocused(true);
                    //_SearchDialog->takeFocus();
                    //getParentWindow()->giveFocus(_SearchDialog);
                }
                break;
            case KeyEventDetails::KEY_C:
                std::string theClipboard = getParentWindow()->getParentDrawingSurface()->getEventProducer()->getClipboard();
                _TheClipboardListModel->pushBack(boost::any(theClipboard));
                break;
        }
    }
}

void TextEditor::mouseClicked(MouseEventDetails* const details)
{

    //TODO Move this to a FocusEvent connection
    if(getParentWindow()->getFocusedComponent()->getType().isDerivedFrom(TextDomArea::getClassType()))
    {
        setFocusedDomArea(dynamic_cast<TextDomArea*>(this->getParentWindow()->getFocusedComponent()));
    }

    Inherited::mouseClicked(details);
}

void TextEditor::handleSearchButtonClicked(SearchWindowEventDetails* const details)
{
    searchWindowButtonClicked(details,SEARCH);
}

void TextEditor::handleReplaceButtonClicked(SearchWindowEventDetails* const details)
{
    searchWindowButtonClicked(details,REPLACE);
}

void TextEditor::handleReplaceAllButtonClicked(SearchWindowEventDetails* const details)
{
    searchWindowButtonClicked(details,REPLACE_ALL);
}

void TextEditor::handleBookmarkAllButtonClicked(SearchWindowEventDetails* const details)
{
    searchWindowButtonClicked(details,BOOKMARK_ALL);
}


void TextEditor::searchWindowButtonClicked(SearchWindowEventDetails* const details,UInt32 button)
{
    SearchWindowRefPtr theSearchWindow = dynamic_cast<SearchWindow*>(details->getSource());

    if(theSearchWindow)
    {
        TextDomAreaRefPtr theFocussedDomArea = getFocusedDomArea();

        if(theFocussedDomArea)
        {
            switch(button)
            {
                case SEARCH: 
                    theFocussedDomArea->searchForStringInDocumentUsingRegEx(theSearchWindow->getSearchText(),
                                                                            theSearchWindow->isCaseChecked(),
                                                                            theSearchWindow->isWholeWordChecked(),
                                                                            theSearchWindow->isSearchUpChecked(),
                                                                            theSearchWindow->isWrapAroundChecked(),
                                                                            theSearchWindow->isUseRegExChecked());
                    break;
                case REPLACE:
                    theFocussedDomArea->handlePastingAString(theSearchWindow->getReplaceText());
                    break;
                case REPLACE_ALL:
                    theFocussedDomArea->replaceAllUsingRegEx(theSearchWindow->getSearchText(),
                                                             theSearchWindow->getReplaceText(),
                                                             theSearchWindow->isCaseChecked(),
                                                             theSearchWindow->isWholeWordChecked(),
                                                             theSearchWindow->isUseRegExChecked());
                    break;
                case BOOKMARK_ALL:
                    theFocussedDomArea->editMFBookmarkedLines()->clear();
                    theFocussedDomArea->bookmarkAllUsingRegEx(theSearchWindow->getSearchText(),
                                                              theSearchWindow->isCaseChecked(),
                                                              theSearchWindow->isWholeWordChecked(),
                                                              theSearchWindow->isUseRegExChecked());
                    break;
            }
        }
    }
}


void TextEditor::saveFile(const BoostPath& file) const
{
    TextDomAreaRefPtr theFocussedDomArea = getFocusedDomArea();
    theFocussedDomArea->saveFile(file);
}

void TextEditor::handleCloseButtonAction(ActionEventDetails* const details)
{
    Button* _TempCloseButton = dynamic_cast<Button*>(details->getSource());
    Panel* _TempPanel = dynamic_cast<Panel*>(_TempCloseButton->getParentContainer());
    TabPanel* _TempTabPanel = dynamic_cast<TabPanel*>(_TempPanel->getParentContainer());
    UInt32 _ChildIndex = (_TempTabPanel->getChildIndex(_TempPanel))/2;

    _LeftTabPanel->removeTab(_ChildIndex);

    _RightTabPanel->removeTab(_ChildIndex);
}

void TextEditor::handleClipboardButtonAction(ActionEventDetails* const details)
{
    TextDomAreaRefPtr tempDomArea = getFocusedDomArea();
    if(tempDomArea == NULL) return;
    std::string stringToBeInserted = boost::any_cast<std::string>(_TheClipboardList->getSelectedItem());
    tempDomArea->handlePastingAString(stringToBeInserted);
}

void TextEditor::createTabPanels(void)
{
    ComponentRecPtr LeftTabPanelLabel = createTabLabel("Untitled");

    // Create a _StackTraceTextArea
    AdvancedTextDomAreaRecPtr LeftTabPanelTextArea = AdvancedTextDomArea::create();
    setFocusedDomArea(LeftTabPanelTextArea->getTextDomArea());

    ComponentRecPtr RightTabPanelLabel = createTabLabel("Untitled");

    // Create a _StackTraceTextArea
    AdvancedTextDomAreaRecPtr RightTabPanelTextArea = createDuplicate(LeftTabPanelTextArea);

    BorderLayoutConstraintsRefPtr ExampleSplitPanelConstraints = BorderLayoutConstraints::create();
    ExampleSplitPanelConstraints->setRegion(BorderLayoutConstraints::BORDER_CENTER);

    LeftTabPanelTextArea->setText(" \r\n");
    _LeftTabPanel= TabPanel::create();
    _LeftTabPanel->addTab(LeftTabPanelLabel, LeftTabPanelTextArea);
    _LeftTabPanel->setTabAlignment(0.0f);
    _LeftTabPanel->setTabPlacement(TabPanel::PLACEMENT_NORTH);
    _LeftTabPanel->setSelectedIndex(0);
    _LeftTabPanel->setConstraints(ExampleSplitPanelConstraints);

    _RightTabPanel= TabPanel::create();
    _RightTabPanel->addTab(RightTabPanelLabel, RightTabPanelTextArea);
    _RightTabPanel->setTabAlignment(0.0f);
    _RightTabPanel->setTabPlacement(TabPanel::PLACEMENT_NORTH);
    _RightTabPanel->setSelectedIndex(0);
}

void TextEditor::updateArrangment(void)
{
    clearChildren();
    _DomAreaAndClipboard->setMinComponent(NULL);
    _InsideDomArea->setMinComponent(NULL);

    if(getClipboardVisible())
    {
        pushToChildren(_DomAreaAndClipboard);

        if(getIsSplit())
        {
            _DomAreaAndClipboard->setMinComponent(_InsideDomArea);
            _InsideDomArea->setMinComponent(_LeftTabPanel);
        }
        else
        {
            _DomAreaAndClipboard->setMinComponent(_LeftTabPanel);
        }
    }
    else
    {
        if(getIsSplit())
        {
            pushToChildren(_InsideDomArea);
            _InsideDomArea->setMinComponent(_LeftTabPanel);
        }
        else
        {
            pushToChildren(_LeftTabPanel);
        }
    }
}

AdvancedTextDomAreaTransitPtr TextEditor::createDuplicate(AdvancedTextDomArea* const TheAdvancedTextDomArea)
{
    return AdvancedTextDomAreaTransitPtr(TheAdvancedTextDomArea->createDuplicate());
}

ComponentTransitPtr TextEditor::createTabLabel(const std::string& LabelText)
{
    PanelRefPtr NewTabLabelPanel = Panel::createEmpty();

    ButtonRefPtr NewTabLabelCloseButton =
        dynamic_pointer_cast<Button>(dynamic_cast<InternalWindow*>(InternalWindow::getClassType().getPrototype())->getTitlebar()->getCloseButton()->shallowCopy());

    NewTabLabelCloseButton->connectActionPerformed(boost::bind(&TextEditor::handleCloseButtonAction, this, _1));

    LabelRefPtr NewTabLabelLabel=Label::create();
    NewTabLabelLabel->setText(LabelText);
    NewTabLabelLabel->setBorders(NULL);
    NewTabLabelLabel->setBackgrounds(NULL);

    SpringLayoutRefPtr NewTabLabelPanelSpringLayout = SpringLayout::create();

    NewTabLabelPanelSpringLayout->putConstraint(SpringLayoutConstraints::VERTICAL_CENTER_EDGE, NewTabLabelCloseButton, 0, SpringLayoutConstraints::VERTICAL_CENTER_EDGE, NewTabLabelPanel);  
    NewTabLabelPanelSpringLayout->putConstraint(SpringLayoutConstraints::EAST_EDGE, NewTabLabelCloseButton, -2, SpringLayoutConstraints::EAST_EDGE, NewTabLabelPanel);

    NewTabLabelPanelSpringLayout->putConstraint(SpringLayoutConstraints::NORTH_EDGE, NewTabLabelLabel, 2, SpringLayoutConstraints::NORTH_EDGE, NewTabLabelPanel);  
    NewTabLabelPanelSpringLayout->putConstraint(SpringLayoutConstraints::EAST_EDGE, NewTabLabelLabel, -5, SpringLayoutConstraints::WEST_EDGE, NewTabLabelCloseButton);
    NewTabLabelPanelSpringLayout->putConstraint(SpringLayoutConstraints::WEST_EDGE, NewTabLabelLabel, 2, SpringLayoutConstraints::WEST_EDGE, NewTabLabelPanel);
    NewTabLabelPanelSpringLayout->putConstraint(SpringLayoutConstraints::SOUTH_EDGE, NewTabLabelLabel, -2, SpringLayoutConstraints::SOUTH_EDGE, NewTabLabelPanel);

    NewTabLabelPanel->setPreferredSize(Vec2f(120,20));
    NewTabLabelPanel->pushToChildren(NewTabLabelLabel);
    NewTabLabelPanel->pushToChildren(NewTabLabelCloseButton);
    NewTabLabelPanel->setLayout(NewTabLabelPanelSpringLayout);

    return ComponentTransitPtr(NewTabLabelPanel);
}

void TextEditor::loadFile(const BoostPath& file)
{
    if(boost::filesystem::exists(file))
    {
        ComponentRecPtr NewLeftTabLabelPanel = createTabLabel(file.leaf());

        // Create a TextDomArea component
        UIFontRefPtr _Font = UIFont::create();
        _Font->setFamily("SANS");
        _Font->setGap(3);
        _Font->setGlyphPixelSize(46);
        _Font->setSize(15);
        _Font->setTextureWidth(0);
        _Font->setStyle(TextFace::STYLE_PLAIN);

        AdvancedTextDomAreaRefPtr ExampleTextDomArea = AdvancedTextDomArea::create();
        ExampleTextDomArea->loadFile(file);
        setFocusedDomArea(ExampleTextDomArea->getTextDomArea());//***************************************
        /*ExampleTextDomArea->setWrapStyleWord(false);
          ExampleTextDomArea->setFont(_Font);*/

        ComponentRecPtr NewRightTabLabelPanel = createTabLabel(file.leaf());

        AdvancedTextDomAreaRefPtr ExampleTextDomArea2 =  createDuplicate(ExampleTextDomArea);///*dynamic_pointer_cast<AdvancedTextDomArea>(deepClone(ExampleTextDomArea));*/AdvancedTextDomArea::create();

        _LeftTabPanel->addTab(NewLeftTabLabelPanel, ExampleTextDomArea);
        _LeftTabPanel->setSelectedIndex((_LeftTabPanel->getMFTabs()->size())-1);
        _RightTabPanel->addTab(NewRightTabLabelPanel, ExampleTextDomArea2);
        _RightTabPanel->setSelectedIndex((_RightTabPanel->getMFTabs()->size())-1);
    }
}

void TextEditor::setText(const std::string& txt)
{
    if(getFocusedDomArea() != NULL)
        getFocusedDomArea()->setText(txt);
}

void TextEditor::clear(void) 
{
    if(getFocusedDomArea() != NULL)
        getFocusedDomArea()->clear();
}

void TextEditor::write(const std::string& txt) 
{
    if(getFocusedDomArea() != NULL)
        getFocusedDomArea()->write(txt);
}

std::string TextEditor::getText(void) const
{
    if(getFocusedDomArea() != NULL)
        return getFocusedDomArea()->getText();
    else 
        return "";
}

void TextEditor::setEditable(bool val)
{
    if(getFocusedDomArea() != NULL)
        getFocusedDomArea()->setEditable(val);
}

void TextEditor::setEnabled(bool val)
{
    if(getFocusedDomArea() != NULL)
        getFocusedDomArea()->setEnabled(val);
}

void TextEditor::createDomArea(void)
{
    createTabPanels();

    BorderLayoutConstraintsRefPtr ExampleSplitPanelConstraints2 = BorderLayoutConstraints::create();
    ExampleSplitPanelConstraints2->setRegion(BorderLayoutConstraints::BORDER_CENTER);

    _InsideDomArea = SplitPanel::create();

    _InsideDomArea->setConstraints(ExampleSplitPanelConstraints2);
    _InsideDomArea->setExpandable(true);
    _InsideDomArea->setDividerSize(2);
    _InsideDomArea->setOrientation(SplitPanel::HORIZONTAL_ORIENTATION);
    _InsideDomArea->setDividerPosition(.50); 
    _InsideDomArea->setMaxDividerPosition(.85);
    _InsideDomArea->setMinDividerPosition(.15);
    _InsideDomArea->setMaxComponent(_RightTabPanel);
}

void TextEditor::clipboardInitialization()
{
    BorderLayoutRefPtr MainInternalWindowLayout = BorderLayout::create();

    BorderLayoutConstraintsRefPtr ClipboardLabelConstraints = BorderLayoutConstraints::create();
    BorderLayoutConstraintsRefPtr ClipboardPanelConstraints = BorderLayoutConstraints::create();
    BorderLayoutConstraintsRefPtr ClipboardButtonConstraints = BorderLayoutConstraints::create();

    ClipboardLabelConstraints->setRegion(BorderLayoutConstraints::BORDER_NORTH);
    ClipboardPanelConstraints->setRegion(BorderLayoutConstraints::BORDER_CENTER);
    ClipboardButtonConstraints->setRegion(BorderLayoutConstraints::BORDER_SOUTH);

    _TheClipboardPanel = Panel::create();

    // the Clipboard label
    _TheClipboardLabel = Label::create();
    _TheClipboardLabel->setText("Copy Clipboard");
    _TheClipboardLabel->setTextColor(Color4f(0.3, 0.3, 0.3, 1.0));
    _TheClipboardLabel->setAlignment(Vec2f(0.5,0.5));
    _TheClipboardLabel->setPreferredSize(Vec2f(200, 20));
    _TheClipboardLabel->setTextSelectable(false);
    _TheClipboardLabel->setConstraints(ClipboardLabelConstraints);

    _TheClipboardButton = Button::create();
    _TheClipboardButton->setText("Insert Into Document");
    _TheClipboardButton->setMinSize(_TheClipboardButton->getPreferredSize());
    _TheClipboardButton->setPreferredSize(_TheClipboardButton->getRequestedSize());
    _ClipboardButtonActionConnection.disconnect();
    _ClipboardButtonActionConnection = _TheClipboardButton->connectActionPerformed(boost::bind(&TextEditor::handleClipboardButtonAction, this, _1));
    _TheClipboardButton->setConstraints(ClipboardButtonConstraints);

    _TheClipboardListModel = DefaultListModel::create();
    //_TheClipboardListModel->pushBack(boost::any(std::string("Red")));

    _TheClipboardList = List::create();
    _TheClipboardList->setPreferredSize(Vec2f(200, 400));
    _TheClipboardList->setOrientation(List::VERTICAL_ORIENTATION);
    _TheClipboardList->setModel(_TheClipboardListModel);

    _TheClipboardScrollPanel = ScrollPanel::create();
    _TheClipboardScrollPanel->setPreferredSize(Vec2f(200,400));
    _TheClipboardScrollPanel->setHorizontalResizePolicy(ScrollPanel::RESIZE_TO_VIEW);
    _TheClipboardScrollPanel->setViewComponent(_TheClipboardList);
    _TheClipboardScrollPanel->setConstraints(ClipboardPanelConstraints);

    _TheClipboardPanel->pushToChildren(_TheClipboardLabel);
    _TheClipboardPanel->pushToChildren(_TheClipboardScrollPanel);
    _TheClipboardPanel->pushToChildren(_TheClipboardButton);
    _TheClipboardPanel->setLayout(/*LayoutRefPtr(FlowLayout::create())*/MainInternalWindowLayout/*_TheClipboardPanelLayout*/);
    _TheClipboardPanel->setPreferredSize(Vec2f(200, 400));
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

void TextEditor::onCreate(const TextEditor *source)
{

    if(source == NULL)
    {
        return;
    }

    _DomAreaAndClipboard = SplitPanel::create();

    createDomArea();
    clipboardInitialization();

    BorderLayoutRefPtr EditorLayout = BorderLayout::create();
    setLayout(EditorLayout);

    BorderLayoutConstraintsRefPtr ExampleSplitPanelConstraints = BorderLayoutConstraints::create();
    ExampleSplitPanelConstraints->setRegion(BorderLayoutConstraints::BORDER_CENTER);

    _DomAreaAndClipboard->setConstraints(ExampleSplitPanelConstraints);
    _DomAreaAndClipboard->setExpandable(true);
    _DomAreaAndClipboard->setDividerSize(2);
    _DomAreaAndClipboard->setDividerPosition(0.75);
    _DomAreaAndClipboard->setMaxDividerPosition(.9);
    _DomAreaAndClipboard->setMinDividerPosition(0.5);
    _DomAreaAndClipboard->setOrientation(SplitPanel::HORIZONTAL_ORIENTATION);
    _DomAreaAndClipboard->setMaxComponent(_TheClipboardPanel);
}

void TextEditor::resolveLinks(void)
{
    Inherited::resolveLinks();

    _DomAreaAndClipboard = NULL;
    _InsideDomArea = NULL;
    _TheClipboardList = NULL;
    _TheClipboardListModel = NULL;
    _TheClipboardScrollPanel = NULL;
    _TheClipboardLabel = NULL;
    _TheClipboardPanel = NULL;
    _TheClipboardPanelLayout = NULL;
    _TheClipboardButton = NULL;
    _LeftTabPanel = NULL;
    _RightTabPanel = NULL;
    _SearchDialog = NULL;

    _SearchButtonClickedConnection.disconnect();
    _ReplaceButtonClickedConnection.disconnect();
    _ReplaceAllButtonClickedConnection.disconnect();
    _BookmarkAllButtonClickedConnection.disconnect();
    _ClipboardButtonActionConnection.disconnect();
    _CloseButtonActionConnection.disconnect();
}

/*----------------------- constructors & destructors ----------------------*/

TextEditor::TextEditor(void) :
    Inherited()
{
}

TextEditor::TextEditor(const TextEditor &source) :
    Inherited(source)
{
}

TextEditor::~TextEditor(void)
{
}

/*----------------------------- class specific ----------------------------*/

void TextEditor::changed(ConstFieldMaskArg whichField, 
                            UInt32            origin,
                            BitVector         details)
{
    Inherited::changed(whichField, origin, details);

    //Do not respond to changes that have a Sync origin
    if(origin & ChangedOrigin::Sync)
    {
        return;
    }

    if(whichField & ClipboardVisibleFieldMask ||
       whichField & IsSplitFieldMask)
    {
        updateArrangment();
    }
}

void TextEditor::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump TextEditor NI" << std::endl;
}

OSG_END_NAMESPACE
