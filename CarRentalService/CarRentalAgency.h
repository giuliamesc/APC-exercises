#ifndef CAR_RENTAL_AGENCY_HPP
#define CAR_RENTAL_AGENCY_HPP
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include "Vehicle.h"
class CarRentalAgency
{
private:
//The name of the agency
    const std::string name;
//The address of the agency
    const std::string address;
//The vehicles available for renting (i.e., not rented at the moment) - key is the identifier of the vehicle
    std::unordered_map<size_t, VehiclePtr> vehicles;
//Add a vehicle to the available ones
    void AddVehicle(const VehiclePtr vehicle){
        vehicle->SetAvailable(true);
        vehicles.insert(std::make_pair(vehicle->CGetIdentifier(),vehicle));
    }
//Rent a vehicle
    const VehiclePtr RentVehicle(Vehicle::Type type){
        for(const auto vehicle:vehicles){
            if (vehicle.second->IsAvailable() && vehicle.second->CGetVehicleType()== type){
                VehiclePtr ret=vehicle.second;
                vehicle.second->SetAvailable(0);
                vehicles.erase(vehicle.first);

                return ret;
            }
        }
    }

    friend class CarRentalCompany;
public:
//Constructor
    CarRentalAgency(const std::string & n, const std::string & add) : name(n),address(add) {}
};
#endif
