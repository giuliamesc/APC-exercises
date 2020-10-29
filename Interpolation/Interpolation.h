#ifndef INTERPOLATION_HH
#define INTERPOLATION_HH

#include <vector>
#include <limits>
#include "Point.h"

class Interpolation
{
protected:
  std::vector<Point> points; // sorted_vector
  static constexpr double err_val = std::numeric_limits<double>::quiet_NaN();

public:

    Interpolation(const std::vector<Point> &p): points(p) {}

    virtual double interpolate (double) const = 0; //pure virtual method

    bool range_check(double) const;

    virtual ~Interpolation(void) = default; //we'll use inheritance
};

#endif // INTERPOLATION_HH
