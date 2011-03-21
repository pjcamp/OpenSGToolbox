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

// Forward declaration so we can have the interesting stuff upfront
void display(SimpleSceneManager *mgr);
void reshape(Vec2f Size, SimpleSceneManager *mgr);

// 30RotatedComponent Headers
#include "OSGFlowLayout.h"
#include "OSGUIFont.h"
#include "OSGColorLayer.h"
#include "OSGPanel.h"
#include "OSGButton.h"
#include "OSGToggleButton.h"
#include "OSGRotatedComponent.h"

ComponentTransitPtr createPanel(void);

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
    DocForeground->addLine("of a \\{\\color=AAAA00FF RotatedComponent}.");
    DocForeground->addLine("");
    
    DocForeground->addLine("\\{\\color=AAAAAAFF Key Commands}:");
    DocForeground->addLine("   \\{\\color=AAAAFFFF Cmd+q}: Close the application");
    DocForeground->addLine("       \\{\\color=AAAAFFFF ?}: Show/hide this documentation");

    return SimpleTextForegroundTransitPtr(DocForeground);
}


/******************************************************

  Create connection to let RotatedComponent
  rotate

 ******************************************************/    
void handleUpdate(UpdateEventDetails* const details,
                  RotatedComponent* const ExampleRotatedComponent)
{
    static Time Elps(0.0f);
    Real32 RadPerSec(3.14159f);

    // Increment the time
    Elps += details->getElapsedTime();

    // Change the RotatedComponent Angle
    ExampleRotatedComponent->setAngle(Elps * RadPerSec);
}

// Create Listener to turn rotating on/off
void handleButtonSelected(ButtonSelectedEventDetails* const details,
                          WindowEventProducer* const TutorialWindow,
                          RotatedComponent* const ExampleRotatedComponent)
{
    // When Selected, get the selected Component (in this case
    // a ToggleButton) and then change its text accordingly.
    dynamic_cast<ToggleButton*>(details->getSource())->setText("Stop Rotating");

    TutorialWindow->connectUpdate(boost::bind(handleUpdate, _1,
                                              ExampleRotatedComponent));
}

// Change text when deselected
void handleButtonDeselected(ButtonSelectedEventDetails* const details,
                            WindowEventProducer* const TutorialWindow,
                            RotatedComponent* const ExampleRotatedComponent)
{
    dynamic_cast<ToggleButton*>(details->getSource())->setText("Start Rotating");

    TutorialWindow->disconnectAllSlotsUpdate();
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

          Create a RotatedComponent.
          -setAngle(Angle, in radians): Determine
          the angle the Component initially
          is rotated.
          -setInternalComponent(Component): 
          Determine what Component will
          be rotated.
          -setResizePolicy(RotatedComponent::ENUM):
          Takes NO_RESIZING, RESIZE_TO_MIN, or
          RESIZE_TO_MAX arguments.

         ******************************************************/    

        RotatedComponentRecPtr TheRotatedComponent = RotatedComponent::create();
        // Define PI
        Real32 PI(3.14159);
        TheRotatedComponent->setAngle(PI/4);
        ComponentRecPtr InnerPanel = createPanel();
        TheRotatedComponent->setInternalComponent(InnerPanel);
        TheRotatedComponent->setResizePolicy(RotatedComponent::RESIZE_TO_MIN);

        /******************************************************

          Create a ToggleButton which can 
          be used to start and stop the 
          Button from rotating.

            Note: due to the way FlowLayout works
            you will notice that this ToggleButton
            will move as well.  In cases where
            a Rotating Component is used, an 
            alternate Layout may be preferred
            to prevent other Components from 
            moving as well.  This is 
            intentionally left this way to 
            illustrate why this might be the case.
            A SplitPanel with fixed divider for 
            example would prevent the ToggleButton
            from moving, while still allowing the 
            Panel to move freely.

         ******************************************************/    
        ToggleButtonRecPtr RotateControlButton = ToggleButton::create();
        RotateControlButton->setText("Start Rotating");
        RotateControlButton->setPreferredSize(Vec2f(100.0f, 29.0f));

        RotateControlButton->connectButtonSelected(boost::bind(handleButtonSelected, _1,
                                                               TutorialWindow.get(),
                                                               TheRotatedComponent.get()));
        RotateControlButton->connectButtonDeselected(boost::bind(handleButtonDeselected, _1,
                                                                 TutorialWindow.get(),
                                                                 TheRotatedComponent.get()));

        // Create The Main InternalWindow
        // Create Background to be used with the Main InternalWindow
        ColorLayerRecPtr MainInternalWindowBackground = ColorLayer::create();
        MainInternalWindowBackground->setColor(Color4f(1.0,1.0,1.0,0.5));

        LayoutRecPtr MainInternalWindowLayout = FlowLayout::create();

        InternalWindowRecPtr MainInternalWindow = InternalWindow::create();
        MainInternalWindow->pushToChildren(TheRotatedComponent);
        MainInternalWindow->pushToChildren(RotateControlButton);
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
                                   "30RotatedComponent");

        //Enter main Loop
        TutorialWindow->mainLoop();
    }

    osgExit();

    return 0;
}

ComponentTransitPtr createPanel(void)
{
    // Function to create a panel to be rotated
    ButtonRecPtr button1 = Button::create();
    ButtonRecPtr button2 = Button::create();
    ButtonRecPtr button3 = Button::create();
    ButtonRecPtr button4 = Button::create();
    FlowLayoutRecPtr panel1Layout = FlowLayout::create();
    PanelRecPtr panel1 = Panel::create();
    panel1->pushToChildren(button1);    
    panel1->pushToChildren(button2);
    panel1->pushToChildren(button3);
    panel1->pushToChildren(button4);
    panel1->setLayout(panel1Layout);
    panel1->setPreferredSize(Vec2f(100, 220));
    button1->setText("This");
    button2->setText("Can");
    button3->setText("Be");
    button4->setText("Rotated!");

    return ComponentTransitPtr(panel1);
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

