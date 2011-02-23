// OpenSG Tutorial Example: Cluster Server
//
// This is a full functional OpenSG cluster server. In OpenSG
// the terms server and client are used similar to X11. The
// application is the client. Instances that are used for 
// rendering are called server.
//
// See the clusterclient.cpp for an example of how to use them.
//
// Libs: Cluster

#include <iostream>

#ifdef OSG_BUILD_ACTIVE
// General OpenSG configuration, needed everywhere
#include <OSGConfig.h>
// The Cluster server definition
#include <OSGClusterServer.h>
// Render action definition. 
#include <OSGRenderAction.h>

#include <OSGWindowUtils.h>
#else
// General OpenSG configuration, needed everywhere
#include <OpenSG/OSGConfig.h>
// The Cluster server defini2tion
#include <OpenSG/OSGClusterServer.h>
// Render action definition. 
#include <OpenSG/OSGRenderAction.h>

#include <OpenSG/OSGWindowUtils.h>
#endif

// Activate the OpenSG namespace
// This is not strictly necessary, you can also prefix all OpenSG symbols
// with OSG::, but that would be a bit tedious for this example
OSG_USING_NAMESPACE

// local glut window
WindowEventProducerRefPtr  window;
// render action
RenderAction     *ract;
// pointer the the cluster server instance
ClusterServer    *server;

// forward declaration so we can have the interesting stuff upfront
void display(void);
void reshape(Vec2f Size);

// Initialize GLUT & OpenSG and start the cluster server
int main(int argc, char **argv)
{
    const char     *name           = "ClusterServer";
    const char     *connectionType = "StreamSock";
    bool            fullscreen     = true;
    std::string     address        = "";

    Vec2f WinSize(400.f,400.0f);
    Pnt2f WinPos(500.f,100.0f);
    // evaluate params
    for(int a=1 ; a<argc ; ++a)
    {
        if(argv[a][0] == '-')
        {
            char *opt;
            switch(argv[a][1])
            {
                case 'm': connectionType="Multicast";
                          break;
                case 'p': connectionType="SockPipeline";
                          break;
                case 'w': opt = argv[a][2] ? argv[a]+2 : argv[++a];
                          if(opt != argv[argc])
                              WinSize[0] = atoi(opt);
                          break;
                case 'h': opt = argv[a][2] ? argv[a]+2 : argv[++a];
                          if(opt != argv[argc])
                              WinSize[1] = atoi(opt);
                          break;
                case 'x': opt = argv[a][2] ? argv[a]+2 : argv[++a];
                          if(opt != argv[argc])
                              WinPos[0] = atoi(opt);
                          break;
                case 'y': opt = argv[a][2] ? argv[a]+2 : argv[++a];
                          if(opt != argv[argc])
                              WinPos[1] = atoi(opt);
                          break;
                case 'a': address = argv[a][2] ? argv[a]+2 : argv[++a];
                          if(address.empty())
                          { 
                              SLOG << "address missing" << endLog;
                              return 0;
                          }
                          std::cout << address << endLog;
                          break;
                default:  std::cout << argv[0] 
                                    << "-m "
                                    << "-p "
                                    << "-w width"
                                    << "-h height"
                                    << "-x window x"
                                    << "-y window y"
                                    << "-a address "
                                    << endLog;
                          return 0;
            }
        }
        else
        {
            name=argv[a];
        }
    }
    try
    {
        preloadSharedObject("OSGContribUserInterface");
        // init OpenSG
        osgInit(argc, argv);

        //Create a Window object
        window = createNativeWindow();

        //Apply window settings
        window->setUseCallbackForDraw(true);
        window->setUseCallbackForReshape(true);
        window->initWindow();
        
        // create the SimpleSceneManager helper
        window->setDisplayCallback(boost::bind(display));
        window->setReshapeCallback(boost::bind(reshape, _1));

        // create the render action
        ract = RenderAction::create();

        // create the cluster server
        server     = new ClusterServer(window,name,connectionType,address);

        // start the server
        server->start();

        //Open Window
        window->openWindow(WinPos,
                           WinSize,
                           name);

        //Enter main loop
        window->mainLoop();
    }
    catch(OSG_STDEXCEPTION_NAMESPACE::exception &e)
    {
        SLOG << e.what() << endLog;
        
        // clean up global variables
        delete server;
        delete ract;
        window = NULL;
        
        osgExit(); 
    }
    return 0;
}

// redraw the window
void display(void)
{
    try
    {
        // receive scenegraph and do rendering
        server->render(ract);
        // clear changelist 
        Thread::getCurrentChangeList()->clear();
    } 
    catch(OSG_STDEXCEPTION_NAMESPACE::exception &e)
    {
        SLOG << e.what() << endLog;
        
        //window->clearPorts();

        //// try to restart server
        //server->stop();
        //// start server, wait for client to connect
        //server->start();

        throw(e);
    }
}

// react to size changes
void reshape(Vec2f Size)
{
	window->resize(Size.x(), Size.y());
}

