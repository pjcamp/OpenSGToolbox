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

#ifndef _OSGSPINNERNUMBEREDITOR_H_
#define _OSGSPINNERNUMBEREDITOR_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGSpinnerNumberEditorBase.h"

OSG_BEGIN_NAMESPACE

/*! \brief SpinnerNumberEditor class. See \ref
           PageContribUserInterfaceSpinnerNumberEditor for a description.
*/

class OSG_CONTRIBUSERINTERFACE_DLLMAPPING SpinnerNumberEditor : public SpinnerNumberEditorBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef SpinnerNumberEditorBase Inherited;
    typedef SpinnerNumberEditor     Self;

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
    //Pushes the currently edited value to the SpinnerModel.
    virtual void commitEdit(void);
    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in SpinnerNumberEditorBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    SpinnerNumberEditor(void);
    SpinnerNumberEditor(const SpinnerNumberEditor &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~SpinnerNumberEditor(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */

    virtual void handleModelStateChanged(ChangeEventDetails* const e);
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class SpinnerNumberEditorBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const SpinnerNumberEditor &source);
};

typedef SpinnerNumberEditor *SpinnerNumberEditorP;

OSG_END_NAMESPACE

#include "OSGSpinnerNumberEditorBase.inl"
#include "OSGSpinnerNumberEditor.inl"

#endif /* _OSGSPINNERNUMBEREDITOR_H_ */
