
#include <iostream>
#include <vector>

#include "BasicSorting.h"

#include <iostream>

int main()
{
    std::vector lArrayA { 45, 34, 8, 6, 5, 1, 0, -2, -3, -100 };
    
    std::cout << "\nInsertion Sort: Standard template function call:" << std::endl;
    
    sendToStream( std::cout, lArrayA ) << std::endl;
    performInsertionSort( lArrayA );
    sendToStream( std::cout, lArrayA ) << std::endl;
    sendToStream( std::cout, lArrayA ) << std::endl;
    performInsertionSort( lArrayA, std::less<int>{} );
    sendToStream( std::cout, lArrayA ) << std::endl;

    std::vector lArrayB { 45, 34, 8, 6, 5, 1, 0, -2, -3, -100 };
    InsertionSorter lSorter( lArrayB );

    std::cout << "\nInsertion Sort: Template function object call:" << std::endl;

    sendToStream( std::cout, lSorter.data() ) << std::endl;
    lSorter();
    sendToStream( std::cout, lSorter.data() ) << std::endl;
    sendToStream( std::cout, lSorter.data() ) << std::endl;
    lSorter( std::less<int>{} );
    sendToStream( std::cout, lSorter.data() ) << std::endl;

    
    return 0;
}
