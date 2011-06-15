/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 * contact: Achyuthan Vasanth (vasanth.achyuthan@gmail.com)                  *
 *          David Kabala (djkabala@gmail.com)                                *
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

#ifndef _OSGPLAINDOCUMENTBRANCHELEMENT_H_
#define _OSGPLAINDOCUMENTBRANCHELEMENT_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGPlainDocumentBranchElementBase.h"

OSG_BEGIN_NAMESPACE

/*! \brief PlainDocumentBranchElement class. See \ref
           PageContribTextDomPlainDocumentBranchElement for a description.
*/

class OSG_CONTRIBTEXTDOM_DLLMAPPING PlainDocumentBranchElement : public PlainDocumentBranchElementBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef PlainDocumentBranchElementBase Inherited;
    typedef PlainDocumentBranchElement     Self;

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
    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in PlainDocumentBranchElementBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    PlainDocumentBranchElement(void);
    PlainDocumentBranchElement(const PlainDocumentBranchElement &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~PlainDocumentBranchElement(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class PlainDocumentBranchElementBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const PlainDocumentBranchElement &source);
};

typedef PlainDocumentBranchElement *PlainDocumentBranchElementP;

OSG_END_NAMESPACE

#include "OSGPlainDocumentBranchElementBase.inl"
#include "OSGPlainDocumentBranchElement.inl"

#endif /* _OSGPLAINDOCUMENTBRANCHELEMENT_H_ */
