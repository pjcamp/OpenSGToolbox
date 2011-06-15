// OpenSG Tutorial Example: Creating a Border
//
// This tutorial explains how to implement the 
// TabPanel and its characteristics
// 
// Includes: TabPanel creation and example TabPanel, as well as 
// utilizing Action to add/remove Tabs on mouseclicks

// General OpenSG configuration, needed everywhere
#include "OSGConfig.h"

// Methods to create simple geometry: boxes, spheres, tori etc.
#include "OSGSimpleGeometry.h"

// A little helper to simplify scene management and interaction
#include "OSGSimpleSceneManager.h"
#include "OSGNode.h"
#include "OSGGroup.h"
#include "OSGViewport.h"

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

// 15TabPanel Headers
#include <sstream>
#include "OSGButton.h"
#include "OSGLabel.h"
#include "OSGLayers.h"
#include "OSGBoxLayout.h"
#include "OSGFlowLayout.h"
//#include "OSGUIDefines.h"
#include "OSGPanel.h"
#include "OSGTabPanel.h"

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
    DocForeground->addLine(" of a \\{\\color=AAAA00FF TabPanel}.");
    DocForeground->addLine("");
    
    DocForeground->addLine("\\{\\color=AAAAAAFF Key Commands}:");
    DocForeground->addLine("   \\{\\color=AAAAFFFF Cmd+q}: Close the application");
    DocForeground->addLine("       \\{\\color=AAAAFFFF ?}: Show/hide this documentation");

    return SimpleTextForegroundTransitPtr(DocForeground);
}

void handleAddTabAction(ActionEventDetails* const details,
                        TabPanel* const ExampleTabPanel,
                        Button* const ExampleTabContentA,
                        Button* const ExampleTabContentB)
{
    /******************************************************

      Create a Tab and edit texts accordingly.

     ******************************************************/

    LabelRecPtr AddedTabLabel = Label::create();
    ButtonRecPtr AddedTabContent = Button::create();

    AddedTabLabel->setText("Tab7");
    AddedTabLabel->setBorders(NULL);
    AddedTabLabel->setBackgrounds(NULL);

    AddedTabContent->setText("This is where the new Tab content hangs out");

    // Determine if the number of Tabs is 6 and 
    // if so, add a 7th Tab
    if( ExampleTabPanel->getMFTabs()->size() == 6) 
    {
        ExampleTabPanel->addTab(AddedTabLabel, AddedTabContent);

        // Change the text on the Tabs
        ExampleTabContentA->setText("Remove Tab7 under Tab2!");

        ExampleTabContentB->setText("Remove Tab7");
    }

}

void handleRemoveTabAction(ActionEventDetails* const details,
                           TabPanel* const ExampleTabPanel,
                           Button* const ExampleTabContentA,
                           Button* const ExampleTabContentB)
{
    /******************************************************

      Remove the last Tab and change texts
      accordingly.

        Note: removeTab()
        can take either the TabName or index 
        number

     ******************************************************/        
    // If the number of Tabs is 7 (one was added)
    // then remove it
    if( ExampleTabPanel->getMFTabs()->size() == 7) 
    {
        ExampleTabPanel->removeTab(6);

        ExampleTabContentA->setText("Add another Tab");

        // Change the text on the Tabs
        ExampleTabContentB->setText("Add a Tab under Tab1!");
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

          Create Button Components to be used with 
          TabPanel and specify their characteristics.

          Note: Buttons are used for simplicity,
          any Component can be used as Tab content
          or as a Tab.  A Panel with several
          Buttons within it is also added.

         ******************************************************/

        LabelRecPtr ExampleTabLabel1 = Label::create();
        LabelRecPtr ExampleTabLabel2 = Label::create();
        LabelRecPtr ExampleTabLabel3 = Label::create();
        LabelRecPtr ExampleTabLabel4 = Label::create();
        LabelRecPtr ExampleTabLabel5 = Label::create();
        LabelRecPtr ExampleTabLabel6 = Label::create();
        ButtonRecPtr ExampleTabContentA = Button::create();
        ButtonRecPtr ExampleTabContentB = Button::create();
        ButtonRecPtr ExampleTabContentC = Button::create();
        ButtonRecPtr ExampleTabContentD = Button::create();
        ButtonRecPtr ExampleTabContentE = Button::create();
        ButtonRecPtr ExampleTabContentF = Button::create();

        ExampleTabLabel1->setText("Tab1");
        ExampleTabLabel1->setBorders(NULL);
        ExampleTabLabel1->setBackgrounds(NULL);

        ExampleTabLabel2->setText("Tab2");
        ExampleTabLabel2->setBorders(NULL);
        ExampleTabLabel2->setBackgrounds(NULL);

        ExampleTabLabel3->setText("Tab3");
        ExampleTabLabel3->setBorders(NULL);
        ExampleTabLabel3->setBackgrounds(NULL);

        ExampleTabLabel4->setText("Tab4");
        ExampleTabLabel4->setBorders(NULL);
        ExampleTabLabel4->setBackgrounds(NULL);

        ExampleTabLabel5->setText("Tab5");
        ExampleTabLabel5->setBorders(NULL);
        ExampleTabLabel5->setBackgrounds(NULL);

        ExampleTabLabel6->setText("Tab6");
        ExampleTabLabel6->setBorders(NULL);
        ExampleTabLabel6->setBackgrounds(NULL);

        ExampleTabContentA->setText("Add another Tab");


        ExampleTabContentB->setText("Add a Tab in Tab1!");

        ExampleTabContentC->setText("Stuff for Tab3");

        ExampleTabContentD->setText("Stuff for Tab5");

        ExampleTabContentE->setText("Stuff for Tab6");

        /******************************************************

          Create a Panel to add to the TabPanel

         ******************************************************/

        // Create and edit the Panel Buttons
        ButtonRecPtr ExampleTabPanelButton1 = Button::create();
        ButtonRecPtr ExampleTabPanelButton2 = Button::create();
        ButtonRecPtr ExampleTabPanelButton3 = Button::create();
        ButtonRecPtr ExampleTabPanelButton4 = Button::create();
        ButtonRecPtr ExampleTabPanelButton5 = Button::create();
        ButtonRecPtr ExampleTabPanelButton6 = Button::create();

        ExampleTabPanelButton1->setText("This");

        ExampleTabPanelButton2->setText("is a");

        ExampleTabPanelButton3->setText("sample");

        ExampleTabPanelButton4->setText("Panel");

        ExampleTabPanelButton5->setText("within");

        ExampleTabPanelButton6->setText("TabPanel");

        // Create and edit Panel Layout
        BoxLayoutRecPtr TabPanelLayout = BoxLayout::create();
        TabPanelLayout->setOrientation(BoxLayout::VERTICAL_ORIENTATION);

        // Create and edit Panel
        PanelRecPtr ExampleTabPanelPanel = Panel::create();
        ExampleTabPanelPanel->setPreferredSize(Vec2f(180, 500));
        ExampleTabPanelPanel->pushToChildren(ExampleTabPanelButton1);
        ExampleTabPanelPanel->pushToChildren(ExampleTabPanelButton2);
        ExampleTabPanelPanel->pushToChildren(ExampleTabPanelButton3);
        ExampleTabPanelPanel->pushToChildren(ExampleTabPanelButton4);
        ExampleTabPanelPanel->pushToChildren(ExampleTabPanelButton5);
        ExampleTabPanelPanel->pushToChildren(ExampleTabPanelButton6);
        ExampleTabPanelPanel->setBorders(NULL);
        ExampleTabPanelPanel->setBackgrounds(NULL);
        ExampleTabPanelPanel->setLayout(TabPanelLayout);

        /******************************************************

          Create TabPanel.  TabPanel automatically
          sizes objects within it to cause the appearance
          of Tabs.  The following functions are 
          unique to TabPanel:
          -addTab(TAB_OBJECT, TAB_CONENT):
          Determine the Tab and content for a new 
          Tab.  See below for detailed explanation
          of arguments.
          -removeTab(TAB_OBJECT or TAB_INDEX):
          Remove a Tab based on either the Tab name
          or the index of the Tab.  See below for 
          detailed explanation of arguments.
          -setActiveTab(TAB_INDEX): Determine which Tab
          is Active (ie shown) based in index.
          See below for detailed explanation of 
          arguments.
          -insertTab(TAB_OBJECT or TAB_INDEX, NEW_TAB_OBJECT, 
          NEW_TAB_CONTENT): Insert a new Tab by
          either an existing Tab (the Tab will 
          be inserted before this Tab) or by 
          its index.
          -tabAlignment(ENUM):  Determine the alignment
          of the Tabs.  Takes AXIS_CENTER_ALIGNMENT,
          AXIS_MAX_ALIGNMENT, and AXIS_MIN_ALIGNMENT
          arguments.
          -tabPlacement(ENUM): Determine location of
          the Tabs around the Tab content.  Takes
          PLACEMENT_NORTH, PLACEMENT_SOUTH, 
          PLACEMENT_WEST, and PLACEMENT_EAST 
          arguments.

          Definition of terms:
          TAB_OBJECT: This denotes a component which
          is used as the Tab itself.
          TAB_INDEX: This denotes the index within
          the "list" of Tabs.  The first Tab
          is indexed as 0, and subsequent Tabs
          are 1, 2, etc.
          TAB_CONTENT: This denotes the Component
          which will be displayed within the
          Tab.

          Note: The TabPanel has a PreferredSize
          which it displays at and if the Frame is 
          too small, then the TabPanel will appear
          distorted.  Also, removeTab/addTab are most 
          useful when combined with Action 
          to allow for interactability with the 
          TabPanel.  An example of this is shown
          above, allowing for a Tab to be created/
          removed by the user.

         ******************************************************/
        TabPanelRecPtr ExampleTabPanel = TabPanel::create();
        ExampleTabPanel->setPreferredSize(Vec2f(600,600));
        ExampleTabPanel->addTab(ExampleTabLabel1, ExampleTabContentA);
        ExampleTabPanel->addTab(ExampleTabLabel2, ExampleTabContentB);
        ExampleTabPanel->addTab(ExampleTabLabel3, ExampleTabContentC);
        ExampleTabPanel->addTab(ExampleTabLabel4, ExampleTabPanelPanel);
        ExampleTabPanel->addTab(ExampleTabLabel5, ExampleTabContentD);
        ExampleTabPanel->addTab(ExampleTabLabel6, ExampleTabContentE);
        ExampleTabPanel->setTabAlignment(0.5f);
        ExampleTabPanel->setTabPlacement(TabPanel::PLACEMENT_NORTH);
        ExampleTabPanel->setSelectedIndex(3);

        ExampleTabContentB->connectActionPerformed(boost::bind(handleRemoveTabAction, _1,
                                                               ExampleTabPanel.get(),
                                                               ExampleTabContentA.get(),
                                                               ExampleTabContentB.get()));
        ExampleTabContentA->connectActionPerformed(boost::bind(handleAddTabAction, _1,
                                                               ExampleTabPanel.get(),
                                                               ExampleTabContentA.get(),
                                                               ExampleTabContentB.get()));
        /******************************************************

          By using CardLayout, the TabPanel  
          automatically takes up the entire
          MainFrame (which can be very useful
          with TabPanel).

         ******************************************************/
        LayoutRecPtr MainInternalWindowLayout = FlowLayout::create();

        // Create The Main InternalWindow
        // Create Background to be used with the Main InternalWindow
        ColorLayerRecPtr MainInternalWindowBackground = ColorLayer::create();
        MainInternalWindowBackground->setColor(Color4f(1.0,1.0,1.0,0.5));

        InternalWindowRecPtr MainInternalWindow = InternalWindow::create();
        MainInternalWindow->pushToChildren(ExampleTabPanel);
        MainInternalWindow->setLayout(MainInternalWindowLayout);
        MainInternalWindow->setBackgrounds(MainInternalWindowBackground);
        MainInternalWindow->setAlignmentInDrawingSurface(Vec2f(0.5f,0.5f));
        MainInternalWindow->setScalingInDrawingSurface(Vec2f(0.85f,0.85f));
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
                                   "15TabPanel");

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

