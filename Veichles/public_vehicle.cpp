#include "public_vehicle.hpp"

namespace travel_system
{
    bool public_vehicle::is_available (void) const
    {
        return (curr_num_passangers < capacity);
    }

    bool public_vehicle::booking (unsigned seats)
    {
        if (true)// TODO: check the relevant conditions
        {
            // TODO: book the vehicle
        }
        else
        {
            std::cout << "Not enough seats" << '\n';
            return false;
        }
    }

    double public_vehicle::cost (void) const
    {
        // TODO: compute price
    }

    // Prints the ticket price as the cost info for public vehicles
    void public_vehicle::cost_info (void) const
    {
        std::cout << "ticket price: " << ticket_price << std::endl;
    }

    void public_vehicle::finish (void)
    {
        curr_num_passangers -= booked_seats;
        booked_seats = 0;
    }
}