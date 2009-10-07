/* This is a template file for fcdEdit.
 * To create it from sample source,  cut'n'paste the source and apply the following
 * substitutions:
 * s|\|\\|g 
 * s|"|\"|g 
 * s|^|"| 
 * s|$|",|
 */

const char *FCBaseTemplate_h[]={
"/*---------------------------------------------------------------------------*\\",
" *                                OpenSG                                     *",
" *                                                                           *",
" *                                                                           *",
" *               Copyright (C) 2000-2002 by the OpenSG Forum                 *",
" *                                                                           *",
" *                            www.opensg.org                                 *",
" *                                                                           *",
" *   contact: dirk@opensg.org, gerrit.voss@vossg.org, jbehr@zgdv.de          *",
" *                                                                           *",
"\\*---------------------------------------------------------------------------*/",
"/*---------------------------------------------------------------------------*\\",
" *                                License                                    *",
" *                                                                           *",
" * This library is free software; you can redistribute it and/or modify it   *",
" * under the terms of the GNU Library General Public License as published    *",
" * by the Free Software Foundation, version 2.                               *",
" *                                                                           *",
" * This library is distributed in the hope that it will be useful, but       *",
" * WITHOUT ANY WARRANTY; without even the implied warranty of                *",
" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *",
" * Library General Public License for more details.                          *",
" *                                                                           *",
" * You should have received a copy of the GNU Library General Public         *",
" * License along with this library; if not, write to the Free Software       *",
" * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.                 *",
" *                                                                           *",
"\\*---------------------------------------------------------------------------*/",
"/*---------------------------------------------------------------------------*\\",
" *                                Changes                                    *",
" *                                                                           *",
" *                                                                           *",
" *                                                                           *",
" *                                                                           *",
" *                                                                           *",
" *                                                                           *",
"\\*---------------------------------------------------------------------------*/",
"",
"/*****************************************************************************\\",
" *****************************************************************************",
" **                                                                         **",
" **                  This file is automatically generated.                  **",
" **                                                                         **",
" **          Any changes made to this file WILL be lost when it is          **",
" **           regenerated, which can become necessary at any time.          **",
" **                                                                         **",
" **     Do not change this file, changes should be done in the derived      **",
" **     class @!Classname!@",
" **                                                                         **",
" *****************************************************************************",
"\\*****************************************************************************/",
"", 
"",
"#ifndef _OSG@!CLASSNAME!@BASE_H_",
"#define _OSG@!CLASSNAME!@BASE_H_",
"#ifdef __sgi",
"#pragma once",
"#endif",
"",
"",
"#include <@!HeaderPrefix!@OSGConfig.h>",
"@@if Library",
"@@if useLocalIncludes",
"#include \"OSG@!Libname!@Def.h\"",
"@@else",
"#include <OSG@!Libname!@Def.h>",
"@@endif",
"@@endif",
"",
"#include <@!HeaderPrefix!@OSGBaseTypes.h>",
"#include <@!HeaderPrefix!@OSGRefPtr.h>",
"#include <@!HeaderPrefix!@OSGCoredNodePtr.h>",
"",
#if 0 // Not sure what's the right way here
"@@if useLocalIncludes",
"#include \"@!ParentHeaderPrefix!@OSG@!Parent!@.h\" // Parent",
"@@else",
"#include <@!ParentHeaderPrefix!@OSG@!Parent!@.h> // Parent",
"@@endif",
#else
"@@if hasParentHeader",
"#include <@!ParentHeader!@.h> // Parent",
"@@else",
"#include <@!ParentHeaderPrefix!@OSG@!Parent!@.h> // Parent",
"@@endif",
"",
#endif
"@@if !Decorator",
"@@BeginFieldLoop@@",
"#include @!FieldtypeInclude!@ // @!Fieldname!@ type",
"@@EndFieldLoop@@",
"@@else",
"#include <@!ParentHeaderPrefix!@OSG@!Parent!@Fields.h> // Decoratee type",
"@@endif",
"",
"@@if useLocalIncludes",
"#include \"OSG@!Classname!@Fields.h\"",
"@@else",
"#include <OSG@!Classname!@Fields.h>",
"",
"@@endif",
"@@if hasProducedMethods", 
"#include <OpenSG/Toolbox/OSGEventProducer.h>",
"#include <OpenSG/Toolbox/OSGEventProducerType.h>",
"#include <OpenSG/Toolbox/OSGMethodDescription.h>",
"",
"@@endif",
"OSG_BEGIN_NAMESPACE",

"",
"class @!Classname!@;",
"class BinaryDataHandler;",
"",
"//! \\brief @!Classname!@ Base Class.",
"",
"@@if Library",
"@@if isRootProducer", 
"class OSG_@!LIBNAME!@LIB_DLLMAPPING @!Classname!@Base : public @!Parent!@, public EventProducer",
"@@else",
"class OSG_@!LIBNAME!@LIB_DLLMAPPING @!Classname!@Base : public @!Parent!@",
"@@endif",
"@@else",
"@@if isRootProducer", 
"class @!Classname!@Base : public @!Parent!@, public EventProducer",
"@@else",
"class @!Classname!@Base : public @!Parent!@",
"@@endif",
"@@endif",
"{",
"  private:",
"",
"    typedef @!Parent!@    Inherited;",
"@@if hasProducedMethods", 
"    typedef @!ParentProducer!@    ProducerInherited;",
"@@endif",
"",
"    /*==========================  PUBLIC  =================================*/",
"  public:",
"",
"    typedef @!Classname!@Ptr  Ptr;",
"",
"@@if Decorator",
"    enum",
"    {",
"        DecorateeFieldId        = Inherited::NextFieldId,",
"        NextFieldId             = DecorateeFieldId          + 1",
"    };",
"",
"    static const OSG::BitVector DecorateeFieldMask;",
"@@else",
"@@FieldIdsAndMasksDecl@@",
"@@endif",
"",
"@@if hasProducedMethods", 
"@@MethodIdsDecl@@",
"",
"@@endif",
"    static const OSG::BitVector MTInfluenceMask;",
"",
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                    Class Get                                 */",
"    /*! \\{                                                                 */",
"",
"    static        FieldContainerType &getClassType    (void); ",
"    static        UInt32              getClassTypeId  (void); ",
"@@if hasProducedMethods", 
"    static const  EventProducerType  &getProducerClassType  (void); ",
"    static        UInt32              getProducerClassTypeId(void); ",
"@@endif",
"",
"    /*! \\}                                                                 */",
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                FieldContainer Get                            */",
"    /*! \\{                                                                 */",
"",
"    virtual       FieldContainerType &getType  (void); ",
"    virtual const FieldContainerType &getType  (void) const; ",
"",
"    virtual       UInt32              getContainerSize(void) const;",
"",
"    /*! \\}                                                                 */",
"@@if hasPublicFields", 
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                    Field Get                                 */",
"    /*! \\{                                                                 */",
"",
"@@if decorator", 
"    @!FieldMethodType!@       SF@!Parent!@Ptr *editSFDecoratee(void);",
"    @!FieldMethodType!@ const SF@!Parent!@Ptr *getSFDecoratee(void) const;",
"@@endif", 

"@@BeginFieldLoop@@",
"@@if isPublic", 
"",
"    @!FieldMethodType!@       @!CARDINALITY!@@!CapsFieldtypeClean:17!@ *edit@!CARDINALITY!@@!Fieldname:15!@(void);",
"    @!FieldMethodType!@ const @!CARDINALITY!@@!CapsFieldtypeClean:17!@ *get@!CARDINALITY!@@!Fieldname:15!@(void) const;",
"@@else", 
"@@if isReadPublic", 
"    @!FieldMethodType!@ const @!CARDINALITY!@@!CapsFieldtypeClean:17!@ *get@!CARDINALITY!@@!Fieldname:15!@(void) const;",
"@@endif", 
"@@endif", 
"@@EndFieldLoop@@",
"",

"@@if Decorator", 
"    @!FieldMethodType!@ const @!Parent!@Ptr &getDecoratee(void) const;",
"@@endif", 

"@@BeginSFFieldLoop@@",
"",
"@@if isPublic", 
"    @!FieldMethodType!@       @!Fieldtype:19!@ &edit@!Fieldname:15!@(void);",
"    @!FieldMethodType!@ const @!Fieldtype:19!@ &get@!Fieldname:15!@(void) const;",
"@@else",

"@@if isReadPublic", 
"    @!FieldMethodType!@ const @!Fieldtype:19!@ &get@!Fieldname:15!@(void) const;",
"@@endif", 

"@@endif", 
"@@EndSFFieldLoop@@",

"@@BeginMFFieldLoop@@",
"",
"@@if isPublic", 
"    @!FieldMethodType!@       @!Fieldtype:19!@ &edit@!Fieldname:15!@(const UInt32 index);",
"    @!FieldMethodType!@ const @!Fieldtype:19!@ &get@!Fieldname:15!@(const UInt32 index) const;",
"#ifndef OSG_2_PREP",
"    @!FieldMethodType!@       @!CARDINALITY!@@!CapsFieldtypeClean:17!@ &get@!Fieldname:15!@(void);",
"    @!FieldMethodType!@ const @!CARDINALITY!@@!CapsFieldtypeClean:17!@ &get@!Fieldname:15!@(void) const;",
"#endif",
"@@else",

"@@if isReadPublic", 
"    @!FieldMethodType!@ const @!Fieldtype:19!@ &get@!Fieldname:15!@(const UInt32 index) const;",
"@@endif", 
"@@endif", 
"@@EndMFFieldLoop@@",

"",
"    /*! \\}                                                                 */",
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                    Field Set                                 */",
"    /*! \\{                                                                 */",
"",
"@@if decorator", 
"    @!FieldMethodType!@ void setDecoratee      ( const @!Parent!@Ptr &value );",
"@@endif", 
"@@BeginSFFieldLoop@@",
"@@if isPublic", 
"    @!FieldMethodType!@ void set@!Fieldname:15!@( const @!Fieldtype!@ &value );",
"@@endif", 
"@@EndSFFieldLoop@@",
"",
"    /*! \\}                                                                 */",
"@@endif", 
"@@if hasProducedMethods", 
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                Method Produced Get                           */",
"    /*! \\{                                                                 */",
"",
"    virtual const EventProducerType &getProducerType(void) const; ",
"",
"    /*! \\}                                                                 */",
"@@endif", 
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                       Sync                                   */",
"    /*! \\{                                                                 */",
"",
"    /*! \\}                                                                 */",
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                   Binary Access                              */",
"    /*! \\{                                                                 */",
"",
"    virtual UInt32 getBinSize (const BitVector         &whichField);",
"    virtual void   copyToBin  (      BinaryDataHandler &pMem,", 
"                               const BitVector         &whichField);",
"    virtual void   copyFromBin(      BinaryDataHandler &pMem,", 
"                               const BitVector         &whichField);",
"",
"",
"    /*! \\}                                                                 */",
"@@if !Abstract",
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                   Construction                               */",
"    /*! \\{                                                                 */",
"",
"    static  @!Classname!@Ptr      create          (void); ",
"    static  @!Classname!@Ptr      createEmpty     (void); ",
"",
"    /*! \\}                                                                 */",
"",
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                       Copy                                   */",
"    /*! \\{                                                                 */",
"",
"    virtual FieldContainerPtr     shallowCopy     (void) const; ",
"",
"    /*! \\}                                                                 */",
"@@endif",
"    /*=========================  PROTECTED  ===============================*/",
"  protected:",
"",
"@@if hasFields", 
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                      Fields                                  */",
"    /*! \\{                                                                 */",
"",
"@@if Decorator", 
"    SF@!Parent!@Ptr   _sfDecoratee;",
"@@else", 
"@@BeginFieldLoop@@",
"@@if !isPrivate", 
"    @!CARDINALITY!@@!CapsFieldtypeClean:15!@   _@!fieldname!@;",
"@@endif", 
"@@EndFieldLoop@@",
"@@endif", 
"",
"    /*! \\}                                                                 */",
"@@endif", 
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                   Constructors                               */",
"    /*! \\{                                                                 */",
"",
"    @!Classname!@Base(void);",
"    @!Classname!@Base(const @!Classname!@Base &source);",
"",
"    /*! \\}                                                                 */",
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                   Destructors                                */",
"    /*! \\{                                                                 */",
"",
"    virtual ~@!Classname!@Base(void); ",
"",
"    /*! \\}                                                                 */",
"@@if hasProtectedFields", 
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                    Field Get                                 */",
"    /*! \\{                                                                 */",
"",
"@@BeginFieldLoop@@",
"@@if isProtected", 
"    @!FieldMethodType!@       @!CARDINALITY!@@!CapsFieldtypeClean:17!@ *edit@!CARDINALITY!@@!Fieldname:15!@(void);",
"@@if !isReadPublic", 
"    @!FieldMethodType!@ const @!CARDINALITY!@@!CapsFieldtypeClean:17!@ *get@!CARDINALITY!@@!Fieldname:15!@(void) const;",
"@@endif", 
"@@endif", 
"@@EndFieldLoop@@",
"",

"@@BeginSFFieldLoop@@",
"@@if isProtected", 
"    @!FieldMethodType!@       @!Fieldtype:19!@ &edit@!Fieldname:15!@(void);",
"@@if !isReadPublic", 
"    @!FieldMethodType!@ const @!Fieldtype:19!@ &get@!Fieldname:15!@(void) const;",
"@@endif", 
"@@endif", 
"@@EndSFFieldLoop@@",

"@@BeginMFFieldLoop@@",
"@@if isProtected", 
"    @!FieldMethodType!@       @!Fieldtype:19!@ &edit@!Fieldname:15!@(UInt32 index);",
"#ifndef OSG_2_PREP",
"    @!FieldMethodType!@       @!CARDINALITY!@@!CapsFieldtypeClean:17!@ &get@!Fieldname:15!@(void);",
"    @!FieldMethodType!@ const @!CARDINALITY!@@!CapsFieldtypeClean:17!@ &get@!Fieldname:15!@(void) const;",
"#endif",
"@@if !isReadPublic", 
"    @!FieldMethodType!@ const @!Fieldtype:19!@ &get@!Fieldname:15!@(UInt32 index) const;",
"@@endif", 
"@@endif", 
"@@EndMFFieldLoop@@",

"",
"    /*! \\}                                                                 */",
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                    Field Set                                 */",
"    /*! \\{                                                                 */",
"",
"@@BeginSFFieldLoop@@",
"@@if isProtected", 
"    @!FieldMethodType!@ void set@!Fieldname:15!@(const @!Fieldtype!@ &value);",
"@@endif", 
"@@EndSFFieldLoop@@",
"",
"    /*! \\}                                                                 */",
"@@endif", 
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                       Sync                                   */",
"    /*! \\{                                                                 */",
"",
"#if !defined(OSG_FIXED_MFIELDSYNC)",
"    void executeSyncImpl(      @!Classname!@Base *pOther,",
"                         const BitVector         &whichField);",
"",
"    virtual void   executeSync(      FieldContainer    &other,",
"                               const BitVector         &whichField);",
"#else",
"    void executeSyncImpl(      @!Classname!@Base *pOther,",
"                         const BitVector         &whichField,",
"                         const SyncInfo          &sInfo     );",
"",
"    virtual void   executeSync(      FieldContainer    &other,",
"                               const BitVector         &whichField,",
"                               const SyncInfo          &sInfo);",
"",
"    virtual void execBeginEdit     (const BitVector &whichField,", 
"                                          UInt32     uiAspect,",
"                                          UInt32     uiContainerSize);",
"",
"            void execBeginEditImpl (const BitVector &whichField,", 
"                                          UInt32     uiAspect,",
"                                          UInt32     uiContainerSize);",
"",
"    virtual void onDestroyAspect(UInt32 uiId, UInt32 uiAspect);",
"#endif",
"",
"    /*! \\}                                                                 */",
"    /*==========================  PRIVATE  ================================*/",
"  private:",
"",
"    friend class FieldContainer;",
"",
"@@if hasProducedMethods", 
"    static MethodDescription   *_methodDesc[];",
"    static EventProducerType _producerType;",
"",
"@@endif", 

"@@if hasFields", 
"    static FieldDescription   *_desc[];",
"@@endif", 
"    static FieldContainerType  _type;",
"",
"@@if hasPrivateFields", 
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                      Fields                                  */",
"    /*! \\{                                                                 */",
"",
"@@if !Decorator", 
"@@BeginFieldLoop@@",
"@@if isPrivate", 
"    @!CARDINALITY!@@!CapsFieldtypeClean:15!@   _@!fieldname!@;",
"@@endif", 
"@@EndFieldLoop@@",
"@@endif", 
"",
"    /*! \\}                                                                 */",
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                    Field Get                                 */",
"    /*! \\{                                                                 */",
"",
"@@BeginFieldLoop@@",
"@@if isPrivate", 
"    @!FieldMethodType!@       @!CARDINALITY!@@!CapsFieldtypeClean:17!@ *edit@!CARDINALITY!@@!Fieldname:15!@(void);",
"    @!FieldMethodType!@ const @!CARDINALITY!@@!CapsFieldtypeClean:17!@ *get@!CARDINALITY!@@!Fieldname:15!@(void) const;",
"@@endif", 
"@@EndFieldLoop@@",
"",

"@@BeginSFFieldLoop@@",
"@@if isPrivate", 
"    @!FieldMethodType!@       @!Fieldtype:19!@ &edit@!Fieldname:15!@(void);",
"    @!FieldMethodType!@ const @!Fieldtype:19!@ &get@!Fieldname:15!@(void) const;",
"@@endif", 
"@@EndSFFieldLoop@@",

"@@BeginMFFieldLoop@@",
"@@if isPrivate", 
"    @!FieldMethodType!@       @!Fieldtype:19!@ &edit@!Fieldname:15!@(UInt32 index);",
"    @!FieldMethodType!@ const @!Fieldtype:19!@ &get@!Fieldname:15!@(UInt32 index) const;",
"@@endif", 
"@@EndMFFieldLoop@@",
"",
"    /*! \\}                                                                 */",
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                    Field Set                                 */",
"    /*! \\{                                                                 */",
"",
"@@BeginSFFieldLoop@@",
"@@if isPrivate", 
"    @!FieldMethodType!@ void set@!Fieldname:15!@(const @!Fieldtype!@ &value);",
"@@endif", 
"@@EndSFFieldLoop@@",
"",
"    /*! \\}                                                                 */",
"@@endif", 
"",
"    // prohibit default functions (move to 'public' if you need one)",
"    void operator =(const @!Classname!@Base &source);",
"};",
"",
"//---------------------------------------------------------------------------",
"//   Exported Types",
"//---------------------------------------------------------------------------",
"",
"",
"typedef @!Classname!@Base *@!Classname!@BaseP;",
"",
"typedef osgIF<@!Classname!@Base::isNodeCore,",
"              CoredNodePtr<@!Classname!@>,",
"              FieldContainer::attempt_to_create_CoredNodePtr_on_non_NodeCore_FC",
"              >::_IRet @!Classname!@NodePtr;",
"",
"typedef RefPtr<@!Classname!@Ptr> @!Classname!@RefPtr;",
"",
"OSG_END_NAMESPACE",
"", 
"#endif /* _OSG@!CLASSNAME!@BASE_H_ */",
NULL };
