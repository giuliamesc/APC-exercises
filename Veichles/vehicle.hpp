#ifndef vehicle_hh
#define vehicle_hh

#include <string>

//Namespace used by all classes in the program
namespace travel_system
{
    //Base class of all vehicles
    class vehicle
    {
    public:

        virtual bool booking (unsigned seats) = 0;
        virtual void cost_info (void) const = 0;
        virtual double cost (void) const = 0;
        virtual bool is_available (void) const = 0;
        virtual void finish (void) = 0;
        std::string get_identifier (void) const;

        virtual ~vehicle (void){};

    protected:
        vehicle(const std::string& s, unsigned c, unsigned p):
                identifier(s), capacity(c), curr_num_passangers(p){} //base constructor

        std::string identifier; //the vehicle type (car, taxi, bus, etc)
        unsigned capacity = 0; //max number of passangers
        unsigned curr_num_passangers = 0; //current number of pasangers
    };
}
#endif
