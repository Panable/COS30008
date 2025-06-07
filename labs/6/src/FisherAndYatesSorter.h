
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
    
    void shuffle() noexcept;
    
    bool isSorted() noexcept;
    
public:
    
    FisherAndYatesSorter( const T aArray[] = nullptr, size_t aSize = 0 ) noexcept;

    void sort( bool aDoLog = false, std::ostream& aOStream = std::cout ) noexcept override;
};
