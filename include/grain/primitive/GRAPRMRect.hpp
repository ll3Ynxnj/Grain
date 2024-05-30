#ifndef GRAIN_GRARECT_HPP
#define GRAIN_GRARECT_HPP

#include "GRAPRMVector.hpp"

template <typename T> struct GRAPRMRect
{
  GRAVec2<T> pos;
  GRAVec2<T> size;

  GRAPRMRect(GRAVec2<T> aPos, GRAVec2<T> aSize) : pos(aPos), size(aSize) {};
  ~GRAPRMRect() {};
};

#endif // GRAIN_GRARECT_HPP
