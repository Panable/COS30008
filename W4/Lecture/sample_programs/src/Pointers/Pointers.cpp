
#include "Pointers.h"

#include <cctype>
#include <cassert>

int convert( const char* aCString,  int(*aMap)(char aChar))
{
    assert( aCString != nullptr );
    
    int Result = 0;
    
    while ( *aCString )    // using * to deference pointer aCString
    {
        Result = Result * 10 + aMap( *aCString );
        aCString++;        // pointer arithmetic, advance to next character
    }
    
    return Result;
}

int ctoi( char aChar )
{
    assert( std::isdigit( aChar ) );    // debug-mode assertion testing
    
    return aChar - '0';        // characters are integers, ‘0’ == 0x30
}
