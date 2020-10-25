//
// Created by giuli on 25/10/2020.
//

#ifndef POLIROOTS_FUNCTION_H
#define POLIROOTS_FUNCTION_H

#include <iostream>
#include <vector>
#include "Rootfinding.h"

class Function {
private:
    const std::vector<double> coefficients;

public:
    Function(const std::vector<double> &coefficients) : coefficients(coefficients) {}
    double eval(double x) const;
    Function derive() const;
    void print_f() const;

};


#endif //POLIROOTS_FUNCTION_H
