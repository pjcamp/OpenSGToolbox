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
 **     class SkeletonDrawable!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &SkeletonDrawableBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 SkeletonDrawableBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 SkeletonDrawableBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/


//! Get the value of the SkeletonDrawable::_sfSkeleton field.
inline
Skeleton * SkeletonDrawableBase::getSkeleton(void) const
{
    return _sfSkeleton.getValue();
}

//! Set the value of the SkeletonDrawable::_sfSkeleton field.
inline
void SkeletonDrawableBase::setSkeleton(Skeleton * const value)
{
    editSField(SkeletonFieldMask);

    _sfSkeleton.setValue(value);
}
//! Get the value of the SkeletonDrawable::_sfDrawBindPose field.

inline
bool &SkeletonDrawableBase::editDrawBindPose(void)
{
    editSField(DrawBindPoseFieldMask);

    return _sfDrawBindPose.getValue();
}

//! Get the value of the SkeletonDrawable::_sfDrawBindPose field.
inline
      bool  SkeletonDrawableBase::getDrawBindPose(void) const
{
    return _sfDrawBindPose.getValue();
}

//! Set the value of the SkeletonDrawable::_sfDrawBindPose field.
inline
void SkeletonDrawableBase::setDrawBindPose(const bool value)
{
    editSField(DrawBindPoseFieldMask);

    _sfDrawBindPose.setValue(value);
}
//! Get the value of the SkeletonDrawable::_sfDrawPose field.

inline
bool &SkeletonDrawableBase::editDrawPose(void)
{
    editSField(DrawPoseFieldMask);

    return _sfDrawPose.getValue();
}

//! Get the value of the SkeletonDrawable::_sfDrawPose field.
inline
      bool  SkeletonDrawableBase::getDrawPose(void) const
{
    return _sfDrawPose.getValue();
}

//! Set the value of the SkeletonDrawable::_sfDrawPose field.
inline
void SkeletonDrawableBase::setDrawPose(const bool value)
{
    editSField(DrawPoseFieldMask);

    _sfDrawPose.setValue(value);
}
//! Get the value of the SkeletonDrawable::_sfBindPoseColor field.

inline
Color4f &SkeletonDrawableBase::editBindPoseColor(void)
{
    editSField(BindPoseColorFieldMask);

    return _sfBindPoseColor.getValue();
}

//! Get the value of the SkeletonDrawable::_sfBindPoseColor field.
inline
const Color4f &SkeletonDrawableBase::getBindPoseColor(void) const
{
    return _sfBindPoseColor.getValue();
}

//! Set the value of the SkeletonDrawable::_sfBindPoseColor field.
inline
void SkeletonDrawableBase::setBindPoseColor(const Color4f &value)
{
    editSField(BindPoseColorFieldMask);

    _sfBindPoseColor.setValue(value);
}
//! Get the value of the SkeletonDrawable::_sfPoseColor field.

inline
Color4f &SkeletonDrawableBase::editPoseColor(void)
{
    editSField(PoseColorFieldMask);

    return _sfPoseColor.getValue();
}

//! Get the value of the SkeletonDrawable::_sfPoseColor field.
inline
const Color4f &SkeletonDrawableBase::getPoseColor(void) const
{
    return _sfPoseColor.getValue();
}

//! Set the value of the SkeletonDrawable::_sfPoseColor field.
inline
void SkeletonDrawableBase::setPoseColor(const Color4f &value)
{
    editSField(PoseColorFieldMask);

    _sfPoseColor.setValue(value);
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void SkeletonDrawableBase::execSync (      SkeletonDrawableBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (SkeletonFieldMask & whichField))
        _sfSkeleton.syncWith(pFrom->_sfSkeleton);

    if(FieldBits::NoField != (DrawBindPoseFieldMask & whichField))
        _sfDrawBindPose.syncWith(pFrom->_sfDrawBindPose);

    if(FieldBits::NoField != (DrawPoseFieldMask & whichField))
        _sfDrawPose.syncWith(pFrom->_sfDrawPose);

    if(FieldBits::NoField != (BindPoseColorFieldMask & whichField))
        _sfBindPoseColor.syncWith(pFrom->_sfBindPoseColor);

    if(FieldBits::NoField != (PoseColorFieldMask & whichField))
        _sfPoseColor.syncWith(pFrom->_sfPoseColor);
}
#endif


inline
const Char8 *SkeletonDrawableBase::getClassname(void)
{
    return "SkeletonDrawable";
}
OSG_GEN_CONTAINERPTR(SkeletonDrawable);

OSG_END_NAMESPACE

