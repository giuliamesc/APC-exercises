#include "NearestNeighborInterpolation.h"

/* TO BE COMPLETED */

NearestNeighborInterpolation::NearestNeighborInterpolation (const std::vector<Point> & points) :
Interpolation(points) {}

double
NearestNeighborInterpolation::interpolate (double x) const
{
    double result = err_val;

    if(range_check(x))
    {
        std::vector<Point>::const_iterator previous = points.cbegin();
        std::vector<Point>::const_iterator current = previous + 1;

        while(current != points.cend() && current->get_x() < x)
        {
            ++current;
            ++previous;
        }

        if(current != points.cend())
        {
            const double first_distance = x - previous->get_x();
            const double second_distance = current->get_x() - x;
            const bool first_closest = second_distance > first_distance;
            result = first_closest ? previous->get_y() : current->get_y();

        }

    }

    return result;
}
