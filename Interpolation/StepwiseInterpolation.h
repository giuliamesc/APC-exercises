#ifndef STEPWISE_INTERPOLATION_HH
#define STEPWISE_INTERPOLATION_HH

#include <vector>

#include "Interpolation.h"

/* TO BE COMPLETED */

class StepwiseInterpolation : public Interpolation
{
public:
  StepwiseInterpolation (const std::vector<Point> &);

  virtual double interpolate (double) const override;

  virtual ~StepwiseInterpolation() = default;
};

#endif // STEPWISE_INTERPOLATION_HH
