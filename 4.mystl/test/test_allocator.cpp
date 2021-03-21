#include "../allocator.h"

#include<iostream>
#include<string>

int main()
{
    mystl::allocator<std::string> alloc;
    auto const p = alloc.allocate(2); 
    auto q = p;
    alloc.construct(q);
    alloc.construct(q++,"hi");
    do {
        alloc.destroy(q);
    }while(q-- != p);
    alloc.deallocate(p, 2);
}