#ifndef GRAIN_PLATILE_HPP
#define GRAIN_PLATILE_HPP

#include "GRAPRMType.hpp"
#include "GRAPRMVector.hpp"

template <typename T> struct GRAPRMTile
{
  GRAVec2<GRASize> tileSize = GRAVec2<GRASize>(0);
  GRAVec2<T> chipSize = GRAVec2<T>(0);

  GRAPRMTile(GRAVec2<GRASize> aTileSize, GRAVec2<T> aChipSize):
  tileSize(aTileSize), chipSize(aChipSize) {};
};

#endif //GRAIN_PLATILE_HPP
