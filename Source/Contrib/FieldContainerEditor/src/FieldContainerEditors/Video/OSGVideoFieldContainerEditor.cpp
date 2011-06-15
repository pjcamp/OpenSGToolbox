/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 * contact: David Kabala (djkabala@gmail.com)                                *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                License                                    *
 *                                                                           *
 * This library is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU Library General Public License as published    *
 * by the Free Software Foundation, version 2.                               *
 *                                                                           *
 * This library is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of                *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 * Library General Public License for more details.                          *
 *                                                                           *
 * You should have received a copy of the GNU Library General Public         *
 * License along with this library; if not, write to the Free Software       *
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.                 *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                Changes                                    *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
\*---------------------------------------------------------------------------*/

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"

#include "OSGVideoFieldContainerEditor.h"

#include "OSGFieldContainerFactory.h"
#include "OSGFieldContainerEditorFactory.h"
#include "OSGFieldEditorFactory.h"
#include "OSGSpringLayout.h"
#include "OSGSpringLayoutConstraints.h"
#include "OSGSplitPanel.h"
#include "OSGUIDrawObjectCanvas.h"
#include "OSGVideoWrapper.h"
#include "OSGButton.h"
#include "OSGSlider.h"
#include "OSGPanel.h"
#include "OSGLabel.h"
#include "OSGScrollPanel.h"
#include "OSGBorderLayout.h"
#include "OSGBorderLayoutConstraints.h"
#include "OSGChangeEventDetails.h"
#include "OSGWindowEventProducer.h"
#include "OSGInternalWindow.h"
#include "OSGUIDrawingSurface.h"
#include "OSGMaterialLayer.h"
#include "OSGChunkMaterial.h"
#include "OSGFilePathAttachment.h"

#include <boost/format.hpp>

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGVideoFieldContainerEditorBase.cpp file.
// To modify it, please change the .fcd file (OSGVideoFieldContainerEditor.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

std::vector<const FieldContainerType*>
VideoFieldContainerEditor::_EditableTypes = std::vector<const FieldContainerType*>();

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void VideoFieldContainerEditor::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
        //Fill in all of the editable types
        UInt32 NumTypes(FieldContainerFactory::the()->getNumTypes());
        UInt32 FoundTypes(0);
        FieldContainerType* type;
        for(UInt32 i(0) ; FoundTypes<NumTypes; ++i)
        {
            type = FieldContainerFactory::the()->findType(i);
            if(type != NULL)
            {
                ++FoundTypes;
                if(type->isDerivedFrom(VideoWrapper::getClassType()))
                {
                    _EditableTypes.push_back(type);
                    FieldContainerEditorFactory::the()->setDefaultEditor(type,
                                                                         &getClassType());
                    FieldContainerEditorFactory::the()->setEditorType(type,
                                                                      &getClassType(),
                                                                      "VideoWrapper");
                }
            }
        }
    }
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

const std::vector<const FieldContainerType*>& VideoFieldContainerEditor::getEditableTypes(void) const
{
    return _EditableTypes;
}

bool VideoFieldContainerEditor::attachFieldContainer(FieldContainer* fc)
{
    //Check that this is a valid FieldContainer
    if(!Inherited::attachFieldContainer(fc))
    {
        return false;
    }

    //Attach the video
    attachVideo(dynamic_cast<VideoWrapper*>(fc));
    return true;
}

bool VideoFieldContainerEditor::dettachFieldContainer(void)
{
    //Dettach the video
    dettachVideo();

    return Inherited::dettachFieldContainer();
}

bool VideoFieldContainerEditor::getScrollableTracksViewportHeight(void)
{
    return true;
}

bool VideoFieldContainerEditor::getScrollableTracksViewportWidth(void)
{
    return true;
}

bool VideoFieldContainerEditor::getScrollableHeightMinTracksViewport(void)
{
    return true;
}

bool VideoFieldContainerEditor::getScrollableWidthMinTracksViewport(void)
{
    return true;
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

void VideoFieldContainerEditor::onCreate(const VideoFieldContainerEditor *Id)
{
    Inherited::onCreate(Id);

    if(GlobalSystemState != Startup)
    {
        //Create the Panel for the video preview
        PanelRecPtr VideoPanel = createVideoPreviewPanel();

        ScrollPanelRecPtr EditorScrollPanel = ScrollPanel::create();
        EditorScrollPanel->setViewComponent(_GenericEditor);

        _MainSplitPanel = SplitPanel::create();
        _MainSplitPanel->setOrientation(SplitPanel::VERTICAL_ORIENTATION);
        _MainSplitPanel->setDividerPosition(350.0f); 
        _MainSplitPanel->setMinComponent(VideoPanel);
        _MainSplitPanel->setMaxComponent(EditorScrollPanel);

        //Add the SplitPanel
        pushToChildren(_MainSplitPanel);

        //Set the layout constraints for the SplitPanel
        BorderLayoutConstraintsRecPtr CenterConstraints = BorderLayoutConstraints::create();
        CenterConstraints->setRegion(BorderLayoutConstraints::BORDER_CENTER);
        _MainSplitPanel->setConstraints(CenterConstraints);

        //Set the layout
        BorderLayoutRecPtr MainLayout = BorderLayout::create();
        setLayout(MainLayout);
    }
}

void VideoFieldContainerEditor::onDestroy()
{
}

void VideoFieldContainerEditor::resolveLinks(void)
{
    Inherited::resolveLinks();

    _PlayPauseActionConnection.disconnect();
    _StopActionConnection.disconnect();
    _LoadActionConnection.disconnect();
    dettachVideo();

    _MainSplitPanel = NULL;
    _FileNameLabel = NULL;
    _VideoPanel = NULL;
    _VideoMaterialLayer = NULL;
    _TotalTimeLabel = NULL;
    _PlaybackTimeLabel = NULL;
    _PlayPauseButton = NULL;
    _StopButton = NULL;
    _LocationSlider = NULL;
    _AttachedVideo = NULL;
}

void VideoFieldContainerEditor::updateVideoPreviewPanel(void)
{
    if(_AttachedVideo != NULL)
    {
        _PlayPauseButton->setEnabled(true);
        _LocationSlider->setEnabled(true);

        //_FileNameLabel->setText(_AttachedVideo->getFile().filename());

        updateTimeInterface();
    }
    else
    {
        _FileNameLabel->setText("<<No file loaded>>");
        _PlayPauseButton->setEnabled(false);
        _StopButton->setEnabled(false);
        _LocationSlider->setEnabled(false);
    }
}

void VideoFieldContainerEditor::attachVideo(VideoWrapper* const TheVideo)
{
    if(_AttachedVideo != NULL)
    {
        dettachVideo();
    }

    _AttachedVideo = TheVideo;

    dynamic_cast<ChunkMaterial*>(_VideoMaterialLayer->getMaterial())->addChunk(TheVideo);

    if(_AttachedVideo != NULL)
    {
        _AttachedVideo->setMinFilter(GL_NEAREST);
        _AttachedVideo->setMagFilter(GL_LINEAR);
        _AttachedVideo->setWrapS(GL_CLAMP_TO_EDGE);
        _AttachedVideo->setWrapT(GL_CLAMP_TO_EDGE);   

        _LocationSlider->getRangeModel()->setRangeProperties(0, 0, 0, 1000, false);

        _VideoPlayedConnection = _AttachedVideo->connectStarted(boost::bind(&VideoFieldContainerEditor::handleVideoPlayed, this,   _1));
        _VideoStoppedConnection = _AttachedVideo->connectStopped(boost::bind(&VideoFieldContainerEditor::handleVideoStopped, this,  _1));
        _VideoPausedConnection = _AttachedVideo->connectPaused(boost::bind(&VideoFieldContainerEditor::handleVideoPaused, this,   _1));
        _VideoUnpausedConnection = _AttachedVideo->connectUnpaused(boost::bind(&VideoFieldContainerEditor::handleVideoUnpaused, this, _1));
        _VideoSeekedConnection = _AttachedVideo->connectSeeked(boost::bind(&VideoFieldContainerEditor::handleVideoSeeked, this, _1));
        _VideoEndedConnection = _AttachedVideo->connectEnded(boost::bind(&VideoFieldContainerEditor::handleVideoEnded, this, _1));
        _VideoCycledConnection = _AttachedVideo->connectCycled(boost::bind(&VideoFieldContainerEditor::handleVideoCycled, this, _1));
        _VideoOpenedConnection = _AttachedVideo->connectOpened(boost::bind(&VideoFieldContainerEditor::handleVideoOpened, this, _1));
        _VideoClosedConnection = _AttachedVideo->connectClosed(boost::bind(&VideoFieldContainerEditor::handleVideoClosed, this, _1));
    }
    updateVideoPreviewPanel();
}

void VideoFieldContainerEditor::dettachVideo(void)
{
    if(_AttachedVideo != NULL)
    {
        //Stop the video
        _AttachedVideo->stop();
    }

    _AttachedVideo = NULL;

    _VideoPlayedConnection.disconnect();
    _VideoStoppedConnection.disconnect();
    _VideoPausedConnection.disconnect();
    _VideoUnpausedConnection.disconnect();
    _VideoSeekedConnection.disconnect();
    _VideoEndedConnection.disconnect();
    _VideoCycledConnection.disconnect();
    _VideoOpenedConnection.disconnect();
    _VideoClosedConnection.disconnect();
    _VideoPlayingUpdateConnection.disconnect();
}

PanelTransitPtr VideoFieldContainerEditor::createVideoPreviewPanel(void)
{
    ChunkMaterialUnrecPtr VideoMaterial = ChunkMaterial::create();

    //Video MaterialLayer
    _VideoMaterialLayer = MaterialLayer::create();
    _VideoMaterialLayer->setMaterial(VideoMaterial);

    //Video Panel
    _VideoPanel = Panel::createEmpty();
    _VideoPanel->setBackgrounds(_VideoMaterialLayer);

    //Filename Label
    _FileNameLabel = Label::create();
    _FileNameLabel->setAlignment(Vec2f(0.5f, 0.5f));

    //Total time Label
    _TotalTimeLabel = Label::create();
    _TotalTimeLabel->setAlignment(Vec2f(0.0f, 1.0f));
    _TotalTimeLabel->setBorders(NULL);
    _TotalTimeLabel->setBackgrounds(NULL);
    _TotalTimeLabel->setPreferredSize(Vec2f(50.0f,_TotalTimeLabel->getPreferredSize().y()));

    //Playback time Label
    _PlaybackTimeLabel = Label::create();
    _PlaybackTimeLabel->setAlignment(Vec2f(1.0f, 1.0f));
    _PlaybackTimeLabel->setPreferredSize(Vec2f(50.0f,_TotalTimeLabel->getPreferredSize().y()));
    _PlaybackTimeLabel->setBorders(NULL);
    _PlaybackTimeLabel->setBackgrounds(NULL);

    LabelRecPtr TimeSeparatorLabel = Label::create();
    TimeSeparatorLabel->setAlignment(Vec2f(0.5f, 1.0f));
    TimeSeparatorLabel->setPreferredSize(Vec2f(8.0f,_TotalTimeLabel->getPreferredSize().y()));
    TimeSeparatorLabel->setBorders(NULL);
    TimeSeparatorLabel->setBackgrounds(NULL);
    TimeSeparatorLabel->setText("/");

    //PlayPause Button
    _PlayPauseButton = Button::create();
    _PlayPauseButton->setText("Play");
    _PlayPauseButton->setPreferredSize(Vec2f(40.0f,40.0f));
    _PlayPauseButton->connectActionPerformed(boost::bind(&VideoFieldContainerEditor::handlePlayPauseAction, this,   _1));

    //Stop Button
    _StopButton = Button::create();
    _StopButton->setText("Stop");
    _StopButton->setPreferredSize(Vec2f(40.0f,40.0f));
    _StopButton->connectActionPerformed(boost::bind(&VideoFieldContainerEditor::handleStopAction, this,   _1));

    //Load Button
    ButtonRecPtr LoadButton = Button::create();
    LoadButton->setText("Load");
    LoadButton->setPreferredSize(Vec2f(40.0f,40.0f));
    LoadButton->connectActionPerformed(boost::bind(&VideoFieldContainerEditor::handleLoadAction, this,   _1));

    //Playback position slider
    _LocationSlider = Slider::create();
    _LocationSlider->setOrientation(Slider::HORIZONTAL_ORIENTATION);
    _LocationSlider->setDrawLabels(false);
    _LocationSlider->setDrawMajorTicks(false);
    _LocationSlider->setDrawMinorTicks(false);
    _LocationSlider->setBorders(NULL);
    _LocationSlider->setBackgrounds(NULL);
    //_LocationSlider->getKnobButton()->setPreferredSize(Vec2f(15.0f, 8.0f));
    _LocationSlider->getRangeModel()->connectStateChanged(boost::bind(&VideoFieldContainerEditor::handlePlaybackLocationStateChanged, this,   _1));


    //Layout
    PanelRecPtr VideoPanel = Panel::createEmpty();
    SpringLayoutRecPtr MainLayout = SpringLayout::create();


    //Video Panel
    MainLayout->putConstraint(SpringLayoutConstraints::EAST_EDGE, _VideoPanel, 0,
                              SpringLayoutConstraints::EAST_EDGE, VideoPanel);
    MainLayout->putConstraint(SpringLayoutConstraints::WEST_EDGE, _VideoPanel, 0,
                              SpringLayoutConstraints::WEST_EDGE, VideoPanel);
    MainLayout->putConstraint(SpringLayoutConstraints::NORTH_EDGE, _VideoPanel, 0,
                              SpringLayoutConstraints::NORTH_EDGE, VideoPanel);
    MainLayout->putConstraint(SpringLayoutConstraints::SOUTH_EDGE, _VideoPanel, -1,
                              SpringLayoutConstraints::NORTH_EDGE, _PlayPauseButton);

    //Filename Label
    MainLayout->putConstraint(SpringLayoutConstraints::EAST_EDGE, _FileNameLabel, 0,
                              SpringLayoutConstraints::EAST_EDGE, VideoPanel);
    MainLayout->putConstraint(SpringLayoutConstraints::WEST_EDGE, _FileNameLabel, 0,
                              SpringLayoutConstraints::WEST_EDGE, VideoPanel);
    MainLayout->putConstraint(SpringLayoutConstraints::NORTH_EDGE, _FileNameLabel, 0,
                              SpringLayoutConstraints::NORTH_EDGE, VideoPanel);

    //Play/pause Button
    MainLayout->putConstraint(SpringLayoutConstraints::EAST_EDGE, _PlayPauseButton, -3,
                              SpringLayoutConstraints::WEST_EDGE, _StopButton);
    MainLayout->putConstraint(SpringLayoutConstraints::SOUTH_EDGE, _PlayPauseButton, 0,
                              SpringLayoutConstraints::SOUTH_EDGE, VideoPanel);

    //Stop Button
    MainLayout->putConstraint(SpringLayoutConstraints::EAST_EDGE, _StopButton, -3,
                              SpringLayoutConstraints::WEST_EDGE, _LocationSlider);
    MainLayout->putConstraint(SpringLayoutConstraints::SOUTH_EDGE, _StopButton, 0,
                              SpringLayoutConstraints::SOUTH_EDGE, VideoPanel);

    //Playback Slider
    MainLayout->putConstraint(SpringLayoutConstraints::HORIZONTAL_CENTER_EDGE, _LocationSlider, 0,
                              SpringLayoutConstraints::HORIZONTAL_CENTER_EDGE, VideoPanel);
    MainLayout->putConstraint(SpringLayoutConstraints::SOUTH_EDGE, _LocationSlider, 0,
                              SpringLayoutConstraints::SOUTH_EDGE, VideoPanel);

    //Total video length label
    MainLayout->putConstraint(SpringLayoutConstraints::SOUTH_EDGE, _TotalTimeLabel, 0,
                              SpringLayoutConstraints::SOUTH_EDGE, LoadButton);
    MainLayout->putConstraint(SpringLayoutConstraints::EAST_EDGE, _TotalTimeLabel, 0,
                              SpringLayoutConstraints::EAST_EDGE, _LocationSlider);

    //Separator label
    MainLayout->putConstraint(SpringLayoutConstraints::SOUTH_EDGE, TimeSeparatorLabel, 0,
                              SpringLayoutConstraints::SOUTH_EDGE, LoadButton);
    MainLayout->putConstraint(SpringLayoutConstraints::EAST_EDGE, TimeSeparatorLabel, -2,
                              SpringLayoutConstraints::WEST_EDGE, _TotalTimeLabel);

    //Playback time label
    MainLayout->putConstraint(SpringLayoutConstraints::SOUTH_EDGE, _PlaybackTimeLabel, 0,
                              SpringLayoutConstraints::SOUTH_EDGE, LoadButton);
    MainLayout->putConstraint(SpringLayoutConstraints::EAST_EDGE, _PlaybackTimeLabel, -2,
                              SpringLayoutConstraints::WEST_EDGE, TimeSeparatorLabel);

    //Load Button
    MainLayout->putConstraint(SpringLayoutConstraints::WEST_EDGE, LoadButton, 3,
                              SpringLayoutConstraints::EAST_EDGE, _LocationSlider);
    MainLayout->putConstraint(SpringLayoutConstraints::SOUTH_EDGE, LoadButton, 0,
                              SpringLayoutConstraints::SOUTH_EDGE, VideoPanel);

    //Main Video Panel
    VideoPanel->setLayout(MainLayout);

    VideoPanel->pushToChildren(_VideoPanel);
    VideoPanel->pushToChildren(_FileNameLabel);
    VideoPanel->pushToChildren(_PlayPauseButton);
    VideoPanel->pushToChildren(_StopButton);
    VideoPanel->pushToChildren(LoadButton);
    VideoPanel->pushToChildren(_PlaybackTimeLabel);
    VideoPanel->pushToChildren(TimeSeparatorLabel);
    VideoPanel->pushToChildren(_TotalTimeLabel);
    VideoPanel->pushToChildren(_LocationSlider);

    return PanelTransitPtr(VideoPanel);
}

void VideoFieldContainerEditor::handlePlayPauseAction(ActionEventDetails* const details)
{
    if(_AttachedVideo != NULL)
    {
        if(!_AttachedVideo->isPlaying())
        {
            //Play the video
            _AttachedVideo->play();
        }
        else
        {
            //Toggle Pause
            _AttachedVideo->pauseToggle();
        }
    }
}

void VideoFieldContainerEditor::handleStopAction(ActionEventDetails* const details)
{
    if(_AttachedVideo != NULL)
    {
        //Stop the video
        _AttachedVideo->stop();
    }
}

void VideoFieldContainerEditor::handleLoadAction(ActionEventDetails* const details)
{
    if(_AttachedVideo != NULL)
    {
        //Stop the video
        _AttachedVideo->stop();
    }

    //Have the user select the file to import
    std::vector<WindowEventProducer::FileDialogFilter> Filters;

    Filters.push_back(WindowEventProducer::FileDialogFilter("All (*.*)","*"));

    std::vector<BoostPath> FilesToOpen;
    FilesToOpen =
        getParentWindow()->getParentDrawingSurface()->getEventProducer()->openFileDialog("Load a video file.",
                                                                          Filters,
                                                                          BoostPath("."),
                                                                          false);

    if(FilesToOpen.size() > 0)
    {
        _AttachedVideo->open(FilesToOpen[0],getParentWindow()->getParentDrawingSurface()->getEventProducer());
        if(_AttachedVideo->hasAudio())
        {
            _AttachedVideo->enableAudio();
            _AttachedVideo->setAudioVolume(0.5f);
        }
    }
    updateVideoPreviewPanel();
}

void VideoFieldContainerEditor::handlePlaybackLocationStateChanged(ChangeEventDetails* const details)
{
    BoundedRangeModel* const Model(dynamic_cast<BoundedRangeModel* const>(details->getSource()));

    if(_AttachedVideo != NULL &&
       _AttachedVideo->isPlaying() &&
       !Model->getValueIsAdjusting())
    {
        _AttachedVideo->pause();
        //Move the video playback position
        _AttachedVideo->seek(static_cast<Real32>(Model->getValue())/1000.0f * _AttachedVideo->getDuration());
    }
}

void VideoFieldContainerEditor::handleVideoPlayed(VideoEventDetails* const details)
{
    //Make sure the update producer is attached
    _AttachedVideo->attachUpdateProducer(getParentWindow()->getParentDrawingSurface()->getEventProducer());

    //Play/pause button
    _PlayPauseButton->setText("Pause");

    //Stop Button
    _StopButton->setEnabled(true);
    _LocationSlider->getRangeModel()->setRangeProperties(_AttachedVideo->getPosition()/_AttachedVideo->getDuration() * 1000.0f,
                                                             0, 0, 1000, true);

    _VideoPlayingUpdateConnection =
        getParentWindow()->getParentDrawingSurface()->getEventProducer()->connectUpdate(boost::bind(&VideoFieldContainerEditor::handleVideoPlayingUpdate, this,   _1));
}

void VideoFieldContainerEditor::handleVideoStopped(VideoEventDetails* const details)
{
    _PlayPauseButton->setText("Play");
    _StopButton->setEnabled(false);
    updateTimeInterface();
    _VideoPlayingUpdateConnection.disconnect();
}

void VideoFieldContainerEditor::handleVideoPaused(VideoEventDetails* const details)
{
    _PlayPauseButton->setText("Play");

    _VideoPlayingUpdateConnection.disconnect();
}

void VideoFieldContainerEditor::handleVideoUnpaused(VideoEventDetails* const details)
{
    _PlayPauseButton->setText("Pause");

    _VideoPlayingUpdateConnection =
        getParentWindow()->getParentDrawingSurface()->getEventProducer()->connectUpdate(boost::bind(&VideoFieldContainerEditor::handleVideoPlayingUpdate, this,   _1));
}

void VideoFieldContainerEditor::handleVideoSeeked(VideoEventDetails* const details)
{
    updateTimeInterface();
}

void VideoFieldContainerEditor::handleVideoEnded(VideoEventDetails* const details)
{
    //Move the video back to the beginning
    _AttachedVideo->stop();

    _PlayPauseButton->setText("Play");
    _StopButton->setEnabled(false);

    _VideoPlayingUpdateConnection.disconnect();
}

void VideoFieldContainerEditor::handleVideoCycled(VideoEventDetails* const details)
{
}

void VideoFieldContainerEditor::handleVideoOpened(VideoEventDetails* const details)
{
}

void VideoFieldContainerEditor::handleVideoClosed(VideoEventDetails* const details)
{
    _VideoPlayingUpdateConnection.disconnect();
}

void VideoFieldContainerEditor::updateTimeInterface(void)
{
    if(_AttachedVideo != NULL)
    {
        Real32 Time(_AttachedVideo->getPosition());

        UInt32 Min(osgFloor(Time/60.0f)),
               Sec(osgFloor(Time - Min*60.0f));
        boost::format TimeFormatter("%d:%02d");
        _PlaybackTimeLabel->setText(boost::str(TimeFormatter % Min  % Sec ));

        Time = _AttachedVideo->getDuration();
        Min  = osgFloor(Time/60.0f);
        Sec  = osgFloor(Time - Min*60.0f);
        _TotalTimeLabel->setText(boost::str(TimeFormatter % Min  % Sec ));

        _LocationSlider->getRangeModel()->setRangeProperties(_AttachedVideo->getPosition()/_AttachedVideo->getDuration() * 1000.0f,
                                                             0, 0, 1000, true);
    }
    else
    {
        _TotalTimeLabel->setText("");
        _PlaybackTimeLabel->setText("");
        _LocationSlider->getRangeModel()->setValue(0);
    }
}

void VideoFieldContainerEditor::handleVideoPlayingUpdate(UpdateEventDetails* const details)
{
    updateTimeInterface();
}

/*----------------------- constructors & destructors ----------------------*/

VideoFieldContainerEditor::VideoFieldContainerEditor(void) :
    Inherited()
{
}

VideoFieldContainerEditor::VideoFieldContainerEditor(const VideoFieldContainerEditor &source) :
    Inherited(source)
{
}

VideoFieldContainerEditor::~VideoFieldContainerEditor(void)
{
}

/*----------------------------- class specific ----------------------------*/

void VideoFieldContainerEditor::changed(ConstFieldMaskArg whichField, 
                            UInt32            origin,
                            BitVector         details)
{
    Inherited::changed(whichField, origin, details);
}

void VideoFieldContainerEditor::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump VideoFieldContainerEditor NI" << std::endl;
}

OSG_END_NAMESPACE
