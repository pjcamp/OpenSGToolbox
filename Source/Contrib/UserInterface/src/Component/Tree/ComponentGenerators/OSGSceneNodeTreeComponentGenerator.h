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

#ifndef _OSGSCENENODETREECOMPONENTGENERATOR_H_
#define _OSGSCENENODETREECOMPONENTGENERATOR_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGSceneNodeTreeComponentGeneratorBase.h"

OSG_BEGIN_NAMESPACE

/*! \brief SceneNodeTreeComponentGenerator class. See \ref
           PageContribUserInterfaceSceneNodeTreeComponentGenerator for a description.
*/

class OSG_CONTRIBUSERINTERFACE_DLLMAPPING SceneNodeTreeComponentGenerator : public SceneNodeTreeComponentGeneratorBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef SceneNodeTreeComponentGeneratorBase Inherited;
    typedef SceneNodeTreeComponentGenerator     Self;

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
    virtual ComponentTransitPtr getTreeComponent(Tree* const Parent,
                                             const boost::any& Value,
                                             bool IsSelected,
                                             bool Expanded,
                                             bool Leaf,
                                             UInt32 Row,
                                             bool HasFocus);
    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in SceneNodeTreeComponentGeneratorBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    SceneNodeTreeComponentGenerator(void);
    SceneNodeTreeComponentGenerator(const SceneNodeTreeComponentGenerator &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~SceneNodeTreeComponentGenerator(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class SceneNodeTreeComponentGeneratorBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const SceneNodeTreeComponentGenerator &source);
};

typedef SceneNodeTreeComponentGenerator *SceneNodeTreeComponentGeneratorP;

OSG_END_NAMESPACE

#include "OSGSceneNodeTreeComponentGeneratorBase.inl"
#include "OSGSceneNodeTreeComponentGenerator.inl"

#endif /* _OSGSCENENODETREECOMPONENTGENERATOR_H_ */
