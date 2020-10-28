#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Employee.hpp"

class Developer: public Employee {

protected:

    // TODO: we need to differentiate work hours from workshop hours
    // both activities will have corresponding (constant) pay rate, and the
    // user needs to set hours for both activities independently

public:

    Developer (const std::string& n, const std::string& sn, unsigned id):
            Employee(n, sn, id) {}

    double salary_cal (void) const override;

};

#endif /* DEVELOPER_H */
