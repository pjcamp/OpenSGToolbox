/*************************************************
  Welcome to the 03Border tutorial.  In this
  tutorial, you will see how to use the 
  different Borders available and add them
  to components.  The following Borders are
introduced:

BevelBorder
CompoundBorder
EmptyBorder
EtchedBorder
LineBorder
MatteBorder
MultiColorMatteBorder
RoundedCornerLineBorder
ShadowBorder
PolygonBorder

Borders are used to quite simply give 
borders to components.  They can be added to 
components which are displayed for visual,
aesthetic, or interactive effect.  The 
different styles can be seen by running
this Tutorial.

The following all are shown and explained
within this tutorial (note the specific
requirements of each Border are not listed
here):

All Borders (where applicable):
Creating Border
Setting Color
Setting Width
Specifying style
Adding Borders to components

These tutorials contain potentially relevant
information:



 *************************************************/


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

// Include Border header files
#include "OSGBorders.h"
#include "OSGLayers.h"
#include "OSGButton.h"
#include "OSGFlowLayout.h"

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
    DocForeground->addLine("of the different \\{\\color=AAAA00FF Border} types.");
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

        // Make Torus Node
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

          Create Border components and assign
          each attribute to each Border.  Note
          that the LookAndFeelManager automatically
          assigns default settings to Borders.
          Each attribute will be set individually
          in this tutorial.

         ******************************************************/
        BevelBorderRecPtr ExampleBevelBorder = BevelBorder::create();
        CompoundBorderRecPtr ExampleCompoundBorder = CompoundBorder::create();
        EtchedBorderRecPtr ExampleEtchedBorder = EtchedBorder::create();
        LineBorderRecPtr ExampleLineBorder = LineBorder::create();
        MatteBorderRecPtr ExampleMatteBorder = MatteBorder::create();
        EmptyBorderRecPtr ExampleEmptyBorder = EmptyBorder::create();
        MultiColorMatteBorderRecPtr ExampleMultiColorMatteBorder = MultiColorMatteBorder::create();
        RoundedCornerLineBorderRecPtr ExampleRoundedCornerLineBorder = RoundedCornerLineBorder::create();
        ShadowBorderRecPtr ExampleShadowBorder = ShadowBorder::create();
        PolygonBorderRecPtr ExamplePolygonBorder = PolygonBorder::create();

        /******************************************************

          The BevelBorder causes the Border to appear
          raised or indented.

          -setRaised(bool): Determines whether Border
          appears Raised (true) or indented (false).
          -setWidth(int): Determines the Width
          of the Border in pixels.
          -setHighlightInner(Color4f): See below.
          -setHighlightOuter(Color4f): See below.
          -setShadowInner(Color4f): See below.
          -setShadowOuter(Color4f): See below.

          These four functions determine the color
          of the BevelBorder.  While setRaised(true):
          HightlightInner and HighlightOuter are bottom
          and right, and left and top while false.  The 
          ShadowInner and ShadowOuter are the opposite 
          sides.            

         ******************************************************/

        ExampleBevelBorder->setRaised(true);
        ExampleBevelBorder->setWidth(5);
        ExampleBevelBorder->setHighlightInner(Color4f(1.0, 1.0, 0.5, 1.0));
        ExampleBevelBorder->setHighlightOuter(Color4f(0.5, 0.5, 1.0, 1.0));
        ExampleBevelBorder->setShadowInner(Color4f(1.0, 0.5, 1.0, 1.0));
        ExampleBevelBorder->setShadowOuter(Color4f(0.5, 1.0, 1.0, 1.0));

        /******************************************************

          The CompoundBorder takes two other Borders
          and creates a new Border using both.

          -setInnerBorder(BorderName): Determines 
          the inner Border.
          -setOuterBorder(BorderName): Determines
          the outer Border.

Note: It is possible to create
CompoundBorders using CompoundBorders
using CompoundBorders using other 
CompoundBorders, etc. 

         ******************************************************/

        ExampleCompoundBorder->setInnerBorder(ExampleBevelBorder);
        ExampleCompoundBorder->setOuterBorder(ExampleMatteBorder);

        /******************************************************

          The EmptyBorder has a transparent Border
          which is not visible.

          -setBottomWidth(int): Determine the bottom
          Width of the Border in pixels.
          -setLeftWidth(int): Determine the left
          Width of the Border in pixels.
          -setRightWidth(int): Determine the right
          Width of the Border in pixels.
          -setTopWidth(int): Determine the top
          Width of the Border in pixels.

         ******************************************************/

        ExampleEmptyBorder->setBottomWidth(5);
        ExampleEmptyBorder->setLeftWidth(5);
        ExampleEmptyBorder->setRightWidth(30);
        ExampleEmptyBorder->setTopWidth(30);

        /******************************************************

          The EtchedBorder causes the Border to appear
          raised or indented, but in a different
          style than BevelBorder.

          -setWidth(int): Determine the Width of
          the Border in pixels.  This works
          best with a Width of a multiple of 2.
          -setHighlight(Color4f): Determine the
          hightlight Color of the Border.
          -setShadow(Color4f): Determine the
          shadow Color of the Border.    
          -setRaised(bool): Determine if the 
          Border appears raised (true) or
          indented (false).

         ******************************************************/

        ExampleEtchedBorder->setWidth(4);
        ExampleEtchedBorder->setHighlight(Color4f(1.0, 1.0, 1.0, 1.0));
        ExampleEtchedBorder->setShadow(Color4f(0.8, 0.8, 0.8, 1.0));
        ExampleEtchedBorder->setRaised(false);

        /******************************************************

          The LineBorder is simply a plain Line Border.

          -setWidth(int): Determines Width of    
          the Border in pixels.
          -setColor(Color4f): Determine the Color
          of the Border.

         ******************************************************/

        ExampleLineBorder->setWidth(1);
        ExampleLineBorder->setColor(Color4f(.7, 0.0, .5, 1.0));

        /******************************************************

          The MatteBorder is a LineBorder, except
          each edge Width can be specified
          individually.

          -setLeftWidth(int): Determines Width of    
          the left side of the Border in pixels.
          -setRightWidth(int): Determines Width of    
          the right side of the Border in pixels.
          -setBottomWidth(int): Determines Width of    
          the bottom side of the Border in pixels.
          -setTopWidth(int): Determines Width of    
          the top side of the Border in pixels.            
          -setColor(Color4f): Determine the Color
          of the Border.

         ******************************************************/

        ExampleMatteBorder->setLeftWidth(3);
        ExampleMatteBorder->setRightWidth(2);
        ExampleMatteBorder->setBottomWidth(5);
        ExampleMatteBorder->setTopWidth(1);
        ExampleMatteBorder->setColor(Color4f(1.0, .5, .5, 1.0));

        /******************************************************

          The MultiColorMatteBorder is a MatteBorder,
          except each edge Color can also be
          specified individually.

          -setLeftWidth(int): Determines Width of    
          the left side of the Border in pixels.
          -setRightWidth(int): Determines Width of    
          the right side of the Border in pixels.
          -setBottomWidth(int): Determines Width of    
          the bottom side of the Border in pixels.
          -setTopWidth(int): Determines Width of    
          the top side of the Border in pixels.            

          -setLeftLineTopColor(Color4f): See below.
          -setLeftLineBottomCo(Color4f): See below.
          -setRightLineTopColor(Color4f): See below.
          -setRightLineBottomColor(Color4f): See below.
          -setBottomLineLeftColor(Color4f): See below.
          -setBottomLineRightColor(Color4f): See below.
          -setTopLineLeftColor(Color4f): See below.
          -setTopLineRightColor(Color4f): See below.

          These functions are used to create 
          ColorUIGradients for each of the Border's
          edges.  The functions themselves explain
          which part of the Border they are applicable
          to (bottom, right, etc).

         ******************************************************/

        ExampleMultiColorMatteBorder->setLeftWidth(10);
        ExampleMultiColorMatteBorder->setLeftLineLeftColor(Color4f(1.0,0.0,0.0,1.0));
        ExampleMultiColorMatteBorder->setLeftLineRightColor(Color4f(1.0,1.0,1.0,1.0));
        ExampleMultiColorMatteBorder->setRightWidth(10);
        ExampleMultiColorMatteBorder->setRightLineLeftColor(Color4f(0.0,1.0,0.0,1.0));
        ExampleMultiColorMatteBorder->setRightLineRightColor(Color4f(0.0,0.0,1.0,1.0));
        ExampleMultiColorMatteBorder->setBottomWidth(10);
        ExampleMultiColorMatteBorder->setBottomLineTopColor(Color4f(1.0,1.0,1.0,1.0));
        ExampleMultiColorMatteBorder->setBottomLineBottomColor(Color4f(0.0,0.0,1.0,1.0));
        ExampleMultiColorMatteBorder->setTopWidth(10);
        ExampleMultiColorMatteBorder->setTopLineTopColor(Color4f(1.0,0.0,0.0,1.0));
        ExampleMultiColorMatteBorder->setTopLineBottomColor(Color4f(0.0,1.0,0.0,1.0));

        /******************************************************

          The RoundedCornerLineBorder is a LineBorder
          with rounded corners.

          -setWidth(int): Determines Width of    
          the Border in pixels.
          -setColor(Color4f): Determine the Color
          of the Border.
          -setCornerRadius(int): Determine the radius
          of the corner in pixels.

         ******************************************************/

        ExampleRoundedCornerLineBorder->setWidth(2);
        ExampleRoundedCornerLineBorder->setColor(Color4f(1.0, 0.5, 0.5, 1.0));
        ExampleRoundedCornerLineBorder->setCornerRadius(15);

        // The ShadowBorder
        ExampleShadowBorder->setTopOffset(0);
        ExampleShadowBorder->setBottomOffset(5);
        ExampleShadowBorder->setLeftOffset(0);
        ExampleShadowBorder->setRightOffset(5);
        ExampleShadowBorder->setInsideBorder(ExampleRoundedCornerLineBorder);
        ExampleShadowBorder->setCornerRadius(15);
        ExampleShadowBorder->setInternalColor(Color4f(0.0, 0.0, 0.0, 0.5));
        ExampleShadowBorder->setEdgeColor(Color4f(0.0, 0.0, 0.0, 0.0));
        ExampleShadowBorder->setInternalToEdgeColorLength(5);

        // The PolygonBorder
        ExamplePolygonBorder->setWidth(4.0f);
        ExamplePolygonBorder->setColor(Color4f(1.0, 0.0, 0.0, 1.0));
        //ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(0.2, 0.2));
        //ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(1.0, 0.0));
        //ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(0.0, 1.0));

        ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(0.0, 0.0));
        ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(0.4, 0.1));
        ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(0.5, 0.0));
        ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(0.6, 0.1));

        ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(1.0, 0.0));
        ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(0.9, 0.4));
        ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(1.0, 0.5));
        ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(0.9, 0.6));

        ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(1.0, 1.0));
        ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(0.6, 0.9));
        ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(0.5, 1.0));
        ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(0.4, 0.9));

        ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(0.0, 1.0));
        ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(0.1, 0.6));
        ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(0.0, 0.5));
        ExamplePolygonBorder->editMFVertices()->push_back(Vec2f(0.1, 0.4));

        /******************************************************

          Create Button Components to display each 
          of the different Borders.  Buttons will 
          be placed via the Flow layout.  

          Note that by setting the ActiveBorder
          and RolloverBorder, the Button will
          have the same Border even if the Button 
          is pressed or if the Mouse is hovering 
          above the Button (Active/Rollover 
          respectively).

         ******************************************************/

        ButtonRecPtr ExampleBevelBorderButton = Button::create();
        ButtonRecPtr ExampleCompoundBorderButton = Button::create();
        ButtonRecPtr ExampleEmptyBorderButton = Button::create();
        ButtonRecPtr ExampleEtchedBorderButton = Button::create();
        ButtonRecPtr ExampleLineBorderButton = Button::create();
        ButtonRecPtr ExampleMatteBorderButton = Button::create();
        ButtonRecPtr ExampleMultiColorMatteBorderButton = Button::create();
        ButtonRecPtr ExampleoundedCornerLineBorderButton = Button::create();
        ButtonRecPtr ExampleShadowBorderButton = Button::create();
        ButtonRecPtr ExamplePolygonBorderButton = Button::create();

        ExampleBevelBorderButton->setPreferredSize(Vec2f(100,50));
        ExampleBevelBorderButton->setText("Bevel Border");
        ExampleBevelBorderButton->setBorders(ExampleBevelBorder);

        ExampleCompoundBorderButton->setPreferredSize(Vec2f(100,50));
        ExampleCompoundBorderButton->setText("Compound Border");
        ExampleCompoundBorderButton->setBorders(ExampleCompoundBorder);

        ExampleEmptyBorderButton->setPreferredSize(Vec2f(100,50));
        ExampleEmptyBorderButton->setText("Empty Border");
        ExampleEmptyBorderButton->setBorders(ExampleEmptyBorder);

        ExampleEtchedBorderButton->setPreferredSize(Vec2f(100,50));
        ExampleEtchedBorderButton->setText("Etched Border");
        ExampleEtchedBorderButton->setBorders(ExampleEtchedBorder);

        ExampleLineBorderButton->setPreferredSize(Vec2f(100,50));
        ExampleLineBorderButton->setText("Line Border");
        ExampleLineBorderButton->setBorders(ExampleLineBorder);

        ExampleMatteBorderButton->setPreferredSize(Vec2f(100,50));
        ExampleMatteBorderButton->setText("Matte Border");
        ExampleMatteBorderButton->setBorders(ExampleMatteBorder);
        ExampleMatteBorderButton->setRolloverBorder(ExampleMatteBorder);
        // Note that when ExampleMatteBorderButton is pressed, the Border will revert to the 
        // default Border for Buttons, a "pressed" BevelBorder.  This is because no
        // ActiveBorder is specified.

        ExampleMultiColorMatteBorderButton->setPreferredSize(Vec2f(100,50));
        ExampleMultiColorMatteBorderButton->setText("Multi-Color Matte Border");
        ExampleMultiColorMatteBorderButton->setBorders(ExampleMultiColorMatteBorder);

        ExampleoundedCornerLineBorderButton->setPreferredSize(Vec2f(100,50));
        ExampleoundedCornerLineBorderButton->setText("Rounded Border");
        ExampleoundedCornerLineBorderButton->setBorders(ExampleRoundedCornerLineBorder);

        ExampleShadowBorderButton->setPreferredSize(Vec2f(100,50));
        ExampleShadowBorderButton->setText("Shadow Border");
        ExampleShadowBorderButton->setBorders(ExampleShadowBorder);
        ExampleShadowBorderButton->setFocusedBorder(NULL);

        ExamplePolygonBorderButton->setPreferredSize(Vec2f(100,50));
        ExamplePolygonBorderButton->setText("Polygon Border");    
        ExamplePolygonBorderButton->setBorders(ExamplePolygonBorder);


        // Create The Main InternalWindow
        // Create Background to be used with the Main InternalWindow
        ColorLayerRecPtr MainInternalWindowBackground = ColorLayer::create();
        MainInternalWindowBackground->setColor(Color4f(1.0,1.0,1.0,0.5));
        InternalWindowRecPtr MainInternalWindow = InternalWindow::create();
        LayoutRecPtr MainInternalWindowLayout = FlowLayout::create();
        MainInternalWindow->pushToChildren(ExampleBevelBorderButton);
        MainInternalWindow->pushToChildren(ExampleCompoundBorderButton);
        MainInternalWindow->pushToChildren(ExampleEtchedBorderButton);
        MainInternalWindow->pushToChildren(ExampleEmptyBorderButton);
        MainInternalWindow->pushToChildren(ExampleLineBorderButton);
        MainInternalWindow->pushToChildren(ExampleMatteBorderButton);
        MainInternalWindow->pushToChildren(ExampleMultiColorMatteBorderButton);
        MainInternalWindow->pushToChildren(ExampleoundedCornerLineBorderButton);
        MainInternalWindow->pushToChildren(ExampleShadowBorderButton);
        MainInternalWindow->pushToChildren(ExamplePolygonBorderButton);
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
                                   "03Border");

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

