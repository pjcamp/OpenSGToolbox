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

#include "OSGTextFieldEditor.h"
#include "OSGSetFieldValueCommand.h"
#include "OSGTypeFactory.h"
#include "OSGFieldEditorFactory.h"
#include <sstream>
#include "OSGPointerSFieldBase.h"
#include "OSGFieldContainerSFieldHandle.h"
#include "OSGPointerMFieldBase.h"
#include "OSGFieldContainerMFieldHandle.h"
#include <boost/lexical_cast.hpp>
#include "OSGScrollPanel.h"

#include "OSGTextArea.h"
#include "OSGSimpleSHLChunk.h"

#ifdef OSG_WITH_CG
#include "OSGCgFXMaterial.h"
#endif

//#include "OSGSHLChunk.h"
#include "OSGShaderProgram.h"

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGTextFieldEditorBase.cpp file.
// To modify it, please change the .fcd file (OSGTextFieldEditor.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/
 
std::vector<const DataType*> TextFieldEditor::_EditableTypes = std::vector<const DataType*>();

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void TextFieldEditor::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::FactoryPost)
    {
        _EditableTypes.push_back(&FieldTraits<std::string>::getType());
        for(UInt32 i(0) ; i<_EditableTypes.size(); ++i)
        {
            FieldEditorFactory::the()->addEditorType(_EditableTypes[i], &getClassType(), "Text");
        }

        //Add some overrides
        //Text field of TextArea
        FieldEditorFactory::the()->setSpecializedEditor(&TextArea::getClassType(), TextArea::TextFieldId, &getClassType());

        //SimpleSHLChunk
        FieldEditorFactory::the()->setSpecializedEditor(&SimpleSHLChunk::getClassType(), SimpleSHLChunk::VertexProgramFieldId, &getClassType());
        FieldEditorFactory::the()->setSpecializedEditor(&SimpleSHLChunk::getClassType(), SimpleSHLChunk::GeometryProgramFieldId, &getClassType());
        FieldEditorFactory::the()->setSpecializedEditor(&SimpleSHLChunk::getClassType(), SimpleSHLChunk::FragmentProgramFieldId, &getClassType());

        //SHLChunk
        //FieldEditorFactory::the()->setSpecializedEditor(&SHLChunk::getClassType(), SHLChunk::VertexProgramFieldId, &getClassType());
        //FieldEditorFactory::the()->setSpecializedEditor(&SHLChunk::getClassType(), SHLChunk::GeometryProgramFieldId, &getClassType());
        //FieldEditorFactory::the()->setSpecializedEditor(&SHLChunk::getClassType(), SHLChunk::FragmentProgramFieldId, &getClassType());
        
#ifdef OSG_WITH_CG
        //CgFXMaterial
        FieldEditorFactory::the()->setSpecializedEditor(&CgFXMaterial::getClassType(), CgFXMaterial::EffectStringFieldId, &getClassType());
#endif

        //ShaderProgram
        FieldEditorFactory::the()->setSpecializedEditor(&ShaderProgram::getClassType(), ShaderProgram::ProgramFieldId, &getClassType());
    }
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/
UInt32 TextFieldEditor::getNumRequestedRows(void) const
{
    return 8;
}

void TextFieldEditor::internalFieldChanged (void)
{
    GetFieldHandlePtr TheFieldHandle = getEditingFC()->getField(getEditingFieldId());

    std::ostringstream StrStream;
    OutStream TheOutStream(StrStream);
    if(TheFieldHandle->getCardinality() == FieldType::SingleField)
    {
        TheFieldHandle->pushValueToStream(TheOutStream);
    }
    else
    {
        TheFieldHandle->pushIndexedValueToStream(TheOutStream, getEditingFieldIndex());
    }
        
    _EditingTextArea->setText(StrStream.str());

}

void TextFieldEditor::internalStartEditing (void)
{
    _InitialValue =  _EditingTextArea->getText();
}

void TextFieldEditor::internalStopEditing  (void)
{
    //Call the command to set the Field
    SetFieldValueCommandPtr SetCommand = SetFieldValueCommand::create(getEditingFC(), getEditingFieldId(), _EditingTextArea->getText(), getEditingFieldIndex());

    getCommandManager()->executeCommand(SetCommand);
}

void TextFieldEditor::internalCancelEditing(void)
{
    _EditingTextArea->setText(_InitialValue);
}

const std::vector<const DataType*>& TextFieldEditor::getEditableTypes(void) const
{
    return _EditableTypes;
}

void TextFieldEditor::updateLayout(void)
{
    Pnt2f TopLeft, BottomRight;
    getInsideBorderBounds(TopLeft, BottomRight);

    _EditingTextAreaScrollPanel->setPosition(TopLeft);
    _EditingTextAreaScrollPanel->setSize(BottomRight - TopLeft);
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/
void TextFieldEditor::onCreate(const TextFieldEditor *Id)
{
    Inherited::onCreate(Id);

    if(Id != NULL)
    {
        _EditingTextArea = TextArea::create();

        _EditingTextAreaScrollPanel = ScrollPanel::create();
        _EditingTextAreaScrollPanel->setViewComponent(_EditingTextArea);

        pushToChildren(_EditingTextAreaScrollPanel);
        _TextDomAreaFocusGainedConnection = _EditingTextArea->connectFocusGained(boost::bind(&TextFieldEditor::handleTextDomAreaFocusGained, this, _1));
        _TextDomAreaFocusLostConnection = _EditingTextArea->connectFocusLost(boost::bind(&TextFieldEditor::handleTextDomAreaFocusLost, this, _1));
        //_TextDomAreaActionPerformedConnection = _EditingTextArea->connectActionPerformed(boost::bind(&TextFieldEditor::handleTextDomAreaActionPerformed, this, _1));
        _TextDomAreaKeyTypedConnection = _EditingTextArea->connectKeyTyped(boost::bind(&TextFieldEditor::handleTextDomAreaKeyTyped, this, _1));
    }
}

void TextFieldEditor::onDestroy()
{
}

void TextFieldEditor::resolveLinks(void)
{
    Inherited::resolveLinks();

    _EditingTextArea = NULL;
    _EditingTextAreaScrollPanel = NULL;

    _TextDomAreaFocusGainedConnection.disconnect();
    _TextDomAreaFocusLostConnection.disconnect();
    //_TextDomAreaActionPerformedConnection.disconnect();
    _TextDomAreaKeyTypedConnection.disconnect();
}

void TextFieldEditor::handleTextDomAreaFocusGained    (FocusEventDetails* const details)
{
    startEditing();
}

void TextFieldEditor::handleTextDomAreaFocusLost      (FocusEventDetails* const details)
{
    stopEditing();
}

void TextFieldEditor::handleTextDomAreaActionPerformed(ActionEventDetails* const details)
{
    stopEditing();
    startEditing();
}

void TextFieldEditor::handleTextDomAreaKeyTyped       (KeyEventDetails* const details)
{
    if(details->getKey() == KeyEventDetails::KEY_ESCAPE)
    {
        cancelEditing();
        startEditing();
    }
}

/*----------------------- constructors & destructors ----------------------*/

TextFieldEditor::TextFieldEditor(void) :
    Inherited()
{
}

TextFieldEditor::TextFieldEditor(const TextFieldEditor &source) :
    Inherited(source)
{
}

TextFieldEditor::~TextFieldEditor(void)
{
}

/*----------------------------- class specific ----------------------------*/

void TextFieldEditor::changed(ConstFieldMaskArg whichField, 
                            UInt32            origin,
                            BitVector         details)
{
    Inherited::changed(whichField, origin, details);
}

void TextFieldEditor::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump TextFieldEditor NI" << std::endl;
}

OSG_END_NAMESPACE
