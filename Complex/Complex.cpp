//
// Created by Giulia Mescolini on 14/10/2020.
//

#include "Complex.h"
#include <math.h>

/*Complex::Complex(double real, double img) {
    m_real=real;
    m_img=img;
} */

double Complex::get_real() const {
    return m_real;
}

double Complex::get_img() const {
    return m_img;
}

double Complex::get_modulus() const {
    return sqrt(m_img*m_img+m_real*m_real);
}

double Complex::get_phase() const {
    double sign = m_img >= 0 ? 1.0f: -1.0f; //ternary operator: it's like an if-else expression
    if(m_real != 0) {
        double res = atan(m_img/m_real);
        if(m_real < 0 && m_img != 0)
            res+=sign*M_PI;
        return res;
    }
    else {
        return sign * (M_PI / 2.0);
    }
}

void Complex::set_real(double real) {
    m_real=real;
}

void Complex::set_img(double img) {
    m_img=img;
}

void Complex::set_modulus(double mod) {
    double ph=get_phase();
    m_real=mod*cos(ph);
    m_img=mod*sin(ph);
}

void Complex::set_phase(double phase) {
    double mod=get_modulus();
    m_real=mod*cos(phase);
    m_img=mod*sin(phase);
}

Complex Complex::operator+(const Complex &rhs) const {
    Complex res(m_real+rhs.m_real, m_img+rhs.m_img);
    return res;
}

Complex Complex::operator-(const Complex &rhs) const {
    Complex res(m_real-rhs.m_real, m_img-rhs.m_img);
    return res;
}

Complex Complex::operator*(const Complex &rhs) const {
    double real = m_real*rhs.m_real-m_img*rhs.m_img;
    double img = m_img*rhs.m_real+m_real*rhs.m_img;
    return Complex(real,img);
}

Complex Complex::operator/(const Complex &rhs) const {
    double den =rhs.m_real*rhs.m_real+rhs.m_img*rhs.m_img;
    double r_num=m_real*rhs.m_real+m_img*rhs.m_img;
    double i_num=m_img*rhs.m_real-m_real*rhs.m_img;
    return Complex (r_num/den,i_num/den);
}
