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

#ifndef _OSGUIFOREGROUND_H_
#define _OSGUIFOREGROUND_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGUIForegroundBase.h"
#include "OSGUIDrawingSurface.h"

OSG_BEGIN_NAMESPACE

/*! \brief UIForeground class. See \ref
           PageContribUserInterfaceUIForeground for a description.
*/

class OSG_CONTRIBUSERINTERFACE_DLLMAPPING UIForeground : public UIForegroundBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef UIForegroundBase Inherited;
    typedef UIForeground     Self;

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

    virtual void draw(DrawEnv * env);

    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in UIForegroundBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    UIForeground(void);
    UIForeground(const UIForeground &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~UIForeground(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Class Specific                             */
    /*! \{                                                                 */
    void onCreate(const UIForeground *Id = NULL);
    void onDestroy();
    
    /*! \}                                                                 */
    void beginOrthoRender(DrawEnv *pEnv,
                          UInt32  &fullWidth,
                          UInt32  &fullHeight);

    void endOrthoRender(DrawEnv *pEnv);
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class UIForegroundBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const UIForeground &source);
};

typedef UIForeground *UIForegroundP;

OSG_END_NAMESPACE

#include "OSGUIForegroundMouseTransformFunctor.h"
#include "OSGInternalWindow.h"

#include "OSGUIForegroundBase.inl"
#include "OSGUIForeground.inl"

#endif /* _OSGUIFOREGROUND_H_ */
