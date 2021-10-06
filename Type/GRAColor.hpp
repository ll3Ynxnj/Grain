#ifndef GRAIN_GRACOLOR_HPP
#define GRAIN_GRACOLOR_HPP

template <typename T> struct GRAColorRGBA8888
{
  T r = 0;
  T g = 0;
  T b = 0;
  T a = 0;

  GRAColorRGBA8888(): a(1) {}
  explicit GRAColorRGBA8888(T aV) : r(aV), g(aV), b(aV), a(aV) {}
  GRAColorRGBA8888(T aR, T aG, T aB, T aA) :
  r(aR), g(aG), b(aB), a(aA) {};

  void Mul(T aV) { r *= aV; g *= aV; b *= aV; a *= aV; };
  void Mul(const GRAColorRGBA8888<T> &aC)
  { r *= aC.r; g *= aC.g; b *= aC.b; a *= aC.a; };
};

#endif // GRAIN_GRACOLOR_HPP
