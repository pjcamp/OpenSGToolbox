// 
// OpenSGToolbox Tutorial: 08MorphGeometry
//
// Demonstrates a simple animation using transformation keyframes. 
//


// General OpenSG configuration, needed everywhere
#include "OSGConfig.h"

// Methods to create simple geometry: boxes, spheres, tori etc.
#include "OSGSimpleGeometry.h"

// A little helper to simplify scene management and interaction
#include "OSGSimpleSceneManager.h"

// Input
#include "OSGWindowUtils.h"
#include "OSGWindowEventProducer.h"
#include "OSGRenderOptions.h"

//Text Foreground
#include "OSGSimpleTextForeground.h"

//Animation
#include "OSGKeyframeSequences.h"
#include "OSGKeyframeAnimator.h"
#include "OSGFieldAnimation.h"

#include "OSGFCFileHandler.h"
#include "OSGSceneFileHandler.h"
#include <boost/filesystem/convenience.hpp>

#include "OSGAnimation.h"

// Activate the OpenSG namespace
// This is not strictly necessary, you can also prefix all OpenSG symbols
// with OSG::, but that would be a bit tedious for this example
OSG_USING_NAMESPACE


// forward declaration so we can have the interesting stuff upfront
// The SimpleSceneManager to manage simple applications
void display(SimpleSceneManager *mgr);
void reshape(Vec2f Size, SimpleSceneManager *mgr);

void saveScene(Node* const TheScene,
               WindowEventProducer* const TheMainWindow)
{
    std::vector<WindowEventProducer::FileDialogFilter> Filters;
    Filters.push_back(WindowEventProducer::FileDialogFilter("All","*"));

    BoostPath SavePath=
        TheMainWindow->saveFileDialog("Save scene to",
                                      Filters,
                                      std::string("ModelExport.osb"),
                                      BoostPath("."),
                                      true);

    if(!SavePath.empty())
    {
        //Try saving as a FCFile
        if(!FCFileHandler::the()->write(TheScene, SavePath))
        {
            //Failed to save as a FCFile

            //Try saving as a Scene file
            SceneFileHandler::the()->write(TheScene, SavePath.string().c_str());
        }
    }
}

void openScene(SimpleSceneManager *SceneManager,
               WindowEventProducer* const TheMainWindow)
{
    std::vector<WindowEventProducer::FileDialogFilter> Filters;
    Filters.push_back(WindowEventProducer::FileDialogFilter("All","*"));

    std::vector<BoostPath> FilesToOpen;
    FilesToOpen = TheMainWindow->openFileDialog("Open model file",
                                                Filters,
                                                BoostPath("."),
                                                false);

    if(FilesToOpen.size() > 0)
    {
        NodeRefPtr LoadedRoot;
        //std::vector<AnimationRecPtr> LoadedAnimations;

        FCFileType::FCPtrStore ObjStore;
        try
        {
            ObjStore = FCFileHandler::the()->read(FilesToOpen.front());
        }
        catch(std::exception &ex)
        {
            std::cerr << "Failed to load file: " << FilesToOpen.front().string() << ", error:"
                     << ex.what()                        << std::endl;
            return;
        }
        for(FCFileType::FCPtrStore::iterator StorItor(ObjStore.begin());
            StorItor != ObjStore.end();
            ++StorItor)
        {
            //Animations
            //if((*StorItor)->getType().isDerivedFrom(Animation::getClassType()))
            //{
                //LoadedAnimations.push_back(dynamic_pointer_cast<Animation>(*StorItor));
                //LoadedAnimations.back()->attachUpdateProducer(TutorialWindow);
                //LoadedAnimations.back()->start();
            //}
            //Root Node
            if((*StorItor)->getType() == Node::getClassType() &&
                    dynamic_pointer_cast<Node>(*StorItor)->getParent() == NULL)
            {
                LoadedRoot = dynamic_pointer_cast<Node>(*StorItor);
            }
        }

        bool LoadedFileSuccessfully = (LoadedRoot != NULL);

        if(!LoadedFileSuccessfully)
        {
            LoadedRoot =
                SceneFileHandler::the()->read(FilesToOpen.front().string().c_str(), NULL);
            LoadedFileSuccessfully = (LoadedRoot != NULL);
        }

        if(LoadedFileSuccessfully)
        {
            // tell the manager what to manage
            SceneManager->setRoot  (LoadedRoot);

            // show the whole scene
            SceneManager->showAll();
        }
    }
}

void keyPressed(KeyEventDetails* const details,
                SimpleSceneManager *SceneManager)
{
    if(details->getModifiers() & KeyEventDetails::KEY_MODIFIER_COMMAND)
    {
        WindowEventProducer* TheMainWindow(dynamic_cast<WindowEventProducer*>(details->getSource()));
        switch(details->getKey())
        {
            case KeyEventDetails::KEY_Q:
                TheMainWindow->closeWindow();
                break;
            case KeyEventDetails::KEY_O:
                //Open a model file
                openScene(SceneManager, TheMainWindow);
                break;
            case KeyEventDetails::KEY_S:
                //Save the model
                saveScene(SceneManager->getRoot(), TheMainWindow);
                break;
        }
    }
    else
    {
        switch(details->getKey())
        {
            case KeyEventDetails::KEY_T:
                SceneManager->setStatistics(!SceneManager->getStatistics());
                break;
            case KeyEventDetails::KEY_H:
                SceneManager->setHeadlight(!SceneManager->getHeadlightState());
                break;
            case KeyEventDetails::KEY_A:
                SceneManager->showAll();
                break;
            case KeyEventDetails::KEY_V:
                SceneManager->getRenderAction()->setVolumeDrawing(!SceneManager->getRenderAction()->getVolumeDrawing());
                break;
        }
    }
}

void mousePressed(MouseEventDetails* const details, SimpleSceneManager *mgr)
{
    mgr->mouseButtonPress(details->getButton(), details->getLocation().x(), details->getLocation().y());
}

void mouseReleased(MouseEventDetails* const details, SimpleSceneManager *mgr)
{
    mgr->mouseButtonRelease(details->getButton(), details->getLocation().x(), details->getLocation().y());
}

void mouseDragged(MouseEventDetails* const details, SimpleSceneManager *mgr)
{
    mgr->mouseMove(details->getLocation().x(), details->getLocation().y());
}

void mouseWheelMoved(MouseWheelEventDetails* const details, SimpleSceneManager *mgr)
{
    if(details->getUnitsToScroll() > 0)
    {
        for(UInt32 i(0) ; i<details->getUnitsToScroll() ;++i)
        {
            mgr->mouseButtonPress(Navigator::DOWN_MOUSE,details->getLocation().x(),details->getLocation().y());
        }
    }
    else if(details->getUnitsToScroll() < 0)
    {
        for(UInt32 i(0) ; i<abs(details->getUnitsToScroll()) ;++i)
        {
            mgr->mouseButtonPress(Navigator::UP_MOUSE,details->getLocation().x(),details->getLocation().y());
        }
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
    DocForeground->addLine("of a \\{\\color=AAAA00FF FCFileHandler} and \\{\\color=AAAA00FF SceneFileHandler}.");
    
    DocForeground->addLine("");
    DocForeground->addLine("\\{\\color=AAAAAAFF Key Commands}:");
    DocForeground->addLine("   \\{\\color=AAAAFFFF h}: Turn headlight on/off");
    DocForeground->addLine("   \\{\\color=AAAAFFFF t}: Show/hide statistics");
    DocForeground->addLine("   \\{\\color=AAAAFFFF v}: Show/hide node bounding boxes");
    DocForeground->addLine("   \\{\\color=AAAAFFFF a}: Show the entire scene");
    DocForeground->addLine("   \\{\\color=AAAAFFFF Cmd+o}: Open a model file");
    DocForeground->addLine("   \\{\\color=AAAAFFFF Cmd+s}: Save a model file");
    DocForeground->addLine("   \\{\\color=AAAAFFFF Cmd+q}: Close the application");
    DocForeground->addLine("       \\{\\color=AAAAFFFF ?}: Show/hide this documentation");

    DocForeground->addLine("");
    DocForeground->addLine("\\{\\color=AAAAAAFF Mouse Controls}:");
    DocForeground->addLine("   \\{\\color=AAAAFFFF Scroll wheel}: Zoom in/out");
    DocForeground->addLine("      \\{\\color=AAAAFFFF Left+drag}: Rotate");
    DocForeground->addLine("     \\{\\color=AAAAFFFF Right+drag}: Translate");

    return SimpleTextForegroundTransitPtr(DocForeground);
}

// Initialize GLUT & OpenSG and set up the scene
int main(int argc, char **argv)
{
    // OSG init
    osgInit(argc,argv);

    {
        // Set up Window
        WindowEventProducerRecPtr TutorialWindow = createNativeWindow();

        //Initialize Window
        TutorialWindow->initWindow();
        bool LoadedFileSuccessfully(false);

        SimpleSceneManager sceneManager;
        TutorialWindow->setDisplayCallback(boost::bind(display, &sceneManager));
        TutorialWindow->setReshapeCallback(boost::bind(reshape, _1, &sceneManager));

        // Tell the Manager what to manage
        sceneManager.setWindow(TutorialWindow);

        //Attach to events
        TutorialWindow->connectMousePressed(boost::bind(mousePressed, _1, &sceneManager));
        TutorialWindow->connectMouseReleased(boost::bind(mouseReleased, _1, &sceneManager));
        TutorialWindow->connectMouseDragged(boost::bind(mouseDragged, _1, &sceneManager));
        TutorialWindow->connectMouseWheelMoved(boost::bind(mouseWheelMoved, _1, &sceneManager));
        TutorialWindow->connectKeyPressed(boost::bind(keyPressed, _1, &sceneManager));

        BoostPath FilePath("../Animation/Data/Nanobot.dae");
        if(argc >= 2)
        {
            FilePath = BoostPath(argv[1]);
            if(!boost::filesystem::exists(FilePath))
            {
                std::cerr << "Could not load file: "<< FilePath.string()
                          << ", because no such files exists."<< std::endl;
                FilePath = BoostPath("../Animation/Data/Nanobot.dae");
            }
        }

        NodeRefPtr LoadedRoot;
        std::vector<AnimationRecPtr> LoadedAnimations;

        FCFileType::FCPtrStore ObjStore;
        try
        {
            ObjStore = FCFileHandler::the()->read(FilePath);
        }
        catch(std::exception &ex)
        {
            std::cerr << "Failed to load file: " << FilePath.string() << ", error:"
                     << ex.what()                        << std::endl;
            return -1;
        }
        for(FCFileType::FCPtrStore::iterator StorItor(ObjStore.begin());
            StorItor != ObjStore.end();
            ++StorItor)
        {
            //Animations
            if((*StorItor)->getType().isDerivedFrom(Animation::getClassType()))
            {
                LoadedAnimations.push_back(dynamic_pointer_cast<Animation>(*StorItor));
                LoadedAnimations.back()->attachUpdateProducer(TutorialWindow);
                LoadedAnimations.back()->start();
            }
            //Root Node
            if((*StorItor)->getType() == Node::getClassType() &&
                    dynamic_pointer_cast<Node>(*StorItor)->getParent() == NULL)
            {
                LoadedRoot = dynamic_pointer_cast<Node>(*StorItor);
            }
        }

        LoadedFileSuccessfully = (LoadedRoot != NULL);

        if(!LoadedFileSuccessfully)
        {
            LoadedRoot =
                SceneFileHandler::the()->read(FilePath.string().c_str(), NULL);
            LoadedFileSuccessfully = (LoadedRoot != NULL);
        }

        if(!LoadedFileSuccessfully)
        {
            LoadedRoot= makeTorus(.5, 2, 32, 32);
        }

        //Make Main Scene Node
        NodeRefPtr scene = makeCoredNode<Group>();

        scene->addChild(LoadedRoot);

        // tell the manager what to manage
        sceneManager.setRoot  (scene);

        //Create the Documentation Foreground and add it to the viewport
        SimpleScreenDoc TheSimpleScreenDoc(&sceneManager, TutorialWindow);

        // show the whole scene
        sceneManager.showAll();
        sceneManager.setStatistics(true);

        sceneManager.getWindow()->getPort(0)->setTravMask(1);
        RenderOptionsRecPtr ViewportRenderOptions = RenderOptions::create();
        ViewportRenderOptions->setRenderProperties(0x0);
        ViewportRenderOptions->setRenderProperties(RenderPropertiesPool::the()->getFrom1("Default"));
        ViewportRenderOptions->setRenderProperties(0x01);

        sceneManager.getWindow()->getPort(0)->setRenderOptions(ViewportRenderOptions);

        Vec2f WinSize(TutorialWindow->getDesktopSize() * 0.85f);
        Pnt2f WinPos((TutorialWindow->getDesktopSize() - WinSize) *0.5);
        std::string WindowTitle("OpenSG Viewer - ");
        if(LoadedFileSuccessfully)
        {
            WindowTitle += FilePath.string();
        }
        else
        {
            WindowTitle += "[No file loaded]";
        }
        TutorialWindow->openWindow(WinPos,
                                   WinSize,
                                   WindowTitle);

        //Enter main Loop
        TutorialWindow->mainLoop();

    }

    osgExit();

    return 0;
}

// Redraw the window
void display(SimpleSceneManager *mgr)
{
    mgr->redraw();

    //Commit and Clear the change list
    //Since this is a single aspect, non-clustered application
    //The ChangeList can be cleared periodically
    commitChangesAndClear();
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
    _DocForeground->setHorizontalAlign(SimpleTextForeground::Right);
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

