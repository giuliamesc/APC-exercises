#include "taxi.hpp"

namespace travel_system
{
    double taxi::cost (void) const
    {
        return private_vehicle::cost();
    }

    void taxi::cost_info (void) const
    {
        private_vehicle::cost_info();
    }
}