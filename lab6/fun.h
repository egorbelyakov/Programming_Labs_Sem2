#ifndef FUN_H
#define FUN_H

using namespace std;

template <typename iterator, typename predicate>
bool none_of(iterator begin, iterator end, predicate function)
{
    int count = 0;
    for(auto it = begin; it != end; it = next(it))
    {
        if(function(*it))
        {
            count++;
        }
    }
    return count == 0;
}

template <typename iterator, typename object>
bool is_sorted(const iterator begin, const iterator end, bool (&f)(object, object))
{
    iterator prev = begin;
    for(auto it = next(begin); it != end; it = next(it))
    {
        if(!f(*prev, *it))
            return false;
        prev = it;
    }
    return true;
}

template <typename iterator, typename object>
iterator find_not(iterator begin, iterator end, const object& v)
{
    for(auto it = begin; it != end; it = next(it))
    {
        if(*it != v)
            return it;
    }
    cout << "All elements are equal((" << endl;
    return end;
}

#endif //FUN_H