#ifndef limousine_hh
#define limousine_hh

#include <string>
#include <iostream>

#include "private_vehicle.hpp"

namespace travel_system
{
    class limousine: public private_vehicle
    {

    public:
        limousine (const std::string& number, unsigned c, double cost):
                private_vehicle("limousine", c, number, cost){}

        double cost (void) const override;
        void cost_info (void) const override;

    };
}
#endif
