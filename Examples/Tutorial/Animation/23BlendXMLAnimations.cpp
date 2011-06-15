// 
// OpenSGToolbox Tutorial: 23BlendXMLAnimations 
//
// Creates a SkeletonBlendedAnimation from skeleton
// animations stored in two XML files.
//

#ifdef OSG_BUILD_ACTIVE
// General OpenSG configuration, needed everywhere
#include <OSGConfig.h>

// Methods to create simple geometry: boxes, spheres, tori etc.
#include <OSGSimpleGeometry.h>

// A little helper to simplify scene management and interaction
#include <OSGSimpleSceneManager.h>

// Input
#include <OSGKeyListener.h>
#include <OSGWindowUtils.h>

//Text Foreground
#include "OSGSimpleTextForeground.h"

#include <OSGComponentTransform.h>
#include <OSGTransform.h>
#include <OSGGeometry.h>
#include <OSGGradientBackground.h>
#include <OSGViewport.h>
#include <OSGDirectionalLight.h>

#include <OSGBlendGeometry.h>

#include <OSGFieldContainerUtils.h>
#include <OSGSimpleAttachments.h>

//User Interface
#include <OSGUIForeground.h>
#include <OSGInternalWindow.h>
#include <OSGUIDrawingSurface.h>
#include <OSGGraphics2D.h>
#include <OSGFlowLayout.h>
#include <OSGLookAndFeelManager.h>
#include <OSGLayers.h>
#include <OSGSlider.h>
#include <OSGLabel.h>
#include <OSGDefaultBoundedRangeModel.h>
#include <OSGGLViewport.h>

//Material
#include <OSGLineChunk.h>
#include <OSGBlendChunk.h>
#include <OSGChunkMaterial.h>
#include <OSGMaterialChunk.h>

//Animation
#include <OSGSkeleton.h>
#include <OSGSkeletonDrawable.h>
#include <OSGTime.h>
#include <OSGKeyframeSequences.h>
#include <OSGFieldAnimation.h>
#include <OSGKeyframeAnimator.h>
#include <OSGElapsedTimeAnimationAdvancer.h>
#include <OSGSimpleAttachments.h>
#include <OSGSkeletonAnimation.h>
#include <OSGSkeletonBlendedAnimation.h>
#include <OSGSkeleton.h>
#include <OSGJoint.h>

#include <OSGSimpleGeometry.h>
#include <OSGSkeletonBlendedGeometry.h>

// the general scene file loading handler
#include <OSGSceneFileHandler.h>

//IO
#include <OSGFCFileHandler.h>
#else
// General OpenSG configuration, needed everywhere
#include <OpenSG/OSGConfig.h>

// Methods to create simple geometry: boxes, spheres, tori etc.
#include <OpenSG/OSGSimpleGeometry.h>

// A little helper to simplify scene management and interaction
#include <OpenSG/OSGSimpleSceneManager.h>

// Input
#include <OpenSG/Input/OSGKeyListener.h>
#include <OpenSG/Input/OSGWindowUtils.h>

#include <OpenSG/OSGComponentTransform.h>
#include <OpenSG/OSGTransform.h>
#include <OpenSG/OSGGeometry.h>
#include <OpenSG/OSGGradientBackground.h>
#include <OpenSG/OSGViewport.h>
#include <OpenSG/OSGDirectionalLight.h>

#include <OpenSG/Animation/OSGBlendGeometry.h>

#include <OpenSG/Toolbox/OSGFieldContainerUtils.h>
#include <OpenSG/OSGSimpleAttachments.h>

//User Interface
#include <OpenSG/UserInterface/OSGUIForeground.h>
#include <OpenSG/UserInterface/OSGInternalWindow.h>
#include <OpenSG/UserInterface/OSGUIDrawingSurface.h>
#include <OpenSG/UserInterface/OSGGraphics2D.h>
#include <OpenSG/UserInterface/OSGFlowLayout.h>
#include <OpenSG/UserInterface/OSGLookAndFeelManager.h>
#include <OpenSG/UserInterface/OSGLayers.h>
#include <OpenSG/UserInterface/OSGSlider.h>
#include <OpenSG/UserInterface/OSGLabel.h>
#include <OpenSG/UserInterface/OSGDefaultBoundedRangeModel.h>
#include <OpenSG/UserInterface/OSGGLViewport.h>

//Material
#include <OpenSG/OSGLineChunk.h>
#include <OpenSG/OSGBlendChunk.h>
#include <OpenSG/OSGChunkMaterial.h>
#include <OpenSG/OSGMaterialChunk.h>

//Animation
#include <OpenSG/Animation/OSGSkeleton.h>
#include <OpenSG/Animation/OSGSkeletonDrawable.h>
#include <OpenSG/OSGTime.h>
#include <OpenSG/Animation/OSGKeyframeSequences.h>
#include <OpenSG/Animation/OSGFieldAnimation.h>
#include <OpenSG/Animation/OSGKeyframeAnimator.h>
#include <OpenSG/Animation/OSGElapsedTimeAnimationAdvancer.h>
#include <OpenSG/OSGSimpleAttachments.h>
#include <OpenSG/Animation/OSGSkeletonAnimation.h>
#include <OpenSG/Animation/OSGSkeletonBlendedAnimation.h>
#include <OpenSG/Animation/OSGSkeleton.h>
#include <OpenSG/Animation/OSGJoint.h>

#include <OpenSG/OSGSimpleGeometry.h>
#include <OpenSG/Animation/OSGSkeletonBlendedGeometry.h>

// the general scene file loading handler
#include <OpenSG/OSGSceneFileHandler.h>

//IO
#include <OpenSG/Toolbox/OSGFCFileHandler.h>
#endif

// Activate the OpenSG namespace
// This is not strictly necessary, you can also prefix all OpenSG symbols
// with OSG::, but that would be a bit tedious for this example
OSG_USING_NAMESPACE

// The SimpleSceneManager to manage simple applications
SimpleSceneManager *mgr;
WindowEventProducerPtr TutorialWindowEventProducer;

// For the skeleton
SkeletonBlendedAnimationPtr TheSkeletonBlendedAnimation;
SkeletonAnimationPtr TheWalkingAnimation;
SkeletonAnimationPtr TheSecondAnimation;
Real32 BlendWalking = 1;
Real32 BlendTouchScreen = 1;
AnimationAdvancerPtr TheAnimationAdvancer;

std::vector<NodePtr> UnboundGeometries;
std::vector<NodePtr> SkeletonNodes;
std::vector<NodePtr> MeshNodes;

// forward declaration so we can have the interesting stuff upfront
ComponentPtr createGLPanel(void);
bool animationPaused = false;

// Forward declaration so we can have the interesting stuff upfront
void display(void);
void reshape(Vec2f Size);

// Create a class to allow for the use of the keyboard shortcuts 
class TutorialKeyListener : public KeyListener
{
public:

   virtual void keyPressed(const KeyEventPtr e)
   {
       //Exit
       if(e->getKey() == KeyEvent::KEY_Q && e->getModifiers() & KeyEvent::KEY_MODIFIER_COMMAND)
       {
           TutorialWindowEventProducer->closeWindow();
       }

       //Toggle animation
       if(e->getKey() == KeyEvent::KEY_SPACE)
       {
           if(animationPaused)
               animationPaused = false;
           else
               animationPaused = true;
       }


       //Toggle bind pose
       if(e->getKey() == KeyEvent::KEY_B)
       {
           if(e->getModifiers() & KeyEvent::KEY_MODIFIER_SHIFT)
           {
               //Toggle mesh
               for(int i(0); i < UnboundGeometries.size(); ++i)
               {
                   if(UnboundGeometries[i]->getTravMask() == 0)
                   {
                       beginEditCP(UnboundGeometries[i], Node::TravMaskFieldMask);
                            UnboundGeometries[i]->setTravMask(1);
                        endEditCP(UnboundGeometries[i], Node::TravMaskFieldMask);
                   } 
                   else
                   {
                       beginEditCP(UnboundGeometries[i], Node::TravMaskFieldMask);
                            UnboundGeometries[i]->setTravMask(0);
                        endEditCP(UnboundGeometries[i], Node::TravMaskFieldMask);
                   }
               }
           }
           else
           {
               //Toggle skeleton
               for(int i(0); i < SkeletonNodes.size(); ++i)
               {
                   if(SkeletonDrawable::Ptr::dcast(SkeletonNodes[i]->getCore())->getDrawBindPose() == false)
                   {
                       beginEditCP(SkeletonDrawable::Ptr::dcast(SkeletonNodes[i]->getCore()), SkeletonDrawable::DrawBindPoseFieldMask);
                         SkeletonDrawable::Ptr::dcast(SkeletonNodes[i]->getCore())->setDrawBindPose(true);
                        endEditCP(SkeletonDrawable::Ptr::dcast(SkeletonNodes[i]->getCore()), SkeletonDrawable::DrawBindPoseFieldMask);
                   } 
                   else
                   {
                       beginEditCP(SkeletonDrawable::Ptr::dcast(SkeletonNodes[i]->getCore()), SkeletonDrawable::DrawBindPoseFieldMask);
                         SkeletonDrawable::Ptr::dcast(SkeletonNodes[i]->getCore())->setDrawBindPose(false);
                        endEditCP(SkeletonDrawable::Ptr::dcast(SkeletonNodes[i]->getCore()), SkeletonDrawable::DrawBindPoseFieldMask);
                   }
               }
           }
       }

       //Toggle current pose
       if(e->getKey() == KeyEvent::KEY_P)
       {
           if(e->getModifiers() & KeyEvent::KEY_MODIFIER_SHIFT)
           {
               //Toggle mesh
               for(int i(0); i < MeshNodes.size(); ++i)
               {
                   if(MeshNodes[i]->getTravMask() == 0)
                   {
                       beginEditCP(MeshNodes[i], Node::TravMaskFieldMask);
                            MeshNodes[i]->setTravMask(1);
                        endEditCP(MeshNodes[i], Node::TravMaskFieldMask);
                   } 
                   else
                   {
                       beginEditCP(MeshNodes[i], Node::TravMaskFieldMask);
                            MeshNodes[i]->setTravMask(0);
                        endEditCP(MeshNodes[i], Node::TravMaskFieldMask);
                   }
               }
           }
           else
           {
               //Toggle skeleton
               for(int i(0); i < SkeletonNodes.size(); ++i)
               {
                   if(SkeletonDrawable::Ptr::dcast(SkeletonNodes[i]->getCore())->getDrawPose() == false)
                   {
                       beginEditCP(SkeletonDrawable::Ptr::dcast(SkeletonNodes[i]->getCore()), SkeletonDrawable::DrawPoseFieldMask);
                         SkeletonDrawable::Ptr::dcast(SkeletonNodes[i]->getCore())->setDrawPose(true);
                        endEditCP(SkeletonDrawable::Ptr::dcast(SkeletonNodes[i]->getCore()), SkeletonDrawable::DrawPoseFieldMask);
                   } 
                   else
                   {
                       beginEditCP(SkeletonDrawable::Ptr::dcast(SkeletonNodes[i]->getCore()), SkeletonDrawable::DrawPoseFieldMask);
                         SkeletonDrawable::Ptr::dcast(SkeletonNodes[i]->getCore())->setDrawPose(false);
                        endEditCP(SkeletonDrawable::Ptr::dcast(SkeletonNodes[i]->getCore()), SkeletonDrawable::DrawPoseFieldMask);
                   }
               }
           }
       }

       //Toggle override status on second animation
       if(e->getKey() == KeyEvent::KEY_O)
       {
           if(TheSkeletonBlendedAnimation->getOverrideStatus(1))
           {
               TheSkeletonBlendedAnimation->setOverrideStatus(1, false);
           }
           else
           {
               TheSkeletonBlendedAnimation->setOverrideStatus(1, true);
           }
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
        if(!animationPaused)
        {
            ElapsedTimeAnimationAdvancer::Ptr::dcast(TheAnimationAdvancer)->update(e->getElapsedTime());

            TheSkeletonBlendedAnimation->update(TheAnimationAdvancer);
        }
    }
};

//Create a listener to let us change the SkeletonBlendedAnimation's blend amounts at runtime
class BlendAmountSliderChangeListener : public ChangeListener
{
  public:
      BlendAmountSliderChangeListener(SkeletonBlendedAnimationPtr TheSkeletonBlendedAnimation,
          UInt32 BlendAmountIndex, SliderPtr TheSlider) : _SkeletonBlendedAnimation(TheSkeletonBlendedAnimation),_BlendAmountIndex(BlendAmountIndex),_Slider(TheSlider)
      {
      }

    virtual void stateChanged(const ChangeEventPtr e)
    {
        if(_Slider != NullFC && 
            _SkeletonBlendedAnimation != NullFC)
        {
            _SkeletonBlendedAnimation->setBlendAmount(_BlendAmountIndex,static_cast<Real32>(_Slider->getValue())/100.0f);
        }
    }
protected:
    SkeletonBlendedAnimationPtr _SkeletonBlendedAnimation;
    UInt32 _BlendAmountIndex;
    SliderPtr _Slider;
};

class NamedNodeFinder
{
  public:
  
    NamedNodeFinder(void) : _name(), _found() {}

    NodePtr operator() (NodePtr root, std::string name)
    {
        _name=&name;
        _found=NullFC;
        
        traverse(root, osgTypedMethodFunctor1ObjPtrCPtrRef(
                            this, 
                            &NamedNodeFinder::check));
        
        return _found;
    }
 
    static NodePtr find(NodePtr root, std::string name)
    {
        NamedNodeFinder f;      
        
        return f(root,name);
    }
   
  private:
     
    Action::ResultE check(NodePtr& node)
    {
        if(getName(node) && *_name == getName(node))
        {
            _found = node;
            return Action::Quit;
        }

        return Action::Continue;        
    }
 
    NodePtr  _found;
    std::string  *_name;
};

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
    DocForeground->addLine("     \\{\\color=AAAAFFFF Cmd+q}: Close the application");
    DocForeground->addLine("         \\{\\color=AAAAFFFF ?}: Show/hide this documentation");

    DocForeground->addLine("");
    DocForeground->addLine("\\{\\color=AAAAAAFF Mouse Controls}:");
    DocForeground->addLine("   \\{\\color=AAAAFFFF Scroll wheel}: Zoom in/out");
    DocForeground->addLine("      \\{\\color=AAAAFFFF Left+drag}: Rotate");
    DocForeground->addLine("     \\{\\color=AAAAFFFF Right+drag}: Translate");

    return SimpleTextForegroundTransitPtr(DocForeground);
}

// Initialize OpenSG and set up the scene
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
    mgr->setWindow(MainWindow);
    

    //Print key command info
    std::cout << "\n\nKEY COMMANDS:" << std::endl;
    std::cout << "space   Play/Pause the animation" << std::endl;
    std::cout << "B       Show/Hide the bind pose skeleton" << std::endl;
    std::cout << "SHIFT-B Show/Hide the bind pose mesh" << std::endl;
    std::cout << "P       Show/Hide the current pose skeleton" << std::endl;
    std::cout << "SHIFT-P Show/Hide the current pose mesh" << std::endl;
    std::cout << "O       Toggle override status of TheSecondAnimation" << std::endl;
    std::cout << "CTRL-Q  Exit\n\n" << std::endl;


    
    //Import scene from XML
    ChunkMaterialPtr ExampleMaterial;
    std::vector<SkeletonPtr> SkeletonPtrs;
    std::vector<SkeletonBlendedGeometryPtr> SkeletonBlendedGeometryPtrs;
    std::vector<GeometryPtr> GeometryPtrs;

    //Skeleton materaial
    LineChunkPtr SkelLineChunk = LineChunk::create();
    beginEditCP(SkelLineChunk);
        SkelLineChunk->setWidth(0.0f);
        SkelLineChunk->setSmooth(true);
    endEditCP(SkelLineChunk);

    ChunkMaterialPtr SkelMaterial = ChunkMaterial::create();
    beginEditCP(SkelMaterial, ChunkMaterial::ChunksFieldMask);
        SkelMaterial->addChunk(SkelLineChunk);
    endEditCP(SkelMaterial, ChunkMaterial::ChunksFieldMask);

    //LOAD FIRST ANIMATION
    FCFileType::FCPtrStore NewContainers;
    NewContainers = FCFileHandler::the()->read(BoostPath("./Data/23WalkingAnimation.xml"));
    FCFileType::FCPtrStore::iterator Itor;
    for(Itor = NewContainers.begin() ; Itor != NewContainers.end() ; ++Itor)
    {
        if( (*Itor)->getType() == (ChunkMaterial::getClassType()))
        {
            //Set ExampleMaterial to the ChunkMaterial we just read in
            ExampleMaterial = (ChunkMaterial::Ptr::dcast(*Itor));
        }
        if( (*Itor)->getType() == (Skeleton::getClassType()))
        {
            //Add the Skeleton we just read in to SkeletonPtrs
            SkeletonPtrs.push_back(Skeleton::Ptr::dcast(*Itor));
        }
        if( (*Itor)->getType() == (SkeletonBlendedGeometry::getClassType()))
        {
            //Add the SkeletonBlendedGeometry we just read in to SkeletonBlendedGeometryPtrs
            SkeletonBlendedGeometryPtrs.push_back(SkeletonBlendedGeometry::Ptr::dcast(*Itor));
        }
        if( (*Itor)->getType().isDerivedFrom(SkeletonAnimation::getClassType()))
        {
            //Set TheWalkingAnimation to the SkeletonAnimation we just read in
            TheWalkingAnimation = (SkeletonAnimation::Ptr::dcast(*Itor));
        }
        if( (*Itor)->getType() == (Geometry::getClassType()))
        {
            //Add the Geometry we just read in to GeometryPtrs
            GeometryPtrs.push_back(Geometry::Ptr::dcast(*Itor));
        }
    }

    //LOAD SECOND ANIMATION
    NewContainers = FCFileHandler::the()->read(BoostPath("./Data/23SamAnimation.xml"));
    for(Itor = NewContainers.begin() ; Itor != NewContainers.end() ; ++Itor)
    {
         //Import only the skeletonAnimation from the second XML file; we've already imported the skeleton and the geometry
        if( (*Itor)->getType().isDerivedFrom(SkeletonAnimation::getClassType()))
        {
            TheSecondAnimation = (SkeletonAnimation::Ptr::dcast(*Itor));
        }
    }

    //Blend the two animations
    TheSkeletonBlendedAnimation = SkeletonBlendedAnimation::create();
    beginEditCP(TheSkeletonBlendedAnimation);
        TheSkeletonBlendedAnimation->addAnimationBlending(TheWalkingAnimation, BlendWalking, false);
        TheSkeletonBlendedAnimation->addAnimationBlending(TheSecondAnimation, BlendTouchScreen, false);
    endEditCP(TheSkeletonBlendedAnimation);


    
    //Create unbound geometry Node (to show the mesh in its bind pose)
    for (int i(0); i < GeometryPtrs.size(); ++i)
    {
        NodePtr UnboundGeometry = Node::create();
        beginEditCP(UnboundGeometry, Node::CoreFieldMask | Node::TravMaskFieldMask);
            UnboundGeometry->setCore(GeometryPtrs[i]);
            UnboundGeometry->setTravMask(0);  //By default, we don't show the mesh in its bind pose.
        endEditCP(UnboundGeometry, Node::CoreFieldMask | Node::TravMaskFieldMask);

        UnboundGeometries.push_back(UnboundGeometry);
    }


    //Create skeleton nodes
    for (int i(0); i < SkeletonPtrs.size(); ++i)
    {
        //SkeletonDrawer
        SkeletonDrawablePtr ExampleSkeletonDrawable = osg::SkeletonDrawable::create();
        beginEditCP(ExampleSkeletonDrawable, SkeletonDrawable::SkeletonFieldMask | SkeletonDrawable::MaterialFieldMask | SkeletonDrawable::DrawPoseFieldMask | SkeletonDrawable::PoseColorFieldMask  | SkeletonDrawable::DrawBindPoseFieldMask | SkeletonDrawable::BindPoseColorFieldMask);
            ExampleSkeletonDrawable->setSkeleton(SkeletonPtrs[i]);
            ExampleSkeletonDrawable->setMaterial(SkelMaterial);
            ExampleSkeletonDrawable->setDrawPose(true);                                  //By default we draw the current skeleton
            ExampleSkeletonDrawable->setPoseColor(Color4f(1.0, 0.0, 1.0, 1.0));       //Set color of current skeleton
            ExampleSkeletonDrawable->setDrawBindPose(false);                          //By default we don't draw the bind pose skeleton
            ExampleSkeletonDrawable->setBindPoseColor(Color4f(1.0, 1.0, 0.0, 1.0));   //Set color of bind pose skeleton
        endEditCP(ExampleSkeletonDrawable, SkeletonDrawable::SkeletonFieldMask | SkeletonDrawable::MaterialFieldMask | SkeletonDrawable::DrawPoseFieldMask | SkeletonDrawable::PoseColorFieldMask  | SkeletonDrawable::DrawBindPoseFieldMask | SkeletonDrawable::BindPoseColorFieldMask);
        
        //Skeleton Node
        NodePtr SkeletonNode = osg::Node::create();
        beginEditCP(SkeletonNode, Node::CoreFieldMask);
            SkeletonNode->setCore(ExampleSkeletonDrawable);
        endEditCP(SkeletonNode, Node::CoreFieldMask);

        SkeletonNodes.push_back(SkeletonNode);
    }



    //Create skeleton blended geometry nodes
    for (int i(0); i < SkeletonBlendedGeometryPtrs.size(); ++i)
    {
        NodePtr MeshNode = osg::Node::create();
        beginEditCP(MeshNode, Node::CoreFieldMask);
            MeshNode->setCore(SkeletonBlendedGeometryPtrs[i]);
        endEditCP(MeshNode, Node::CoreFieldMask);

        MeshNodes.push_back(MeshNode);
    }



    //Setup scene
    NodePtr EmptyScene = osg::Node::create();
    beginEditCP(EmptyScene, Node::CoreFieldMask);
        EmptyScene->setCore(Group::create());
    endEditCP  (EmptyScene, Node::CoreFieldMask);

    mgr->setRoot(EmptyScene);



    //User Interface
    // Create the Graphics
    GraphicsPtr TutorialGraphics = osg::Graphics2D::create();

    // Initialize the LookAndFeelManager to enable default settings
    LookAndFeelManager::the()->getLookAndFeel()->init();

    // Create the DefaultBoundedRangeModelPtr and 
    // set its values
    DefaultBoundedRangeModelPtr UpperAnimationSliderRangeModel = DefaultBoundedRangeModel::create();
    UpperAnimationSliderRangeModel->setMinimum(0);
    UpperAnimationSliderRangeModel->setMaximum(100);
    UpperAnimationSliderRangeModel->setValue(BlendWalking * 100);
    UpperAnimationSliderRangeModel->setExtent(0);
    
    //Create the upper animation blend amount slider
    LabelPtr TempLabel;
    SliderPtr UpperAnimationSlider = Slider::create();
    beginEditCP(UpperAnimationSlider, Slider::LabelMapFieldMask | Slider::PreferredSizeFieldMask | Slider::MajorTickSpacingFieldMask | Slider::MinorTickSpacingFieldMask | Slider::SnapToTicksFieldMask | Slider::DrawLabelsFieldMask | Slider::RangeModelFieldMask);

     //Label the slider
        TempLabel = Label::Ptr::dcast(UpperAnimationSlider->getLabelPrototype()->shallowCopy());
        beginEditCP(TempLabel, Label::TextFieldMask); TempLabel->setText("0.0"); endEditCP(TempLabel, Label::TextFieldMask);
        UpperAnimationSlider->getLabelMap()[0] = TempLabel;

        TempLabel = Label::Ptr::dcast(UpperAnimationSlider->getLabelPrototype()->shallowCopy());
        beginEditCP(TempLabel, Label::TextFieldMask); TempLabel->setText("1.0"); endEditCP(TempLabel, Label::TextFieldMask);
        UpperAnimationSlider->getLabelMap()[100] = TempLabel;

        //Customize the slider
        UpperAnimationSlider->setPreferredSize(Vec2f(100, 300));
        UpperAnimationSlider->setSnapToTicks(false);
        UpperAnimationSlider->setMajorTickSpacing(10);
        UpperAnimationSlider->setMinorTickSpacing(5);
        UpperAnimationSlider->setOrientation(Slider::VERTICAL_ORIENTATION);
        UpperAnimationSlider->setInverted(true);
        UpperAnimationSlider->setDrawLabels(true);
        UpperAnimationSlider->setRangeModel(UpperAnimationSliderRangeModel);
    endEditCP(UpperAnimationSlider, Slider::LabelMapFieldMask | Slider::PreferredSizeFieldMask | Slider::MajorTickSpacingFieldMask | Slider::MinorTickSpacingFieldMask | Slider::SnapToTicksFieldMask | Slider::DrawLabelsFieldMask | Slider::RangeModelFieldMask);
    
    DefaultBoundedRangeModelPtr LowerAnimationSliderRangeModel = DefaultBoundedRangeModel::create();
    LowerAnimationSliderRangeModel->setMinimum(0);
    LowerAnimationSliderRangeModel->setMaximum(100);
    LowerAnimationSliderRangeModel->setValue(BlendTouchScreen * 100);
    LowerAnimationSliderRangeModel->setExtent(0);
    
    //Create the lower animation blend amount slider
    SliderPtr LowerAnimationSlider = Slider::create();
    beginEditCP(LowerAnimationSlider, Slider::LabelMapFieldMask | Slider::PreferredSizeFieldMask | Slider::MajorTickSpacingFieldMask | Slider::MinorTickSpacingFieldMask | Slider::SnapToTicksFieldMask | Slider::DrawLabelsFieldMask | Slider::RangeModelFieldMask);

     //Label the slider
        TempLabel = Label::Ptr::dcast(LowerAnimationSlider->getLabelPrototype()->shallowCopy());
        beginEditCP(TempLabel, Label::TextFieldMask); TempLabel->setText("0.0"); endEditCP(TempLabel, Label::TextFieldMask);
        LowerAnimationSlider->getLabelMap()[0] = TempLabel;

        TempLabel = Label::Ptr::dcast(LowerAnimationSlider->getLabelPrototype()->shallowCopy());
        beginEditCP(TempLabel, Label::TextFieldMask); TempLabel->setText("1.0"); endEditCP(TempLabel, Label::TextFieldMask);
        LowerAnimationSlider->getLabelMap()[100] = TempLabel;

        //Customize the slider
        LowerAnimationSlider->setPreferredSize(Vec2f(100, 300));
        LowerAnimationSlider->setSnapToTicks(false);
        LowerAnimationSlider->setMajorTickSpacing(10);
        LowerAnimationSlider->setMinorTickSpacing(5);
        LowerAnimationSlider->setOrientation(Slider::VERTICAL_ORIENTATION);
        LowerAnimationSlider->setInverted(true);
        LowerAnimationSlider->setDrawLabels(true);
        LowerAnimationSlider->setRangeModel(LowerAnimationSliderRangeModel);
    endEditCP(LowerAnimationSlider, Slider::LabelMapFieldMask | Slider::PreferredSizeFieldMask | Slider::MajorTickSpacingFieldMask | Slider::MinorTickSpacingFieldMask | Slider::SnapToTicksFieldMask | Slider::DrawLabelsFieldMask | Slider::RangeModelFieldMask);

    // Create Background to be used with the MainFrame
    ColorLayerPtr MainFrameBackground = osg::ColorLayer::create();
    beginEditCP(MainFrameBackground, ColorLayer::ColorFieldMask);
        MainFrameBackground->setColor(Color4f(1.0,1.0,1.0,0.5));
    endEditCP(MainFrameBackground, ColorLayer::ColorFieldMask);

    // Create The Main InternalWindow
    // Create Background to be used with the Main InternalWindow
    ColorLayerPtr MainInternalWindowBackground = osg::ColorLayer::create();
    beginEditCP(MainInternalWindowBackground, ColorLayer::ColorFieldMask);
        MainInternalWindowBackground->setColor(Color4f(1.0,1.0,1.0,0.5));
    endEditCP(MainInternalWindowBackground, ColorLayer::ColorFieldMask);

    LayoutPtr MainInternalWindowLayout = osg::FlowLayout::create();

    //GL Viewport
    ComponentPtr TheGLViewport = createGLPanel();
    InternalWindowPtr MainInternalWindow = osg::InternalWindow::create();
    beginEditCP(MainInternalWindow, InternalWindow::ChildrenFieldMask | InternalWindow::LayoutFieldMask | InternalWindow::BackgroundsFieldMask | InternalWindow::AlignmentInDrawingSurfaceFieldMask | InternalWindow::ScalingInDrawingSurfaceFieldMask | InternalWindow::DrawTitlebarFieldMask | InternalWindow::ResizableFieldMask);
       MainInternalWindow->getChildren().push_back(UpperAnimationSlider);
       MainInternalWindow->getChildren().push_back(LowerAnimationSlider);
       MainInternalWindow->getChildren().push_back(TheGLViewport);
       MainInternalWindow->setLayout(MainInternalWindowLayout);
       MainInternalWindow->setBackgrounds(MainInternalWindowBackground);
       MainInternalWindow->setAlignmentInDrawingSurface(Vec2f(0.5f,0.5f));
       MainInternalWindow->setScalingInDrawingSurface(Vec2f(1.0f,1.0f));
       MainInternalWindow->setDrawTitlebar(false);
       MainInternalWindow->setResizable(false);
    endEditCP(MainInternalWindow, InternalWindow::ChildrenFieldMask | InternalWindow::LayoutFieldMask | InternalWindow::BackgroundsFieldMask | InternalWindow::AlignmentInDrawingSurfaceFieldMask | InternalWindow::ScalingInDrawingSurfaceFieldMask | InternalWindow::DrawTitlebarFieldMask | InternalWindow::ResizableFieldMask);

    // Create the Drawing Surface
    UIDrawingSurfacePtr TutorialDrawingSurface = UIDrawingSurface::create();
    beginEditCP(TutorialDrawingSurface, UIDrawingSurface::GraphicsFieldMask | UIDrawingSurface::EventProducerFieldMask);
        TutorialDrawingSurface->setGraphics(TutorialGraphics);
        TutorialDrawingSurface->setEventProducer(TutorialWindowEventProducer);
    endEditCP(TutorialDrawingSurface, UIDrawingSurface::GraphicsFieldMask | UIDrawingSurface::EventProducerFieldMask);
    
    TutorialDrawingSurface->openWindow(MainInternalWindow);

    // Create the UI Foreground Object
    UIForegroundPtr TutorialUIForeground = osg::UIForeground::create();

    beginEditCP(TutorialUIForeground, UIForeground::DrawingSurfaceFieldMask);
        TutorialUIForeground->setDrawingSurface(TutorialDrawingSurface);
    endEditCP(TutorialUIForeground, UIForeground::DrawingSurfaceFieldMask);

    ViewportPtr TutorialViewport = mgr->getWindow()->getPort(0);
    beginEditCP(TutorialViewport, Viewport::ForegroundsFieldMask);
        TutorialViewport->getForegrounds().push_back(TutorialUIForeground);
    beginEditCP(TutorialViewport, Viewport::ForegroundsFieldMask);

    //Attach the Slider Listeners
    BlendAmountSliderChangeListener UpperAnimationSliderListener(TheSkeletonBlendedAnimation, 0, UpperAnimationSlider);
    UpperAnimationSlider->addChangeListener(&UpperAnimationSliderListener);
    
    BlendAmountSliderChangeListener LowerAnimationSliderListener(TheSkeletonBlendedAnimation, 1, LowerAnimationSlider);
    LowerAnimationSlider->addChangeListener(&LowerAnimationSliderListener);

    //Animation Advancer
    TheAnimationAdvancer = ElapsedTimeAnimationAdvancer::create();
    beginEditCP(TheAnimationAdvancer);
    ElapsedTimeAnimationAdvancer::Ptr::dcast(TheAnimationAdvancer)->setStartTime( 0.0 );


    beginEditCP(TheAnimationAdvancer);

        //Create the Documentation
        SimpleScreenDoc TheSimpleScreenDoc(&sceneManager, TutorialWindow);
    
    // Show the whole Scene
    mgr->showAll();
    TheAnimationAdvancer->start();

     //Show window
    Vec2f WinSize(TutorialWindowEventProducer->getDesktopSize() * 0.85f);
    Pnt2f WinPos((TutorialWindowEventProducer->getDesktopSize() - WinSize) *0.5);
    TutorialWindowEventProducer->openWindow(WinPos,
                        WinSize,
                                        "23BlendXMLAnimations");

    //Enter main Loop
    TutorialWindowEventProducer->mainLoop();

    osgExit();

    return 0;
}

// redraw the window
void display(void)
{
    mgr->redraw();
}

// React to size changes
void reshape(Vec2f Size)
{
    mgr->resize(Size.x(), Size.y());
}

NodePtr createScene(void)
{
    //Make Main Scene Node
    NodePtr scene = osg::Node::create();
    osg::ComponentTransformPtr Trans;
    Trans = osg::ComponentTransform::create();
    osg::setName(Trans, std::string("MainTransformationCore"));
    beginEditCP(scene, Node::CoreFieldMask | Node::ChildrenFieldMask);
        scene->setCore(Trans);

        for (int i(0); i < SkeletonNodes.size(); ++i)
        {
            scene->addChild(SkeletonNodes[i]);
        }

        for (int i(0); i < UnboundGeometries.size(); ++i)
        {
            scene->addChild(UnboundGeometries[i]);
        }

        for (int i(0); i < MeshNodes.size(); ++i)
        {
            scene->addChild(MeshNodes[i]);
        }

    endEditCP  (scene, Node::CoreFieldMask | Node::ChildrenFieldMask);

    return scene;
}


ComponentPtr createGLPanel(void)
{
    //Create the nessicary parts for a viewport

    //Camera Beacon
    Matrix TransformMatrix;
    TransformMatrix.setTranslate(0.0f,0.0f, 0.0f);
    TransformPtr CameraBeaconTransform = Transform::create();
    beginEditCP(CameraBeaconTransform, Transform::MatrixFieldMask);
        CameraBeaconTransform->setMatrix(TransformMatrix);
    endEditCP(CameraBeaconTransform, Transform::MatrixFieldMask);

    NodePtr CameraBeaconNode = Node::create();
    beginEditCP(CameraBeaconNode, Node::CoreFieldMask);
        CameraBeaconNode->setCore(CameraBeaconTransform);
    endEditCP(CameraBeaconNode, Node::CoreFieldMask);

    //Light Beacon
    Matrix LightTransformMatrix;
    LightTransformMatrix.setTranslate(0.0f,0.0f, 0.0f);
    TransformPtr LightBeaconTransform = Transform::create();
    beginEditCP(LightBeaconTransform, Transform::MatrixFieldMask);
        LightBeaconTransform->setMatrix(TransformMatrix);
    endEditCP(LightBeaconTransform, Transform::MatrixFieldMask);

    NodePtr LightBeaconNode = Node::create();
    beginEditCP(LightBeaconNode, Node::CoreFieldMask);
        LightBeaconNode->setCore(CameraBeaconTransform);
    endEditCP(LightBeaconNode, Node::CoreFieldMask);
    
    //Light Node
    DirectionalLightPtr TheDirectionLight = DirectionalLight::create();
    beginEditCP(TheDirectionLight, DirectionalLight::DirectionFieldMask);
        TheDirectionLight->setDirection(0.0f,1.0f,0.0f);
    endEditCP(TheDirectionLight, DirectionalLight::DirectionFieldMask);

    NodePtr LightNode = Node::create();
    beginEditCP(LightNode, Node::CoreFieldMask | Node::ChildrenFieldMask);
        LightNode->setCore(TheDirectionLight);
        LightNode->addChild(createScene());
    endEditCP(LightNode, Node::CoreFieldMask | Node::ChildrenFieldMask);

    // Make Torus Node (creates Torus in background of scene)
    NodePtr GeometryNode = makeTorus(.5, 2, 32, 32);

    // Make Main Scene Node and add the Torus
    NodePtr DefaultRootNode = osg::Node::create();
    beginEditCP(DefaultRootNode, Node::CoreFieldMask | Node::ChildrenFieldMask);
        DefaultRootNode->setCore(osg::Group::create());
        DefaultRootNode->addChild(CameraBeaconNode);
        DefaultRootNode->addChild(LightBeaconNode);
        DefaultRootNode->addChild(LightNode);
    endEditCP(DefaultRootNode, Node::CoreFieldMask | Node::ChildrenFieldMask);

    //Camera
    PerspectiveCameraPtr DefaultCamera = PerspectiveCamera::create();
     beginEditCP(DefaultCamera);
         DefaultCamera->setBeacon(CameraBeaconNode);
         DefaultCamera->setFov   (deg2rad(60.f));
         DefaultCamera->setNear  (0.1f);
         DefaultCamera->setFar   (100.f);
     endEditCP(DefaultCamera);

    //Background
    GradientBackgroundPtr DefaultBackground = GradientBackground::create();
    beginEditCP(DefaultBackground, GradientBackground::ColorFieldMask | GradientBackground::PositionFieldMask);
        DefaultBackground->addLine(Color3f(0.0f,0.0f,0.0f), 0.0f);
        DefaultBackground->addLine(Color3f(0.0f,0.0f,1.0f), 1.0f);
    endEditCP(DefaultBackground, GradientBackground::ColorFieldMask | GradientBackground::PositionFieldMask);
    
    //Viewport
    ViewportPtr DefaultViewport = Viewport::create();
    beginEditCP(DefaultViewport);
        DefaultViewport->setCamera                  (DefaultCamera);
        DefaultViewport->setRoot                    (DefaultRootNode);
        DefaultViewport->setSize                    (0.0f,0.0f, 1.0f,1.0f);
        DefaultViewport->setBackground              (DefaultBackground);
    endEditCP(DefaultViewport);

    //GL Viewport Component

    GLViewportPtr TheGLViewport = GLViewport::create();
    beginEditCP(TheGLViewport, GLViewport::PortFieldMask | GLViewport::PreferredSizeFieldMask | GLViewport::BordersFieldMask);
        TheGLViewport->setPort(DefaultViewport);
        TheGLViewport->setPreferredSize(Vec2f(1024.0f,768.0f));
    endEditCP(TheGLViewport, GLViewport::PortFieldMask | GLViewport::PreferredSizeFieldMask | GLViewport::BordersFieldMask);
    
    TheGLViewport->showAll();

    return TheGLViewport;
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


