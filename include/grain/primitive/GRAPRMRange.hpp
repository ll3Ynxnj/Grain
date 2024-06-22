#ifndef GRAIN_GRARANGE_HPP
#define GRAIN_GRARANGE_HPP

template <typename T>
struct GRAPRMRange {
  T start;
  T end;

  GRAPRMRange(const T& aStart, const T& aEnd): start(aStart), end(aEnd) {}

  bool IsInside(const T& value) const
  { return value >= start && value <= end; }

  bool operator==(const GRAPRMRange<T>& aRange) const
  { return start == aRange.start && end == aRange.end; }

  bool operator!=(const GRAPRMRange<T>& aRange) const
  { return !(*this == aRange); }
};

#endif // GRAIN_GRARANGE_HPP
