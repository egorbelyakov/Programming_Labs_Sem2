#ifndef FUN_H
#define FUN_H

#include <string>
#include <queue>
#include <iostream>

using namespace std;

template<typename Type>
void swap_(Type& a, Type& b)
{
    Type tmp = a;
    a = b;
    b = tmp;
}

class BaseExeption
{
protected:
    string text;
public:
    virtual string what_() = 0;
};

class QueueOverflow final: public BaseExeption
{
public:
    QueueOverflow()
    {
        text = "Error. Queue overflow";
    }

    QueueOverflow(string text_)
    {
        text = text_;
    }

    string what_()
    {
        return text;
    }
};

class RemoveFromEmptyQueue final: public BaseExeption
{
public:
    RemoveFromEmptyQueue()
    {
        text = "Error. Remove from empty queue";
    }

    RemoveFromEmptyQueue(string text_)
    {
        text = text_;
    }

    string what_()
    {
        return text;
    }
};

template <int N, class T>
class MyQueue
{
private:
    int size = 0;
    queue<T> q;
public:
    MyQueue()
    {
        size = 0;
    }

    void Push_(const T& element)
    {
        if (size + 1 > N)
            throw QueueOverflow();
        size++;
        q.push(element);
    }

    T Pop_()
    {
        if (size <= 0)
            throw RemoveFromEmptyQueue();
        size--;
        q.pop();
    }
};

#endif //FUN_H