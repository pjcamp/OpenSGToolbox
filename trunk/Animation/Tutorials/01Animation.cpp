// 
// OpenSGToolbox Tutorial: 01Animation
//
// Demonstrates a simple animation using transformation keyframes. 
//


// General OpenSG configuration, needed everywhere
#include <OpenSG/OSGConfig.h>

// Methods to create simple geometry: boxes, spheres, tori etc.
#include <OpenSG/OSGSimpleGeometry.h>

// A little helper to simplify scene management and interaction
#include <OpenSG/OSGSimpleSceneManager.h>

#include <OpenSG/OSGSimpleMaterial.h>

#include <OpenSG/OSGComponentTransform.h>
#include <OpenSG/OSGTransform.h>
#include <OpenSG/OSGTypeFactory.h>
#include <OpenSG/OSGFieldFactory.h>

#include <OpenSG/OSGFieldContainerFactory.h>
#include <OpenSG/OSGSimpleAttachments.h>

#include <OpenSG/Toolbox/OSGFieldContainerUtils.h>

// Input
#include <OpenSG/Input/OSGKeyListener.h>
#include <OpenSG/Input/OSGWindowUtils.h>

//Animation
#include <OpenSG/Animation/OSGKeyframeSequences.h>
#include <OpenSG/Animation/OSGKeyframeAnimator.h>
#include <OpenSG/Animation/OSGFieldAnimation.h>

// Activate the OpenSG namespace
// This is not strictly necessary, you can also prefix all OpenSG symbols
// with OSG::, but that would be a bit tedious for this example
OSG_USING_NAMESPACE


// forward declaration so we can have the interesting stuff upfront
void setupAnimation(void);
void display(void);
void reshape(Vec2f Size);

class TutorialAnimationListener : public AnimationListener
{
public:
   virtual void animationStarted(const AnimationEventPtr e)
   {
       std::cout << "Animation Started"  << std::endl;
   }

   virtual void animationStopped(const AnimationEventPtr e)
   {
       std::cout << "Animation Stopped"  << std::endl;
   }

   virtual void animationPaused(const AnimationEventPtr e)
   {
       std::cout << "Animation Paused"  << std::endl;
   }

   virtual void animationUnpaused(const AnimationEventPtr e)
   {
       std::cout << "Animation Unpaused"  << std::endl;
   }

   virtual void animationEnded(const AnimationEventPtr e)
   {
       std::cout << "Animation Ended"  << std::endl;
   }

   virtual void animationCycled(const AnimationEventPtr e)
   {
       std::cout << "Animation Cycled.  Cycle Count: " << AnimationPtr::dcast(e->getSource())->getCycles() << std::endl;
   }

};

// The SimpleSceneManager to manage simple applications
SimpleSceneManager *mgr;
WindowEventProducerPtr TutorialWindowEventProducer;

Time TimeLastIdle;
FieldAnimationPtr TheAnimation;
TutorialAnimationListener TheAnimationListener;
MaterialPtr TheTorusMaterial;


KeyframeAnimatorPtr TheAnimator;
KeyframeTransformationsSequencePtr TransformationKeyframes;
KeyframeColorsSequencePtr ColorKeyframes;
KeyframeVectorsSequencePtr VectorKeyframes;
KeyframeRotationsSequencePtr RotationKeyframes;

// Create a class to allow for the use of the keyboard shortucts 
class TutorialKeyListener : public KeyListener
{
public:

   virtual void keyPressed(const KeyEventPtr e)
   {
       if(e->getKey() == KeyEvent::KEY_Q && e->getModifiers() & KeyEvent::KEY_MODIFIER_CONTROL)
       {
           TutorialWindowEventProducer->closeWindow();
       }

       switch(e->getKey())
       {
       case KeyEvent::KEY_SPACE:
           TheAnimation->pause(!TheAnimation->isPaused());
           break;
       case KeyEvent::KEY_ENTER:
           TheAnimation->attachUpdateProducer(TutorialWindowEventProducer->editEventProducer());
           TheAnimation->start();
           break;
       case KeyEvent::KEY_0:
            beginEditCP(TheAnimation, FieldAnimation::InterpolationTypeFieldMask);
                FieldAnimationPtr::dcast(TheAnimation)->setInterpolationType(STEP_INTERPOLATION);
            endEditCP(TheAnimation, FieldAnimation::InterpolationTypeFieldMask);
           break;
       case KeyEvent::KEY_1:
            beginEditCP(TheAnimation, FieldAnimation::InterpolationTypeFieldMask);
                FieldAnimationPtr::dcast(TheAnimation)->setInterpolationType(LINEAR_INTERPOLATION);
            endEditCP(TheAnimation, FieldAnimation::InterpolationTypeFieldMask);
           break;
       case KeyEvent::KEY_2:
            beginEditCP(TheAnimation, FieldAnimation::InterpolationTypeFieldMask);
                FieldAnimationPtr::dcast(TheAnimation)->setInterpolationType(CUBIC_INTERPOLATION);
            endEditCP(TheAnimation, FieldAnimation::InterpolationTypeFieldMask);
           break;
		//case '1':
			//beginEditCP(TheAnimator, KeyframeAnimator::KeyframeSequenceFieldMask);
				//TheAnimator->setKeyframeSequence(ColorKeyframes);
			//endEditCP(TheAnimator, KeyframeAnimator::KeyframeSequenceFieldMask);
			
			//TheAnimation->setAnimatedField(TheTorusMaterial, std::string("diffuse"));
			
			//break;
		//case '2':
			//beginEditCP(TheAnimator, KeyframeAnimator::KeyframeSequenceFieldMask);
				//TheAnimator->setKeyframeSequence(TransformationKeyframes);
			//endEditCP(TheAnimator, KeyframeAnimator::KeyframeSequenceFieldMask);

			//TheAnimation->setAnimatedField(getFieldContainer("Transform",std::string("TorusNodeTransformationCore")), std::string("matrix"));
            //break;
       }
   }

   virtual void keyReleased(const KeyEventPtr e)
   {
   }

   virtual void keyTyped(const KeyEventPtr e)
   {
   }
};

class TutorialMouseListener : public MouseListener
{
  public:
    virtual void mouseClicked(const MouseEventPtr e)
    {
    }
    virtual void mouseEntered(const MouseEventPtr e)
    {
    }
    virtual void mouseExited(const MouseEventPtr e)
    {
    }
    virtual void mousePressed(const MouseEventPtr e)
    {
            mgr->mouseButtonPress(e->getButton(), e->getLocation().x(), e->getLocation().y());
    }
    virtual void mouseReleased(const MouseEventPtr e)
    {
           mgr->mouseButtonRelease(e->getButton(), e->getLocation().x(), e->getLocation().y());
    }
};

class TutorialMouseMotionListener : public MouseMotionListener
{
  public:
    virtual void mouseMoved(const MouseEventPtr e)
    {
            mgr->mouseMove(e->getLocation().x(), e->getLocation().y());
    }

    virtual void mouseDragged(const MouseEventPtr e)
    {
            mgr->mouseMove(e->getLocation().x(), e->getLocation().y());
    }
};

class TutorialUpdateListener : public UpdateListener
{
  public:
    virtual void update(const UpdateEventPtr e)
    {
    }
};

// Initialize GLUT & OpenSG and set up the scene
int main(int argc, char **argv)
{
    // OSG init
    osgInit(argc,argv);

    // Set up Window
    TutorialWindowEventProducer = createDefaultWindowEventProducer();
    WindowPtr MainWindow = TutorialWindowEventProducer->initWindow();

    TutorialWindowEventProducer->setDisplayCallback(display);
    TutorialWindowEventProducer->setReshapeCallback(reshape);

    //Add Window Listener
    TutorialKeyListener TheKeyListener;
    TutorialWindowEventProducer->addKeyListener(&TheKeyListener);
    TutorialMouseListener TheTutorialMouseListener;
    TutorialMouseMotionListener TheTutorialMouseMotionListener;
    TutorialWindowEventProducer->addMouseListener(&TheTutorialMouseListener);
    TutorialWindowEventProducer->addMouseMotionListener(&TheTutorialMouseMotionListener);
	TutorialUpdateListener TheTutorialUpdateListener;
    TutorialWindowEventProducer->addUpdateListener(&TheTutorialUpdateListener);

    // Create the SimpleSceneManager helper
    mgr = new SimpleSceneManager;

	
    // Tell the Manager what to manage
    mgr->setWindow(TutorialWindowEventProducer->getWindow());

    //Torus Material
    TheTorusMaterial = SimpleMaterial::create();
    beginEditCP(TheTorusMaterial);
        SimpleMaterialPtr::dcast(TheTorusMaterial)->setAmbient(Color3f(0.3,0.3,0.3));
        SimpleMaterialPtr::dcast(TheTorusMaterial)->setDiffuse(Color3f(0.7,0.7,0.7));
        SimpleMaterialPtr::dcast(TheTorusMaterial)->setSpecular(Color3f(1.0,1.0,1.0));
    endEditCP(TheTorusMaterial);

    //Torus Geometry
    GeometryPtr TorusGeometry = makeTorusGeo(.5, 2, 32, 32);
    beginEditCP(TorusGeometry);
        TorusGeometry->setMaterial(TheTorusMaterial);
    endEditCP  (TorusGeometry);
    
    NodePtr TorusGeometryNode = Node::create();
    beginEditCP(TorusGeometryNode, Node::CoreFieldMask);
        TorusGeometryNode->setCore(TorusGeometry);
    endEditCP  (TorusGeometryNode, Node::CoreFieldMask);

    //Make Torus Node
    NodePtr TorusNode = Node::create();
    TransformPtr TorusNodeTrans;
    TorusNodeTrans = Transform::create();
    setName(TorusNodeTrans, std::string("TorusNodeTransformationCore"));

    beginEditCP(TorusNode, Node::CoreFieldMask | Node::ChildrenFieldMask);
        TorusNode->setCore(TorusNodeTrans);
        TorusNode->addChild(TorusGeometryNode);
    endEditCP  (TorusNode, Node::CoreFieldMask | Node::ChildrenFieldMask);

    //Make Main Scene Node
    NodePtr scene = Node::create();
    ComponentTransformPtr Trans;
    Trans = ComponentTransform::create();
    setName(Trans, std::string("MainTransformationCore"));
    beginEditCP(scene, Node::CoreFieldMask | Node::ChildrenFieldMask);
    {
        scene->setCore(Trans);
 
        // add the torus as a child
        scene->addChild(TorusNode);
    }
    endEditCP  (scene, Node::CoreFieldMask | Node::ChildrenFieldMask);

    setupAnimation();

    // tell the manager what to manage
    mgr->setRoot  (scene);

    // show the whole scene
    mgr->showAll();

    
    Vec2f WinSize(TutorialWindowEventProducer->getDesktopSize() * 0.85f);
    Pnt2f WinPos((TutorialWindowEventProducer->getDesktopSize() - WinSize) *0.5);
    TutorialWindowEventProducer->openWindow(WinPos,
            WinSize,
            "OpenSG 01Animation Window");

    //Enter main Loop
    TutorialWindowEventProducer->mainLoop();

    osgExit();

    return 0;
}

// Redraw the window
void display(void)
{
    mgr->redraw();
}

// React to size changes
void reshape(Vec2f Size)
{
    mgr->resize(Size.x(), Size.y());
}

void setupAnimation(void)
{
    //Color Keyframe Sequence
    ColorKeyframes = KeyframeColorsSequence3f::create();
    ColorKeyframes->addKeyframe(Color4f(1.0f,0.0f,0.0f,1.0f),0.0f);
    ColorKeyframes->addKeyframe(Color4f(0.0f,1.0f,0.0f,1.0f),2.0f);
    ColorKeyframes->addKeyframe(Color4f(0.0f,0.0f,1.0f,1.0f),4.0f);
    ColorKeyframes->addKeyframe(Color4f(1.0f,0.0f,0.0f,1.0f),6.0f);

	//Vector Keyframe Sequence
    VectorKeyframes = KeyframeVectorsSequence3f::create();
    VectorKeyframes->addKeyframe(Vec3f(0.0f,0.0f,0.0f),0.0f);
    VectorKeyframes->addKeyframe(Vec3f(0.0f,1.0f,0.0f),1.0f);
    VectorKeyframes->addKeyframe(Vec3f(1.0f,1.0f,0.0f),2.0f);
    VectorKeyframes->addKeyframe(Vec3f(1.0f,0.0f,0.0f),3.0f);
    VectorKeyframes->addKeyframe(Vec3f(0.0f,0.0f,0.0f),4.0f);
    
	//Rotation Keyframe Sequence
    RotationKeyframes = KeyframeRotationsSequenceQuat::create();
    RotationKeyframes->addKeyframe(Quaternion(Vec3f(0.0f,1.0f,0.0f), 3.14159f*0.0),0.0f);
    RotationKeyframes->addKeyframe(Quaternion(Vec3f(0.0f,1.0f,0.0f), 3.14159f*0.5),1.0f);
    RotationKeyframes->addKeyframe(Quaternion(Vec3f(0.0f,1.0f,0.0f), 3.14159f*1.0),2.0f);
    RotationKeyframes->addKeyframe(Quaternion(Vec3f(0.0f,1.0f,0.0f), 3.14159f*1.5),3.0f);
    RotationKeyframes->addKeyframe(Quaternion(Vec3f(0.0f,1.0f,0.0f), 3.14159f*0.0),4.0f);

	//Transformation Keyframe Sequence
    TransformationKeyframes = KeyframeTransformationsSequence44f::create();
	Matrix TempMat;
	TempMat.setTransform(Vec3f(0.0f,0.0f,0.0f), Quaternion(Vec3f(0.0f,1.0f,0.0f), 3.14159f*0.0));
    TransformationKeyframes->addKeyframe(TempMat,0.0f);
	TempMat.setTransform(Vec3f(0.0f,1.0f,0.0f), Quaternion(Vec2f(0.0f,1.0f,0.0f), 3.14159f*0.5));
    TransformationKeyframes->addKeyframe(TempMat,1.0f);
	TempMat.setTransform(Vec3f(1.0f,1.0f,0.0f), Quaternion(Vec3f(0.0f,1.0f,0.0f), 3.14159f*1.0));
    TransformationKeyframes->addKeyframe(TempMat,2.0f);
	TempMat.setTransform(Vec3f(1.0f,0.0f,0.0f), Quaternion(Vec3f(0.0f,1.0f,0.0f), 3.14159f*1.5));
    TransformationKeyframes->addKeyframe(TempMat,3.0f);
	TempMat.setTransform(Vec3f(0.0f,0.0f,0.0f), Quaternion(Vec3f(0.0f,1.0f,0.0f), 3.14159f*0.0));
    TransformationKeyframes->addKeyframe(TempMat,4.0f);
    
    //Animator
    TheAnimator = KeyframeAnimator::create();
    beginEditCP(TheAnimator, KeyframeAnimator::KeyframeSequenceFieldMask);
        TheAnimator->setKeyframeSequence(TransformationKeyframes);
    endEditCP(TheAnimator, KeyframeAnimator::KeyframeSequenceFieldMask);
    
    //Animation
    TheAnimation = FieldAnimation::create();
    beginEditCP(TheAnimation);
        TheAnimation->setAnimator(TheAnimator);
        TheAnimation->setInterpolationType(LINEAR_INTERPOLATION);
        TheAnimation->setCycling(2);
    endEditCP(TheAnimation);
	TheAnimation->setAnimatedField(getFieldContainer("Transform",std::string("TorusNodeTransformationCore")), std::string("matrix"));

    //Animation Listener
    TheAnimation->addAnimationListener(&TheAnimationListener);

    TheAnimation->attachUpdateProducer(TutorialWindowEventProducer->editEventProducer());
    TheAnimation->start();
}

