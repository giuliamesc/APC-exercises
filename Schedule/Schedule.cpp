//
// Created by Federica Filippini on 16/11/2020.
//

#include "Schedule.h"

void Schedule::validate(){
    if(order.empty())
        return;
    order[0].set_start_time(order[0].get_submission_time());
    ScheduledJob pred = order[0];

    for(std::size_t i=1; i<order.size(); ++i){
        order[i].set_start_time(std::max(pred.get_end_time(),order[i].get_submission_time()));
        pred=order[i];
    }
}

void Schedule::add (const std::shared_ptr<Job> & j){
    if(order.empty())
        order.emplace_back(ScheduledJob(j,0));
    else {
        ScheduledJob new_job(j, order.back().get_end_time());
        order.push_back(new_job);
    }
}


Schedule::size_type Schedule::size() const
{
    return order.size();
}


double Schedule::evaluate() const{
    double sum=0.0;
    for(const ScheduledJob& j:order)
        sum+=j.evaluate();
    return sum;
}


void Schedule::print() const
{
    for (std::size_t i = 0; i < order.size(); ++i)
    {
        order[i].print();
        std::cout << std::endl;
    }
}
