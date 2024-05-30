#ifndef GRAIN_GRAVECTOR_HPP
#define GRAIN_GRAVECTOR_HPP

#include <sstream>

template <typename T> struct GRAVec2
{
  T x = 0, y = 0;

  GRAVec2() {};
  explicit GRAVec2<T>(const T &aV) : x(aV), y(aV) {};
  GRAVec2<T>(const T &aX, const T &aY) : x(aX), y(aY) {};

  using Vec2 = GRAVec2<T>;

  Vec2 operator +(const Vec2 &v) const { return { x + v.x, y + v.y }; };
  Vec2 operator -(const Vec2 &v) const { return { x - v.x, y - v.y }; };
  Vec2 operator *(T s) const { return { x * s, y * s }; };
  Vec2 operator /(T s) const { return { x / s, y / s }; };

  Vec2 operator -() const { return { -x, -y }; };

  bool operator ==(const Vec2 &v) const { return x == v.x && y == v.y; }

  void operator +=(const Vec2 &v) { *this = { x + v.x, y + v.y }; };
  void operator -=(const Vec2 &v) { *this = { x - v.x, y - v.y }; };
  void operator *=(T s) { *this = { x * s, y * s }; };
  void operator /=(T s) { *this = { x / s, y / s }; };

  std::string str() const
  {
    std::stringstream ss;
    ss << "GRAVec2<T> x: " << x << ", y: " << y;
    return ss.str();
  }
};

template <typename T> struct GRAVec3
{
  T x = 0, y = 0, z = 0;

  GRAVec3() {};
  explicit GRAVec3<T>(const T &aV) : x(aV), y(aV), z(aV) {};
  GRAVec3<T>(const T &aX, const T &aY, const T &aZ) : x(aX), y(aY), z(aZ) {};

  using Vec3 = GRAVec3<T>;

  Vec3 operator +(const Vec3 &v) const
  { return { x + v.x, y + v.y,  z + v.z }; }
  Vec3 operator -(const Vec3 &v) const
  { return { x - v.x, y - v.y,  z - v.z }; }
  Vec3 operator *(T s) const { return { x * s, y * s, z * s }; }
  Vec3 operator /(T s) const { return { x / s, y / s, z / s }; }

  Vec3 operator -() const { return { -x, -y, -z }; }

  bool operator ==(const Vec3 &v) const
  { return x == v.x && y == v.y && z == v.z; }

  void operator +=(const Vec3 &v) { x += v.x; y += v.y; z += v.z; }
  void operator -=(const Vec3 &v) { x -= v.x; y -= v.y; z -= v.z; }
  void operator *=(T s) { x *= s; y *= s; z *= s; }
  void operator /=(T s) { x /= s; y /= s; z /= s; }

  std::string str() const
  {
    std::stringstream ss;
    ss << "GRAVec3<T> x: " << x << ", y: " << y << ", z: " << z;
    return ss.str();
  }
};

template <typename T> struct GRAVec4
{
  T x = 0, y = 0, z = 0, w = 0;

  GRAVec4() {};
  explicit GRAVec4<T>(const T &aV) : x(aV), y(aV), z(aV), w(aV) {};
  GRAVec4<T>(const T &aX, const T &aY, const T &aZ, const T &aW) :
    x(aX), y(aY), z(aZ), w(aW) {};

  using Vec4 = GRAVec4<T>;

  Vec4 operator +(const Vec4 &v) const
  { return { x + v.x, y + v.y, z + v.z, w + v.w }; }
  Vec4 operator -(const Vec4 &v) const
  { return { x - v.x, y - v.y, z - v.z, w + v.w }; }
  Vec4 operator *(T s) const { return { x * s, y * s, z * s, w * s }; }
  Vec4 operator /(T s) const { return { x / s, y / s, z / s, w / s }; }

  Vec4 operator -() const { return { -x, -y, -z, -w }; }

  bool operator ==(const Vec4 &v) const
  { return x == v.x && y == v.y && z == v.z && w == v.w; }

  void operator +=(const Vec4 &v) { x += v.x; y += v.y; z += v.z; w += v.w; }
  void operator -=(const Vec4 &v) { x -= v.x; y -= v.y; z -= v.z; w -= v.w; }
  void operator *=(T s) { x *= s; y *= s; z *= s; w *= s; }
  void operator /=(T s) { x /= s; y /= s; z /= s; w /= s; }

  std::string str() const
  {
    std::stringstream ss;
    ss << "GRAVec4<T> x: " << x << ", y: " << y << ", z: " << z << ", w: " << w;
    return ss.str();
  }
};

#endif // GRAIN_GRAVECTOR_HPP
