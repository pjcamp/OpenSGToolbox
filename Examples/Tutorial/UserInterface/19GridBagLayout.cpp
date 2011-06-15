// OpenSG Tutorial Example: Using the GridBag Layout
//        to place Components 
//
// This tutorial explains how to place ExampleButtons within a 
// frame utilizing the GridBag Layout command to 
// manage the layout through the OSG User Interface library.
//
// GridBagLayout is incredibly customizable with many more
// features than most Layouts
// 
// Includes: using GridBagLayout and GridBagLayoutConstraints

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


// 19GridBagLayout Headers
#include "OSGUIForeground.h"
#include "OSGUIDrawingSurface.h"
#include "OSGGraphics2D.h"
#include "OSGButton.h"
#include "OSGLookAndFeelManager.h"
#include "OSGColorLayer.h"
#include "OSGGridBagLayout.h"
#include "OSGGridBagLayoutConstraints.h"

void keyPressed(KeyEventDetails* const details)
{
    if(details->getKey() == KeyEventDetails::KEY_Q && details->getModifiers() & KeyEventDetails::KEY_MODIFIER_COMMAND)
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
    DocForeground->addLine("of \\{\\color=AAAA00FF GrigBagLayout} and \\{\\color=AAAA00FF GrigBagLayoutConstraints}.");
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

          Creates some Button components

         ******************************************************/
        ButtonRecPtr ExampleButton1 = Button::create();
        ButtonRecPtr ExampleButton2 = Button::create();
        ButtonRecPtr ExampleButton3 = Button::create();
        ButtonRecPtr ExampleButton4 = Button::create();
        ButtonRecPtr ExampleButton5 = Button::create();
        ButtonRecPtr ExampleButton6 = Button::create();


        /******************************************************

          Create and edit GridBagLayout.

          -setColumns(int): Determine    the number of
          Columns in the Layout.  This automatically
          sets the Column Width weights equal, so
          that each Column is the same Width 
          unless otherwise specified (using
          GridBayLayoutConstraints).
          -setRows(int): Determines the number of Rows
          in the Layout.  This also sets the
          Row Height weights equal as above.

         ******************************************************/
        GridBagLayoutRecPtr MainInternalWindowLayout = GridBagLayout::create();

        MainInternalWindowLayout->setColumns(3);
        MainInternalWindowLayout->setRows(3);


        /******************************************************

          Create and edit GridBagLayoutConstraints.
          GridBagLayoutConstraints have many 
          options and can be incredibly
          versatile.

          -setGridX(X_LOCATION): Determine X location
          of Constraint (0,0 is the upper left 
          hand corner).
          -setGridY(Y_LOCATION): Determine Y location
          of Constraint.
          -setGridHeight(int): Determine how many 
          Grid spaces the Constraint occupies in
          the Vertical direction (a single
          Constraint can cause its Component to
          fill more than a single Grid space).
          -setGridWidth(int): Determine how many 
          Grid spaces the Constraint occupies in
          the Horizontal direction.
          -setFill(ENUM): Determines fill options.
          Arguments are:
FILL_BOTH: Stretches both X/Y directions.
FILL_HORIZONTAL: Stretches X direction; Y dir
remains untouched (so will display whatever
is the PreferredSize Y value).
FILL_VERTICAL: Stretches Y direction; X dir
remains untouched (so will display whatever
is the PreferredSize X value).
FILL_NONE: Does not stretch either direction,
Component displays at PreferredSize.
-setWeightX(float): Determine the percent of the
Grid place the Constraint takes up in the X
direction, assuming a fill property is set in
the X direction, i.details-> FILL_HORIZONTAL.  Float 
values: [0.0,1.0].
-setWeightY(float): Determine the percent of the
Grid place the Constraint takes up in the Y
direction, assuming a fill property is set in
the X direction, i.details-> FILLY_VERTICAL.  Float 
values: [0.0,1.0].
-setPadBottom/Top/Right/Left(int): Determine the
padding within the Grid space in each 
respective direction in pixels.
-setInternalPadX(int): Determine the internal
padding in the X direction, and resizes
Component to fit that size.
-setInternalPadY(int): Determine the internal
padding in the Y direction, and resizes
Component to fit that size.
-setHorizontalAlignment(float): Determine 
alignment in Horizontal direction.  
Float values: [0.0,1.0]  Note: 0.5 will
center it.
-setVerticalAlignment(float): Determine 
alignment in Vertical direction.  
Float values: [0.0,1.0]  Note: 0.5 will
center it.

         ******************************************************/
        GridBagLayoutConstraintsRecPtr ExampleButton1Constraints = GridBagLayoutConstraints::create();
        GridBagLayoutConstraintsRecPtr ExampleButton2Constraints = GridBagLayoutConstraints::create();
        GridBagLayoutConstraintsRecPtr ExampleButton3Constraints = GridBagLayoutConstraints::create();
        GridBagLayoutConstraintsRecPtr ExampleButton4Constraints = GridBagLayoutConstraints::create();
        GridBagLayoutConstraintsRecPtr ExampleButton5Constraints = GridBagLayoutConstraints::create();
        GridBagLayoutConstraintsRecPtr ExampleButton6Constraints = GridBagLayoutConstraints::create();

        ExampleButton1Constraints->setGridX(0);
        ExampleButton1Constraints->setGridY(0);
        ExampleButton1Constraints->setGridHeight(2);
        ExampleButton1Constraints->setGridWidth(1);
        ExampleButton1Constraints->setFill(GridBagLayoutConstraints::FILL_HORIZONTAL);
        ExampleButton1Constraints->setWeightX(0.5);
        ExampleButton1Constraints->setWeightY(0.5);
        ExampleButton1Constraints->setPadBottom(0);
        ExampleButton1Constraints->setPadLeft(0);
        ExampleButton1Constraints->setPadRight(0);
        ExampleButton1Constraints->setPadTop(0);
        ExampleButton1Constraints->setInternalPadX(10);
        ExampleButton1Constraints->setInternalPadY(10);
        ExampleButton1Constraints->setHorizontalAlignment(0.75);
        ExampleButton1Constraints->setVerticalAlignment(0.75);

        ExampleButton2Constraints->setGridX(1);
        ExampleButton2Constraints->setGridY(1);

        ExampleButton3Constraints->setGridX(2);
        ExampleButton3Constraints->setGridY(2);

        ExampleButton4Constraints->setGridX(2);
        ExampleButton4Constraints->setGridY(1);

        ExampleButton5Constraints->setGridX(1);
        ExampleButton5Constraints->setGridY(2);

        ExampleButton6Constraints->setGridX(0);
        ExampleButton6Constraints->setGridY(2);


        ExampleButton1->setText("Button1");
        ExampleButton1->setConstraints(ExampleButton1Constraints);

        ExampleButton2->setText("Button2");
        ExampleButton2->setConstraints(ExampleButton2Constraints);

        ExampleButton3->setText("Button3");
        ExampleButton3->setConstraints(ExampleButton3Constraints);

        ExampleButton4->setText("Button4");
        ExampleButton4->setConstraints(ExampleButton4Constraints);

        ExampleButton5->setText("Button5");
        ExampleButton5->setConstraints(ExampleButton5Constraints);

        ExampleButton6->setText("Button6");
        ExampleButton6->setConstraints(ExampleButton6Constraints);

        // Create The Main InternalWindow
        // Create Background to be used with the Main InternalWindow
        ColorLayerRecPtr MainInternalWindowBackground = ColorLayer::create();
        MainInternalWindowBackground->setColor(Color4f(1.0,1.0,1.0,0.5));

        InternalWindowRecPtr MainInternalWindow = InternalWindow::create();
        MainInternalWindow->pushToChildren(ExampleButton1);
        MainInternalWindow->pushToChildren(ExampleButton2);
        MainInternalWindow->pushToChildren(ExampleButton3);
        MainInternalWindow->pushToChildren(ExampleButton4);
        MainInternalWindow->pushToChildren(ExampleButton5);
        MainInternalWindow->pushToChildren(ExampleButton6);
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
                                   "01RubberBandCamera");

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

