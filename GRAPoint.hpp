#ifndef GRAPOINT_HPP
#define GRAPOINT_HPP

#include "GRAVector.hpp"

typedef GRAVec3<float> GRAPoint;

static const GRAPoint kGRAPointNone = GRAPoint(0);
static const GRAPoint kGRAPointNorm = GRAPoint(1);

#endif // GRAPOINT_HPP
