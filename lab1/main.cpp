#include "fun.h"
#include<iostream>

using namespace std;
using namespace fun;

int main()
{
    //z3

    int a, b;
    cout << "Input 2 numbers:" << endl;
    cin >> a >> b;
    int c, d;
    c = a;
    d = b;
    mod1(&a, &b);
    cout << "Pointer:" << endl;
    cout << a << ' ' << b << endl;
    mod2(c, d);
    cout << "Link:" << endl;
    cout << c << ' ' << d << endl;

    //z6

    float v1, v2;
    cout << "Enter a fractional number:" << endl;
    cin >> v1;
    v2 = v1;
    rounding1(&v1);
    cout << "Pointer:" << endl;
    cout << v1 << endl;
    rounding2(v2);
    cout << "Link:" << endl;
    cout << v2 << endl;

    //z11

    Complex comp;
    float real, image, n;
    cout << "Enter complex value and n like: real imag parts and n" << endl;
    cin >> comp.real >> comp.image >> n;
    cout << "Pointer:" << endl;
    comp1(&comp, &n);
    cout << comp.real << '+' << comp.image << 'i' << endl;
    cout << "Link:" << endl;
    comp2(comp, n);
    cout << comp.real << '+' << comp.image << 'i' << endl;
    //z14

    int i, j, arr[3][3], arr2[3][3];
    cout << "Input matrix:" << endl;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            cin >> arr[i][j];

    cout << "Your matrix:" << endl;
    for(i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            cout << arr[i][j] << ' ';
        cout << endl;
    }

    transp1(&arr[0][0], &arr2[0][0]);
    cout << "Pointer:" << endl;
    for(i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            cout << arr2[i][j] << ' ';
        cout << endl;
    }

    cout << "Link:" << endl;
    for(i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            cout << arr2[i][j] << ' ';
        cout << endl;
    }

    return 0;
}