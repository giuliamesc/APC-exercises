#ifndef MANAGER_H
#define MANAGER_H

#include "Developer.hpp"
class Manager: public Developer {

protected:

    const double m_rate = 9.5;
    unsigned m_hours = 0;

public:

    Manager (const std::string& n, const std::string& sn, unsigned id):
            Developer(n, sn, id) {}

    double salary_cal (void) const override;

    void set_m_hours(unsigned n);

};

#endif /* MANAGER_H */
