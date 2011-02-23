// OpenSG Tutorial Example: Minimalistic OpenSG cluster client program
// 
// To test it, run 
//   ./clusterserver -geometry 300x300+200+100 -m -w test1 &
//   ./clusterserver -geometry 300x300+500+100 -m -w test2 &
//   ./clusterclient -m -fData/tie.wrl test1 test2
//
// If you have trouble with multicasting, you can alternatively try
//   ./clusterserver -geometry 300x300+200+100 -w 127.0.0.1:30000 &
//   ./clusterserver -geometry 300x300+500+100 -w 127.0.0.1:30001 &
//   ./clusterclient -m -fData/tie.wrl 127.0.0.1:30000 127.0.0.1:30001
// 
// The client will open an empty window that you can use to navigate. The
// display is shown in the server windows.
//
// This will run all three on the same machine, but you can also start the 
// servers anywhere else, as long as you can reach them via multicast.
//
// Note: This will run two VERY active OpenGL programs on one screen. Not all
// OpenGL drivers are happy with that, so if it crashes your X, it's not our
// fault! ;)
//
// Libs: Cluster

#ifdef OSG_BUILD_ACTIVE

// General OpenSG configuration, needed everywhere
#include <OSGConfig.h>

// Methods to create simple geometry: boxes, spheres, tori etc.
#include <OSGSimpleGeometry.h>

// A little helper to simplify scene management and interaction
#include <OSGSimpleSceneManager.h>

// A little helper to simplify scene management and interaction
#include <OSGMultiDisplayWindow.h>

// Scene file handler for loading geometry files
#include <OSGSceneFileHandler.h>

#include <OSGWindowUtils.h>
#else

// General OpenSG configuration, needed everywhere
#include <OpenSG/OSGConfig.h>

// Methods to create simple geometry: boxes, spheres, tori etc.
#include <OpenSG/OSGSimpleGeometry.h>

// A little helper to simplify scene management and interaction
#include <OpenSG/OSGSimpleSceneManager.h>

// A little helper to simplify scene management and interaction
#include <OpenSG/OSGMultiDisplayWindow.h>

// Scene file handler for loading geometry files
#include <OpenSG/OSGSceneFileHandler.h>

#include <OpenSG/OSGWindowUtils.h>
#endif

#include "OSGTransform.h"
#include "OSGComponentTransform.h"
#include "OSGNameAttachment.h"

#include "OSGAnimation.h"
#include "OSGBackground.h"
#include "OSGForeground.h"
#include "OSGUIDrawingSurface.h"
#include "OSGInternalWindow.h"
#include "OSGUIForeground.h"
#include "OSGGraphics2D.h"
#include "OSGParticleSystem.h"
#include "OSGLookAndFeelManager.h"

#include "OSGFCFileHandler.h"
#include <boost/filesystem/convenience.hpp>

// Activate the OpenSG namespace
// This is not strictly necessary, you can also prefix all OpenSG symbols
// with OSG::, but that would be a bit tedious for this example
OSG_USING_NAMESPACE

// The SimpleSceneManager to manage simple applications
SimpleSceneManager *mgr;

// forward declaration so we can have the interesting stuff upfront
void display(SimpleSceneManager *LocalMgr);
void reshape(Vec2f Size, SimpleSceneManager *LocalMgr);
void keyPressed(KeyEventDetails* const details);
void mousePressed(MouseEventDetails* const details, SimpleSceneManager *LocalMgr);
void mouseReleased(MouseEventDetails* const details, SimpleSceneManager *LocalMgr);
void mouseDragged(MouseEventDetails* const details, SimpleSceneManager *LocalMgr);
void mouseWheelMoved(MouseWheelEventDetails* const details, SimpleSceneManager *LocalMgr);
void update(UpdateEventDetails* const details);

// Initialize GLUT & OpenSG and set up the scene
int main(int argc, char **argv)
{
    char *opt;

    // OSG init
    osgInit(argc,argv);

    // Initialize the LookAndFeelManager to enable default settings
    LookAndFeelManager::the()->getLookAndFeel()->init();

    //Create a Window object
    WindowEventProducerRefPtr window = createNativeWindow();

    //Scene Path
    BoostPath SceneFilePath;

    NodeRefPtr               SceneRoot;
    BackgroundRefPtr         SceneBackground;
    std::vector<ForegroundRecPtr> SceneForegrounds;
    std::vector<AnimationRecPtr> SceneAnimations;
    std::vector<UIDrawingSurfaceRecPtr> SceneUIDrawingSurfaces;
    std::vector<InternalWindowRecPtr> SceneUIWindows;
    std::vector<ParticleSystemRecPtr> SceneParticleSystems;

    // open a new scope, because the pointers below should go out of scope
    // Otherwise OpenSG will complain about objects being alive after shutdown.
    {
        // the connection between this client and the servers
        MultiDisplayWindowRefPtr mwin  = MultiDisplayWindow::create();
    
        // evaluate params
        for(int a=1 ; a<argc ; ++a)
        {
            if(argv[a][0] == '-')
            {
                switch(argv[a][1])
                {
                case 'm': mwin->setConnectionType("Multicast");
                          std::cout << "Connection type set to Multicast"
                                    << std::endl;
                          break;
                case 'p': mwin->setConnectionType("SockPipeline");
                          std::cout << "Connection type set to SockPipeline"
                                    << std::endl;
                          break;
                case 'i': opt = argv[a][2] ? argv[a]+2 : argv[++a];
                          if(opt != argv[argc])
                              mwin->setConnectionInterface(opt);
                          break;
                case 'a': opt = argv[a][2] ? argv[a]+2 : argv[++a];
                          if(opt != argv[argc])
                              mwin->setServiceAddress(opt);
                          break;
                case 'f': opt = argv[a][2] ? argv[a]+2 : argv[++a];
                          if(opt != argv[argc])
                              SceneFilePath = BoostPath(opt);
                          break;
                case 'x': opt = argv[a][2] ? argv[a]+2 : argv[++a];
                          if(opt != argv[argc])
                              mwin->setHServers(atoi(opt));
                          break;
                case 'y': opt = argv[a][2] ? argv[a]+2 : argv[++a];
                          if(opt != argv[argc])
                              mwin->setVServers(atoi(opt));
                          break;
                default:  std::cout << argv[0]  
                                    << " -m"
                                    << " -p"
                                    << " -i interface"
                                    << " -f file"
                                    << " -x horizontal server cnt"
                                    << " -y vertical server cnt"
                                    << std::endl;
                          return 0;
                }
            }
            else
            {
                printf("%s\n",argv[a]);
                mwin->editMFServers()->push_back(argv[a]);
            }
        }
    
        // dummy size for navigator
        mwin->setSize(300,300);

        //Load the scene file
        if(!boost::filesystem::exists(SceneFilePath))
        {
            std::cerr << "Could not load file: "<< SceneFilePath.string()
                      << ", because no such files exists."<< std::endl;
        }
        else
        {
            FCFileType::FCPtrStore ObjStore = FCFileHandler::the()->read(SceneFilePath);
            for(FCFileType::FCPtrStore::iterator StorItor(ObjStore.begin());
                StorItor != ObjStore.end();
                ++StorItor)
            {
                //Handle Animations
                if((*StorItor)->getType().isDerivedFrom(Animation::getClassType()))
                {
                    SceneAnimations.push_back(dynamic_pointer_cast<Animation>(*StorItor));
                }

                //Handle Root Nodes
                else if((*StorItor)->getType() == Node::getClassType() &&
                        dynamic_pointer_cast<Node>(*StorItor)->getParent() == NULL)
                {
                    if(SceneRoot == NULL)
                    {
                        SceneRoot = makeCoredNode<Group>();
                    }

                    SceneRoot->addChild(dynamic_pointer_cast<Node>(*StorItor));
                }

                //Handle Backgrounds
                else if((*StorItor)->getType().isDerivedFrom(Background::getClassType()))
                {
                    SceneBackground = dynamic_pointer_cast<Background>(*StorItor);
                }

                //Handle Foregrounds
                else if((*StorItor)->getType().isDerivedFrom(Foreground::getClassType()))
                {
                    SceneForegrounds.push_back(dynamic_pointer_cast<Foreground>(*StorItor));
                }

                //Handle ParticleSystems
                else if((*StorItor)->getType().isDerivedFrom(ParticleSystem::getClassType()))
                {
                    SceneParticleSystems.push_back(dynamic_pointer_cast<ParticleSystem>(*StorItor));
                }

                //Handle DrawingSurfaces
                //else if((*StorItor)->getType() == UIDrawingSurface::getClassType())
                //{
                    //SceneUIDrawingSurfaces.push_back(dynamic_pointer_cast<UIDrawingSurfaces>(*StorItor));
                //}

                //Handle UI Windows
                else if( (*StorItor)->getType().isDerivedFrom((InternalWindow::getClassType())))
                {
                    SceneUIWindows.push_back(dynamic_pointer_cast<InternalWindow>(*StorItor));
                }
            }
        }
    
        // create default scene
        if(SceneRoot == NULL)
        {
            SceneRoot = makeTorus(.5, 2, 32, 32);
        }
    
        commitChanges();
    
        // create the SimpleSceneManager helper
        mgr = new SimpleSceneManager;
    
        // tell the manager what to manage
        mgr->setWindow(mwin );
        mgr->setRoot  (SceneRoot);
    
        // show the whole scene
        mgr->showAll();
        
        // initialize window
        mwin->init();
    }

    //Apply window settings
    window->setUseCallbackForDraw(true);
    window->setUseCallbackForReshape(true);
    window->initWindow();


    // tell the manager what to manage
    SimpleSceneManager LocalMgr;
    LocalMgr.setWindow(window );
    //NodeRecPtr LocalNode = makeNodeFor(SceneRoot->getCore());
    NodeRecPtr LocalNode = makeCoredNode<Group>();
    LocalMgr.setRoot  (LocalNode);

    ViewportRefPtr TutorialViewport = mgr->getWindow()->getPort(0);

    //Start all animations
    for(UInt32 i(0) ; i<SceneAnimations.size() ; ++i)
    {
        SceneAnimations[i]->attachUpdateProducer(window);
        SceneAnimations[i]->start();
    }

    //Add all foregrounds
    for(UInt32 i(0) ; i<SceneForegrounds.size() ; ++i)
    {
        TutorialViewport->addForeground(SceneForegrounds[i]);
    }

    //Add background if on was defined
    if(SceneBackground != NULL)
    {
        SLOG << "Bg Not NULL" << std::endl;
        TutorialViewport->setBackground(SceneBackground);
    }

    //Attach all UI drawing surfaces
    //for(UInt32 i(0) ; i<SceneUIDrawingSurfaces.size() ; ++i)
    //{
        //SceneUIDrawingSurfaces[i]->setEventProducer(window);
    //}

    //Add all ParticleSystems
    for(UInt32 i(0) ; i<SceneParticleSystems.size() ; ++i)
    {
        SceneParticleSystems[i]->attachUpdateProducer(window);
    }

    if(SceneUIWindows.size() > 0)
    {
        // Create the Graphics
        GraphicsRecPtr TutorialGraphics = Graphics2D::create();

        // Create the Drawing Surface
        UIDrawingSurfaceRecPtr TutorialDrawingSurface = UIDrawingSurface::create();
        TutorialDrawingSurface->setGraphics(TutorialGraphics);
        TutorialDrawingSurface->setEventProducer(window);
        TutorialDrawingSurface->setSize(Vec2f(1200.0f, 800.0f));

        //Loop through the vector and open each window
        for(UInt32 i(0) ; i<SceneUIWindows.size() ; ++i)
        {
            TutorialDrawingSurface->openWindow(SceneUIWindows[i]);
        }

        // Create the UI Foreground Object
        UIForegroundRecPtr TutorialUIForeground = UIForeground::create();
        TutorialUIForeground->setDrawingSurface(TutorialDrawingSurface);

        //Add the foreground
        TutorialViewport->addForeground(TutorialUIForeground);
    }

    // show the whole scene
    LocalMgr.showAll();
    
    // create the SimpleSceneManager helper
    window->setDisplayCallback(boost::bind(display, &LocalMgr));
    window->setReshapeCallback(boost::bind(reshape, _1, &LocalMgr));

    //Attach to events
    window->connectMousePressed(boost::bind(mousePressed, _1, &LocalMgr));
    window->connectMouseReleased(boost::bind(mouseReleased, _1, &LocalMgr));
    window->connectMouseDragged(boost::bind(mouseDragged, _1, &LocalMgr));
    window->connectMouseWheelMoved(boost::bind(mouseWheelMoved, _1, &LocalMgr));
    window->connectKeyPressed(boost::bind(keyPressed, _1));
    //window->connectUpdate(boost::bind(update, _1));

    //FieldAnimationRecPtr TheAnimation =
        //setupAnimation(dynamic_cast<Transform*>(SceneRoot->getCore()), window);

    Vec2f WinSize(300.0f,300.0f);
    Pnt2f WinPos(10.0f,30.0f);
    window->openWindow(WinPos,
                       WinSize,
                       "Client Window");
    
    window->mainLoop();

    return 0;
}

//
// callback functions
//

void display(SimpleSceneManager *localMgr)
{
    mgr->redraw();
    localMgr->redraw();

    // clear change list. If you don't clear the changelist,
    // then the same changes will be transmitted a second time
    // in the next frame. 
    Thread::getCurrentChangeList()->clear();

    //osgSleep(10);
}

// react to size changes
void reshape(Vec2f Size, SimpleSceneManager *localMgr)
{
    std::cout << "Reshape" << std::endl;
}

void update(UpdateEventDetails* const details)
{
    std::cout << "Update" << std::endl;
}

void keyPressed(KeyEventDetails* const details)
{
    if(details->getKey() == KeyEventDetails::KEY_Q &&
       details->getModifiers() & KeyEventDetails::KEY_MODIFIER_COMMAND)
    {
        dynamic_cast<WindowEventProducer*>(details->getSource())->closeWindow();
    }
    //switch(details->getKey())
    //{
    //case KeyEventDetails::KEY_T:
        //TutorialUIForeground->setTile(!TutorialUIForeground->getTile());
        //break;

    //}
}

void mousePressed(MouseEventDetails* const details, SimpleSceneManager *localMgr)
{
    mgr->mouseButtonPress(details->getButton(), details->getLocation().x(), details->getLocation().y());
}

void mouseReleased(MouseEventDetails* const details, SimpleSceneManager *localMgr)
{
    mgr->mouseButtonRelease(details->getButton(), details->getLocation().x(), details->getLocation().y());
}

void mouseDragged(MouseEventDetails* const details, SimpleSceneManager *localMgr)
{
    mgr->mouseMove(details->getLocation().x(), details->getLocation().y());
}

void mouseWheelMoved(MouseWheelEventDetails* const details, SimpleSceneManager *localMgr)
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

