
// COS30008, Tutorial 6, 2025

#pragma once

#include "ArraySorter.h"

#include <cstdlib>
#include <ctime>

template<typename T, typename Order = std::greater<T>>
class FisherAndYatesSorter : public ArraySorter<T>
{
private:
    
    Order fOrderFtn;
    
    void shuffle() noexcept
    {
        const size_t& sz = this->size();

        for (size_t i = sz; i > 1 ;)
        {
            // [0, fSize - 1]
            int rand = std::rand() % (i--);
            this->swap((*this)[i], (*this)[rand]);
        }
    }
    
    bool isSorted() noexcept
    {
        const size_t sz = this->size();
        for (size_t i = 1; i < sz; i++)
        {
            if (!fOrderFtn((*this)[i - 1], (*this)[i])) return false;
        }
        return true;
    }
    
public:
    
    FisherAndYatesSorter( const T aArray[] = nullptr, size_t aSize = 0 ) noexcept
        : ArraySorter<T>(aArray, aSize), fOrderFtn()
    {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
    }

    void sort( bool aDoLog = false, std::ostream& aOStream = std::cout ) noexcept override
    {
        while (!isSorted())
        {
            shuffle();
            if (aDoLog) aOStream << (*this);
        }
    }
};
