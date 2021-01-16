#ifndef CAR_RENTAL_COMPANY_HPP
#define CAR_RENTAL_COMPANY_HPP
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "Vehicle.h"
#include "CarRentalAgency.h"
class CarRentalAgency;
typedef std::shared_ptr<CarRentalAgency> CarRentalAgencyPtr;
class CarRentalCompany
{
private:
//The vehicles owned by the company
    std::vector<VehiclePtr> vehicles;
//The agencies of the company - key is the name of the agency
    std::unordered_map<std::string, CarRentalAgencyPtr> agencies;
public:
//Release the vehicle at the end of the renting
    void ReleaseVehicle(const std::string & agency_name, const VehiclePtr vehicle){
    CarRentalAgencyPtr my_agency=agencies.at(agency_name);
    my_agency->AddVehicle(vehicle);
}
//Rent a vehichle
    const VehiclePtr RentVehicle(const std::string & agency_name, Vehicle::Type type){
        CarRentalAgencyPtr my_agency=agencies.at(agency_name);
        my_agency->RentVehicle(type);
}

//Add a new agency
    void AddNewAgency(const std::string & agency_name, const std::string & address){
    CarRentalAgencyPtr pt_ag = std::make_shared<CarRentalAgency>(agency_name, address);
    agencies.insert(std::make_pair(agency_name,pt_ag));
}

//Add a new car - agency is its initial position
    void AddNewCar(const std::string & plate, unsigned int max_passengers, const std::string & agency){
    auto new_car = std::make_shared<Car>(plate, max_passengers, vehicles.size());
    agencies.at(agency)->AddVehicle(new_car);

    vehicles.push_back(new_car);
}
//Get all available vehicles
    const std::unordered_set<VehiclePtr> CGetAvailableVehicles() const{
    std::unordered_set<VehiclePtr> ret;
    for(const auto vehicle : vehicles){
        if(vehicle->IsAvailable())
            ret.insert(vehicle);
    }
    return ret;

}
};
#endif
