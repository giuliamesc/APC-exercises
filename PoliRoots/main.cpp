#include <iostream>
#include "Function.h"
#include "Methods.h"

// MAIN FUNCTION

int main() {

unsigned nit_bis = 10;
unsigned nit_newt = 20;
std::vector<double> coef = {1,-2.5,3,-7,9,-11};
Function f(coef);
f.print_f();

Methods m(f);

std::cout << std::numeric_limits<double>::infinity() << std::endl;
std::cout << "Bisection"<< std::endl;
std::cout << m.bisection(0., 1., 1e-8, 100, INCREMENT, nit_bis);
std::cout << '\t' << nit_bis << std::endl;

std::cout << "Newton"<< std::endl;
std::cout << m.newton(.1, 1e-8, 100, INCREMENT, nit_newt);
std::cout << '\t' << nit_newt << std::endl;

std::cout << "Robust"<< std::endl;
std::cout << m.robust(0., 1., 1e-8, 1e4, 100, INCREMENT, nit_bis, nit_newt);
std::cout << '\t' << nit_bis << " " << nit_newt << std::endl;

return 0;
}
