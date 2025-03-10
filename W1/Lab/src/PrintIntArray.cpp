#include <iostream>
void printIntArray(int aArray[], size_t aSize)
{
    if (aSize == 0) return;

    std::cout << "[" << aArray[0];
    for (size_t i = 1; i < aSize; i++)
    {
        std::cout << ", " << aArray[i];
    }
    std::cout << "]" << std::endl;;
}
