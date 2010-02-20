/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                         www.vrac.iastate.edu                              *
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
 **     class Button!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEBUTTONINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "OSGButtonBase.h"
#include "OSGButton.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  ButtonBase::FontFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::FontFieldId);

const OSG::BitVector  ButtonBase::TextFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::TextFieldId);

const OSG::BitVector  ButtonBase::ActiveBorderFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::ActiveBorderFieldId);

const OSG::BitVector  ButtonBase::ActiveBackgroundFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::ActiveBackgroundFieldId);

const OSG::BitVector  ButtonBase::ActiveForegroundFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::ActiveForegroundFieldId);

const OSG::BitVector  ButtonBase::ActiveTextColorFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::ActiveTextColorFieldId);

const OSG::BitVector  ButtonBase::FocusedTextColorFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::FocusedTextColorFieldId);

const OSG::BitVector  ButtonBase::RolloverTextColorFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::RolloverTextColorFieldId);

const OSG::BitVector  ButtonBase::DisabledTextColorFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::DisabledTextColorFieldId);

const OSG::BitVector  ButtonBase::TextColorFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::TextColorFieldId);

const OSG::BitVector  ButtonBase::AlignmentFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::AlignmentFieldId);

const OSG::BitVector  ButtonBase::EnableActionOnMouseDownTimeFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::EnableActionOnMouseDownTimeFieldId);

const OSG::BitVector  ButtonBase::ActionOnMouseDownRateFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::ActionOnMouseDownRateFieldId);

const OSG::BitVector  ButtonBase::ActiveOffsetFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::ActiveOffsetFieldId);

const OSG::BitVector  ButtonBase::DrawObjectFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::DrawObjectFieldId);

const OSG::BitVector  ButtonBase::ActiveDrawObjectFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::ActiveDrawObjectFieldId);

const OSG::BitVector  ButtonBase::FocusedDrawObjectFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::FocusedDrawObjectFieldId);

const OSG::BitVector  ButtonBase::RolloverDrawObjectFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::RolloverDrawObjectFieldId);

const OSG::BitVector  ButtonBase::DisabledDrawObjectFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::DisabledDrawObjectFieldId);

const OSG::BitVector  ButtonBase::DrawObjectToTextAlignmentFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::DrawObjectToTextAlignmentFieldId);

const OSG::BitVector  ButtonBase::DrawObjectToTextPaddingFieldMask = 
    (TypeTraits<BitVector>::One << ButtonBase::DrawObjectToTextPaddingFieldId);

const OSG::BitVector ButtonBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var UIFontPtr       ButtonBase::_sfFont
    
*/
/*! \var std::string     ButtonBase::_sfText
    
*/
/*! \var BorderPtr       ButtonBase::_sfActiveBorder
    
*/
/*! \var LayerPtr        ButtonBase::_sfActiveBackground
    
*/
/*! \var LayerPtr        ButtonBase::_sfActiveForeground
    
*/
/*! \var Color4f         ButtonBase::_sfActiveTextColor
    
*/
/*! \var Color4f         ButtonBase::_sfFocusedTextColor
    
*/
/*! \var Color4f         ButtonBase::_sfRolloverTextColor
    
*/
/*! \var Color4f         ButtonBase::_sfDisabledTextColor
    
*/
/*! \var Color4f         ButtonBase::_sfTextColor
    
*/
/*! \var Vec2f           ButtonBase::_sfAlignment
    
*/
/*! \var bool            ButtonBase::_sfEnableActionOnMouseDownTime
    
*/
/*! \var Time            ButtonBase::_sfActionOnMouseDownRate
    
*/
/*! \var Vec2f           ButtonBase::_sfActiveOffset
    
*/
/*! \var UIDrawObjectCanvasPtr ButtonBase::_sfDrawObject
    
*/
/*! \var UIDrawObjectCanvasPtr ButtonBase::_sfActiveDrawObject
    
*/
/*! \var UIDrawObjectCanvasPtr ButtonBase::_sfFocusedDrawObject
    
*/
/*! \var UIDrawObjectCanvasPtr ButtonBase::_sfRolloverDrawObject
    
*/
/*! \var UIDrawObjectCanvasPtr ButtonBase::_sfDisabledDrawObject
    
*/
/*! \var UInt32          ButtonBase::_sfDrawObjectToTextAlignment
    
*/
/*! \var Real32          ButtonBase::_sfDrawObjectToTextPadding
    
*/

//! Button description

FieldDescription *ButtonBase::_desc[] = 
{
    new FieldDescription(SFUIFontPtr::getClassType(), 
                     "Font", 
                     FontFieldId, FontFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFFont)),
    new FieldDescription(SFString::getClassType(), 
                     "Text", 
                     TextFieldId, TextFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFText)),
    new FieldDescription(SFBorderPtr::getClassType(), 
                     "ActiveBorder", 
                     ActiveBorderFieldId, ActiveBorderFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFActiveBorder)),
    new FieldDescription(SFLayerPtr::getClassType(), 
                     "ActiveBackground", 
                     ActiveBackgroundFieldId, ActiveBackgroundFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFActiveBackground)),
    new FieldDescription(SFLayerPtr::getClassType(), 
                     "ActiveForeground", 
                     ActiveForegroundFieldId, ActiveForegroundFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFActiveForeground)),
    new FieldDescription(SFColor4f::getClassType(), 
                     "ActiveTextColor", 
                     ActiveTextColorFieldId, ActiveTextColorFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFActiveTextColor)),
    new FieldDescription(SFColor4f::getClassType(), 
                     "FocusedTextColor", 
                     FocusedTextColorFieldId, FocusedTextColorFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFFocusedTextColor)),
    new FieldDescription(SFColor4f::getClassType(), 
                     "RolloverTextColor", 
                     RolloverTextColorFieldId, RolloverTextColorFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFRolloverTextColor)),
    new FieldDescription(SFColor4f::getClassType(), 
                     "DisabledTextColor", 
                     DisabledTextColorFieldId, DisabledTextColorFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFDisabledTextColor)),
    new FieldDescription(SFColor4f::getClassType(), 
                     "TextColor", 
                     TextColorFieldId, TextColorFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFTextColor)),
    new FieldDescription(SFVec2f::getClassType(), 
                     "Alignment", 
                     AlignmentFieldId, AlignmentFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFAlignment)),
    new FieldDescription(SFBool::getClassType(), 
                     "EnableActionOnMouseDownTime", 
                     EnableActionOnMouseDownTimeFieldId, EnableActionOnMouseDownTimeFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFEnableActionOnMouseDownTime)),
    new FieldDescription(SFTime::getClassType(), 
                     "ActionOnMouseDownRate", 
                     ActionOnMouseDownRateFieldId, ActionOnMouseDownRateFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFActionOnMouseDownRate)),
    new FieldDescription(SFVec2f::getClassType(), 
                     "ActiveOffset", 
                     ActiveOffsetFieldId, ActiveOffsetFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFActiveOffset)),
    new FieldDescription(SFUIDrawObjectCanvasPtr::getClassType(), 
                     "DrawObject", 
                     DrawObjectFieldId, DrawObjectFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFDrawObject)),
    new FieldDescription(SFUIDrawObjectCanvasPtr::getClassType(), 
                     "ActiveDrawObject", 
                     ActiveDrawObjectFieldId, ActiveDrawObjectFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFActiveDrawObject)),
    new FieldDescription(SFUIDrawObjectCanvasPtr::getClassType(), 
                     "FocusedDrawObject", 
                     FocusedDrawObjectFieldId, FocusedDrawObjectFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFFocusedDrawObject)),
    new FieldDescription(SFUIDrawObjectCanvasPtr::getClassType(), 
                     "RolloverDrawObject", 
                     RolloverDrawObjectFieldId, RolloverDrawObjectFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFRolloverDrawObject)),
    new FieldDescription(SFUIDrawObjectCanvasPtr::getClassType(), 
                     "DisabledDrawObject", 
                     DisabledDrawObjectFieldId, DisabledDrawObjectFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFDisabledDrawObject)),
    new FieldDescription(SFUInt32::getClassType(), 
                     "DrawObjectToTextAlignment", 
                     DrawObjectToTextAlignmentFieldId, DrawObjectToTextAlignmentFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFDrawObjectToTextAlignment)),
    new FieldDescription(SFReal32::getClassType(), 
                     "DrawObjectToTextPadding", 
                     DrawObjectToTextPaddingFieldId, DrawObjectToTextPaddingFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ButtonBase::editSFDrawObjectToTextPadding))
};


FieldContainerType ButtonBase::_type(
    "Button",
    "Component",
    NULL,
    reinterpret_cast<PrototypeCreateF>(&ButtonBase::createEmpty),
    Button::initMethod,
    _desc,
    sizeof(_desc));

//! Button Produced Methods

MethodDescription *ButtonBase::_methodDesc[] =
{
    new MethodDescription("ActionPerformed", 
                     ActionPerformedMethodId, 
                     SFEventPtr::getClassType(),
                     FunctorAccessMethod()),
    new MethodDescription("MousePressedActionPerformed", 
                     MousePressedActionPerformedMethodId, 
                     SFEventPtr::getClassType(),
                     FunctorAccessMethod())
};

EventProducerType ButtonBase::_producerType(
    "ButtonProducerType",
    "ComponentProducerType",
    NULL,
    InitEventProducerFunctor(),
    _methodDesc,
    sizeof(_methodDesc));
//OSG_FIELD_CONTAINER_DEF(ButtonBase, ButtonPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &ButtonBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &ButtonBase::getType(void) const 
{
    return _type;
} 

const EventProducerType &ButtonBase::getProducerType(void) const
{
    return _producerType;
}


FieldContainerPtr ButtonBase::shallowCopy(void) const 
{ 
    ButtonPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const Button *>(this)); 

    return returnValue; 
}

UInt32 ButtonBase::getContainerSize(void) const 
{ 
    return sizeof(Button); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void ButtonBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl(static_cast<ButtonBase *>(&other),
                          whichField);
}
#else
void ButtonBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((ButtonBase *) &other, whichField, sInfo);
}
void ButtonBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void ButtonBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

ButtonBase::ButtonBase(void) :
    _sfFont                   (), 
    _sfText                   (), 
    _sfActiveBorder           (BorderPtr(NullFC)), 
    _sfActiveBackground       (LayerPtr(NullFC)), 
    _sfActiveForeground       (LayerPtr(NullFC)), 
    _sfActiveTextColor        (), 
    _sfFocusedTextColor       (), 
    _sfRolloverTextColor      (), 
    _sfDisabledTextColor      (), 
    _sfTextColor              (), 
    _sfAlignment              (Vec2f(0.5,0.5)), 
    _sfEnableActionOnMouseDownTime(bool(false)), 
    _sfActionOnMouseDownRate  (Time(0.1)), 
    _sfActiveOffset           (Vec2f(0,0)), 
    _sfDrawObject             (UIDrawObjectCanvasPtr(NullFC)), 
    _sfActiveDrawObject       (UIDrawObjectCanvasPtr(NullFC)), 
    _sfFocusedDrawObject      (UIDrawObjectCanvasPtr(NullFC)), 
    _sfRolloverDrawObject     (UIDrawObjectCanvasPtr(NullFC)), 
    _sfDisabledDrawObject     (UIDrawObjectCanvasPtr(NullFC)), 
    _sfDrawObjectToTextAlignment(UInt32(Button::ALIGN_DRAW_OBJECT_LEFT_OF_TEXT)), 
    _sfDrawObjectToTextPadding(Real32(2.0)), 
    Inherited() 
{
    _Producer.setType(&_producerType);
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

ButtonBase::ButtonBase(const ButtonBase &source) :
    _sfFont                   (source._sfFont                   ), 
    _sfText                   (source._sfText                   ), 
    _sfActiveBorder           (source._sfActiveBorder           ), 
    _sfActiveBackground       (source._sfActiveBackground       ), 
    _sfActiveForeground       (source._sfActiveForeground       ), 
    _sfActiveTextColor        (source._sfActiveTextColor        ), 
    _sfFocusedTextColor       (source._sfFocusedTextColor       ), 
    _sfRolloverTextColor      (source._sfRolloverTextColor      ), 
    _sfDisabledTextColor      (source._sfDisabledTextColor      ), 
    _sfTextColor              (source._sfTextColor              ), 
    _sfAlignment              (source._sfAlignment              ), 
    _sfEnableActionOnMouseDownTime(source._sfEnableActionOnMouseDownTime), 
    _sfActionOnMouseDownRate  (source._sfActionOnMouseDownRate  ), 
    _sfActiveOffset           (source._sfActiveOffset           ), 
    _sfDrawObject             (source._sfDrawObject             ), 
    _sfActiveDrawObject       (source._sfActiveDrawObject       ), 
    _sfFocusedDrawObject      (source._sfFocusedDrawObject      ), 
    _sfRolloverDrawObject     (source._sfRolloverDrawObject     ), 
    _sfDisabledDrawObject     (source._sfDisabledDrawObject     ), 
    _sfDrawObjectToTextAlignment(source._sfDrawObjectToTextAlignment), 
    _sfDrawObjectToTextPadding(source._sfDrawObjectToTextPadding), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

ButtonBase::~ButtonBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 ButtonBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (FontFieldMask & whichField))
    {
        returnValue += _sfFont.getBinSize();
    }

    if(FieldBits::NoField != (TextFieldMask & whichField))
    {
        returnValue += _sfText.getBinSize();
    }

    if(FieldBits::NoField != (ActiveBorderFieldMask & whichField))
    {
        returnValue += _sfActiveBorder.getBinSize();
    }

    if(FieldBits::NoField != (ActiveBackgroundFieldMask & whichField))
    {
        returnValue += _sfActiveBackground.getBinSize();
    }

    if(FieldBits::NoField != (ActiveForegroundFieldMask & whichField))
    {
        returnValue += _sfActiveForeground.getBinSize();
    }

    if(FieldBits::NoField != (ActiveTextColorFieldMask & whichField))
    {
        returnValue += _sfActiveTextColor.getBinSize();
    }

    if(FieldBits::NoField != (FocusedTextColorFieldMask & whichField))
    {
        returnValue += _sfFocusedTextColor.getBinSize();
    }

    if(FieldBits::NoField != (RolloverTextColorFieldMask & whichField))
    {
        returnValue += _sfRolloverTextColor.getBinSize();
    }

    if(FieldBits::NoField != (DisabledTextColorFieldMask & whichField))
    {
        returnValue += _sfDisabledTextColor.getBinSize();
    }

    if(FieldBits::NoField != (TextColorFieldMask & whichField))
    {
        returnValue += _sfTextColor.getBinSize();
    }

    if(FieldBits::NoField != (AlignmentFieldMask & whichField))
    {
        returnValue += _sfAlignment.getBinSize();
    }

    if(FieldBits::NoField != (EnableActionOnMouseDownTimeFieldMask & whichField))
    {
        returnValue += _sfEnableActionOnMouseDownTime.getBinSize();
    }

    if(FieldBits::NoField != (ActionOnMouseDownRateFieldMask & whichField))
    {
        returnValue += _sfActionOnMouseDownRate.getBinSize();
    }

    if(FieldBits::NoField != (ActiveOffsetFieldMask & whichField))
    {
        returnValue += _sfActiveOffset.getBinSize();
    }

    if(FieldBits::NoField != (DrawObjectFieldMask & whichField))
    {
        returnValue += _sfDrawObject.getBinSize();
    }

    if(FieldBits::NoField != (ActiveDrawObjectFieldMask & whichField))
    {
        returnValue += _sfActiveDrawObject.getBinSize();
    }

    if(FieldBits::NoField != (FocusedDrawObjectFieldMask & whichField))
    {
        returnValue += _sfFocusedDrawObject.getBinSize();
    }

    if(FieldBits::NoField != (RolloverDrawObjectFieldMask & whichField))
    {
        returnValue += _sfRolloverDrawObject.getBinSize();
    }

    if(FieldBits::NoField != (DisabledDrawObjectFieldMask & whichField))
    {
        returnValue += _sfDisabledDrawObject.getBinSize();
    }

    if(FieldBits::NoField != (DrawObjectToTextAlignmentFieldMask & whichField))
    {
        returnValue += _sfDrawObjectToTextAlignment.getBinSize();
    }

    if(FieldBits::NoField != (DrawObjectToTextPaddingFieldMask & whichField))
    {
        returnValue += _sfDrawObjectToTextPadding.getBinSize();
    }


    return returnValue;
}

void ButtonBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (FontFieldMask & whichField))
    {
        _sfFont.copyToBin(pMem);
    }

    if(FieldBits::NoField != (TextFieldMask & whichField))
    {
        _sfText.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ActiveBorderFieldMask & whichField))
    {
        _sfActiveBorder.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ActiveBackgroundFieldMask & whichField))
    {
        _sfActiveBackground.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ActiveForegroundFieldMask & whichField))
    {
        _sfActiveForeground.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ActiveTextColorFieldMask & whichField))
    {
        _sfActiveTextColor.copyToBin(pMem);
    }

    if(FieldBits::NoField != (FocusedTextColorFieldMask & whichField))
    {
        _sfFocusedTextColor.copyToBin(pMem);
    }

    if(FieldBits::NoField != (RolloverTextColorFieldMask & whichField))
    {
        _sfRolloverTextColor.copyToBin(pMem);
    }

    if(FieldBits::NoField != (DisabledTextColorFieldMask & whichField))
    {
        _sfDisabledTextColor.copyToBin(pMem);
    }

    if(FieldBits::NoField != (TextColorFieldMask & whichField))
    {
        _sfTextColor.copyToBin(pMem);
    }

    if(FieldBits::NoField != (AlignmentFieldMask & whichField))
    {
        _sfAlignment.copyToBin(pMem);
    }

    if(FieldBits::NoField != (EnableActionOnMouseDownTimeFieldMask & whichField))
    {
        _sfEnableActionOnMouseDownTime.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ActionOnMouseDownRateFieldMask & whichField))
    {
        _sfActionOnMouseDownRate.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ActiveOffsetFieldMask & whichField))
    {
        _sfActiveOffset.copyToBin(pMem);
    }

    if(FieldBits::NoField != (DrawObjectFieldMask & whichField))
    {
        _sfDrawObject.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ActiveDrawObjectFieldMask & whichField))
    {
        _sfActiveDrawObject.copyToBin(pMem);
    }

    if(FieldBits::NoField != (FocusedDrawObjectFieldMask & whichField))
    {
        _sfFocusedDrawObject.copyToBin(pMem);
    }

    if(FieldBits::NoField != (RolloverDrawObjectFieldMask & whichField))
    {
        _sfRolloverDrawObject.copyToBin(pMem);
    }

    if(FieldBits::NoField != (DisabledDrawObjectFieldMask & whichField))
    {
        _sfDisabledDrawObject.copyToBin(pMem);
    }

    if(FieldBits::NoField != (DrawObjectToTextAlignmentFieldMask & whichField))
    {
        _sfDrawObjectToTextAlignment.copyToBin(pMem);
    }

    if(FieldBits::NoField != (DrawObjectToTextPaddingFieldMask & whichField))
    {
        _sfDrawObjectToTextPadding.copyToBin(pMem);
    }


}

void ButtonBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (FontFieldMask & whichField))
    {
        _sfFont.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (TextFieldMask & whichField))
    {
        _sfText.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ActiveBorderFieldMask & whichField))
    {
        _sfActiveBorder.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ActiveBackgroundFieldMask & whichField))
    {
        _sfActiveBackground.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ActiveForegroundFieldMask & whichField))
    {
        _sfActiveForeground.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ActiveTextColorFieldMask & whichField))
    {
        _sfActiveTextColor.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (FocusedTextColorFieldMask & whichField))
    {
        _sfFocusedTextColor.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (RolloverTextColorFieldMask & whichField))
    {
        _sfRolloverTextColor.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (DisabledTextColorFieldMask & whichField))
    {
        _sfDisabledTextColor.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (TextColorFieldMask & whichField))
    {
        _sfTextColor.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (AlignmentFieldMask & whichField))
    {
        _sfAlignment.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (EnableActionOnMouseDownTimeFieldMask & whichField))
    {
        _sfEnableActionOnMouseDownTime.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ActionOnMouseDownRateFieldMask & whichField))
    {
        _sfActionOnMouseDownRate.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ActiveOffsetFieldMask & whichField))
    {
        _sfActiveOffset.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (DrawObjectFieldMask & whichField))
    {
        _sfDrawObject.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ActiveDrawObjectFieldMask & whichField))
    {
        _sfActiveDrawObject.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (FocusedDrawObjectFieldMask & whichField))
    {
        _sfFocusedDrawObject.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (RolloverDrawObjectFieldMask & whichField))
    {
        _sfRolloverDrawObject.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (DisabledDrawObjectFieldMask & whichField))
    {
        _sfDisabledDrawObject.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (DrawObjectToTextAlignmentFieldMask & whichField))
    {
        _sfDrawObjectToTextAlignment.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (DrawObjectToTextPaddingFieldMask & whichField))
    {
        _sfDrawObjectToTextPadding.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void ButtonBase::executeSyncImpl(      ButtonBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (FontFieldMask & whichField))
        _sfFont.syncWith(pOther->_sfFont);

    if(FieldBits::NoField != (TextFieldMask & whichField))
        _sfText.syncWith(pOther->_sfText);

    if(FieldBits::NoField != (ActiveBorderFieldMask & whichField))
        _sfActiveBorder.syncWith(pOther->_sfActiveBorder);

    if(FieldBits::NoField != (ActiveBackgroundFieldMask & whichField))
        _sfActiveBackground.syncWith(pOther->_sfActiveBackground);

    if(FieldBits::NoField != (ActiveForegroundFieldMask & whichField))
        _sfActiveForeground.syncWith(pOther->_sfActiveForeground);

    if(FieldBits::NoField != (ActiveTextColorFieldMask & whichField))
        _sfActiveTextColor.syncWith(pOther->_sfActiveTextColor);

    if(FieldBits::NoField != (FocusedTextColorFieldMask & whichField))
        _sfFocusedTextColor.syncWith(pOther->_sfFocusedTextColor);

    if(FieldBits::NoField != (RolloverTextColorFieldMask & whichField))
        _sfRolloverTextColor.syncWith(pOther->_sfRolloverTextColor);

    if(FieldBits::NoField != (DisabledTextColorFieldMask & whichField))
        _sfDisabledTextColor.syncWith(pOther->_sfDisabledTextColor);

    if(FieldBits::NoField != (TextColorFieldMask & whichField))
        _sfTextColor.syncWith(pOther->_sfTextColor);

    if(FieldBits::NoField != (AlignmentFieldMask & whichField))
        _sfAlignment.syncWith(pOther->_sfAlignment);

    if(FieldBits::NoField != (EnableActionOnMouseDownTimeFieldMask & whichField))
        _sfEnableActionOnMouseDownTime.syncWith(pOther->_sfEnableActionOnMouseDownTime);

    if(FieldBits::NoField != (ActionOnMouseDownRateFieldMask & whichField))
        _sfActionOnMouseDownRate.syncWith(pOther->_sfActionOnMouseDownRate);

    if(FieldBits::NoField != (ActiveOffsetFieldMask & whichField))
        _sfActiveOffset.syncWith(pOther->_sfActiveOffset);

    if(FieldBits::NoField != (DrawObjectFieldMask & whichField))
        _sfDrawObject.syncWith(pOther->_sfDrawObject);

    if(FieldBits::NoField != (ActiveDrawObjectFieldMask & whichField))
        _sfActiveDrawObject.syncWith(pOther->_sfActiveDrawObject);

    if(FieldBits::NoField != (FocusedDrawObjectFieldMask & whichField))
        _sfFocusedDrawObject.syncWith(pOther->_sfFocusedDrawObject);

    if(FieldBits::NoField != (RolloverDrawObjectFieldMask & whichField))
        _sfRolloverDrawObject.syncWith(pOther->_sfRolloverDrawObject);

    if(FieldBits::NoField != (DisabledDrawObjectFieldMask & whichField))
        _sfDisabledDrawObject.syncWith(pOther->_sfDisabledDrawObject);

    if(FieldBits::NoField != (DrawObjectToTextAlignmentFieldMask & whichField))
        _sfDrawObjectToTextAlignment.syncWith(pOther->_sfDrawObjectToTextAlignment);

    if(FieldBits::NoField != (DrawObjectToTextPaddingFieldMask & whichField))
        _sfDrawObjectToTextPadding.syncWith(pOther->_sfDrawObjectToTextPadding);


}
#else
void ButtonBase::executeSyncImpl(      ButtonBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (FontFieldMask & whichField))
        _sfFont.syncWith(pOther->_sfFont);

    if(FieldBits::NoField != (TextFieldMask & whichField))
        _sfText.syncWith(pOther->_sfText);

    if(FieldBits::NoField != (ActiveBorderFieldMask & whichField))
        _sfActiveBorder.syncWith(pOther->_sfActiveBorder);

    if(FieldBits::NoField != (ActiveBackgroundFieldMask & whichField))
        _sfActiveBackground.syncWith(pOther->_sfActiveBackground);

    if(FieldBits::NoField != (ActiveForegroundFieldMask & whichField))
        _sfActiveForeground.syncWith(pOther->_sfActiveForeground);

    if(FieldBits::NoField != (ActiveTextColorFieldMask & whichField))
        _sfActiveTextColor.syncWith(pOther->_sfActiveTextColor);

    if(FieldBits::NoField != (FocusedTextColorFieldMask & whichField))
        _sfFocusedTextColor.syncWith(pOther->_sfFocusedTextColor);

    if(FieldBits::NoField != (RolloverTextColorFieldMask & whichField))
        _sfRolloverTextColor.syncWith(pOther->_sfRolloverTextColor);

    if(FieldBits::NoField != (DisabledTextColorFieldMask & whichField))
        _sfDisabledTextColor.syncWith(pOther->_sfDisabledTextColor);

    if(FieldBits::NoField != (TextColorFieldMask & whichField))
        _sfTextColor.syncWith(pOther->_sfTextColor);

    if(FieldBits::NoField != (AlignmentFieldMask & whichField))
        _sfAlignment.syncWith(pOther->_sfAlignment);

    if(FieldBits::NoField != (EnableActionOnMouseDownTimeFieldMask & whichField))
        _sfEnableActionOnMouseDownTime.syncWith(pOther->_sfEnableActionOnMouseDownTime);

    if(FieldBits::NoField != (ActionOnMouseDownRateFieldMask & whichField))
        _sfActionOnMouseDownRate.syncWith(pOther->_sfActionOnMouseDownRate);

    if(FieldBits::NoField != (ActiveOffsetFieldMask & whichField))
        _sfActiveOffset.syncWith(pOther->_sfActiveOffset);

    if(FieldBits::NoField != (DrawObjectFieldMask & whichField))
        _sfDrawObject.syncWith(pOther->_sfDrawObject);

    if(FieldBits::NoField != (ActiveDrawObjectFieldMask & whichField))
        _sfActiveDrawObject.syncWith(pOther->_sfActiveDrawObject);

    if(FieldBits::NoField != (FocusedDrawObjectFieldMask & whichField))
        _sfFocusedDrawObject.syncWith(pOther->_sfFocusedDrawObject);

    if(FieldBits::NoField != (RolloverDrawObjectFieldMask & whichField))
        _sfRolloverDrawObject.syncWith(pOther->_sfRolloverDrawObject);

    if(FieldBits::NoField != (DisabledDrawObjectFieldMask & whichField))
        _sfDisabledDrawObject.syncWith(pOther->_sfDisabledDrawObject);

    if(FieldBits::NoField != (DrawObjectToTextAlignmentFieldMask & whichField))
        _sfDrawObjectToTextAlignment.syncWith(pOther->_sfDrawObjectToTextAlignment);

    if(FieldBits::NoField != (DrawObjectToTextPaddingFieldMask & whichField))
        _sfDrawObjectToTextPadding.syncWith(pOther->_sfDrawObjectToTextPadding);



}

void ButtonBase::execBeginEditImpl (const BitVector &whichField, 
                                                 UInt32     uiAspect,
                                                 UInt32     uiContainerSize)
{
    Inherited::execBeginEditImpl(whichField, uiAspect, uiContainerSize);

}
#endif



OSG_END_NAMESPACE

#include <OpenSG/OSGSFieldTypeDef.inl>
#include <OpenSG/OSGMFieldTypeDef.inl>

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldDataTraits<ButtonPtr>::_type("ButtonPtr", "ComponentPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(ButtonPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(ButtonPtr, OSG_USERINTERFACELIB_DLLTMPLMAPPING);


OSG_END_NAMESPACE
