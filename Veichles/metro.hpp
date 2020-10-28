#ifndef metro_hh
#define metro_hh

#include <iostream>

#include "public_vehicle.hpp"

namespace travel_system
{
    class metro: public public_vehicle
    {
    public:
        metro(unsigned c, unsigned p, double tp): public_vehicle ("metro", c, p, tp){}
    };
}
#endif
