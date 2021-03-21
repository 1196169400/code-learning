#ifndef MYSTL_CONSTRUCT_H_
#define MYSTL_CONSTRUCT_H_

#include<new>
#include<iostream>
#include<type_traits>

namespace mystl
{

template<typename T>
void construct(T* ty)
{
    ::new((void*)ty) T();
}

template<typename T, typename type>
void construct(T* ty, const type& value)
{
    ::new((void*)ty) T(value);
}

template<typename T>
void destroy_one(T* ty, std::true_type)
{

}

template<typename T>
void destroy_one(T* ty, std::false_type)
{
    if (ty != nullptr)
        ty->~T();
}

template<typename T>
void destroy(T* ty)
{
    destroy_one(ty, std::is_trivially_destructible<T>{});
}

template<typename T>
void destroy_cat(T* iter1, T* iter2, std::true_type)
{

}

template<typename T>
void destroy_cat(T* iter1, T* iter2, std::false_type)
{
    for (; iter1 != iter2; iter1++) {
        destroy(&*iter1);
    }
}

template<typename T>
void destroy(T* iter1, T* iter2)
{
    destroy_cat(iter1, iter2, std::is_trivially_destructible<T>::value);
}


}


#endif