//
// Created by giuli on 16/10/2020.
//

#ifndef COMPLEX_COMPLEXPOLAR_H
#define COMPLEX_COMPLEXPOLAR_H


class ComplexPolar {
private:
    double m_mod;
    double m_ph;

public:
    // constructor
    ComplexPolar(double mod, double ph): m_mod(mod), m_ph(ph){};

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
    ComplexPolar operator+(const ComplexPolar &rhs) const;
    ComplexPolar operator-(const ComplexPolar &rhs) const;
    ComplexPolar operator*(const ComplexPolar &rhs) const;
    ComplexPolar operator/(const ComplexPolar &rhs) const;
};


#endif //COMPLEX_COMPLEXPOLAR_H
