//
// Created by giuli on 25/10/2020.
//

#include "Function.h"
#include <cmath>
#include <limits>
#include <cstdlib>

double Function::eval(double x) const{
    double res = 0;
    for(size_t i = 0; i<coefficients.size(); i++){
        res += pow(x,i)*coefficients[i];
    }
    return res;
}

Function Function::derive() const{
    std::vector<double> dcoeff={};
    for(size_t i = 1; i<coefficients.size(); i++){
        dcoeff.push_back(i*coefficients[i]);
    }
    if(dcoeff.empty())
        dcoeff.push_back(0);

    return Function(dcoeff);
}

void Function::print_f() const{
    for(size_t i = 0; i<coefficients.size(); i++){
        std::cout << "Coefficient of grade " << i << " is " << coefficients[i] << std::endl;
    }
}