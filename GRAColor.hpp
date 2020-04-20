#ifndef GRAIN_GRACOLOR_HPP
#define GRAIN_GRACOLOR_HPP

struct GRAColorRGBA8888
{
  float r;
  float g;
  float b;
  float a;

  explicit GRAColorRGBA8888(float aVal) : r(aVal), g(aVal), b(aVal), a(aVal) {};
  GRAColorRGBA8888(float aR, float aG, float aB, float aA) : r(aR), g(aG), b(aB), a(aA) {};
};

#endif // GRAIN_GRACOLOR_HPP
