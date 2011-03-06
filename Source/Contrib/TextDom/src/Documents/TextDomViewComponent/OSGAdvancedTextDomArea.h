/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 * contact: Achyuthan Vasanth (vasanth.achyuthan@gmail.com)                  *
 *          David Kabala (djkabala@gmail.com)                                *
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

#ifndef _OSGADVANCEDTEXTDOMAREA_H_
#define _OSGADVANCEDTEXTDOMAREA_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGAdvancedTextDomAreaBase.h"
#include "OSGScrollPanelFields.h"

OSG_BEGIN_NAMESPACE

/*! \brief AdvancedTextDomArea class. See \ref
           PageContribTextDomAdvancedTextDomArea for a description.
*/

class OSG_CONTRIBTEXTDOM_DLLMAPPING AdvancedTextDomArea : public AdvancedTextDomAreaBase
{
  protected:




    
    /*==========================  PUBLIC  =================================*/

  public:

    
    std::string getText(void) const;
    void clear(void);
    void write(const std::string& txt);
    
    virtual Vec2f getContentRequestedSize(void) const;

    void setTextDomArea(TextDomArea* const duplicatedTextDom);
    TextDomArea* getTextDomArea(void) const;

    std::string getHighlightedString(void) const;
    virtual void updateLayout(void);
    void loadFile(const BoostPath& path);
    AdvancedTextDomAreaTransitPtr createDuplicate(void) const;
    void setText(const std::string& txt);
    void setEditable(bool val);


    /*---------------------------------------------------------------------*/
    /*! \name                      Gutter                                  */
    /*! \{                                                                 */
    Vec2f getGutterSize(void) const;
    Real32 getGutterWidth(void) const;
    void setGutterWidth(Real32 Width);

    const Vec2f&   getGutterAlignment(void) const;
    const Color4f& getGutterTextColor(void) const;
    UIFont*        getGutterFont     (void) const;

    void setGutterAlignment(const Vec2f& Align);
    void setGutterTextColor(const Color4f& Color);
    void setGutterFont     (UIFont* const Font);

    /*! \}                                                                 */

    typedef AdvancedTextDomAreaBase Inherited;
    typedef AdvancedTextDomArea     Self;

    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    virtual void changed(ConstFieldMaskArg whichField,
                         UInt32            origin,
                         BitVector         details    );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
    /*! \{                                                                 */

    void onCreate(const AdvancedTextDomArea *source = NULL);
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual void dump(      UInt32     uiIndent = 0,
                      const BitVector  bvFlags  = 0) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:
    /*! \}                                                                 */

    // Variables should all be in AdvancedTextDomAreaBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    AdvancedTextDomArea(void);
    AdvancedTextDomArea(const AdvancedTextDomArea &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~AdvancedTextDomArea(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

    virtual void resolveLinks(void);

    /*! \}                                                                 */
    ScrollPanelRefPtr _ScrollPanel;
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class AdvancedTextDomAreaBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const AdvancedTextDomArea &source);
};

typedef AdvancedTextDomArea *AdvancedTextDomAreaP;

OSG_END_NAMESPACE

#include "OSGGlyphView.h"

#include "OSGAdvancedTextDomAreaBase.inl"
#include "OSGAdvancedTextDomArea.inl"

#endif /* _OSGADVANCEDTEXTDOMAREA_H_ */
