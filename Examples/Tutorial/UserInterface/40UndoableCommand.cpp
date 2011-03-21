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

// Activate the OpenSG namespace
OSG_USING_NAMESPACE

WindowEventProducerRecPtr TutorialWindow;

// Forward declaration so we can have the interesting stuff upfront
void display(SimpleSceneManager *mgr);
void reshape(Vec2f Size, SimpleSceneManager *mgr);

// 01 Button Headers
#include "OSGButton.h"
#include "OSGLabel.h"
#include "OSGLayers.h"
#include "OSGBorders.h"
#include "OSGFlowLayout.h"
#include "OSGList.h"
#include "OSGDefaultListModel.h"
#include "OSGScrollPanel.h"

#include "OSGUndoableCommand.h"
#include "OSGCommandManager.h"
#include "OSGUndoManager.h"

void keyPressed(KeyEventDetails* const details)
{
    if(details->getKey() == KeyEventDetails::KEY_Q &&
       details->getModifiers() & KeyEventDetails::KEY_MODIFIER_COMMAND)
    {
        dynamic_cast<WindowEventProducer*>(details->getSource())->closeWindow();
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
    DocForeground->addLine("of \\{\\color=AAAA00FF UndoableCommand}, \\{\\color=AAAA00FF UndoManager}, and \\{\\color=AAAA00FF CommandManager}.");
    DocForeground->addLine("");
    
    DocForeground->addLine("\\{\\color=AAAAAAFF Key Commands}:");
    DocForeground->addLine("   \\{\\color=AAAAFFFF Cmd+q}: Close the application");
    DocForeground->addLine("       \\{\\color=AAAAFFFF ?}: Show/hide this documentation");

    return SimpleTextForegroundTransitPtr(DocForeground);
}


class SetBorderColor;
typedef boost::shared_ptr<SetBorderColor> SetBorderColorRecPtr;

class SetBorderColor: public UndoableCommand
{
  protected:
    typedef UndoableCommand Inherited;

    LineBorderRecPtr _TheBorder;
    Color4f _ChangeToColor;
    Color4f _PreviousColor;

    SetBorderColor(LineBorderRecPtr TheBorder, Color4f ChangeToColor) : Inherited(),
    _TheBorder(TheBorder),
    _ChangeToColor(ChangeToColor)
    {
    }

    SetBorderColor(const SetBorderColor& source) : Inherited(source),
    _TheBorder(source._TheBorder),
    _ChangeToColor(source._ChangeToColor),
    _PreviousColor(source._PreviousColor)

    {
    }

    static CommandType _Type;

    void execute(void)
    {
        _HasBeenDone = true;

        _PreviousColor = _TheBorder->getColor();

        _TheBorder->setColor(_ChangeToColor);
    }
  public:

    std::string getPresentationName(void) const
    {
        return getCommandDescription();
    }

    std::string getCommandDescription(void) const
    {
        std::ostringstream Temp;
        OutStream osgStream(Temp);
        FieldTraits<Color4f>::putToStream(_ChangeToColor, osgStream);
        return std::string("Set Border Color to: ") + Temp.str();
    }

    void redo(void)
    {
        Inherited::redo();
        _TheBorder->setColor(_ChangeToColor);
    }

    void undo(void)
    {
        Inherited::undo();
        _TheBorder->setColor(_PreviousColor);
    }

    bool isSignificant(void) const
    {
        return _ChangeToColor != _PreviousColor;
    }

    const CommandType &getType(void) const
    {
        return _Type;
    }

    static const CommandType &getClassType(void)
    {
        return _Type;
    }

    ~SetBorderColor(void)
    {
    }

    static SetBorderColorRecPtr create(LineBorderRecPtr TheBorder, Color4f ChangeToColor)
    {
        return SetBorderColorRecPtr(new SetBorderColor(TheBorder, ChangeToColor));
    }
};

CommandType SetBorderColor::_Type("SetBorderColor", "UndoableCommand");

class SetBackgroundColor;
typedef boost::shared_ptr<SetBackgroundColor> SetBackgroundColorRecPtr;

class SetBackgroundColor: public UndoableCommand
{
  protected:
    typedef UndoableCommand Inherited;

    ColorLayerRecPtr _TheBackground;
    Color4f _ChangeToColor;
    Color4f _PreviousColor;

    SetBackgroundColor(ColorLayerRecPtr TheBackground, Color4f ChangeToColor) : Inherited(),
    _TheBackground(TheBackground),
    _ChangeToColor(ChangeToColor)
    {
    }

    SetBackgroundColor(const SetBackgroundColor& source) : Inherited(source),
    _TheBackground(source._TheBackground),
    _ChangeToColor(source._ChangeToColor),
    _PreviousColor(source._PreviousColor)

    {
    }

    static CommandType _Type;

    void execute(void)
    {
        _HasBeenDone = true;

        _PreviousColor = _TheBackground->getColor();

        _TheBackground->setColor(_ChangeToColor);
    }
  public:

    std::string getPresentationName(void) const
    {
        return getCommandDescription();
    }

    std::string getCommandDescription(void) const
    {
        std::ostringstream Temp;
        OutStream osgStream(Temp);
        FieldTraits<Color4f>::putToStream(_ChangeToColor, osgStream);
        return std::string("Set Background Color to: ") + Temp.str();
    }


    void redo(void)
    {
        Inherited::redo();
        _TheBackground->setColor(_ChangeToColor);
    }

    void undo(void)
    {
        Inherited::undo();
        _TheBackground->setColor(_PreviousColor);
    }

    bool isSignificant(void) const
    {
        return _ChangeToColor != _PreviousColor;
    }

    const CommandType &getType(void) const
    {
        return _Type;
    }

    static const CommandType &getClassType(void)
    {
        return _Type;
    }

    ~SetBackgroundColor(void)
    {
    }

    static SetBackgroundColorRecPtr create(ColorLayerRecPtr TheBackground, Color4f ChangeToColor)
    {
        return SetBackgroundColorRecPtr(new SetBackgroundColor(TheBackground, ChangeToColor));
    }
};

CommandType SetBackgroundColor::_Type("SetBackgroundColor", "UndoableCommand");

void handleSetBorderColorAction(ActionEventDetails* const details,
                                CommandManagerPtr TheCommandManager,
                                LineBorder* const TheBorder,
                                Color4f ChangeToColor)
{
    SetBorderColorRecPtr TheCommand = SetBorderColor::create(TheBorder, ChangeToColor);

    TheCommandManager->executeCommand(TheCommand);
}

void handleSetBackgroundColorAction(ActionEventDetails* const details,
                                    CommandManagerPtr TheCommandManager,
                                    ColorLayer* const TheBackground,
                                    Color4f ChangeToColor)
{
    UndoableCommandPtr TheCommand = SetBackgroundColor::create(TheBackground, ChangeToColor);

    TheCommandManager->executeCommand(TheCommand);
}

void handleUndoButtonAction(ActionEventDetails* const details,
                            UndoManagerPtr TheUndoManager)
{
    TheUndoManager->undo();
}

void handleRedoButtonAction(ActionEventDetails* const details,
                            UndoManagerPtr TheUndoManager)
{
    TheUndoManager->redo();
}

void handleUndoManagerStateChanged(ChangeEventDetails* const details,
                                   DefaultListModel* const UndoRedoListModel,
                                   UndoManagerPtr TheUndoManager,
                                   Button* const UndoButton,
                                   Button* const RedoButton)
{
    while(UndoRedoListModel->getSize()-1 > TheUndoManager->numberOfRedos() + TheUndoManager->numberOfUndos())
    {
        UndoRedoListModel->popBack();
    }

    //Resize
    while(UndoRedoListModel->getSize()-1 < TheUndoManager->numberOfRedos() + TheUndoManager->numberOfUndos())
    {
        UndoRedoListModel->pushBack(boost::any(std::string("")));
    }

    UInt32 UndoCount(TheUndoManager->numberOfUndos());
    for(UInt32 i(0) ; i<UndoCount ; ++i)
    {
        UndoRedoListModel->set(i+1, boost::any(std::string(TheUndoManager->editToBeUndone(i)->getUndoPresentationName())));
    }
    UInt32 RedoCount(TheUndoManager->numberOfRedos());
    for(UInt32 i(0) ; i<RedoCount ; ++i)
    {
        UndoRedoListModel->set(i+TheUndoManager->numberOfUndos()+1, boost::any(std::string(TheUndoManager->editToBeRedone(i)->getRedoPresentationName())));
    }

    if((UndoCount == 0 && UndoButton->getEnabled()) ||
       (UndoCount != 0 && !UndoButton->getEnabled()) )
    {
        UndoButton->setEnabled(UndoCount != 0);
    }
    if((RedoCount == 0 && RedoButton->getEnabled()) ||
       (RedoCount != 0 && !RedoButton->getEnabled()) )
    {
        RedoButton->setEnabled(RedoCount != 0);
    }
}

void handleUndoRedoListSelectionChanged(ListSelectionEventDetails* const details,
                                        List* const UndoRedoList,
                                        UndoManagerPtr TheUndoManager)
{
    if(!UndoRedoList->getSelectionModel()->isSelectionEmpty())
    {
        Int32 ListSelectedIndex(UndoRedoList->getSelectionModel()->getAnchorSelectionIndex());

        TheUndoManager->undoOrRedoTo(ListSelectedIndex);
    }
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

        TutorialWindow->connectKeyTyped(boost::bind(keyPressed, _1));

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
        /******************************************************

          Create an Button Component and
          a simple Font.
          See 17Label_Font for more
          information about Fonts.

         ******************************************************/

        LineBorderRecPtr ChangableBorder = LineBorder::create();
        ChangableBorder->setColor(Color4f(0.0,0.0,0.0,1.0));

        ColorLayerRecPtr ChangableBackground = ColorLayer::create();
        ChangableBackground->setColor(Color4f(1.0,1.0,1.0,1.0));

        LabelRecPtr ChangableLabel = Label::create();

        ChangableLabel->setText("Changable");
        ChangableLabel->setBorders(ChangableBorder);
        ChangableLabel->setBackgrounds(ChangableBackground);

        //Command Buttons
        UndoManagerPtr TheUndoManager = UndoManager::create();

        CommandManagerPtr TheCommandManager = CommandManager::create(TheUndoManager);
        ButtonRecPtr BorderRedButton = Button::create();
        BorderRedButton->setText("Border Red");
        BorderRedButton->setPreferredSize(Vec2f(85, 20));
        BorderRedButton->connectActionPerformed(boost::bind(handleSetBorderColorAction,
                                                            _1,
                                                            TheCommandManager,
                                                            ChangableBorder.get(),
                                                            Color4f(1.0,0.0,0.0,1.0)));

        ButtonRecPtr BorderGreenButton = Button::create();
        BorderGreenButton->setText("Border Green");
        BorderGreenButton->setPreferredSize(Vec2f(85, 20));
        BorderGreenButton->connectActionPerformed(boost::bind(handleSetBorderColorAction,
                                                            _1,
                                                            TheCommandManager,
                                                            ChangableBorder.get(),
                                                            Color4f(0.0,1.0,0.0,1.0)));

        ButtonRecPtr BorderBlueButton = Button::create();
        BorderBlueButton->setText("Border Blue");
        BorderBlueButton->setPreferredSize(Vec2f(85, 20));
        BorderBlueButton->connectActionPerformed(boost::bind(handleSetBorderColorAction,
                                                            _1,
                                                            TheCommandManager,
                                                            ChangableBorder.get(),
                                                            Color4f(0.0,0.0,1.0,1.0)));

        //Background
        ButtonRecPtr BackgroundRedButton = Button::create();
        BackgroundRedButton->setText("Background Red");
        BackgroundRedButton->setPreferredSize(Vec2f(105, 20));
        BackgroundRedButton->connectActionPerformed(boost::bind(handleSetBackgroundColorAction,
                                                                _1,
                                                                TheCommandManager,
                                                                ChangableBackground.get(),
                                                                Color4f(1.0,0.0,0.0,1.0)));

        ButtonRecPtr BackgroundGreenButton = Button::create();
        BackgroundGreenButton->setText("Background Green");
        BackgroundGreenButton->setPreferredSize(Vec2f(105, 20));
        BackgroundGreenButton->connectActionPerformed(boost::bind(handleSetBackgroundColorAction,
                                                                _1,
                                                                TheCommandManager,
                                                                ChangableBackground.get(),
                                                                Color4f(0.0,1.0,0.0,1.0)));

        ButtonRecPtr BackgroundBlueButton = Button::create();
        BackgroundBlueButton->setText("Background Blue");
        BackgroundBlueButton->setPreferredSize(Vec2f(105, 20));
        BackgroundBlueButton->connectActionPerformed(boost::bind(handleSetBackgroundColorAction,
                                                                _1,
                                                                TheCommandManager,
                                                                ChangableBackground.get(),
                                                                Color4f(0.0,0.0,1.0,1.0)));

        //UndoList
        DefaultListModelRecPtr UndoRedoListModel = DefaultListModel::create();
        UndoRedoListModel->pushBack(boost::any(std::string("Top")));

        ListRecPtr UndoRedoList = List::create();
        UndoRedoList->setPreferredSize(Vec2f(200, 300));
        UndoRedoList->setOrientation(List::VERTICAL_ORIENTATION);
        UndoRedoList->setModel(UndoRedoListModel);

        UndoRedoList->getSelectionModel()->connectSelectionChanged(boost::bind(handleUndoRedoListSelectionChanged,
                                                                               _1,
                                                                               UndoRedoList.get(),
                                                                               TheUndoManager));

        ButtonRecPtr UndoButton = Button::create();
        UndoButton->setText("Undo");
        UndoButton->setEnabled(TheUndoManager->numberOfUndos() != 0);
        UndoButton->connectActionPerformed(boost::bind(handleUndoButtonAction,
                                                       _1,
                                                       TheUndoManager));


        ButtonRecPtr RedoButton = Button::create();
        RedoButton->setText("Redo");
        RedoButton->setEnabled(TheUndoManager->numberOfRedos() != 0);
        RedoButton->connectActionPerformed(boost::bind(handleRedoButtonAction,
                                                       _1,
                                                       TheUndoManager));

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
        MainInternalWindow->pushToChildren(BorderRedButton);
        MainInternalWindow->pushToChildren(BorderGreenButton);
        MainInternalWindow->pushToChildren(BorderBlueButton);
        MainInternalWindow->pushToChildren(BackgroundRedButton);
        MainInternalWindow->pushToChildren(BackgroundGreenButton);
        MainInternalWindow->pushToChildren(BackgroundBlueButton);
        MainInternalWindow->pushToChildren(ChangableLabel);
        MainInternalWindow->pushToChildren(UndoRedoScrollPanel);
        MainInternalWindow->pushToChildren(UndoButton);
        MainInternalWindow->pushToChildren(RedoButton);
        MainInternalWindow->setLayout(MainInternalWindowLayout);
        MainInternalWindow->setBackgrounds(MainInternalWindowBackground);
        MainInternalWindow->setAlignmentInDrawingSurface(Vec2f(0.5f,0.5f));
        MainInternalWindow->setScalingInDrawingSurface(Vec2f(0.95f,0.95f));
        MainInternalWindow->setDrawTitlebar(false);
        MainInternalWindow->setResizable(false);


        TheUndoManager->connectStateChanged(boost::bind(handleUndoManagerStateChanged,
                                                        _1,
                                                        UndoRedoListModel.get(),
                                                        TheUndoManager,
                                                        UndoButton.get(),
                                                        RedoButton.get()));

        // Create the Drawing Surface
        UIDrawingSurfaceRecPtr TutorialDrawingSurface = UIDrawingSurface::create();
        TutorialDrawingSurface->setGraphics(TutorialGraphics);
        TutorialDrawingSurface->setEventProducer(TutorialWindow);

        TutorialDrawingSurface->openWindow(MainInternalWindow);

        // Create the UI Foreground Object
        UIForegroundRecPtr TutorialUIForeground = UIForeground::create();

        TutorialUIForeground->setDrawingSurface(TutorialDrawingSurface);

        // Tell the Manager what to manage
        sceneManager.setRoot(scene);

        // Add the UI Foreground Object to the Scene
        ViewportRecPtr TutorialViewport = sceneManager.getWindow()->getPort(0);
        TutorialViewport->addForeground(TutorialUIForeground);

        //Create the Documentation Foreground and add it to the viewport
        SimpleScreenDoc TheSimpleScreenDoc(&sceneManager, TutorialWindow);

        // Show the whole Scene
        sceneManager.showAll();


        //Open Window
        Vec2f WinSize(TutorialWindow->getDesktopSize() * 0.85f);
        Pnt2f WinPos((TutorialWindow->getDesktopSize() - WinSize) *0.5);
        TutorialWindow->openWindow(WinPos,
                                   WinSize,
                                   "40UndoableCommand");

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

