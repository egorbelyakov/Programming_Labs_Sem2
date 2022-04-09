#ifndef COMPLEXE_H
#define COMPLEXE_H

#include <iostream>
#include <complex.h>

using namespace std;

class Complex {
private:
    complex<double> val;
public:
    double re, im;
    Complex();
    Complex(double r);
    Complex(double r, double i);
    Complex(const Complex &c);
    Complex(const Complex &c, double n);
    Complex operator * (const Complex &c);
    Complex operator + (const Complex &c);
    operator double() const;
    void operator * (double val);
    /*friend ostream & operator << (ostream &, const Complex &);
    friend istream & operator >> (istream &, Complex &);*/
};

#endif //COMPLEXE_H