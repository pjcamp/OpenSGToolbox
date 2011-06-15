// OpenSG Tutorial Example: Creating a Button Component
//
// This tutorial explains how to edit the basic features of
// a Button and a ToggleButtoncreated in the OSG User 
// Interface library.
// 
// Includes: Button PreferredSize, MaximumSize, MinimumSize, Font,
// Text,and adding a Button to a Scene.  Also note that clicking
// the Button causes it to appear pressed


// General OpenSG configuration, needed everywhere
#include "OSGConfig.h"

// Methods to create simple geometry: boxes, spheres, tori etc.
#include "OSGSimpleGeometry.h"

// A little helper to simplify scene management and interaction
#include "OSGSimpleSceneManager.h"
#include "OSGNode.h"
#include "OSGGroup.h"
#include "OSGViewport.h"

// The general scene file loading handler
#include "OSGSceneFileHandler.h"

// Input
#include "OSGWindowUtils.h"

//Text Foreground
#include "OSGSimpleTextForeground.h"

//Animation
#include "OSGKeyframeSequences.h"
#include "OSGKeyframeAnimator.h"
#include "OSGFieldAnimation.h"

// UserInterface Headers
#include "OSGUIForeground.h"
#include "OSGInternalWindow.h"
#include "OSGUIDrawingSurface.h"
#include "OSGGraphics2D.h"
#include "OSGLookAndFeelManager.h"
#include "OSGTabPanel.h"

#include "OSGButton.h"
#include "OSGLabel.h"
#include "OSGLayers.h"
#include "OSGBorders.h"
#include "OSGFlowLayout.h"
#include "OSGList.h"
#include "OSGDefaultListModel.h"
#include "OSGDefaultListSelectionModel.h"
#include "OSGScrollPanel.h"

#include "OSGUndoableCommand.h"
#include "OSGCommandManager.h"
#include "OSGUndoManager.h"
#include "OSGSysFieldTraits.h"
#include "OSGList.h"
#include "OSGMFieldListModel.h"
#include "OSGDefaultListSelectionModel.h"
#include "OSGGradientBackground.h"
#include "OSGPopupMenu.h"
#include "OSGDialogWindow.h"
#include "OSGUIDrawUtils.h"
#include "OSGFunctorListComponentGenerator.h"
#include "OSGNameAttachment.h"

#include "OSGCompoundUndoableCommand.h"
#include "OSGSetFieldValueCommand.h"
#include "OSGAddFieldElementCommand.h"
#include "OSGInsertFieldElementCommand.h"
#include "OSGMoveFieldElementCommand.h"
#include "OSGSwapFieldElementCommand.h"
#include "OSGRemoveFieldElementCommand.h"
#include "OSGCreateFieldContainerCommand.h"
#include "OSGRandomPoolManager.h"

#include <sstream>
#include <boost/lexical_cast.hpp>

// Activate the OpenSG namespace
OSG_USING_NAMESPACE

// The SimpleSceneManager to manage simple applications

UndoManagerPtr TheUndoManager;
CommandManagerPtr TheCommandManager;
GradientBackgroundRecPtr TutorialBackground;
ListRecPtr MultiFieldList;
MFieldListModelRecPtr MultiFieldListModel;
ListRecPtr MultiPtrFieldList;
MFieldListModelRecPtr MultiPtrFieldListModel;
PanelRecPtr MultiPtrFieldInnerPanel;

PanelRecPtr createSingleFieldPanel(void);
PanelRecPtr createMultiFieldPanel(void);
PanelRecPtr createSinglePtrFieldPanel(void);
PanelRecPtr createMultiPtrFieldPanel(void);

// Forward declaration so we can have the interesting stuff upfront
void display(SimpleSceneManager *mgr);
void reshape(Vec2f Size, SimpleSceneManager *mgr);

//Ctrl+q handler
void keyTyped(KeyEventDetails* const details)
{
    if(details->getKey() == KeyEventDetails::KEY_Q && details->getModifiers() &
       KeyEventDetails::KEY_MODIFIER_COMMAND)
    {
        dynamic_cast<WindowEventProducer*>(details->getSource())->closeWindow();
    }
}

    /******************************************************

         Create an connection to display text
         in the Console Window when the Button is
         pressed (causing an action).

    ******************************************************/

void handleSetBorderColorAction(ActionEventDetails* const details,
                                Color4f newColor,
                                Border* const theBorder)
{
    std::ostringstream StrStream;
    operator<<(StrStream, newColor);
    SetFieldValueCommandPtr TheCommand = SetFieldValueCommand::create(theBorder,LineBorder::ColorFieldId, StrStream.str());

    TheCommandManager->executeCommand(TheCommand);
}

void handleSetBackgroundColorActionPerformed(ActionEventDetails* const details,
                                Color4f newColor,
                                Layer* const theBackground)
{
    std::ostringstream StrStream;
    operator<<(StrStream, newColor);
    SetFieldValueCommandPtr TheCommand = SetFieldValueCommand::create(theBackground,ColorLayer::ColorFieldId, StrStream.str());

    TheCommandManager->executeCommand(TheCommand);
}

void handleUndoButtonAction(ActionEventDetails* const details)
{
    TheUndoManager->undo();
}

void handleRedoButtonActionPerformed(ActionEventDetails* const details)
{
    TheUndoManager->redo();
}

void handleUndoManagerStateChanged(ChangeEventDetails* const details,
                                   Button* const undoButton,
                                   Button* const redoButton,
                                   DefaultListModel* const undoRedoListModel)
{
    while(undoRedoListModel->getSize()-1 > TheUndoManager->numberOfRedos() + TheUndoManager->numberOfUndos())
    {
        undoRedoListModel->popBack();
    }

    //Resize
    while(undoRedoListModel->getSize()-1 < TheUndoManager->numberOfRedos() + TheUndoManager->numberOfUndos())
    {
        undoRedoListModel->pushBack(boost::any(std::string("")));
    }

    UInt32 UndoCount(TheUndoManager->numberOfUndos());
    for(UInt32 i(0) ; i<UndoCount ; ++i)
    {
        undoRedoListModel->set(i+1, boost::any(std::string(TheUndoManager->editToBeUndone(i)->getUndoPresentationName())));
    }
    UInt32 RedoCount(TheUndoManager->numberOfRedos());
    for(UInt32 i(0) ; i<RedoCount ; ++i)
    {
        undoRedoListModel->set(i+TheUndoManager->numberOfUndos()+1, boost::any(std::string(TheUndoManager->editToBeRedone(i)->getRedoPresentationName())));
    }

    if((UndoCount == 0 && undoButton->getEnabled()) ||
        (UndoCount != 0 && !undoButton->getEnabled()) )
    {
            undoButton->setEnabled(UndoCount != 0);
    }
    if((RedoCount == 0 && redoButton->getEnabled()) ||
        (RedoCount != 0 && !redoButton->getEnabled()) )
    {
            redoButton->setEnabled(RedoCount != 0);
    }
}

// Setup a FontListener to change the label's font
// when a different item in the FontList is
// selected
void handleUndoRedoListSelectionChanged(ListSelectionEventDetails* const details)
{
    if(!dynamic_cast<ListSelectionModel*>(details->getSource())->isSelectionEmpty())
    {
        Int32 ListSelectedIndex(dynamic_cast<ListSelectionModel*>(details->getSource())->getAnchorSelectionIndex());

        TheUndoManager->undoOrRedoTo(ListSelectedIndex);
    }
}

class SimpleScreenDoc
{
  public:
    SimpleScreenDoc(SimpleSceneManager*  SceneManager,
                    WindowEventProducer* MainWindow);

  private:
    SimpleTextForegroundRecPtr _DocForeground;
    SimpleTextForegroundRecPtr _DocShowForeground;
    FieldAnimationRecPtr _ShowDocFadeOutAnimation;

    SimpleScreenDoc(void);
    SimpleScreenDoc(const SimpleScreenDoc& );

    SimpleTextForegroundTransitPtr makeDocForeground(void);
    SimpleTextForegroundTransitPtr makeDocShowForeground(void);

    void keyTyped(KeyEventDetails* const details);
};

/******************************************************

  Documentation Foreground

 ******************************************************/
SimpleTextForegroundTransitPtr SimpleScreenDoc::makeDocForeground(void)
{
    SimpleTextForegroundRecPtr DocForeground =  SimpleTextForeground::create(); 

    DocForeground->addLine("This tutorial is a simple demonstration of the use");
    DocForeground->addLine("of \\{\\color=AAAA00FF SetFieldValueCommand}, \\{\\color=AAAA00FF AddFieldElementCommand},");
    DocForeground->addLine("\\{\\color=AAAA00FF CreateFieldContainerCommand}, \\{\\color=AAAA00FF InsertFieldElementCommand},");
    DocForeground->addLine("\\{\\color=AAAA00FF MoveFieldElementCommand}, \\{\\color=AAAA00FF RemoveFieldElementCommand},");
    DocForeground->addLine("\\{\\color=AAAA00FF SetFieldValueCommand}, and \\{\\color=AAAA00FF SwapFieldElementCommand}");

    DocForeground->addLine("");
    DocForeground->addLine("\\{\\color=AAAAAAFF Key Controls}:");
    DocForeground->addLine("     \\{\\color=AAAAFFFF Cmd+q}: Close the application");
    DocForeground->addLine("         \\{\\color=AAAAFFFF ?}: Show/hide this documentation");

    return SimpleTextForegroundTransitPtr(DocForeground);
}

int main(int argc, char **argv)
{
    // OSG init
    osgInit(argc,argv);
    {
        // Set up Window
        WindowEventProducerRecPtr TutorialWindow = createNativeWindow();
        TutorialWindow->initWindow();

        // Create the SimpleSceneManager helper
        SimpleSceneManager sceneManager;
        TutorialWindow->setDisplayCallback(boost::bind(display, &sceneManager));
        TutorialWindow->setReshapeCallback(boost::bind(reshape, _1, &sceneManager));

        // Tell the Manager what to manage
        sceneManager.setWindow(TutorialWindow);

        TutorialWindow->connectKeyTyped(boost::bind(keyTyped, _1));

        // Make Torus Node (creates Torus in background of scene)
        NodeRecPtr TorusGeometryNode = makeTorus(.5, 2, 16, 16);

        // Make Main Scene Node and add the Torus
        NodeRecPtr scene = Node::create();
            scene->setCore(Group::create());
            scene->addChild(TorusGeometryNode);

        // Create the Graphics
        GraphicsRecPtr TutorialGraphics = Graphics2D::create();

        // Initialize the LookAndFeelManager to enable default settings
        LookAndFeelManager::the()->getLookAndFeel()->init();

        //UndoList
        DefaultListModelRecPtr UndoRedoListModel = DefaultListModel::create();
        UndoRedoListModel->pushBack(boost::any(std::string("Top")));

        ListRecPtr UndoRedoList = List::create();
        UndoRedoList->setPreferredSize(Vec2f(200, 300));
        UndoRedoList->setOrientation(List::VERTICAL_ORIENTATION);
        UndoRedoList->setModel(UndoRedoListModel);

        UndoRedoList->getSelectionModel()->connectSelectionChanged(boost::bind(&handleUndoRedoListSelectionChanged, _1));

        ButtonRecPtr UndoButton = Button::create();
        UndoButton->setText("Undo");
        UndoButton->setEnabled(false);
        UndoButton->connectActionPerformed(boost::bind(&handleUndoButtonAction, _1));
        

        ButtonRecPtr RedoButton = Button::create();
        RedoButton->setText("Redo");
        RedoButton->setEnabled(false);
        RedoButton->connectActionPerformed(boost::bind(&handleRedoButtonActionPerformed, _1));

        TheUndoManager = UndoManager::create();
        TheUndoManager->connectStateChanged(boost::bind(&handleUndoManagerStateChanged, _1, UndoButton.get(), RedoButton.get(), UndoRedoListModel.get()));

        //Background
        TutorialBackground = GradientBackground::create();
        TutorialBackground->addLine(Color3f(1.0,0.0,0.0), 0.0);
        TutorialBackground->addLine(Color3f(0.0,1.0,0.0), 0.2);
        TutorialBackground->addLine(Color3f(0.0,0.0,1.0), 0.4);
        TutorialBackground->addLine(Color3f(0.0,1.0,1.0), 0.6);
        TutorialBackground->addLine(Color3f(1.0,1.0,0.0), 0.8);
        TutorialBackground->addLine(Color3f(1.0,1.0,1.0), 1.0);
        
        LabelRecPtr SingleFieldLabel = Label::create();
        SingleFieldLabel->setText("Single Field");
        SingleFieldLabel->setBorders(NULL);
        SingleFieldLabel->setBackgrounds(NULL);

        LabelRecPtr MultiFieldLabel = Label::create();
        MultiFieldLabel->setText("Multi Field");
        MultiFieldLabel->setBorders(NULL);
        MultiFieldLabel->setBackgrounds(NULL);

        LabelRecPtr SinglePtrFieldLabel = Label::create();
        SinglePtrFieldLabel->setText("Single Ptr Field");
        SinglePtrFieldLabel->setBorders(NULL);
        SinglePtrFieldLabel->setBackgrounds(NULL);

        LabelRecPtr MultiPtrFieldLabel = Label::create();
        MultiPtrFieldLabel->setText("Multi Ptr Field");
        MultiPtrFieldLabel->setBorders(NULL);
        MultiPtrFieldLabel->setBackgrounds(NULL);

        TabPanelRecPtr ExampleTabPanel = TabPanel::create();
        ExampleTabPanel->setPreferredSize(Vec2f(600,600));
        ExampleTabPanel->addTab(SingleFieldLabel, createSingleFieldPanel());
        ExampleTabPanel->addTab(MultiFieldLabel, createMultiFieldPanel());
        ExampleTabPanel->addTab(SinglePtrFieldLabel, createSinglePtrFieldPanel());
        ExampleTabPanel->addTab(MultiPtrFieldLabel, createMultiPtrFieldPanel());
        ExampleTabPanel->setTabAlignment(0.5f);
        ExampleTabPanel->setTabPlacement(TabPanel::PLACEMENT_NORTH);
        ExampleTabPanel->setSelectedIndex(0);

        // Create a ScrollPanel for easier viewing of the List (see 27ScrollPanel)
        ScrollPanelRecPtr UndoRedoScrollPanel = ScrollPanel::create();
        UndoRedoScrollPanel->setPreferredSize(Vec2f(200,200));
        UndoRedoScrollPanel->setHorizontalResizePolicy(ScrollPanel::RESIZE_TO_VIEW);
        UndoRedoScrollPanel->setViewComponent(UndoRedoList);

        // Create The Main InternalWindow
        // Create Background to be used with the Main InternalWindow
        ColorLayerRecPtr MainInternalWindowBackground = ColorLayer::create();
            MainInternalWindowBackground->setColor(Color4f(1.0,1.0,1.0,0.5));
        InternalWindowRecPtr MainInternalWindow = InternalWindow::create();
        LayoutRecPtr MainInternalWindowLayout = FlowLayout::create();
           MainInternalWindow->pushToChildren(ExampleTabPanel);
           MainInternalWindow->pushToChildren(UndoRedoScrollPanel);
           MainInternalWindow->pushToChildren(UndoButton);
           MainInternalWindow->pushToChildren(RedoButton);
           MainInternalWindow->setLayout(MainInternalWindowLayout);
           MainInternalWindow->setBackgrounds(MainInternalWindowBackground);
           MainInternalWindow->setAlignmentInDrawingSurface(Vec2f(0.5f,0.5f));
           MainInternalWindow->setScalingInDrawingSurface(Vec2f(0.95f,0.95f));
           MainInternalWindow->setDrawTitlebar(false);
           MainInternalWindow->setResizable(false);

        // Create the Drawing Surface
        UIDrawingSurfaceRecPtr TutorialDrawingSurface = UIDrawingSurface::create();
        TutorialDrawingSurface->setGraphics(TutorialGraphics);
        TutorialDrawingSurface->setEventProducer(TutorialWindow);
        
        TutorialDrawingSurface->openWindow(MainInternalWindow);
        
        // Create the UI Foreground Object
        UIForegroundRecPtr TutorialUIForeground = UIForeground::create();
        TutorialUIForeground->setDrawingSurface(TutorialDrawingSurface);

        // Tell the Manager what to manage
        sceneManager.setWindow(TutorialWindow);
        sceneManager.setRoot(scene);

        // Add the UI Foreground Object to the Scene
        ViewportRecPtr TutorialViewport = sceneManager.getWindow()->getPort(0);
        TutorialViewport->addForeground(TutorialUIForeground);
        TutorialViewport->setBackground(TutorialBackground);

        //Create the Documentation Foreground and add it to the viewport
        SimpleScreenDoc TheSimpleScreenDoc(&sceneManager, TutorialWindow);

        // Show the whole Scene
        sceneManager.showAll();


        //Open Window
        Vec2f WinSize(TutorialWindow->getDesktopSize() * 0.85f);
        Pnt2f WinPos((TutorialWindow->getDesktopSize() - WinSize) *0.5);
        TutorialWindow->openWindow(WinPos,
                WinSize,
                "01ChangeFieldCommands");

        //Enter main Loop
        TutorialWindow->mainLoop();
    }

    osgExit();

    return 0;
}


// Callback functions


// Redraw the window
void display(SimpleSceneManager *mgr)
{
    mgr->redraw();
}

// React to size changes
void reshape(Vec2f Size, SimpleSceneManager *mgr)
{
    mgr->resize(Size.x(), Size.y());
}


PanelRecPtr createSingleFieldPanel(void)
{

    LineBorderRecPtr ChangableBorder = LineBorder::create();
    ChangableBorder->setColor(Color4f(0.0,0.0,0.0,1.0));
    
    ColorLayerRecPtr ChangableBackground = ColorLayer::create();
    ChangableBackground->setColor(Color4f(1.0,1.0,1.0,1.0));

    LabelRecPtr ChangableLabel = Label::create();

    ChangableLabel->setText("Changable");
    ChangableLabel->setBorders(ChangableBorder);
    ChangableLabel->setBackgrounds(ChangableBackground);

    //Command Buttons

    TheCommandManager = CommandManager::create(TheUndoManager);
    ButtonRecPtr BorderRedButton = Button::create();
    BorderRedButton->setText("Border Red");
    BorderRedButton->setPreferredSize(Vec2f(100.0f,BorderRedButton->getPreferredSize().y()));
    BorderRedButton->connectActionPerformed(boost::bind(&handleSetBorderColorAction, _1, Color4f(1.0,0.0,0.0,1.0), ChangableBorder.get()));
    
    ButtonRecPtr BorderGreenButton = Button::create();
    BorderGreenButton->setText("Border Green");
    BorderGreenButton->setPreferredSize(Vec2f(100.0f,BorderGreenButton->getPreferredSize().y()));
    BorderGreenButton->connectActionPerformed(boost::bind(&handleSetBorderColorAction, _1, Color4f(0.0,1.0,0.0,1.0), ChangableBorder.get()));
    
    ButtonRecPtr BorderBlueButton = Button::create();
    BorderBlueButton->setText("Border Blue");
    BorderBlueButton->setPreferredSize(Vec2f(100.0f,BorderBlueButton->getPreferredSize().y()));
    BorderBlueButton->connectActionPerformed(boost::bind(&handleSetBorderColorAction, _1, Color4f(0.0,0.0,1.0,1.0), ChangableBorder.get()));
    
    //Background
    ButtonRecPtr BackgroundRedButton = Button::create();
    BackgroundRedButton->setText("Background Red");
    BackgroundRedButton->setPreferredSize(Vec2f(130.0f,BackgroundRedButton->getPreferredSize().y()));
    BackgroundRedButton->connectActionPerformed(boost::bind(&handleSetBackgroundColorActionPerformed, _1, Color4f(1.0,0.0,0.0,1.0), ChangableBackground.get()));
    
    ButtonRecPtr BackgroundGreenButton = Button::create();
    BackgroundGreenButton->setText("Background Green");
    BackgroundGreenButton->setPreferredSize(Vec2f(130.0f,BackgroundGreenButton->getPreferredSize().y()));
    BackgroundGreenButton->connectActionPerformed(boost::bind(&handleSetBackgroundColorActionPerformed, _1, Color4f(0.0,1.0,0.0,1.0), ChangableBackground.get()));
    
    ButtonRecPtr BackgroundBlueButton = Button::create();
    BackgroundBlueButton->setText("Background Blue");
    BackgroundBlueButton->setPreferredSize(Vec2f(130.0f,BackgroundBlueButton->getPreferredSize().y()));
    BackgroundBlueButton->connectActionPerformed(boost::bind(&handleSetBackgroundColorActionPerformed, _1, Color4f(0.0,0.0,1.0,1.0), ChangableBackground.get()));

    LayoutRecPtr ThePanelLayout = FlowLayout::create();

    PanelRecPtr ThePanel = Panel::createEmpty();
    ThePanel->setLayout(ThePanelLayout);
    ThePanel->pushToChildren(BorderRedButton);
    ThePanel->pushToChildren(BorderGreenButton);
    ThePanel->pushToChildren(BorderBlueButton);
    ThePanel->pushToChildren(BackgroundRedButton);
    ThePanel->pushToChildren(BackgroundGreenButton);
    ThePanel->pushToChildren(BackgroundBlueButton);
    ThePanel->pushToChildren(ChangableLabel);

    return ThePanel;
    
}

void handleSetMultiFieldDialogClosed(DialogWindowEventDetails* const details)
{
    if(details->getOption() != DialogWindowEventDetails::DIALOG_OPTION_CANCEL)
    {
        SetFieldValueCommandPtr TheCommand = SetFieldValueCommand::create(TutorialBackground,GradientBackground::ColorFieldId, details->getInput(), MultiFieldList->getSelectionModel()->getMinSelectionIndex());

        TheCommandManager->executeCommand(TheCommand);
    }
}

void handleSetMultiFieldAction(ActionEventDetails* const details)
{
    std::vector<std::string> inputValues;
    inputValues.push_back("1 0 0");

    DialogWindowRecPtr TheDialog;
    TheDialog = DialogWindow::createInputDialog("Set the value", "Please enter a color below", DialogWindow::INPUT_TEXT,true,inputValues);
    TheDialog->setAllwaysOnTop(true);
    TheDialog->connectDialogWindowClosed(boost::bind(&handleSetMultiFieldDialogClosed, _1));

    Pnt2f CenteredPosition = calculateAlignment(dynamic_cast<Component*>(details->getSource())->getParentWindow()->getPosition(), dynamic_cast<Component*>(details->getSource())->getParentWindow()->getSize(), TheDialog->getPreferredSize(), 0.5f, 0.5f);
    TheDialog->setPosition(CenteredPosition);

    dynamic_cast<Component*>(details->getSource())->getParentWindow()->getParentDrawingSurface()->openWindow(TheDialog);
}

void handleAddMultiFieldDialogClosed(DialogWindowEventDetails* const details)
{
    if(details->getOption() != DialogWindowEventDetails::DIALOG_OPTION_CANCEL)
    {
        UndoableCommandPtr TheCommand1 = AddFieldElementCommand::create(TutorialBackground,GradientBackground::ColorFieldId, details->getInput());
        UndoableCommandPtr TheCommand2 = AddFieldElementCommand::create(TutorialBackground,GradientBackground::PositionFieldId, "1.0");

        std::vector<UndoableCommandPtr> CommandVec;
        CommandVec.push_back(TheCommand1);
        CommandVec.push_back(TheCommand2);

        CommandPtr TheCommand = CompoundUndoableCommand::create(CommandVec);
        TheCommandManager->executeCommand(TheCommand);
    }
}

void handleAddMultiFieldAction(ActionEventDetails* const details)
{
    std::vector<std::string> inputValues;
    inputValues.push_back("1 0 0");

    DialogWindowRecPtr TheDialog;
    TheDialog = DialogWindow::createInputDialog("Add value", "Please enter a color below", DialogWindow::INPUT_TEXT,true,inputValues);
    TheDialog->setAllwaysOnTop(true);
    TheDialog->connectDialogWindowClosed(boost::bind(&handleAddMultiFieldDialogClosed, _1));

    Pnt2f CenteredPosition = calculateAlignment(dynamic_cast<Component*>(details->getSource())->getParentWindow()->getPosition(), dynamic_cast<Component*>(details->getSource())->getParentWindow()->getSize(), TheDialog->getPreferredSize(), 0.5f, 0.5f);
    TheDialog->setPosition(CenteredPosition);

    dynamic_cast<Component*>(details->getSource())->getParentWindow()->getParentDrawingSurface()->openWindow(TheDialog);
}

void handleMoveMultiFieldDialogClosed(DialogWindowEventDetails* const details)
{
    if(details->getOption() != DialogWindowEventDetails::DIALOG_OPTION_CANCEL)
    {
        CommandPtr TheCommand = MoveFieldElementCommand::create(TutorialBackground,GradientBackground::ColorFieldId, MultiFieldList->getSelectionModel()->getMinSelectionIndex(), boost::lexical_cast<UInt32>(details->getInput()));

        TheCommandManager->executeCommand(TheCommand);
    }
}

void handleMoveMultiFieldAction(ActionEventDetails* const details)
{
    std::vector<std::string> inputValues;
    inputValues.push_back("0");

    DialogWindowRecPtr TheDialog;
    TheDialog = DialogWindow::createInputDialog("Move selected index to", "Please enter the index to move to", DialogWindow::INPUT_TEXT,true,inputValues);
    TheDialog->setAllwaysOnTop(true);
    TheDialog->connectDialogWindowClosed(boost::bind(&handleMoveMultiFieldDialogClosed, _1));

    Pnt2f CenteredPosition = calculateAlignment(dynamic_cast<Component*>(details->getSource())->getParentWindow()->getPosition(), dynamic_cast<Component*>(details->getSource())->getParentWindow()->getSize(), TheDialog->getPreferredSize(), 0.5f, 0.5f);
    TheDialog->setPosition(CenteredPosition);

    dynamic_cast<Component*>(details->getSource())->getParentWindow()->getParentDrawingSurface()->openWindow(TheDialog);
}

void handleInsertMultiFieldDialogClosed(DialogWindowEventDetails* const details)
{
    if(details->getOption() != DialogWindowEventDetails::DIALOG_OPTION_CANCEL)
    {
        UndoableCommandPtr TheCommand1 = InsertFieldElementCommand::create(TutorialBackground,GradientBackground::ColorFieldId, details->getInput(), MultiFieldList->getSelectionModel()->getMinSelectionIndex());

        UndoableCommandPtr TheCommand2 = InsertFieldElementCommand::create(TutorialBackground,GradientBackground::PositionFieldId, "1.0", MultiFieldList->getSelectionModel()->getMinSelectionIndex());

        std::vector<UndoableCommandPtr> CommandVec;
        CommandVec.push_back(TheCommand1);
        CommandVec.push_back(TheCommand2);

        CommandPtr TheCommand = CompoundUndoableCommand::create(CommandVec);
        TheCommandManager->executeCommand(TheCommand);
    }
}

void handleInsertMultiFieldActionPerformed(ActionEventDetails* const details)
{
    std::vector<std::string> inputValues;
    inputValues.push_back("1 0 0");

    DialogWindowRecPtr TheDialog;
    TheDialog = DialogWindow::createInputDialog("Insert the value", "Please enter a color below", DialogWindow::INPUT_TEXT,true,inputValues);
    TheDialog->setAllwaysOnTop(true);
    TheDialog->connectDialogWindowClosed(boost::bind(&handleInsertMultiFieldDialogClosed, _1));

    Pnt2f CenteredPosition = calculateAlignment(dynamic_cast<Component*>(details->getSource())->getParentWindow()->getPosition(), dynamic_cast<Component*>(details->getSource())->getParentWindow()->getSize(), TheDialog->getPreferredSize(), 0.5f, 0.5f);
    TheDialog->setPosition(CenteredPosition);

    dynamic_cast<Component*>(details->getSource())->getParentWindow()->getParentDrawingSurface()->openWindow(TheDialog);
}

void handleSwapMultiFieldDialogClosed(DialogWindowEventDetails* const details)
{
    if(details->getOption() != DialogWindowEventDetails::DIALOG_OPTION_CANCEL)
    {
        CommandPtr TheCommand = SwapFieldElementCommand::create(TutorialBackground,GradientBackground::ColorFieldId, MultiFieldList->getSelectionModel()->getMinSelectionIndex(), boost::lexical_cast<UInt32>(details->getInput()));

        TheCommandManager->executeCommand(TheCommand);
    }
}

void handleSwapMultiFieldAction(ActionEventDetails* const details)
{
    std::vector<std::string> inputValues;
    inputValues.push_back("0");

    DialogWindowRecPtr TheDialog;
    TheDialog = DialogWindow::createInputDialog("Swap selected index with", "Please enter the index to move to", DialogWindow::INPUT_TEXT,true,inputValues);
    TheDialog->setAllwaysOnTop(true);
    TheDialog->connectDialogWindowClosed(boost::bind(&handleSwapMultiFieldDialogClosed, _1));

    Pnt2f CenteredPosition = calculateAlignment(dynamic_cast<Component*>(details->getSource())->getParentWindow()->getPosition(), dynamic_cast<Component*>(details->getSource())->getParentWindow()->getSize(), TheDialog->getPreferredSize(), 0.5f, 0.5f);
    TheDialog->setPosition(CenteredPosition);

    dynamic_cast<Component*>(details->getSource())->getParentWindow()->getParentDrawingSurface()->openWindow(TheDialog);
}

void handleRemoveMultiFieldAction(ActionEventDetails* const details)
{
    if(!MultiFieldList->getSelectionModel()->isSelectionEmpty())
    {
        UndoableCommandPtr TheCommand1 = RemoveFieldElementCommand::create(TutorialBackground,GradientBackground::ColorFieldId, MultiFieldList->getSelectionModel()->getMinSelectionIndex());

        UndoableCommandPtr TheCommand2 = RemoveFieldElementCommand::create(TutorialBackground,GradientBackground::PositionFieldId, MultiFieldList->getSelectionModel()->getMinSelectionIndex());

        std::vector<UndoableCommandPtr> CommandVec;
        CommandVec.push_back(TheCommand1);
        CommandVec.push_back(TheCommand2);

        CommandPtr TheCommand = CompoundUndoableCommand::create(CommandVec);
        TheCommandManager->executeCommand(TheCommand);
    }
}

ComponentTransitPtr generateColorListComponent(List* const Parent,
                                               const boost::any& Value,
                                               UInt32 Index,
                                               bool IsSelected,
                                               bool HasFocus)
{
    std::string ValueString;
    Color3f ColorValue;
    try
    {
        MFieldListModel::MFieldIndexed MFieldValue = boost::any_cast<MFieldListModel::MFieldIndexed>(Value);
        std::ostringstream TheOSStream;
        OutStream TheOutStream(TheOSStream);
        MFieldValue.first->pushIndexedValueToStream(TheOutStream,
                                                    MFieldValue.second);
        ValueString = TheOSStream.str();
        ColorValue = static_cast<const
            GradientBackground::MFColorType*>(MFieldValue.first->getField())->operator[](MFieldValue.second);
    }
    catch (boost::bad_lexical_cast &)
    {
        //Could not convert to string
    }

    ColorLayerRecPtr LabelBackground = ColorLayer::create();
    LabelBackground->setColor(Color4f(ColorValue.red(),ColorValue.green(),ColorValue.blue(),1.0f));

    LabelRefPtr TheComponent = Label::create();

    TheComponent->setBackgrounds(LabelBackground);
    TheComponent->setText(ValueString);

    if(IsSelected)
    {
        LineBorderRecPtr LabelBorder = LineBorder::create();
        LabelBorder->setWidth(1.0f);
        LabelBorder->setColor(Color4f(0.0f,0.0f,0.0f,1.0f));
        TheComponent->setBorders(LabelBorder);
    }
    else
    {
        TheComponent->setBorders(NULL);
    }

    return ComponentTransitPtr(TheComponent);
}

PanelRecPtr createMultiFieldPanel(void)
{
    //Popup Menu
    MenuItemRecPtr RemoveIndexMenuItem = MenuItem::create();
    RemoveIndexMenuItem->setText("Remove Index");
    RemoveIndexMenuItem->connectActionPerformed(boost::bind(&handleRemoveMultiFieldAction, _1));

    MenuItemRecPtr SetValueMenuItem = MenuItem::create();
    SetValueMenuItem->setText("Set Value");
    SetValueMenuItem->connectActionPerformed(boost::bind(&handleSetMultiFieldAction, _1));
    
    MenuItemRecPtr AddValueMenuItem = MenuItem::create();
    AddValueMenuItem->setText("Add Value");
    AddValueMenuItem->connectActionPerformed(boost::bind(&handleAddMultiFieldAction, _1));
    
    MenuItemRecPtr InsertIndexMenuItem = MenuItem::create();
    InsertIndexMenuItem->setText("Insert Value");
    InsertIndexMenuItem->connectActionPerformed(boost::bind(&handleInsertMultiFieldActionPerformed, _1));
    
    MenuItemRecPtr MoveIndexMenuItem = MenuItem::create();
    MoveIndexMenuItem->setText("Move Value");
    MoveIndexMenuItem->connectActionPerformed(boost::bind(&handleMoveMultiFieldAction, _1));
    
    MenuItemRecPtr SwapIndexMenuItem = MenuItem::create();
    SwapIndexMenuItem->setText("Swap Value");
    SwapIndexMenuItem->connectActionPerformed(boost::bind(&handleSwapMultiFieldAction, _1));

    PopupMenuRecPtr MultiFieldListPopupMenu = PopupMenu::create();
    MultiFieldListPopupMenu->addItem(SetValueMenuItem);
    MultiFieldListPopupMenu->addItem(AddValueMenuItem);
    MultiFieldListPopupMenu->addItem(InsertIndexMenuItem);
    MultiFieldListPopupMenu->addItem(MoveIndexMenuItem);
    MultiFieldListPopupMenu->addItem(SwapIndexMenuItem);
    MultiFieldListPopupMenu->addItem(RemoveIndexMenuItem);

    //Multi-field List Model
    MultiFieldListModel = MFieldListModel::create();
    MultiFieldListModel->setContainer(TutorialBackground);
    MultiFieldListModel->setFieldId(GradientBackground::ColorFieldId);

    //List Component Generator
    FunctorListComponentGeneratorRecPtr ListCompGenerator =
        FunctorListComponentGenerator::create();

    ListCompGenerator->setGenerateFunction(boost::bind(generateColorListComponent, _1, _2, _3, _4, _5));

    //List
    MultiFieldList = List::create();
    MultiFieldList->setPreferredSize(Vec2f(200, 300));
    MultiFieldList->setOrientation(List::VERTICAL_ORIENTATION);
    MultiFieldList->setModel(MultiFieldListModel);
    MultiFieldList->setPopupMenu(MultiFieldListPopupMenu);
    MultiFieldList->setCellGenerator(ListCompGenerator);

    // Create a ScrollPanel for easier viewing of the List
    ScrollPanelRecPtr ExampleScrollPanel = ScrollPanel::create();
        ExampleScrollPanel->setPreferredSize(Vec2f(200,300));
        ExampleScrollPanel->setHorizontalResizePolicy(ScrollPanel::RESIZE_TO_VIEW);
    ExampleScrollPanel->setViewComponent(MultiFieldList);

    // Create MainFramelayout
    FlowLayoutRecPtr MainInternalWindowLayout = FlowLayout::create();
    MainInternalWindowLayout->setOrientation(FlowLayout::VERTICAL_ORIENTATION);
    MainInternalWindowLayout->setMajorAxisAlignment(0.5f);
    MainInternalWindowLayout->setMinorAxisAlignment(0.5f);

    //Label
    LabelRecPtr ListLabel = Label::create();
    ListLabel->setText("Background Colors List");
    ListLabel->setPreferredSize(Vec2f(200.0f, ListLabel->getPreferredSize().y()));


    //Panel
    FlowLayoutRecPtr ThePanelLayout = FlowLayout::create();
    ThePanelLayout->setOrientation(FlowLayout::VERTICAL_ORIENTATION);
    ThePanelLayout->setMajorAxisAlignment(0.5f);
    ThePanelLayout->setMinorAxisAlignment(0.5f);

    PanelRecPtr ThePanel = Panel::createEmpty();
    ThePanel->setLayout(ThePanelLayout);
    ThePanel->pushToChildren(ListLabel);
    ThePanel->pushToChildren(ExampleScrollPanel);

    return ThePanel;
    
}


void handleSinglePtrFieldCreateDialogClosed(DialogWindowEventDetails* const details,
                                      Label* const singlePtrFieldLabel)
{
    if(details->getOption() != DialogWindowEventDetails::DIALOG_OPTION_CANCEL)
    {
        //Create the Layer FieldContainer
        CreateFieldContainerCommandPtr CreateCommand = CreateFieldContainerCommand::create(details->getInput());

        TheCommandManager->executeCommand(CreateCommand);

        //If the layer is a ColorLayer then give it a random color
        if(CreateCommand->getContainer()->getType() == ColorLayer::getClassType())
        {
            Color4f RandColor(RandomPoolManager::getRandomReal32(0.0f,1.0f),
                              RandomPoolManager::getRandomReal32(0.0f,1.0f),
                              RandomPoolManager::getRandomReal32(0.0f,1.0f),
                              1.0f);

            dynamic_cast<ColorLayer*>(CreateCommand->getContainer())->setColor(RandColor);
        }


        //Set the background layer to use the newly create layer
        SetFieldValueCommandPtr SetFieldCommand = SetFieldValueCommand::create(singlePtrFieldLabel,Component::BackgroundFieldId, boost::lexical_cast<std::string>(CreateCommand->getContainer()->getId()));

        TheCommandManager->executeCommand(SetFieldCommand);
    }
}

void handleSinglePtrFieldCreateAction(ActionEventDetails* const details,
                                      Label* const singlePtrFieldLabel)
{
    std::vector<std::string> inputValues;
    inputValues.push_back("ColorLayer");
    inputValues.push_back("EmptyLayer");

    DialogWindowRecPtr TheDialog;
    TheDialog = DialogWindow::createInputDialog("Create component background", "Please select the component background to create", DialogWindow::INPUT_COMBO,true,inputValues);
    TheDialog->setAllwaysOnTop(true);
    TheDialog->connectDialogWindowClosed(boost::bind(&handleSinglePtrFieldCreateDialogClosed, _1, singlePtrFieldLabel));

    Pnt2f CenteredPosition = calculateAlignment(dynamic_cast<Component*>(details->getSource())->getParentWindow()->getPosition(), dynamic_cast<Component*>(details->getSource())->getParentWindow()->getSize(), TheDialog->getPreferredSize(), 0.5f, 0.5f);
    TheDialog->setPosition(CenteredPosition);

    dynamic_cast<Component*>(details->getSource())->getParentWindow()->getParentDrawingSurface()->openWindow(TheDialog);
}

PanelRecPtr createSinglePtrFieldPanel(void)
{
    LabelRecPtr SinglePtrFieldLabel = Label::create();

    SinglePtrFieldLabel->setText("Changable");
    SinglePtrFieldLabel->setBorders(NULL);
    
    ButtonRecPtr SinglePtrFieldCreateBackgroundButton = Button::create();
    SinglePtrFieldCreateBackgroundButton->setText("Create Background");
    SinglePtrFieldCreateBackgroundButton->setPreferredSize(Vec2f(175.0f,SinglePtrFieldCreateBackgroundButton->getPreferredSize().y()));
    SinglePtrFieldCreateBackgroundButton->connectActionPerformed(boost::bind(&handleSinglePtrFieldCreateAction, _1, SinglePtrFieldLabel.get()));

    LayoutRecPtr ThePanelLayout = FlowLayout::create();

    PanelRecPtr ThePanel = Panel::createEmpty();
    ThePanel->setLayout(ThePanelLayout);
    ThePanel->pushToChildren(SinglePtrFieldLabel);
    ThePanel->pushToChildren(SinglePtrFieldCreateBackgroundButton);

    return ThePanel;
    
}

void handleSetMultiPtrFieldDialogClosed(DialogWindowEventDetails* const details)
{
    if(details->getOption() != DialogWindowEventDetails::DIALOG_OPTION_CANCEL)
    {
        SetFieldValueCommandPtr TheCommand = SetFieldValueCommand::create(MultiPtrFieldInnerPanel,Panel::ChildrenFieldId, details->getInput(), MultiPtrFieldList->getSelectionModel()->getMinSelectionIndex());

        TheCommandManager->executeCommand(TheCommand);
    }
}

void handleSetMultiPtrFieldAction(ActionEventDetails* const details)
{
    std::vector<std::string> inputValues;
    inputValues.push_back("0");

    DialogWindowRecPtr TheDialog;
    TheDialog = DialogWindow::createInputDialog("Assign the button by Id", "Please enter a button Id", DialogWindow::INPUT_TEXT,true,inputValues);
    TheDialog->setAllwaysOnTop(true);
    TheDialog->connectDialogWindowClosed(boost::bind(&handleSetMultiPtrFieldDialogClosed, _1));

    Pnt2f CenteredPosition = calculateAlignment(dynamic_cast<Component*>(details->getSource())->getParentWindow()->getPosition(), dynamic_cast<Component*>(details->getSource())->getParentWindow()->getSize(), TheDialog->getPreferredSize(), 0.5f, 0.5f);
    TheDialog->setPosition(CenteredPosition);

    dynamic_cast<Component*>(details->getSource())->getParentWindow()->getParentDrawingSurface()->openWindow(TheDialog);
}

void handleAddMultiPtrFieldDialogClosed(DialogWindowEventDetails* const details)
{
    if(details->getOption() != DialogWindowEventDetails::DIALOG_OPTION_CANCEL)
    {
        ButtonRecPtr NewButton = Button::create();
        NewButton->setText(details->getInput());
        setName(NewButton, NewButton->getText());

        CommandPtr TheCommand = AddFieldElementCommand::create(MultiPtrFieldInnerPanel,Panel::ChildrenFieldId, boost::lexical_cast<std::string>(NewButton->getId()));

        TheCommandManager->executeCommand(TheCommand);
    }
}

void handleAddMultiPtrFieldActionPerformed(ActionEventDetails* const details)
{
    std::vector<std::string> inputValues;
    inputValues.push_back("C");

    DialogWindowRecPtr TheDialog;
    TheDialog = DialogWindow::createInputDialog("Add a new button", "Please enter text for the button", DialogWindow::INPUT_TEXT,true,inputValues);
    TheDialog->setAllwaysOnTop(true);
    TheDialog->connectDialogWindowClosed(boost::bind(&handleAddMultiPtrFieldDialogClosed, _1));

    Pnt2f CenteredPosition = calculateAlignment(dynamic_cast<Component*>(details->getSource())->getParentWindow()->getPosition(), dynamic_cast<Component*>(details->getSource())->getParentWindow()->getSize(), TheDialog->getPreferredSize(), 0.5f, 0.5f);
    TheDialog->setPosition(CenteredPosition);

    dynamic_cast<Component*>(details->getSource())->getParentWindow()->getParentDrawingSurface()->openWindow(TheDialog);
}

void handleMoveMultiPtrFieldDialogClosed(DialogWindowEventDetails* const details)
{
    if(details->getOption() != DialogWindowEventDetails::DIALOG_OPTION_CANCEL)
    {
        CommandPtr TheCommand = MoveFieldElementCommand::create(MultiPtrFieldInnerPanel,Panel::ChildrenFieldId, MultiPtrFieldList->getSelectionModel()->getMinSelectionIndex(), boost::lexical_cast<UInt32>(details->getInput()));

        TheCommandManager->executeCommand(TheCommand);
    }
}

void handleMoveMultiPtrFieldActionPerformed(ActionEventDetails* const details)
{
    std::vector<std::string> inputValues;
    inputValues.push_back("0");

    DialogWindowRecPtr TheDialog;
    TheDialog = DialogWindow::createInputDialog("Move selected index to", "Please enter the index to move to", DialogWindow::INPUT_TEXT,true,inputValues);
    TheDialog->setAllwaysOnTop(true);
    TheDialog->connectDialogWindowClosed(boost::bind(&handleMoveMultiPtrFieldDialogClosed, _1));

    Pnt2f CenteredPosition = calculateAlignment(dynamic_cast<Component*>(details->getSource())->getParentWindow()->getPosition(), dynamic_cast<Component*>(details->getSource())->getParentWindow()->getSize(), TheDialog->getPreferredSize(), 0.5f, 0.5f);
    TheDialog->setPosition(CenteredPosition);

    dynamic_cast<Component*>(details->getSource())->getParentWindow()->getParentDrawingSurface()->openWindow(TheDialog);
}

void handleInsertMultiPtrFieldDialogClosed(DialogWindowEventDetails* const details)
{
    if(details->getOption() != DialogWindowEventDetails::DIALOG_OPTION_CANCEL)
    {
        ButtonRecPtr NewButton = Button::create();
        NewButton->setText(details->getInput());
        setName(NewButton, NewButton->getText());

        CommandPtr TheCommand = InsertFieldElementCommand::create(MultiPtrFieldInnerPanel,Panel::ChildrenFieldId, boost::lexical_cast<std::string>(NewButton->getId()), MultiPtrFieldList->getSelectionModel()->getMinSelectionIndex());

        TheCommandManager->executeCommand(TheCommand);
    }
}

void handleInsertMultiPtrFieldActionPerformed(ActionEventDetails* const details)
{
    std::vector<std::string> inputValues;
    inputValues.push_back("C");

    DialogWindowRecPtr TheDialog;
    TheDialog = DialogWindow::createInputDialog("Insert a button", "Please enter text for the button", DialogWindow::INPUT_TEXT,true,inputValues);
    TheDialog->setAllwaysOnTop(true);
    TheDialog->connectDialogWindowClosed(boost::bind(&handleInsertMultiPtrFieldDialogClosed, _1));

    Pnt2f CenteredPosition = calculateAlignment(dynamic_cast<Component*>(details->getSource())->getParentWindow()->getPosition(), dynamic_cast<Component*>(details->getSource())->getParentWindow()->getSize(), TheDialog->getPreferredSize(), 0.5f, 0.5f);
    TheDialog->setPosition(CenteredPosition);

    dynamic_cast<Component*>(details->getSource())->getParentWindow()->getParentDrawingSurface()->openWindow(TheDialog);
}

void handleSwapMultiPtrFieldDialogClosed(DialogWindowEventDetails* const details)
{
    if(details->getOption() != DialogWindowEventDetails::DIALOG_OPTION_CANCEL)
    {
        CommandPtr TheCommand = SwapFieldElementCommand::create(MultiPtrFieldInnerPanel,Panel::ChildrenFieldId, MultiPtrFieldList->getSelectionModel()->getMinSelectionIndex(), boost::lexical_cast<UInt32>(details->getInput()));

        TheCommandManager->executeCommand(TheCommand);
    }
}

void handleSwapMultiPtrFieldActionPerformed(ActionEventDetails* const details)
{
    std::vector<std::string> inputValues;
    inputValues.push_back("0");

    DialogWindowRecPtr TheDialog;
    TheDialog = DialogWindow::createInputDialog("Swap selected index with", "Please enter the index to swap with", DialogWindow::INPUT_TEXT,true,inputValues);
    TheDialog->setAllwaysOnTop(true);
    TheDialog->connectDialogWindowClosed(boost::bind(&handleSwapMultiPtrFieldDialogClosed, _1));

    Pnt2f CenteredPosition = calculateAlignment(dynamic_cast<Component*>(details->getSource())->getParentWindow()->getPosition(), dynamic_cast<Component*>(details->getSource())->getParentWindow()->getSize(), TheDialog->getPreferredSize(), 0.5f, 0.5f);
    TheDialog->setPosition(CenteredPosition);

    dynamic_cast<Component*>(details->getSource())->getParentWindow()->getParentDrawingSurface()->openWindow(TheDialog);
}

void handleRemoveMultiPtrFieldAction(ActionEventDetails* const details)
{
    if(!MultiPtrFieldList->getSelectionModel()->isSelectionEmpty())
    {
        UndoableCommandPtr TheCommand = RemoveFieldElementCommand::create(MultiPtrFieldInnerPanel,Panel::ChildrenFieldId, MultiPtrFieldList->getSelectionModel()->getMinSelectionIndex());

        TheCommandManager->executeCommand(TheCommand);
    }
}

ComponentTransitPtr generatePtrListComponent(List* const Parent,
                                             const boost::any& Value,
                                             UInt32 Index,
                                             bool IsSelected,
                                             bool HasFocus)
{
    std::string ValueString("<<Unnamed>>");
    FieldContainer* ContainerValue;
    try
    {
        MFieldListModel::MFieldIndexed MFieldValue = boost::any_cast<MFieldListModel::MFieldIndexed>(Value);
        ContainerValue = static_cast<const
            Panel::MFChildrenType*>(MFieldValue.first->getField())->operator[](MFieldValue.second);
    }
    catch (boost::bad_lexical_cast &)
    {
        //Could not convert to string
    }

    if(dynamic_cast<AttachmentContainer*>(ContainerValue) != NULL &&
       getName(dynamic_cast<AttachmentContainer*>(ContainerValue)) != NULL)
    {
        ValueString = getName(dynamic_cast<AttachmentContainer*>(ContainerValue));
    }

    if(ContainerValue != NULL)
    {
        ValueString += std::string(" [") + ContainerValue->getType().getName() + "]";
    }

    LabelRefPtr TheComponent = Label::create();

    TheComponent->setText(ValueString);

    if(IsSelected)
    {
        LineBorderRecPtr LabelBorder = LineBorder::create();
        LabelBorder->setWidth(1.0f);
        LabelBorder->setColor(Color4f(0.0f,0.0f,0.0f,1.0f));
        TheComponent->setBorders(LabelBorder);
    }
    else
    {
        TheComponent->setBorders(NULL);
    }

    return ComponentTransitPtr(TheComponent);
}

PanelRecPtr createMultiPtrFieldPanel(void)
{
    //Buttons for Inner Panel
    ButtonRecPtr AButton = Button::create();
    AButton->setText("A");
    setName(AButton, "A");

    ButtonRecPtr BButton = Button::create();
    BButton->setText("B");
    setName(BButton, "B");

    //Inner Panel
    LayoutRecPtr MultiPtrFieldInnerPanelLayout = FlowLayout::create();

    MultiPtrFieldInnerPanel = Panel::create();
    MultiPtrFieldInnerPanel->setLayout(MultiPtrFieldInnerPanelLayout);
    MultiPtrFieldInnerPanel->setPreferredSize(Vec2f(200.0f, 200.0f));
    MultiPtrFieldInnerPanel->pushToChildren(AButton);
    MultiPtrFieldInnerPanel->pushToChildren(BButton);

    //Popup Menu
    MenuItemRecPtr RemoveIndexMenuItem = MenuItem::create();
    RemoveIndexMenuItem->setText("Remove Index");
    RemoveIndexMenuItem->connectActionPerformed(boost::bind(&handleRemoveMultiPtrFieldAction, _1));

    MenuItemRecPtr SetValueMenuItem = MenuItem::create();
    SetValueMenuItem->setText("Set Value");
    SetValueMenuItem->connectActionPerformed(boost::bind(&handleSetMultiPtrFieldAction, _1));
    
    MenuItemRecPtr AddValueMenuItem = MenuItem::create();
    AddValueMenuItem->setText("Add Value");
    AddValueMenuItem->connectActionPerformed(boost::bind(&handleAddMultiPtrFieldActionPerformed, _1));
    
    MenuItemRecPtr InsertIndexMenuItem = MenuItem::create();
    InsertIndexMenuItem->setText("Insert Value");
    InsertIndexMenuItem->connectActionPerformed(boost::bind(&handleInsertMultiPtrFieldActionPerformed, _1));
    
    MenuItemRecPtr MoveIndexMenuItem = MenuItem::create();
    MoveIndexMenuItem->setText("Move Value");
    MoveIndexMenuItem->connectActionPerformed(boost::bind(&handleMoveMultiPtrFieldActionPerformed, _1));
    
    MenuItemRecPtr SwapIndexMenuItem = MenuItem::create();
    SwapIndexMenuItem->setText("Swap Value");
    SwapIndexMenuItem->connectActionPerformed(boost::bind(&handleSwapMultiPtrFieldActionPerformed, _1));

    PopupMenuRecPtr MultiPtrFieldListPopupMenu = PopupMenu::create();
    MultiPtrFieldListPopupMenu->addItem(SetValueMenuItem);
    MultiPtrFieldListPopupMenu->addItem(AddValueMenuItem);
    MultiPtrFieldListPopupMenu->addItem(InsertIndexMenuItem);
    MultiPtrFieldListPopupMenu->addItem(MoveIndexMenuItem);
    MultiPtrFieldListPopupMenu->addItem(SwapIndexMenuItem);
    MultiPtrFieldListPopupMenu->addItem(RemoveIndexMenuItem);

    //Multi-field List Model
    MultiPtrFieldListModel = MFieldListModel::create();
    MultiPtrFieldListModel->setContainer(MultiPtrFieldInnerPanel);
    MultiPtrFieldListModel->setFieldId(Panel::ChildrenFieldId);

    //List Component Generator
    FunctorListComponentGeneratorRecPtr ListCompGenerator =
        FunctorListComponentGenerator::create();

    ListCompGenerator->setGenerateFunction(boost::bind(generatePtrListComponent, _1, _2, _3, _4, _5));

    //List
    MultiPtrFieldList = List::create();
    MultiPtrFieldList->setPreferredSize(Vec2f(200, 300));
    MultiPtrFieldList->setOrientation(List::VERTICAL_ORIENTATION);
    MultiPtrFieldList->setModel(MultiPtrFieldListModel);
    MultiPtrFieldList->setPopupMenu(MultiPtrFieldListPopupMenu);
    MultiPtrFieldList->setCellGenerator(ListCompGenerator);

    // Create a ScrollPanel for easier viewing of the List
    ScrollPanelRecPtr ExampleScrollPanel = ScrollPanel::create();
        ExampleScrollPanel->setPreferredSize(Vec2f(200,300));
        ExampleScrollPanel->setHorizontalResizePolicy(ScrollPanel::RESIZE_TO_VIEW);
    ExampleScrollPanel->setViewComponent(MultiPtrFieldList);


    LayoutRecPtr ThePanelLayout = FlowLayout::create();

    PanelRecPtr ThePanel = Panel::createEmpty();
    ThePanel->setLayout(ThePanelLayout);
    ThePanel->pushToChildren(MultiPtrFieldInnerPanel);
    ThePanel->pushToChildren(ExampleScrollPanel);

    return ThePanel;
    
}

SimpleTextForegroundTransitPtr SimpleScreenDoc::makeDocShowForeground(void)
{
    SimpleTextForegroundRecPtr DocShowForeground =  SimpleTextForeground::create(); 

    DocShowForeground->setSize(20.0f);
    DocShowForeground->setBgColor(Color4f(0.0f,0.0f,0.0f,0.0f));
    DocShowForeground->setShadowColor(Color4f(0.0f,0.0f,0.0f,0.0f));
    DocShowForeground->setBorderColor(Color4f(1.0f,1.0f,1.0f,0.0f));
    DocShowForeground->setHorizontalAlign(SimpleTextForeground::Middle);
    DocShowForeground->setVerticalAlign(SimpleTextForeground::Top);

    DocShowForeground->addLine("Press ? for help.");

    return SimpleTextForegroundTransitPtr(DocShowForeground);
}

SimpleScreenDoc::SimpleScreenDoc(SimpleSceneManager*  SceneManager,
                                 WindowEventProducer* MainWindow)
{
    _DocForeground = makeDocForeground();
    _DocForeground->setBgColor(Color4f(0.0f,0.0f,0.0f,0.8f));
    _DocForeground->setBorderColor(Color4f(1.0f,1.0f,1.0f,1.0f));
    _DocForeground->setTextMargin(Vec2f(5.0f,5.0f));
    _DocForeground->setHorizontalAlign(SimpleTextForeground::Left);
    _DocForeground->setVerticalAlign(SimpleTextForeground::Top);
    _DocForeground->setActive(false);

    _DocShowForeground = makeDocShowForeground();

    ViewportRefPtr TutorialViewport = SceneManager->getWindow()->getPort(0);
    TutorialViewport->addForeground(_DocForeground);
    TutorialViewport->addForeground(_DocShowForeground);

    MainWindow->connectKeyTyped(boost::bind(&SimpleScreenDoc::keyTyped,
                                            this,
                                            _1));
    
    //Color Keyframe Sequence
    KeyframeColorSequenceRecPtr ColorKeyframes = KeyframeColorSequenceColor4f::create();
    ColorKeyframes->addKeyframe(Color4f(0.0f,0.0f,0.0f,1.0f),0.0f);
    ColorKeyframes->addKeyframe(Color4f(0.0f,0.0f,0.0f,1.0f),5.0f);
    ColorKeyframes->addKeyframe(Color4f(0.0f,0.0f,0.0f,0.0f),7.0f);
    
    //Animator
    KeyframeAnimatorRecPtr TheAnimator = KeyframeAnimator::create();
    TheAnimator->setKeyframeSequence(ColorKeyframes);
    
    //Animation
    _ShowDocFadeOutAnimation = FieldAnimation::create();
    _ShowDocFadeOutAnimation->setAnimator(TheAnimator);
    _ShowDocFadeOutAnimation->setInterpolationType(Animator::LINEAR_INTERPOLATION);
    _ShowDocFadeOutAnimation->setCycling(1);
    _ShowDocFadeOutAnimation->setAnimatedField(_DocShowForeground,
                                               SimpleTextForeground::ColorFieldId);

    _ShowDocFadeOutAnimation->attachUpdateProducer(MainWindow);
    _ShowDocFadeOutAnimation->start();
}

void SimpleScreenDoc::keyTyped(KeyEventDetails* const details)
{
    switch(details->getKeyChar())
    {
        case '?':
            _DocForeground->setActive(!_DocForeground->getActive());
            break;
    }
}

