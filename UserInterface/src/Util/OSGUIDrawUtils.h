#ifndef _OSG_UI_DRAW_UTILS_H_
#define _OSG_UI_DRAW_UTILS_H_
#ifdef __sgi
#pragma once
#endif

#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"
#include <OpenSG/OSGVector.h>
#include "Component/OSGComponent.h"

OSG_BEGIN_NAMESPACE

void OSG_USERINTERFACELIB_DLLMAPPING convertTopLeftToCenteredLine(const Pnt2s& Point1, const Pnt2s& Point2, const UInt16 Width,Pnt2s& ResultPoint1, Pnt2s& ResultPoint2);
void OSG_USERINTERFACELIB_DLLMAPPING convertTopRightToCenteredLine(const Pnt2s& Point1, const Pnt2s& Point2, const UInt16 Width,Pnt2s& ResultPoint1, Pnt2s& ResultPoint2);

Pnt2s OSG_USERINTERFACELIB_DLLMAPPING calculateAlignment(const Pnt2s& Position1, const Vec2s& Size1, const Vec2s& Size2, const UInt32& VAlign, const UInt32& HAlign);

void OSG_USERINTERFACELIB_DLLMAPPING quadIntersection(const Pnt2s& Quad1TopLeft, const Vec2s& Quad1Size,
                                                      const Pnt2s& Quad2TopLeft, const Vec2s& Quad2Size,
                                                      Pnt2s& ResultQuadTopLeft, Vec2s& ResultQuadSize);
void OSG_USERINTERFACELIB_DLLMAPPING componentQuadIntersection(const ComponentPtr c1,
                                                      const ComponentPtr c2,
                                                      Pnt2s& ResultQuadTopLeft, Vec2s& ResultQuadSize);
OSG_END_NAMESPACE

#endif /* _OSG_UI_DRAW_UTILS_H_ */
