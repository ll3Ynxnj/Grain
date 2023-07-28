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
  GRAColorRGBA8888(T aR, T aG, T aB, T aA) : r(aR), g(aG), b(aB), a(aA) {}
  // Motionの_distanceが負の値になる場合があるので、ここで値のチェックは行わない
  // Do not check the value here because the value of _distance may be negative.
  /*
  r(aR < 0 ? 0 : 1 < aR ? 1 : aR),
  g(aG < 0 ? 0 : 1 < aG ? 1 : aG),
  b(aB < 0 ? 0 : 1 < aG ? 1 : aB),
  a(aA < 0 ? 0 : 1 < aA ? 1 : aA) {};
   */

  GRAColorRGBA8888 operator +(T aV) const
  { return GRAColorRGBA8888(r + aV, g + aV, b + aV, a + aV); }
  GRAColorRGBA8888 operator +(const GRAColorRGBA8888 &aC) const
  { return GRAColorRGBA8888(r + aC.r, g + aC.g, b + aC.b, a + aC.a); }
  void operator +=(T aV) { r += aV; g += aV; b += aV; a += aV; }
  void operator +=(const GRAColorRGBA8888<T> &aC)
  { r += aC.r; g += aC.g; b += aC.b; a += aC.a; };

  GRAColorRGBA8888 operator -(T aV) const
  { return GRAColorRGBA8888(r - aV, g - aV, b - aV, a - aV); }
  GRAColorRGBA8888 operator -(const GRAColorRGBA8888 &aC) const
  { return GRAColorRGBA8888(r - aC.r, g - aC.g, b - aC.b, a - aC.a); }
  void operator -=(T aV) { r -= aV; g -= aV; b -= aV; a -= aV; }
  void operator -=(const GRAColorRGBA8888<T> &aC)
  { r -= aC.r; g -= aC.g; b -= aC.b; a -= aC.a; };

  GRAColorRGBA8888 operator *(T aV) const
  { return GRAColorRGBA8888(r * aV, g * aV, b * aV, a * aV); }
  GRAColorRGBA8888 operator *(const GRAColorRGBA8888 &aC) const
  { return GRAColorRGBA8888(r * aC.r, g * aC.g, b * aC.b, a * aC.a); }
  void operator *=(T aV) { r *= aV; g *= aV; b *= aV; a *= aV; }
  void operator *=(const GRAColorRGBA8888<T> &aC)
  { r *= aC.r; g *= aC.g; b *= aC.b; a *= aC.a; };

  GRAColorRGBA8888 operator /(T aV) const
  { return GRAColorRGBA8888(r / aV, g / aV, b / aV, a / aV); }
  GRAColorRGBA8888 operator /(const GRAColorRGBA8888 &aC) const
  { return GRAColorRGBA8888(r / aC.r, g / aC.g, b / aC.b, a / aC.a); }
  void operator /=(T aV) { r /= aV; g /= aV; b /= aV; a /= aV; }
  void operator /=(const GRAColorRGBA8888<T> &aC)
  { r /= aC.r; g /= aC.g; b /= aC.b; a /= aC.a; };

  /*
  GRAColorRGBA8888 Mul(T aV) const
  { return GRAColorRGBA8888(r * aV, g * aV, b * aV, a * aV); };
  GRAColorRGBA8888 Mul(const GRAColorRGBA8888<T> &aC) const
  { return GRAColorRGBA8888(r * aC.r, g * aC.g, b * aC.b, a * aC.a); };
  void MulIn(T aV) { r *= aV; g *= aV; b *= aV; a *= aV; };
  void MulIn(const GRAColorRGBA8888<T> &aC)
  { r *= aC.r; g *= aC.g; b *= aC.b; a *= aC.a; };
   */
};

#endif // GRAIN_GRACOLOR_HPP
