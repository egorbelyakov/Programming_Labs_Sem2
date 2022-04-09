#include "steck.h"
#include <iostream>

using namespace std;

Steck::Steck(int t)
{
    m = new int[t];
    maxk = t;
    k = -1;
}

bool Steck::push(int t)
{
    if (maxk == k)
        return false;
    else {
        k++;
        m[k] = t;
        return true;
    }
}

void Steck::pop()
{
    if(k > -1) {
        k--;
    }
}

Steck::~Steck()
{
    delete[] m;
}

void Steck::show()
{
    int i = k;
    cout << "Stack:" << endl;
    while(i > - 1)
    {
        cout << m[i] << endl;
        i--;
    }
    cout << endl;
}

void operator << (Steck& steck, int element)
{
    steck.push(element);
}

void operator >> (Steck& steck, int& n)
{
    steck.pop();
}
