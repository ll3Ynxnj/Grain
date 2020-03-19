#ifndef GRACOLOR_H
#define GRACOLOR_H

typedef struct
{
  float r;
  float g;
  float b;
  float a;
} GRAColor;

static const GRAColor kGRAColorBlack   = { 0.00, 0.00, 0.00, 1.00 };
static const GRAColor kGRAColorRed     = { 1.00, 0.00, 0.00, 1.00 };
static const GRAColor kGRAColorGreen   = { 0.00, 1.00, 0.00, 1.00 };
static const GRAColor kGRAColorBlue    = { 0.00, 0.00, 1.00, 1.00 };
static const GRAColor kGRAColorYellow  = { 1.00, 1.00, 0.00, 1.00 };
static const GRAColor kGRAColorCyan    = { 0.00, 1.00, 1.00, 1.00 };
static const GRAColor kGRAColorMagenta = { 1.00, 0.00, 1.00, 1.00 };
static const GRAColor kGRAColorWhite   = { 1.00, 1.00, 1.00, 1.00 };

static const GRAColor kGRAColorNone = { 0, 0, 0, 0 };
static const GRAColor kGRAColorNorm = { 1, 1, 1, 1 };

#endif
