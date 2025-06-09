// COS30008 - Tutorial 1, 2025

#include <cstddef>

extern void printIntArray( int aArray[], size_t aSize );

int main()
{
    int lArray[] = { 23, 4, 67, 1, 0, -20, 29, -100, 32, 99, -56 };
    size_t lSize = sizeof(lArray) / sizeof(int);
    
    printIntArray( lArray, lSize );
    
    return 0;
}
