#ifndef FLIGHT_HPP
#define FLIGHT_HPP
#include "Flyer.h"
#include <map>
#include <unordered_set>
class Flight {
private:
    std::map<FlyerRef, size_t> passengers;
    std::string id;
    size_t max_passengers;
    float distance;
public:
///Constructor
    Flight(const std::string & _id, const size_t _max_passengers, const float _distance) :
            id(_id),
            max_passengers(_max_passengers),
            distance(_distance)
    {}
    size_t AddPassenger(const FlyerRef traveller) {
    size_t ticket=passengers.size();
    passengers.insert(std::make_pair(traveller,ticket));
    return ticket;
    }

    std::unordered_set<FlyerRef> CloseFlight() {

    std::unordered_set<FlyerRef> ret;
    while(passengers.size()>max_passengers){
        ret.insert(passengers.begin()->first);
        passengers.erase(passengers.begin());
    }

    }
    void UpdateMiles() const {
    for(const auto & passenger : passengers){
        passenger.first->AddMiles(distance);
        }
    }

    size_t CGetETicket(const FlyerRef traveller) {
    std::map<FlyerRef,size_t>::const_iterator pos=passengers.find(traveller);
    if(pos!=passengers.cend())
        return pos->second;
    else
        return 0;
    }
};

#endif

bool operator< (const FlyerRef & first, const FlyerRef & second) {
    const auto first_miles = first->GetMiles();
    const auto second_miles = second->GetMiles();
    if(first_miles != second_miles)
        return first_miles < second_miles;
    return first->ff_id > second->ff_id;
}
