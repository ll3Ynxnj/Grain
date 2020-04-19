#ifndef GRARECT_HPP
#define GRARECT_HPP

#include "GRAPoint.hpp"
#include "GRASize.hpp"

struct GRARect
{
  GRAPoint pos;
  GRASize size;

  GRARect(GRAPoint aPos, GRASize aSize) : pos(aPos), size(aSize) {};
};

static const GRARect kGRARectNone = GRARect(GRAPoint(0), GRASize(0));
static const GRARect kGRARectNorm = GRARect(GRAPoint(0), GRASize(0));

#endif // GRARECT_HPP
