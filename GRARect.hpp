#ifndef GRAIN_GRARECT_HPP
#define GRAIN_GRARECT_HPP

#include "GRAVector.hpp"

template <typename T> struct GRARect
{
  GRAVec2<T> pos;
  GRAVec2<T> size;
};

#endif // GRAIN_GRARECT_HPP
