#include "limousine.hpp"

namespace travel_system
{
    double limousine::cost (void) const
    {
        return private_vehicle::cost() +driver_cost +service_cost;
    }

    void limousine::cost_info (void) const
    {
        private_vehicle::cost_info();
        std::cout << "driver cost: " << driver_cost <<std::endl;
        std::cout << "service cost: " << service_cost <<std::endl;

    }
}