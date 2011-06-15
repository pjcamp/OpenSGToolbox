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

#ifndef _OSGTREEROWMAPPER_H_
#define _OSGTREEROWMAPPER_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGTreeRowMapperBase.h"
#include "OSGTreePath.h"
#include <vector>

OSG_BEGIN_NAMESPACE

/*! \brief TreeRowMapper class. See \ref
           PageContribUserInterfaceTreeRowMapper for a description.
*/

class OSG_CONTRIBUSERINTERFACE_DLLMAPPING TreeRowMapper : public TreeRowMapperBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef TreeRowMapperBase Inherited;
    typedef TreeRowMapper     Self;

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
    
    //Returns the rows that the TreePath instances in path are being displayed at.
    virtual std::vector<Int32> getRowsForPaths(const std::vector<TreePath>& paths) const = 0;
    
    virtual Int32 getRowForPath(const TreePath& path) const = 0;

    //Returns the path for passed in row.
    virtual TreePath getPathForRow(const UInt32& row) const = 0;

    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in TreeRowMapperBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    TreeRowMapper(void);
    TreeRowMapper(const TreeRowMapper &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~TreeRowMapper(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class TreeRowMapperBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const TreeRowMapper &source);
};

typedef TreeRowMapper *TreeRowMapperP;

OSG_END_NAMESPACE

#include "OSGTreeRowMapperBase.inl"
#include "OSGTreeRowMapper.inl"

#endif /* _OSGTREEROWMAPPER_H_ */
