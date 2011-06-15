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
#include "OSGList.h"
#include "OSGDefaultListSelectionModel.h"
#include "OSGSolidBackground.h"
#include "OSGUIDrawUtils.h"
#include "OSGFieldEditorFactory.h"

// Activate the OpenSG namespace
OSG_USING_NAMESPACE

// The SimpleSceneManager to manage simple applications

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

void handleUndoButtonAction(ActionEventDetails* const details,
                            UndoManagerPtr TheUndoManager)
{
    TheUndoManager->undo();
}

void handleRedoButtonActionPerformed(ActionEventDetails* const details,
                            UndoManagerPtr TheUndoManager)
{
    TheUndoManager->redo();
}

void handleUndoManagerStateChanged(ChangeEventDetails* const details,
                                   Button* const undoButton,
                                   Button* const redoButton,
                                   DefaultListModel* const undoRedoListModel,
                                   UndoManagerPtr TheUndoManager)
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

void handleUndoRedoListSelectionChanged(ListSelectionEventDetails* const details,
                                        UndoManagerPtr TheUndoManager)
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
    DocForeground->addLine("of \\{\\color=AAAA00FF FieldEditorComponent} and \\{\\color=AAAA00FF FieldEditorFactory}.");
    
    DocForeground->addLine("");
    DocForeground->addLine("\\{\\color=AAAAAAFF Key Controls}:");
    DocForeground->addLine("     \\{\\color=AAAAFFFF Cmd+q}: Close the application");
    DocForeground->addLine("         \\{\\color=AAAAFFFF ?}: Show/hide this documentation");

    DocForeground->addLine("");
    DocForeground->addLine("\\{\\color=AAAAAAFF Mouse Controls}:");
    DocForeground->addLine("   \\{\\color=AAAAFFFF Scroll wheel}: Zoom in/out");
    DocForeground->addLine("      \\{\\color=AAAAFFFF Left+drag}: Rotate");
    DocForeground->addLine("     \\{\\color=AAAAFFFF Right+drag}: Translate");

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
        NodeRefPtr TorusGeometryNode = makeTorus(.5, 2, 16, 16);

        // Make Main Scene Node and add the Torus
        NodeRefPtr scene = OSG::Node::create();
        scene->setCore(OSG::Group::create());
        scene->addChild(TorusGeometryNode);

        // Create the Graphics
        GraphicsRefPtr TutorialGraphics = OSG::Graphics2D::create();

        // Initialize the LookAndFeelManager to enable default settings
        LookAndFeelManager::the()->getLookAndFeel()->init();

        //Background
        SolidBackgroundRefPtr TutorialBackground = SolidBackground::create();
        TutorialBackground->setColor(Color3f(1.0,0.0,0.0));
                
        UndoManagerPtr TheUndoManager = UndoManager::create();
        CommandManagerPtr TheCommandManager = CommandManager::create(TheUndoManager);

        //UndoList
        DefaultListModelRecPtr UndoRedoListModel = DefaultListModel::create();
        UndoRedoListModel->pushBack(boost::any(std::string("Top")));

        ListRecPtr UndoRedoList = List::create();
        UndoRedoList->setPreferredSize(Vec2f(250, 300));
        UndoRedoList->setOrientation(List::VERTICAL_ORIENTATION);
        UndoRedoList->setModel(UndoRedoListModel);

        UndoRedoList->getSelectionModel()->connectSelectionChanged(boost::bind(&handleUndoRedoListSelectionChanged, _1, TheUndoManager));

        ButtonRecPtr UndoButton = OSG::Button::create();
        UndoButton->setText("Undo");
        UndoButton->setEnabled(false);
        UndoButton->connectActionPerformed(boost::bind(&handleUndoButtonAction, _1, TheUndoManager));
        

        ButtonRecPtr RedoButton = OSG::Button::create();
        RedoButton->setText("Redo");
        RedoButton->setEnabled(false);
        RedoButton->connectActionPerformed(boost::bind(&handleRedoButtonActionPerformed, _1, TheUndoManager));

        TheUndoManager->connectStateChanged(boost::bind(&handleUndoManagerStateChanged, _1, UndoButton.get(), RedoButton.get(), UndoRedoListModel.get(), TheUndoManager));

        // Create a ScrollPanel for easier viewing of the List (see 27ScrollPanel)
        ScrollPanelRefPtr UndoRedoScrollPanel = ScrollPanel::create();
        UndoRedoScrollPanel->setPreferredSize(Vec2f(200,200));
        UndoRedoScrollPanel->setHorizontalResizePolicy(ScrollPanel::RESIZE_TO_VIEW);
        UndoRedoScrollPanel->setViewComponent(UndoRedoList);


        //Edited Label
        LabelRecPtr EditedLabel = Label::create();
        EditedLabel->setText("Can be edited");
        EditedLabel->setPreferredSize(Vec2f(100.0f,18.0f));

        //Editor Field
        LabelRecPtr TheTextEditorLabel = Label::create();
        TheTextEditorLabel->setText("Text");
        TheTextEditorLabel->setPreferredSize(Vec2f(100.0f, 20.0f));

        FieldEditorComponentRefPtr TheTextEditor = FieldEditorFactory::the()->createDefaultEditor(EditedLabel,
                                                                                                  Label::TextFieldId,
                                                                                                  TheCommandManager);
        TheTextEditor->setPreferredSize(Vec2f(100.0f, 20.0f));

        LabelRecPtr ThePreferredSizeEditorLabel = Label::create();
        ThePreferredSizeEditorLabel->setText("PreferredSize");
        ThePreferredSizeEditorLabel->setPreferredSize(Vec2f(100.0f, 20.0f));

        FieldEditorComponentRefPtr ThePreferredSizeEditor =
            FieldEditorFactory::the()->createDefaultEditor(EditedLabel,
                                                           Label::PreferredSizeFieldId,
                                                           TheCommandManager);
        ThePreferredSizeEditor->setPreferredSize(Vec2f(150.0f, 20.0f));

        //Editing Panel
        LayoutRefPtr EditorPanelLayout = OSG::FlowLayout::create();
        PanelRecPtr EditorPanel = Panel::create();
        EditorPanel->setPreferredSize(Vec2f(200.0f,200.0f));
        EditorPanel->pushToChildren(TheTextEditorLabel);
        EditorPanel->pushToChildren(TheTextEditor);
        EditorPanel->pushToChildren(ThePreferredSizeEditorLabel);
        EditorPanel->pushToChildren(ThePreferredSizeEditor);
        EditorPanel->setLayout(EditorPanelLayout);

        //Undo Panel
        LabelRecPtr UndoPanelLabel = Label::create();
        UndoPanelLabel->setText("Undo Panel");
        UndoPanelLabel->setPreferredSize(Vec2f(100.0f, 20.0f));

        LayoutRefPtr UndoPanelLayout = OSG::FlowLayout::create();
        PanelRecPtr UndoPanel = Panel::create();
        UndoPanel->setPreferredSize(Vec2f(300.0f,300.0f));
        UndoPanel->pushToChildren(UndoPanelLabel);
        UndoPanel->pushToChildren(UndoRedoScrollPanel);
        UndoPanel->pushToChildren(UndoButton);
        UndoPanel->pushToChildren(RedoButton);
        UndoPanel->setLayout(UndoPanelLayout);

        // Create The Main InternalWindow
        // Create Background to be used with the Main InternalWindow
        ColorLayerRefPtr MainInternalWindowBackground = OSG::ColorLayer::create();
        MainInternalWindowBackground->setColor(Color4f(1.0,1.0,1.0,0.5));
        InternalWindowRefPtr MainInternalWindow = OSG::InternalWindow::create();
        LayoutRefPtr MainInternalWindowLayout = OSG::FlowLayout::create();
        MainInternalWindow->pushToChildren(EditedLabel);
        MainInternalWindow->pushToChildren(EditorPanel);
        MainInternalWindow->pushToChildren(UndoPanel);
        MainInternalWindow->setLayout(MainInternalWindowLayout);
        MainInternalWindow->setBackgrounds(MainInternalWindowBackground);
        MainInternalWindow->setAlignmentInDrawingSurface(Vec2f(0.5f,0.5f));
        MainInternalWindow->setScalingInDrawingSurface(Vec2f(0.95f,0.95f));
        MainInternalWindow->setDrawTitlebar(false);
        MainInternalWindow->setResizable(false);

        // Create the Drawing Surface
        UIDrawingSurfaceRefPtr TutorialDrawingSurface = UIDrawingSurface::create();
        TutorialDrawingSurface->setGraphics(TutorialGraphics);
        TutorialDrawingSurface->setEventProducer(TutorialWindow);
        
        TutorialDrawingSurface->openWindow(MainInternalWindow);
        
        // Create the UI Foreground Object
        UIForegroundRefPtr TutorialUIForeground = OSG::UIForeground::create();

        TutorialUIForeground->setDrawingSurface(TutorialDrawingSurface);

        // Tell the Manager what to manage
        sceneManager.setWindow(TutorialWindow);
        sceneManager.setRoot(scene);

        // Add the UI Foreground Object to the Scene
        ViewportRefPtr TutorialViewport = sceneManager.getWindow()->getPort(0);
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
                                    "02GenericFieldEditor");

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
    ColorKeyframes->addKeyframe(Color4f(1.0f,1.0f,1.0f,1.0f),0.0f);
    ColorKeyframes->addKeyframe(Color4f(1.0f,1.0f,1.0f,1.0f),5.0f);
    ColorKeyframes->addKeyframe(Color4f(1.0f,1.0f,1.0f,0.0f),7.0f);
    
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

