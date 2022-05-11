#include "fun.h"

using namespace std;

int main()
{
    //SWAP

    int in1 = 3, in2 = 8;
    double d1 = 2.7, d2 = 9.1;
    char c1 = 'a', c2 = 'b';
    swap_(in1, in2);
    swap_(d1, d2);
    swap_(c1, c2);
    swap_<double>(1.23, 5);
    cout << endl;

    //QUEUE

    MyQueue<2, int> q;
    q.Pop_();
    q.Push_(1);
    q.Push_(2);
    q.Push_(3);

    return 0;
}
