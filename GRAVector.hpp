#ifndef GRAVECTOR_HPP
#define GRAVECTOR_HPP

template <typename T> struct GRAVec2
{
  explicit GRAVec2<T>(T aVal) : x(aVal), y(aVal) {};
  GRAVec2<T>(T aX, T aY) : x(aX), y(aY) {};
  T x, y;
};

template <typename T> struct GRAVec3
{
  explicit GRAVec3<T>(T aVal) : x(aVal), y(aVal), z(aVal) {};
  GRAVec3<T>(T aX, T aY, T aZ) : x(aX), y(aY), z(aZ) {};
  T x, y, z;
};

template <typename T> struct GRAVec4
{
  explicit GRAVec4<T>(T aVal) : x(aVal), y(aVal), z(aVal), w(aVal) {};
  GRAVec4<T>(T aX, T aY, T aZ, T aW) : x(aX), y(aY), z(aZ), w(aW) {};
  T x, y, z, w;
};

#endif //GRAVECTOR_HPP
