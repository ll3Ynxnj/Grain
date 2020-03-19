#ifndef GRASIZE_H
#define GRASIZE_H

typedef struct
{
  float width;
  float height;
} GRASize;

static const GRASize kGRASizeNone = { 0, 0 };
static const GRASize kGRASizeNorm = { 1, 1 };

#endif
