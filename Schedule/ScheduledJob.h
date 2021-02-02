//
// Created by Federica Filippini on 16/11/2020.
//

#ifndef SCHEDULEEVALUATION_SCHEDULEDJOB_H
#define SCHEDULEEVALUATION_SCHEDULEDJOB_H

#include <memory>

#include "Job.h"

class ScheduledJob {

private:
    std::shared_ptr<Job> ptr;
    Job::time_instant start_time;

    void adjust_start_time();

public:
    ScheduledJob (const std::shared_ptr<Job>& j_ptr, Job::time_instant st_time)
            : ptr (j_ptr), start_time (st_time)
    {
        adjust_start_time();
    }

    ScheduledJob (Job j, Job::time_instant st_time)
            : ptr (std::make_shared<Job> (j)), start_time (st_time)
    {
        adjust_start_time();
    }

    explicit ScheduledJob (const std::shared_ptr<Job> & j_ptr)
            : ptr (j_ptr),
              start_time (j_ptr->get_submission_time())
    {}

    Job::time_instant get_end_time() const;
    Job::time_instant get_start_time() const;
    Job::time_instant get_deadline() const;
    Job::time_instant get_execution_time() const;
    Job::time_instant get_submission_time() const;

    void set_start_time (Job::time_instant  st_time);

    double evaluate() const;

    void print() const;
};


#endif //SCHEDULEEVALUATION_SCHEDULEDJOB_H
