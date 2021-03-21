#ifndef MYSTL_ALLOCATOR_H_
#define MYSTL_ALLOCATOR_H_

#include "construct.h"

namespace mystl
{

template<typename T>
class allocator
{
    typedef T           value_type;
    typedef T*          pointer;
    typedef const T*    const_pointer;
    typedef T&          reference;
    typedef const T&    const_reference;
    typedef std::size_t size_type;


    //static pointer allocate();
    static T* allocate(size_type n = 1);

    //static void deallocate(pointer p);
    static void deallocate(pointer p, size_type n = 1);
    
    static void construct(pointer p);
    static void construct(pointer p, const_reference value);
    //static void construct(pointer p, right_reference value);

    static void destory(pointer p);
    static void destory(pointer p1, pointer p2);
};

}


#endif