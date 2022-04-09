#include "Steck.h"
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
        if(cnt < maxk) {
            if (maxk == k)
                return false;
            else {
                k++;
                m[k] = t;
                cnt++;
                return true;
            }
        }
    }

    void Steck::pop()
    {
        if(k > -1) {
            k--;
            cnt--;
        }
    }

    int Steck::top()
    {
        return m[k];
    }

    int Steck::caunt()
    {
        return k + 1;
    }

    bool Steck::isNotEmpty()
    {
        return (k > -1);
    }

    void Steck::show()
    {
        int i = k;
        while(i > - 1)
        {
            cout << m[i] << endl;
            i--;
        }
    }

    Steck::~Steck()
    {
        delete[] m;
    }

    int Menu::showMenu()
    {
        cout << "Commands:\n push x - add element to stack\n pop - remove element from stack\n top - top item view\n show - output on display\n isEmpty - check for emptiness\n count - number of elements\n end - close the program" << endl;
        cout << "\nEnter stack size" << endl;
        cin >> sizee;
        Steck s(sizee);
        cout << "Enter commands" << endl;

        while(true)
        {
            cin >> command;

            if(command == "push")
            {
                cin >> t;
                s.push(t);
                continue;
            }

            if(command == "pop")
            {
                s.pop();
                continue;
            }

            if (command == "top")
            {
                if(s.isNotEmpty()){
                    cout << s.top() << endl;
                    continue;
                }
                else {
                    cout << "stack is empty" << endl;
                    continue;
                }
            }

            if(command == "count")
            {
                cout << s.caunt() << endl;
                continue;
            }

            if(command == "isEmpty")
            {
                if(!(s.isNotEmpty())) {
                    cout << "stack is empty" << endl;
                    continue;
                }
                else {
                    cout << "stack is not empty" << endl;
                    continue;
                }
            }

            if(command == "show")
            {
                s.show();
                continue;
            }

            if (command == "end")
            {
                return 0;
            }
        }
    }
