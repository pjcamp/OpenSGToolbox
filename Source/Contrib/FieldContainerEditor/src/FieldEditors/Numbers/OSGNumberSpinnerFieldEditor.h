/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
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

#ifndef _OSGNUMBERSPINNERFIELDEDITOR_H_
#define _OSGNUMBERSPINNERFIELDEDITOR_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGNumberSpinnerFieldEditorBase.h"
#include "OSGSpinnerFields.h"
#include "OSGChangeEventDetailsFields.h"
#include "OSGNumberSpinnerModel.h"

OSG_BEGIN_NAMESPACE

/*! \brief NumberSpinnerFieldEditor class. See \ref
           PageContribFieldContainerEditorNumberSpinnerFieldEditor for a description.
*/

class OSG_CONTRIBFIELDCONTAINEREDITOR_DLLMAPPING NumberSpinnerFieldEditor : public NumberSpinnerFieldEditorBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef NumberSpinnerFieldEditorBase Inherited;
    typedef NumberSpinnerFieldEditor     Self;

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

    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in NumberSpinnerFieldEditorBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    NumberSpinnerFieldEditor(void);
    NumberSpinnerFieldEditor(const NumberSpinnerFieldEditor &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~NumberSpinnerFieldEditor(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
	/*---------------------------------------------------------------------*/
	/*! \name                   Class Specific                             */
	/*! \{                                                                 */
	void onCreate(const NumberSpinnerFieldEditor *Id = NULL);
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
    virtual bool internalAttachField (FieldContainer* fc, UInt32 fieldId, UInt32 index);
    virtual void updateLayout         (void);
    void         runCommand           (void);

    static std::vector<const DataType*> _EditableTypes;
    SpinnerRefPtr   _EditingSpinner;
    SpinnerModelPtr _EditingSpinnerModel;
    
    void handleSpinnerStateChanged(ChangeEventDetails* const details);
    boost::signals2::connection _SpinnerStateChangedConnection;
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class NumberSpinnerFieldEditorBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const NumberSpinnerFieldEditor &source);
};

typedef NumberSpinnerFieldEditor *NumberSpinnerFieldEditorP;

OSG_END_NAMESPACE

#include "OSGNumberSpinnerFieldEditorBase.inl"
#include "OSGNumberSpinnerFieldEditor.inl"

#endif /* _OSGNUMBERSPINNERFIELDEDITOR_H_ */
