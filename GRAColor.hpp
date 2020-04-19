#ifndef GRACOLOR_HPP
#define GRACOLOR_HPP

struct GRAColor
{
  float r;
  float g;
  float b;
  float a;

  explicit GRAColor(float aVal) : r(aVal), g(aVal), b(aVal), a(aVal) {};
  GRAColor(float aR, float aG, float aB, float aA) : r(aR), g(aG), b(aB), a(aA) {};
};

static const GRAColor kGRAColorBlack   = GRAColor(0.00, 0.00, 0.00, 1.00);
static const GRAColor kGRAColorRed     = GRAColor(1.00, 0.00, 0.00, 1.00);
static const GRAColor kGRAColorGreen   = GRAColor(0.00, 1.00, 0.00, 1.00);
static const GRAColor kGRAColorBlue    = GRAColor(0.00, 0.00, 1.00, 1.00);
static const GRAColor kGRAColorYellow  = GRAColor(1.00, 1.00, 0.00, 1.00);
static const GRAColor kGRAColorCyan    = GRAColor(0.00, 1.00, 1.00, 1.00);
static const GRAColor kGRAColorMagenta = GRAColor(1.00, 0.00, 1.00, 1.00);
static const GRAColor kGRAColorGray    = GRAColor(0.50, 0.50, 0.50, 1.00);
static const GRAColor kGRAColorWhite   = GRAColor(1.00, 1.00, 1.00, 1.00);

static const GRAColor kGRAColorNone = GRAColor(0);
static const GRAColor kGRAColorNorm = GRAColor(1);

#endif // GRACOLOR_HPP
