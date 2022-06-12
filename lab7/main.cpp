#include <iostream>
#include <algorithm>
#include "buffer.h"

using namespace std;

int main()
{
    CCircleBuffer<int> buffer(4);

    buffer.push_front(12);
    buffer.push_front(13);
    buffer.push_front(17);
    buffer.push_front(199);
    buffer.push_front(201);
    buffer.push_front(1);
    buffer.resize(5);
    buffer.push_back(2);
    buffer.push_back(4);
    buffer.push_back(5);
    buffer.push_back(6);
    buffer.push_back(10);
    buffer.push_back(11);

    CCircleBuffer<int>::iterator b = CCircleBuffer<int>::iterator(buffer.begin());
    CCircleBuffer<int>::iterator e = CCircleBuffer<int>::iterator(buffer.end());
    cout << *b << endl;
    for(auto i = buffer.begin(); i != buffer.end(); i++)
        cout << buffer[i] << " ";
    cout << endl;

    CCircleBuffer<int>::iterator result = find(b, e, 4);
    cout << *result;
    return 0;
}