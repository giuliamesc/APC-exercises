#include "Developer.hpp"

double Developer::salary_cal (void) const
{
    return wsh_rate*wsh_hours+pay_rate*(work_hours-wsh_hours);
}

void Developer::set_wsh_hours(unsigned n)
{
    wsh_hours = n;
}