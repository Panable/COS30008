
// COS30008, Tutorial 10, 2025

#include <iostream>
#include <string>

#include "Array.h"

void test()
{
    const char * lStrings[] =
    {
        "To ",
        "be, ",
        "or ",
        "not ",
        "to ",
        "be: ",
        "that ",
        "is ",
        "the ",
        "question:"
    };
    size_t lSizeStrings = sizeof(lStrings)/ sizeof(const char *);
    
    Array<std::string> lArray1;
    
    lArray1.reserve( lSizeStrings );
    
    for ( size_t i = 0; i < lArray1.size(); i++ )
    {
        lArray1.emplace_at(i , lStrings[i] );
    }

    for ( size_t i = 0; i < lArray1.size(); i++ )
    {
        std::cout << lArray1[i] << ", length = " << lArray1[i].size() << std::endl;
    }

    Array<std::string> lArray2( lArray1 );
    Array<std::string> lArray3 = lArray1;

    std::cout << "lArray1 size: " << lArray1.size() << std::endl;

    for ( size_t i = 0; i < lArray2.size(); i++ )
    {
        std::cout << lArray2[i];
    }
    
    std::cout << std::endl;
    
    for ( size_t i = 0; i < lArray3.size(); i++ )
    {
        std::cout << lArray3[i];
    }
    
    std::cout << std::endl;

    Array<std::string> lArray4( std::move(lArray2) );
    Array<std::string> lArray5 = std::move(lArray3);

    std::cout << "lArray1 size: " << lArray1.size() << std::endl;
    std::cout << "lArray2 size: " << lArray2.size() << std::endl;
    std::cout << "lArray3 size: " << lArray3.size() << std::endl;

    for ( size_t i = 0; i < lArray4.size(); i++ )
    {
        std::cout << lArray4[i];
    }
    
    std::cout << std::endl;
    
    for ( size_t i = 0; i < lArray4.size(); i++ )
    {
        std::cout << lArray4[i];
    }
    
    std::cout << std::endl;

    std::cout << "All arrays go out of scope." << std::endl;
}

int main()
{
    std::cout << "Start Array test..." << std::endl;
    
    test();
    
    std::cout << "Array test complete." << std::endl;

    return 0;
}
