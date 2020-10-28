#ifndef taxi_hh
#define taxi_hh

#include <string>
#include <iostream>

#include "private_vehicle.hpp"

namespace travel_system
{
    class taxi: public private_vehicle
    {
        double driver_cost;

    public:
        taxi (const std::string& number, unsigned c, double cost, double d_cost):
                private_vehicle("taxi", c, number, cost), driver_cost(d_cost){}

        double cost (void) const override;
        void cost_info (void) const override;
    };
}
#endif
