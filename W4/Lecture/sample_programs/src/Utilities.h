
#pragma once

#include <ostream>
#include <vector>

template<typename T>
std::ostream& sendToStream( std::ostream& aOStream, const std::vector<T>& aArray, size_t aIndent = 0 )
{
    for ( size_t i = 0; i < aIndent; i++ )
    {
        aOStream << ' ';
    }
    
    aOStream << '[';

    if ( aArray.size() > 0 )
    {
        aOStream << aArray[0];

        for ( size_t i = 1; i < aArray.size(); i++ )
        {
            aOStream << ',' << aArray[i];
        }
    }
    
    return aOStream << ']';
}

template<typename InputIt>
std::ostream& sendToStream( std::ostream& aOStream, InputIt aStart, InputIt aEnd, size_t aIndent = 0 )
{
    for ( size_t i = 0; i < aIndent; i++ )
    {
        aOStream << ' ';
    }
    
    aOStream << '[';

    if ( aStart != aEnd )
    {
        aOStream << *aStart;
        
        while ( ++aStart != aEnd )
        {
            aOStream << ',' << *aStart;
        }
    }
    
    return aOStream << ']';
}

template<typename T>
std::vector<T>&& makeVector( T aArray[], size_t aLength )
{
    std::vector<T> Result;
    
    for ( size_t i = 0; i < aLength; i++ )
    {
        Result.emplace_back( aArray[i] );
    }
    
    return Result;
}
