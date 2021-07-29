#ifndef ANHR_GRATILE_HPP
#define ANHR_GRATILE_HPP

#include "GRAType.hpp"

template <typename T> struct GRATile
{
  GRAVec2<GRASize> tileSize = GRAVec2<GRASize>(0);
  GRAVec2<T> chipSize = GRAVec2<T>(0);

  GRATile(GRAVec2<GRASize> aTileSize, GRAVec2<T> aChipSize):
  tileSize(aTileSize), chipSize(aChipSize) {};
};

#endif //ANHR_GRATILE_HPP
