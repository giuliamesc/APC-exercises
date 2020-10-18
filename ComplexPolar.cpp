//
// Created by giuli on 16/10/2020.
//

#include "ComplexPolar.h"
#include <math.h>

double ComplexPolar::get_modulus() const {
    return m_mod;
}

double ComplexPolar::get_phase() const {
    return m_ph;
}

double ComplexPolar::get_real() const {
    return m_mod*cos(m_ph);
}

double ComplexPolar::get_img() const {
    return m_mod*sin(m_ph);
}

void ComplexPolar::set_modulus(double mod) {
    m_mod=mod;
}

void ComplexPolar::set_phase(double phase) {
    m_ph=phase;
}

void ComplexPolar::set_real(double x) {
    double y=get_img();
    m_mod=sqrt(x*x+y*y);
    double sign = y >= 0 ? 1.0f: -1.0f; //ternary operator: it's like an if-else expression
    if(x != 0) {
        double res = atan(y/x);
        if(x < 0 && y != 0)
            res+=sign*M_PI;
        m_ph = res;
    }
    else {
        m_ph = sign * (M_PI / 2.0);
    }
}

void ComplexPolar::set_img(double y) {
    double x=get_real();
    m_mod=sqrt(x*x+y*y);
    double sign = y >= 0 ? 1.0f: -1.0f; //ternary operator: it's like an if-else expression
    if(x != 0) {
        double res = atan(y/x);
        if(x < 0 && y != 0)
            res+=sign*M_PI;
        m_ph = res;
    }
    else {
        m_ph = sign * (M_PI / 2.0);
    }
}


ComplexPolar ComplexPolar::operator+(const ComplexPolar &rhs) const {
   double real=get_real()+rhs.get_real();
   double img=get_img()+rhs.get_img();
   ComplexPolar res(0,0);
   res.set_real(real);
   res.set_img(img);
}

ComplexPolar ComplexPolar::operator-(const ComplexPolar &rhs) const {
    double real=get_real()-rhs.get_real();
    double img=get_img()-rhs.get_img();
    ComplexPolar res(0,0);
    res.set_real(real);
    res.set_img(img);
}

ComplexPolar ComplexPolar::operator*(const ComplexPolar &rhs) const {
    return ComplexPolar(m_mod*rhs.m_mod,m_ph+rhs.m_ph);
}

ComplexPolar ComplexPolar::operator/(const ComplexPolar &rhs) const {
    return ComplexPolar(m_mod/rhs.m_mod,m_ph-rhs.m_ph);
}
