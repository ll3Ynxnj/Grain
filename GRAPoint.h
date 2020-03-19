#ifndef GRAPOINT_H
#define GRAPOINT_H

typedef struct
{
  float x;
  float y;
} GRAPoint;

static const GRAPoint kGRAPointNone = { 0, 0 };
static const GRAPoint kGRAPointNorm = { 1, 1 };

#endif
