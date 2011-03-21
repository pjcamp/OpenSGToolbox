// OpenSG Tutorial Example: Creating a List
//
// This tutorial explains how to create a List 
// via the  OSG User Interface library.
// 
// Includes: placing multiple buttons using Flow Layout


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

// Forward declaration so we can have the interesting stuff upfront
void display(SimpleSceneManager *mgr);
void reshape(Vec2f Size, SimpleSceneManager *mgr);

// 18List Headers
#include "OSGLookAndFeelManager.h"
#include "OSGFlowLayout.h"
#include "OSGMenuButton.h"
#include "OSGLayers.h"

// List header files
#include "OSGDefaultListModel.h"

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
    DocForeground->addLine("of a \\{\\color=AAAA00FF MenuButton}.");
    DocForeground->addLine("");
    
    DocForeground->addLine("\\{\\color=AAAAAAFF Key Commands}:");
    DocForeground->addLine("   \\{\\color=AAAAFFFF Cmd+q}: Close the application");
    DocForeground->addLine("       \\{\\color=AAAAFFFF ?}: Show/hide this documentation");

    return SimpleTextForegroundTransitPtr(DocForeground);
}

void handleAction(ActionEventDetails* const details)
{
    MenuButton* TheMenuButton(dynamic_cast<MenuButton*>(details->getSource()));
    if(TheMenuButton != NULL)
    {
        try
        {
            std::string StrValue = boost::any_cast<std::string>(TheMenuButton->getSelectionValue());
            std::cout << "Selected: " << StrValue << std::endl;
        }
        catch(boost::bad_any_cast &ex)
        {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
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

        //Create list data model to use for the Popup menu
        DefaultListModelRecPtr ExampleListModel = DefaultListModel::create();
        ExampleListModel->pushBack(boost::any(std::string("Red")));
        ExampleListModel->pushBack(boost::any(std::string("Green")));
        ExampleListModel->pushBack(boost::any(std::string("Blue")));
        ExampleListModel->pushBack(boost::any(std::string("Orange")));
        ExampleListModel->pushBack(boost::any(std::string("Purple")));
        ExampleListModel->pushBack(boost::any(std::string("Yellow")));
        ExampleListModel->pushBack(boost::any(std::string("White")));
        ExampleListModel->pushBack(boost::any(std::string("Black")));
        ExampleListModel->pushBack(boost::any(std::string("Gray")));
        ExampleListModel->pushBack(boost::any(std::string("Brown")));
        ExampleListModel->pushBack(boost::any(std::string("Indigo")));
        ExampleListModel->pushBack(boost::any(std::string("Pink")));
        ExampleListModel->pushBack(boost::any(std::string("Violet")));
        ExampleListModel->pushBack(boost::any(std::string("Mauve")));
        ExampleListModel->pushBack(boost::any(std::string("Peach")));
        ExampleListModel->pushBack(boost::any(std::string("Red")));
        ExampleListModel->pushBack(boost::any(std::string("Green")));
        ExampleListModel->pushBack(boost::any(std::string("Blue")));
        ExampleListModel->pushBack(boost::any(std::string("Orange")));
        ExampleListModel->pushBack(boost::any(std::string("Purple")));
        ExampleListModel->pushBack(boost::any(std::string("Yellow")));
        ExampleListModel->pushBack(boost::any(std::string("White")));
        ExampleListModel->pushBack(boost::any(std::string("Black")));
        ExampleListModel->pushBack(boost::any(std::string("Gray")));
        ExampleListModel->pushBack(boost::any(std::string("Brown")));
        ExampleListModel->pushBack(boost::any(std::string("Indigo")));
        ExampleListModel->pushBack(boost::any(std::string("Pink")));
        ExampleListModel->pushBack(boost::any(std::string("Violet")));
        ExampleListModel->pushBack(boost::any(std::string("Mauve")));
        ExampleListModel->pushBack(boost::any(std::string("Peach")));
        ExampleListModel->pushBack(boost::any(std::string("Red")));
        ExampleListModel->pushBack(boost::any(std::string("Green")));
        ExampleListModel->pushBack(boost::any(std::string("Blue")));
        ExampleListModel->pushBack(boost::any(std::string("Orange")));
        ExampleListModel->pushBack(boost::any(std::string("Purple")));
        ExampleListModel->pushBack(boost::any(std::string("Yellow")));
        ExampleListModel->pushBack(boost::any(std::string("White")));
        ExampleListModel->pushBack(boost::any(std::string("Black")));
        ExampleListModel->pushBack(boost::any(std::string("Gray")));
        ExampleListModel->pushBack(boost::any(std::string("Brown")));
        ExampleListModel->pushBack(boost::any(std::string("Indigo")));
        ExampleListModel->pushBack(boost::any(std::string("Pink")));
        ExampleListModel->pushBack(boost::any(std::string("Violet")));
        ExampleListModel->pushBack(boost::any(std::string("Mauve")));
        ExampleListModel->pushBack(boost::any(std::string("Peach")));

        //Create the MenuButton
        MenuButtonRecPtr ExampleMenuButton = MenuButton::create();

        ExampleMenuButton->setText("Menu Button");
        ExampleMenuButton->setPreferredSize(Vec2f(120, 20));
        ExampleMenuButton->setModel(ExampleListModel);
        ExampleMenuButton->connectActionPerformed(boost::bind(handleAction, _1));

        // Create MainFramelayout
        FlowLayoutRecPtr MainInternalWindowLayout = FlowLayout::create();
        MainInternalWindowLayout->setOrientation(FlowLayout::HORIZONTAL_ORIENTATION);
        MainInternalWindowLayout->setMinorAxisAlignment(0.2f);

        // Create The Main InternalWindow
        // Create Background to be used with the Main InternalWindow
        ColorLayerRecPtr MainInternalWindowBackground = ColorLayer::create();
        MainInternalWindowBackground->setColor(Color4f(1.0,1.0,1.0,0.5));

        InternalWindowRecPtr MainInternalWindow = InternalWindow::create();
        MainInternalWindow->pushToChildren(ExampleMenuButton);
        MainInternalWindow->setLayout(MainInternalWindowLayout);
        MainInternalWindow->setBackgrounds(MainInternalWindowBackground);
        MainInternalWindow->setAlignmentInDrawingSurface(Vec2f(0.5f,0.5f));
        MainInternalWindow->setScalingInDrawingSurface(Vec2f(0.8f,0.8f));
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
                                   "43MenuButton");

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

