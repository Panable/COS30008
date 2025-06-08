
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
        : ArraySorter<T>(aArray, aSize), fOrderFtn()
    {
    }

    void sort( bool aDoLog = false, std::ostream& aOStream = std::cout ) noexcept override
    {
        bool again = false;

        for (size_t i = 0; i < this->size() - 1; i++)
        {
            T& before = (*this)[i];
            T& after  = (*this)[i + 1];
            if (!fOrderFtn(before, after))
            {
                this->swap(before, after);
                again = true;
            }
        }

        if (aDoLog) aOStream << (*this);
        if (again) this->sort(aDoLog, aOStream);
    }
};
