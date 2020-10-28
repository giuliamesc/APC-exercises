#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "vehicle.hpp"
#include "public_vehicle.hpp"
#include "private_vehicle.hpp"
#include "car.hpp"
#include "taxi.hpp"
#include "limousine.hpp"
#include "shuttle.hpp"
#include "metro.hpp"
#include "bus.hpp"

typedef std::vector<travel_system::vehicle*> vehicles_vector; //shorter alias
std::vector<travel_system::vehicle*> private_vehicles; //stores private vehicles
std::vector<travel_system::vehicle*> public_vehicles; //stores public vehicles

/**
  Prints the cost info from all vehicles in the vector
  */
void
print_cost_info(vehicles_vector vehicles, std::istream &is){
    int count = 0;
    for(travel_system::vehicle *v: vehicles)
    {
        std::cout <<
                  "choice " << count <<
                  " -> type: " << v->get_identifier() << " ";
        v->cost_info();
        count++;
    }
}

/**
  Allows the user to attempt to book one vehicle among those in the vector parameter
  after reading the requested number of seats.
Returns: the index of the booked vehicle in the vector or -1 if booking failed
*/
int
book_vehicle(vehicles_vector vehicles, std::istream &is){
    //show the options to the traveller
    int count = 0;
    int num = 0;

    print_cost_info(vehicles, is);
    std::cout << "pick your choice or -1 for choosing another type of vehicle" << '\n';
    if(is >> count && count >= 0){
        std::cout << "enter the number of people" << '\n';
        is >> num;
        is.ignore(); //ignores the \n
        //calling the booking function from proper class through dynamic binding
        return vehicles[count]->booking(num) ? count : -1;
    }
    else
        return -1;
}

void read_from_stream (std::istream &is){

    //interacting with the traveller to get his/her choice
    std::string line;
    while(line != "q"){
        std::cout << "please choose your preference (private or public) or 'q' to quit" << '\n';
        getline(is, line);
        if (line == "private"){
            int vehicle_index = book_vehicle(private_vehicles, is);
            if(vehicle_index != -1){
                std::cout << "you have successfully booked a private vehicle" << std::endl;

                // TODO: iterate X times calling the add_km() method, print the
                // total cost and then call finish()

                break;
            }
        }
        else if(line == "public"){
            int vehicle_index = book_vehicle(public_vehicles, is);
            if(vehicle_index != -1){
                std::cout << "you have successfully booked a public vehicle" << std::endl;
                std::cout << "total cost: " << public_vehicles[vehicle_index]-> cost() << std::endl;
                public_vehicles[vehicle_index]-> finish();
                break;
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    //create some vehicles
    travel_system::car c1 ("AB08609", 5, 0.35, "sedan");
    travel_system::car c2 ("AB08610", 2, 0.20, "smart");
    travel_system::taxi t1 ("AB08610", 4, 1.00, 2.00);
    travel_system::taxi t2 ("AB08611", 5, 1.00, 2.00);
    travel_system::limousine l1 ("AB08610", 10, 5.00, 50.0, 100);
    travel_system::limousine l2 ("AB08611", 8, 4.00, 70.0, 120);
    travel_system::shuttle sh1(10, 0, 15);
    travel_system::bus b1(40, 20, 3);//20 seats already occupied
    travel_system::metro m1(200, 50, 5);//50 seats already occupied

    //add them to the availability vectors
    private_vehicles.push_back(&c1);
    private_vehicles.push_back(&c2);
    //TODO: add the other vehicle objects to their respective vectors

    //use this for reading from console
    read_from_stream(std::cin);

    return 0;
}
