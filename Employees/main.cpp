#include "Secretary.hpp"
#include "Developer.hpp"
#include "Manager.hpp"

int main (void)
{
    Secretary S("Anna","Rossi",1);
    Developer D("Mauro","Neri",2);
    Manager M("Gaia","Bruni",3);

    std::cout << "Secretary:" << std::endl;
    S.print();
    S.set_work_hours(10);
    double Ssalary = S.salary_cal();
    std::cout << Ssalary << std::endl;

    std::cout << "Developer:" << std::endl;
    D.print();
    D.set_work_hours(10);
    D.set_wsh_hours(5);
    double Dsalary = D.salary_cal();
    std::cout << Dsalary << std::endl;

    std::cout << "Manager:" << std::endl;
    M.print();
    M.set_work_hours(10);
    M.set_wsh_hours(2);
    M.set_m_hours(3);
    double Msalary = M.salary_cal();
    std::cout << Msalary << std::endl;

    return 0;
}
