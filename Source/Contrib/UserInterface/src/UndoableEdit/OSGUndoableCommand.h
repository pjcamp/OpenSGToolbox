/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
 *                                                                           *
 *                                                                           *
 *                                                                           *
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

#ifndef _OSGUNDOABLECOMMAND_H_
#define _OSGUNDOABLECOMMAND_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGContribUserInterfaceDef.h"

#include "OSGCommand.h"
#include "OSGAbstractUndoableEdit.h"
#include "OSGTime.h"

OSG_BEGIN_NAMESPACE

class UndoableCommand;
typedef boost::shared_ptr<UndoableCommand> UndoableCommandPtr;

class OSG_CONTRIBUSERINTERFACE_DLLMAPPING UndoableCommand : public Command, public AbstractUndoableEdit
{
protected:
    typedef Command Inherited1;
    typedef AbstractUndoableEdit Inherited2;
    typedef UndoableCommandPtr  Ptr;
    typedef UndoableCommand  Self;

    friend class CompoundUndoableCommand;

    UndoableCommand(void);

    UndoableCommand(const UndoableCommand& source);
    
    void operator =(const UndoableCommand& source);

    virtual void execute(void);

    Time _ExecuteTime;

    static Time _MaxReplaceTime;

    static CommandType _Type;

public:
    
    virtual const CommandType &getType(void) const;
    
    static const CommandType &getClassType(void);

    virtual ~UndoableCommand(void);

    const Time& getTime(void) const;

    static const Time& getMaxReplaceTime(void);

    static void setMaxReplaceTime(const Time& t);
};


OSG_END_NAMESPACE

#include "OSGUndoableCommand.inl"

#endif /* _OSGUNDOABLECOMMAND_H_ */
