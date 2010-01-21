/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *   contact:  David Kabala (djkabala@gmail.com), David Naylor               *
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
 **     class SkeletonBlendedAnimation!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &SkeletonBlendedAnimationBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 SkeletonBlendedAnimationBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 SkeletonBlendedAnimationBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/


//! Get the value of the \a index element the SkeletonBlendedAnimation::_mfSkeletonAnimations field.
inline
SkeletonAnimation * SkeletonBlendedAnimationBase::getSkeletonAnimations(const UInt32 index) const
{
    return _mfSkeletonAnimations[index];
}

//! Get the value of the \a index element the SkeletonBlendedAnimation::_mfBlendAmounts field.
inline
      Real32  SkeletonBlendedAnimationBase::getBlendAmounts(const UInt32 index) const
{
    return _mfBlendAmounts[index];
}

inline
Real32 &SkeletonBlendedAnimationBase::editBlendAmounts(const UInt32 index)
{
    editMField(BlendAmountsFieldMask, _mfBlendAmounts);

    return _mfBlendAmounts[index];
}


//! Get the value of the \a index element the SkeletonBlendedAnimation::_mfOverrideStatuses field.
inline
      UInt8  SkeletonBlendedAnimationBase::getOverrideStatuses(const UInt32 index) const
{
    return _mfOverrideStatuses[index];
}

inline
UInt8 &SkeletonBlendedAnimationBase::editOverrideStatuses(const UInt32 index)
{
    editMField(OverrideStatusesFieldMask, _mfOverrideStatuses);

    return _mfOverrideStatuses[index];
}



#ifdef OSG_MT_CPTR_ASPECT
inline
void SkeletonBlendedAnimationBase::execSync (      SkeletonBlendedAnimationBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (SkeletonAnimationsFieldMask & whichField))
        _mfSkeletonAnimations.syncWith(pFrom->_mfSkeletonAnimations,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);

    if(FieldBits::NoField != (BlendAmountsFieldMask & whichField))
        _mfBlendAmounts.syncWith(pFrom->_mfBlendAmounts,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);

    if(FieldBits::NoField != (OverrideStatusesFieldMask & whichField))
        _mfOverrideStatuses.syncWith(pFrom->_mfOverrideStatuses,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);
}
#endif


inline
const Char8 *SkeletonBlendedAnimationBase::getClassname(void)
{
    return "SkeletonBlendedAnimation";
}
OSG_GEN_CONTAINERPTR(SkeletonBlendedAnimation);

OSG_END_NAMESPACE

