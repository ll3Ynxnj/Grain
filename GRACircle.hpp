#ifndef GRACIRCLE_HPP
#define GRACIRCLE_HPP

#include "GRAPoint.hpp"

struct GRACircle
{
  GRAPoint origin;
  float radius;

  GRACircle(GRAPoint aOrigin, float aRadius) : origin(aOrigin), radius(aRadius) {}
};

static const GRACircle kGRACircleNone = GRACircle(GRAPoint(0), 0);
static const GRACircle kGRACircleNorm = GRACircle(GRAPoint(0), 1);

#endif // GRACIRCLE_HPP
