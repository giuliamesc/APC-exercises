#ifndef limousine_hh
#define limousine_hh

#include <string>
#include <iostream>

#include "private_vehicle.hpp"

namespace travel_system
{
    class limousine: public private_vehicle
    {

        double driver_cost;
        double service_cost;

    public:
        limousine (const std::string& number, unsigned c, double cost, double d_cost, double s_cost):
                private_vehicle("limousine", c, number, cost), driver_cost(d_cost), service_cost(s_cost){}

        double cost (void) const override;
        void cost_info (void) const override;

    };
}
#endif
