#ifndef STECK_H
#define STECK_H

#include <string.h>
#include <iostream>

using namespace std;

class Steck
{
private:
    int *m, k, maxk;
    int  cnt = 0;

public:
    Steck(int t);
    ~Steck();
    bool push(int t);
    void pop();
    int top();
    int caunt();
    void show();
    bool isNotEmpty();
};

class Menu
{
private:
    int i, t;
    int sizee;
    string command;

public:
    int showMenu();
};

#endif // STECK_H
