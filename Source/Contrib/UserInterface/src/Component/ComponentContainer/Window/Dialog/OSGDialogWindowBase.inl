/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *   contact:  David Kabala (djkabala@gmail.com), Mark Stenerson             *
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
 **     class DialogWindow!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &DialogWindowBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 DialogWindowBase::getClassTypeId(void)
{
    return _type.getId();
}
//! access the producer type of the class
inline
const EventProducerType &DialogWindowBase::getProducerClassType(void)
{
    return _producerType;
}

//! access the producer type id of the class
inline
UInt32 DialogWindowBase::getProducerClassTypeId(void)
{
    return _producerType.getId();
}

inline
OSG::UInt16 DialogWindowBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/


//! Get the value of the DialogWindow::_sfErrorIcon field.
inline
TextureObjChunk * DialogWindowBase::getErrorIcon(void) const
{
    return _sfErrorIcon.getValue();
}

//! Set the value of the DialogWindow::_sfErrorIcon field.
inline
void DialogWindowBase::setErrorIcon(TextureObjChunk * const value)
{
    editSField(ErrorIconFieldMask);

    _sfErrorIcon.setValue(value);
}

//! Get the value of the DialogWindow::_sfQuestionIcon field.
inline
TextureObjChunk * DialogWindowBase::getQuestionIcon(void) const
{
    return _sfQuestionIcon.getValue();
}

//! Set the value of the DialogWindow::_sfQuestionIcon field.
inline
void DialogWindowBase::setQuestionIcon(TextureObjChunk * const value)
{
    editSField(QuestionIconFieldMask);

    _sfQuestionIcon.setValue(value);
}

//! Get the value of the DialogWindow::_sfDefaultIcon field.
inline
TextureObjChunk * DialogWindowBase::getDefaultIcon(void) const
{
    return _sfDefaultIcon.getValue();
}

//! Set the value of the DialogWindow::_sfDefaultIcon field.
inline
void DialogWindowBase::setDefaultIcon(TextureObjChunk * const value)
{
    editSField(DefaultIconFieldMask);

    _sfDefaultIcon.setValue(value);
}
//! Get the value of the DialogWindow::_sfShowCancel field.

inline
bool &DialogWindowBase::editShowCancel(void)
{
    editSField(ShowCancelFieldMask);

    return _sfShowCancel.getValue();
}

//! Get the value of the DialogWindow::_sfShowCancel field.
inline
      bool  DialogWindowBase::getShowCancel(void) const
{
    return _sfShowCancel.getValue();
}

//! Set the value of the DialogWindow::_sfShowCancel field.
inline
void DialogWindowBase::setShowCancel(const bool value)
{
    editSField(ShowCancelFieldMask);

    _sfShowCancel.setValue(value);
}
//! Get the value of the DialogWindow::_sfInputValues field.

inline
std::string &DialogWindowBase::editInputValues(void)
{
    editSField(InputValuesFieldMask);

    return _sfInputValues.getValue();
}

//! Get the value of the DialogWindow::_sfInputValues field.
inline
const std::string &DialogWindowBase::getInputValues(void) const
{
    return _sfInputValues.getValue();
}

//! Set the value of the DialogWindow::_sfInputValues field.
inline
void DialogWindowBase::setInputValues(const std::string &value)
{
    editSField(InputValuesFieldMask);

    _sfInputValues.setValue(value);
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void DialogWindowBase::execSync (      DialogWindowBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (ErrorIconFieldMask & whichField))
        _sfErrorIcon.syncWith(pFrom->_sfErrorIcon);

    if(FieldBits::NoField != (QuestionIconFieldMask & whichField))
        _sfQuestionIcon.syncWith(pFrom->_sfQuestionIcon);

    if(FieldBits::NoField != (DefaultIconFieldMask & whichField))
        _sfDefaultIcon.syncWith(pFrom->_sfDefaultIcon);

    if(FieldBits::NoField != (ShowCancelFieldMask & whichField))
        _sfShowCancel.syncWith(pFrom->_sfShowCancel);

    if(FieldBits::NoField != (InputValuesFieldMask & whichField))
        _sfInputValues.syncWith(pFrom->_sfInputValues);
}
#endif


inline
const Char8 *DialogWindowBase::getClassname(void)
{
    return "DialogWindow";
}
OSG_GEN_CONTAINERPTR(DialogWindow);

OSG_END_NAMESPACE

