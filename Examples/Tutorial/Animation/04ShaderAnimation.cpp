// 
// OpenSGToolbox Tutorial: 04ShaderAnimation 
//
// Demonstrates a simple animation. 
//

// General OpenSG configuration, needed everywhere
#include "OSGConfig.h"

// A little helper to simplify scene management and interaction
#include "OSGSimpleSceneManager.h"
#include "OSGNode.h"
#include "OSGGroup.h"
#include "OSGViewport.h"
#include "OSGSimpleGeometry.h"
#include "OSGLineChunk.h"
#include "OSGBlendChunk.h"
#include "OSGChunkMaterial.h"
#include "OSGMaterialChunk.h"
#include "OSGSimpleSHLChunk.h"
#include "OSGSimpleSHLVariableChunk.h"
#include "OSGShaderVariableVec4f.h"

// Input
#include "OSGWindowUtils.h"

//Text Foreground
#include "OSGSimpleTextForeground.h"

#include <sstream>

//Animation
#include "OSGKeyframeSequences.h"
#include "OSGKeyframeAnimator.h"
#include "OSGFieldAnimation.h"

// Activate the OpenSG namespace
OSG_USING_NAMESPACE

// The SimpleSceneManager to manage simple applications

// Forward declaration so we can have the interesting stuff upfront
std::string createSHLVertexProg(void);
std::string createSHLFragProg(void);

AnimationTransitPtr setupAnimation(FieldContainer* const AnimatedObject,
                                   const std::string& AnimatedField);

void display(SimpleSceneManager *mgr);
void reshape(Vec2f Size, SimpleSceneManager *mgr);

void animationCycled(AnimationEventDetails* const details)
{
    std::cout << "Animation Cycled.  Cycle Count: " << dynamic_cast<Animation*>(details->getSource())->getCycles() << std::endl;
}

// The SimpleSceneManager to manage simple applications
void keyPressed(KeyEventDetails* const details, WindowEventProducer* const TutorialWindow)
{
    if(details->getKey() == KeyEventDetails::KEY_Q &&
       details->getModifiers() & KeyEventDetails::KEY_MODIFIER_COMMAND)
    {
        TutorialWindow->closeWindow();
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
    DocForeground->addLine("of a \\{\\color=AAAA00FF FieldAnimation} on a \\{\\color=AAAA00FF ShaderVariableVec4f}.");
    
    DocForeground->addLine("");
    DocForeground->addLine("\\{\\color=AAAAAAFF Key Controls}:");
    DocForeground->addLine("     \\{\\color=AAAAFFFF Cmd+q}: Close the application");
    DocForeground->addLine("         \\{\\color=AAAAFFFF ?}: Show/hide this documentation");

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

        //Initialize Window
        TutorialWindow->initWindow();

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
        TutorialWindow->connectKeyPressed(boost::bind(keyPressed, _1, TutorialWindow.get()));

        //Shader Chunk
        SimpleSHLChunkUnrecPtr TheSHLChunk = SimpleSHLChunk::create();
        TheSHLChunk->setVertexProgram(createSHLVertexProg());
        TheSHLChunk->setFragmentProgram(createSHLFragProg());
        //TheSHLChunk->addUniformVariable("Color1",Vec4f(0.0f,1.0f,0.0f,1.0f));
        //TheSHLChunk->addUniformVariable("Color2",Vec4f(1.0f,1.0f,1.0f,1.0f));

        //Shader Parameter Chunk
        SimpleSHLVariableChunkUnrecPtr SHLParameters = SimpleSHLVariableChunk::create();
        //Color Parameter
        SHLParameters->addUniformVariable("Color1",Vec4f(0.0f,1.0f,0.0f,1.0f));
        SHLParameters->addUniformVariable("Color2",Vec4f(1.0f,1.0f,1.0f,1.0f));

        ChunkMaterialUnrecPtr ShaderMaterial = ChunkMaterial::create();
        ShaderMaterial->addChunk(TheSHLChunk);
        ShaderMaterial->addChunk(SHLParameters);

        //Torus Node
        GeometryUnrecPtr TorusGeometry = makeTorusGeo(5.0f,20.0f, 32,32);

        TorusGeometry->setMaterial(ShaderMaterial);

        NodeUnrecPtr TorusNode = Node::create();
        TorusNode->setCore(TorusGeometry);

        // Make Main Scene Node
        NodeUnrecPtr scene = Node::create();
        scene->setCore(Group::create());
        scene->addChild(TorusNode);

        sceneManager.setRoot(scene);

        //Create the Documentation
        SimpleScreenDoc TheSimpleScreenDoc(&sceneManager, TutorialWindow);

        // Show the whole Scene
        sceneManager.showAll();

        //Create the Animations

        ShaderVariableVec4fUnrecPtr Color1Parameter;
        ShaderVariableVec4fUnrecPtr Color2Parameter;

        Color1Parameter = dynamic_cast<ShaderVariableVec4f*>(const_cast<ShaderVariable*>(SHLParameters->getVariables()->getVariable("Color1")));
        Color2Parameter = dynamic_cast<ShaderVariableVec4f*>(const_cast<ShaderVariable*>(SHLParameters->getVariables()->getVariable("Color2")));
        commitChanges();

        AnimationUnrecPtr TheAnimation = setupAnimation(Color1Parameter, "value");
        TheAnimation->attachUpdateProducer(TutorialWindow);
        TheAnimation->start();

        //Open Window
        Vec2f WinSize(TutorialWindow->getDesktopSize() * 0.85f);
        Pnt2f WinPos((TutorialWindow->getDesktopSize() - WinSize) *0.5);
        TutorialWindow->openWindow(WinPos,
                                   WinSize,
                                   "04ShaderAnimation");

        //Main Loop
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

std::string createSHLVertexProg(void)
{
    std::ostringstream FragCodeStream;

    FragCodeStream
        << "//Vertex Shader\n"
        << "attribute vec4 Position;//Position\n"
        << "attribute vec3 Normal;//Normal\n"

        << "void main(void)\n"
        << "{\n"
        << "    gl_FrontColor = vec4(gl_NormalMatrix * Normal, 1.0);\n"
        << "    gl_Position = gl_ModelViewProjectionMatrix * Position;\n"
        << "}\n";


    return FragCodeStream.str();
}

std::string createSHLFragProg(void)
{
    std::ostringstream FragCodeStream;

    FragCodeStream
        << "//Fragment Shader\n"
        << "uniform vec4 Color1;\n"
        << "uniform vec4 Color2;\n"

        << "void main()\n"
        << "{\n"
        << "    gl_FragColor = mix(Color1,Color2,1.0-gl_Color.r);\n"
        << "}\n";


    return FragCodeStream.str();
}

AnimationTransitPtr setupAnimation(FieldContainer* const AnimatedObject,
                                   const std::string& AnimatedField)
{
    //Color Keyframe Sequence
    KeyframeVectorSequenceVec4fUnrecPtr ColorKeyframes = KeyframeVectorSequenceVec4f::create();
    ColorKeyframes->addRawKeyframe(Vec4f(1.0f,0.0f,0.0f,1.0f),0.0f);
    ColorKeyframes->addRawKeyframe(Vec4f(0.0f,1.0f,0.0f,1.0f),2.0f);
    ColorKeyframes->addRawKeyframe(Vec4f(0.0f,0.0f,1.0f,1.0f),4.0f);
    ColorKeyframes->addRawKeyframe(Vec4f(1.0f,0.0f,0.0f,1.0f),6.0f);

    //Animator
    KeyframeAnimatorUnrecPtr Animator = KeyframeAnimator::create();
    Animator->setKeyframeSequence(ColorKeyframes);

    //Animation
    FieldAnimationUnrecPtr ColorAnimation = FieldAnimation::create();
    ColorAnimation->setAnimator(Animator);
    ColorAnimation->setInterpolationType(Animator::LINEAR_INTERPOLATION);
    ColorAnimation->setCycling(-1);
    ColorAnimation->setAnimatedField(AnimatedObject, AnimatedField);

    return AnimationTransitPtr(ColorAnimation);
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


