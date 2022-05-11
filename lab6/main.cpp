#include <iostream>
#include "fun.h"
#include <vector>

using namespace std;

bool negative(int a)
{
    return a < 0;
}

bool even(int a)
{
    return a % 2 == 0;
}

bool sortpred(int a, int b)
{
    return a < b;
}

int main()
{
    vector<int> v = {1, 5, 3, 3, 2};
    cout << "For int vector" << endl;
    if(none_of(v.begin(), v.end(), negative))
        cout << "Not found" << endl;
    else
        cout << "Found" << endl;

    if(none_of(v.begin(), v.end(), even))
        cout << "Not found" << endl;
    else
        cout << "Found" << endl;

    if(is_sorted(v.begin(), v.end(), sortpred))
        cout << "Sorted" << endl;
    else
        cout << "Not sorted" << endl;

    cout << find_not(v.begin(), v.end(), 1) << endl;
    cout << endl;

    vector<double> vd = {1.1, 1.1, 1.1, 1.1, 1.1};
    cout << "For double vector" << endl;
    if(none_of(vd.begin(), vd.end(), negative))
        cout << "Not found" << endl;
    else
        cout << "Found" << endl;

    if(is_sorted(vd.begin(), vd.end(), sortpred))
        cout << "Sorted" << endl;
    else
        cout << "Not sorted" << endl;

    cout << find_not(vd.begin(), vd.end(), 1.1) << endl;

    return 0;
}
