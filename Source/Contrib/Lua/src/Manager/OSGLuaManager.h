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

#ifndef _OSGLUAMANAGER_H_
#define _OSGLUAMANAGER_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGContribLuaDef.h"

#include "lua.hpp"
#include <list>

#include "OSGEventProducerType.h"
#include "OSGLuaErrorEventDetails.h"
#include "OSGConsumableEventCombiner.h"
#include "OSGEventDescription.h"
#include "OSGActivity.h"
#include "OSGPathType.h"
#include "OSGStatElemTypes.h"

#include <boost/function.hpp>


OSG_BEGIN_NAMESPACE

/*! \brief LuaManager class. See \ref 
  PageSoundLuaManager for a description.
  */

class OSG_CONTRIBLUA_DLLMAPPING LuaManager
{
    friend class LuaActivity;

  private:

    /*==========================  PUBLIC  =================================*/
  public:
    typedef LuaErrorEventDetails LuaErrorEventDetailsType;
    typedef boost::signals2::signal<void (LuaErrorEventDetails* const, UInt32), ConsumableEventCombiner> LuaErrorEventType;
    typedef boost::function<int ( lua_State* )> OpenBoundLuaLibFunctor;

    enum
    {
        LuaErrorEventId = 1,
        NextEventId     = LuaErrorEventId            + 1
    };

    static LuaManager* the(void);

    int runScript(const std::string& Script);
    int runScript(const BoostPath& ScriptPath);
    int runPushedFunction(UInt32 NumArgs, UInt32 NumReturns);

    static void report_errors(lua_State *L, int status);

    static bool init(void);
    bool recreateLuaState(void);
    bool openLuaBindingLib(OpenBoundLuaLibFunctor OpenFunc);
    static bool uninit(void);

    void setPackagePath(const std::string& Pattern);
    std::string getPackagePath(void) const;

    void setPackageCPath(const std::string& Pattern);
    std::string getPackageCPath(void) const;

    static const  EventProducerType  &getProducerClassType  (void); 
    static        UInt32              getProducerClassTypeId(void); 
    virtual const EventProducerType &getProducerType(void) const; 

    boost::signals2::connection          attachActivity(UInt32 eventId,
                                                       Activity* TheActivity);
    UInt32                   getNumProducedEvents(void)          const;
    const EventDescription *getProducedEventDescription(const   Char8 *ProducedEventName) const;
    const EventDescription *getProducedEventDescription(UInt32  ProducedEventId) const;
    UInt32                   getProducedEventId(const            Char8 *ProducedEventName) const;

    boost::signals2::connection connectLuaError(const LuaErrorEventType::slot_type &listener,
                                                       boost::signals2::connect_position at= boost::signals2::at_back);
    boost::signals2::connection connectLuaError(const LuaErrorEventType::group_type &group,
                                                       const LuaErrorEventType::slot_type &listener,
                                                       boost::signals2::connect_position at= boost::signals2::at_back);
    void   disconnectLuaError       (const LuaErrorEventType::group_type &group);
    void   disconnectAllSlotsLuaError(void);
    bool   isEmptyLuaError          (void) const;
    UInt32 numSlotsLuaError         (void) const;

    lua_State *getLuaState(void);
    void checkError(int Status);

    static StatElemDesc<StatTimeElem   > statScriptsRunTime;
    /*==========================  PRIVATE  ================================*/
  private:

    static LuaManager* _the;

    static EventDescription   *_eventDesc[];
    static EventProducerType _producerType;
    LuaErrorEventType _LuaErrorEvent;

    // Variables should all be in StubSoundManagerBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    LuaManager(void);
    LuaManager(const LuaManager &source);
    LuaManager& operator=(const LuaManager &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~LuaManager(void); 

    /*! \}                                                                 */

    void printStackTrace(void) const;


    static lua_State *_State;

    void produceLuaError(int Status);
    
    void produceLuaError(LuaErrorEventDetailsType* const e);

};

typedef LuaManager *LuaManagerP;

OSG_END_NAMESPACE

#include "OSGLuaManager.inl"

#endif /* _OSGLUAMANAGER_H_ */

