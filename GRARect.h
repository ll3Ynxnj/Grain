#ifndef GRARECT_H
#define GRARECT_H

#include "GRAPoint.h"
#include "GRASize.h"

typedef struct
{
  GRAPoint position;
  GRASize size;
} GRARect;

static const GRARect kGRARectNone = {{0, 0}, {0, 0}};
static const GRARect kGRARectNorm = {{0, 0}, {1, 1}};

#endif
