//
// Created by giuli on 14/10/2020.
//

#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H


class Complex {
private:
    double m_real;
    double m_img;

public:
    // constructor
    Complex(double real, double img): m_real(real), m_img(img){};

    // getters
    double get_img() const;
    double get_real() const;
    double get_modulus() const;
    double get_phase() const;

    //setters
    void set_real(double);
    void set_img(double);
    void set_modulus(double);
    void set_phase(double);

    //operators
    Complex operator+(const Complex &rhs) const;
    Complex operator-(const Complex &rhs) const;
    Complex operator*(const Complex &rhs) const;
    Complex operator/(const Complex &rhs) const;
};


#endif //COMPLEX_COMPLEX_H
