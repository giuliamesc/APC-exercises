#ifndef shuttle_hh
#define shuttle_hh

#include <iostream>

#include "public_vehicle.hpp"

namespace travel_system
{
    class shuttle: public public_vehicle
    {
    public:
        shuttle(unsigned c, unsigned p, double tp): public_vehicle ("shuttle", c, p, tp){}
    };
}
#endif
