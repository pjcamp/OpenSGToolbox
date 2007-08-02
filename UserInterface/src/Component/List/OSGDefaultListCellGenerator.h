/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                         www.vrac.iastate.edu                              *
 *                                                                           *
 *   Authors: David Kabala, Alden Peterson, Lee Zaniewski, Jonathan Flory    *
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

#ifndef _OSGDEFAULTLISTCELLGENERATOR_H_
#define _OSGDEFAULTLISTCELLGENERATOR_H_
#ifdef __sgi
#pragma once
#endif

#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"

#include "OSGListCellGenerator.h"

OSG_BEGIN_NAMESPACE

/*! \brief DefaultListCellGenerator class. See \ref 
           PageUserInterfaceDefaultListCellGenerator for a description.
*/

class OSG_USERINTERFACELIB_DLLMAPPING DefaultListCellGenerator : public ListCellGenerator
{
    /*==========================  PUBLIC  =================================*/
  public:
    virtual ComponentPtr getListCellGeneratorComponent(ListPtr list, Field* value, UInt32 index, bool isSelected, bool cellHasFocus);

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    DefaultListCellGenerator(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~DefaultListCellGenerator(void); 

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/
  protected:

    // Variables should all be in DefaultListCellGeneratorBase.

    
    /*==========================  PRIVATE  ================================*/
  private:
};

typedef DefaultListCellGenerator *DefaultListCellGeneratorP;

OSG_END_NAMESPACE

#include "OSGDefaultListCellGenerator.inl"

#endif /* _OSGDEFAULTLISTCELLGENERATOR_H_ */
