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

#ifndef _OSGGRAPHICS2D_H_
#define _OSGGRAPHICS2D_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGGraphics2DBase.h"
#include "OSGDepthChunk.h"
#include "OSGColorMaskChunk.h"
#include "OSGStencilChunk.h"

OSG_BEGIN_NAMESPACE

/*! \brief Graphics2D class. See \ref
           PageContribUserInterfaceGraphics2D for a description.
*/

class OSG_CONTRIBUSERINTERFACE_DLLMAPPING Graphics2D : public Graphics2DBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef Graphics2DBase Inherited;
    typedef Graphics2D     Self;

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
    virtual void incrDrawBounderiesNesting(void);
    virtual void decrDrawBounderiesNestring(void);

    virtual void initAddDrawBounderies(void);
    virtual void uninitAddDrawBounderies(void);
    virtual void initRemoveDrawBounderies(void);
    virtual void uninitRemoveDrawBounderies(void);
    
    virtual void activateDrawBounderiesTest(void);
    virtual void deactivateDrawBounderiesTest(void);


    
    virtual void drawRect(const Pnt2f& TopLeft,
                          const Pnt2f& BottomRight,
                          const Color4f& Color,
                          const Real32& Opacity) const;

    virtual void drawQuad(const Pnt2f& p1,
                          const Pnt2f& p2,
                          const Pnt2f& p3,
                          const Pnt2f& p4, 
                          const Color4f& c1,
                          const Color4f& c2,
                          const Color4f& c3,
                          const Color4f& c4,
                          const Real32& Opacity) const;

    virtual void drawQuad(const Pnt2f& p1,
                          const Pnt2f& p2,
                          const Pnt2f& p3,
                          const Pnt2f& p4, 
                          const Vec2f& t1,
                          const Vec2f& t2,
                          const Vec2f& t3,
                          const Vec2f& t4,
                          const Color4f& color,
                          const TextureBaseChunkUnrecPtr Texture,
                          const Real32& Opacity) const;

    virtual void drawQuad(const Pnt2f& p1,
                          const Pnt2f& p2,
                          const Pnt2f& p3,
                          const Pnt2f& p4, 
                          const Vec2f& t1,
                          const Vec2f& t2,
                          const Vec2f& t3,
                          const Vec2f& t4,
                          Material* const Material,
                          const Real32& Opacity) const;

    virtual void drawLine(const Pnt2f& TopLeft,
                          const Pnt2f& BottomRight,
                          const Real32& Width,
                          const Color4f& Color,
                          const Real32& Opacity) const;

    virtual void drawPolygon(const MFPnt2f Verticies,
                             const Color4f& Color,
                             const Real32& Opacity) const;

    virtual void drawDisc(const Pnt2f& Center,
                          const Real32& Width,
                          const Real32& Height,
                          const Real32& StartAngleRad,
                          const Real32& EndAngleRad,
                          const UInt16& SubDivisions,
                          const Color4f& CenterColor,
                          const Color4f& OuterColor,
                          const Real32& Opacity) const;

    virtual void drawComplexDisc(const Pnt2f& Center,
                                 const Real32& InnerRadius,
                                 const Real32& OuterRadius,
                                 const Real32& StartAngleRad,
                                 const Real32& EndAngleRad,
                                 const UInt16& SubDivisions,
                                 const Color4f& CenterColor,
                                 const Color4f& OuterColor,
                                 const Real32& Opacity) const;

    virtual void drawArc(const Pnt2f& Center,
                         const Real32& Width,
                         const Real32& Height,
                         const Real32& StartAngleRad,
                         const Real32& EndAngleRad,
                         const Real32& LineWidth,
                         const UInt16& SubDivisions,
                         const Color4f& Color,
                         const Real32& Opacity) const;

    virtual void drawText(const Pnt2f& Position,
                          const std::string& Text,
                          UIFont* const TheFont,
                          const Color4f& Color,
                          const Real32& Opacity) const;

    virtual void drawTextUnderline(const Pnt2f& Position,
                                   const std::string& Text,
                                   UIFont* const TheFont,
                                   const Color4f& Color,
                                   const Real32& Opacity) const;

    virtual void preDraw(void);
    virtual void postDraw(void);

    virtual Real32 getClipPlaneOffset(void) const;

    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in Graphics2DBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    Graphics2D(void);
    Graphics2D(const Graphics2D &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~Graphics2D(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Class Specific                             */
    /*! \{                                                                 */
    void onCreate(const Graphics2D *Id = NULL);
    void onDestroy();
    
    /*! \}                                                                 */
    
    static ColorMaskChunkUnrecPtr createColorMask(void);
    static StencilChunkUnrecPtr createStenciledAreaSetup(void);
    static StencilChunkUnrecPtr createStenciledAreaCleanup(void);
    static StencilChunkUnrecPtr createStenciledAreaTest(void);
    
    UInt32 _StencilNesting;
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class Graphics2DBase;

    void drawCharacters( const TextLayoutResult& layoutResult, UIFont* const TheFont) const;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const Graphics2D &source);
};

typedef Graphics2D *Graphics2DP;

OSG_END_NAMESPACE

#include "OSGGraphics2DBase.inl"
#include "OSGGraphics2D.inl"

#endif /* _OSGGRAPHICS2D_H_ */
