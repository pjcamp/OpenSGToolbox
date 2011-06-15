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
bool Button::getActive(void) const
{
    return getStateByMask(ActiveStateMask);
}

inline
void Button::setActive(bool Value)
{
    setStateByMask(ActiveStateMask, Value);
}

inline
bool Button::getArmed(void) const
{
    return getStateByMask(ArmedStateMask);
}

inline
void Button::setArmed(bool Value)
{
    setStateByMask(ArmedStateMask, Value);
}

inline
void Button::resetArmed(void)
{
    _ActionFireElps = 0.0;
}

inline
void Button::setTextures(TextureObjChunk* const TheTexture, Vec2f Size)
{
    setTexture        (TheTexture, Size);
    setActiveTexture  (TheTexture, Size);
    setFocusedTexture (TheTexture, Size);
    setRolloverTexture(TheTexture, Size);
    setDisabledTexture(TheTexture, Size);
}

inline
void Button::setImages(const BoostPath& Path, Vec2f Size)
{
    setImages(Path.string(), Size);
}

OSG_END_NAMESPACE
