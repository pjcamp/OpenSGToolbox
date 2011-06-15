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

#ifndef _OSGTRANSFORMATIONELEMENT_H_
#define _OSGTRANSFORMATIONELEMENT_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGTransformationElementBase.h"
#include "OSGMatrix.h"

OSG_BEGIN_NAMESPACE

/*! \brief TransformationElement class. See \ref
           PageGroupTransformationElement for a description.
*/

class OSG_GROUP_DLLMAPPING TransformationElement : public TransformationElementBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef TransformationElementBase Inherited;
    typedef TransformationElement     Self;

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

    void accumulateMatrix(Matrix &result) const;

    virtual void calcMatrix(Matrix &result) const = 0;

    Matrix calcMatrix(void) const;
    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in TransformationElementBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    TransformationElement(void);
    TransformationElement(const TransformationElement &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~TransformationElement(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    void updateParentTransform(void);
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class TransformationElementBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const TransformationElement &source);
};

typedef TransformationElement *TransformationElementP;

OSG_END_NAMESPACE

#include "OSGTransformationElementBase.inl"
#include "OSGTransformationElement.inl"

#endif /* _OSGTRANSFORMATIONELEMENT_H_ */
