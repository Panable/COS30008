
#include "SimpleAssociativeArray.h"

#include <cassert>
#include <cctype>

SimpleAssociativeArray::SimpleAssociativeArray( int aArray[], size_t aSize ) noexcept :
    fArray(aArray),
    fSize(aSize)
{}

size_t SimpleAssociativeArray::size() const noexcept
{
    return fSize;
}

int& SimpleAssociativeArray::operator[]( size_t aIndex ) const
{
    assert( aIndex < fSize );   // debug range check
    
    return fArray[aIndex];
}

int& SimpleAssociativeArray::operator[]( const std::string& aKey ) const
{
    size_t lIndex = 0;
           
    for ( char c : aKey )                       // scan key string
    {
        if ( std::isdigit( c ) )
        {
         // convert string to number
           lIndex = lIndex * 10 + static_cast<size_t>(c) - '0';
        }
        else
        {
           break;
        }
    }
           
    return (*this)[lIndex];         // forward to operator[]( size_t aIndex )
}
