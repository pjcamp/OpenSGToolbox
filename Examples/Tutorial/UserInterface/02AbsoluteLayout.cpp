/*************************************************
  Welcome to the 02AbsoluteLayout tutorial.  This 
  tutorial details how to use the AbsoluteLayout
  to place components within a frame.  The following
  components are introduced:

  AbsoluteLayout
  AbsoluteLayoutConstraints

  The AbsoluteLayout is used when a user wants an
  interface in which components are precisely
  located regardless of window size.  Components
  are placed absolutely by pixel location, which
  do not change when windows are resized.

  The following all are shown and explained
  within this tutorial:
  Creating AbsoluteLayout
  Creating Constraints
  Defining Constraints
  Adding Contrainst to components
  Creating a frame using AbsoluteLayout

  These tutorials contain potentially relevant
information:



 *************************************************/


// OpenSG Tutorial Example: Using the AbsoluteLayout
//
// This tutorial explains how to place ExampleButtons within a 
// frame utilizing the Absolute Layout to manage the layout 
// through the OSG User Interface library.
// 
// Includes: placing multiple ExampleButtons and using 
// AbsoluteLayoutConstraints to locate the ExampleButtons.

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

// Include AbsoluteLayout and AbsoluteLayoutConstraints header files
#include "OSGAbsoluteLayout.h"
#include "OSGAbsoluteLayoutConstraints.h"
#include "OSGButton.h"
#include "OSGColorLayer.h"

void keyPressed(KeyEventDetails* const details);

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
    DocForeground->addLine("of \\{\\color=AAAA00FF AbsoluteLayout} and \\{\\color=AAAA00FF AbsoluteLayoutConstraints}.");
    DocForeground->addLine("");
    
    DocForeground->addLine("\\{\\color=AAAAAAFF Key Commands}:");
    DocForeground->addLine("   \\{\\color=AAAAFFFF Cmd+q}: Close the application");
    DocForeground->addLine("       \\{\\color=AAAAFFFF ?}: Show/hide this documentation");

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

          Create three Button Components and three 
          AbsoluteLayoutConstraints.

          AbsoluteLayoutConstraints are used within the 
          AbsoluteLayout to define where the Components 
          will be placed.  Each Component is individually
          placed to an exact location using an 
          AbsoluteLayoutConstraint.

         ******************************************************/

        ButtonRecPtr ExampleButton1 = Button::create();
        ButtonRecPtr ExampleButton2 = Button::create();
        ButtonRecPtr ExampleButton3 = Button::create();

        AbsoluteLayoutConstraintsRecPtr ExampleButtonConstraints1 = AbsoluteLayoutConstraints::create();
        AbsoluteLayoutConstraintsRecPtr ExampleButtonConstraints2 = AbsoluteLayoutConstraints::create();
        AbsoluteLayoutConstraintsRecPtr ExampleButtonConstraints3 = AbsoluteLayoutConstraints::create();

        /******************************************************

          Edit the AbsoluteLayoutConstraints.

          -setPositition(Pnt2f): Determine the location
          the Constraints represent within the 
          AbsoluteLayout, referenced from the 
          upper left hand corner of the Layout's
          ComponentContainer.  

          Note that this is not a relative location, so
          if the ComponentContainer becomes resized and the 
          AbsoluteLayoutConstraints would place the 
          Component they are assigned to outside the
          Layout, then the Component will not be 
          displayed.  Depending on where the 

          Define the AbsoluteLayoutConstraints (where Buttons 
          are located in the Layout).  setPosition gives you 
          the location of the Button relative to the Layout
          Manager's upper left hand corner.  Buttons will
          not display if their AbsoluteLayoutConstraints 
          place them outside the Frame in which they are to
          be rendered (the part within the Frame still does
          display).  Changing the window size shows an 
          example of this.

         ******************************************************/

        ExampleButtonConstraints1->setPosition(Pnt2f(0,150));

        ExampleButtonConstraints2->setPosition(Pnt2f(200,200));

        // Note that this will cause the ExampleButton's position to overlap with Button2
        // when the program is run; the AbsoluteLayoutConstraints will overlap
        // if the specified coordinates overlap
        ExampleButtonConstraints3->setPosition(Pnt2f(150,220));

        /******************************************************

          Edit Button Components and assign Text,
          PreferredSize, and AbsoluteLayoutConstraints.

          By assigning AbsoluteLayoutContraints to
          Components, those Components are then
          displayed in the Layout according to their
          AbsoluteLayoutConstraints.  

          -setContraints(ConstraintName): Determines
          the Constraints for the Component.  In
          AbsoluteLayout, Components will not
          be displayed without Constraints being
          assigned.

          Note: see below for importance of order
          when adding Components to AbsoluteLayouts 

         ******************************************************/

        ExampleButton1->setPreferredSize(Vec2f(100,50));
        ExampleButton1->setText("Button 1");
        ExampleButton1->setConstraints(ExampleButtonConstraints1);

        ExampleButton2->setPreferredSize(Vec2f(100,50));
        ExampleButton2->setText("Button 2");
        ExampleButton2->setConstraints(ExampleButtonConstraints2);

        ExampleButton3->setPreferredSize(Vec2f(100,50));
        ExampleButton3->setText("Button 3");
        ExampleButton3->setConstraints(ExampleButtonConstraints3);

        //Absolute Layout
        LayoutRecPtr MainInternalWindowLayout = AbsoluteLayout::create();

        // Create The Main InternalWindow
        // Create Background to be used with the Main InternalWindow
        ColorLayerRecPtr MainInternalWindowBackground = ColorLayer::create();
        MainInternalWindowBackground->setColor(Color4f(1.0,1.0,1.0,0.5));

        InternalWindowRecPtr MainInternalWindow = InternalWindow::create();
        MainInternalWindow->pushToChildren(ExampleButton1);
        MainInternalWindow->pushToChildren(ExampleButton3);
        MainInternalWindow->pushToChildren(ExampleButton2);
        MainInternalWindow->setLayout(MainInternalWindowLayout);
        MainInternalWindow->setBackgrounds(MainInternalWindowBackground);
        MainInternalWindow->setAlignmentInDrawingSurface(Vec2f(0.5f,0.5f));
        MainInternalWindow->setScalingInDrawingSurface(Vec2f(0.5f,0.5f));
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
                                   "02AbsoluteLayout");

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

void keyPressed(KeyEventDetails* const details)
{
    if(details->getKey() == KeyEventDetails::KEY_Q && details->getModifiers() & KeyEventDetails::KEY_MODIFIER_COMMAND)
    {
        dynamic_cast<WindowEventProducer*>(details->getSource())->closeWindow();
    }
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

