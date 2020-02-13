#ifndef GRASIZE_H
#define GRASIZE_H

#include "GRAType.h"

typedef struct
{
  GRAFloat width;
  GRAFloat height;
} GRASize;

static const GRASize kGRASizeNone = { 0, 0 };
static const GRASize kGRASizeNorm = { 1, 1 };

#endif
