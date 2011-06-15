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

#ifndef _OSGSTYLEDDOCUMENT_H_
#define _OSGSTYLEDDOCUMENT_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"

#include "OSGStyledDocumentBase.h"

#include "OSGStyledDocumentBranchElementFields.h"
#include "OSGStyledDocumentLeafElementFields.h"

OSG_BEGIN_NAMESPACE

/*! \brief StyledDocument class. See \ref
           PageContribTextDomStyledDocument for a description.
*/

class OSG_CONTRIBTEXTDOM_DLLMAPPING StyledDocument : public StyledDocumentBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  private:
    
    UInt32 _DocumentSize;

    void tokenize(std::string sentence,std::vector<std::string> & setOfWords);
    bool equals(DocumentElementAttribute &oldProps,DocumentElementAttribute &newProps);
    void removeTheSlashN(std::string& stringWithSlashN);

  public:

    typedef StyledDocumentBase Inherited;
    typedef StyledDocument     Self;

    void  displayDebugInfo(void);
    //This method allows an application to mark a place in a sequence of character content.
    UInt32 createPosition(Int32 offs);

    //Returns the root element that views should be based upon, unless some other mechanism for assigning views to element structures is provided.
    Element* getDefaultRootElement(void) const;

    //Returns a position that represents the end of the document.
    UInt32 getEndPosition(void) const;

    //Returns number of characters of content currently in the document.(including endlines)
    UInt32 getLength(void) const;

    //Element* getRootElement(UInt32 index);

    //Returns all of the root elements that are defined.
    std::vector<Element*> getRootElements(void);

    //Returns a position that represents the start of the document.
    UInt64 getStartPosition(void) const;

    //Fetches the text with properties contained within the given portion of the document.
    std::vector<DocumentElementAttribute> getDocumentElementAttribute(Int32 offset, Int32 length) const;

    //Fetches the text with properties contained within the given portion of the document.
    void getDocumentElementAttribute(Int32 offset, Int32 length, std::vector<DocumentElementAttribute>& txt) const;

    //Fetches the text contained within the given portion of the document.
    std::string getText(Int32 offset, Int32 length) const;

    //Fetches the text contained within the given portion of the document.
    void getText(Int32 offset, Int32 length, std::string& txt) const;


    void removeElement(UInt32 leafElementIndex,
                       StyledDocumentBranchElement* const rootElement);

    void addElements(Int32 theLeafElementIndex,
                     const std::string& theCharactersBefore,
                     const std::string& theCharactersAfter,
                     std::vector<std::string> &setOfWords,
                     StyledDocumentBranchElement* const rootElement,
                     DocumentElementAttribute &oldProps,
                     DocumentElementAttribute &newProps);

    
    //Removes a portion of the content of the document.
    void remove(Int32 offs, Int32 len);


    //Deletes the region of text from offset to offset + length, and replaces it with text.
    void replace(Int32 offset, Int32 length, const std::string& str, DocumentElementAttribute& properties);


    void setFonts(const std::vector<std::string>& fontArray);
    void setColors(const std::vector<Color3f>& colorArray);
    const std::vector<Color3f>& getColors(void) const;
    const std::vector<std::string>& getFonts(void) const;

    void addTextAsNewElementToDocument(const std::string& str, DocumentElementAttribute& properties,bool createFreshDocument);

    void insertString(UInt32 offset, const std::string& str, DocumentElementAttribute& properties);

    void insertCharacter(UInt32 offset, const char character, DocumentElementAttribute& properties);

    void insertCharacter(UInt32 offsetInElement,UInt32 elementIndex, const char character, DocumentElementAttribute& properties);

    void deleteCharacter(UInt32 elementIndex,UInt32 offsetInChild);

    void deleteCharacters(UInt32 lesserIndex,UInt32 lesserOffset,UInt32 greaterIndex,UInt32 greaterOffset);

    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    virtual void changed(ConstFieldMaskArg whichField,
                         UInt32            origin,
                         BitVector         details    );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual void dump(      UInt32     uiIndent = 0,
                      const BitVector  bvFlags  = 0) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

      
    
    std::vector<std::string> _Fonts;
    std::vector<Color3f> _Colors;

    

    // Variables should all be in StyledDocumentBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    StyledDocument(void);
    StyledDocument(const StyledDocument &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~StyledDocument(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class StyledDocumentBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const StyledDocument &source);
};

typedef StyledDocument *StyledDocumentP;

OSG_END_NAMESPACE

#include "OSGElement.h"

#include "OSGStyledDocumentBase.inl"
#include "OSGStyledDocument.inl"

#endif /* _OSGSTYLEDDOCUMENT_H_ */
