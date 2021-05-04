#ifndef GRAIN_GRACOLOR_HPP
#define GRAIN_GRACOLOR_HPP

template <typename T> struct GRAColorRGBA8888
{
  T r;
  T g;
  T b;
  T a;

  GRAColorRGBA8888(T aR, T aG, T aB, T aA) :
  r(aR), g(aG), b(aB), a(aA) {};
};

#endif // GRAIN_GRACOLOR_HPP
