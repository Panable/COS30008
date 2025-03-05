#include <iostream>
void printIntArray(int aArray[], size_t aSize)
{
    std::cout << "[";
    for (size_t i = 0; i < aSize; i++)
    {
        std::cout << aArray[i];
        if (i != aSize - 1) //last elem
            std::cout << ", ";
    }
    std::cout << "]";
}
