#ifndef private_vehicle_hh
#define private_vehicle_hh

#include <string>
#include <iostream>

#include "vehicle.hpp"

namespace travel_system
{
    class private_vehicle: public vehicle
    {
    public:
        virtual void cost_info (void) const override;
        virtual double cost (void) const override;
        bool booking (unsigned seats) override;
        void finish (void) override;
        void add_km (void);
        bool is_available (void) const override;

        virtual ~private_vehicle (void){};

    protected:
        private_vehicle (const std::string& s, unsigned c, std::string number, double cost):
                vehicle(s, c, 0), cost_per_km(cost), plate_number(number){}

        bool available = true;
        double current_km_counter = 0;
        double base_km_counter = 0;
        double const cost_per_km = 0;
        std::string plate_number;

    };
}
#endif
