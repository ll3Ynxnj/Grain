#ifndef GRAIN_GRACIRCLE_HPP
#define GRAIN_GRACIRCLE_HPP

#include "GRAVector.hpp"

template <typename T> struct GRACircle
{
  GRAVec3<T> origin;
  float radius;

  GRACircle<T>(GRAVec3<T> aOrigin, float aRadius) : origin(aOrigin), radius(aRadius) {}
};

#endif // GRAIN_GRACIRCLE_HPP
