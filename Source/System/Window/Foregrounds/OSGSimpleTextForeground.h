/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 * contact: David Kabala (djkabala@gmail.com)                                *
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

#ifndef _OSGSIMPLETEXTFOREGROUND_H_
#define _OSGSIMPLETEXTFOREGROUND_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGSimpleTextForegroundBase.h"
#include "OSGTextureObjChunkFields.h"
#include "OSGTextureEnvChunkFields.h"
#include "OSGTextTXFFace.h"

OSG_BEGIN_NAMESPACE

/*! \brief SimpleTextForeground class. See \ref
           PageUtilSimpleTextForeground for a description.
*/

class OSG_UTIL_DLLMAPPING SimpleTextForeground : public SimpleTextForegroundBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef SimpleTextForegroundBase Inherited;
    typedef SimpleTextForeground     Self;

    /*---------------------------------------------------------------------*/
    /*! \name                     Modes                                    */
    /*! \{                                                                 */

    enum
    {
        Left   = 0,
        Middle = 1,
        Right  = 2
    } HorizontalAlignE;

    enum
    {
        Top    = 0,
        Center = 1,
        Bottom = 2
    } VerticalAlignE;
       
    /*! \}                                                                 */
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
    /*---------------------------------------------------------------------*/
    /*! \name                      Draw                                    */
    /*! \{                                                                 */

    virtual void draw(DrawEnv *pEnv);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name               Convenience Functions                          */
    /*! \{                                                                 */

    void addLine(const std::string& text);
    void clear  (void);

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in SimpleTextForegroundBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    SimpleTextForeground(void);
    SimpleTextForeground(const SimpleTextForeground &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~SimpleTextForeground(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Init                                   */
    /*! \{                                                                 */

    virtual void resolveLinks(void);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    TextTXFFaceRefPtr       _face;

    TextureObjChunkUnrecPtr _texchunk;
    TextureEnvChunkUnrecPtr _texenvchunk;

    void initText(const std::string &family, Real32 size);

    friend class FieldContainer;
    friend class SimpleTextForegroundBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const SimpleTextForeground &source);
};

typedef SimpleTextForeground *SimpleTextForegroundP;

OSG_END_NAMESPACE

#include "OSGSimpleTextForegroundBase.inl"
#include "OSGSimpleTextForeground.inl"

#endif /* _OSGSIMPLETEXTFOREGROUND_H_ */
