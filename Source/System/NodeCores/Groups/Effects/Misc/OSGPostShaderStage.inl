/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

OSG_BEGIN_NAMESPACE

inline
TextureObjChunk* PostShaderStage::RenderPassData::getOutputTexture(void) const
{
    return _OutputTexture;
}

inline
bool PostShaderStage::RenderPassData::getIsLastPass(void) const
{
    return _IsLassPass;
}

inline
SimpleSHLChunk* PostShaderStage::RenderPassData::getShader(void) const
{
    return _Shader;
}

inline
std::string PostShaderStage::RenderPassData::getOutputTextureName(void) const
{
    return PostShaderStage::PrePassXName
         + boost::lexical_cast<std::string>(_Index)
         + PostShaderStage::PostPassXColorTexName;
}

inline
std::string PostShaderStage::RenderPassData::getWidthName(void) const
{
    return PostShaderStage::PrePassXName
         + boost::lexical_cast<std::string>(_Index)
         + PostShaderStage::PostPassXColorWidthName;
}

inline
std::string PostShaderStage::RenderPassData::getHeightName(void) const
{
    return PostShaderStage::PrePassXName
         + boost::lexical_cast<std::string>(_Index)
         + PostShaderStage::PostPassXColorHeightName;
}

inline
UInt32 PostShaderStage::RenderPassData::getIndex(void) const
{
    return _Index;
}

inline
UInt32 PostShaderStage::getNumPasses(void) const
{
    return getMFVertexShaders()->size();
}

inline
void PostShaderStage::insertPass(UInt32 Index,
                                 const std::string& VertexProgram,
                                 const std::string& FragmentProgram,
                                 Vec2f Size)
{
    editMFVertexShaders()->insert(Index, VertexProgram);
    editMFFragmentShaders()->insert(Index, FragmentProgram);
    editMFPassSizes()->push_back(Size);
}

inline
void PostShaderStage::addPass(const std::string& VertexProgram,
                              const std::string& FragmentProgram,
                              Vec2f Size)
{
    editMFVertexShaders()->push_back(VertexProgram);
    editMFFragmentShaders()->push_back(FragmentProgram);
    editMFPassSizes()->push_back(Size);
}

inline
void PostShaderStage::clearPasses(void)
{
    editMFVertexShaders()->clear();
    editMFFragmentShaders()->clear();
    editMFPassSizes()->clear();
}

inline
void PostShaderStage::erasePass(UInt32 Index)
{
    editMFVertexShaders()->erase(Index);
    editMFFragmentShaders()->erase(Index);
    editMFPassSizes()->erase(Index);
}

inline
SimpleSHLChunk* PostShaderStage::getPassShader(UInt32 Index) const
{
    _PostProcessPasses[Index]->getShader();
}

OSG_END_NAMESPACE
