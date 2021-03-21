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
    std::cout << "allocate::" << sizeof(T)*n << std::endl;
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
        tmp++;
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
    int* p = alloc.allocate(a); 
    std::cout << reinterpret_cast<int>(p) << std::endl;
    int* q = p;
    alloc.construct(q,10);
    alloc.construct(q++,30);
    std::cout << reinterpret_cast<int>(p) <<std::endl;
    std::cout << p[0] <<std::endl;
    std::cout << p[1] << std::endl;
    std::cout << "1" << std::endl;
    do {
        alloc.destroy(q);
    }while(q-- != p);
    std::cout << "2" <<std::endl;
    alloc.deallocate(p, 2);
    std::cout << "success" << std::endl;
    return 0;
}