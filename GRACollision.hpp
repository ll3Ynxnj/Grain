#ifndef GRAIN_PLACOLLISION_HPP
#define GRAIN_PLACOLLISION_HPP

#include "Type/GRAPoint.hpp"
#include "Type/GRALine.hpp"
#include "Type/GRARect.hpp"
#include "Type/GRACircle.hpp"

template <typename T> class GRACollision {
public:
  /*
  static bool IsCollideWithPointAndPoint(const PLAPoint &aPoint0,
                                         const PLAPoint &aPoint1);

  static bool IsCollideWithPointAndLine(const PLAPoint &aPoint,
                                        const PLALine &aLine);

  static bool IsCollideWithPointAndRect(const PLAPoint &aPoint,
                                        const PLARect &aRect);

  static bool IsCollideWithPointAndCircle(const PLAPoint &aPoint,
                                          const PLACircle &aCircle);

  static bool IsCollideWithLineAndLine(const PLALine &aLine0,
                                       const PLALine &aLine1);

  static bool IsCollideWithLineAndRect(const PLALine &aLine,
                                       const PLARect &aRect);

  static bool IsCollideWithLineAndCircle(const PLALine &aLine,
                                         const PLACircle &aCircle);

  static bool IsCollideWithRectAndRect(const PLARect &aRect0,
                                       const PLARect &aRect1);

  static bool IsCollideWithRectAndCircle(const PLARect &aRect,
                                         const PLACircle &aCircle);

  static bool IsCollideWithCircleAndCircle(const PLACircle &aCircle0,
                                           const PLACircle &aCircle1);
  */

  static bool IsCollideWithPointAndPoint(const GRAPoint<T> &aPoint0,
                                         const GRAPoint<T> &aPoint1)
  {
    // A point cannot collide with point. This code was written to show that.
    return false;
  };

  static bool IsCollideWithPointAndLine(const GRAPoint<T> &aPoint,
                                        const GRALine<T> &aLine)
  {
    return false;
  };

  static bool IsCollideWithPointAndRect(const GRAPoint<T> &aPoint,
                                        const GRARect<T> &aRect)
  {
    if (aPoint.x < aRect.pos.x) { return false; }
    if (aPoint.y < aRect.pos.y) { return false; }
    if (aRect.pos.x + aRect.size.x <= aPoint.x) { return false; }
    if (aRect.pos.y + aRect.size.y <= aPoint.y) { return false; }
    return true;
  };

  static bool IsCollideWithPointAndCircle(const GRAPoint<T> &aPoint,
                                          const GRACircle<T> &aCircle)
  {
    return
      aCircle.radius >
      abs(hypot(aCircle.origin.x - aPoint.x, aCircle.origin.y - aPoint.y));
  };

  static bool IsCollideWithLineAndLine(const GRALine<T> &aLine0,
                                       const GRALine<T> &aLine1)
  {
    return false;
  };

  static bool IsCollideWithLineAndRect(const GRALine<T> &aLine,
                                       const GRARect<T> &aRect)
  {
    return false;
  };

  static bool IsCollideWithLineAndCircle(const GRALine<T> &aLine,
                                         const GRACircle<T> &aCircle)
  {
    return false;
  };

  static bool IsCollideWithRectAndRect(const GRARect<T> &aRect0,
                                       const GRARect<T> &aRect1)
  {
    if ((aRect1.pos.x + aRect1.size.x) <= aRect0.pos.x) { return false; }
    if ((aRect1.pos.y + aRect1.size.y) <= aRect0.pos.y) { return false; }
    if ((aRect0.pos.x + aRect0.size.x) <= aRect1.pos.x) { return false; }
    if ((aRect0.pos.y + aRect0.size.y) <= aRect1.pos.y) { return false; }
    return true;
  };

  static bool IsCollideWithRectAndCircle(const GRARect<T> &aRect,
                                         const GRACircle<T> &aCircle)
  {
    GRARect combinedRect = aRect;
    combinedRect.pos.x -= aCircle.radius;
    combinedRect.pos.y -= aCircle.radius;
    combinedRect.size.x += aCircle.radius * 2;
    combinedRect.size.y += aCircle.radius * 2;
    if (!GRACollision::IsCollideWithPointAndRect(aCircle.origin, combinedRect))
    { return false; }

    if (GRACollision::IsCollideWithPointAndRect(aCircle.origin, aRect))
    { return true; }

    GRAPoint<T> nearestPoint = GRAPoint<T>(0, 0);
    nearestPoint.x =
      abs(aCircle.origin.x - aRect.pos.x) <=
      abs(aCircle.origin.x - (aRect.pos.x + aRect.size.x)) ?
      aRect.pos.x : aRect.pos.x + aRect.size.x;
    nearestPoint.y =
      abs(aCircle.origin.y - aRect.pos.y) <=
      abs(aCircle.origin.y - (aRect.pos.y + aRect.size.y)) ?
      aRect.pos.y : aRect.pos.y + aRect.size.y;
    return GRACollision::IsCollideWithPointAndCircle(nearestPoint, aCircle);
  };

  static bool IsCollideWithCircleAndCircle(const GRACircle<T> &aCircle0,
                                           const GRACircle<T> &aCircle1)
  {
    return
      aCircle0.radius + aCircle1.radius >
      abs(hypot(aCircle1.origin.x - aCircle0.origin.x,
                aCircle1.origin.y - aCircle0.origin.y));
  };
};

#endif //GRAIN_PLACOLLISION_HPP

