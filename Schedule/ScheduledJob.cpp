//
// Created by Federica Filippini on 16/11/2020.
//

#include "ScheduledJob.h"


void ScheduledJob::adjust_start_time(){
    if(start_time<ptr->get_submission_time())
        start_time=ptr->get_submission_time();
}

void ScheduledJob::set_start_time (Job::time_instant  st_time){
    start_time=st_time;
    adjust_start_time();
}


Job::time_instant ScheduledJob::get_end_time() const
{
    return start_time + ptr->get_execution_time();
}

Job::time_instant ScheduledJob::get_start_time() const
{
    return start_time;
}

Job::time_instant ScheduledJob::get_deadline() const
{
    return ptr->get_deadline();
}

Job::time_instant ScheduledJob::get_execution_time() const
{
    return ptr->get_execution_time();
}

Job::time_instant ScheduledJob::get_submission_time() const
{
    return ptr->get_submission_time();
}


double ScheduledJob::evaluate() const{
    double tardiness=0.0;
    if(get_end_time()>=ptr->get_deadline()){
        tardiness=((double) get_end_time()-ptr->get_deadline())*ptr->get_weight();
    }
    return tardiness;
}


void ScheduledJob::print() const
{
    ptr->print();
    std::cout << " start_time " << start_time
              << " end_time " << get_end_time();
}
