#ifndef STECK_H
#define STECK_H

#include<iostream>

using namespace std;

class Steck
{
private:
    int *m, k, maxk;

public:
    Steck(int t);
    ~Steck();
    bool push(int t);
    void pop();
    void show();
};

void operator << (Steck& steck, int element);
void operator >> (Steck& steck, int& n);

#endif //STECK_H