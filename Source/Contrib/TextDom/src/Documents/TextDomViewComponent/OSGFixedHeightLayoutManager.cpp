/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 *   contact: dirk@opensg.org, gerrit.voss@vossg.org, jbehr@zgdv.de          *
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

#define OSG_COMPILECONTRIBTEXTDOMLIB

#include <OSGConfig.h>

#include "OSGDocument.h"
#include "OSGElement.h"
#include "OSGTextDomArea.h"
#include "OSGGlyphView.h"
#include "OSGPlainDocumentBranchElement.h"
#include "OSGPlainDocumentLeafElement.h"
#include "OSGFixedHeightLayoutManager.h"
#include "OSGUIViewport.h"
#include "OSGStringUtils.h"
#include "OSGTextDomUtils.h"

#define LINEHEIGHT 15.0;

#define HSL _HighlightStartLine
#define HSI _HighlightStartIndex
#define HEL _HighlightEndLine
#define HEI _HighlightEndIndex

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGFixedHeightLayoutManagerBase.cpp file.
// To modify it, please change the .fcd file (OSGFixedHeightLayoutManager.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/


void FixedHeightLayoutManager::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
    }
}

/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

void FixedHeightLayoutManager::setTheClipBounds(Pnt2f topLeft,Pnt2f bottomRight)
{
    _TheClipBoundsTopLeft = topLeft;
    _TheClipBoundsBottomRight = bottomRight;
    updateViews();
}

void FixedHeightLayoutManager::setCaretIndexAndLine(UInt32 _theOriginalCaretIndex,UInt32 _theOriginalCaretLine)
{
    _CaretIndex = _theOriginalCaretIndex;
    _CaretLine = _theOriginalCaretLine;
    recalculateCaretPositions();
}

char FixedHeightLayoutManager::getNextCharacter(UInt32 _theOriginalCaretIndex,
                                                UInt32 _theOriginalCaretLine) const
{
    PlainDocumentLeafElementRefPtr temp = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(_theOriginalCaretLine));
    if(temp->getTextLength()-2 == _theOriginalCaretIndex)
    {
        temp = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(_theOriginalCaretLine+1));
        std::string tempstring = temp->getText();
        return tempstring[0];
    }
    else
    {
        std::string tempstring = temp->getText();
        return tempstring[_theOriginalCaretIndex];
    }

}


bool FixedHeightLayoutManager::isLastCharacterOfLine(UInt32 _theOriginalCaretIndex,UInt32 _theOriginalCaretLine) const
{
    if(rootElement)
    {
        PlainDocumentLeafElementRefPtr temp = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(_theOriginalCaretLine));
        if(temp->getTextLength()-2 == _theOriginalCaretIndex)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else 
    {
        return true;
    }
}

UInt32 FixedHeightLayoutManager::CaretLineAndIndexToCaretOffsetInDOM(UInt32 CaretLine,UInt32 CaretIndex)
{
    UInt32 offset = 0;
    if(rootElement)
    {
        for(UInt32 i=0;i<CaretLine;i++)
        {
            PlainDocumentLeafElementRefPtr temp = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(i));
            offset += temp->getTextLength();
        }
        offset += CaretIndex;
    }
    return offset;
}

void FixedHeightLayoutManager::deleteCharacters(UInt32 lesserLine,UInt32 lesserIndex,UInt32 greaterLine,UInt32 greaterIndex)
{
    std::string theHighlightedString = getParentTextDomArea()->getHighlightedString();
    //if(_CaretIndex == greaterIndex && _CaretLine == greaterLine)
    //{
    //    // caret position should be shifted back by length of theHighlightedString
    //    getParentTextDomArea()->setCaretPosition(getParentTextDomArea()->getCaretPosition()-theHighlightedString.length());
    //}
    //else
    //{
    //    //do nothing
    //}
    getParentTextDomArea()->getDocumentModel()->deleteCharacters(lesserLine,lesserIndex,greaterLine,greaterIndex);
    HSL = HEL = _CaretLine = lesserLine;
    HSI = HEI = _CaretIndex = lesserIndex;
    recalculateCaretPositions();
}

void FixedHeightLayoutManager::selectAll(void)
{
    HSL = 0;
    HSI = 0;
    HEL = rootElement->getElementCount()-1;
    PlainDocumentLeafElementRefPtr temp = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(HEL));
    HEI = temp->getTextLength()-2;

    _CaretLine = HEL;
    _CaretIndex = HEI;

    recalculateCaretPositions();
}

void FixedHeightLayoutManager::deleteSelected(void)
{
    if(isStartLocationBeforeEndLocation())
        deleteCharacters(HSL,HSI,HEL,HEI);
    else
        deleteCharacters(HEL,HEI,HSL,HSI);
}

bool FixedHeightLayoutManager::isLastCharacterOfDocument() const
{
    if(_CaretLine == rootElement->getElementCount()-1)
    {
        PlainDocumentLeafElementRefPtr temp = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(_CaretLine));
        if(_CaretIndex >= temp->getTextLength()-2) return true;
    }
    return  false;
}

void FixedHeightLayoutManager::highlightString(UInt32 _theOriginalCaretLine,UInt32 _theOriginalCaretIndex,std::string _StringToBeInserted)
{
    HSL = HEL = _theOriginalCaretLine;
    HSI = HEI = _theOriginalCaretIndex;
    for(UInt32 i=0;i<_StringToBeInserted.size();i++)
    {
        HEI++;
        if(_StringToBeInserted[i] == '\n' || _StringToBeInserted[i] == '\r')
        {
            if(i+1<_StringToBeInserted.size() && (_StringToBeInserted[i+1] == '\n' || _StringToBeInserted[i+1] == '\r'))
            {
                i++;
            }
            HEI = 0;
            HEL++;
        }
    }
}

UInt32 FixedHeightLayoutManager::getTopmostVisibleLineNumber() const
{
    Pnt2f topLeft,bottomRight;
    getParentTextDomArea()->getClipBounds(topLeft,bottomRight);
    UInt32 topmostVisibleLineNumber = UInt32(floor((topLeft.y()) / heightOfLine));
    return topmostVisibleLineNumber; 
}

UInt32 FixedHeightLayoutManager::getLinesToBeDisplayed() const
{
    Pnt2f topLeft,bottomRight;
    getParentTextDomArea()->getClipBounds(topLeft,bottomRight);

    UInt32 linesToBeDisplayed = 0;
    if(bottomRight.x() == 0 && bottomRight.y() == 0 )
        linesToBeDisplayed = (UInt32(ceil(getParentTextDomArea()->getPreferredSize().y()/ heightOfLine)));
    else
        linesToBeDisplayed = (UInt32(ceil((bottomRight.y() - topLeft.y())/heightOfLine)));

    return linesToBeDisplayed;
}


void FixedHeightLayoutManager::updateSize()
{
    _preferredHeight = rootElement->getElementCount() * heightOfLine;
}

void FixedHeightLayoutManager::initializeRootElement() 
{
    if(getParentTextDomArea())
    {
        if(getParentTextDomArea()->getDocumentModel())
        {
            defaultRoot=getParentTextDomArea()->getDocumentModel()->getDefaultRootElement();
            rootElement = dynamic_cast<PlainDocumentBranchElement*>(defaultRoot);
        }
    }
}

void FixedHeightLayoutManager::updateViews(void)
{
    if(rootElement)
    {
        Pnt2f init = getParentTextDomArea()->getPosition();

        UInt32 lineNumber = getTopmostVisibleLineNumber();
        UInt32 linesToBeDisplayed = getLinesToBeDisplayed();

        clearVisibleViews();

        if(getParentTextDomArea()->getWrapStyleWord())
        {
            if(linesToElements.size()==0)
            {
                SWARNING<<"FixedHeightLayoutManager::updateViews_orig(void) : Cache is empty"<<std::endl;
                return;
            }

            UInt32 initLineNumber = lineNumber;
            for(UInt32 i=0;i<linesToBeDisplayed;i++,lineNumber++)
            {
                if(lineNumber<linesToElements.size())
                {
                    if( lineNumber == initLineNumber || (lineNumber != initLineNumber && linesToElements[lineNumber]!= linesToElements[lineNumber-1]))
                    {
                        GlyphViewRefPtr view = GlyphView::create();
                        view->setElement(rootElement->getElement(linesToElements[lineNumber]));
                        view->setLines(getNumberOfLines(getFirstLineOfElement(lineNumber)));
                        view->setLineHeight(heightOfLine);
                        view->setLineWidth(/*init.x()+*/getParentTextDomArea()->getPreferredSize().x());
                        view->setFont(getParentTextDomArea()->getFont());


                        if(lineNumber == initLineNumber)    // get the linenumber where the element corresponding to this line was first drawn
                            view->setInitialPosition(Pnt2f(0,/*init.y()+*/getFirstLineOfElement(lineNumber)*heightOfLine));
                        else
                            view->setInitialPosition(Pnt2f(0,/*init.y()+*/lineNumber*heightOfLine));

                        pushToVisibleViews(view);

                    }
                }
                else break;

            }
        }
        else
        {
            for(UInt32 i=0;i<linesToBeDisplayed;i++)
            {
                if(lineNumber<rootElement->getElementCount())
                {
                    GlyphViewRefPtr view = GlyphView::create();
                    view->setElement(rootElement->getElement(lineNumber));
                    view->setInitialPosition(Pnt2f(/*init.x()+*/_GutterSpace+_GutterSeparation,/*init.y()+*/lineNumber*heightOfLine));
                    view->setFont(getParentTextDomArea()->getFont());
                    view->setLineNumber(lineNumber+1);
                    pushToVisibleViews(view);
                    lineNumber++;
                }
                else break;
            }
        }
    }
}



UInt32 FixedHeightLayoutManager::getFirstLineOfElement(UInt32 lineNumber) const
{
    UInt32 initElement = linesToElements[lineNumber];
    while(lineNumber >= 1 && linesToElements[lineNumber-1]==initElement)lineNumber--;
    return lineNumber;
}


UInt32 FixedHeightLayoutManager::totalNumberOfLines(void)
{
    if(getParentTextDomArea()->getWrapStyleWord()) return linesToElements.size();
    else 
    {
        ElementRefPtr defaultRoot=getParentTextDomArea()->getDocumentModel()->getDefaultRootElement();
        PlainDocumentBranchElementRefPtr rootElement = dynamic_pointer_cast<PlainDocumentBranchElement>(defaultRoot);
        return rootElement->getElementCount();
    }
}

UInt32 FixedHeightLayoutManager::getNumberOfLines(UInt32 lineNumber) const
{
    UInt32 noOfLines = 0;
    UInt32 initialValue = linesToElements[lineNumber];
    while(lineNumber<linesToElements.size() && linesToElements[lineNumber] == initialValue)
    {
        lineNumber++;
        noOfLines++;
    }
    return noOfLines;
}

void FixedHeightLayoutManager::calculatePreferredSize(void)
{
    if(getParentTextDomArea()->getWrapStyleWord())
    {
        Pnt2f topLeft,bottomRight;
        getParentTextDomArea()->getClipBounds(topLeft,bottomRight);

        if(topLeft.x() == 0 && topLeft.y() == 0)
        {
            _preferredWidth = getParentTextDomArea()->getPreferredSize().x();
        }
        else
        {
            _preferredWidth = bottomRight.x()-topLeft.x();
        }

        _preferredHeight = linesToElements.size() * heightOfLine;
    }
    else
    {    
        if(getParentTextDomArea()->getDocumentModel())
        {
            ElementRefPtr defaultRoot=getParentTextDomArea()->getDocumentModel()->getDefaultRootElement();
            PlainDocumentBranchElementRefPtr rootElement = dynamic_pointer_cast<PlainDocumentBranchElement>(defaultRoot);

            _preferredWidth = osgMax(getParentTextDomArea()->getSize().x(),calculateWidthOfLongestLine(rootElement));
            _preferredHeight =  rootElement->getElementCount() * heightOfLine;
        }
        else 
        {
            _preferredWidth = getParentTextDomArea()->getSize().x();
            _preferredHeight =  getParentTextDomArea()->getSize().y();
        }
    }
}

Vec2f  FixedHeightLayoutManager::getContentRequestedSize(void) const
{
    return Vec2f(_preferredWidth,_preferredHeight);
}

void FixedHeightLayoutManager::printDebugInformation(void) const
{
}


void FixedHeightLayoutManager::calculateLineHeight(void)
{
    // calculating the character height using 'A' as the standard character
    heightOfLine = LINEHEIGHT;

    UInt32 lineSpacing = getParentTextDomArea()->getLineSpacing();

    Vec2f topLeft(0,0),bottomRight(0,0);

    if(getParentTextDomArea()->getFont())
    {
        getParentTextDomArea()->getFont()->getBounds("A",topLeft,bottomRight);
        heightOfLine = bottomRight.y() - topLeft.y();
    }
}

Real32 FixedHeightLayoutManager::calculateWidthOfLongestLine(Element* const rootElement) const
{
    Real32 finalWidth=0.0;
    Real32 currentWidth;

    for(UInt32 i=0;i<rootElement->getElementCount();i++)
    {
        PlainDocumentLeafElementRefPtr temp = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(i));

        Pnt2f TopLeft, BottomRight;
        getParentTextDomArea()->getFont()->getBounds(temp->getText(), TopLeft, BottomRight);

        currentWidth = BottomRight.x() - TopLeft.x();

        if(currentWidth > finalWidth)finalWidth = currentWidth;
    }
    return finalWidth + 15.0;
}

bool FixedHeightLayoutManager::insideGutterRegion(Real32 PointOnComponentX)const
{
    Pnt2f topLeft,bottomRight;
    getParentTextDomArea()->getClipBounds(topLeft,bottomRight);
    return ((PointOnComponentX - topLeft.x())<=(_GutterSpace + _GutterSeparation));
}

UInt32 FixedHeightLayoutManager::calculateCaretPosition(Pnt2f PointOnComponent,bool isDragging)
{
    if(!insideGutterRegion(PointOnComponent.x()))
    {

        UInt32 pos = 0, noOfCharacters =0;
        UInt32 row = (UInt32(floor((PointOnComponent.y()/* - getParentTextDomArea()->getPosition().y() */) / heightOfLine)));

        _CaretLine = row;
        // calculating the caret line and caret y position
        _CaretYPosition = row * heightOfLine;

        Real32 xpos = PointOnComponent.x() - _GutterSpace - _GutterSeparation ;

        if(row>=rootElement->getElementCount())
        {
            _CaretLine = rootElement->getElementCount()-1;
            PlainDocumentLeafElementRefPtr temp = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(_CaretLine));
            _CaretIndex = temp->getTextLength()-2;

            recalculateCaretPositions();

            HEL = _CaretLine;
            HEI = _CaretIndex;

            if(!isDragging)
            {
                HSL = HEL;
                HSI = HEI;
            }

            printDebugInformation();

            getParentTextDomArea()->setCaretPosition(getParentTextDomArea()->getDocumentModel()->getEndPosition()-2);
            return 0;    
        }
        for(UInt32 i=0;i<_CaretLine;i++)
        {
            PlainDocumentLeafElementRefPtr temp = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(i));
            noOfCharacters= temp->getTextLength();
            pos += noOfCharacters;
        }
        PlainDocumentLeafElementRefPtr temp = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(row));

        noOfCharacters = 0;

        std::string temptext = temp->getText();
        Pnt2f topLeft,bottomRight;

        std::string ttemp = ""; 

        Real32 widthSoFar = 0.0;
        _CaretIndex = 0;

        for(UInt32 i=0;i<temp->getTextLength()-2;i++)
        {
            ttemp = temptext[i];
            getParentTextDomArea()->getFont()->getBounds(ttemp,topLeft,bottomRight);

            if(widthSoFar + bottomRight.x() <= xpos) 
            {
                noOfCharacters++;
                widthSoFar += bottomRight.x();
                _CaretIndex++;
            }
            else
            {
                break;
            }

        }

        _CaretXPosition = _GutterSpace + _GutterSeparation + widthSoFar;
        pos += noOfCharacters;

        HEL = _CaretLine;
        HEI = _CaretIndex;

        if(!isDragging)
        {
            HSL = HEL;
            HSI = HEI;
        }

        printDebugInformation();

        getParentTextDomArea()->setCaretPosition(pos);
        return pos;
    }
}


void FixedHeightLayoutManager::DoIfLineLongerThanPreferredSize()
{
    PlainDocumentLeafElementRefPtr temp = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(_CaretLine));

    if(temp)
    {
        Pnt2f topLeft,bottomRight;
        getParentTextDomArea()->getFont()->getBounds(temp->getText(),topLeft,bottomRight);

        Vec2f preferredSize = getParentTextDomArea()->getPreferredSize(); 

        if(bottomRight.x() > preferredSize.x())preferredSize.setValues(bottomRight.x(),preferredSize.y());

        getParentTextDomArea()->setPreferredSize(preferredSize);

        _preferredWidth = preferredSize.x();
        _preferredHeight = preferredSize.y();
    }
}



void FixedHeightLayoutManager::moveCaretLeft(void)
{
    PlainDocumentLeafElementRefPtr theElement; 
    if(_CaretIndex>0)
    {
        // set caret line
        // set caret index

        _CaretIndex--;
        // set caret x,y position
        recalculateCaretPositions();
        // set the caret position wrt DOM
        getParentTextDomArea()->setCaretPosition(getParentTextDomArea()->getCaretPosition()-1);
    }
    else
    {
        if(_CaretLine>0)
        {
            _CaretLine--;
            theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(_CaretLine));
            _CaretIndex = theElement->getTextLength()-2;
            if(_CaretIndex<0)_CaretIndex = 0;
            recalculateCaretPositions();
            getParentTextDomArea()->setCaretPosition(getParentTextDomArea()->getCaretPosition()-2);
        }
    }
}

void FixedHeightLayoutManager::moveCaretRight(void)
{
    PlainDocumentLeafElementRefPtr theElement; 
    theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(_CaretLine));
    if(_CaretIndex>=theElement->getTextLength()-2) 
    {
        if(_CaretLine<rootElement->getElementCount()-1)
        {
            _CaretLine++;
            _CaretIndex = 0;
            recalculateCaretPositions();
            getParentTextDomArea()->setCaretPosition(getParentTextDomArea()->getCaretPosition()+2);
        }
    }
    else 
    {
        _CaretIndex++;
        recalculateCaretPositions();
        getParentTextDomArea()->setCaretPosition(getParentTextDomArea()->getCaretPosition()+1);
    }
}

void FixedHeightLayoutManager::moveAndHighlightWord(UInt32 dir)
{
    Int32 prevIndex= _CaretIndex;
    Int32 prevLine= _CaretLine;
    bool fromPrevElement = false;
    PlainDocumentLeafElementRefPtr theElement; 
    std::string theString;

    switch(dir)
    {

        case TextDomArea::LEFT:

            theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(prevLine));

            if(prevIndex == 0)
            {
                if(prevLine>0)
                {
                    prevLine--;
                    theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(prevLine));
                    prevIndex = theElement->getTextLength()-2;
                    _CaretLine = prevLine;
                    _CaretIndex = prevIndex;
                    fromPrevElement = true;
                    getParentTextDomArea()->setCaretPosition(getParentTextDomArea()->getCaretPosition()-2);
                }
                else break;
            }

            theString = theElement->getText();

            if(prevIndex>0 && isWordChar(theString[prevIndex-1]) == false)fromPrevElement = true;

            for(Int32 i=prevIndex-1; i>=0;)
            {
                if(isWordChar(theString[i]) != fromPrevElement) // this means that when prevIndex is 0, it would indicate the beginning of the line and hence, the ctrl action should take the cursor until a wordchar is found
                {
                    _CaretLine = prevLine;
                    _CaretIndex = i;    
                    getParentTextDomArea()->setCaretPosition(getParentTextDomArea()->getCaretPosition()-1);
                    i--;
                }
                else
                {
                    break;
                }
            }
            recalculateCaretPositions();
            break;    // case left complete.

        case TextDomArea::RIGHT:

            theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(prevLine));

            if(prevIndex >=theElement->getTextLength()-2)
            {
                if(prevLine<rootElement->getElementCount()-1)
                {
                    prevLine++;
                    prevIndex = 0;
                    _CaretLine = prevLine;
                    _CaretIndex = prevIndex;
                    fromPrevElement = true;
                    theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(prevLine));
                    getParentTextDomArea()->setCaretPosition(getParentTextDomArea()->getCaretPosition()+2);
                }
                else break;
            }

            theString = theElement->getText();

            if(isWordChar(theString[prevIndex]) == false)fromPrevElement = true;

            for(UInt32 i=prevIndex; i<theElement->getTextLength()-2;)
            {
                if(isWordChar(theString[i]) != fromPrevElement) // this means that when prevIndex is 0, it would indicate the beginning of the line and hence, the ctrl action should take the cursor until a wordchar is found
                {
                    i++;
                    _CaretLine = prevLine;
                    _CaretIndex = i;    
                    getParentTextDomArea()->setCaretPosition(getParentTextDomArea()->getCaretPosition()+1);
                }
                else
                {
                    break;
                }
            }
            recalculateCaretPositions();
            break;    // Case Right complete.
    }
}

void FixedHeightLayoutManager::moveCaretUp(void)
{
    PlainDocumentLeafElementRefPtr theElement;

    if(_CaretLine > 0) 
    {
        UInt32 prevIndex = _CaretIndex;
        UInt32 prevLine = _CaretLine;
        _CaretLine--;
        theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(_CaretLine));
        if(_CaretIndex> theElement->getTextLength()-2)_CaretIndex = theElement->getTextLength()-2;
        if(_CaretIndex<0)_CaretIndex=0;
        recalculateCaretPositions();
        UInt32 charactersToBeRewinded=0;
        charactersToBeRewinded += prevIndex;
        charactersToBeRewinded += (theElement->getTextLength() - _CaretIndex);
        getParentTextDomArea()->setCaretPosition(getParentTextDomArea()->getCaretPosition()-charactersToBeRewinded);
    }
}

void FixedHeightLayoutManager::moveCaretDown(void)
{
    PlainDocumentLeafElementRefPtr theElement;
    if(_CaretLine < rootElement->getElementCount()-1)
    {
        theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(_CaretLine));
        UInt32 prevIndex = _CaretIndex;
        UInt32 prevLineLength = theElement->getTextLength();
        _CaretLine++;
        theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(_CaretLine));
        if(_CaretIndex> theElement->getTextLength()-2)_CaretIndex = theElement->getTextLength()-2;
        if(_CaretIndex<0)_CaretIndex=0;
        recalculateCaretPositions();
        UInt32 charactersToBeForwarded=0;
        charactersToBeForwarded += _CaretIndex;
        charactersToBeForwarded += (prevLineLength - prevIndex);
        getParentTextDomArea()->setCaretPosition(getParentTextDomArea()->getCaretPosition()+charactersToBeForwarded);
    }
}

void FixedHeightLayoutManager::moveCaretHome(bool isControlPressed)
{
    if(isControlPressed)
    {
        _CaretLine = 0;
        _CaretIndex = 0;
        getParentTextDomArea()->setCaretPosition(0);
    }
    else
    {
        PlainDocumentLeafElementRefPtr theElement;
        UInt32 prevIndex = _CaretIndex;
        _CaretIndex = 0;
        getParentTextDomArea()->setCaretPosition(getParentTextDomArea()->getCaretPosition()-(prevIndex - _CaretIndex));
    }
    recalculateCaretPositions();
}

void FixedHeightLayoutManager::moveCaretEnd(bool isControlPressed)
{
    PlainDocumentLeafElementRefPtr theElement;

    if(isControlPressed)
    {
        _CaretLine = rootElement->getElementCount()-1;
        theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(_CaretLine));
        _CaretIndex = theElement->getTextLength()-2;
        getParentTextDomArea()->setCaretPosition(getParentTextDomArea()->getDocumentModel()->getEndPosition()-2);
        recalculateCaretPositions();
    }
    else
    {
        UInt32 prevIndex = _CaretIndex;
        theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(_CaretLine));
        _CaretIndex = theElement->getTextLength()-2;
        if(_CaretIndex<0)
        {
            SWARNING << "_CaretIndex < 0 .. Setting it to 0"<<std::endl;
            _CaretIndex = 0;
        }
        if(_CaretIndex>prevIndex)
            recalculateCaretPositions();
        getParentTextDomArea()->setCaretPosition(getParentTextDomArea()->getCaretPosition()+ (_CaretIndex - prevIndex));
    }
}

inline bool FixedHeightLayoutManager::isStartLocationBeforeEndLocation(void) const
{
    return (HSL<HEL || (HSL==HEL && HSI<HEI));
}

void FixedHeightLayoutManager::moveTheCaret(UInt32 dir,bool isShiftPressed,bool isControlPressed)
{

    if(!rootElement || !rootElement->getElementCount()) return;
    UInt32 charactersToBeForwarded;
    PlainDocumentLeafElementRefPtr theElement;
    Int32 tempIndex;
    Int32 tempLine;
    switch(dir)
    {
        case TextDomArea::LEFT:
            if(!isShiftPressed)
            {
                if(HSL != HEL || HSI != HEI) // something was highlighted before this
                {
                    if(isStartLocationBeforeEndLocation())    
                    {                    
                        _CaretLine = HSL;                    // set caret position to the Highlight Starting position
                        _CaretIndex = HSI;
                        HEI = HSI;
                        HEL = HSL;
                    }
                    else
                    {
                        _CaretLine = HEL;                    // set caret position to the Highlight Ending position
                        _CaretIndex = HEI;
                        HSI = HEI;
                        HSL = HEL;
                    }
                    recalculateCaretPositions();
                }
                else    // nothing was highlighted before this
                {
                    if(!isControlPressed)moveCaretLeft();
                    else    moveAndHighlightWord(TextDomArea::LEFT);

                    HSI = HEI = _CaretIndex;
                    HSL = HEL = _CaretLine;
                }
            }
            else    // if shift is pressed
            {
                if(!isControlPressed)moveCaretLeft();
                else    moveAndHighlightWord(TextDomArea::LEFT);

                HEI = _CaretIndex;
                HEL = _CaretLine;
            }
            break;
        case TextDomArea::RIGHT:    
            if(!isShiftPressed)
            {
                if(HSL != HEL || HSI != HEI) // something was highlighted before this
                {
                    if(isStartLocationBeforeEndLocation())    
                    {                    
                        _CaretLine = HEL;                    // set caret position to the Highlight Starting position
                        _CaretIndex = HEI;
                        HSI = HEI;
                        HSL = HEL;
                    }
                    else
                    {
                        _CaretLine = HSL;                    // set caret position to the Highlight Ending position
                        _CaretIndex = HSI;
                        HEI = HSI;
                        HEL = HSL;
                    }
                    recalculateCaretPositions();
                }
                else    // nothing was highlighted before this
                {
                    if(!isControlPressed)moveCaretRight();
                    else    moveAndHighlightWord(TextDomArea::RIGHT);

                    HSI = HEI = _CaretIndex;
                    HSL = HEL = _CaretLine;
                }
            }
            else    // if shift is pressed
            {
                if(!isControlPressed)moveCaretRight();
                else    moveAndHighlightWord(TextDomArea::RIGHT);

                HEI = _CaretIndex;
                HEL = _CaretLine;
            }
            break;

        case TextDomArea::UP:
            if(!isShiftPressed && !isControlPressed)
            {
                if(HSL != HEL || HSI != HEI) // something was highlighted before this
                {
                    if(isStartLocationBeforeEndLocation())    
                    {                    
                        _CaretLine = HSL;                    // set caret position to the Highlight Starting position
                        _CaretIndex = HSI;
                        HEI = HSI;
                        HEL = HSL;
                    }
                    else
                    {
                        _CaretLine = HEL;                    // set caret position to the Highlight Ending position
                        _CaretIndex = HEI;
                        HSI = HEI;
                        HSL = HEL;
                    }
                    moveCaretUp();
                }
                else    // nothing was highlighted before this
                {
                    moveCaretUp();
                    HSI = HEI = _CaretIndex;
                    HSL = HEL = _CaretLine;
                }
            }
            else if(isShiftPressed && !isControlPressed)    // if shift is pressed
            {
                moveCaretUp();
                HEI = _CaretIndex;
                HEL = _CaretLine;
            }
            break;

        case TextDomArea::DOWN:    

            if(!isShiftPressed && !isControlPressed)
            {
                if(HSL != HEL || HSI != HEI) // something was highlighted before this
                {
                    if(isStartLocationBeforeEndLocation())    
                    {                    
                        _CaretLine = HEL;                    // set caret position to the Highlight Starting position
                        _CaretIndex = HEI;
                        HSI = HEI;
                        HSL = HEL;
                    }
                    else
                    {
                        _CaretLine = HSL;                    // set caret position to the Highlight Ending position
                        _CaretIndex = HSI;
                        HEI = HSI;
                        HEL = HSL;
                    }
                    moveCaretDown();
                }
                else // nothing was highlighted before this
                {
                    moveCaretDown();
                    HSI = HEI = _CaretIndex;
                    HSL = HEL = _CaretLine;
                }
            }
            else if(isShiftPressed && !isControlPressed)    // if shift is pressed
            {
                moveCaretDown();
                HEI = _CaretIndex;
                HEL = _CaretLine;
            }
            break;

        case TextDomArea::HOME:
            moveCaretHome(isControlPressed);
            HEI = _CaretIndex;
            HEL = _CaretLine;
            if(!isShiftPressed)
            {
                HSI = HEI;
                HSL = HEL;
            }
            break;

        case TextDomArea::HOMEOFNEXTLINE:

            theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(_CaretLine));
            charactersToBeForwarded = theElement->getTextLength()-_CaretIndex;
            _CaretIndex = 0;
            _CaretLine++;
            recalculateCaretPositions();
            getParentTextDomArea()->setCaretPosition(getParentTextDomArea()->getCaretPosition()+ charactersToBeForwarded);

            break;

        case TextDomArea::END:
            moveCaretEnd(isControlPressed);
            HEI = _CaretIndex;
            HEL = _CaretLine;
            if(!isShiftPressed)
            {
                HSI = HEI;
                HSL = HEL;
            }
            break;

        case TextDomArea::PAGEUP:
            tempIndex = _CaretIndex;
            tempLine = _CaretLine;
            tempLine -= getLinesToBeDisplayed();
            if(tempLine<0)tempLine = 0;
            theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(tempLine));
            if(tempIndex > theElement->getTextLength()-2)tempIndex = theElement->getTextLength()-2;

            HEI = tempIndex;
            HEL = tempLine;
            if(!isShiftPressed)
            {
                HSI = HEI;
                HSL = HEL;
            }
            _CaretLine = HEL;                    // set caret position to the Highlight Ending position
            _CaretIndex = HEI;
            recalculateCaretPositions();

            break;

        case TextDomArea::PAGEDOWN:
            tempIndex = _CaretIndex;
            tempLine = _CaretLine;
            tempLine += getLinesToBeDisplayed();
            if(tempLine>=rootElement->getElementCount())tempLine = rootElement->getElementCount()-1;
            theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(tempLine));
            if(tempIndex > theElement->getTextLength()-2)tempIndex = theElement->getTextLength()-2;

            HEI = tempIndex;
            HEL = tempLine;
            if(!isShiftPressed)
            {
                HSI = HEI;
                HSL = HEL;
            }
            _CaretLine = HEL;                    // set caret position to the Highlight Ending position
            _CaretIndex = HEI;
            recalculateCaretPositions();

            break;
    }
    checkCaretVisibility();
}

UInt32 FixedHeightLayoutManager::getNumberOfLeadingSpaces(UInt32 line) const
{
    if(line>=rootElement->getElementCount())return 0;
    UInt32 count = 0;
    PlainDocumentLeafElementRefPtr theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(line));
    std::string theString = theElement->getText();

    for(UInt32 i=0;i<theString.size(),theString[i]==' ';i++)count++;

    return count;
}

void FixedHeightLayoutManager::checkCaretVisibility(void)
{
    if(!isCaretVisible())makeCaretVisible();
}

bool FixedHeightLayoutManager::isCaretInWidthRange()
{

    Pnt2f topLeft,bottomRight;
    getParentTextDomArea()->getClipBounds(topLeft,bottomRight);
    return (_CaretXPosition>=topLeft.x() && _CaretXPosition<=bottomRight.x());
}

bool FixedHeightLayoutManager::isCaretVisible(void)
{
    return (_CaretLine>=getTopmostVisibleLineNumber() && _CaretLine<getTopmostVisibleLineNumber()+ getLinesToBeDisplayed() && isCaretInWidthRange());
}

void FixedHeightLayoutManager::doubleClickHandler(void)
{
    UInt32 initIndex = _CaretIndex;
    PlainDocumentLeafElementRefPtr theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(_CaretLine));
    std::string theString = theElement->getText();

    Int32 BeginWord = 0;
    Int32 EndWord = theElement->getTextLength();

    if(isPunctuationChar(theString[_CaretIndex]))
    {
        EndWord = _CaretIndex + 1;
        BeginWord = _CaretIndex;
    }
    else
    {
        for(Int32 i = _CaretIndex; i < theElement->getTextLength(); i++)
        {
            if(!isWordChar(theString[i]))
            {
                EndWord = i;
                break;
            }
        }
        for(Int32 i = _CaretIndex; i >= 0; i--)
        {
            if(!isWordChar(theString[i]))
            {
                BeginWord = i + 1;
                break;
            }
        }
    }

    HEL = HSL = _CaretLine;
    HSI = BeginWord;
    HEI = EndWord;

    _CaretIndex = EndWord;

    recalculateCaretPositions();

    getParentTextDomArea()->setCaretPosition(getParentTextDomArea()->getCaretPosition()+ (EndWord - initIndex));

}



void FixedHeightLayoutManager::makeCaretVisible(void)
{
    Pnt2f TempTopLeft, TempBottomRight;

    TempTopLeft = Pnt2f(_CaretXPosition,_CaretYPosition);//TempTopLeft + Offset;
    TempBottomRight = Pnt2f(_CaretXPosition + 25 + 2,_CaretYPosition+heightOfLine);//25 here denotes the gutterwidth .. should not hardcode here

    if(getParentTextDomArea()->getParentContainer() != NULL && getParentTextDomArea()->getParentContainer()->getType().isDerivedFrom(UIViewport::getClassType()))
    {
        //Get the bounds of this line
        dynamic_cast<UIViewport*>(getParentTextDomArea()->getParentContainer())->maximizeVisibility(TempTopLeft, TempBottomRight);
    }
    else if(getParentTextDomArea()->getParentContainer() != NULL && 
            getParentTextDomArea()->getParentContainer()->getParentContainer() != NULL && 
            getParentTextDomArea()->getParentContainer()->getParentContainer()->getType().isDerivedFrom(UIViewport::getClassType()))
    {
        dynamic_cast<UIViewport*>(getParentTextDomArea()->getParentContainer()->getParentContainer())->maximizeVisibility(TempTopLeft, TempBottomRight);
    }
    updateViews();

}

bool FixedHeightLayoutManager::isLastCharacter(void)
{
    PlainDocumentLeafElementRefPtr theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(_CaretLine));
    return (_CaretIndex == theElement->getTextLength()-2);
}

void FixedHeightLayoutManager::recalculateCaretPositions(void)
{
    // this function assumes that the caret index and line values are valid and computes the caret x and y positions directly
    _CaretYPosition = /*getParentTextDomArea()->getPosition().y() + */_CaretLine * heightOfLine;
    PlainDocumentLeafElementRefPtr theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(_CaretLine));
    Pnt2f topLeft,bottomRight;
    std::string theSubstring = theElement->getText();
    theSubstring = theSubstring.substr(0,_CaretIndex);
    getParentTextDomArea()->getFont()->getBounds(theSubstring,topLeft,bottomRight);
    _CaretXPosition = _GutterSpace + _GutterSeparation + bottomRight.x();
}

Pnt2f FixedHeightLayoutManager::getXYPosition(UInt32 lineNumber,UInt32 index,bool isBeginning) const
{
    PlainDocumentLeafElementRefPtr theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(lineNumber));
    if(theElement)
    {
        std::string substring = theElement->getText();
        substring = substring.substr(0,index);

        Pnt2f topLeft,bottomRight;
        getParentTextDomArea()->getFont()->getBounds(substring,topLeft,bottomRight);

        if(isBeginning)return Pnt2f( _GutterSpace + _GutterSeparation + bottomRight.x(),lineNumber*heightOfLine);
        return Pnt2f(_GutterSpace + _GutterSeparation + bottomRight.x(),(lineNumber+1)*heightOfLine);
    }
    else
    {
        return Pnt2f(0,0);
    }

}

Pnt2f FixedHeightLayoutManager::getStartXYPosition(UInt32 lineNumber) const
{
    return Pnt2f(_GutterSpace + _GutterSeparation,lineNumber*heightOfLine);
}

Pnt2f FixedHeightLayoutManager::getEndXYPosition(UInt32 lineNumber) const
{
    PlainDocumentLeafElementRefPtr theElement = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(lineNumber));
    if(theElement)
    {
        Pnt2f topLeft,bottomRight;
        getParentTextDomArea()->getFont()->getBounds(theElement->getText(),topLeft,bottomRight);
        return Pnt2f(_GutterSpace + _GutterSeparation + bottomRight.x(),(lineNumber+1)*heightOfLine);
    }
    else
    {
        return Pnt2f(0,0);
    }
}


void FixedHeightLayoutManager::setStartingBraces(char theChar,UInt32 CaretIndex,UInt32 CaretLine,bool isNewCharacter)
{
    _BracesHighlightFlag = true;
    _StartingBraceIndex = CaretIndex;
    _StartingBraceLine = CaretLine;
    _EndingBraceIndex = CaretIndex;
    _EndingBraceLine = CaretLine;
    findBrace(theChar,TextDomArea::AFTER,isNewCharacter);
}

void FixedHeightLayoutManager::setEndingBraces(char theChar,UInt32 CaretIndex,UInt32 CaretLine)
{
    _BracesHighlightFlag = true;
    _StartingBraceIndex = CaretIndex;
    _StartingBraceLine = CaretLine;
    _EndingBraceIndex = CaretIndex;
    _EndingBraceLine = CaretLine;
    findBrace(theChar,TextDomArea::BEFORE,true);
}

void FixedHeightLayoutManager::findBrace(char theChar,UInt32 direction,bool isNewCharacter)
{
    bool found = false;
    Int32 currentLine;

    switch(direction)
    {
        case TextDomArea::AFTER:
            {
                currentLine = _StartingBraceLine;
                UInt32 val = 1;
                while(currentLine<rootElement->getElementCount())
                {
                    PlainDocumentLeafElementRefPtr temp = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(currentLine));
                    std::string theString = temp->getText();
                    if(currentLine == _StartingBraceLine)
                    {
                        if(isNewCharacter)
                            theString = theString.substr(_StartingBraceIndex);
                        else
                            theString = theString.substr(_StartingBraceIndex+1);
                    }
                    if(find(theString.begin(),theString.end(),theChar) == theString.end() && find(theString.begin(),theString.end(),getOppositeBraceForEncoding(theChar)) == theString.end())
                    {
                        currentLine++;
                        continue;
                    }
                    else 
                    {
                        for(UInt32 i=0;i<theString.size();i++)
                        {
                            if(theString[i]==theChar)
                            {
                                val++;
                            }                        
                            else if(theString[i]==getOppositeBraceForEncoding(theChar))
                            {
                                val--;
                                if(val <= 0)
                                {
                                    _EndingBraceIndex = (currentLine == _StartingBraceLine)?(_StartingBraceIndex+i):i;
                                    _EndingBraceLine = currentLine;
                                    return;
                                }
                            }
                        }
                    }
                    currentLine++;
                }
                break;
            }
        case TextDomArea::BEFORE:
            {
                currentLine = _EndingBraceLine;
                UInt32 val = 1;
                while(currentLine>=0)
                {
                    PlainDocumentLeafElementRefPtr temp = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(currentLine));
                    std::string theString = temp->getText();
                    if(currentLine == _EndingBraceLine)
                    {
                        theString = theString.substr(0,_EndingBraceIndex);
                    }
                    if(find(theString.begin(),theString.end(),theChar) == theString.end() && find(theString.begin(),theString.end(),getOppositeBraceForEncoding(theChar)) == theString.end())
                    {
                        currentLine--;
                        continue;
                    }
                    else 
                    {
                        for(Int32 i=theString.size()-1;i>=0;i--)
                        {
                            if(theString[i]==theChar)
                            {
                                val++;
                            }                        
                            else if(theString[i]==getOppositeBraceForEncoding(theChar))
                            {
                                val--;
                                if(val <= 0)
                                {
                                    _StartingBraceIndex = i;
                                    _StartingBraceLine = currentLine;
                                    return;
                                }
                            }
                        }
                    }
                    currentLine--;
                }
                break;
            }
    }
}

void FixedHeightLayoutManager::removeBracesHighlightIndices()
{
    _BracesHighlightFlag = false;
}

void FixedHeightLayoutManager::populateCache(void)
{
    // cache exists only when the word wrap is enabled
    if(getParentTextDomArea()->getWrapStyleWord()) 
    {
        linesToElements.clear();

        if(getParentTextDomArea()->getDocumentModel())
        {
            ElementRefPtr defaultRoot=getParentTextDomArea()->getDocumentModel()->getDefaultRootElement();
            if(defaultRoot)
            {
                PlainDocumentBranchElementRefPtr rootElement = dynamic_pointer_cast<PlainDocumentBranchElement>(defaultRoot);

                Pnt2f init = getParentTextDomArea()->getPosition();
                Vec2f dimensions = getParentTextDomArea()->getPreferredSize();


                for(UInt32 i=0;i<rootElement->getElementCount();i++)
                {
                    //GlyphViewRefPtr view = GlyphView::create();
                    PlainDocumentLeafElementRefPtr temp = dynamic_cast<PlainDocumentLeafElement*>(rootElement->getElement(i));
                    //view->setElement(ElementRefPtr(temp));
                    UInt32 noOfCharacters= temp->getTextLength();

                    /* to be edited............
                       Real32 totalLengthOfAllCharacters = noOfCharacters * widthOfCharacter;
                       UInt32 noOfLines = UInt32(ceil(totalLengthOfAllCharacters / dimensions.x()));

                       for(UInt32 j=0;j<noOfLines;j++)
                       linesToElements.push_back(i);
                       */
                }
            }
        }

    }
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

FixedHeightLayoutManager::FixedHeightLayoutManager(void) :
    Inherited(),
    defaultRoot(NULL),
    rootElement(NULL),
    _CaretLine(0),
    _CaretIndex(0),
    _CaretXPosition(0),
    _CaretYPosition(0),
    _HighlightStartLine(0),
    _HighlightStartIndex(0),
    _HighlightEndLine(0),
    _HighlightEndIndex(0),
    _preferredHeight(0.0),
    _preferredWidth(0.0),
    _GutterSpace(0.0),
    _GutterSeparation(0.0),
    _StartingBraceLine(-1),
    _StartingBraceIndex(-1),
    _EndingBraceLine(-1),
    _EndingBraceIndex(-1),
    _BracesHighlightFlag(false)
{
}

FixedHeightLayoutManager::FixedHeightLayoutManager(const FixedHeightLayoutManager &source) :
    Inherited(source),
    defaultRoot(NULL),
    rootElement(NULL)
{
    _CaretLine = source._CaretLine;
    _CaretIndex = source._CaretIndex;
    _CaretXPosition = source._CaretXPosition;
    _CaretYPosition = source._CaretYPosition;
    _HighlightStartLine = source._HighlightStartLine; 
    _HighlightStartIndex = source._HighlightStartIndex; 
    _HighlightEndLine = source._HighlightEndLine; 
    _HighlightEndIndex = source._HighlightEndIndex; 
    _preferredHeight = source._preferredHeight;
    _preferredWidth = source._preferredWidth;
    _GutterSpace = source._GutterSpace;
    _GutterSeparation = source._GutterSeparation;
    _StartingBraceLine = source._StartingBraceLine;
    _StartingBraceIndex = source._StartingBraceIndex;
    _EndingBraceLine = source._EndingBraceLine;
    _EndingBraceIndex = source._EndingBraceIndex;
    _BracesHighlightFlag = source._BracesHighlightFlag;
}

FixedHeightLayoutManager::~FixedHeightLayoutManager(void)
{
}

/*----------------------------- class specific ----------------------------*/

void FixedHeightLayoutManager::changed(ConstFieldMaskArg whichField, 
                            UInt32            origin,
                            BitVector         details)
{
    //Do not respond to changes that have a Sync origin
    if(origin & ChangedOrigin::Sync)
    {
        return;
    }

    if(whichField & FixedHeightLayoutManager::ParentTextDomAreaFieldMask)
    {
        initializeRootElement();
    }

    Inherited::changed(whichField, origin, details);
}

void FixedHeightLayoutManager::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump FixedHeightLayoutManager NI" << std::endl;
}

OSG_END_NAMESPACE
