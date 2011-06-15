/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
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

OSG_BEGIN_NAMESPACE
inline
bool Component::getStateByMask(UInt64 Mask) const
{
    return (getState() & Mask) != 0;
}

inline
void Component::setStateByMask(UInt64 Mask, const bool value)
{
    setState(value ? (getState() | Mask) : (getState() & ~Mask));
}

inline
bool Component::getStateById(UInt16 Id) const
{
    return (getState() & (TypeTraits<BitVector>::One << Id)) != 0;
}

inline
void Component::setStateById(UInt16 Id, const bool value)
{
    setStateByMask((TypeTraits<BitVector>::One << Id), value);
}

inline
bool Component::getEnabled  (void) const
{
    return getStateByMask(EnabledStateMask);
}

inline
bool Component::getVisible  (void) const
{
    return getStateByMask(VisibleStateMask);
}

inline
bool Component::getFocused  (void) const
{
    return getStateByMask(FocusedStateMask);
}

inline
bool Component::getMouseOver(void) const
{
    return getStateByMask(MouseOverStateMask);
}

inline
bool Component::getToolTipActive(void) const
{
    return getStateByMask(ToolTipActiveStateMask);
}

inline
void Component::setEnabled  (const bool value)
{
    setStateByMask(EnabledStateMask, value);
}

inline
void Component::setVisible  (const bool value)
{
    setStateByMask(VisibleStateMask, value);
}

inline
void Component::setFocused  (const bool value)
{
    setStateByMask(FocusedStateMask, value);
}

inline
void Component::setMouseOver(const bool value)
{
    setStateByMask(MouseOverStateMask, value);
}

inline
void Component::setToolTipActive(const bool value)
{
    setStateByMask(ToolTipActiveStateMask, value);
}

inline
void Component::getClipBounds(Pnt2f& TopLeft, Pnt2f& BottomRight) const
{
    TopLeft = getClipTopLeft();
    BottomRight = getClipBottomRight();
}


inline
void Component::setMouseContained(bool Value)
{
    setMouseOver(Value);
}

inline
bool Component::getMouseContained(void)
{
    return getMouseOver();
}

inline
void Component::moveFocusNext(void)
{
    moveFocus(1);
}

inline
void Component::moveFocusPrev(void)
{
    moveFocus(-1);
}

inline
bool Component::isToolTipActive(void) const
{
    return (getToolTip() != NULL && 
            getToolTipActive());
}

OSG_END_NAMESPACE
