#ifndef GRACIRCLE_H
#define GRACIRCLE_H

#include "GRAPoint.h"

typedef struct
{
  GRAPoint origin;
  float radius;
} GRACircle;

static const GRACircle kGRACircleNone = {(GRAPoint){0, 0}, 0};
static const GRACircle kGRACircleNorm = {(GRAPoint){0, 0}, 1};

#endif
