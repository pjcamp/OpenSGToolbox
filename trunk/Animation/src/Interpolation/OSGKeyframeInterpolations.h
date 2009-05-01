#ifndef _OPENSG_MFINTERPOLATIONS_H_
#define _OPENSG_MFINTERPOLATIONS_H_

#include "OSGAnimationDef.h"

#include <OpenSG/OSGField.h>
#include <OpenSG/OSGMFBaseTypes.h>
#include <OpenSG/OSGMFSysTypes.h>
#include <OpenSG/OSGSFMathTypes.h>
#include <OpenSG/OSGBaseTypes.h>

#include <OpenSG/Toolbox/OSGInterpolations.h>
#include "KeyframeSequence/OSGKeyframeSequenceFields.h"
#include <boost/function.hpp>

OSG_BEGIN_NAMESPACE

enum InterpolationType {LINEAR_INTERPOLATION=1, CUBIC_INTERPOLATION=2, STEP_INTERPOLATION=4, LINEAR_NORMAL_INTERPOLATION=8};
enum ValueReplacementPolicy {OVERWRITE=1, ADDITIVE_ABSOLUTE=2, ADDITIVE_SINCE_LAST=4};

typedef boost::function<bool (const Real32&, osg::Field&, bool)> RawInterpFuncion;
typedef boost::function<bool (RawInterpFuncion&,
                              const osg::Real32&,
                              const osg::Real32&,
                              const osg::ValueReplacementPolicy&,
                              bool,
                              osg::Field&)> ReplacementFuncion;

bool OSG_ANIMATIONLIB_DLLMAPPING getInterpolationIndexes(const osg::MFReal32& Keys, const osg::Real32& time, osg::UInt32& LastKeyframeIndex, osg::UInt32& NextKeyframeIndex, osg::Real32& t, bool isCyclic=false);

bool OSG_ANIMATIONLIB_DLLMAPPING getInterpolationIndex(const osg::MFReal32& Keys, const osg::Real32& time, osg::UInt32& Index, osg::Real32& t, bool isCyclic=false);

//Generic Replace
template<class SFieldTypeT>
bool replacement(RawInterpFuncion& InterpFunc,
                              const osg::Real32& time,
                              const osg::Real32& prevtime,
                              const osg::ValueReplacementPolicy& ReplacePolicy,
                              bool isCyclic,
                              osg::Field& Result)
{
    SFieldTypeT Value(static_cast<SFieldTypeT&>(Result).getValue());
    bool ReturnValue = InterpFunc(time, Value,isCyclic);

    switch(ReplacePolicy)
    {
    case ADDITIVE_SINCE_LAST:
        {
            SFieldTypeT PrevValue;
            InterpFunc(prevtime, PrevValue,isCyclic);
            static_cast<SFieldTypeT&>(Result).setValue(static_cast<SFieldTypeT&>(Result).getValue() + (Value.getValue() - PrevValue.getValue()));
            break;
        }
    case ADDITIVE_ABSOLUTE:
        static_cast<SFieldTypeT&>(Result).setValue(static_cast<SFieldTypeT&>(Result).getValue() + Value.getValue());
        break;
    case OVERWRITE:
        static_cast<SFieldTypeT&>(Result).setValue(Value.getValue());
        break;
    default:
        SWARNING << "No policy defined for Animation value replacement policy: " << ReplacePolicy << "." << std::endl;
        break;
   }
   return ReturnValue;
}
//Matrix Replace
template<>
bool OSG_ANIMATIONLIB_DLLMAPPING replacement<SFMatrix>(RawInterpFuncion& InterpFunc,
                              const osg::Real32& time,
                              const osg::Real32& prevtime,
                              const osg::ValueReplacementPolicy& ReplacePolicy,
                              bool isCyclic,
                              osg::Field& Result);

//String Replace
template<>
bool OSG_ANIMATIONLIB_DLLMAPPING replacement<SFString>(RawInterpFuncion& InterpFunc,
                              const osg::Real32& time,
                              const osg::Real32& prevtime,
                              const osg::ValueReplacementPolicy& ReplacePolicy,
                              bool isCyclic,
                              osg::Field& Result);

//Generic Step
template<class MFieldTypeT,class SFieldTypeT>
bool  stepKeyframeSequence(  const MFieldTypeT& KeyValues, const osg::MFReal32& Keys, const osg::Real32& time, osg::Field& Value, bool isCyclic=false )
{
   osg::Real32 t;
   osg::UInt32 LastKeyframeIndex, NextKeyframeIndex;
   SFieldTypeT Result;
   
   if( getInterpolationIndexes(Keys, time, LastKeyframeIndex, NextKeyframeIndex, t, isCyclic) )
   {
      Result.setValue(KeyValues.back());
   }
   else
   {
      //Return the floor
      Result.setValue(KeyValues[LastKeyframeIndex]);
   }
   if(Result.getValue() == static_cast<SFieldTypeT&>(Value).getValue())
   {
      return false;
   }
   else
   {
      static_cast<SFieldTypeT&>(Value).setValue(Result.getValue());
      return true;
   }
}

//Generic Lerp
template<class MFieldTypeT,class SFieldTypeT>
bool  lerpKeyframeSequence(  const MFieldTypeT& KeyValues, const osg::MFReal32& Keys, const osg::Real32& time, osg::Field& Value, bool isCyclic=false )
{
   osg::Real32 t;
   osg::UInt32 LastKeyframeIndex, NextKeyframeIndex;
   
   if( getInterpolationIndexes(Keys, time, LastKeyframeIndex, NextKeyframeIndex, t, isCyclic) )
   {
      static_cast<SFieldTypeT&>(Value).setValue(KeyValues[KeyValues.size()-1]);
   }
   else
   {
      //Return the linearly interpolated value
      static_cast<SFieldTypeT&>(Value).setValue(osg::lerp(KeyValues[LastKeyframeIndex], KeyValues[NextKeyframeIndex], t));
   }
   return true;
}

//Generic Spline
template<typename MFieldTypeT,typename SFieldTypeT>
bool  splineKeyframeSequence(  const MFieldTypeT& KeyValues, const osg::MFReal32& Keys, const osg::Real32& time, osg::Field& Value, bool isCyclic=false )
{
   osg::Real32 t;
   osg::UInt32 i;
   
   if( getInterpolationIndex(Keys, time, i, t, isCyclic) )
   {
      static_cast<SFieldTypeT&>(Value).setValue(KeyValues[KeyValues.size()-1]);
      return true;
   }
   
   std::vector< typename MFieldTypeT::StoredType > V;
   std::vector<osg::Real32> T;
   
   V.reserve(4);
   T.reserve(4);
   
   if(isCyclic)
   {
      if(i == 0)
      {
         V.push_back(KeyValues[KeyValues.size()-2]);
         V.push_back(KeyValues[i]);
         V.push_back(KeyValues[i+1]);
         V.push_back(KeyValues[i+2]);

         T.push_back(Keys[Keys.size()-2] - Keys[Keys.size()-1]);
         T.push_back(Keys[i]);
         T.push_back(Keys[i+1]);
         T.push_back(Keys[i+2]);
      }
      else if(i == KeyValues.size()-1)
      {
         V.push_back(KeyValues[i-1]);
         V.push_back(KeyValues[i]);
         V.push_back(KeyValues[1]);
         V.push_back(KeyValues[2]);

         T.push_back(Keys[i-1]);
         T.push_back(Keys[i]);
         T.push_back(Keys[1] + Keys[KeyValues.size()-1]);
         T.push_back(Keys[2] + Keys[KeyValues.size()-1]);
      }
      else if(i == KeyValues.size()-2)
      {
         V.push_back(KeyValues[i-1]);
         V.push_back(KeyValues[i]);
         V.push_back(KeyValues[i+1]);
         V.push_back(KeyValues[1]);

         T.push_back(Keys[i-1]);
         T.push_back(Keys[i]);
         T.push_back(Keys[i+1]);
         T.push_back(Keys[1] + Keys[KeyValues.size()-1]);
      }
      else
      {
         V.push_back(KeyValues[i-1]);
         V.push_back(KeyValues[i]);
         V.push_back(KeyValues[i+1]);
         V.push_back(KeyValues[i+2]);

         T.push_back(Keys[i-1]);
         T.push_back(Keys[i]);
         T.push_back(Keys[i+1]);
         T.push_back(Keys[i+2]);
      }
   }
   else
   {
      if(i == 0)
      {
         V.push_back(KeyValues[i]);
         V.push_back(KeyValues[i]);
         V.push_back(KeyValues[i+1]);
         V.push_back(KeyValues[i+2]);

         T.push_back(Keys[i+1]);
         T.push_back(Keys[i]);
         T.push_back(Keys[i+1]);
         T.push_back(Keys[i+2]);
      }
      else if(i == KeyValues.size()-1)
      {
         static_cast<SFieldTypeT&>(Value).setValue(KeyValues[KeyValues.size()-1]);
         return true;
      }
      else if(i == KeyValues.size()-2)
      {
         V.push_back(KeyValues[i-1]);
         V.push_back(KeyValues[i]);
         V.push_back(KeyValues[i+1]);
         V.push_back(KeyValues[i+1]);

         T.push_back(Keys[i-1]);
         T.push_back(Keys[i]);
         T.push_back(Keys[i+1]);
         T.push_back(Keys[i]);
      }
      else
      {
         V.push_back(KeyValues[i-1]);
         V.push_back(KeyValues[i]);
         V.push_back(KeyValues[i+1]);
         V.push_back(KeyValues[i+2]);

         T.push_back(Keys[i-1]);
         T.push_back(Keys[i]);
         T.push_back(Keys[i+1]);
         T.push_back(Keys[i+2]);
      }
   }
   
   static_cast<SFieldTypeT&>(Value).setValue(spline(V, T, t));
   return true;
}

//Normals Lerp
template<class MFieldTypeT,class SFieldTypeT>
bool  lerpNormalKeyframeSequence(  const MFieldTypeT& KeyValues, const osg::MFReal32& Keys, const osg::Real32& time, osg::Field& Value, bool isCyclic=false )
{
   osg::Real32 t;
   osg::UInt32 LastKeyframeIndex, NextKeyframeIndex;
   
   if( getInterpolationIndexes(Keys, time, LastKeyframeIndex, NextKeyframeIndex, t, isCyclic) )
   {
      static_cast<SFieldTypeT&>(Value).setValue(KeyValues[KeyValues.size()-1]);
   }
   else
   {
      //Return the linearly interpolated value
      static_cast<SFieldTypeT&>(Value).setValue(lerpNormal(KeyValues[LastKeyframeIndex], KeyValues[NextKeyframeIndex], t));
   }
   return true;
}

//Slerp -- Quaternion Lerp
template<class MFieldTypeT,class SFieldTypeT>
bool  slerpKeyframeSequence(  const MFieldTypeT& KeyValues, const osg::MFReal32& Keys, const osg::Real32& time, osg::Field& Value, bool isCyclic=false )
{
   osg::Real32 t;
   osg::UInt32 LastKeyframeIndex, NextKeyframeIndex;
   
   if( getInterpolationIndexes(Keys, time, LastKeyframeIndex, NextKeyframeIndex, t, isCyclic) )
   {
      static_cast<SFieldTypeT&>(Value).setValue( KeyValues[KeyValues.size()-1] );
   }
   else
   {
      //Return the spherically interpolated value
      static_cast<SFieldTypeT&>(Value).setValue(slerp(KeyValues[LastKeyframeIndex], KeyValues[NextKeyframeIndex], t));
   }
   return true;
}

//Squad -- Quaternion Spline
template<class MFieldTypeT,class SFieldTypeT>
bool  squadKeyframeSequence(  const MFieldTypeT& KeyValues, const osg::MFReal32& Keys, const osg::Real32& time, osg::Field& Value, bool isCyclic=false )
{
   osg::Real32 t;
   osg::UInt32 i;
   
   if( getInterpolationIndex(Keys, time, i, t, isCyclic) )
   {
      static_cast<SFieldTypeT&>(Value).setValue( KeyValues[KeyValues.size()-1] );
      return true;
   }
   
   std::vector<Quaternion > Q;
   std::vector<osg::Real32> T;
   
   Q.reserve(4);
   T.reserve(4);
   
   if(isCyclic)
   {
      if(i == 0)
      {
         Q.push_back(KeyValues[KeyValues.size()-2]);
         Q.push_back(KeyValues[i]);
         Q.push_back(KeyValues[i+1]);
         Q.push_back(KeyValues[i+2]);

         T.push_back(Keys[Keys.size()-2] - Keys[Keys.size()-1]);
         T.push_back(Keys[i]);
         T.push_back(Keys[i+1]);
         T.push_back(Keys[i+2]);
      }
      else if(i == KeyValues.size()-1)
      {
         Q.push_back(KeyValues[i-1]);
         Q.push_back(KeyValues[i]);
         Q.push_back(KeyValues[1]);
         Q.push_back(KeyValues[2]);

         T.push_back(Keys[i-1]);
         T.push_back(Keys[i]);
         T.push_back(Keys[1] + Keys[KeyValues.size()-1]);
         T.push_back(Keys[2] + Keys[KeyValues.size()-1]);
      }
      else if(i == KeyValues.size()-2)
      {
         Q.push_back(KeyValues[i-1]);
         Q.push_back(KeyValues[i]);
         Q.push_back(KeyValues[i+1]);
         Q.push_back(KeyValues[1]);

         T.push_back(Keys[i-1]);
         T.push_back(Keys[i]);
         T.push_back(Keys[i+1]);
         T.push_back(Keys[1] + Keys[KeyValues.size()-1]);
      }
      else
      {
         Q.push_back(KeyValues[i-1]);
         Q.push_back(KeyValues[i]);
         Q.push_back(KeyValues[i+1]);
         Q.push_back(KeyValues[i+2]);

         T.push_back(Keys[i-1]);
         T.push_back(Keys[i]);
         T.push_back(Keys[i+1]);
         T.push_back(Keys[i+2]);
      }
   }
   else
   {
      if(i == 0)
      {
         Q.push_back(KeyValues[i]);
         Q.push_back(KeyValues[i]);
         Q.push_back(KeyValues[i+1]);
         Q.push_back(KeyValues[i+2]);

         T.push_back(Keys[i+1]);
         T.push_back(Keys[i]);
         T.push_back(Keys[i+1]);
         T.push_back(Keys[i+2]);
      }
      else if(i == KeyValues.size()-1)
      {
         static_cast<SFieldTypeT&>(Value).setValue(KeyValues[KeyValues.size()-1]);
         return true;
      }
      else if(i == KeyValues.size()-2)
      {
         Q.push_back(KeyValues[i-1]);
         Q.push_back(KeyValues[i]);
         Q.push_back(KeyValues[i+1]);
         Q.push_back(KeyValues[i+1]);

         T.push_back(Keys[i-1]);
         T.push_back(Keys[i]);
         T.push_back(Keys[i+1]);
         T.push_back(Keys[i]);
      }
      else
      {
         Q.push_back(KeyValues[i-1]);
         Q.push_back(KeyValues[i]);
         Q.push_back(KeyValues[i+1]);
         Q.push_back(KeyValues[i+2]);

         T.push_back(Keys[i-1]);
         T.push_back(Keys[i]);
         T.push_back(Keys[i+1]);
         T.push_back(Keys[i+2]);
      }
   }
   
   static_cast<SFieldTypeT&>(Value).setValue(squad(Q, T, t));
   return true;
}

/*
//Floor
template <class FieldTypeT, osg::Int32 fieldNameSpace>
bool  floor(  const osg::MField<FieldTypeT, fieldNameSpace>& KeyValues, const osg::MFReal32& Keys, const osg::Real32& time, FieldTypeT& Value, bool isCyclic=false )
{
   osg::Real32 t;
   osg::UInt32 LastKeyframeIndex, NextKeyframeIndex;
   FieldTypeT Result;
   
   if( getInterpolationIndexes(Keys, time, LastKeyframeIndex, NextKeyframeIndex, t, isCyclic) )
   {
      Result = KeyValues[KeyValues.size()-1];
   }  
   else
   {  
      //Return the floor
      Result = KeyValues[LastKeyframeIndex];
   }
   if(Result == Value)
   {
      return false;
   }
   else
   {
      Value = Result;
      return true;
   }
}

//Ceil
template <class FieldTypeT, osg::Int32 fieldNameSpace>
bool  ceil(  const osg::MField<FieldTypeT, fieldNameSpace>& KeyValues, const osg::MFReal32& Keys, const osg::Real32& time, FieldTypeT& Value, bool isCyclic=false )
{
   osg::Real32 t;
   osg::UInt32 LastKeyframeIndex, NextKeyframeIndex;
   FieldTypeT Result;
   
   if( getInterpolationIndexes(Keys, time, LastKeyframeIndex, NextKeyframeIndex, t, isCyclic) )
   {
      Result = KeyValues[KeyValues.size()-1];
   }
   else
   {  
      //Return the floor
      Result = KeyValues[NextKeyframeIndex];
   }
   if(Result == Value)
   {
      return false;
   }
   else
   {
      Value = Result;
      return true;
   }
}

//Closest
template <class FieldTypeT, osg::Int32 fieldNameSpace>
bool  closest(  const osg::MField<FieldTypeT, fieldNameSpace>& KeyValues, const osg::MFReal32& Keys, const osg::Real32& time, FieldTypeT& Value, bool isCyclic=false )
{
   osg::Real32 t;
   osg::UInt32 LastKeyframeIndex, NextKeyframeIndex;
   FieldTypeT Result;
   
   if( getInterpolationIndexes(Keys, time, LastKeyframeIndex, NextKeyframeIndex, t, isCyclic) )
   {
      Result = KeyValues[KeyValues.size()-1];
   }
   else
   {
      //Return the closest
      if(t <= 0.5)
      {
         Result = KeyValues[LastKeyframeIndex];
      }
      else
      {
         Result = KeyValues[NextKeyframeIndex];
      }
   }
   if(Result == Value)
   {
      return false;
   }
   else
   {
      Value = Result;
      return true;
   }
}*/

OSG_END_NAMESPACE

#endif