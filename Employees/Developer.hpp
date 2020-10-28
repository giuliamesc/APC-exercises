#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Employee.hpp"

class Developer: public Employee {

protected:

const double wsh_rate = 8.0;
unsigned wsh_hours = 0;

public:

    Developer (const std::string& n, const std::string& sn, unsigned id):
            Employee(n, sn, id) {}

    double salary_cal (void) const override;
    
    void set_wsh_hours(double n);

};

#endif /* DEVELOPER_H */
