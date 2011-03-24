// OpenSG Tutorial Example: Creating a Text area to run a Lua script from
//

// General OpenSG configuration, needed everywhere
#include "OSGConfig.h"

// Methods to create simple geometry: boxes, spheres, tori etc.
#include "OSGSimpleGeometry.h"

// A little helper to simplify scene management and interaction
#include "OSGSimpleSceneManager.h"
#include "OSGNode.h"
#include "OSGGroup.h"
#include "OSGViewport.h"
#include "OSGGradientBackground.h"
#include "OSGNameAttachment.h"

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

//Lua
#include "OSGLuaActivity.h"

// Activate the OpenSG namespace
OSG_USING_NAMESPACE

// Forward declaration so we can have the interesting stuff upfront
void display(SimpleSceneManager *mgr);
void reshape(Vec2f Size, SimpleSceneManager *mgr);

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
    DocForeground->addLine("of a \\{\\color=AAAA00FF LuaActivity}.");

    DocForeground->addLine("");
    DocForeground->addLine("\\{\\color=AAAAAAFF Key Commands}:");
    DocForeground->addLine("   \\{\\color=AAAAFFFF <Any key>}: Run LuaActivity attached to KeyTyped");
    DocForeground->addLine("       \\{\\color=AAAAFFFF Cmd+q}: Close the application");
    DocForeground->addLine("           \\{\\color=AAAAFFFF ?}: Show/hide this documentation");

    DocForeground->addLine("");
    DocForeground->addLine("\\{\\color=AAAAAAFF Mouse Controls}:");
    DocForeground->addLine("   \\{\\color=AAAAFFFF <Any button>}: Run LuaActivity attached to MousePressed");

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

        //Make the Lua Activity
        std::string LuaButtonCode = 
            "if(not eventFuncTable) then eventFuncTable = {} end\n"
            "\n"
            "function eventFuncTable.handleButtonEvent(Event, EventID)\n"
            "    print(\"Source:  \", Event:getFieldValue(\"Source\"))\n"
            "    print(\"TimeStamp:  \", Event:getFieldValue(\"TimeStamp\"))\n"
            "    print(\"Button:  \", Event:getFieldValue(\"Button\"))\n"
            "    print(\"Position:  \", Event:getFieldValue(\"Location\"):x(), \", \", Event:getFieldValue(\"Location\"):y())\n"
            "end";

        std::string LuaKeyCode = 
            "if(not eventFuncTable) then eventFuncTable = {} end\n"
            "\n"
            "function eventFuncTable.handleKeyEvent(Event, EventID)\n"
            "    print(\"Source:  \", Event:getFieldValue(\"Source\"))\n"
            "    print(\"TimeStamp:  \", Event:getFieldValue(\"TimeStamp\"))\n"
            "    print(\"Key:  \", Event:getFieldValue(\"Key\"))\n"
            "end";
        LuaActivityRecPtr TheLuaButtonActivity = LuaActivity::create();
        TheLuaButtonActivity->setCode(LuaButtonCode);
        TheLuaButtonActivity->setEntryFunction("eventFuncTable.handleButtonEvent");

        LuaActivityRecPtr TheLuaKeyActivity = LuaActivity::create();
        TheLuaKeyActivity->setCode(LuaKeyCode);
        TheLuaKeyActivity->setEntryFunction("eventFuncTable.handleKeyEvent");

        TutorialWindow->attachActivity(WindowEventProducer::MousePressedEventId, TheLuaButtonActivity);
        TutorialWindow->attachActivity(WindowEventProducer::KeyTypedEventId, TheLuaKeyActivity);

        // Make Torus Node (creates Torus in background of scene)
        NodeRecPtr TorusGeometryNode = makeTorus(.5, 2, 16, 16);
        setName(TorusGeometryNode,"TorusGeometryNode");

        // Make Main Scene Node and add the Torus
        NodeRecPtr scene = Node::create();
        scene->setCore(Group::create());
        scene->addChild(TorusGeometryNode);
        setName(scene,"Scene Node");

        //Scene Background
        GradientBackgroundRecPtr SceneBackground = GradientBackground::create();
        SceneBackground->addLine(Color3f(0.0,0.0,0.0),0.0);
        setName(SceneBackground,"Scene Background");


        // Tell the Manager what to manage
        sceneManager.setRoot(scene);

        // Add the UI Foreground Object to the Scene
        ViewportRecPtr TutorialViewport = sceneManager.getWindow()->getPort(0);
        TutorialViewport->setBackground(SceneBackground);

        //Create the Documentation Foreground and add it to the viewport
        SimpleScreenDoc TheSimpleScreenDoc(&sceneManager, TutorialWindow);

        // Show the whole Scene
        sceneManager.showAll();


        //Open Window
        Vec2f WinSize(TutorialWindow->getDesktopSize() * 0.85f);
        Pnt2f WinPos((TutorialWindow->getDesktopSize() - WinSize) *0.5);
        TutorialWindow->openWindow(WinPos,
                                   WinSize,
                                   "05LuaActivity");

        //Enter main Loop
        TutorialWindow->mainLoop();
        TutorialWindow = NULL;
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

