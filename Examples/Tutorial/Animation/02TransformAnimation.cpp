// 
// OpenSGToolbox Tutorial: 02TransformAnimation
//
// Demonstrates a simple animation using transformation keyframes. 
//


// General OpenSG configuration, needed everywhere
#include "OSGConfig.h"

// Methods to create simple geometry: boxes, spheres, tori etc.
#include "OSGSimpleGeometry.h"

// A little helper to simplify scene management and interaction
#include "OSGSimpleSceneManager.h"

#include "OSGSimpleMaterial.h"

#include "OSGComponentTransform.h"
#include "OSGTransform.h"
#include "OSGTypeFactory.h"

#include "OSGFieldContainerFactory.h"
#include "OSGNameAttachment.h"

#include "OSGContainerUtils.h"
#include "OSGMTRefCountPtr.h"

// Input
#include "OSGWindowUtils.h"
#include "OSGWindowEventProducer.h"

//Text Foreground
#include "OSGSimpleTextForeground.h"
#include "OSGKeyframeAnimator.h"

//Animation
#include "OSGKeyframeSequences.h"
#include "OSGTransformAnimator.h"
#include "OSGFieldAnimation.h"

// Activate the OpenSG namespace
// This is not strictly necessary, you can also prefix all OpenSG symbols
// with OSG::, but that would be a bit tedious for this example
OSG_USING_NAMESPACE


// forward declaration so we can have the interesting stuff upfront
FieldAnimationTransitPtr setupAnimation(Transform* const transCore, WindowEventProducer* const win);
void display(SimpleSceneManager *mgr);
void reshape(Vec2f Size, SimpleSceneManager *mgr);

void animationStarted(AnimationEventDetails* const details)
{
    std::cout << "Animation Started"  << std::endl;
}

void animationStopped(AnimationEventDetails* const details)
{
    std::cout << "Animation Stopped"  << std::endl;
}

void animationPaused(AnimationEventDetails* const details)
{
    std::cout << "Animation Paused"  << std::endl;
}

void animationUnpaused(AnimationEventDetails* const details)
{
    std::cout << "Animation Unpaused"  << std::endl;
}

void animationEnded(AnimationEventDetails* const details)
{
    std::cout << "Animation Ended"  << std::endl;
}

void animationCycled(AnimationEventDetails* const details)
{
    std::cout << "Animation Cycled.  Cycle Count: " << dynamic_cast<Animation*>(details->getSource())->getCycles() << std::endl;
}

void keyPressed(KeyEventDetails* const details, FieldAnimation* const anim, WindowEventProducer* const win)
{
    if(details->getKey() == KeyEventDetails::KEY_Q && details->getModifiers() & KeyEventDetails::KEY_MODIFIER_COMMAND)
    {
        win->closeWindow();
    }

    switch(details->getKey())
    {
        case KeyEventDetails::KEY_SPACE:
            anim->pause(!anim->isPaused());
            break;
        case KeyEventDetails::KEY_ENTER:
            anim->attachUpdateProducer(win);
            anim->start();
            break;
        case KeyEventDetails::KEY_1:
            anim->setInterpolationType(Animator::STEP_INTERPOLATION);
            break;
        case KeyEventDetails::KEY_2:
            anim->setInterpolationType(Animator::LINEAR_INTERPOLATION);
            break;
        case KeyEventDetails::KEY_3:
            anim->setInterpolationType(Animator::CUBIC_INTERPOLATION);
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
    DocForeground->addLine("of a \\{\\color=AAAA00FF TransformAnimator}.");
    
    DocForeground->addLine("");
    DocForeground->addLine("\\{\\color=AAAAAAFF Key Controls}:");
    DocForeground->addLine("   \\{\\color=AAAAFFFF <Space>}: Pause/unpause animation");
    DocForeground->addLine("   \\{\\color=AAAAFFFF <Enter>}: Restart animation");
    DocForeground->addLine("         \\{\\color=AAAAFFFF 1}: Step interpolation");
    DocForeground->addLine("         \\{\\color=AAAAFFFF 2}: Linear interpolation");
    DocForeground->addLine("         \\{\\color=AAAAFFFF 3}: Cubic interpolation");
    DocForeground->addLine("     \\{\\color=AAAAFFFF Cmd+q}: Close the application");
    DocForeground->addLine("         \\{\\color=AAAAFFFF ?}: Show/hide this documentation");

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

        SimpleSceneManager sceneManager;
        TutorialWindow->setDisplayCallback(boost::bind(display, &sceneManager));
        TutorialWindow->setReshapeCallback(boost::bind(reshape, _1, &sceneManager));

        //Initialize Window
        TutorialWindow->initWindow();

        // Tell the Manager what to manage
        sceneManager.setWindow(TutorialWindow);

        //Attach to events
        TutorialWindow->connectMousePressed(boost::bind(mousePressed, _1, &sceneManager));
        TutorialWindow->connectMouseReleased(boost::bind(mouseReleased, _1, &sceneManager));
        TutorialWindow->connectMouseDragged(boost::bind(mouseDragged, _1, &sceneManager));
        TutorialWindow->connectMouseWheelMoved(boost::bind(mouseWheelMoved, _1, &sceneManager));

        //Torus Material
        SimpleMaterialRecPtr TheTorusMaterial = SimpleMaterial::create();
        dynamic_pointer_cast<SimpleMaterial>(TheTorusMaterial)->setAmbient(Color3f(0.2,0.2,0.2));
        dynamic_pointer_cast<SimpleMaterial>(TheTorusMaterial)->setDiffuse(Color3f(0.7,0.7,0.7));
        dynamic_pointer_cast<SimpleMaterial>(TheTorusMaterial)->setSpecular(Color3f(0.7,0.7,0.7));
        dynamic_pointer_cast<SimpleMaterial>(TheTorusMaterial)->setShininess(100.0f);

        //Torus Geometry
        GeometryRecPtr TorusGeometry = makeTorusGeo(.5, 2, 32, 32);
        TorusGeometry->setMaterial(TheTorusMaterial);

        NodeRecPtr TorusGeometryNode = Node::create();
        TorusGeometryNode->setCore(TorusGeometry);

        //Make Torus Node
        NodeRecPtr TorusNode = Node::create();
        TransformRecPtr TorusNodeTrans = Transform::create();
        setName(TorusNodeTrans, std::string("TorusNodeTransformationCore"));

        TorusNode->setCore(TorusNodeTrans);
        TorusNode->addChild(TorusGeometryNode);

        //Make Main Scene Node
        NodeRecPtr scene = Node::create();
        ComponentTransformRecPtr Trans = ComponentTransform::create();
        setName(Trans, std::string("MainTransformationCore"));

        scene->setCore(Trans);
        scene->addChild(TorusNode);

        FieldAnimationRecPtr TheAnimation = setupAnimation(TorusNodeTrans, TutorialWindow);

        TutorialWindow->connectKeyPressed(boost::bind(keyPressed, _1, TheAnimation.get(), TutorialWindow.get()));

        TheAnimation->connectAnimationStarted(boost::bind(animationStarted, _1));
        TheAnimation->connectAnimationStopped(boost::bind(animationStopped, _1));
        TheAnimation->connectAnimationPaused(boost::bind(animationPaused, _1));
        TheAnimation->connectAnimationUnpaused(boost::bind(animationUnpaused, _1));
        TheAnimation->connectAnimationEnded(boost::bind(animationEnded, _1));
        TheAnimation->connectAnimationCycled(boost::bind(animationCycled, _1));

        commitChanges();

        // tell the manager what to manage
        sceneManager.setRoot  (scene);

        //Create the Documentation
        SimpleScreenDoc TheSimpleScreenDoc(&sceneManager, TutorialWindow);

        // show the whole scene
        sceneManager.showAll();

        Vec2f WinSize(TutorialWindow->getDesktopSize() * 0.85f);
        Pnt2f WinPos((TutorialWindow->getDesktopSize() - WinSize) *0.5);
        TutorialWindow->openWindow(WinPos,
                                   WinSize,
                                   "02TransformAnimation");

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

FieldAnimationTransitPtr setupAnimation(Transform* const transCore, WindowEventProducer* const win)
{
    //Number Keyframe Sequence
    KeyframeNumberSequenceReal32RecPtr XTransKeyframes = KeyframeNumberSequenceReal32::create();
    XTransKeyframes->addKeyframe(1.0,0.0f);
    XTransKeyframes->addKeyframe(5.0,2.0f);
    XTransKeyframes->addKeyframe(-5.0,4.0f);
    XTransKeyframes->addKeyframe(1.0,6.0f);

    KeyframeNumberSequenceReal32RecPtr YRotKeyframes = KeyframeNumberSequenceReal32::create();
    YRotKeyframes->addKeyframe(0.0,0.0f);
    YRotKeyframes->addKeyframe(45.0,2.0f);
    YRotKeyframes->addKeyframe(0.0,4.0f);

    KeyframeNumberSequenceReal32RecPtr ZScaleKeyframes = KeyframeNumberSequenceReal32::create();
    ZScaleKeyframes->addKeyframe(1.0,0.0f);
    ZScaleKeyframes->addKeyframe(2.0,2.0f);
    ZScaleKeyframes->addKeyframe(3.0,4.0f);
    ZScaleKeyframes->addKeyframe(1.0,6.0f);

    //Animator
    TransformAnimatorRecPtr TheAnimator = TransformAnimator::create();
    TheAnimator->setXTranslationSequence(XTransKeyframes);
    TheAnimator->setXRotationSequence(YRotKeyframes);
    TheAnimator->setYRotationSequence(YRotKeyframes);
    //TheAnimator->setZRotationSequence(YRotKeyframes);
    TheAnimator->setZScaleSequence(ZScaleKeyframes);

    //Animation
    FieldAnimationRecPtr TheAnimation = FieldAnimation::create();
    TheAnimation->setAnimator(TheAnimator);
    TheAnimation->setInterpolationType(Animator::LINEAR_INTERPOLATION);
    TheAnimation->setCycling(2);
    TheAnimation->setAnimatedField(transCore, std::string("matrix"));

    TheAnimation->attachUpdateProducer(win);
    TheAnimation->start();

    return FieldAnimationTransitPtr(TheAnimation);
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


