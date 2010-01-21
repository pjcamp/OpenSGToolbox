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

/*****************************************************************************\
 *****************************************************************************
 **                                                                         **
 **                  This file is automatically generated.                  **
 **                                                                         **
 **          Any changes made to this file WILL be lost when it is          **
 **           regenerated, which can become necessary at any time.          **
 **                                                                         **
 **     Do not change this file, changes should be done in the derived      **
 **     class BlendedKeyframeAnimator!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &BlendedKeyframeAnimatorBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 BlendedKeyframeAnimatorBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 BlendedKeyframeAnimatorBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/


//! Get the value of the \a index element the BlendedKeyframeAnimator::_mfKeyframeSequences field.
inline
KeyframeSequence * BlendedKeyframeAnimatorBase::getKeyframeSequences(const UInt32 index) const
{
    return _mfKeyframeSequences[index];
}

//! Get the value of the \a index element the BlendedKeyframeAnimator::_mfBlendAmounts field.
inline
      Real32  BlendedKeyframeAnimatorBase::getBlendAmounts(const UInt32 index) const
{
    return _mfBlendAmounts[index];
}

inline
Real32 &BlendedKeyframeAnimatorBase::editBlendAmounts(const UInt32 index)
{
    editMField(BlendAmountsFieldMask, _mfBlendAmounts);

    return _mfBlendAmounts[index];
}



#ifdef OSG_MT_CPTR_ASPECT
inline
void BlendedKeyframeAnimatorBase::execSync (      BlendedKeyframeAnimatorBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (KeyframeSequencesFieldMask & whichField))
        _mfKeyframeSequences.syncWith(pFrom->_mfKeyframeSequences,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);

    if(FieldBits::NoField != (BlendAmountsFieldMask & whichField))
        _mfBlendAmounts.syncWith(pFrom->_mfBlendAmounts,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);
}
#endif


inline
const Char8 *BlendedKeyframeAnimatorBase::getClassname(void)
{
    return "BlendedKeyframeAnimator";
}
OSG_GEN_CONTAINERPTR(BlendedKeyframeAnimator);

OSG_END_NAMESPACE

