#include "complexe.h"
#include <math.h>
#include <complex.h>

Complex::Complex() {}

Complex::Complex(double r) {
    re = r;
    im = 0;
}

Complex::Complex(double r, double i) {
    re = r;
    im = i;
}

Complex::Complex(const Complex &c) {
    re = c.re;
    im = c.im;
}

Complex Complex::operator + (const Complex &c)
{
    return Complex(re + c.re, im + c.im);
}

Complex Complex::operator * (const Complex &c)
{
    return Complex(re * c.re - im  * c.im, im * c.re + re * c.im);
}

Complex::operator double() const
{
    return sqrt(re * re + im * im);
}

void Complex::operator * (double val)
{
    im *= val;
    re *= val;
}
/*ostream& operator << (ostream &out, const Complex &c)
{
    out << "(" << c.re << ", " << c.im << ")";
    return out;
}

istream& operator >> (istream &in, Complex &c)
{
    in >> c.re >> c.im;
    return in;
}
*/
