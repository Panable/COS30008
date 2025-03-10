
#pragma once

#include <functional>
#include <iostream>
#include <vector>

#include "Utilities.h"

// Function template for insertion sort

template<typename T, typename Op = std::greater<T> >
void performInsertionSort( std::vector<T>& aArray, Op aTest = Op{}, std::ostream& aOStream = std::cout )
{
    size_t i = 1;
    
    while ( i < aArray.size() )
    {
        size_t j = i++;
        
        while ( j > 0 && aTest( aArray[j-1], aArray[j] ) )
        {
            std::swap( aArray[j-1], aArray[j] );
            
            j--;
        }
        
        sendToStream( aOStream, aArray, 2u ) << std::endl;
    }
}

// template class for insertion sort

template<typename T>
class InsertionSorter
{
public:
    
    using array_type = std::vector<T>;
    
    InsertionSorter( const array_type& aData ) : fData(aData) {}
    
    template<typename Op = std::greater<T>>
    void operator()( Op aTest = Op{}, std::ostream& aOStream = std::cout )
    {
        performInsertionSort( fData, aTest, aOStream );
    }
    
    const array_type& data() const { return fData; }

private:

    array_type fData;
};
