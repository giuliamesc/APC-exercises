#include "callcenter.h"

void CallCenter::RegisterTaxi(const std::string& license_id){
    Taxi new_taxi(license_id);
    taxis.insert(std::pair<std::string, Taxi>(license_id,new_taxi));

    available_taxis.insert(license_id);

    if(new_taxi.CGetPosition()==station)
        station_available_taxis.insert(new_taxi);
}

Taxi CallCenter::Call (const Place& source, const Place& destination){
    if(available_taxis.empty()){
        std::cerr << "NO TAXIS" << std::endl;
        return Taxi("nonexistent");
    }

    auto closest_taxi_id=*(available_taxis.begin());
    float closest_distance=ComputeDistance(taxis.at(closest_taxi_id).CGetPosition(), source);

    for(const std::string& taxi_id : available_taxis){
        float distance=ComputeDistance(taxis.at(taxi_id).CGetPosition(),source);
        if(distance<closest_distance){
            closest_distance=distance;
            closest_taxi_id=taxi_id;
        }
    }
    available_taxis.erase(closest_taxi_id);
    Taxi return_taxi = taxis.at(closest_taxi_id);

    if(return_taxi.CGetPosition()==station)
        station_available_taxis.erase(return_taxi);

    return_taxi.SetRide(source,destination);

    return return_taxi;
}

Taxi CallCenter::CallAtRailStation (const Place& Destination){
    if(not station_available_taxis.empty()){
        Taxi first_taxi=*(station_available_taxis.begin());
        taxis.at(first_taxi.CGetLicenseId()).SetRide(station,Destination);
        station_available_taxis.erase(first_taxi);
        available_taxis.erase(first_taxi.CGetLicenseId());
        return first_taxi;
    }
    else
        return Call(station,Destination);
}


void CallCenter::Arrived (const std::string& license_id){
    auto taxi=taxis.at(license_id);
    const auto last_ride=taxi.CGetLastRide();
    taxi.AddDistance(ComputeDistance(last_ride.first,last_ride.second));
    if(taxi.CGetPosition()==station){
        station_available_taxis.insert(taxi);
        available_taxis.insert(license_id);
    }
}
