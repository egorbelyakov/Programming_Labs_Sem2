#include <iostream>
#include "complexe.h"
#include "steck.h"

using namespace std;

int main()
{
    //Stack

    int n;
    Steck steck(3);
    steck << 1;
    steck << 3;
    steck >> n;
    steck << 4;
    steck << 5;
    steck.show();

    //Complex

    Complex a(5,2);
    Complex b(1, 3);
    Complex c = a * b;
    Complex d = a + b;

    cout << "Complex a = " << '(' << a.re << ", " << a.im << ')' << endl;
    cout << "Complex b = " << '(' << b.re << ", " << b.im << ')' << endl;

    cout << "a * b = " << '(' << c.re << ", " << c.im << ')' << endl;
    cout << "a + b = " << '(' << d.re << ", " << d.im << ')' << endl;
    float lenght = double(a);
    cout << "lenght = " << lenght << endl;
    double q = 3.5;
    a * q;
    cout << "a * 3.5 = " << '(' << a.re << ", " << a.im << ')' << endl;
    return 0;
}
