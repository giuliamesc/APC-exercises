#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.hpp"
// TODO: is Employee the correct class to inherit from?
class Manager: public Employee {

protected:

    // TODO: we need to differentiate work hours from workshop or mission hours
    // each activity will have corresponding (constant) pay rate, and the user
    // needs to set hours for each activity independently

public:

    Manager (const std::string& n, const std::string& sn, unsigned id):
            Employee(n, sn, id) {}

    double salary_cal (void) const override;

};

#endif /* MANAGER_H */
