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
//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include "OSGConfig.h"

#include "OSGFCPtrEditorEventProducerStore.h"
#include "OSGFieldContainerFactory.h"

OSG_USING_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::FCPtrEditorEventProducerStore
A FCPtrEditorEventProducerStore. 
*/

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/
FCPtrEditorEventProducerStorePtr
FCPtrEditorEventProducerStore::create(ReflexiveContainer::EventDescPair type,
                                      const FieldContianerVector& Exclude,
                                      const FieldContianerTypeVector& ExcludeTypes)
{
    return FCPtrEditorEventProducerStorePtr(new FCPtrEditorEventProducerStore(type, Exclude, ExcludeTypes));
}

FCPtrEditorEventProducerStorePtr FCPtrEditorEventProducerStore::create(void)
{
    return FCPtrEditorEventProducerStorePtr(new FCPtrEditorEventProducerStore());
}

/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/
FCPtrEditorStorePtr FCPtrEditorEventProducerStore::clone(void) const
{
    return FCPtrEditorStorePtr(new FCPtrEditorEventProducerStore(*this));
}

void FCPtrEditorEventProducerStore::updateList(void)
{
    _Store.clear();
    if(_EventTypeToStore.second == NULL)
    {
        return;
    }

    const FieldContainerFactoryBase::ContainerStore &FCStore(FieldContainerFactory::the()->getFieldContainerStore () );

    FieldContainerFactoryBase::ContainerStore::const_iterator FCStoreIter;
    FieldContainerFactoryBase::ContainerPtr Cont;
    for(FCStoreIter = FCStore.begin() ; FCStoreIter != FCStore.end() ; ++FCStoreIter)
    {
        if(*FCStoreIter == NULL)
        {
            continue;
        }
#ifdef OSG_MT_CPTR_ASPECT
        Cont = (*FCStoreIter)->getPtr();
#else
        Cont = *FCStoreIter;
#endif
        EventDescription const *
            LocalDesc(Cont->getEventDescription(_EventTypeToStore.first.c_str()));

        if(LocalDesc != NULL &&  //Container produces the event type
           LocalDesc->getEventArgumentType() == (*_EventTypeToStore.second) &&
           !isExcluded(Cont) && //Container is not specifically excluded
           Cont != Cont->getType().getPrototype()  //Container is not a prototype
          )
        {
            _Store.push_back(Cont);
        }
    }
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

FCPtrEditorEventProducerStore::FCPtrEditorEventProducerStore(void) :
    Inherited(),
    _EventTypeToStore("",static_cast<const TypeBase*>(NULL))
{
}

FCPtrEditorEventProducerStore::FCPtrEditorEventProducerStore(ReflexiveContainer::EventDescPair type,
                                         const FieldContianerVector& Exclude,
                                         const FieldContianerTypeVector& ExcludeTypes) :
    Inherited(FieldContianerVector(),Exclude,ExcludeTypes),
    _EventTypeToStore(type)
{
    updateList();
}

FCPtrEditorEventProducerStore::FCPtrEditorEventProducerStore(const FCPtrEditorEventProducerStore& source) :
    Inherited(source),
    _EventTypeToStore(source._EventTypeToStore)
{
    updateList();
}


FCPtrEditorEventProducerStore::~FCPtrEditorEventProducerStore(void)
{
}

/*----------------------------- class specific ----------------------------*/
void FCPtrEditorEventProducerStore::operator =(const FCPtrEditorEventProducerStore& source)
{
    if(this == &source)
    {
        return;
    }

    Inherited::operator=(source);
    _EventTypeToStore = source._EventTypeToStore;
}

