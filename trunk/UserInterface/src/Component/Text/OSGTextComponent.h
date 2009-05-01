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

#ifndef _OSGTEXTCOMPONENT_H_
#define _OSGTEXTCOMPONENT_H_
#ifdef __sgi
#pragma once
#endif

#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"

#include "OSGTextComponentBase.h"
#include "Event/OSGTextListener.h"

#include <OpenSG/Input/OSGEventConnection.h>

OSG_BEGIN_NAMESPACE

/*! \brief TextComponent class. See \ref 
           PageUserInterfaceTextComponent for a description.
*/

class OSG_USERINTERFACELIB_DLLMAPPING TextComponent : public TextComponentBase
{
  private:

    typedef TextComponentBase Inherited;

    /*==========================  PUBLIC  =================================*/
  public:

    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    virtual void changed(BitVector  whichField, 
                         UInt32     origin    );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual void dump(      UInt32     uiIndent = 0, 
                      const BitVector  bvFlags  = 0) const;

    /*! \}                                                                 */
    EventConnection addTextListener(TextListenerPtr Listener);
	bool isTextListenerAttached(TextListenerPtr Listener) const;
    void removeTextListener(TextListenerPtr Listener);
	
	virtual void keyTyped(const KeyEvent& e);

	virtual void select(const UInt32& index1,
						const UInt32& index2);
	virtual void selectAll(void);
	virtual void setSelectionStart(const UInt32& index);
	virtual void setSelectionEnd(const UInt32& index);
	virtual std::string getSelectedText(void)const;

    static const OSG::BitVector TextColorsFieldMask;
	virtual void setTextColors(const Color4f& TheColor);
    /*=========================  PROTECTED  ===============================*/
  protected:

    // Variables should all be in TextComponentBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    TextComponent(void);
    TextComponent(const TextComponent &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~TextComponent(void); 

    /*! \}                                                                 */
	UInt32 _TextSelectionStart;
	UInt32 _TextSelectionEnd;
    
	typedef std::set<TextListenerPtr> TextListenerSet;
    typedef TextListenerSet::iterator TextListenerSetItor;
    typedef TextListenerSet::const_iterator TextListenerSetConstItor;
	
    TextListenerSet       _TextListeners;
    void produceTextValueChanged(const TextEvent& e);
    virtual Color4f getDrawnTextColor(void) const;
    
    /*==========================  PRIVATE  ================================*/
  private:

    friend class FieldContainer;
    friend class TextComponentBase;

    static void initMethod(void);

    // prohibit default functions (move to 'public' if you need one)

    void operator =(const TextComponent &source);
};

typedef TextComponent *TextComponentP;

OSG_END_NAMESPACE

#include "OSGTextComponentBase.inl"
#include "OSGTextComponent.inl"

#define OSGTEXTCOMPONENT_HEADER_CVSID "@(#)$Id: FCTemplate_h.h,v 1.23 2005/03/05 11:27:26 dirk Exp $"

#endif /* _OSGTEXTCOMPONENT_H_ */