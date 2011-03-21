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
#include "OSGGradientBackground.h"
#include "OSGFunctorListComponentGenerator.h"

// Activate the OpenSG namespace
OSG_USING_NAMESPACE

// Forward declaration so we can have the interesting stuff upfront
void display(SimpleSceneManager *mgr);
void reshape(Vec2f Size, SimpleSceneManager *mgr);

// 18List Headers
#include "OSGLookAndFeelManager.h"
#include "OSGColorLayer.h"
#include "OSGLineBorder.h"
#include "OSGBevelBorder.h"
#include "OSGFlowLayout.h"
#include "OSGLabel.h"
#include "OSGScrollPanel.h"

#include <sstream>

// List header files
#include "OSGList.h"
#include "OSGMFieldListModel.h"
#include "OSGDefaultListSelectionModel.h"

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
    DocForeground->addLine("of \\{\\color=AAAA00FF MFieldListModel} and \\{\\color=AAAA00FF FunctorListComponentGenerator}.");
    DocForeground->addLine("");
    
    DocForeground->addLine("\\{\\color=AAAAAAFF Key Commands}:");
    DocForeground->addLine("   \\{\\color=AAAAFFFF Cmd+q}: Close the application");
    DocForeground->addLine("       \\{\\color=AAAAFFFF ?}: Show/hide this documentation");

    return SimpleTextForegroundTransitPtr(DocForeground);
}

ComponentTransitPtr generateListComponent(List* const Parent,
                                          const boost::any& Value,
                                          UInt32 Index,
                                          bool IsSelected,
                                          bool HasFocus)
{
    std::string ValueString;
    Color3f ColorValue;
    try
    {
        MFieldListModel::MFieldIndexed MFieldValue = boost::any_cast<MFieldListModel::MFieldIndexed>(Value);
        std::ostringstream TheOSStream;
        OutStream TheOutStream(TheOSStream);
        MFieldValue.first->pushIndexedValueToStream(TheOutStream,
                                                    MFieldValue.second);
        ValueString = TheOSStream.str();
        ColorValue = static_cast<const
            GradientBackground::MFColorType*>(MFieldValue.first->getField())->operator[](MFieldValue.second);
    }
    catch (boost::bad_lexical_cast &)
    {
        //Could not convert to string
    }

    ColorLayerRecPtr LabelBackground = ColorLayer::create();
    LabelBackground->setColor(Color4f(ColorValue.red(),ColorValue.green(),ColorValue.blue(),1.0f));

    LabelRefPtr TheComponent = Label::create();

    TheComponent->setBackgrounds(LabelBackground);
    TheComponent->setText(ValueString);

    if(IsSelected)
    {
        LineBorderRecPtr LabelBorder = LineBorder::create();
        LabelBorder->setWidth(1.0f);
        LabelBorder->setColor(Color4f(0.0f,0.0f,0.0f,1.0f));
        TheComponent->setBorders(LabelBorder);
    }
    else
    {
        TheComponent->setBorders(NULL);
    }

    return ComponentTransitPtr(TheComponent);
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

        GradientBackgroundRecPtr TheBackground = GradientBackground::create();
        TheBackground->addLine(Color3f(1.0,0.0,0.0), 0.0);
        TheBackground->addLine(Color3f(0.0,1.0,0.0), 0.2);
        TheBackground->addLine(Color3f(0.0,0.0,1.0), 0.4);
        TheBackground->addLine(Color3f(0.0,1.0,1.0), 0.6);
        TheBackground->addLine(Color3f(1.0,1.0,0.0), 0.8);
        TheBackground->addLine(Color3f(1.0,1.0,1.0), 1.0);

        /******************************************************

          Create a List.  A List has several 
          parts to it:
          -ListModel: Contains the data which is to be
          displayed in the List.  Data is added
          as shown below
          -ListCellRenderer: Creates the Components to
          be used within the List (the default
          setting is to create Labels using 
          the desired text).
          -ListSelectionModel: Determines how
          the List may be selected.

          To add values to the list:

          First, create SFStrings and use the 
          .setValue("Value") function to set their
          values.  Then, use the .pushBack(&SFStringName)
          to add them to the List.

          Next, create the CellRenderer and ListSelectionModel
          defaults.

          Finally, actually create the List.  Set
          its Model, CellRenderer, and SelectionModel
          as shown below.  Finally, choose the
          type of display for the List (choices outlined
          below).

         ******************************************************/

        // Add data to it
        MFieldListModelRecPtr ExampleListModel = MFieldListModel::create();
        ExampleListModel->setContainer(TheBackground);
        ExampleListModel->setFieldId(GradientBackground::ColorFieldId);

        /******************************************************

          Create ListCellRenderer and 
          ListSelectionModel.  Most 
          often the defauls will be used.

            Note: the ListSelectionModel was
            created above and is referenced
            by the Action.

         ******************************************************/    

        FunctorListComponentGeneratorRecPtr ListCompGenerator =
            FunctorListComponentGenerator::create();

        ListCompGenerator->setGenerateFunction(boost::bind(generateListComponent, _1, _2, _3, _4, _5));

        /******************************************************

          Create List itself and assign its 
          Model
          to it.
          -setOrientation(ENUM): Determine the
          Layout of the cells (Horizontal
          or Vertical).  Takes List::VERTICAL_ORIENTATION
          and List::HORIZONTAL_ORIENTATION arguments.

         ******************************************************/    
        ListRecPtr ExampleList = List::create();
        ExampleList->setPreferredSize(Vec2f(200, 300));
        ExampleList->setOrientation(List::VERTICAL_ORIENTATION);
        //ExampleList->setOrientation(List::HORIZONTAL_ORIENTATION);
        ExampleList->setModel(ExampleListModel);
        ExampleList->setCellGenerator(ListCompGenerator);


        // Create a ScrollPanel for easier viewing of the List (see 27ScrollPanel)
        ScrollPanelRecPtr ExampleScrollPanel = ScrollPanel::create();
        ExampleScrollPanel->setPreferredSize(Vec2f(200,300));
        ExampleScrollPanel->setHorizontalResizePolicy(ScrollPanel::RESIZE_TO_VIEW);
        //ExampleScrollPanel->setVerticalResizePolicy(ScrollPanel::RESIZE_TO_VIEW);
        ExampleScrollPanel->setViewComponent(ExampleList);

        // Create MainFramelayout
        FlowLayoutRecPtr MainInternalWindowLayout = FlowLayout::create();
        MainInternalWindowLayout->setOrientation(FlowLayout::VERTICAL_ORIENTATION);
        MainInternalWindowLayout->setMajorAxisAlignment(0.5f);
        MainInternalWindowLayout->setMinorAxisAlignment(0.5f);

        LabelRecPtr ListLabel = Label::create();
        ListLabel->setText("Background Colors List");
        ListLabel->setPreferredSize(Vec2f(200.0f, ListLabel->getPreferredSize().y()));

        // Create The Main InternalWindow
        // Create Background to be used with the Main InternalWindow
        ColorLayerRecPtr MainInternalWindowBackground = ColorLayer::create();
        MainInternalWindowBackground->setColor(Color4f(1.0,1.0,1.0,0.5));

        InternalWindowRecPtr MainInternalWindow = InternalWindow::create();
        MainInternalWindow->pushToChildren(ListLabel);
        MainInternalWindow->pushToChildren(ExampleScrollPanel);
        MainInternalWindow->setLayout(MainInternalWindowLayout);
        MainInternalWindow->setBackgrounds(MainInternalWindowBackground);
        MainInternalWindow->setAlignmentInDrawingSurface(Vec2f(0.5f,0.5f));
        MainInternalWindow->setScalingInDrawingSurface(Vec2f(0.7f,0.5f));
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
        TutorialViewport->setBackground(TheBackground);

        //Create the Documentation Foreground and add it to the viewport
        SimpleScreenDoc TheSimpleScreenDoc(&sceneManager, TutorialWindow);

        // Show the whole Scene
        sceneManager.showAll();


        //Open Window
        Vec2f WinSize(TutorialWindow->getDesktopSize() * 0.85f);
        Pnt2f WinPos((TutorialWindow->getDesktopSize() - WinSize) *0.5);
        TutorialWindow->openWindow(WinPos,
                                   WinSize,
                                   "44MFieldList");

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

