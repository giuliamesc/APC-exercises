//
// Created by giuli on 25/10/2020.
//

#ifndef POLIROOTS_METHODS_H
#define POLIROOTS_METHODS_H

#include <iostream>
#include "Function.h"
#include "Rootfinding.h"
#include <cmath>
#include <limits>
#include <cstdlib>

class Methods {

private:
    Function fun;
    bool converged(double increment, double residual, double tol, const checkT& check) const;

public:
    Methods(Function &f) : fun(f) {}
    double bisection(double a, double b, double tol, unsigned maxit, const checkT& check, unsigned& nit) const;
    double newton(double xp, double tol, unsigned maxit, const checkT& check, unsigned& nit) const ;
    double robust(double a, double b, double tol, double cfratio, unsigned maxit, const checkT& check, unsigned& nit_coarse, unsigned& nit_fine) const;
};


#endif //POLIROOTS_METHODS_H
