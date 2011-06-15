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

#include <cstdlib>
#include <cstdio>

#include <OSGConfig.h>

#include "OSGRadioButton.h"
#include "OSGUIDrawUtils.h"

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGRadioButtonBase.cpp file.
// To modify it, please change the .fcd file (OSGRadioButton.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void RadioButton::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
    }
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

UIDrawObjectCanvas* RadioButton::getDrawnDrawObject(void) const
{
    if(getEnabled())
    {
        if(getActive())
        {
            if(getSelected())
            {
                return getActiveRadioDrawObject();
            }
            else
            {
                return getActiveSelectedRadioDrawObject();
            }
        }
        else if(getMouseOver())
        {
            if(getSelected())
            {
                return getRolloverSelectedRadioDrawObject();
            }
            else
            {
                return getRolloverRadioDrawObject();
            }
        }
        else
        {
            if(getSelected())
            {
                return getSelectedRadioDrawObject();
            }
            else
            {
                return getRadioDrawObject();
            }
        }
    }
    else
    {
        if(getSelected())
        {
            return getDisabledSelectedRadioDrawObject();
        }
        else
        {
            return getDisabledRadioDrawObject();
        }
    }
}

UIDrawObjectCanvas* RadioButton::getBaseDrawObject(void) const
{
    return getRadioDrawObject();          
}

void RadioButton::actionPreformed(ActionEventDetails* const e)
{
    setSelected(true);
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

RadioButton::RadioButton(void) :
    Inherited()
{
}

RadioButton::RadioButton(const RadioButton &source) :
    Inherited(source)
{
}

RadioButton::~RadioButton(void)
{
}

/*----------------------------- class specific ----------------------------*/

void RadioButton::changed(ConstFieldMaskArg whichField, 
                            UInt32            origin,
                            BitVector         details)
{
    Inherited::changed(whichField, origin, details);

    //Do not respond to changes that have a Sync origin
    if(origin & ChangedOrigin::Sync)
    {
        return;
    }

    if(whichField & RadioDrawObjectFieldMask &&
        getRadioDrawObject() != NULL)
    {
        getRadioDrawObject()->setSize(getRadioDrawObject()->getRequestedSize());
    }
    
    if(whichField & SelectedRadioDrawObjectFieldMask &&
        getSelectedRadioDrawObject() != NULL)
    {
        getSelectedRadioDrawObject()->setSize(getSelectedRadioDrawObject()->getRequestedSize());
    }
    
    if(whichField & ActiveRadioDrawObjectFieldMask &&
        getActiveRadioDrawObject() != NULL)
    {
        getActiveRadioDrawObject()->setSize(getActiveRadioDrawObject()->getRequestedSize());
    }
    
    if(whichField & ActiveSelectedRadioDrawObjectFieldMask &&
        getActiveSelectedRadioDrawObject() != NULL)
    {
        getActiveSelectedRadioDrawObject()->setSize(getActiveSelectedRadioDrawObject()->getRequestedSize());
    }
    
    if(whichField & RolloverRadioDrawObjectFieldMask &&
        getRolloverRadioDrawObject() != NULL)
    {
        getRolloverRadioDrawObject()->setSize(getRolloverRadioDrawObject()->getRequestedSize());
    }
    
    if(whichField & RolloverSelectedRadioDrawObjectFieldMask &&
        getRolloverSelectedRadioDrawObject() != NULL)
    {
        getRolloverSelectedRadioDrawObject()->setSize(getRolloverSelectedRadioDrawObject()->getRequestedSize());
    }
    
    if(whichField & DisabledRadioDrawObjectFieldMask &&
        getDisabledRadioDrawObject() != NULL)
    {
        getDisabledRadioDrawObject()->setSize(getDisabledRadioDrawObject()->getRequestedSize());
    }
    
    if(whichField & DisabledSelectedRadioDrawObjectFieldMask &&
        getDisabledSelectedRadioDrawObject() != NULL)
    {
        getDisabledSelectedRadioDrawObject()->setSize(getDisabledSelectedRadioDrawObject()->getRequestedSize());
    }
}

void RadioButton::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump RadioButton NI" << std::endl;
}

OSG_END_NAMESPACE
