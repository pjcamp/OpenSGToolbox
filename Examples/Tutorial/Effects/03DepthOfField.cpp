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

#include "OSGPostShaderStage.h"
#include "OSGDirectionalLight.h"
#include "OSGSolidBackground.h"

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

std::string generateNoEffectProg(void);
std::string generateDOFHorzBlurFragProg(void);
std::string generateDOFVertBlurFragProg(void);
std::string generateDOFCombineProg(void);

void updateDofInfo(SimpleTextForeground* const InfoForeground,
                   PostShaderStage* const PostStage);

void keyPressed(KeyEventDetails* const details,
                WindowEventProducer* const TutorialWindow,
                PostShaderStage* const ThePostShaderCore)
{
    if(details->getKey() == KeyEventDetails::KEY_Q &&
       details->getModifiers() & KeyEventDetails::KEY_MODIFIER_COMMAND)
    {
        TutorialWindow->closeWindow();
    }

    static Real32 InitValue(1.0f);
    static Real32 IncValue(0.1f);
    static std::string ChangableVariable("Gamma");
    switch(details->getKey())
    {
        case KeyEventDetails::KEY_1:
            ThePostShaderCore->clearPasses();
            ThePostShaderCore->addPass("", generateNoEffectProg(),
                                       Vec2f(0.25f,0.25f));
            ThePostShaderCore->addPass("", generateDOFHorzBlurFragProg(),
                                       Vec2f(0.25f,0.25f));
            ThePostShaderCore->addPass("", generateDOFVertBlurFragProg(),
                                       Vec2f(0.25f,0.25f));
            ThePostShaderCore->addPass("", generateDOFCombineProg());
            break;
        case KeyEventDetails::KEY_2:
            ThePostShaderCore->clearPasses();
            ThePostShaderCore->addPass("", generateNoEffectProg(),
                                       Vec2f(0.25f,0.25f));
            break;
        case KeyEventDetails::KEY_3:
            ThePostShaderCore->clearPasses();
            ThePostShaderCore->addPass("", generateNoEffectProg(),
                                       Vec2f(0.25f,0.25f));
            ThePostShaderCore->addPass("", generateDOFHorzBlurFragProg(),
                                       Vec2f(0.25f,0.25f));
            break;
        case KeyEventDetails::KEY_4:
            ThePostShaderCore->clearPasses();
            ThePostShaderCore->addPass("", generateNoEffectProg(),
                                       Vec2f(0.25f,0.25f));
            ThePostShaderCore->addPass("", generateDOFHorzBlurFragProg(),
                                       Vec2f(0.25f,0.25f));
            ThePostShaderCore->addPass("", generateDOFVertBlurFragProg(),
                                       Vec2f(0.25f,0.25f));
            break;
        case KeyEventDetails::KEY_5:
            ThePostShaderCore->clearPasses();
            ThePostShaderCore->addPass("", generateNoEffectProg());
            break;
        case KeyEventDetails::KEY_6:
            //ThePostShaderCore->clearPasses();
            break;
        case KeyEventDetails::KEY_EQUALS:
            {
                Real32 Value(0.0f);
                if(!ThePostShaderCore->getPassShader(3)->getUniformVariable("FocalLength",
                                                                            Value))
                {
                    ThePostShaderCore->getPassShader(3)->addUniformVariable("FocalLength", 200.0f);
                }
                else
                {
                    ThePostShaderCore->getPassShader(3)->updateUniformVariable("FocalLength", Value + 1.0f);
                }
                std::cout << "Focal Length: " << Value + 1.0f <<  std::endl;
            }
            break;
        case KeyEventDetails::KEY_MINUS:
            {
                Real32 Value(0.0f);
                if(!ThePostShaderCore->getPassShader(3)->getUniformVariable("FocalLength",
                                                                            Value))
                {
                    ThePostShaderCore->getPassShader(3)->addUniformVariable("FocalLength", 200.0f);
                }
                else
                {
                    ThePostShaderCore->getPassShader(3)->updateUniformVariable("FocalLength", Value - 1.0f);
                }
                std::cout << "Focal Length: " << Value - 1.0f <<  std::endl;
            }
            break;
        case KeyEventDetails::KEY_R:
            {
                Real32 Value(0.0f);
                if(!ThePostShaderCore->getPassShader(3)->getUniformVariable("FocalRange",
                                                                            Value))
                {
                    ThePostShaderCore->getPassShader(3)->addUniformVariable("FocalRange", 100.0f);
                }
                else
                {
                    ThePostShaderCore->getPassShader(3)->updateUniformVariable("FocalRange", Value + 1.0f);
                }
                std::cout << "Focal Range: " << Value + 1.0f <<  std::endl;
            }
            break;
        case KeyEventDetails::KEY_S:
            {
                Real32 Value(0.0f);
                if(!ThePostShaderCore->getPassShader(3)->getUniformVariable("FocalRange",
                                                                            Value))
                {
                    ThePostShaderCore->getPassShader(3)->addUniformVariable("FocalRange", 100.0f);
                }
                else
                {
                    ThePostShaderCore->getPassShader(3)->updateUniformVariable("FocalRange", Value - 1.0f);
                }
                std::cout << "Focal Range: " << Value - 1.0f <<  std::endl;
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
    DocForeground->addLine("of a \\{\\color=AAAA00FF FCFileHandler} and \\{\\color=AAAA00FF SceneFileHandler}.");
    
    DocForeground->addLine("");
    DocForeground->addLine("\\{\\color=AAAAAAFF Key Commands}:");
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

        if(LoadedRoot == NULL)
        {
            LoadedRoot = SceneFileHandler::the()->read(FilePath.string().c_str());
        }

        if(LoadedRoot == NULL)
        {
            LoadedRoot= makeTorus(.5, 2, 32, 32);
        }

        //Make the fog node
        PostShaderStageRecPtr PostShaderStageCore = PostShaderStage::create();
        PostShaderStageCore->clearPasses();
        PostShaderStageCore->addPass("", generateNoEffectProg(),
                                   Vec2f(0.25f,0.25f));
        PostShaderStageCore->addPass("", generateDOFHorzBlurFragProg(),
                                   Vec2f(0.25f,0.25f));
        PostShaderStageCore->addPass("", generateDOFVertBlurFragProg(),
                                   Vec2f(0.25f,0.25f));
        PostShaderStageCore->addPass("", generateDOFCombineProg());


        DirectionalLightRecPtr SceneLightCore = DirectionalLight::create();
        SceneLightCore->setAmbient(Color4f(0.2f, 0.2f, 0.2f, 1.0f));
        SceneLightCore->setDiffuse(Color4f(0.8f, 0.8f, 0.8f, 1.0f));
        SceneLightCore->setSpecular(Color4f(1.0f, 1.0f, 1.0f, 1.0f));

        NodeRefPtr SceneLight = makeNodeFor(SceneLightCore);
        SceneLight->addChild(LoadedRoot);

        NodeRefPtr PostShaderStageNode = makeNodeFor(PostShaderStageCore);
        PostShaderStageNode->addChild(SceneLight);

        //Make Main Scene Node
        NodeRefPtr scene = makeCoredNode<Group>();

        scene->addChild(PostShaderStageNode);

        // tell the manager what to manage
        sceneManager.setRoot  (scene);
        SceneLightCore->setBeacon(sceneManager.getCamera()->getBeacon());


        //Create the Documentation Foreground and add it to the viewport
        SimpleScreenDoc TheSimpleScreenDoc(&sceneManager, TutorialWindow);


        //Create a foreground for the DOF information
        SimpleTextForegroundRecPtr DOFInfoForeground = SimpleTextForeground::create();
        DOFInfoForeground->setSize(20.0f);
        DOFInfoForeground->setBgColor(Color4f(0.0f,0.0f,0.0f,0.8f));
        DOFInfoForeground->setBorderColor(Color4f(1.0f,1.0f,1.0f,1.0f));
        DOFInfoForeground->setTextMargin(Vec2f(5.0f,5.0f));
        DOFInfoForeground->setHorizontalAlign(SimpleTextForeground::Left);
        DOFInfoForeground->setVerticalAlign(SimpleTextForeground::Top);

        sceneManager.getWindow()->getPort(0)->addForeground(DOFInfoForeground);

        TutorialWindow->connectUpdate(boost::bind(updateDofInfo,
                                                  DOFInfoForeground.get(),
                                                  PostShaderStageCore.get()));

        // show the whole scene
        sceneManager.showAll();

        sceneManager.getWindow()->getPort(0)->setTravMask(1);
        RenderOptionsRecPtr ViewportRenderOptions = RenderOptions::create();
        ViewportRenderOptions->setRenderProperties(0x0);
        ViewportRenderOptions->setRenderProperties(RenderPropertiesPool::the()->getFrom1("Default"));
        ViewportRenderOptions->setRenderProperties(0x01);

        //Make the background
        SolidBackgroundRecPtr BlackBackground = SolidBackground::create();
        BlackBackground->setColor(Color3f(0.0f,0.0f,0.0f));
        sceneManager.getWindow()->getPort(0)->setBackground(BlackBackground);

        sceneManager.getWindow()->getPort(0)->setRenderOptions(ViewportRenderOptions);

        Vec2f WinSize(TutorialWindow->getDesktopSize() * 0.85f);
        Pnt2f WinPos((TutorialWindow->getDesktopSize() - WinSize) *0.5);
        TutorialWindow->openWindow(WinPos,
                                   WinSize,
                                   "Collada Loader");

        TutorialWindow->connectKeyPressed(boost::bind(keyPressed, _1,
                                                      TutorialWindow.get(),
                                                      PostShaderStageCore.get()));

        //Enter main Loop
        TutorialWindow->mainLoop();

    }

    osgExit();

    return 0;
}

void updateDofInfo(SimpleTextForeground* const InfoForeground,
                   PostShaderStage* const PostStage)
{
    InfoForeground->clear();
    if(PostStage->getNumPasses() == 4)
    {
        Real32 Value;
        PostStage->getPassShader(3)->getUniformVariable("FocalLength",
                                                        Value);
        InfoForeground->addLine(std::string("Focus Length: ") +
                                boost::lexical_cast<std::string>(Value));

        PostStage->getPassShader(3)->getUniformVariable("FocalRange",
                                                        Value);
        InfoForeground->addLine(std::string("Focus Range: ") +
                                boost::lexical_cast<std::string>(Value));
    }
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

std::string generateNoEffectProg(void)
{
    std::string ShaderCode;
    ShaderCode = "uniform sampler2D PostSceneColorTex;"
                 "void main(void)"
                 "{"
                 "    gl_FragColor = texture2D( PostSceneColorTex, gl_TexCoord[0].st );"
                 "}";
    return ShaderCode;
}

std::string generateDOFHorzBlurFragProg(void)
{
    std::string ShaderCode;
    ShaderCode = "uniform sampler2D PostPass0ColorTex;"
                 "uniform float PostPass0Width;"
                 "void main(void)"
                 "{"
                 "    float HorzBlurSize = 1.0/PostPass0Width;"
                 "    vec3 ColorSum = vec3(0.0);"
                 "    ColorSum   += texture2D(PostPass0ColorTex,vec2(gl_TexCoord[0].s + 4.0 *HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.05;"
                 "    ColorSum   += texture2D(PostPass0ColorTex,vec2(gl_TexCoord[0].s + 3.0 *HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.09;"
                 "    ColorSum   += texture2D(PostPass0ColorTex,vec2(gl_TexCoord[0].s + 2.0 *HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.12;"
                 "    ColorSum   += texture2D(PostPass0ColorTex,vec2(gl_TexCoord[0].s + HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.15;"
                 "    ColorSum   += texture2D(PostPass0ColorTex,vec2(gl_TexCoord[0].s,gl_TexCoord[0].t)).rgb * 0.16;"
                 "    ColorSum   += texture2D(PostPass0ColorTex,vec2(gl_TexCoord[0].s - HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.15;"
                 "    ColorSum   += texture2D(PostPass0ColorTex,vec2(gl_TexCoord[0].s - 2.0 *HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.12;"
                 "    ColorSum   += texture2D(PostPass0ColorTex,vec2(gl_TexCoord[0].s - 3.0 *HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.09;"
                 "    ColorSum   += texture2D(PostPass0ColorTex,vec2(gl_TexCoord[0].s - 4.0 *HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.05;"
                 "    gl_FragColor = vec4(ColorSum, 1.0);"
                 "}";
    return ShaderCode;
}

std::string generateDOFVertBlurFragProg(void)
{
    std::string ShaderCode;
    ShaderCode = "uniform sampler2D PostPass1ColorTex;"
                 "uniform float PostPass1Height;"
                 "void main(void)"
                 "{"
                 "    float VertPixelSize = 1.0/PostPass1Height;"
                 "    vec3 ColorSum = vec3(0.0);"
                 "    ColorSum   += texture2D(PostPass1ColorTex,vec2(gl_TexCoord[0].s,gl_TexCoord[0].t + 4.0 *VertPixelSize)).rgb * 0.05;"
                 "    ColorSum   += texture2D(PostPass1ColorTex,vec2(gl_TexCoord[0].s,gl_TexCoord[0].t + 3.0 *VertPixelSize)).rgb * 0.09;"
                 "    ColorSum   += texture2D(PostPass1ColorTex,vec2(gl_TexCoord[0].s,gl_TexCoord[0].t + 2.0 *VertPixelSize)).rgb * 0.12;"
                 "    ColorSum   += texture2D(PostPass1ColorTex,vec2(gl_TexCoord[0].s,gl_TexCoord[0].t + VertPixelSize)).rgb * 0.15;"
                 "    ColorSum   += texture2D(PostPass1ColorTex,vec2(gl_TexCoord[0].s,gl_TexCoord[0].t)).rgb * 0.16;"
                 "    ColorSum   += texture2D(PostPass1ColorTex,vec2(gl_TexCoord[0].s,gl_TexCoord[0].t - VertPixelSize)).rgb * 0.15;"
                 "    ColorSum   += texture2D(PostPass1ColorTex,vec2(gl_TexCoord[0].s,gl_TexCoord[0].t - 2.0 *VertPixelSize)).rgb * 0.12;"
                 "    ColorSum   += texture2D(PostPass1ColorTex,vec2(gl_TexCoord[0].s,gl_TexCoord[0].t - 3.0 *VertPixelSize)).rgb * 0.09;"
                 "    ColorSum   += texture2D(PostPass1ColorTex,vec2(gl_TexCoord[0].s,gl_TexCoord[0].t - 4.0 *VertPixelSize)).rgb * 0.05;"
                 "    gl_FragColor = vec4(ColorSum, 1.0);"
                 "}";
    return ShaderCode;
}

std::string generateDOFCombineProg(void)
{
    std::string ShaderCode;
    ShaderCode = "uniform sampler2D PostPass2ColorTex;"
                 "uniform sampler2D PostSceneColorTex;"
                 "uniform sampler2D PostSceneDepthTex;"
                 "uniform float PostCameraNear;"
                 "uniform float PostCameraFar;"
                 //"float FocalLength = 25.0;"
                 //"float FocalRange = 10.0;"
                 "uniform float FocalLength;"
                 "uniform float FocalRange;"
                 "void main(void)"
                 "{"
                 "    vec3 SceneColor = texture2D( PostSceneColorTex, gl_TexCoord[0].st ).rgb;"
                 "    vec3 BlurColor = texture2D( PostPass2ColorTex, gl_TexCoord[0].st ).rgb;"
                 "    vec3 depthSample = texture2D( PostSceneDepthTex, gl_TexCoord[0].st ).rgb;"
                 "    float depth = depthSample.x * 255.0 / 256.0 +"
                 "                  depthSample.y * 255.0 / 65536.0 +"
                 "                  depthSample.z * 255.0 / 16777216.0;"
                 "    float zDistance = (PostCameraNear * PostCameraFar) / (PostCameraFar - depth * (PostCameraFar -PostCameraNear));"
                 "    float blur = clamp(abs(zDistance - FocalLength) / FocalRange, 0.0, 1.0);"

                 "    gl_FragColor = vec4(mix(SceneColor, BlurColor, blur),1.0);"
                 //"    gl_FragColor = vec4(vec3(blur),1.0);"
                 //"    gl_FragColor = vec4(vec3(pow(1.0 - (zDistance - PostCameraNear )/(PostCameraFar -PostCameraNear), 10.0)),1.0);"
                 "}";
    return ShaderCode;
}

