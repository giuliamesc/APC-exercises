#include "Interpolation.h"

bool Interpolation::range_check(double x) const
{
    bool inf = x < points.front().get_x(); //comparison with points[0]
    bool sup = x > points.back().get_x();
    return ! (inf || sup);
}
