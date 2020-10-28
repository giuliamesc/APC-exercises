#ifndef taxi_hh
#define taxi_hh

#include <string>
#include <iostream>

#include "private_vehicle.hpp"

namespace travel_system
{
    class taxi: public private_vehicle
    {
        // TODO: do we need some additional attributes?

    public:
        taxi (const std::string& number, unsigned c, double cost):
                private_vehicle("taxi", c, number, cost){}

        double cost (void) const override;
        void cost_info (void) const override;
    };
}
#endif
