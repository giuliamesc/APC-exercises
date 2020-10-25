#include <iostream>
#include "Complex.h"
#include "ComplexPolar.h"

int main() {
    Complex c1(5,2);
    Complex c2(6,3);
    Complex c3=c1;
    c3=c1+c2; //we have to overload the + operator
    //Complex c4=c2+5; //c4=5+c2; gives error because with Complex operator+(double) const; our expected first input is a Complex
    return 0;
}
