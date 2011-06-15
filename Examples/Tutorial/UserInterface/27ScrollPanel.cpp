// OpenSG Tutorial Example: Using the AbsoluteLayout
//
// This tutorial explains how to place buttons within a 
// frame utilizing the Absolute Layout to manage the layout 
// through the OSG User Interface library.
// 
// Includes: placing multiple buttons and using 
// AbsoluteLayoutConstraints to locate the buttons.


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

// 27ScrollPanel Headers
#include "OSGLookAndFeelManager.h"
#include "OSGLayers.h"
#include "OSGFlowLayout.h"
#include "OSGPanel.h"
#include "OSGScrollPanel.h"
#include "OSGScrollBar.h"
#include "OSGDefaultBoundedRangeModel.h"
#include "OSGUIViewport.h"
#include "OSGButton.h"

// Activate the OpenSG namespace
OSG_USING_NAMESPACE

// Forward declaration so we can have the interesting stuff upfront
void display(SimpleSceneManager *mgr);
void reshape(Vec2f Size, SimpleSceneManager *mgr);

// Declare function up front
PanelTransitPtr createPanelWithButtons(void);

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
    DocForeground->addLine("of \\{\\color=AAAA00FF ScrollBar} and \\{\\color=AAAA00FF ScrollPanel}.");
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

          Create a Panel containing Buttons to
          add to ScrollPanel using a function
          (located at bottom of this file)

         ******************************************************/    

        PanelRecPtr ExampleViewablePanel = createPanelWithButtons();

        /******************************************************

          Create a UIViewport to use with the
          ScrollPanel.  This sets up a secondary
          TutorialViewport inside the ScrollPanel.  
          Without this, the ScrollPanel would 
          not function correctly.

          The Panel created above is added to be
          viewed in the UIViewport and the size
          and position are set.

         ******************************************************/    
        UIViewportRecPtr ScrollPanelUIViewport = UIViewport::create();

        ScrollPanelUIViewport->setViewComponent(ExampleViewablePanel);
        ScrollPanelUIViewport->setViewPosition(Pnt2f(150,150));
        ScrollPanelUIViewport->setPreferredSize(Vec2f(200,200));

        /******************************************************

          Create the ScrollPanel itself.
          -setHorizontalResizePolicy(ScrollPanel::
          ENUM):  Determines the Horizontal 
          resize policy.  The ScrollPanel will 
          automatically resize itself to the
          Size of its Component within for 
          RESIZE_TO_VIEW, or add a ScrollBar 
          as needed for NO_RESIZE.  Takes
          NO_RESIZE and RESIZE_TO_VIEW 
          arguments.
          -setVerticalResizePolicy(ScrollPanel::
          ENUM):  Determines the Vertical 
          resize policy.  The ScrollPanel will 
          automatically resize itself to the
          Size of its Component within for 
          RESIZE_TO_VIEW, or add a ScrollBar 
          as needed for NO_RESIZE.  Takes
          NO_RESIZE and RESIZE_TO_VIEW 
          arguments.
          -setViewComponent(Component): Determine
          which Component will be added into
          the ScrollPanel.  Note that this
          must be the same as the UIViewport
          created above and does not require
          a begin/endEditCP.

         ******************************************************/    

        ScrollPanelRecPtr ExampleScrollPanel = ScrollPanel::create();
        ExampleScrollPanel->setPreferredSize(Vec2f(100,100));
        ExampleScrollPanel->setVerticalScrollBarAlignment(ScrollPanel::SCROLLBAR_ALIGN_LEFT);
        ExampleScrollPanel->setHorizontalScrollBarAlignment(ScrollPanel::SCROLLBAR_ALIGN_BOTTOM);

        //ExampleScrollPanel->setHorizontalResizePolicy(ScrollPanel::RESIZE_TO_VIEW);
        //ExampleScrollPanel->setVerticalResizePolicy(ScrollPanel::RESIZE_TO_VIEW);

        ExampleScrollPanel->setViewComponent(ExampleViewablePanel);


        /******************************************************

          Create two ScrollBars.

          First, create a DefaultBoundedRangeModel.
          This determines some characteristics of 
          the Scrollbar.  Note that you can link
          several ScollBars to the same 
          DefaultBoundedRangeModel; this will
          cause them to move at the same time.

          -.setMinimum(int): Determine a numeric
          value for the beginning of the 
          ScrollBar.  Note that the visible
          size will be set separately.
          -.setMaximum(int): Determine a numeric
          value for the end of the 
          ScrollBar. 
          -.setValue(int):  Determine the 
          initial location of the Bar on the
          ScrollBar.  This is determined from
          the Min/Max values.
          -.setExtent(int): Determine the size
          of the Bar on the ScrollBar as a 
          fraction of the total size (which is 
          determined from the Min/Max values)
          as well.

          Second, create the ScrollBar itself.

          -setOrientation(ENUM): Determine
          the orientation of the ScrollBar.
          Takes VERTICAL_ORIENTATION
          and HORIZONTAL_ORIENTATION arguments.
          -setUnitIncrement(int): Determines how
          much the Scoller moves per click
          on its end arrows.  References to the
          Min/Max values as well.
          -setBlockIncrement(int): Determine
          how many units the ScrollBar moves 
          when the "non-scroller" is clicked.
          This references the Min/Max values
          above as well (so if the Min/Max
          range was 0 to 100, and this was 
          100, then each click would move the
          scoller to the opposite end).  It 
          would also be impossible to directly
          click the scroller to a middle location.

          Note that while in this tutorial both
          ScrollBars use the same BoundedRangeModel
          (which causes them to be linked), each 
          ScrollBar individually has these last two 
          settings uniquely set.  So while the 
          Scrollers move together (because they
          use the same Model), using each
          will cause them to move at different
          speeds due to these settings being
          different.

         ******************************************************/    

        // Create a DefaultBoundedRangeModel
        DefaultBoundedRangeModelRecPtr TheBoundedRangeModel = DefaultBoundedRangeModel::create();
        TheBoundedRangeModel->setMinimum(10);
        TheBoundedRangeModel->setMaximum(100);
        TheBoundedRangeModel->setValue(10);
        TheBoundedRangeModel->setExtent(20);

        ScrollBarRecPtr ExampleVerticalScrollBar = ScrollBar::create();
        //ExampleScrollPanel->getHorizontalScrollBar()
        ExampleVerticalScrollBar->setOrientation(ScrollBar::VERTICAL_ORIENTATION);
        ExampleVerticalScrollBar->setPreferredSize(Vec2f(20,200));
        ExampleVerticalScrollBar->setEnabled(false);
        ExampleVerticalScrollBar->setUnitIncrement(10);
        ExampleVerticalScrollBar->setBlockIncrement(100);
        ExampleVerticalScrollBar->setRangeModel(TheBoundedRangeModel);

        ScrollBarRecPtr ExampleHorizontalScrollBar = ScrollBar::create();
        ExampleHorizontalScrollBar->setOrientation(ScrollBar::HORIZONTAL_ORIENTATION);
        ExampleHorizontalScrollBar->setPreferredSize(Vec2f(400,20));
        ExampleHorizontalScrollBar->setRangeModel(TheBoundedRangeModel);


        // Creates another DefaultBoundedRangeModel to use 
        // for separating the two ScrollBars from each other.
        // Make sure to comment out the addition of the 
        // previous setModel above.

        /*
           DefaultBoundedRangeModel TheBoundedRangeModel2;
           TheBoundedRangeModel2.setMinimum(0);
           TheBoundedRangeModel2.setMaximum(100);
           TheBoundedRangeModel2.setValue(10);
           TheBoundedRangeModel2.setExtent(20);
           ExampleHorizontalScrollBar->setModel(&TheBoundedRangeModel2);
           */

        // Create The Main InternalWindow
        // Create Background to be used with the Main InternalWindow
        ColorLayerRecPtr MainInternalWindowBackground = ColorLayer::create();
        MainInternalWindowBackground->setColor(Color4f(1.0,1.0,1.0,0.5));

        LayoutRecPtr MainInternalWindowLayout = FlowLayout::create();

        InternalWindowRecPtr MainInternalWindow = InternalWindow::create();
        MainInternalWindow->pushToChildren(ExampleHorizontalScrollBar);
        MainInternalWindow->pushToChildren(ExampleVerticalScrollBar);
        MainInternalWindow->pushToChildren(ExampleScrollPanel);
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
                                   "27ScrollPanel");

        //Enter main Loop
        TutorialWindow->mainLoop();
    }

    osgExit();

    return 0;
}


PanelTransitPtr createPanelWithButtons(void)
{
    ButtonRecPtr PanelButton1 = Button::create();
    ButtonRecPtr PanelButton2 = Button::create();
    ButtonRecPtr PanelButton3 = Button::create();
    ButtonRecPtr PanelButton4 = Button::create();
    ButtonRecPtr PanelButton5 = Button::create();
    ButtonRecPtr PanelButton6 = Button::create();
    PanelButton1->setText("This");
    PanelButton2->setText("is");
    PanelButton3->setText("a");
    PanelButton4->setText("sample");
    PanelButton5->setText("Scroll");
    PanelButton6->setText("Panel!");

    // Create Panel to add Buttons to which will be inserted into 
    // the ScrollPanel itself
    PanelRecPtr ScrollPanelInsertPanel = Panel::create();
    FlowLayoutRecPtr ScrollPanelInsertPanelLayout = FlowLayout::create();
    ScrollPanelInsertPanel->setPreferredSize(Vec2f(100, 250 ));
    ScrollPanelInsertPanel->pushToChildren(PanelButton1);
    ScrollPanelInsertPanel->pushToChildren(PanelButton2);
    ScrollPanelInsertPanel->pushToChildren(PanelButton3);
    ScrollPanelInsertPanel->pushToChildren(PanelButton4);
    ScrollPanelInsertPanel->pushToChildren(PanelButton5);
    ScrollPanelInsertPanel->pushToChildren(PanelButton6);
    ScrollPanelInsertPanel->setLayout(ScrollPanelInsertPanelLayout);

    return PanelTransitPtr(ScrollPanelInsertPanel);
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

