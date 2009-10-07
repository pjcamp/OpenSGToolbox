/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                          Authors: David Kabala                            *
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

/*****************************************************************************\
 *****************************************************************************
 **                                                                         **
 **                  This file is automatically generated.                  **
 **                                                                         **
 **          Any changes made to this file WILL be lost when it is          **
 **           regenerated, which can become necessary at any time.          **
 **                                                                         **
 **     Do not change this file, changes should be done in the derived      **
 **     class AbstractWindow!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <OpenSG/OSGConfig.h>

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &AbstractWindowBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 AbstractWindowBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

//! access the producer type of the class
inline
const EventProducerType &AbstractWindowBase::getProducerClassType(void)
{
    return _producerType;
}

//! access the producer type id of the class
inline
UInt32 AbstractWindowBase::getProducerClassTypeId(void)
{
    return _producerType.getId();
}


/*------------------------------ get -----------------------------------*/

//! Get the AbstractWindow::_sfDrawingSurface field.
inline
const SFUIDrawingSurfacePtr *AbstractWindowBase::getSFDrawingSurface(void) const
{
    return &_sfDrawingSurface;
}

//! Get the AbstractWindow::_sfDrawingSurface field.
inline
SFUIDrawingSurfacePtr *AbstractWindowBase::editSFDrawingSurface(void)
{
    return &_sfDrawingSurface;
}

//! Get the AbstractWindow::_sfClosable field.
inline
const SFBool *AbstractWindowBase::getSFClosable(void) const
{
    return &_sfClosable;
}

//! Get the AbstractWindow::_sfClosable field.
inline
SFBool *AbstractWindowBase::editSFClosable(void)
{
    return &_sfClosable;
}

//! Get the AbstractWindow::_sfIsClosed field.
inline
const SFBool *AbstractWindowBase::getSFIsClosed(void) const
{
    return &_sfIsClosed;
}

//! Get the AbstractWindow::_sfIsClosed field.
inline
SFBool *AbstractWindowBase::editSFIsClosed(void)
{
    return &_sfIsClosed;
}

//! Get the AbstractWindow::_sfIconable field.
inline
const SFBool *AbstractWindowBase::getSFIconable(void) const
{
    return &_sfIconable;
}

//! Get the AbstractWindow::_sfIconable field.
inline
SFBool *AbstractWindowBase::editSFIconable(void)
{
    return &_sfIconable;
}

//! Get the AbstractWindow::_sfIsIcon field.
inline
const SFBool *AbstractWindowBase::getSFIsIcon(void) const
{
    return &_sfIsIcon;
}

//! Get the AbstractWindow::_sfIsIcon field.
inline
SFBool *AbstractWindowBase::editSFIsIcon(void)
{
    return &_sfIsIcon;
}

//! Get the AbstractWindow::_sfMaximizable field.
inline
const SFBool *AbstractWindowBase::getSFMaximizable(void) const
{
    return &_sfMaximizable;
}

//! Get the AbstractWindow::_sfMaximizable field.
inline
SFBool *AbstractWindowBase::editSFMaximizable(void)
{
    return &_sfMaximizable;
}

//! Get the AbstractWindow::_sfIsMaximized field.
inline
const SFBool *AbstractWindowBase::getSFIsMaximized(void) const
{
    return &_sfIsMaximized;
}

//! Get the AbstractWindow::_sfIsMaximized field.
inline
SFBool *AbstractWindowBase::editSFIsMaximized(void)
{
    return &_sfIsMaximized;
}

//! Get the AbstractWindow::_sfPreviousPosition field.
inline
const SFPnt2f *AbstractWindowBase::getSFPreviousPosition(void) const
{
    return &_sfPreviousPosition;
}

//! Get the AbstractWindow::_sfPreviousPosition field.
inline
SFPnt2f *AbstractWindowBase::editSFPreviousPosition(void)
{
    return &_sfPreviousPosition;
}

//! Get the AbstractWindow::_sfPreviousSize field.
inline
const SFVec2f *AbstractWindowBase::getSFPreviousSize(void) const
{
    return &_sfPreviousSize;
}

//! Get the AbstractWindow::_sfPreviousSize field.
inline
SFVec2f *AbstractWindowBase::editSFPreviousSize(void)
{
    return &_sfPreviousSize;
}

//! Get the AbstractWindow::_sfResizable field.
inline
const SFBool *AbstractWindowBase::getSFResizable(void) const
{
    return &_sfResizable;
}

//! Get the AbstractWindow::_sfResizable field.
inline
SFBool *AbstractWindowBase::editSFResizable(void)
{
    return &_sfResizable;
}

//! Get the AbstractWindow::_sfIsSelected field.
inline
const SFBool *AbstractWindowBase::getSFIsSelected(void) const
{
    return &_sfIsSelected;
}

//! Get the AbstractWindow::_sfIsSelected field.
inline
SFBool *AbstractWindowBase::editSFIsSelected(void)
{
    return &_sfIsSelected;
}

//! Get the AbstractWindow::_sfTitle field.
inline
const SFString *AbstractWindowBase::getSFTitle(void) const
{
    return &_sfTitle;
}

//! Get the AbstractWindow::_sfTitle field.
inline
SFString *AbstractWindowBase::editSFTitle(void)
{
    return &_sfTitle;
}

//! Get the AbstractWindow::_sfDesktopIcon field.
inline
const SFUIDrawObjectCanvasPtr *AbstractWindowBase::getSFDesktopIcon(void) const
{
    return &_sfDesktopIcon;
}

//! Get the AbstractWindow::_sfDesktopIcon field.
inline
SFUIDrawObjectCanvasPtr *AbstractWindowBase::editSFDesktopIcon(void)
{
    return &_sfDesktopIcon;
}

//! Get the AbstractWindow::_sfAllwaysOnTop field.
inline
const SFBool *AbstractWindowBase::getSFAllwaysOnTop(void) const
{
    return &_sfAllwaysOnTop;
}

//! Get the AbstractWindow::_sfAllwaysOnTop field.
inline
SFBool *AbstractWindowBase::editSFAllwaysOnTop(void)
{
    return &_sfAllwaysOnTop;
}

//! Get the AbstractWindow::_sfDrawTitlebar field.
inline
const SFBool *AbstractWindowBase::getSFDrawTitlebar(void) const
{
    return &_sfDrawTitlebar;
}

//! Get the AbstractWindow::_sfDrawTitlebar field.
inline
SFBool *AbstractWindowBase::editSFDrawTitlebar(void)
{
    return &_sfDrawTitlebar;
}

//! Get the AbstractWindow::_sfDrawDecorations field.
inline
const SFBool *AbstractWindowBase::getSFDrawDecorations(void) const
{
    return &_sfDrawDecorations;
}

//! Get the AbstractWindow::_sfDrawDecorations field.
inline
SFBool *AbstractWindowBase::editSFDrawDecorations(void)
{
    return &_sfDrawDecorations;
}

//! Get the AbstractWindow::_sfLockInput field.
inline
const SFBool *AbstractWindowBase::getSFLockInput(void) const
{
    return &_sfLockInput;
}

//! Get the AbstractWindow::_sfLockInput field.
inline
SFBool *AbstractWindowBase::editSFLockInput(void)
{
    return &_sfLockInput;
}

//! Get the AbstractWindow::_sfAlignmentInDrawingSurface field.
inline
const SFVec2f *AbstractWindowBase::getSFAlignmentInDrawingSurface(void) const
{
    return &_sfAlignmentInDrawingSurface;
}

//! Get the AbstractWindow::_sfAlignmentInDrawingSurface field.
inline
SFVec2f *AbstractWindowBase::editSFAlignmentInDrawingSurface(void)
{
    return &_sfAlignmentInDrawingSurface;
}

//! Get the AbstractWindow::_sfScalingInDrawingSurface field.
inline
const SFVec2f *AbstractWindowBase::getSFScalingInDrawingSurface(void) const
{
    return &_sfScalingInDrawingSurface;
}

//! Get the AbstractWindow::_sfScalingInDrawingSurface field.
inline
SFVec2f *AbstractWindowBase::editSFScalingInDrawingSurface(void)
{
    return &_sfScalingInDrawingSurface;
}

//! Get the AbstractWindow::_sfResizeModifyCursorWidth field.
inline
const SFUInt32 *AbstractWindowBase::getSFResizeModifyCursorWidth(void) const
{
    return &_sfResizeModifyCursorWidth;
}

//! Get the AbstractWindow::_sfResizeModifyCursorWidth field.
inline
SFUInt32 *AbstractWindowBase::editSFResizeModifyCursorWidth(void)
{
    return &_sfResizeModifyCursorWidth;
}


//! Get the value of the AbstractWindow::_sfDrawingSurface field.
inline
UIDrawingSurfacePtr &AbstractWindowBase::editDrawingSurface(void)
{
    return _sfDrawingSurface.getValue();
}

//! Get the value of the AbstractWindow::_sfDrawingSurface field.
inline
const UIDrawingSurfacePtr &AbstractWindowBase::getDrawingSurface(void) const
{
    return _sfDrawingSurface.getValue();
}

//! Set the value of the AbstractWindow::_sfDrawingSurface field.
inline
void AbstractWindowBase::setDrawingSurface(const UIDrawingSurfacePtr &value)
{
    _sfDrawingSurface.setValue(value);
}

//! Get the value of the AbstractWindow::_sfClosable field.
inline
bool &AbstractWindowBase::editClosable(void)
{
    return _sfClosable.getValue();
}

//! Get the value of the AbstractWindow::_sfClosable field.
inline
const bool &AbstractWindowBase::getClosable(void) const
{
    return _sfClosable.getValue();
}

//! Set the value of the AbstractWindow::_sfClosable field.
inline
void AbstractWindowBase::setClosable(const bool &value)
{
    _sfClosable.setValue(value);
}

//! Get the value of the AbstractWindow::_sfIsClosed field.
inline
bool &AbstractWindowBase::editIsClosed(void)
{
    return _sfIsClosed.getValue();
}

//! Get the value of the AbstractWindow::_sfIsClosed field.
inline
const bool &AbstractWindowBase::getIsClosed(void) const
{
    return _sfIsClosed.getValue();
}

//! Set the value of the AbstractWindow::_sfIsClosed field.
inline
void AbstractWindowBase::setIsClosed(const bool &value)
{
    _sfIsClosed.setValue(value);
}

//! Get the value of the AbstractWindow::_sfIconable field.
inline
bool &AbstractWindowBase::editIconable(void)
{
    return _sfIconable.getValue();
}

//! Get the value of the AbstractWindow::_sfIconable field.
inline
const bool &AbstractWindowBase::getIconable(void) const
{
    return _sfIconable.getValue();
}

//! Set the value of the AbstractWindow::_sfIconable field.
inline
void AbstractWindowBase::setIconable(const bool &value)
{
    _sfIconable.setValue(value);
}

//! Get the value of the AbstractWindow::_sfIsIcon field.
inline
bool &AbstractWindowBase::editIsIcon(void)
{
    return _sfIsIcon.getValue();
}

//! Get the value of the AbstractWindow::_sfIsIcon field.
inline
const bool &AbstractWindowBase::getIsIcon(void) const
{
    return _sfIsIcon.getValue();
}

//! Set the value of the AbstractWindow::_sfIsIcon field.
inline
void AbstractWindowBase::setIsIcon(const bool &value)
{
    _sfIsIcon.setValue(value);
}

//! Get the value of the AbstractWindow::_sfMaximizable field.
inline
bool &AbstractWindowBase::editMaximizable(void)
{
    return _sfMaximizable.getValue();
}

//! Get the value of the AbstractWindow::_sfMaximizable field.
inline
const bool &AbstractWindowBase::getMaximizable(void) const
{
    return _sfMaximizable.getValue();
}

//! Set the value of the AbstractWindow::_sfMaximizable field.
inline
void AbstractWindowBase::setMaximizable(const bool &value)
{
    _sfMaximizable.setValue(value);
}

//! Get the value of the AbstractWindow::_sfIsMaximized field.
inline
bool &AbstractWindowBase::editIsMaximized(void)
{
    return _sfIsMaximized.getValue();
}

//! Get the value of the AbstractWindow::_sfIsMaximized field.
inline
const bool &AbstractWindowBase::getIsMaximized(void) const
{
    return _sfIsMaximized.getValue();
}

//! Set the value of the AbstractWindow::_sfIsMaximized field.
inline
void AbstractWindowBase::setIsMaximized(const bool &value)
{
    _sfIsMaximized.setValue(value);
}

//! Get the value of the AbstractWindow::_sfPreviousPosition field.
inline
Pnt2f &AbstractWindowBase::editPreviousPosition(void)
{
    return _sfPreviousPosition.getValue();
}

//! Get the value of the AbstractWindow::_sfPreviousPosition field.
inline
const Pnt2f &AbstractWindowBase::getPreviousPosition(void) const
{
    return _sfPreviousPosition.getValue();
}

//! Set the value of the AbstractWindow::_sfPreviousPosition field.
inline
void AbstractWindowBase::setPreviousPosition(const Pnt2f &value)
{
    _sfPreviousPosition.setValue(value);
}

//! Get the value of the AbstractWindow::_sfPreviousSize field.
inline
Vec2f &AbstractWindowBase::editPreviousSize(void)
{
    return _sfPreviousSize.getValue();
}

//! Get the value of the AbstractWindow::_sfPreviousSize field.
inline
const Vec2f &AbstractWindowBase::getPreviousSize(void) const
{
    return _sfPreviousSize.getValue();
}

//! Set the value of the AbstractWindow::_sfPreviousSize field.
inline
void AbstractWindowBase::setPreviousSize(const Vec2f &value)
{
    _sfPreviousSize.setValue(value);
}

//! Get the value of the AbstractWindow::_sfResizable field.
inline
bool &AbstractWindowBase::editResizable(void)
{
    return _sfResizable.getValue();
}

//! Get the value of the AbstractWindow::_sfResizable field.
inline
const bool &AbstractWindowBase::getResizable(void) const
{
    return _sfResizable.getValue();
}

//! Set the value of the AbstractWindow::_sfResizable field.
inline
void AbstractWindowBase::setResizable(const bool &value)
{
    _sfResizable.setValue(value);
}

//! Get the value of the AbstractWindow::_sfIsSelected field.
inline
bool &AbstractWindowBase::editIsSelected(void)
{
    return _sfIsSelected.getValue();
}

//! Get the value of the AbstractWindow::_sfIsSelected field.
inline
const bool &AbstractWindowBase::getIsSelected(void) const
{
    return _sfIsSelected.getValue();
}

//! Set the value of the AbstractWindow::_sfIsSelected field.
inline
void AbstractWindowBase::setIsSelected(const bool &value)
{
    _sfIsSelected.setValue(value);
}

//! Get the value of the AbstractWindow::_sfTitle field.
inline
std::string &AbstractWindowBase::editTitle(void)
{
    return _sfTitle.getValue();
}

//! Get the value of the AbstractWindow::_sfTitle field.
inline
const std::string &AbstractWindowBase::getTitle(void) const
{
    return _sfTitle.getValue();
}

//! Set the value of the AbstractWindow::_sfTitle field.
inline
void AbstractWindowBase::setTitle(const std::string &value)
{
    _sfTitle.setValue(value);
}

//! Get the value of the AbstractWindow::_sfDesktopIcon field.
inline
UIDrawObjectCanvasPtr &AbstractWindowBase::editDesktopIcon(void)
{
    return _sfDesktopIcon.getValue();
}

//! Get the value of the AbstractWindow::_sfDesktopIcon field.
inline
const UIDrawObjectCanvasPtr &AbstractWindowBase::getDesktopIcon(void) const
{
    return _sfDesktopIcon.getValue();
}

//! Set the value of the AbstractWindow::_sfDesktopIcon field.
inline
void AbstractWindowBase::setDesktopIcon(const UIDrawObjectCanvasPtr &value)
{
    _sfDesktopIcon.setValue(value);
}

//! Get the value of the AbstractWindow::_sfAllwaysOnTop field.
inline
bool &AbstractWindowBase::editAllwaysOnTop(void)
{
    return _sfAllwaysOnTop.getValue();
}

//! Get the value of the AbstractWindow::_sfAllwaysOnTop field.
inline
const bool &AbstractWindowBase::getAllwaysOnTop(void) const
{
    return _sfAllwaysOnTop.getValue();
}

//! Set the value of the AbstractWindow::_sfAllwaysOnTop field.
inline
void AbstractWindowBase::setAllwaysOnTop(const bool &value)
{
    _sfAllwaysOnTop.setValue(value);
}

//! Get the value of the AbstractWindow::_sfDrawTitlebar field.
inline
bool &AbstractWindowBase::editDrawTitlebar(void)
{
    return _sfDrawTitlebar.getValue();
}

//! Get the value of the AbstractWindow::_sfDrawTitlebar field.
inline
const bool &AbstractWindowBase::getDrawTitlebar(void) const
{
    return _sfDrawTitlebar.getValue();
}

//! Set the value of the AbstractWindow::_sfDrawTitlebar field.
inline
void AbstractWindowBase::setDrawTitlebar(const bool &value)
{
    _sfDrawTitlebar.setValue(value);
}

//! Get the value of the AbstractWindow::_sfDrawDecorations field.
inline
bool &AbstractWindowBase::editDrawDecorations(void)
{
    return _sfDrawDecorations.getValue();
}

//! Get the value of the AbstractWindow::_sfDrawDecorations field.
inline
const bool &AbstractWindowBase::getDrawDecorations(void) const
{
    return _sfDrawDecorations.getValue();
}

//! Set the value of the AbstractWindow::_sfDrawDecorations field.
inline
void AbstractWindowBase::setDrawDecorations(const bool &value)
{
    _sfDrawDecorations.setValue(value);
}

//! Get the value of the AbstractWindow::_sfLockInput field.
inline
bool &AbstractWindowBase::editLockInput(void)
{
    return _sfLockInput.getValue();
}

//! Get the value of the AbstractWindow::_sfLockInput field.
inline
const bool &AbstractWindowBase::getLockInput(void) const
{
    return _sfLockInput.getValue();
}

//! Set the value of the AbstractWindow::_sfLockInput field.
inline
void AbstractWindowBase::setLockInput(const bool &value)
{
    _sfLockInput.setValue(value);
}

//! Get the value of the AbstractWindow::_sfAlignmentInDrawingSurface field.
inline
Vec2f &AbstractWindowBase::editAlignmentInDrawingSurface(void)
{
    return _sfAlignmentInDrawingSurface.getValue();
}

//! Get the value of the AbstractWindow::_sfAlignmentInDrawingSurface field.
inline
const Vec2f &AbstractWindowBase::getAlignmentInDrawingSurface(void) const
{
    return _sfAlignmentInDrawingSurface.getValue();
}

//! Set the value of the AbstractWindow::_sfAlignmentInDrawingSurface field.
inline
void AbstractWindowBase::setAlignmentInDrawingSurface(const Vec2f &value)
{
    _sfAlignmentInDrawingSurface.setValue(value);
}

//! Get the value of the AbstractWindow::_sfScalingInDrawingSurface field.
inline
Vec2f &AbstractWindowBase::editScalingInDrawingSurface(void)
{
    return _sfScalingInDrawingSurface.getValue();
}

//! Get the value of the AbstractWindow::_sfScalingInDrawingSurface field.
inline
const Vec2f &AbstractWindowBase::getScalingInDrawingSurface(void) const
{
    return _sfScalingInDrawingSurface.getValue();
}

//! Set the value of the AbstractWindow::_sfScalingInDrawingSurface field.
inline
void AbstractWindowBase::setScalingInDrawingSurface(const Vec2f &value)
{
    _sfScalingInDrawingSurface.setValue(value);
}

//! Get the value of the AbstractWindow::_sfResizeModifyCursorWidth field.
inline
UInt32 &AbstractWindowBase::editResizeModifyCursorWidth(void)
{
    return _sfResizeModifyCursorWidth.getValue();
}

//! Get the value of the AbstractWindow::_sfResizeModifyCursorWidth field.
inline
const UInt32 &AbstractWindowBase::getResizeModifyCursorWidth(void) const
{
    return _sfResizeModifyCursorWidth.getValue();
}

//! Set the value of the AbstractWindow::_sfResizeModifyCursorWidth field.
inline
void AbstractWindowBase::setResizeModifyCursorWidth(const UInt32 &value)
{
    _sfResizeModifyCursorWidth.setValue(value);
}


OSG_END_NAMESPACE

