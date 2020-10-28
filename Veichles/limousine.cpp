#include "limousine.hpp"

namespace travel_system
{
    double limousine::cost (void) const
    {
        return private_vehicle::cost();
    }

    void limousine::cost_info (void) const
    {
        private_vehicle::cost_info();
    }
}