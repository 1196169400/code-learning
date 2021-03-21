#include "allocator.h"
#include <iostream>

namespace mystl
{

/*
template<T>
pointer allocator<T>::allocate()
{
    pointer tmp = static_cast<pointor>::operator new(sizeof(T));
    return tmp;
}
*/


//返回值不能写pointer，不在类作用域内
template<typename T>
T* allocator<T>::allocate(size_type n)
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
    //pointer tmp = p1;
    while (n--) {
        deallocate(p1++);
        //tmp++;
    }
}

template<typename T>
void allocator<T>::construct(pointer p)
{
    mystl::construct(p);
}

template<typename T>
void allocator<T>::construct(pointer p, const_reference value)
{
    mystl::construct(p, value);
}

template<typename T>
void allocator<T>::destroy(pointer p)
{
    mystl::destroy(p);
}

template<typename T>
void allocator<T>::destroy(pointer p1, pointer p2)
{
    mystl::destroy(p1, p2);
}

}

int main()
{
    mystl::allocator<int> alloc;
    size_t a{2};
    auto const p = alloc.allocate(a); 
    auto q = p;
    alloc.construct(q);
    alloc.construct(q++,1);
    do {
        alloc.destroy(q);
    }while(q-- != p);
    alloc.deallocate(p, 2);
    std::cout << "success" << std::endl;
    return 0;
}