// OpenSG Tutorial Example: Hello World
//
// Minimalistic OpenSG program
// 
// This is the shortest useful OpenSG program 
// (if you remove all the comments ;)
//
// It shows how to use OpenSG together with GLUT to create a little
// interactive rootNode viewer.
//

// General OpenSG configuration, needed everywhere
#include "OSGConfig.h"

// Methods to create simple geometry: boxes, spheres, tori etc.
#include "OSGSimpleGeometry.h"

// A little helper to simplify rootNode management and interaction
#include "OSGSimpleSceneManager.h"

#include "OSGSimpleMaterial.h"

#include "OSGComponentTransform.h"
#include "OSGTransform.h"
#include "OSGTypeFactory.h"


#include "OSGFieldContainerFactory.h"
#include "OSGNameAttachment.h"
#include "OSGSceneFileHandler.h"

// Input
#include "OSGWindowUtils.h"

//Text Foreground
#include "OSGSimpleTextForeground.h"

//Animation
#include "OSGKeyframeSequences.h"
#include "OSGKeyframeAnimator.h"
#include "OSGFieldAnimation.h"

//Physics
#include "OSGPhysics.h"

// Activate the OpenSG namespace
// This is not strictly necessary, you can also prefix all OpenSG symbols
// with , but that would be a bit tedious for this example
OSG_USING_NAMESPACE


// forward declaration so we can have the interesting stuff upfront
void display(SimpleSceneManager *mgr);
void reshape(Vec2f Size, SimpleSceneManager *mgr);
void buildHingeJointMesh(Node* const spaceGroupNode,
                         PhysicsWorld* const physicsWorld,
                         PhysicsHashSpace* const physicsSpace);
void buildBallJointMesh(Node* const spaceGroupNode,
                        PhysicsWorld* const physicsWorld,
                        PhysicsHashSpace* const physicsSpace);
void buildMotorJointMesh(Node* const spaceGroupNode,
                         PhysicsWorld* const physicsWorld,
                         PhysicsHashSpace* const physicsSpace);

void keyPressed(KeyEventDetails* const details,
                Node* const spaceGroupNode,
                PhysicsWorld* const physicsWorld,
                PhysicsHashSpace* const physicsSpace)
{
    if(details->getKey() == KeyEventDetails::KEY_Q &&
       details->getModifiers() & KeyEventDetails::KEY_MODIFIER_COMMAND)
    {
        dynamic_cast<WindowEventProducer*>(details->getSource())->closeWindow();
    }
    switch(details->getKey())
    {
        case KeyEventDetails::KEY_H:
            {
                buildHingeJointMesh(spaceGroupNode,
                                    physicsWorld,
                                    physicsSpace);
            }
            break;
        case KeyEventDetails::KEY_B:
            {
                buildBallJointMesh(spaceGroupNode,
                                   physicsWorld,
                                   physicsSpace);
            }
            break;
        case KeyEventDetails::KEY_M:
            {
                buildMotorJointMesh(spaceGroupNode,
                                    physicsWorld,
                                    physicsSpace);
            }
            break;
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
    DocForeground->addLine("of \\{\\color=AAAA00FF HingeJoint}, \\{\\color=AAAA00FF BallJoint}, and \\{\\color=AAAA00FF MotorJoint}");
    
    DocForeground->addLine("");
    DocForeground->addLine("\\{\\color=AAAAAAFF Key Controls}:");
    DocForeground->addLine("       \\{\\color=AAAAFFFF h}: Create Hinge joint");
    DocForeground->addLine("       \\{\\color=AAAAFFFF b}: Create Ball joint");
    DocForeground->addLine("       \\{\\color=AAAAFFFF m}: Create Motor joint");
    DocForeground->addLine("   \\{\\color=AAAAFFFF Cmd+q}: Close the application");
    DocForeground->addLine("       \\{\\color=AAAAFFFF ?}: Show/hide this documentation");

    DocForeground->addLine("");
    DocForeground->addLine("\\{\\color=AAAAAAFF Mouse Controls}:");
    DocForeground->addLine("   \\{\\color=AAAAFFFF Scroll wheel}: Zoom in/out");
    DocForeground->addLine("      \\{\\color=AAAAFFFF Left+drag}: Rotate");
    DocForeground->addLine("     \\{\\color=AAAAFFFF Right+drag}: Translate");

    return SimpleTextForegroundTransitPtr(DocForeground);
}

// Initialize GLUT & OpenSG and set up the rootNode
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

        //Attach to events
        TutorialWindow->connectMousePressed(boost::bind(mousePressed, _1, &sceneManager));
        TutorialWindow->connectMouseReleased(boost::bind(mouseReleased, _1, &sceneManager));
        TutorialWindow->connectMouseDragged(boost::bind(mouseDragged, _1, &sceneManager));
        TutorialWindow->connectMouseWheelMoved(boost::bind(mouseWheelMoved, _1, &sceneManager));

        //Make Main Scene Node
        NodeUnrecPtr scene = makeCoredNode<Group>();
        setName(scene, "scene");
        NodeRecPtr rootNode = Node::create();
        setName(rootNode, "rootNode");
        ComponentTransformUnrecPtr Trans = ComponentTransform::create();
        rootNode->setCore(Trans);

        // add the torus as a child
        rootNode->addChild(scene);

        //Setup Physics Scene
        PhysicsWorldRecPtr physicsWorld = PhysicsWorld::create();
        physicsWorld->setWorldContactSurfaceLayer(0.005);
        physicsWorld->setAutoDisableFlag(1);
        physicsWorld->setAutoDisableTime(0.75);
        physicsWorld->setWorldContactMaxCorrectingVel(100.0);
        physicsWorld->setGravity(Vec3f(0.0, 0.0, -9.81));
        physicsWorld->setCfm(0.001);
        physicsWorld->setErp(0.2);

        PhysicsHashSpaceRecPtr hashSpace = PhysicsHashSpace::create();

        PhysicsHandlerRecPtr physHandler = PhysicsHandler::create();
        physHandler->setWorld(physicsWorld);
        physHandler->pushToSpaces(hashSpace);
        physHandler->setUpdateNode(rootNode);
        physHandler->attachUpdateProducer(TutorialWindow);

        rootNode->addAttachment(physHandler);    
        rootNode->addAttachment(physicsWorld);
        rootNode->addAttachment(hashSpace);


        /************************************************************************/
        /* create spaces, geoms and bodys                                                                     */
        /************************************************************************/
        //create a group for our space
        GroupUnrecPtr spaceGroup;
        NodeRecPtr spaceGroupNode = makeCoredNode<Group>(&spaceGroup);
        //create the ground plane
        GeometryUnrecPtr plane;
        NodeUnrecPtr planeNode = makeBox(30.0, 30.0, 1.0, 1, 1, 1);
        plane = dynamic_cast<Geometry*>(planeNode->getCore());
        //and its Material
        SimpleMaterialUnrecPtr plane_mat = SimpleMaterial::create();
        plane_mat->setAmbient(Color3f(0.7,0.7,0.7));
        plane_mat->setDiffuse(Color3f(0.9,0.6,1.0));
        plane->setMaterial(plane_mat);


        //create Physical Attachments
        PhysicsBoxGeomUnrecPtr planeGeom = PhysicsBoxGeom::create();
        planeGeom->setLengths(Vec3f(30.0, 30.0, 1.0));
        //add geoms to space for collision
        planeGeom->setSpace(hashSpace);

        //add Attachments to nodes...
        spaceGroupNode->addAttachment(hashSpace);
        spaceGroupNode->addChild(planeNode);

        planeNode->addAttachment(planeGeom);

        scene->addChild(spaceGroupNode);

        TutorialWindow->connectKeyPressed(boost::bind(keyPressed, _1,
                                                      spaceGroupNode.get(),
                                                      physicsWorld.get(),
                                                      hashSpace.get()));

        // tell the manager what to manage
        sceneManager.setRoot  (rootNode);

        //Create the Documentation
        SimpleScreenDoc TheSimpleScreenDoc(&sceneManager, TutorialWindow);

        // show the whole rootNode
        sceneManager.getNavigator()->set(Pnt3f(-10.0,10.0,15.0), Pnt3f(0.0,0.0,0.0), Vec3f(0.0,0.0,1.0));
        sceneManager.getNavigator()->setMotionFactor(1.0f);
        sceneManager.getCamera()->setFar(10000.0f);
        sceneManager.getCamera()->setNear(0.1f);

        Vec2f WinSize(TutorialWindow->getDesktopSize() * 0.85f);
        Pnt2f WinPos((TutorialWindow->getDesktopSize() - WinSize) *0.5);
        TutorialWindow->openWindow(WinPos,
                                   WinSize,
                                   "02Joints");

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
}

// React to size changes
void reshape(Vec2f Size, SimpleSceneManager *mgr)
{
    mgr->resize(Size.x(), Size.y());
}


PhysicsBodyUnrecPtr  buildBox(const Pnt3f& Position,
                              const Vec3f& Dimensions,
                              const Color3f& Color,
                              Node* const spaceGroupNode,
                              PhysicsWorld* const physicsWorld,
                              PhysicsHashSpace* const physicsSpace)
{
    Matrix m;
    //create OpenSG mesh
    GeometryUnrecPtr box;
    NodeUnrecPtr boxNode = makeBox(Dimensions.x(), Dimensions.y(), Dimensions.z(), 1, 1, 1);
    box = dynamic_cast<Geometry*>(boxNode->getCore());
    SimpleMaterialUnrecPtr box_mat = SimpleMaterial::create();
    box_mat->setAmbient(Color3f(0.0,0.0,0.0));
    box_mat->setDiffuse(Color);
    box->setMaterial(box_mat);
    TransformUnrecPtr boxTrans;
    NodeUnrecPtr boxTransNode = makeCoredNode<Transform>(&boxTrans);
    m.setIdentity();
    m.setTranslate(Position);
    boxTrans->setMatrix(m);

    //create ODE data
    PhysicsBodyUnrecPtr boxBody = PhysicsBody::create(physicsWorld);
    boxBody->setPosition(Vec3f(Position));
    boxBody->setBoxMass(1.0,Dimensions.x(), Dimensions.y(), Dimensions.z());
    boxBody->setLinearDamping(0.0001);
    boxBody->setAngularDamping(0.0001);
    PhysicsBoxGeomUnrecPtr boxGeom = PhysicsBoxGeom::create();
    boxGeom->setBody(boxBody);
    boxGeom->setSpace(physicsSpace);
    boxGeom->setLengths(Dimensions);

    //add attachments
    boxNode->addAttachment(boxGeom);
    boxTransNode->addAttachment(boxBody);
    boxTransNode->addChild(boxNode);

    //add to SceneGraph
    spaceGroupNode->addChild(boxTransNode);

    return boxBody;
}
//////////////////////////////////////////////////////////////////////////
//! build a Hinge joint with attached Meshes
//////////////////////////////////////////////////////////////////////////
void buildHingeJointMesh(Node* const spaceGroupNode,
                         PhysicsWorld* const physicsWorld,
                         PhysicsHashSpace* const physicsSpace)
{
    Vec3f Box1Size(1.0,1.0,0.1),
    Box2Size(1.0,1.0,1.0);
    Pnt3f Box1Position((Real32)(rand()%10)-5.0, (Real32)(rand()%10)-5.0, 10.0);
    Pnt3f Box2Position(Box1Position + (Vec3f(Box1Size.x()+.05,0.0,0.0)));

    PhysicsBodyUnrecPtr Box1Body = buildBox(Box1Position,
                                            Box1Size,
                                            Color3f(0.0f,1.0f,0.0f),
                                            spaceGroupNode,
                                            physicsWorld,
                                            physicsSpace);

    PhysicsBodyUnrecPtr Box2Body = buildBox(Box2Position,
                                            Box2Size,
                                            Color3f(0.0f,0.5f,0.0f),
                                            spaceGroupNode,
                                            physicsWorld,
                                            physicsSpace );

    //Create Hinge Joint
    PhysicsHingeJointUnrecPtr TutorialHingeJoint = PhysicsHingeJoint::create(Box1Body->getWorld());
    TutorialHingeJoint->setFirstBody(Box1Body);
    TutorialHingeJoint->setSecondBody(Box2Body);
    TutorialHingeJoint->setAxis(Vec3f(0.0,1.0,0.0));
    TutorialHingeJoint->setAnchor(Vec3f(Box1Position) + (Vec3f(Box1Size.x()/2,0.0,0.0)));
    TutorialHingeJoint->setLoStop(-0.3);
    TutorialHingeJoint->setHiStop(0.3);

    commitChanges();
}

void buildMotorJointMesh(Node* const spaceGroupNode,
                         PhysicsWorld* const physicsWorld,
                         PhysicsHashSpace* const physicsSpace)
{
    Vec3f Box1Size(1.0,1.5,0.1),
          Box2Size(1.0,1.0,1.0);
    Pnt3f Box1Position((Real32)(rand()%10)-5.0, (Real32)(rand()%10)-5.0, 10.0);
    Pnt3f Box2Position(Box1Position + (Vec3f(Box1Size.x()+0.01,0.0,0.0)));

    PhysicsBodyUnrecPtr Box1Body = buildBox(Box1Position,
                                            Box1Size,
                                            Color3f(0.0f,1.0f,0.0f),
                                            spaceGroupNode,
                                            physicsWorld,
                                            physicsSpace);

    PhysicsBodyUnrecPtr Box2Body = buildBox(Box2Position,
                                            Box2Size,
                                            Color3f(0.0f,0.5f,0.0f),
                                            spaceGroupNode,
                                            physicsWorld,
                                            physicsSpace );

    //Create AMotor Joint
    PhysicsAMotorJointUnrecPtr TutorialAMotorJoint = PhysicsAMotorJoint::create(Box1Body->getWorld());
    TutorialAMotorJoint->setFirstBody(Box1Body);
    TutorialAMotorJoint->setSecondBody(NULL);
    TutorialAMotorJoint->setMode(dAMotorUser);
    TutorialAMotorJoint->setNumAxes(1);
    TutorialAMotorJoint->setAxis1Properties(Vec3f(1.0,0.0,0.0),1);

    TutorialAMotorJoint->setFMax(13.0);
    TutorialAMotorJoint->setVel(6.0);

    PhysicsHingeJointUnrecPtr TutorialHingeJoint = PhysicsHingeJoint::create(Box1Body->getWorld());
    TutorialHingeJoint->setFirstBody(Box1Body);
    TutorialHingeJoint->setSecondBody(Box2Body);
    TutorialHingeJoint->setAxis(Vec3f(1.0,0.0,0.0));
    TutorialHingeJoint->setAnchor(Vec3f(Box1Position) + (Vec3f(Box1Size.x()/2,0.0,0.0)));
    commitChanges();

}

void buildUniversalJointMesh(Node* const spaceGroupNode,
                             PhysicsWorld* const physicsWorld,
                             PhysicsHashSpace* const physicsSpace)
{
    /*PhysicsUniversalJointUnrecPtr TutorialUniversalJoint = PhysicsUniversalJoint::create(Box1Body->getWorld());
      TutorialUniversalJoint->setFirstBody(Box1Body);
      TutorialUniversalJoint->setSecondBody(Box2Body);
      TutorialUniversalJoint->setAnchor(Box1Position + (Vec3f(Box1Size.x()/2+0.005,0.0,0.0)));
      TutorialUniversalJoint->setAxis1(Vec3f(0.0,0.0,1.0));
      TutorialUniversalJoint->setAxis2(Vec3f(0.0,1.0,0.0));
      TutorialUniversalJoint->setLoStop(-0.3);
      TutorialUniversalJoint->setHiStop(0.3);
      TutorialUniversalJoint->setLoStop2(-0.3);
      TutorialUniversalJoint->setHiStop2(0.3);*/
    commitChanges();
}

void buildBallJointMesh(Node* const spaceGroupNode,
                        PhysicsWorld* const physicsWorld,
                        PhysicsHashSpace* const physicsSpace)
{
    Vec3f Box1Size(1.0,0.1,0.1),
    Box2Size(1.0,1.0,1.0);
    Pnt3f Box1Position((Real32)(rand()%10)-5.0, (Real32)(rand()%10)-5.0, 10.0);
    Pnt3f Box2Position(Box1Position + (Vec3f(Box1Size.x()+0.1,0.0,0.0)));

    PhysicsBodyUnrecPtr Box1Body = buildBox(Box1Position,
                                            Box1Size,
                                            Color3f(0.0f,1.0f,0.0f),
                                            spaceGroupNode,
                                            physicsWorld,
                                            physicsSpace);

    PhysicsBodyUnrecPtr Box2Body = buildBox(Box2Position,
                                            Box2Size,
                                            Color3f(0.0f,0.5f,0.0f),
                                            spaceGroupNode,
                                            physicsWorld,
                                            physicsSpace );

    //Create Ball Joint
    PhysicsBallJointUnrecPtr TutorialBallJoint = PhysicsBallJoint::create(Box1Body->getWorld());
    TutorialBallJoint->setFirstBody(Box1Body);
    TutorialBallJoint->setSecondBody(Box2Body);
    TutorialBallJoint->setAnchor(Vec3f(Box1Position) + (Vec3f(Box1Size.x()/2+0.05,0.0,0.0)));

    commitChanges();
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

