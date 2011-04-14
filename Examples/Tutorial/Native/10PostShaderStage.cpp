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
#include "OSGPointLight.h"

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

std::string generateInvertColorProg(void);
std::string generateDepthAsGrayProg(void);
std::string generateBlurColorVertProg(void);
std::string generateBlurColorFragProg(void);
std::string generateCutoffProg(void);
std::string generateColorCorrectionProg(void);
std::string generateNoEffectProg(void);
std::string generateLaplaceEdgeDetectProg(void);
std::string generateSobelEdgeDetectProg(void);

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
        case KeyEventDetails::KEY_0:
            ThePostShaderCore->setVertexShader("");
            ThePostShaderCore->setFragmentShader(generateNoEffectProg());
            break;
        case KeyEventDetails::KEY_1:
            ThePostShaderCore->setVertexShader("");
            ThePostShaderCore->setFragmentShader(generateInvertColorProg());
            break;
        case KeyEventDetails::KEY_2:
            ThePostShaderCore->setVertexShader("");
            ThePostShaderCore->setFragmentShader(generateDepthAsGrayProg());
            InitValue = 10.0f;
            IncValue = 10.0f;
            ChangableVariable = "DepthContrast";
            break;
        case KeyEventDetails::KEY_3:
            ThePostShaderCore->setVertexShader(generateBlurColorVertProg());
            ThePostShaderCore->setFragmentShader(generateBlurColorFragProg());
            break;
        case KeyEventDetails::KEY_4:
            ThePostShaderCore->setVertexShader("");
            ThePostShaderCore->setFragmentShader(generateCutoffProg());
            break;
        case KeyEventDetails::KEY_5:
            ThePostShaderCore->setVertexShader("");
            ThePostShaderCore->setFragmentShader(generateColorCorrectionProg());
            InitValue = 1.0f;
            IncValue = 0.1f;
            ChangableVariable = "Gamma";
            break;
        case KeyEventDetails::KEY_6:
            ThePostShaderCore->setVertexShader("");
            ThePostShaderCore->setFragmentShader(generateLaplaceEdgeDetectProg());
            break;
        case KeyEventDetails::KEY_7:
            ThePostShaderCore->setVertexShader("");
            ThePostShaderCore->setFragmentShader(generateSobelEdgeDetectProg());
            break;
        case KeyEventDetails::KEY_EQUALS:
            {
                Real32 Value(0.0f);
                if(!ThePostShaderCore->getShader()->getUniformVariable(ChangableVariable.c_str(),
                                                                        Value))
                {
                    ThePostShaderCore->getShader()->addUniformVariable(ChangableVariable.c_str(), InitValue);
                }
                else
                {
                    ThePostShaderCore->getShader()->updateUniformVariable(ChangableVariable.c_str(),
                                                                          Value + IncValue);
                }
            }
            break;
        case KeyEventDetails::KEY_MINUS:
            {
                Real32 Value(0.0f);
                if(!ThePostShaderCore->getShader()->getUniformVariable(ChangableVariable.c_str(),
                                                                        Value))
                {
                    ThePostShaderCore->getShader()->addUniformVariable(ChangableVariable.c_str(), InitValue);
                }
                else
                {
                    ThePostShaderCore->getShader()->updateUniformVariable(ChangableVariable.c_str(),
                                                                          Value - IncValue);
                }
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
        PostShaderStageCore->setFragmentShader(generateBlurColorFragProg());

        NodeRefPtr SceneLightBeacon = makeCoredNode<Group>();

        PointLightRecPtr SceneLightCore = PointLight::create();
        SceneLightCore->setAmbient(Color4f(0.2f, 0.2f, 0.2f, 1.0f));
        SceneLightCore->setDiffuse(Color4f(0.8f, 0.8f, 0.8f, 1.0f));
        SceneLightCore->setSpecular(Color4f(1.0f, 1.0f, 1.0f, 1.0f));
        SceneLightCore->setBeacon(SceneLightBeacon);

        NodeRefPtr SceneLight = makeNodeFor(SceneLightCore);
        SceneLight->addChild(LoadedRoot);

        NodeRefPtr PostShaderStageNode = makeNodeFor(PostShaderStageCore);
        PostShaderStageNode->addChild(SceneLight);
        PostShaderStageNode->addChild(SceneLightBeacon);

        //Make Main Scene Node
        NodeRefPtr scene = makeCoredNode<Group>();

        scene->addChild(PostShaderStageNode);

        // tell the manager what to manage
        sceneManager.setRoot  (scene);

        //Create the Documentation Foreground and add it to the viewport
        SimpleScreenDoc TheSimpleScreenDoc(&sceneManager, TutorialWindow);

        // show the whole scene
        sceneManager.showAll();

        sceneManager.getWindow()->getPort(0)->setTravMask(1);
        RenderOptionsRecPtr ViewportRenderOptions = RenderOptions::create();
        ViewportRenderOptions->setRenderProperties(0x0);
        ViewportRenderOptions->setRenderProperties(RenderPropertiesPool::the()->getFrom1("Default"));
        ViewportRenderOptions->setRenderProperties(0x01);

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

std::string generateInvertColorProg(void)
{
    std::string ShaderCode;
    ShaderCode = "uniform sampler2D PostSceneColorTex;"
                 "void main(void)"
                 "{"
                 "    vec4 SceneColor   = texture2D(PostSceneColorTex, gl_TexCoord[0].xy);"
                 "    gl_FragColor = vec4(vec3(1.0) - SceneColor.rgb, 1.0);"
                 "}";
    return ShaderCode;
}

std::string generateBlurColorVertProg(void)
{
    std::string ShaderCode;
    ShaderCode = ""
                 //"varying vec2 vTexCoord;"
                 //""
                 //"void main(void)"
                 //"{"
                 //"   gl_Position = ftransform();"
                 //""
                 ////"   vec2 Pos;"
                 ////"   Pos = sign(gl_Vertex.xy);"
                 ////""
                 ////"   gl_Position = vec4(Pos, 0.0, 1.0);"
                 //"   vTexCoord = gl_Vertex.xy/* * 0.5 + 0.5*/;"
                 //"}"
                 ;
    return ShaderCode;
}

std::string generateBlurColorFragProg(void)
{
    std::string ShaderCode;
    ShaderCode = "uniform sampler2D PostSceneColorTex;"
                 "uniform float PostFBOWidth;"
                 "void main(void)"
                 "{"
                 "    float HorzBlurSize = 1.0/PostFBOWidth;"
                 "    vec3 ColorSum = vec3(0.0);"
                 "    ColorSum   += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s + 4.0 *HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.05;"
                 "    ColorSum   += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s + 3.0 *HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.09;"
                 "    ColorSum   += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s + 2.0 *HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.12;"
                 "    ColorSum   += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s + HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.15;"
                 "    ColorSum   += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s,gl_TexCoord[0].t)).rgb * 0.16;"
                 "    ColorSum   += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s - HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.15;"
                 "    ColorSum   += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s - 2.0 *HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.12;"
                 "    ColorSum   += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s - 3.0 *HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.09;"
                 "    ColorSum   += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s - 4.0 *HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.05;"
                 "    gl_FragColor = vec4(ColorSum, 1.0);"
                 "}";
    return ShaderCode;
}

std::string generateDepthAsGrayProg(void)
{
    std::string ShaderCode;
    ShaderCode = ""
                 "uniform sampler2D PostSceneDepthTex;"
                 "uniform float DepthContrast;"
                 "void main(void)"
                 "{"
                 "    vec4 SceneDepth = texture2D( PostSceneDepthTex, gl_TexCoord[0].st );"
                 ""
                 "    float depth = SceneDepth.x * 255.0 / 256.0 +"
                 "                  SceneDepth.y * 255.0 / 65536.0 +"
                 "                  SceneDepth.z * 255.0 / 16777216.0;"
                 "    gl_FragColor = vec4(vec3(1.0 - pow(depth, DepthContrast)), 1.0);"
                 "}";
    return ShaderCode;
}

std::string generateCutoffProg(void)
{
    std::string ShaderCode;
    ShaderCode = ""
                 "uniform sampler2D PostSceneColorTex;"
                 "uniform float PostFBOWidth;"
                 "float Cutoff = 0.1;"
                 "void main(void)"
                 "{"
                 "    vec4 SceneColor = texture2D( PostSceneColorTex, gl_TexCoord[0].st );"
                 "    float Intensity = (0.3 * SceneColor.r + 0.59 * SceneColor.g + 0.11 * SceneColor.b);"
                 "    if(Intensity >= Cutoff)"
                 "    {"
                 "        float HorzBlurSize = 1.0/PostFBOWidth;"
                 "        vec3 ColorSum = vec3(0.0);"
                 "        ColorSum   += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s + 4.0 *HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.05;"
                 "        ColorSum   += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s + 3.0 *HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.09;"
                 "        ColorSum   += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s + 2.0 *HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.12;"
                 "        ColorSum   += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s + HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.15;"
                 "        ColorSum   += SceneColor.rgb * 0.16;"
                 "        ColorSum   += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s - HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.15;"
                 "        ColorSum   += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s - 2.0 *HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.12;"
                 "        ColorSum   += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s - 3.0 *HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.09;"
                 "        ColorSum   += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s - 4.0 *HorzBlurSize,gl_TexCoord[0].t)).rgb * 0.05;"
                 "        gl_FragColor = vec4(ColorSum, 1.0);"
                 "    }"
                 "    else"
                 "    {"
                 "        gl_FragColor = SceneColor;"
                 "    }"
                 "}";
    return ShaderCode;
}

std::string generateColorCorrectionProg(void)
{
    std::string ShaderCode;
    ShaderCode = ""
                 "uniform sampler2D PostSceneColorTex;"
                 "uniform float Gamma;"
                 "mat4 ColorMatrix = mat4(1.02, 0.0, 0.0, 0.0,"
                 "                        0.0, 0.98, 0.0, 0.0,"
                 "                        0.0, 0.0, 0.98, 0.0,"
                 "                        0.0, 0.0, 0.0, 1.0);"
                 //"mat4 ColorMatrix = mat4(1.0, 0.0, 0.0, 0.0,"
                 //"                        0.0, 1.0, 0.0, 0.0,"
                 //"                        0.0, 0.0, 1.0, 0.0,"
                 //"                        0.0, 0.0, 0.0, 1.0);"
                 //"mat4 ColorMatrix = mat4(0.3, 0.3, 0.3, 0.0,"
                 //"                        0.59, 0.59, 0.59, 0.0,"
                 //"                        0.11, 0.11, 0.11, 0.0,"
                 //"                        0.0, 0.0, 0.0, 1.0);"
                 "void main(void)"
                 "{"
                 "    vec4 SceneColor = texture2D( PostSceneColorTex, gl_TexCoord[0].st );"
                 //"   // clamp to 0-1"
                 "    SceneColor.rgb = clamp(SceneColor.rgb,0.0,1.0);"
                 ""
                 //"   // make linear"
                 "    SceneColor.r = pow(SceneColor.r,Gamma);"
                 "    SceneColor.g = pow(SceneColor.g,Gamma);"
                 "    SceneColor.b = pow(SceneColor.b,Gamma);"
                 ""
                 //"   // color matrix transformation"
                 "    SceneColor *= ColorMatrix;"
                 "    gl_FragColor = SceneColor;"
                 "}";
    return ShaderCode;
}

std::string generateLaplaceEdgeDetectProg(void)
{
    std::string ShaderCode;
    ShaderCode = ""
                 "uniform sampler2D PostSceneColorTex;"
                 "uniform float PostFBOWidth;"
                 "uniform float PostFBOHeight;"
                 //Laplace Filter
                 "mat3 ConvolutionFilter = mat3(0.0, -1.0, 0.0,"
                 "                        -1.0, 4.0, -1.0,"
                 "                        0.0, -1.0, 0.0);"
                 "void main(void)"
                 "{"
                 "    float HorzPixelSize = 1.0/PostFBOWidth;"
                 "    float VertPixelSize = 1.0/PostFBOHeight;"
                 "    vec3 ColorSum = vec3(0.0);"
                 "    ColorSum += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s,"
                 "                                                 gl_TexCoord[0].t - 1.0 *VertPixelSize)).rgb * ConvolutionFilter[1][0];"
                 ""
                 "    ColorSum += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s - 1.0 *HorzPixelSize,"
                 "                                                 gl_TexCoord[0].t)).rgb * ConvolutionFilter[0][1];"
                 "    ColorSum += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s,"
                 "                                                 gl_TexCoord[0].t)).rgb * ConvolutionFilter[1][1];"
                 "    ColorSum += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s + 1.0 *HorzPixelSize,"
                 "                                                 gl_TexCoord[0].t)).rgb * ConvolutionFilter[2][1];"
                 ""
                 "    ColorSum += texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s,"
                 "                                                 gl_TexCoord[0].t + 1.0 *VertPixelSize)).rgb * ConvolutionFilter[1][2];"
                 "    float Intensity = (0.3 * ColorSum.r + 0.59 * ColorSum.g + 0.11 * ColorSum.b);"
                 //"    if(Intensity >= 0.1)"
                 //"    {"
                 "        gl_FragColor = vec4(vec3(Intensity), 1.0);"
                 //"    }"
                 //"    else"
                 //"    {"
                 //"        gl_FragColor = vec4(vec3(0.0), 1.0);"
                 //"    }"
                 "}";
    return ShaderCode;
}

std::string generateSobelEdgeDetectProg(void)
{
    std::string ShaderCode;
    ShaderCode = "uniform sampler2D PostSceneColorTex;\n"
                 "uniform float PostFBOWidth;\n"
                 "uniform float PostFBOHeight;\n"
                 //Sobel Filter
                 //"mat3 HorizConvolutionFilter = mat3(-1.0, 0.0, 1.0,"
                 //"                        -2.0, 0.0, 2.0,"
                 //"                        -1.0, 0.0, 1.0);"
                 //"mat3 VertConvolutionFilter = mat3(1.0, 2.0, 1.0,"
                 //"                        0.0, 0.0, 0.0,"
                 //"                        -1.0, -2.0, -1.0);"
                 //Scharr Filter
                 "mat3 HorizConvolutionFilter = mat3(-3.0, 0.0, 3.0,"
                 "                        -10.0, 0.0, 10.0,"
                 "                        -3.0, 0.0, 3.0);\n"
                 "mat3 VertConvolutionFilter = mat3(3.0, 10.0, 3.0,"
                 "                        0.0, 0.0, 0.0,"
                 "                        -3.0, -10.0, -3.0);\n"
                 "void main(void)\n"
                 "{\n"
                 "    float HorzPixelSize = 1.0/PostFBOWidth;\n"
                 "    float VertPixelSize = 1.0/PostFBOHeight;\n"
                 "    float HorizColorSum = 0.0;\n"
                 "    float VertColorSum = 0.0;\n"
                 "    vec3 ToGrey = vec3(0.3, 0.59, 0.11);\n"
                 "    float GreyColor = 0.0;\n"
                 "    GreyColor = dot(texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s - 1.0 *HorzPixelSize,"
                 "                                             gl_TexCoord[0].t - 1.0 *VertPixelSize)).rgb, ToGrey);\n"
                 "    HorizColorSum += GreyColor * HorizConvolutionFilter[0][0];\n"
                 "    VertColorSum += GreyColor * VertConvolutionFilter[0][0];\n"
                 "    GreyColor += dot(texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s,"
                 "                                                 gl_TexCoord[0].t - 1.0 *VertPixelSize)).rgb, ToGrey);\n"
                 "    HorizColorSum += GreyColor * HorizConvolutionFilter[1][0];\n"
                 "    VertColorSum += GreyColor * VertConvolutionFilter[1][0];\n"
                 "    GreyColor = dot(texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s + 1.0 *HorzPixelSize,"
                 "                                             gl_TexCoord[0].t - 1.0 *VertPixelSize)).rgb, ToGrey);\n"
                 "    HorizColorSum += GreyColor * HorizConvolutionFilter[2][0];\n"
                 "    VertColorSum += GreyColor * VertConvolutionFilter[2][0];\n"
                 ""
                 "    GreyColor = dot(texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s - 1.0 *HorzPixelSize,"
                 "                                             gl_TexCoord[0].t)).rgb, ToGrey);\n"
                 "    HorizColorSum += GreyColor * HorizConvolutionFilter[0][1];\n"
                 "    VertColorSum += GreyColor * VertConvolutionFilter[0][1];\n"
                 "    GreyColor = dot(texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s,"
                 "                                             gl_TexCoord[0].t)).rgb, ToGrey);\n"
                 "    HorizColorSum += GreyColor * HorizConvolutionFilter[1][1];\n"
                 "    VertColorSum += GreyColor * VertConvolutionFilter[1][1];\n"
                 "    GreyColor = dot(texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s + 1.0 *HorzPixelSize,"
                 "                                             gl_TexCoord[0].t)).rgb, ToGrey);\n"
                 "    HorizColorSum += GreyColor * HorizConvolutionFilter[2][1];\n"
                 "    VertColorSum += GreyColor * VertConvolutionFilter[2][1];\n"
                 ""
                 "    GreyColor = dot(texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s - 1.0 *HorzPixelSize,"
                 "                                             gl_TexCoord[0].t + 1.0 *VertPixelSize)).rgb, ToGrey);\n"
                 "    HorizColorSum += GreyColor * HorizConvolutionFilter[0][2];\n"
                 "    VertColorSum += GreyColor * VertConvolutionFilter[0][2];\n"
                 "    GreyColor = dot(texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s,"
                 "                                             gl_TexCoord[0].t + 1.0 *VertPixelSize)).rgb, ToGrey);\n"
                 "    HorizColorSum += GreyColor * HorizConvolutionFilter[1][2];\n"
                 "    VertColorSum += GreyColor * VertConvolutionFilter[1][2];\n"
                 "    GreyColor = dot(texture2D(PostSceneColorTex,vec2(gl_TexCoord[0].s + 1.0 *HorzPixelSize,"
                 "                                             gl_TexCoord[0].t + 1.0 *VertPixelSize)).rgb, ToGrey);\n"
                 "    HorizColorSum += GreyColor * HorizConvolutionFilter[2][2];\n"
                 "    VertColorSum += GreyColor * VertConvolutionFilter[2][2];\n"
                 "    float intensity = 0.0;\n"
                 "    if(HorizColorSum * HorizColorSum + VertColorSum * VertColorSum > 10.0)\n"
                 "    {\n"
                 "        intensity = 1.0;\n"
                 "    }\n"
                 "    else\n"
                 "    {\n"
                 "        intensity = 0.0;\n"
                 "    }\n"
                 "    gl_FragColor = vec4(vec3(sqrt(HorizColorSum * HorizColorSum + VertColorSum * VertColorSum)/20.0), 1.0);\n"
                 "}";
    return ShaderCode;
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
