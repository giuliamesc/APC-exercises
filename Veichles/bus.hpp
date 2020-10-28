#ifndef bus_hh
#define bus_hh

#include <iostream>
#include <list>

#include "public_vehicle.hpp"

namespace travel_system
{
    class bus: public public_vehicle
    {
    public:
        bus(unsigned c, unsigned p, double tp): public_vehicle ("bus" , c, p, tp){}
    };
}
#endif