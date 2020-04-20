#ifndef GRAIN_GRARECT_HPP
#define GRAIN_GRARECT_HPP

#include "GRAVector.hpp"

template <typename T> struct GRARect
{
  GRAVec3<T> pos;
  GRAVec3<T> size;

  GRARect<T>(GRAVec3<T> aPos, GRAVec3<T> aSize) : pos(aPos), size(aSize) {};
};

#endif // GRAIN_GRARECT_HPP
