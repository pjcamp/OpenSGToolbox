/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *   contact:  David Kabala (djkabala@gmail.com)                             *
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
 **     class Button!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &ButtonBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 ButtonBase::getClassTypeId(void)
{
    return _type.getId();
}
//! access the producer type of the class
inline
const EventProducerType &ButtonBase::getProducerClassType(void)
{
    return _producerType;
}

//! access the producer type id of the class
inline
UInt32 ButtonBase::getProducerClassTypeId(void)
{
    return _producerType.getId();
}

inline
OSG::UInt16 ButtonBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/


//! Get the value of the Button::_sfFont field.
inline
UIFont * ButtonBase::getFont(void) const
{
    return _sfFont.getValue();
}

//! Set the value of the Button::_sfFont field.
inline
void ButtonBase::setFont(UIFont * const value)
{
    editSField(FontFieldMask);

    _sfFont.setValue(value);
}
//! Get the value of the Button::_sfText field.

inline
std::string &ButtonBase::editText(void)
{
    editSField(TextFieldMask);

    return _sfText.getValue();
}

//! Get the value of the Button::_sfText field.
inline
const std::string &ButtonBase::getText(void) const
{
    return _sfText.getValue();
}

//! Set the value of the Button::_sfText field.
inline
void ButtonBase::setText(const std::string &value)
{
    editSField(TextFieldMask);

    _sfText.setValue(value);
}

//! Get the value of the Button::_sfActiveBorder field.
inline
Border * ButtonBase::getActiveBorder(void) const
{
    return _sfActiveBorder.getValue();
}

//! Set the value of the Button::_sfActiveBorder field.
inline
void ButtonBase::setActiveBorder(Border * const value)
{
    editSField(ActiveBorderFieldMask);

    _sfActiveBorder.setValue(value);
}

//! Get the value of the Button::_sfActiveBackground field.
inline
Layer * ButtonBase::getActiveBackground(void) const
{
    return _sfActiveBackground.getValue();
}

//! Set the value of the Button::_sfActiveBackground field.
inline
void ButtonBase::setActiveBackground(Layer * const value)
{
    editSField(ActiveBackgroundFieldMask);

    _sfActiveBackground.setValue(value);
}

//! Get the value of the Button::_sfActiveForeground field.
inline
Layer * ButtonBase::getActiveForeground(void) const
{
    return _sfActiveForeground.getValue();
}

//! Set the value of the Button::_sfActiveForeground field.
inline
void ButtonBase::setActiveForeground(Layer * const value)
{
    editSField(ActiveForegroundFieldMask);

    _sfActiveForeground.setValue(value);
}
//! Get the value of the Button::_sfActiveTextColor field.

inline
Color4f &ButtonBase::editActiveTextColor(void)
{
    editSField(ActiveTextColorFieldMask);

    return _sfActiveTextColor.getValue();
}

//! Get the value of the Button::_sfActiveTextColor field.
inline
const Color4f &ButtonBase::getActiveTextColor(void) const
{
    return _sfActiveTextColor.getValue();
}

//! Set the value of the Button::_sfActiveTextColor field.
inline
void ButtonBase::setActiveTextColor(const Color4f &value)
{
    editSField(ActiveTextColorFieldMask);

    _sfActiveTextColor.setValue(value);
}
//! Get the value of the Button::_sfFocusedTextColor field.

inline
Color4f &ButtonBase::editFocusedTextColor(void)
{
    editSField(FocusedTextColorFieldMask);

    return _sfFocusedTextColor.getValue();
}

//! Get the value of the Button::_sfFocusedTextColor field.
inline
const Color4f &ButtonBase::getFocusedTextColor(void) const
{
    return _sfFocusedTextColor.getValue();
}

//! Set the value of the Button::_sfFocusedTextColor field.
inline
void ButtonBase::setFocusedTextColor(const Color4f &value)
{
    editSField(FocusedTextColorFieldMask);

    _sfFocusedTextColor.setValue(value);
}
//! Get the value of the Button::_sfRolloverTextColor field.

inline
Color4f &ButtonBase::editRolloverTextColor(void)
{
    editSField(RolloverTextColorFieldMask);

    return _sfRolloverTextColor.getValue();
}

//! Get the value of the Button::_sfRolloverTextColor field.
inline
const Color4f &ButtonBase::getRolloverTextColor(void) const
{
    return _sfRolloverTextColor.getValue();
}

//! Set the value of the Button::_sfRolloverTextColor field.
inline
void ButtonBase::setRolloverTextColor(const Color4f &value)
{
    editSField(RolloverTextColorFieldMask);

    _sfRolloverTextColor.setValue(value);
}
//! Get the value of the Button::_sfDisabledTextColor field.

inline
Color4f &ButtonBase::editDisabledTextColor(void)
{
    editSField(DisabledTextColorFieldMask);

    return _sfDisabledTextColor.getValue();
}

//! Get the value of the Button::_sfDisabledTextColor field.
inline
const Color4f &ButtonBase::getDisabledTextColor(void) const
{
    return _sfDisabledTextColor.getValue();
}

//! Set the value of the Button::_sfDisabledTextColor field.
inline
void ButtonBase::setDisabledTextColor(const Color4f &value)
{
    editSField(DisabledTextColorFieldMask);

    _sfDisabledTextColor.setValue(value);
}
//! Get the value of the Button::_sfTextColor field.

inline
Color4f &ButtonBase::editTextColor(void)
{
    editSField(TextColorFieldMask);

    return _sfTextColor.getValue();
}

//! Get the value of the Button::_sfTextColor field.
inline
const Color4f &ButtonBase::getTextColor(void) const
{
    return _sfTextColor.getValue();
}

//! Set the value of the Button::_sfTextColor field.
inline
void ButtonBase::setTextColor(const Color4f &value)
{
    editSField(TextColorFieldMask);

    _sfTextColor.setValue(value);
}
//! Get the value of the Button::_sfAlignment field.

inline
Vec2f &ButtonBase::editAlignment(void)
{
    editSField(AlignmentFieldMask);

    return _sfAlignment.getValue();
}

//! Get the value of the Button::_sfAlignment field.
inline
const Vec2f &ButtonBase::getAlignment(void) const
{
    return _sfAlignment.getValue();
}

//! Set the value of the Button::_sfAlignment field.
inline
void ButtonBase::setAlignment(const Vec2f &value)
{
    editSField(AlignmentFieldMask);

    _sfAlignment.setValue(value);
}
//! Get the value of the Button::_sfEnableActionOnMouseDownTime field.

inline
bool &ButtonBase::editEnableActionOnMouseDownTime(void)
{
    editSField(EnableActionOnMouseDownTimeFieldMask);

    return _sfEnableActionOnMouseDownTime.getValue();
}

//! Get the value of the Button::_sfEnableActionOnMouseDownTime field.
inline
      bool  ButtonBase::getEnableActionOnMouseDownTime(void) const
{
    return _sfEnableActionOnMouseDownTime.getValue();
}

//! Set the value of the Button::_sfEnableActionOnMouseDownTime field.
inline
void ButtonBase::setEnableActionOnMouseDownTime(const bool value)
{
    editSField(EnableActionOnMouseDownTimeFieldMask);

    _sfEnableActionOnMouseDownTime.setValue(value);
}
//! Get the value of the Button::_sfActionOnMouseDownRate field.

inline
Time &ButtonBase::editActionOnMouseDownRate(void)
{
    editSField(ActionOnMouseDownRateFieldMask);

    return _sfActionOnMouseDownRate.getValue();
}

//! Get the value of the Button::_sfActionOnMouseDownRate field.
inline
const Time &ButtonBase::getActionOnMouseDownRate(void) const
{
    return _sfActionOnMouseDownRate.getValue();
}

//! Set the value of the Button::_sfActionOnMouseDownRate field.
inline
void ButtonBase::setActionOnMouseDownRate(const Time &value)
{
    editSField(ActionOnMouseDownRateFieldMask);

    _sfActionOnMouseDownRate.setValue(value);
}
//! Get the value of the Button::_sfActiveOffset field.

inline
Vec2f &ButtonBase::editActiveOffset(void)
{
    editSField(ActiveOffsetFieldMask);

    return _sfActiveOffset.getValue();
}

//! Get the value of the Button::_sfActiveOffset field.
inline
const Vec2f &ButtonBase::getActiveOffset(void) const
{
    return _sfActiveOffset.getValue();
}

//! Set the value of the Button::_sfActiveOffset field.
inline
void ButtonBase::setActiveOffset(const Vec2f &value)
{
    editSField(ActiveOffsetFieldMask);

    _sfActiveOffset.setValue(value);
}

//! Get the value of the Button::_sfDrawObject field.
inline
UIDrawObjectCanvas * ButtonBase::getDrawObject(void) const
{
    return _sfDrawObject.getValue();
}

//! Set the value of the Button::_sfDrawObject field.
inline
void ButtonBase::setDrawObject(UIDrawObjectCanvas * const value)
{
    editSField(DrawObjectFieldMask);

    _sfDrawObject.setValue(value);
}

//! Get the value of the Button::_sfActiveDrawObject field.
inline
UIDrawObjectCanvas * ButtonBase::getActiveDrawObject(void) const
{
    return _sfActiveDrawObject.getValue();
}

//! Set the value of the Button::_sfActiveDrawObject field.
inline
void ButtonBase::setActiveDrawObject(UIDrawObjectCanvas * const value)
{
    editSField(ActiveDrawObjectFieldMask);

    _sfActiveDrawObject.setValue(value);
}

//! Get the value of the Button::_sfFocusedDrawObject field.
inline
UIDrawObjectCanvas * ButtonBase::getFocusedDrawObject(void) const
{
    return _sfFocusedDrawObject.getValue();
}

//! Set the value of the Button::_sfFocusedDrawObject field.
inline
void ButtonBase::setFocusedDrawObject(UIDrawObjectCanvas * const value)
{
    editSField(FocusedDrawObjectFieldMask);

    _sfFocusedDrawObject.setValue(value);
}

//! Get the value of the Button::_sfRolloverDrawObject field.
inline
UIDrawObjectCanvas * ButtonBase::getRolloverDrawObject(void) const
{
    return _sfRolloverDrawObject.getValue();
}

//! Set the value of the Button::_sfRolloverDrawObject field.
inline
void ButtonBase::setRolloverDrawObject(UIDrawObjectCanvas * const value)
{
    editSField(RolloverDrawObjectFieldMask);

    _sfRolloverDrawObject.setValue(value);
}

//! Get the value of the Button::_sfDisabledDrawObject field.
inline
UIDrawObjectCanvas * ButtonBase::getDisabledDrawObject(void) const
{
    return _sfDisabledDrawObject.getValue();
}

//! Set the value of the Button::_sfDisabledDrawObject field.
inline
void ButtonBase::setDisabledDrawObject(UIDrawObjectCanvas * const value)
{
    editSField(DisabledDrawObjectFieldMask);

    _sfDisabledDrawObject.setValue(value);
}
//! Get the value of the Button::_sfDrawObjectToTextAlignment field.

inline
UInt32 &ButtonBase::editDrawObjectToTextAlignment(void)
{
    editSField(DrawObjectToTextAlignmentFieldMask);

    return _sfDrawObjectToTextAlignment.getValue();
}

//! Get the value of the Button::_sfDrawObjectToTextAlignment field.
inline
      UInt32  ButtonBase::getDrawObjectToTextAlignment(void) const
{
    return _sfDrawObjectToTextAlignment.getValue();
}

//! Set the value of the Button::_sfDrawObjectToTextAlignment field.
inline
void ButtonBase::setDrawObjectToTextAlignment(const UInt32 value)
{
    editSField(DrawObjectToTextAlignmentFieldMask);

    _sfDrawObjectToTextAlignment.setValue(value);
}
//! Get the value of the Button::_sfDrawObjectToTextPadding field.

inline
Real32 &ButtonBase::editDrawObjectToTextPadding(void)
{
    editSField(DrawObjectToTextPaddingFieldMask);

    return _sfDrawObjectToTextPadding.getValue();
}

//! Get the value of the Button::_sfDrawObjectToTextPadding field.
inline
      Real32  ButtonBase::getDrawObjectToTextPadding(void) const
{
    return _sfDrawObjectToTextPadding.getValue();
}

//! Set the value of the Button::_sfDrawObjectToTextPadding field.
inline
void ButtonBase::setDrawObjectToTextPadding(const Real32 value)
{
    editSField(DrawObjectToTextPaddingFieldMask);

    _sfDrawObjectToTextPadding.setValue(value);
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void ButtonBase::execSync (      ButtonBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (FontFieldMask & whichField))
        _sfFont.syncWith(pFrom->_sfFont);

    if(FieldBits::NoField != (TextFieldMask & whichField))
        _sfText.syncWith(pFrom->_sfText);

    if(FieldBits::NoField != (ActiveBorderFieldMask & whichField))
        _sfActiveBorder.syncWith(pFrom->_sfActiveBorder);

    if(FieldBits::NoField != (ActiveBackgroundFieldMask & whichField))
        _sfActiveBackground.syncWith(pFrom->_sfActiveBackground);

    if(FieldBits::NoField != (ActiveForegroundFieldMask & whichField))
        _sfActiveForeground.syncWith(pFrom->_sfActiveForeground);

    if(FieldBits::NoField != (ActiveTextColorFieldMask & whichField))
        _sfActiveTextColor.syncWith(pFrom->_sfActiveTextColor);

    if(FieldBits::NoField != (FocusedTextColorFieldMask & whichField))
        _sfFocusedTextColor.syncWith(pFrom->_sfFocusedTextColor);

    if(FieldBits::NoField != (RolloverTextColorFieldMask & whichField))
        _sfRolloverTextColor.syncWith(pFrom->_sfRolloverTextColor);

    if(FieldBits::NoField != (DisabledTextColorFieldMask & whichField))
        _sfDisabledTextColor.syncWith(pFrom->_sfDisabledTextColor);

    if(FieldBits::NoField != (TextColorFieldMask & whichField))
        _sfTextColor.syncWith(pFrom->_sfTextColor);

    if(FieldBits::NoField != (AlignmentFieldMask & whichField))
        _sfAlignment.syncWith(pFrom->_sfAlignment);

    if(FieldBits::NoField != (EnableActionOnMouseDownTimeFieldMask & whichField))
        _sfEnableActionOnMouseDownTime.syncWith(pFrom->_sfEnableActionOnMouseDownTime);

    if(FieldBits::NoField != (ActionOnMouseDownRateFieldMask & whichField))
        _sfActionOnMouseDownRate.syncWith(pFrom->_sfActionOnMouseDownRate);

    if(FieldBits::NoField != (ActiveOffsetFieldMask & whichField))
        _sfActiveOffset.syncWith(pFrom->_sfActiveOffset);

    if(FieldBits::NoField != (DrawObjectFieldMask & whichField))
        _sfDrawObject.syncWith(pFrom->_sfDrawObject);

    if(FieldBits::NoField != (ActiveDrawObjectFieldMask & whichField))
        _sfActiveDrawObject.syncWith(pFrom->_sfActiveDrawObject);

    if(FieldBits::NoField != (FocusedDrawObjectFieldMask & whichField))
        _sfFocusedDrawObject.syncWith(pFrom->_sfFocusedDrawObject);

    if(FieldBits::NoField != (RolloverDrawObjectFieldMask & whichField))
        _sfRolloverDrawObject.syncWith(pFrom->_sfRolloverDrawObject);

    if(FieldBits::NoField != (DisabledDrawObjectFieldMask & whichField))
        _sfDisabledDrawObject.syncWith(pFrom->_sfDisabledDrawObject);

    if(FieldBits::NoField != (DrawObjectToTextAlignmentFieldMask & whichField))
        _sfDrawObjectToTextAlignment.syncWith(pFrom->_sfDrawObjectToTextAlignment);

    if(FieldBits::NoField != (DrawObjectToTextPaddingFieldMask & whichField))
        _sfDrawObjectToTextPadding.syncWith(pFrom->_sfDrawObjectToTextPadding);
}
#endif


inline
const Char8 *ButtonBase::getClassname(void)
{
    return "Button";
}
OSG_GEN_CONTAINERPTR(Button);

OSG_END_NAMESPACE

