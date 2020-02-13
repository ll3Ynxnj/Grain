#ifndef GRAPOINT_H
#define GRAPOINT_H

#include "GRAType.h"

typedef struct
{
  GRAFloat x;
  GRAFloat y;
} GRAPoint;

static const GRAPoint kGRAPointNone = { 0, 0 };
static const GRAPoint kGRAPointNorm = { 1, 1 };

#endif
