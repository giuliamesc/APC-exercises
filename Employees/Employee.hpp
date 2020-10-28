#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

class Employee {

protected:

    std::string name;
    std::string surname;
    unsigned id;
    const double pay_rate = 7.5;
    unsigned work_hours;

public:

    Employee (const std::string& n, const std::string& sn, unsigned id):
            name(n), surname(sn), id(id) {}

    virtual double salary_cal(void) const = 0;

    void set_work_hours (unsigned n);

    void print (void) const
    {
        std::cout << name << " " << surname << " " << id << std::endl;
    }

};

#endif /* EMPLOYEE_H */
