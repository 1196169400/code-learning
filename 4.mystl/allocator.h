#ifndef MYSTL_ALLOCATOR_H_
#define MYSTL_ALLOCATOR_H_

#include "construct.h"

namespace mystl
{

template<typename T>
class allocator
{
public:
    typedef T           value_type;
    typedef T*          pointer;
    typedef const T*    const_pointer;
    typedef T&          reference;
    typedef const T&    const_reference;
    typedef std::size_t size_type;

public:
    allocator()=default;
    ~allocator()=default;
    //static pointer allocate();
    T* allocate(size_type n = 1);

    //size_type不能有默认参数
    //void deallocate(pointer p);
    void deallocate(pointer p, size_type);
    
    void construct(pointer p);
    void construct(pointer p, const_reference value);
    //static void construct(pointer p, right_reference value);

    static void destroy(pointer p);
    static void destroy(pointer p1, pointer p2);
};

}


#endif