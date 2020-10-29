#ifndef NEAREST_NEIGHBOR_INTERPOLATION_HH
#define NEAREST_NEIGHBOR_INTERPOLATION_HH

#include <vector>

#include "Interpolation.h"

/* TO BE COMPLETED */

class NearestNeighborInterpolation : public Interpolation
{
public:
  NearestNeighborInterpolation (const std::vector<Point> &);

  virtual double interpolate (double) const override;

    virtual ~NearestNeighborInterpolation() = default;
};

#endif // NEAREST_NEIGHBOR_INTERPOLATION_HH
