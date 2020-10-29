#include "LinearInterpolation.h"

/* TO BE COMPLETED */

LinearInterpolation::LinearInterpolation (const std::vector<Point> & points):
    Interpolation(points) {} //delegated constructor

double
LinearInterpolation::interpolate (double x) const
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
            const double x1(previous->get_x()), x2(current->get_x());
            const double y1(previous->get_y()), y2(current->get_y());

            result = y1 + (y2-y1)*(x-x1) / (x2 - x1);
        }

    }

    return result;
}
