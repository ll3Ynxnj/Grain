#ifndef GRAIN_GRACIRCLE_HPP
#define GRAIN_GRACIRCLE_HPP

#include "GRAVector.hpp"

template <typename T> struct GRACircle
{
  GRAVec2<T> origin;
  T radius;

  GRACircle(const GRAVec2<T> &aOrigin, T aRadius) :
  origin(aOrigin), radius(aRadius) {}
};

#endif // GRAIN_GRACIRCLE_HPP
