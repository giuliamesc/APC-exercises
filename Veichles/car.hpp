#ifndef car_hh
#define car_hh

#include <string>
#include <iostream>

#include "private_vehicle.hpp"

namespace travel_system
{
    class car: public private_vehicle
    {
        std::string model;

    public:
        car (const std::string& number, unsigned c, double cost,
             const std::string& model_name):
                private_vehicle("car", c, number, cost), model(model_name){}
    };
}
#endif
