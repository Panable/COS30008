#include <iostream>
#include <stddef.h>

extern void printIntArray( int aArray[], size_t aSize )
{
    std::cout << "[";
    if (aSize > 0)
    {
        std::cout << aArray[0];
    }

    for (size_t i = 1; i < aSize; i++)
    {
        std::cout << ", " << aArray[i];
    }

    std::cout << "]" << std::endl;
}
