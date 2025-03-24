
#pragma once

#include <cstddef>              // definition of size_t
#include <string>               // definition of std::string

class SimpleAssociativeArray
{
public:
    
    using value_type = int;                 // associated value type of SimpleAssociativeArray
    using difference_type = std::ptrdiff_t; // associated pointer difference type of SimpleAssociativeArray
    
    SimpleAssociativeArray( int aArray[], size_t aSize ) noexcept;
    
    size_t size() const noexcept;
    
    int& operator[]( size_t aIndex ) const;
    int& operator[]( const std::string& aKey ) const;
    
private:
    int* fArray;        // non-owning pointer to data array
    size_t fSize;
};
