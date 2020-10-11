#ifndef GRAIN_GRAVECTOR_HPP
#define GRAIN_GRAVECTOR_HPP

template <typename T> struct GRAVec2
{
  T x, y;

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
};

template <typename T> struct GRAVec3
{
  T x, y, z;

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
};

template <typename T> struct GRAVec4
{
  T x, y, z, w;

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
};


#endif // GRAIN_GRAVECTOR_HPP
