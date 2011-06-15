// OpenSG Tutorial Example: Using CardLayout
//
// This tutorial explains how use CardLayout
// 
// Includes: Using CardLayout, including a brief introduction
// to Action


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

// 11CardLayout Headers
#include "OSGButton.h"
#include "OSGLineBorder.h"
#include "OSGColorLayer.h"
#include "OSGPanel.h"
#include "OSGBorderLayout.h"
#include "OSGBorderLayoutConstraints.h"
#include "OSGCardLayout.h"
//#include "OSGUIDefines.h"

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
    DocForeground->addLine("of \\{\\color=AAAA00FF CardLayout} and \\{\\color=AAAA00FF CardLayoutConstraints}.");
    DocForeground->addLine("");
    
    DocForeground->addLine("\\{\\color=AAAAAAFF Key Commands}:");
    DocForeground->addLine("   \\{\\color=AAAAFFFF Cmd+q}: Close the application");
    DocForeground->addLine("       \\{\\color=AAAAFFFF ?}: Show/hide this documentation");

    return SimpleTextForegroundTransitPtr(DocForeground);
}

/******************************************************

  Create CardLayout and its ComponentContainer
  so they can be referenced in the 
  Action (this is required
  when using Action in this
  manner).

 ******************************************************/

/******************************************************

  Create Action to use with
  CardLayout and assign each its action.

  EditCP loops with the CardLayout are
  used in the following manner:
  CardLayoutName->FUNCTION(CardLayoutContainer)

 ******************************************************/
void handleNextCardAction(ActionEventDetails* const details,
                          CardLayout* const ExampleCardLayout,
                          Panel* const ExampleCardPanel)
{
    // Displays the next Card in CardLayout
    ExampleCardLayout->next(ExampleCardPanel);
}

void handleBackCardAction(ActionEventDetails* const details,
                          CardLayout* const ExampleCardLayout,
                          Panel* const ExampleCardPanel)
{
    ExampleCardLayout->previous(ExampleCardPanel);
}

void handleFirstCardAction(ActionEventDetails* const details,
                          CardLayout* const ExampleCardLayout,
                          Panel* const ExampleCardPanel)
{
    ExampleCardLayout->first(ExampleCardPanel);
}

void handleLastCardAction(ActionEventDetails* const details,
                          CardLayout* const ExampleCardLayout,
                          Panel* const ExampleCardPanel)
{
    ExampleCardLayout->last(ExampleCardPanel);
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

          Create BorderLayout and some
          BorderLayoutConstraints to be used 
          to set up CardLayout.

         ******************************************************/

        BorderLayoutRecPtr MainInternalWindowLayout = BorderLayout::create();
        BorderLayoutConstraintsRecPtr ExampleButton1Constraints = BorderLayoutConstraints::create();
        BorderLayoutConstraintsRecPtr ExampleButton2Constraints = BorderLayoutConstraints::create();
        BorderLayoutConstraintsRecPtr ExampleButton7Constraints = BorderLayoutConstraints::create();
        BorderLayoutConstraintsRecPtr ExampleButton8Constraints = BorderLayoutConstraints::create();
        BorderLayoutConstraintsRecPtr ExampleCardPanelConstraints = BorderLayoutConstraints::create();

        ExampleButton1Constraints->setRegion(BorderLayoutConstraints::BORDER_EAST);

        ExampleButton2Constraints->setRegion(BorderLayoutConstraints::BORDER_WEST);

        ExampleButton7Constraints->setRegion(BorderLayoutConstraints::BORDER_NORTH);

        ExampleButton8Constraints->setRegion(BorderLayoutConstraints::BORDER_SOUTH);

        ExampleCardPanelConstraints->setRegion(BorderLayoutConstraints::BORDER_CENTER);

        /******************************************************

          Create CardLayout.  CardLayout shows 
          a single Component at a time, meaning
          it is not exactly practical to use it
          alone for a Layout.  This tutorial uses
          the BorderLayout to include a Panel in
          the Center Region, and within that Panel
          using a CardLayout.  A single card is 
          displayed at one time within a 
          ComponentContainer using CardLayout.

          CardLayout has four functions:
          next, previous, first, and last.

          ->next(CardContainerName): Causes 
          CardLayout to display the next card.
          ->previous(CardContainerName): Causes
          CardLayout to display the 
          previous card.
          ->first(CardContainerName): Causes
          CardLayout to display the
          first card.
          ->last(CardContainerName): Causes
          CardLayout to display the
          last card.

          These are most useful when combined with 
          Action, as shown at the top of 
          this Tutorial, to assign actions to the 
          Buttons or Components to allow the user 
          to cycle through the Card Layout and 
          view different ExampleCards.

          Note that CardContainerName is the name
          of the ComponentContainer which is using the
          CardLayout, while the begin/endEditCP
          is performed on the CardLayout itself.

         ******************************************************/

        CardLayoutRecPtr ExampleCardLayout = CardLayout::create();
        PanelRecPtr ExampleCardPanel = Panel::create();

        /******************************************************

          Create Button Components to be used with 
          CardLayout to allow for interactivity.

         ******************************************************/
        ButtonRecPtr ExampleButton1 = Button::create();
        ButtonRecPtr ExampleButton2 = Button::create();
        ButtonRecPtr ExampleButton3 = Button::create();
        ButtonRecPtr ExampleButton4 = Button::create();
        ButtonRecPtr ExampleButton5 = Button::create();
        ButtonRecPtr ExampleButton6 = Button::create();    
        ButtonRecPtr ExampleButton7 = Button::create();
        ButtonRecPtr ExampleButton8 = Button::create();

        ExampleButton1->setText("Next Card");
        ExampleButton1->setConstraints(ExampleButton1Constraints);

        // Add Action
        ExampleButton1->connectActionPerformed(boost::bind(handleNextCardAction, _1,
                                                           ExampleCardLayout.get(),
                                                           ExampleCardPanel.get()));

        ExampleButton2->setText("Previous Card");
        ExampleButton2->setConstraints(ExampleButton2Constraints);

        // Add Action
        ExampleButton2->connectActionPerformed(boost::bind(handleBackCardAction, _1,
                                                           ExampleCardLayout.get(),
                                                           ExampleCardPanel.get()));

        ExampleButton3->setText("This");

        ExampleButton4->setText("is");

        ExampleButton5->setText("Card");

        ExampleButton6->setText("Layout");

        ExampleButton7->setText("First Card");
        ExampleButton7->setConstraints(ExampleButton7Constraints);

        // Add Action
        ExampleButton7->connectActionPerformed(boost::bind(handleFirstCardAction, _1,
                                                           ExampleCardLayout.get(),
                                                           ExampleCardPanel.get()));

        ExampleButton8->setText("Last Card");
        ExampleButton8->setConstraints(ExampleButton8Constraints);

        // Add Action
        ExampleButton8->connectActionPerformed(boost::bind(handleLastCardAction, _1,
                                                           ExampleCardLayout.get(),
                                                           ExampleCardPanel.get()));

        ExampleCardPanel->setLayout(ExampleCardLayout);
        ExampleCardPanel->pushToChildren(ExampleButton3);
        ExampleCardPanel->pushToChildren(ExampleButton4);
        ExampleCardPanel->pushToChildren(ExampleButton5);
        ExampleCardPanel->pushToChildren(ExampleButton6);
        ExampleCardPanel->setConstraints(ExampleCardPanelConstraints);




        // Create The Main InternalWindow
        // Create Background to be used with the Main InternalWindow
        ColorLayerRecPtr MainInternalWindowBackground = ColorLayer::create();
        MainInternalWindowBackground->setColor(Color4f(1.0,1.0,1.0,0.5));

        InternalWindowRecPtr MainInternalWindow = InternalWindow::create();
        MainInternalWindow->pushToChildren(ExampleButton1);
        MainInternalWindow->pushToChildren(ExampleButton2);
        MainInternalWindow->pushToChildren(ExampleButton7);
        MainInternalWindow->pushToChildren(ExampleButton8);
        MainInternalWindow->pushToChildren(ExampleCardPanel);
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
                                   "11CardLayout");

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

