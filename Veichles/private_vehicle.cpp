#include "private_vehicle.hpp"

namespace travel_system
{
    void private_vehicle::cost_info (void) const
    {
        std::cout << "cost per km: " << cost_per_km << '\n';
    }

    double private_vehicle::cost (void) const
    {
        return (current_km_counter - base_km_counter) * cost_per_km;
    }

    bool private_vehicle::is_available (void) const
    {
        return available;
    }

    // Adds a unit of km to the kilometer counter of the vehicle
    void private_vehicle::add_km (void)
    {
        current_km_counter++;
    }

    bool private_vehicle::booking(unsigned seats)
    {
        if ( available && curr_num_passangers+seats <= capacity)
        {
            curr_num_passangers+=seats;
            available = false;
            std::cout << "booking successfull" << std::endl;
            return true;
        }
        else
        {
            std::cout << "booking not possible" << '\n';
            return false;
        }
    }

    void private_vehicle::finish (void)
    {
        available = true;
        curr_num_passangers = 0;
    }
}
