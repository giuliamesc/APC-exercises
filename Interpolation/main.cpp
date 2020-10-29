#include <iostream>

#include "LinearInterpolation.h"
#include "StepwiseInterpolation.h"
#include "NearestNeighborInterpolation.h"

int
main (void)
{
    std::vector<Point> points {
    Point (1.0, 0.0),
      Point (2.0, 3.0),
      Point (3.0, 1.0),
      Point (4.0, 2.0),
      Point (5.0, 4.0)
      };

    double x = 2.5;
    //std::cin >> x;

    LinearInterpolation method1(points);
    std::cout << method1.interpolate(x) << "\n";

    StepwiseInterpolation method2(points);
    std::cout << method2.interpolate(x) << "\n";

    NearestNeighborInterpolation method3(points);
    std::cout << method3.interpolate(x) << "\n";



    return 0;
}
