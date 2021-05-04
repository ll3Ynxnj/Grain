#ifndef PLAIN_GRALINE_HPP
#define PLAIN_GRALINE_HPP

template <typename T> struct GRALine
{
  GRAVec2<T> p0;
  GRAVec2<T> p1;

  GRALine<T>(const GRAVec2<T> &aP0, const GRAVec2<T> &aP1) :
    p0(aP0), p1(aP1) {};
};

#endif //PLAIN_GRALINE_HPP
