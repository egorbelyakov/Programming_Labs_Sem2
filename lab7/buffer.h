//
// Created by HP on 31.05.2022.
//

#ifndef BUFFER_H
#define BUFFER_H

template<class T>
class CCircleBuffer
{
public:
    class iterator;

    iterator begin() {
        return buff;
    }

    iterator end() {
        return buff + copacity;
    }

    CCircleBuffer(int size_)
    {
        copacity = size_;
        tail = 0;
        head = 0;
        buff = new T[copacity];
        for (int i = 0; i < copacity; i++)
            buff[i] = 0;
    }

    ~CCircleBuffer()
    {
        delete[] buff;
    }

    int length()
    {
        return copacity;
    }

    T &operator[](int i)
    {
        return i < copacity ? buff[(head + i) % copacity] : buff[head];
    }

    T &operator[](iterator i)
    {
        return *i;
    }

    T back()
    {
        return buff[tail];
    }

    T front()
    {
        return buff[head];
    }
    void push_front(const T &value)
    {
        buff[head] = value;
        head = head - 1 < 0 ? copacity - 1 : head - 1;
    }

    void push_back(const T &value)
    {
        buff[tail] = value;
        tail = tail + 1 < copacity ? tail + 1 : 0;
    }

    T &pop_back()
    {
        T tmp = buff[tail];
        buff[tail] = 0;
        return tmp;
    }

    T &pop_front() {
        T tmp = buff[head];
        buff[head] = 0;
        return tmp;
    }

    void resize(int n)
    {
        T *newBuff = new T[n];
        for (int i = 0; i < n; i++) {
            newBuff[i] = i < copacity ? buff[i] : 0;
        }
        buff = newBuff;
        copacity = n;
    }

    class iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
    public:
        iterator(T *tmp) {
            p = tmp;
        }

        T &operator+(int n) {
            return *(p + n);
        }

        T &operator-(int n) {
            return *(p - n);
        }

        T &operator-(iterator other) {
            return *(p - *other);
        }

        T &operator++(int) {
            return *p++;
        }

        T &operator--(int) {
            return *p--;
        }

        T &operator++() {
            return *++p;
        }

        T &operator--() {
            return *--p;
        }

        bool operator==(const iterator &other) {
            return this->p == other.p;
        }

        bool operator!=(const iterator &other) {
            return this->p != other.p;
        }

        T &operator*() {
            return *p;
        }

        T *operator->() {
            return p;
        }

        T &operator[](iterator tmp) {
            return *tmp;
        }

        bool operator<(iterator &other){
            return this->p < other.p;
        }

        bool operator>(iterator &other){
            return this->p > other.p;
        }

    private:
        T *p;
    };

private:
    int copacity, head, tail;
    T *buff;
};

#endif //BUFFER_H
