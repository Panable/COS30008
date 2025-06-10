
// COS30008, Tutorial 6, 2025

#pragma once

#include "ArraySorter.h"
#include <limits.h>

template<typename T, typename Order = std::greater<T>>
class BubbleSorter : public ArraySorter<T>
{
private:
    
    Order fOrderFtn;
    
public:
    
    BubbleSorter( const T aArray[] = nullptr, size_t aSize = 0 ) noexcept


    {
    }

    void sort( bool aDoLog = false, std::ostream& aOStream = std::cout ) noexcept override
    {
















    }
};
