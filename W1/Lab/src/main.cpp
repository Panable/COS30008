#include <cstddef>

extern void printIntArray(int aArray[], size_t aSize);

#define ARRAY_LEN(x) (sizeof x / sizeof x[0])

int main(void)
{
    int lArray[] = { 23, 4, 67, 1, 0, -20, 29, -100, 32, 99, -56 };
    printIntArray(lArray, ARRAY_LEN(lArray));
    return 0;
}
