#include "taxi.hpp"

namespace travel_system
{
    double taxi::cost (void) const
    {
        return private_vehicle::cost() + driver_cost;
    }

    void taxi::cost_info (void) const
    {
        private_vehicle::cost_info();
        std::cout << "driver cost: " << driver_cost <<std::endl;
    }
}