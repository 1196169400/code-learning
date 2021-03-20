#include "allocator.h"

/*
template<T>
pointer allocator<T>::allocate()
{
    pointer tmp = static_cast<pointor>::operator new(sizeof(T));
    return tmp;
}
*/

template<typename T>
pointer allocator<T>::allocate(size_type n)
{
    if (n == 0)
        return nullptr;
    return static_cast<pointer>(::operator new(sizeof(T) * n));
}

template<typename T>
void allocator<T>::deallocate(pointer p)
{
    if (p != nullptr) {
        ::operator delete(p);
    }
}

template<typename T>
void allocator<T>::deallocate(pointer p1, size_type n)
{
    pointer tmp = p1;
    while (n--) {
        deallocate(tmp);
        tmp++；
    }
}

template<typename T>
void allocator<T>::construct(pointer p)
{
    mystl::construct(p);
}

template<typename T>
void allocator<T>::construct(pointer p, const reference value)
{
    mystl::construct(p, value);
}

template<typrname T>
void allocator<T>:destroy(pointer p)
{
    mystl::destroy(p);
}

template<typename T>
void allocator<T>::destroy(pointer p1, pointer p2)
{
    mystl::destroy(p1, p2);
}