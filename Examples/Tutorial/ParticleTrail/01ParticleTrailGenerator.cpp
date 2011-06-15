// General OpenSG configuration, needed everywhere
#include "OSGConfig.h"

// A little helper to simplify scene management and interaction
#include "OSGSimpleSceneManager.h"
#include "OSGNode.h"
#include "OSGGroup.h"
#include "OSGViewport.h"
#include "OSGWindowUtils.h"

//Text Foreground
#include "OSGSimpleTextForeground.h"

//Animation
#include "OSGKeyframeSequences.h"
#include "OSGKeyframeAnimator.h"
#include "OSGFieldAnimation.h"

// Particle Systems and materials, trail generator
#include "OSGSimpleParticleTrailGenerator.h"
#include "OSGBlendChunk.h"
#include "OSGPointChunk.h"
#include "OSGChunkMaterial.h"
#include "OSGMaterialChunk.h"
#include "OSGParticleSystem.h"
#include "OSGParticleSystemCore.h"
#include "OSGPointParticleSystemDrawer.h"
#include "OSGRateParticleGenerator.h"
#include "OSGBurstParticleGenerator.h"
#include "OSGGaussianNormalDistribution1D.h"
#include "OSGLineDistribution3D.h"
#include "OSGSphereDistribution3D.h"
#include "OSGSineWaveParticleAffector.h"

// Activate the OpenSG namespace
OSG_USING_NAMESPACE

// Forward declaration so we can have the interesting stuff upfront
void display(SimpleSceneManager *mgr);
void reshape(Vec2f Size, SimpleSceneManager *mgr);

// Helper fucntions for particle system distributions
Distribution3DRefPtr createPositionDistribution(void);
Distribution3DRefPtr createVelocityDistribution(void);
Distribution3DRefPtr createColorDistribution(void);
Distribution3DRefPtr createNormalDistribution(void);
Distribution1DRefPtr createLifespanDistribution(void);
Distribution3DRefPtr createSizeDistribution(void);

void keyPressed(KeyEventDetails* const details, SimpleSceneManager *mgr, ParticleSystem* const ExampleParticleSystem, SimpleParticleTrailGenerator* const ExampleTrailGenerator)
{
    if(details->getKey() == KeyEventDetails::KEY_Q &&
       details->getModifiers() & KeyEventDetails::KEY_MODIFIER_COMMAND)
    {
        dynamic_cast<WindowEventProducer*>(details->getSource())->closeWindow();
    }
    else
    {
        switch(details->getKey())
        {
            case KeyEventDetails::KEY_B:
                {
                    {
                        BurstParticleGeneratorRecPtr ExampleBurstGen = BurstParticleGenerator::create();
                        ExampleBurstGen->setPositionDistribution(createPositionDistribution());
                        ExampleBurstGen->setBurstAmount(20);
                        ExampleBurstGen->setVelocityDistribution(createVelocityDistribution());
                        ExampleBurstGen->setNormalDistribution(createNormalDistribution());
                        ExampleBurstGen->setLifespanDistribution(createLifespanDistribution());
                        ExampleBurstGen->setSizeDistribution(createSizeDistribution());
                        // attach the burst generator
                        ExampleParticleSystem->pushToGenerators(ExampleBurstGen);
                    }
                }
                break;
            case KeyEventDetails::KEY_P:
                {    // increase trail resolution
                    ExampleTrailGenerator->setTrailResolution(ExampleTrailGenerator->getTrailResolution() * 0.70 + 0.0001);
                    std::cout << "Trail Resolution:  " << ExampleTrailGenerator->getTrailResolution() << std::endl;
                    break;
                }
            case KeyEventDetails::KEY_L:
                {    // decrease trail resolution
                    ExampleTrailGenerator->setTrailResolution(ExampleTrailGenerator->getTrailResolution() * 1.25);
                    std::cout << "Trail Resolution:  " << ExampleTrailGenerator->getTrailResolution() << std::endl;
                    break;
                }
            case KeyEventDetails::KEY_O:
                {    // increase trail length
                    ExampleTrailGenerator->setTrailLength(ExampleTrailGenerator->getTrailLength() * 1.25 + 0.1);
                    std::cout << "Trail Length:  " << ExampleTrailGenerator->getTrailLength() << std::endl;
                    break;
                }
            case KeyEventDetails::KEY_K:
                {    // decrease trail length
                    ExampleTrailGenerator->setTrailLength(ExampleTrailGenerator->getTrailLength() * 0.7);
                    std::cout << "Trail Length:  " << ExampleTrailGenerator->getTrailLength() << std::endl;
                    break;
                }
            case KeyEventDetails::KEY_I:
                {    // toggle lines/points as trail draw method
                    ExampleTrailGenerator->setDrawMethod((ExampleTrailGenerator->getDrawMethod() == SimpleParticleTrailGenerator::LINES)?
                                                         (SimpleParticleTrailGenerator::POINTS):(SimpleParticleTrailGenerator::LINES));
                    break;
                }
            case KeyEventDetails::KEY_J:
                {    // toggle trail length method
                    ExampleTrailGenerator->setTrailLengthMethod((ExampleTrailGenerator->getTrailLengthMethod() == ParticleTrailGenerator::NUM_POINTS)?
                                                                (ParticleTrailGenerator::TIME):(ParticleTrailGenerator::NUM_POINTS));
                    std::cout << "Trail Length: " << (ExampleTrailGenerator->getTrailLengthMethod() == ParticleTrailGenerator::NUM_POINTS ? "Num Pts":"Time") << std::endl;
                    break;
                }
            case KeyEventDetails::KEY_Y:
                {    // toggle trail spacing method
                    ExampleTrailGenerator->setTrailResolutionMethod((ExampleTrailGenerator->getTrailResolutionMethod() == ParticleTrailGenerator::TIME_SPACING)?
                                                                    (ParticleTrailGenerator::DISTANCE_SPACING):(ParticleTrailGenerator::TIME_SPACING));
                    std::cout << "Trail resolution: " <<(ExampleTrailGenerator->getTrailResolutionMethod() == ParticleTrailGenerator::TIME_SPACING ? "Time Spacing" : "Distance Spacing") << std::endl;
                    break;
                }
            case KeyEventDetails::KEY_V:
                {
                    mgr->getRenderAction()->setVolumeDrawing(!mgr->getRenderAction()->getVolumeDrawing());
                }
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
    DocForeground->addLine("of \\{\\color=AAAA00FF SimpleParticleTrailGenerator}");
    
    DocForeground->addLine("");
    DocForeground->addLine("\\{\\color=AAAAAAFF Key Controls}:");
    DocForeground->addLine("       \\{\\color=AAAAFFFF b}: Create a burst of particles");
    DocForeground->addLine("       \\{\\color=AAAAFFFF p}: Increase trail resolution");
    DocForeground->addLine("       \\{\\color=AAAAFFFF l}: Decrease trail resolution");
    DocForeground->addLine("       \\{\\color=AAAAFFFF o}: Increase trail length");
    DocForeground->addLine("       \\{\\color=AAAAFFFF k}: Decrease trail length");
    DocForeground->addLine("       \\{\\color=AAAAFFFF i}: Toggle drawing as points/lines");
    DocForeground->addLine("       \\{\\color=AAAAFFFF j}: Toggle trail length method between:");
    DocForeground->addLine("          Time/Points");
    DocForeground->addLine("       \\{\\color=AAAAFFFF y}: Toggle trail resolution method between:");
    DocForeground->addLine("          Time/Distance");
    DocForeground->addLine("       \\{\\color=AAAAFFFF v}: Hide/show bounding boxes");
    DocForeground->addLine("   \\{\\color=AAAAFFFF Cmd+q}: Close the application");
    DocForeground->addLine("       \\{\\color=AAAAFFFF ?}: Show/hide this documentation");

    DocForeground->addLine("");
    DocForeground->addLine("\\{\\color=AAAAAAFF Mouse Controls}:");
    DocForeground->addLine("   \\{\\color=AAAAFFFF Scroll wheel}: Zoom in/out");
    DocForeground->addLine("      \\{\\color=AAAAFFFF Left+drag}: Rotate");
    DocForeground->addLine("     \\{\\color=AAAAFFFF Right+drag}: Translate");

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

        //Attach to events
        TutorialWindow->connectMousePressed(boost::bind(mousePressed, _1, &sceneManager));
        TutorialWindow->connectMouseReleased(boost::bind(mouseReleased, _1, &sceneManager));
        TutorialWindow->connectMouseDragged(boost::bind(mouseDragged, _1, &sceneManager));
        TutorialWindow->connectMouseWheelMoved(boost::bind(mouseWheelMoved, _1, &sceneManager));

        //Particle System Material
        PointChunkRecPtr PSPointChunk = PointChunk::create();
        PSPointChunk->setSize(9.0f);
        PSPointChunk->setSmooth(true);

        BlendChunkRefPtr PSBlendChunk = BlendChunk::create();
        PSBlendChunk->setSrcFactor(GL_SRC_ALPHA);
        PSBlendChunk->setDestFactor(GL_ONE_MINUS_SRC_ALPHA);

        MaterialChunkRefPtr PSMaterialChunk = MaterialChunk::create();
        PSMaterialChunk->setAmbient(Color4f(0.3f,0.0f,0.0f,1.0f));
        PSMaterialChunk->setDiffuse(Color4f(0.7f,0.0f,0.0f,1.0f));
        PSMaterialChunk->setSpecular(Color4f(0.9f,0.0f,0.0f,1.0f));
        PSMaterialChunk->setColorMaterial(GL_AMBIENT_AND_DIFFUSE);

        ChunkMaterialRefPtr PSMaterial = ChunkMaterial::create();
        PSMaterial->addChunk(PSPointChunk);
        PSMaterial->addChunk(PSMaterialChunk);
        PSMaterial->addChunk(PSBlendChunk);

        PointChunkRecPtr TrailPointChunk = PointChunk::create();
        TrailPointChunk->setSize(3.0f);
        TrailPointChunk->setSmooth(true);

        MaterialChunkRefPtr TrailMaterialChunk = MaterialChunk::create();
        TrailMaterialChunk->setAmbient(Color4f(0.3f,0.3f,0.3f,1.0f));
        TrailMaterialChunk->setDiffuse(Color4f(0.7f,0.7f,0.7f,1.0f));
        TrailMaterialChunk->setSpecular(Color4f(0.9f,0.9f,0.9f,1.0f));
        TrailMaterialChunk->setColorMaterial(GL_AMBIENT_AND_DIFFUSE);

        ChunkMaterialRecPtr TrailMaterial = ChunkMaterial::create();
        TrailMaterial->addChunk(TrailPointChunk);
        TrailMaterial->addChunk(TrailMaterialChunk);
        TrailMaterial->addChunk(PSBlendChunk);

        // Creating a particle generator
        RateParticleGeneratorRefPtr ExampleGenerator = RateParticleGenerator::create();
        //Attach the function objects to the Generator
        ExampleGenerator->setPositionDistribution(createPositionDistribution());
        ExampleGenerator->setGenerationRate(2.0);
        ExampleGenerator->setVelocityDistribution(createVelocityDistribution());
        ExampleGenerator->setColorDistribution(createColorDistribution());
        ExampleGenerator->setLifespanDistribution(createLifespanDistribution());
        ExampleGenerator->setSizeDistribution(createSizeDistribution());

        // Particle System Sine Wave Affector
        SineWaveParticleAffectorRecPtr ExampleSWA = SineWaveParticleAffector::create();
        ExampleSWA->setAmplitude(2.75f);
        ExampleSWA->setUpDirSource(SineWaveParticleAffector::CROSS_PRODUCT);
        ExampleSWA->setFrequency(20.00f);

        //Creating Particle System
        ParticleSystemRecPtr ExampleParticleSystem = ParticleSystem::create();
        // add a couple temp particles so the camera is zoomed out 
        ExampleParticleSystem->addParticle(Pnt3f(0,0,-100),Vec3f(0,1,0),Color4f(1,1,1,1),Vec3f(1,1,1),0.1,Vec3f(0,0,0),Vec3f(0,0,0));
        ExampleParticleSystem->addParticle(Pnt3f(0,0,100),Vec3f(0,1,0),Color4f(1,1,1,1),Vec3f(1,1,1),0.1,Vec3f(0,0,0),Vec3f(0,0,0));
        ExampleParticleSystem->setMaxParticles(200);
        ExampleParticleSystem->attachUpdateProducer(TutorialWindow); 

        //Creating Particle System Drawer
        PointParticleSystemDrawerRefPtr ExampleParticleSystemDrawer = PointParticleSystemDrawer::create();

        // Attaching affector and generator to the particle system
        ExampleParticleSystem->pushToGenerators(ExampleGenerator);
        ExampleParticleSystem->pushToAffectors(ExampleSWA);

        //Particle System Core, setting its system, drawer, and material
        ParticleSystemCoreRefPtr ParticleNodeCore = ParticleSystemCore::create();
        ParticleNodeCore->setSystem(ExampleParticleSystem);
        ParticleNodeCore->setDrawer(ExampleParticleSystemDrawer);
        ParticleNodeCore->setMaterial(PSMaterial);

        // Create Trail Generator(s)
        // simple trail generator
        SimpleParticleTrailGeneratorRecPtr ExampleTrailGenerator = SimpleParticleTrailGenerator::create();
        ExampleTrailGenerator->setTrailResolution(1.0f);
        ExampleTrailGenerator->setDrawMethod(SimpleParticleTrailGenerator::POINTS);
        ExampleTrailGenerator->setTrailLength(3.12);
        ExampleTrailGenerator->setTrailLengthMethod(ParticleTrailGenerator::TIME);
        ExampleTrailGenerator->setTrailResolutionMethod(ParticleTrailGenerator::DISTANCE_SPACING);
        ExampleTrailGenerator->setTrailMaterial(TrailMaterial);

        // attach listener for trail generator to the particle system
        ExampleTrailGenerator->setSystemToTrail(ExampleParticleSystem);

        // Set up node with the particle system at its core
        NodeRefPtr ParticleNode = Node::create();
        ParticleNode->setCore(ParticleNodeCore);
        // add the trail generator to the scene
        ParticleNode->addChild(ExampleTrailGenerator);

        // Make Main Scene Node
        NodeRefPtr scene = Node::create();
        scene->setCore(Group::create());
        scene->addChild(ParticleNode);

        sceneManager.setRoot(scene);

        //Create the Documentation
        SimpleScreenDoc TheSimpleScreenDoc(&sceneManager, TutorialWindow);

        // Show the whole Scene
        sceneManager.showAll();
        sceneManager.getCamera()->setFar(10000.0f);
        sceneManager.getCamera()->setNear(0.1f);
        
        TutorialWindow->connectKeyPressed(boost::bind(keyPressed, _1, &sceneManager, ExampleParticleSystem.get(), ExampleTrailGenerator.get()));

        //Open Window
        Vec2f WinSize(TutorialWindow->getDesktopSize() * 0.85f);
        Pnt2f WinPos((TutorialWindow->getDesktopSize() - WinSize) *0.5);
        TutorialWindow->openWindow(WinPos,
                                   WinSize,
                                   "01ParticleTrail");

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

// helper functions to create particle system distributions
Distribution3DRefPtr createPositionDistribution(void)
{
    //Line Distribution
    LineDistribution3DRefPtr TheLineDistribution = LineDistribution3D::create();
    TheLineDistribution->setPoint1(Pnt3f(0.0,0.0,0.0));
    TheLineDistribution->setPoint2(Pnt3f(0.0,0.0,0.0));

    return TheLineDistribution;
}

Distribution3DRefPtr createVelocityDistribution(void)
{
    // spherical dist.
    SphereDistribution3DRefPtr TheSphereDistribution = SphereDistribution3D::create();
    TheSphereDistribution->setCenter(Pnt3f(0.0,0.0,0.0));
    TheSphereDistribution->setInnerRadius(10.0);
    TheSphereDistribution->setOuterRadius(20.0);
    TheSphereDistribution->setMinTheta(-3.141950);
    TheSphereDistribution->setMaxTheta(3.141950);
    TheSphereDistribution->setMinZ(-1.0);
    TheSphereDistribution->setMaxZ(1.0);
    TheSphereDistribution->setSurfaceOrVolume(SphereDistribution3D::SURFACE);

    return TheSphereDistribution;
}

Distribution3DRefPtr createColorDistribution(void)
{
    // spherical dist.
    LineDistribution3DRefPtr TheLineDistribution = LineDistribution3D::create();
    TheLineDistribution->setPoint1(Pnt3f(1.0,0.0,0.0));
    TheLineDistribution->setPoint2(Pnt3f(1.0,0.0,0.0));

    return TheLineDistribution;
}

Distribution3DRefPtr createNormalDistribution(void)
{    // spherical distribution
    SphereDistribution3DRefPtr TheSphereDistribution = SphereDistribution3D::create();
    TheSphereDistribution->setCenter(Pnt3f(0.0,0.0,0.0));
    TheSphereDistribution->setInnerRadius(1.0);
    TheSphereDistribution->setOuterRadius(1.0);
    TheSphereDistribution->setMinTheta(-3.141950);
    TheSphereDistribution->setMaxTheta(3.141950);
    TheSphereDistribution->setMinZ(-1.0);
    TheSphereDistribution->setMaxZ(1.0);
    TheSphereDistribution->setSurfaceOrVolume(SphereDistribution3D::SURFACE);

    return TheSphereDistribution;
}

Distribution1DRefPtr createLifespanDistribution(void)
{    // Normal Distribution
    GaussianNormalDistribution1DRefPtr TheLifespanDistribution = GaussianNormalDistribution1D::create();
    TheLifespanDistribution->setMean(3.0f);
    TheLifespanDistribution->setStandardDeviation(1.0);

    return TheLifespanDistribution;
}

Distribution3DRefPtr createSizeDistribution(void)
{
    //Line Distribution
    LineDistribution3DRefPtr TheLineDistribution = LineDistribution3D::create();
    TheLineDistribution->setPoint1(Pnt3f(4.0,4.0,4.0));
    TheLineDistribution->setPoint2(Pnt3f(6.0,6.0,6.0));

    return TheLineDistribution;
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

