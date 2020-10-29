#ifndef LINEAR_INTERPOLATION_HH
#define LINEAR_INTERPOLATION_HH

#include <vector>

#include "Interpolation.h"

class LinearInterpolation: public Interpolation
{

public:
  LinearInterpolation (const std::vector<Point> &);

  virtual double interpolate (double) const override;

  virtual ~LinearInterpolation() = default;
};

#endif // LINEAR_INTERPOLATION_HH
