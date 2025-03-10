
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
