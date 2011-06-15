/*---------------------------------------------------------------------------*\
 *                          OpenSG Toolbox Lua                               *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                         www.vrac.iastate.edu                              *
 *                                                                           *
 *   Authors: David Kabala                                                   *
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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define OSG_COMPILELUALIB

#include "OSGConfig.h"
#include "OSGBaseFunctions.h"
#include "OSGBaseInitFunctions.h"
#include "OSGLog.h"
#include "OSGEventDetails.h"
#include "OSGStatCollector.h"

#include "OSGLuaManager.h"
#include <boost/bind.hpp>
#include <boost/filesystem/operations.hpp>
#include <sstream>

//This is the OSGBase wrapped module in Bindings/OSG_wrap.cpp
extern "C" int luaopen_OSG(lua_State* L); // declare the wrapped module

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::LuaManager
A FMod SoundManager Interface. 
*/

struct AddLuaInitFuncs
{
    AddLuaInitFuncs()
    {
        addPreFactoryInitFunction(boost::bind(&LuaManager::init));
        addPreFactoryExitFunction(boost::bind(&LuaManager::uninit));
    }
} AddLuaInitFuncsInstantiation;

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

LuaManager *LuaManager::_the  = NULL;
lua_State *LuaManager::_State = NULL;

//! WindowEventProducer Produced Events

EventDescription *LuaManager::_eventDesc[] =
{
    new EventDescription("LuaError", 
                          "Lua Error",
                          LuaErrorEventId, 
                          FieldTraits<LuaErrorEventDetails *>::getType(),
                          true,
                          NULL),
};

EventProducerType LuaManager::_producerType(
                                            "LuaManagerProducerType",
                                            "EventProducerType",
                                            "",
                                            InitEventProducerFunctor(),
                                            _eventDesc,
                                            sizeof(_eventDesc));

StatElemDesc<StatTimeElem> LuaManager::statScriptsRunTime("ScriptsRunTime", 
                                                         "time to run the lua scripts");

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

const EventProducerType &LuaManager::getProducerType(void) const
{
    return _producerType;
}

LuaManager *LuaManager::the(void)
{
    if(_the == NULL)
    {
        _the = new LuaManager();
    }

    return _the;
}

void LuaManager::report_errors(lua_State *L, int status)
{
}

bool LuaManager::init(void)
{
    SLOG << "LuaManager Initializing." << std::endl;

    _State = lua_open();
    if(_State == NULL)
    {
        SWARNING << "Failed to create lua state." << std::endl;
        return false;
    }

    luaL_openlibs(_State); 

    //Load the OpenSG Bindings
    SLOG << "LuaManager Loading OpenSG Bindings." << std::endl;
    luaopen_OSG(_State);

    SLOG << "LuaManager Successfully Initialized." << std::endl;
    return true;
}

bool LuaManager::recreateLuaState(void)
{
    //Close the Lua State
    if(_State != NULL)
    {
        SLOG << "LuaManager: closing Lua State." << std::endl;

        lua_close(_State);
        _State = NULL;

        SLOG << "LuaManager: Lua State Closed." << std::endl;
    }

    SLOG << "LuaManager: Opening Lua State." << std::endl;

    _State = lua_open();
    if(_State == NULL)
    {
        SWARNING << "LuaManager: Failed to open lua state." << std::endl;
        return false;
    }

    luaL_openlibs(_State); 

    //Load the OpenSG Bindings
    SLOG << "LuaManager: Loading OpenSG Bindings." << std::endl;
    luaopen_OSG(_State);

    SLOG << "LuaManager: Successfully opened Lua State." << std::endl;
    return true;
}

bool LuaManager::openLuaBindingLib(OpenBoundLuaLibFunctor OpenFunc)
{
    if(_State != NULL)
    {
        SLOG << "LuaManager: Opening Lua bindings lib." << std::endl;
        OpenFunc(_State);
        SLOG << "LuaManager: Succefully opened Lua bindings lib." << std::endl;
        return true;
    }
    else
    {
        SWARNING << "LuaManager: Failed to open lua binding, because the Lua State has not been created.." << std::endl;
        return false;
    }
}

bool LuaManager::uninit(void)
{
    if(_State != NULL)
    {
        SLOG << "LuaManager Uninitializing." << std::endl;

        lua_close(_State);
        _State = NULL;

        SLOG << "LuaManager Successfully Uninitialized." << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

int LuaManager::runScript(const std::string& Script)
{
    //Start the  scripts run time statistic
    StatTimeElem *ScriptsRunTimeStatElem = StatCollector::getGlobalElem(statScriptsRunTime);
    if(ScriptsRunTimeStatElem) { ScriptsRunTimeStatElem->start(); }

    //Load the Script
    int s = luaL_loadstring(_State, Script.c_str());
    checkError(s);
    if(s != 0)
    {
        //Error loading the string
        if(ScriptsRunTimeStatElem) { ScriptsRunTimeStatElem->stop(); }
        return s;
    }

    // execute Lua program
    s = lua_pcall(_State, 0, LUA_MULTRET, 0);
    checkError(s);

    if(ScriptsRunTimeStatElem) { ScriptsRunTimeStatElem->stop(); }
    return s;
}

int LuaManager::runScript(const BoostPath& ScriptPath)
{
    if(boost::filesystem::exists(ScriptPath))
    {
        //Start the  scripts run time statistic
        StatTimeElem *ScriptsRunTimeStatElem = StatCollector::getGlobalElem(statScriptsRunTime);
        if(ScriptsRunTimeStatElem) { ScriptsRunTimeStatElem->start(); }

        //Load the Script
        int s = luaL_loadfile(_State, ScriptPath.string().c_str());
        checkError(s);
        if(s != 0)
        {
            //Error loading the string
            if(ScriptsRunTimeStatElem) { ScriptsRunTimeStatElem->stop(); }
            return s;
        }

        // execute Lua program
        s = lua_pcall(_State, 0, LUA_MULTRET, 0);
        checkError(s);

        if(ScriptsRunTimeStatElem) { ScriptsRunTimeStatElem->stop(); }
        return s;
    }
    else
    {
        SWARNING << "LuaManager::runScript(): File by path: " << ScriptPath.string() << ", does not exist." << std::endl;
        return 0;
    }
}

int LuaManager::runPushedFunction(UInt32 NumArgs, UInt32 NumReturns)
{
    //Start the  scripts run time statistic
    StatTimeElem *ScriptsRunTimeStatElem = StatCollector::getGlobalElem(statScriptsRunTime);
    if(ScriptsRunTimeStatElem) { ScriptsRunTimeStatElem->start(); }

    int s = lua_pcall(_State, NumArgs, NumReturns, 0);
    checkError(s);

    //Stop the  scripts run time statistic
    if(ScriptsRunTimeStatElem) { ScriptsRunTimeStatElem->stop(); }
    return s;
}

void LuaManager::checkError(int Status)
{
    switch(Status)
    {
        case 0:
            //No Error
            break;
        case LUA_ERRSYNTAX:
            //Syntax Error
            SWARNING << "Lua Syntax Error: " << lua_tostring(_State, -1) << std::endl;
            produceLuaError(Status);
            lua_pop(_State, 1); // remove error message
            break;
        case LUA_ERRFILE:
            //File Read Error
            SWARNING << "Lua File Load Error: " << lua_tostring(_State, -1) << std::endl;
            printStackTrace();
            produceLuaError(Status);
            lua_pop(_State, 1); // remove error message
            break;
        case LUA_ERRMEM:
            //Memory Allocation Error
            SWARNING << "Lua Memory Allocation Error: " << lua_tostring(_State, -1) << std::endl;
            printStackTrace();
            produceLuaError(Status);
            lua_pop(_State, 1); // remove error message
            break;
        case LUA_ERRRUN:
            //Memory Allocation Error
            SWARNING << "Lua Runtime Error: " << lua_tostring(_State, -1) << std::endl;
            printStackTrace();
            produceLuaError(Status);
            lua_pop(_State, 1); // remove error message
            break;
        case LUA_ERRERR:
            //Memory Allocation Error
            SWARNING << "Lua Error in Error Handler: " << lua_tostring(_State, -1) << std::endl;
            printStackTrace();
            produceLuaError(Status);
            lua_pop(_State, 1); // remove error message
            break;
    }
}

void LuaManager::printStackTrace(void) const
{
    SWARNING << getCallStack();
}


void LuaManager::produceLuaError(int Status)
{
    LuaErrorEventDetailsUnrecPtr Details = LuaErrorEventDetails::create(NULL, getSystemTime(), _State, Status);
   
    produceLuaError(Details);
}

void LuaManager::setPackagePath(const std::string& Pattern)
{
    //Get the package table
    lua_getglobal(_State, "package");
    if (LUA_TTABLE != lua_type(_State, 1))
    {
        SWARNING << "LuaManager::getPackagePath(): package is not a table" << std::endl;
        return;
    }
    lua_pushlstring(_State, Pattern.c_str(), Pattern.size());
    lua_setfield(_State, 1, "path");
    lua_pop(_State, 1);
}

std::string LuaManager::getPackagePath(void) const
{
    std::string Result("");

    //Get the package table
    lua_getglobal(_State, "package");
    if (LUA_TTABLE != lua_type(_State, 1))
    {
        SWARNING << "LuaManager::getPackagePath(): package is not a table" << std::endl;
        return Result;
    }
    lua_getfield(_State, 1, "path");
    if (LUA_TSTRING != lua_type(_State, 2)) 
    {
        SWARNING << "LuaManager::getPackagePath(): package.path is not a string" << std::endl;
        lua_pop(_State, 1);
        return Result;
    }
    Result = lua_tostring(_State, 2);
    lua_pop(_State, 1);

    return Result;
}

void LuaManager::setPackageCPath(const std::string& Pattern)
{
    //Get the package table
    lua_getglobal(_State, "package");
    if (LUA_TTABLE != lua_type(_State, 1))
    {
        SWARNING << "LuaManager::getPackageCPath(): package is not a table" << std::endl;
        return;
    }
    lua_pushlstring(_State, Pattern.c_str(), Pattern.size());
    lua_setfield(_State, 1, "cpath");
    lua_pop(_State, 1);
}

std::string LuaManager::getPackageCPath(void) const
{
    std::string Result("");

    //Get the package table
    lua_getglobal(_State, "package");
    if (LUA_TTABLE != lua_type(_State, 1))
    {
        SWARNING << "LuaManager::getPackageCPath(): package is not a table" << std::endl;
        return Result;
    }
    lua_getfield(_State, 1, "cpath");
    if (LUA_TSTRING != lua_type(_State, 2)) 
    {
        SWARNING << "LuaManager::getPackageCPath(): package.cpath is not a string" << std::endl;
        lua_pop(_State, 1);
        return Result;
    }
    Result = lua_tostring(_State, 2);
    lua_pop(_State, 1);

    return Result;
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

LuaManager::LuaManager(void) 
{    
}

LuaManager::LuaManager(const LuaManager &source) 
{
    assert(false && "Sould NOT CALL LuaManager copy constructor");
}

LuaManager::~LuaManager(void)
{
}

OSG_END_NAMESPACE
