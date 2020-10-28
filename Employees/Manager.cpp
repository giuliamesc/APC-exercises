#include "Manager.hpp"

double Manager::salary_cal (void) const
{
    return (work_hours - wsh_hours - m_hours)*pay_rate+wsh_rate*wsh_hours+m_hours*m_rate;
}

void Manager::set_m_hours(unsigned int n)
{
    m_hours=n;
}
