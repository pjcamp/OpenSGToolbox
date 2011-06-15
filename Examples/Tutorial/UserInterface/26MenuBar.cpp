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

// 26MenuBar Headers
#include "OSGUIForeground.h"
#include "OSGUIDrawingSurface.h"
#include "OSGGraphics2D.h"
#include "OSGButton.h"
#include "OSGLabel.h"
#include "OSGFlowLayout.h"
#include "OSGLookAndFeelManager.h"
#include "OSGUIFont.h"
#include "OSGLayers.h"
#include "OSGBorders.h"
#include "OSGMenu.h"
#include "OSGMenuItem.h"
#include "OSGMenuBar.h"

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
    DocForeground->addLine("of a \\{\\color=AAAA00FF MenuBar}.");
    DocForeground->addLine("");
    
    DocForeground->addLine("\\{\\color=AAAAAAFF Key Commands}:");
    DocForeground->addLine("   \\{\\color=AAAAFFFF Cmd+q}: Close the application");
    DocForeground->addLine("       \\{\\color=AAAAFFFF ?}: Show/hide this documentation");

    return SimpleTextForegroundTransitPtr(DocForeground);
}


void handleQuitAction(ActionEventDetails* const details,
                      WindowEventProducer* const TutorialWindow)
{
    TutorialWindow->closeWindow();
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

          Create Components to add to MenuBar
          Menus.  Each MenuBar has multiple Menus 
          which contain multiple MenuItems.

          -setAcceleratorKey(KeyEventDetails::KEY_*): This
          links the key "*" as a shortcut to 
          selecting the item it is attached to.
          An example of this would be Q with 
          Control+Q causing programs to quit.
          -setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_*):
          This adds the "*" key as another 
          requirement to cause the item to be
          selected.  Things such as "CONTROL" are 
          likely to be used here (as mentioned 
          above, both Control and Q are specified).

Note: These shortcuts will be shown in the list
with the MenuItem they are attached to.

-setMnemonicKey(KeyEventDetails::KEY_****): sets the key
"****" to be underlined within the Menu
itself


         ******************************************************/

        // Creates MenuItems as in 25PopupMenu
        MenuItemRecPtr NewMenuItem = MenuItem::create();
        MenuItemRecPtr OpenMenuItem = MenuItem::create();
        MenuItemRecPtr CloseMenuItem = MenuItem::create();
        MenuItemRecPtr ExitMenuItem = MenuItem::create();
        MenuItemRecPtr UndoMenuItem = MenuItem::create();
        MenuItemRecPtr RedoMenuItem = MenuItem::create();

        //Edits MenuItems
        NewMenuItem->setText("New ...");
        NewMenuItem->setAcceleratorKey(KeyEventDetails::KEY_N);
        NewMenuItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
        NewMenuItem->setMnemonicKey(KeyEventDetails::KEY_N);

        OpenMenuItem->setText("Open ...");
        OpenMenuItem->setAcceleratorKey(KeyEventDetails::KEY_P);
        OpenMenuItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
        OpenMenuItem->setMnemonicKey(KeyEventDetails::KEY_P);

        CloseMenuItem->setText("Close ...");
        CloseMenuItem->setAcceleratorKey(KeyEventDetails::KEY_W);
        CloseMenuItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
        CloseMenuItem->setMnemonicKey(KeyEventDetails::KEY_C);

        ExitMenuItem->setText("Quit");
        ExitMenuItem->setAcceleratorKey(KeyEventDetails::KEY_Q);
        ExitMenuItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
        ExitMenuItem->setMnemonicKey(KeyEventDetails::KEY_Q);

        UndoMenuItem->setText("Undo");
        UndoMenuItem->setAcceleratorKey(KeyEventDetails::KEY_Z);
        UndoMenuItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
        UndoMenuItem->setMnemonicKey(KeyEventDetails::KEY_U);
        RedoMenuItem->setText("Redo");
        RedoMenuItem->setEnabled(false);
        RedoMenuItem->setMnemonicKey(KeyEventDetails::KEY_R);

        // Create a function connection to ExitMenuItem
        // This is defined above, and will cause the program to quit
        // when that MenuItem is selected or Control + Q hit 
        ExitMenuItem->connectActionPerformed(boost::bind(handleQuitAction, _1,
                                                         TutorialWindow.get()));

        /******************************************************

          Create Menu Components to add to MenuBar
          and adds above Components to them.  

          Note: setAcceleratorKey,
          setAcceleratorModifiers, and setMnemnoicKey
          all apply to Menus in addition to MenuItems.

         ******************************************************/

        // Create a File menu and adds its MenuItems
        MenuRecPtr FileMenu = Menu::create();
        FileMenu->addItem(NewMenuItem);
        FileMenu->addItem(OpenMenuItem);
        FileMenu->addItem(CloseMenuItem);
        FileMenu->addSeparator();
        FileMenu->addItem(ExitMenuItem);

        // Labels the File Menu
        FileMenu->setText("File");
        FileMenu->setMnemonicKey(KeyEventDetails::KEY_F);

        // Creates an Edit menu and adds its MenuItems
        MenuRecPtr EditMenu = Menu::create();
        EditMenu->addItem(UndoMenuItem);
        EditMenu->addItem(RedoMenuItem);

        // Labels the Edit Menu
        EditMenu->setText("Edit");
        EditMenu->setMnemonicKey(KeyEventDetails::KEY_E);

        /******************************************************

          Create MainMenuBar and adds the Menus
          created above to it.

          Also creates several Backgrounds
          to improve MenuBar overall look.
          Both the MenuBar and Menu can have
          Backgrounds; the set up currently
          is to have EmptyBackgrounds in 
          each Menu allowing a single
          overall MenuBar Background which
          is given to the MenuBar itself.

          This can be easily changed by adding
          different Backgrounds to the 
          File and Edit Menus.

          Note: The MenuBar is added to the
          MainFrame below.

         ******************************************************/
        // Creates two Backgrounds

        MenuBarRecPtr MainMenuBar = MenuBar::create();
        // Adds the two Menus to the MainMenuBar
        MainMenuBar->addMenu(FileMenu);
        MainMenuBar->addMenu(EditMenu);

        // Create two Labels
        LabelRecPtr ExampleLabel1 = Label::create();
        LabelRecPtr ExampleLabel2 = Label::create();

        ExampleLabel1->setText("Look up in the corner!");
        ExampleLabel1->setPreferredSize(Vec2f(150, 25));    

        ExampleLabel2->setText("Hit Control + Z");
        ExampleLabel2->setPreferredSize(Vec2f(150, 25));    

        // Create The Main InternalWindow
        // Create Background to be used with the Main InternalWindow
        EmptyLayerRecPtr MainInternalWindowBackground = EmptyLayer::create();
        EmptyBorderRecPtr MainInternalWindowBorder = EmptyBorder::create();

        LayoutRecPtr MainInternalWindowLayout = FlowLayout::create();

        InternalWindowRecPtr MainInternalWindow = InternalWindow::create();
        MainInternalWindow->pushToChildren(ExampleLabel1);
        MainInternalWindow->pushToChildren(ExampleLabel2);
        MainInternalWindow->setLayout(MainInternalWindowLayout);
        MainInternalWindow->setMenuBar(MainMenuBar);
        MainInternalWindow->setBackgrounds(MainInternalWindowBackground);
        MainInternalWindow->setBorders(MainInternalWindowBorder);
        MainInternalWindow->setAlignmentInDrawingSurface(Vec2f(0.5f,0.5f));
        MainInternalWindow->setScalingInDrawingSurface(Vec2f(1.0f,1.0f));
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
                                   "26MenuBar");

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

