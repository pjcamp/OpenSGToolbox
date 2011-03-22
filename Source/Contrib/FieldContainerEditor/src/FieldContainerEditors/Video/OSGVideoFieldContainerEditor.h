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

#ifndef _OSGVIDEOFIELDCONTAINEREDITOR_H_
#define _OSGVIDEOFIELDCONTAINEREDITOR_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGVideoFieldContainerEditorBase.h"
#include "OSGSplitPanelFields.h"
#include "OSGChangeEventDetailsFields.h"
#include "OSGActionEventDetailsFields.h"
#include "OSGVideoWrapperFields.h"
#include "OSGButtonFields.h"
#include "OSGPanelFields.h"
#include "OSGLabelFields.h"
#include "OSGSliderFields.h"
#include "OSGMaterialLayerFields.h"
#include "OSGVideoEventDetailsFields.h"
#include "OSGUpdateEventDetailsFields.h"

OSG_BEGIN_NAMESPACE

/*! \brief VideoFieldContainerEditor class. See \ref
           PageContribFieldContainerEditorVideoFieldContainerEditor for a description.
*/

class OSG_CONTRIBFIELDCONTAINEREDITOR_DLLMAPPING VideoFieldContainerEditor : public VideoFieldContainerEditorBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef VideoFieldContainerEditorBase Inherited;
    typedef VideoFieldContainerEditor     Self;

    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    virtual void changed(ConstFieldMaskArg whichField,
                         UInt32            origin,
                         BitVector         details    );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual void dump(      UInt32     uiIndent = 0,
                      const BitVector  bvFlags  = 0) const;

    /*! \}                                                                 */
    virtual const std::vector<const FieldContainerType*>& getEditableTypes(void) const;

    virtual bool attachFieldContainer(FieldContainer* fc);
    virtual bool dettachFieldContainer(void);

    //Return true if a viewport should always force the height of this
    //Scrollable to match the height of the viewport.
    virtual bool getScrollableTracksViewportHeight(void);

    //Return true if a viewport should always force the width of this
    //Scrollable to match the width of the viewport.
    virtual bool getScrollableTracksViewportWidth(void);

    //Return true if a viewport should always force the height of this
    //Scrollable to be at at least the height of the viewport.
    virtual bool getScrollableHeightMinTracksViewport(void);

    //Return true if a viewport should always force the width of this
    //Scrollable to be at at least the width of the viewport.
    virtual bool getScrollableWidthMinTracksViewport(void);
    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in VideoFieldContainerEditorBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    VideoFieldContainerEditor(void);
    VideoFieldContainerEditor(const VideoFieldContainerEditor &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~VideoFieldContainerEditor(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Class Specific                             */
    /*! \{                                                                 */
    void onCreate(const VideoFieldContainerEditor *Id = NULL);
    void onDestroy();
    
    /*! \}                                                                 */
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

    virtual void resolveLinks(void);

    /*! \}                                                                 */
    static std::vector<const FieldContainerType*> _EditableTypes;
    PanelTransitPtr createVideoPreviewPanel(void);
    void updateVideoPreviewPanel(void);
    void updateTimeInterface(void);

    SplitPanelRecPtr    _MainSplitPanel;
    VideoWrapperRecPtr  _AttachedVideo;
    PanelRecPtr         _VideoPanel;
    MaterialLayerRecPtr _VideoMaterialLayer;
    LabelRecPtr         _FileNameLabel;
    LabelRecPtr         _PlaybackTimeLabel;
    LabelRecPtr         _TotalTimeLabel;
    ButtonRecPtr        _PlayPauseButton;
    ButtonRecPtr        _StopButton;
    SliderRecPtr        _LocationSlider;

    void attachVideo(VideoWrapper* const TheVideo);
    void dettachVideo(void);

    void handlePlayPauseAction(ActionEventDetails* const details);
    void handleStopAction(ActionEventDetails* const details);
    void handleLoadAction(ActionEventDetails* const details);
    void handlePlaybackLocationStateChanged(ChangeEventDetails* const details);

    void handleVideoPlayed(VideoEventDetails* const details);
    void handleVideoStopped(VideoEventDetails* const details);
    void handleVideoPaused(VideoEventDetails* const details);
    void handleVideoUnpaused(VideoEventDetails* const details);
    void handleVideoSeeked(VideoEventDetails* const details);
    void handleVideoEnded(VideoEventDetails* const details);
    void handleVideoCycled(VideoEventDetails* const details);
    void handleVideoOpened(VideoEventDetails* const details);
    void handleVideoClosed(VideoEventDetails* const details);
    void handleVideoPlayingUpdate(UpdateEventDetails* const details);

    boost::signals2::connection _PlayPauseActionConnection,
                                _StopActionConnection,
                                _LoadActionConnection,
                                _PlaybackLocationStateChangedConnection,
                                _VideoPlayedConnection,
                                _VideoStoppedConnection,
                                _VideoEndedConnection,
                                _VideoPausedConnection,
                                _VideoUnpausedConnection,
                                _VideoSeekedConnection,
                                _VideoCycledConnection,
                                _VideoOpenedConnection,
                                _VideoClosedConnection,
                                _VideoPlayingUpdateConnection;
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class VideoFieldContainerEditorBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const VideoFieldContainerEditor &source);
};

typedef VideoFieldContainerEditor *VideoFieldContainerEditorP;

OSG_END_NAMESPACE

#include "OSGVideoFieldContainerEditorBase.inl"
#include "OSGVideoFieldContainerEditor.inl"

#endif /* _OSGVIDEOFIELDCONTAINEREDITOR_H_ */
