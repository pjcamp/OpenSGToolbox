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

#ifndef _OSGTEXTFIELDEDITOR_H_
#define _OSGTEXTFIELDEDITOR_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGTextFieldEditorBase.h"
#include "OSGTextAreaFields.h"
#include "OSGScrollPanelFields.h"
#include "OSGActionEventDetailsFields.h"

OSG_BEGIN_NAMESPACE

/*! \brief TextFieldEditor class. See \ref
           PageContribFieldContainerEditorTextFieldEditor for a description.
*/

class OSG_CONTRIBFIELDCONTAINEREDITOR_DLLMAPPING TextFieldEditor : public TextFieldEditorBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef TextFieldEditorBase Inherited;
    typedef TextFieldEditor     Self;

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
    virtual const std::vector<const DataType*>& getEditableTypes(void) const;

    virtual UInt32 getNumRequestedRows(void) const;
    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in TextFieldEditorBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    TextFieldEditor(void);
    TextFieldEditor(const TextFieldEditor &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~TextFieldEditor(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Class Specific                             */
    /*! \{                                                                 */
    void onCreate(const TextFieldEditor *Id = NULL);
    void onDestroy();
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

    virtual void resolveLinks(void);

    /*! \}                                                                 */
    virtual void internalFieldChanged (void);
    virtual void internalStartEditing (void);
    virtual void internalStopEditing  (void);
    virtual void internalCancelEditing(void);
    virtual void updateLayout(void);

    static std::vector<const DataType*> _EditableTypes;
    TextAreaRefPtr _EditingTextArea;
    ScrollPanelRefPtr _EditingTextAreaScrollPanel;
    std::string _InitialValue;
    
    void handleTextDomAreaFocusGained    (FocusEventDetails* const details);
    void handleTextDomAreaFocusLost      (FocusEventDetails* const details);
    void handleTextDomAreaActionPerformed(ActionEventDetails* const details);
    void handleTextDomAreaKeyTyped       (KeyEventDetails* const details);
    boost::signals2::connection _TextDomAreaFocusGainedConnection,
                                _TextDomAreaFocusLostConnection,
                                _TextDomAreaActionPerformedConnection,
                                _TextDomAreaKeyTypedConnection;
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class TextFieldEditorBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const TextFieldEditor &source);
};

typedef TextFieldEditor *TextFieldEditorP;

OSG_END_NAMESPACE

#include "OSGTextFieldEditorBase.inl"
#include "OSGTextFieldEditor.inl"

#endif /* _OSGTEXTFIELDEDITOR_H_ */
