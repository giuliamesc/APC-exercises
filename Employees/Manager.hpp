#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.hpp"
// TODO: is Employee the correct class to inherit from?
class Manager: public Employee {

protected:

    const double m_rate = 9.5;
    unsigned m_hours = 0;

public:

    Manager (const std::string& n, const std::string& sn, unsigned id):
            Employee(n, sn, id) {}

    double salary_cal (void) const override;
    
   void set_m_hours(unsigned n);

};

#endif /* MANAGER_H */
