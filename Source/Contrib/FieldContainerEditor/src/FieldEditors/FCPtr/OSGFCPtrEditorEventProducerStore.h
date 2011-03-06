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
#ifndef _OSGFCPTREDITOREVENTPRODUCERSTORE_H_
#define _OSGFCPTREDITOREVENTPRODUCERSTORE_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGContribFieldContainerEditorDef.h"

#include "OSGFCPtrEditorStore.h"

OSG_BEGIN_NAMESPACE

class FCPtrEditorEventProducerStore;
typedef boost::shared_ptr<FCPtrEditorEventProducerStore> FCPtrEditorEventProducerStorePtr;

class OSG_CONTRIBFIELDCONTAINEREDITOR_DLLMAPPING FCPtrEditorEventProducerStore : public FCPtrEditorStore
{
  public:
    typedef FCPtrEditorStore Inherited;

    virtual ~FCPtrEditorEventProducerStore(void);

    void operator =(const FCPtrEditorEventProducerStore& source);

    virtual FCPtrEditorStorePtr clone(void) const;

    ReflexiveContainer::EventDescPair getEventTypeToStore(void) const;
    virtual void setEventTypeToStore(ReflexiveContainer::EventDescPair type);

    static FCPtrEditorEventProducerStorePtr
        create(ReflexiveContainer::EventDescPair type,
              const FieldContianerVector& Exclude = FieldContianerVector(),
              const FieldContianerTypeVector& ExcludeTypes = FieldContianerTypeVector());

    static FCPtrEditorEventProducerStorePtr create(void);

  protected:
    FCPtrEditorEventProducerStore(void);

    FCPtrEditorEventProducerStore(ReflexiveContainer::EventDescPair type,
                                  const FieldContianerVector& Exclude = FieldContianerVector(),
                                  const FieldContianerTypeVector& ExcludeTypes = FieldContianerTypeVector());

    FCPtrEditorEventProducerStore(const FCPtrEditorEventProducerStore& source);

    virtual void updateList(void);

    ReflexiveContainer::EventDescPair _EventTypeToStore;
};

OSG_END_NAMESPACE

#include "OSGFCPtrEditorEventProducerStore.inl"

#endif /* _OSGFCPTREDITOREVENTPRODUCERSTORE_H_ */
