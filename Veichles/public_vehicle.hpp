#ifndef public_vehicle_hh
#define public_vehicle_hh

#include <iostream>
#include <list>

#include "vehicle.hpp"

namespace travel_system
{
    class public_vehicle: public vehicle
    {
    public:
        void cost_info (void) const override;
        double cost (void) const override;
        bool booking (unsigned seats) override;
        void finish (void) override;
        bool is_available (void) const override;

        virtual ~public_vehicle (void){};

    protected:
        public_vehicle(const std::string& s, unsigned c, unsigned p, double tp):
                vehicle(s, c, p), ticket_price(tp) {}

        std::list<std::string> time_schedule;
        double ticket_price;
        unsigned booked_seats = 0; //the number of booked seats

    };
}
#endif
