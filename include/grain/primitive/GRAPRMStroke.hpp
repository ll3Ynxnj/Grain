#ifndef GRAIN_GRASTROKE_HPP
#define GRAIN_GRASTROKE_HPP

#include "grain/primitive/GRAPRMType.hpp"
#include "grain/primitive/GRAPRMColor.hpp"

template <typename T> struct GRAStroke
{
  enum class Join : GRAInt
  {
    Miter,
    Round,
    Bevel,

    kNumberOfItems,
    None = kGRAIntUndefined,
  };

  enum class Align : GRAInt
  {
    Inside,
    Center,
    Outside,

    kNumberOfItems,
    None = kGRAIntUndefined,
  };

  GRAColorRGBA8888<T> color = GRAColorRGBA8888<T>(0);
  T width = 2.0f;
  Join join = Join::Miter;
  Align align = Align::Center;

  GRAStroke() = default;

  GRAStroke(const GRAColorRGBA8888<T> &aColor, T aWidth)
    : color(aColor), width(aWidth) {}

  GRAStroke(const GRAColorRGBA8888<T> &aColor, T aWidth,
            Join aJoin, Align aAlign)
    : color(aColor), width(aWidth), join(aJoin), align(aAlign) {}
};

#endif // GRAIN_GRASTROKE_HPP
