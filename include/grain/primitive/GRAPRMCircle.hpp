#ifndef GRAIN_GRACIRCLE_HPP
#define GRAIN_GRACIRCLE_HPP

#include "GRAPRMVector.hpp"

template <typename T> struct GRAPRMCircle
{
  GRAVec2<T> origin;
  T radius;

  GRAPRMCircle(const GRAVec2<T> &aOrigin, T aRadius) :
  origin(aOrigin), radius(aRadius) {}
};

#endif // GRAIN_GRACIRCLE_HPP
