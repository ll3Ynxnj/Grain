#ifndef PLAIN_GRALINE_HPP
#define PLAIN_GRALINE_HPP

#include "GRAPRMVector.hpp"

template <typename T> struct GRAPRMLine
{
  GRAVec2<T> p0;
  GRAVec2<T> p1;

  GRAPRMLine(const GRAVec2<T> &aP0, const GRAVec2<T> &aP1) :
    p0(aP0), p1(aP1) {};
};

#endif //PLAIN_GRALINE_HPP
