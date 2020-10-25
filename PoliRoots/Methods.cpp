//
// Created by giuli on 25/10/2020.
//

#include "Methods.h"
#include "Function.h"

bool Methods::converged(double increment, double residual, double tol, const checkT& check) const{
    switch (check) {
        case INCREMENT:
        return (increment < tol);
        case RESIDUAL:
        return (residual < tol);
        case BOTH:
        return ((increment < tol) && (residual < tol));
        default:
            return false;
    }
}

double Methods::bisection(double a, double b, double tol, unsigned maxit, const checkT& check, unsigned& nit) const{
    double u = fun.eval(a);
    double l = b-a;
    double r;
    double c = a+l;

    nit = 0;
    r=fun.eval(c);

    if(u*fun.eval(b)>=0.0){
        std::cout<<"Error Function has same sign at both endpoints"<<std::endl;
        return - std::numeric_limits<double>::infinity();
    }

    while(!(converged(fabs(l),fabs(r),tol,check)) && (nit <= maxit))
    {
        (u*r <0.)?(b=c):(a=c,u=r);
        l*=0.5;
        c=a+l;
        r=fun.eval(c);
        ++nit;
    }
    return c;
}

double Methods::newton(double xp, double tol, unsigned maxit, const checkT& check, unsigned& nit) const{

double v=fun.eval(xp);
double xnew;

nit=0;
for(unsigned k = 1; k<= maxit; ++k,++nit){
    double derv = fun.derive().eval(xp);
    if(!derv) {
        std::cerr << "ERROR: Division by 0 occurred in Newton algorithm" << std::endl;
        exit(1);
        }
    xnew = xp-v/derv;
    v=fun.eval(xnew);
    if(converged(fabs(xnew-xp), fabs(v), tol, check)) break;
    xp = xnew;
    }
return xnew;
}

double Methods::robust(double a, double b, double tol, double cfratio, unsigned maxit, const checkT& check, unsigned& nit_coarse, unsigned& nit_fine) const{
double tol_bis = cfratio*tol;
double x_bis = bisection(a,b,tol_bis,maxit,check,nit_coarse);

return newton(x_bis,tol,maxit,check,nit_fine);
}