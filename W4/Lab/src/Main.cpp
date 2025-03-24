
// COS30008, Tutorial 4, 2025

#include <iostream>
#include <cassert>

#define P0
#define P1
#define P2
#define P3

#ifdef P0

template<typename T>
const T& max(const T& a, const T& b)
{
    return a > b ? a : b;
}

struct AStruct
{
    int a;
    float b;
    
    bool operator>( const AStruct& aOther ) const noexcept
    {
        return a > aOther.a && b > aOther.b;
    }
};

std::ostream& operator<<( std::ostream& aOStream, const AStruct& aObj )
{
    return aOStream << '{' << aObj.a << ", " << aObj.b << '}';
}

void testP0()
{
    int lValue1 = max( 20, 30 );
    float lValue2 = max( 200.0f, 300.0f );
    double lValue3 = max<double>( 200.0f, 300.0 );
    
    std::cout << "Value of max( 20, 30 ): " << lValue1 << std::endl;
    std::cout << "Value of max( 200.0f, 300.0f ): " << lValue2 << std::endl;
    std::cout << "Value of max<double>( 200.0f, 300.0 ): " << lValue3 << std::endl;
    
    AStruct lStruct1 = { 10, 56.0f };
    AStruct lStruct2 = { 10, 57.0f };
    AStruct lStruct3 = { 12, 56.0f };
    
    const AStruct& lRefValue1 = max( lStruct1, lStruct2 );
    const AStruct& lRefValue2 = max( lStruct1, lStruct3 );
    const AStruct& lRefValue3 = max( lStruct2, lStruct3 );
    
    std::cout << "Value of max( lStruct1, lStruct2 ): " << lRefValue1 << std::endl;
    std::cout << "Value of max( lStruct1, lStruct3 ): " << lRefValue2 << std::endl;
    std::cout << "Value of max( lStruct2, lStruct3 ): " << lRefValue3 << std::endl;
}

#endif

#ifdef P1

#include "Map.h"

void testP1()
{
    using DataMap = Map<int,int>;
    
    DataMap lArray1[] = {{1,32}, {2,68}, {3,83}, {4,80},
                         {5,87}, {6,69}, {7,75}, {8, 52}};
    const size_t lSize1 = sizeof(lArray1)/sizeof(DataMap);
    int lArray2[] { 1, 2, 3, 0, 4, 5, 5, 6, 0, 7};
    const size_t lSize2 = sizeof(lArray2)/sizeof(int);

    for ( size_t i = 0; i < lSize1; i++ )
    {
        std::cout << "Key-value pair " << i << ": " << lArray1[i] << std::endl;
    }

    std::cout << "Test type conversion: ";
    
    for ( size_t i = 0; i < lSize2; i++ )
    {
        std::cout << static_cast<char>(lArray1[lArray2[i]]);
    }

    std::cout << std::endl;
}

#endif

#if defined(P2) || defined(P3)

#include "DataWrapper.h"

bool loadData( DataWrapper& aWrapper, const std::string& aFileName )
{
    if ( !aWrapper.load( aFileName ) )
    {
        std::cerr << "Cannot load data file " << aFileName << std::endl;
        
        return false;
    }
    
    std::cout << "Data loaded." << std::endl;
    
    return true;
}

#endif

#ifdef P2

void testP2( const DataWrapper& aWrapper )
{
    std::cout << "Accessing data sequentially: " << std::endl;
    
    for ( size_t i = 0; i < aWrapper.size(); i++ )
    {
        std::cout << static_cast<char>(aWrapper[i]);
    }

    std::cout << std::endl;
}

#endif

#ifdef P3

void printSorted( const DataWrapper& aWrapper )
{
    std::cout << "Sorting the data: " << std::endl;

    for ( size_t i = 0; i < aWrapper.size(); i++ )
    {
        size_t j = 0;
        
        for ( ; j < aWrapper.size(); j++ )
        {
            if ( aWrapper[j].key() == i )
            {
                break;
            }
        }
        
        std::cout << static_cast<char>(aWrapper[j]);
    }

    std::cout << std::endl;
}

#endif

int main( int argc, char* argv[] )
{
#ifdef P0
 
    testP0();

#endif

#ifdef P1
 
    testP1();

#endif
    
#if defined(P2) || defined(P3)
    
    if ( argc != 2 )
    {
        std::cerr << "Arguments missing." << std::endl;
        std::cerr << "Usage: Lab04 <filename>" << std::endl;
        
        return 1;
    }
    
    DataWrapper lWrapper;
    
    if ( loadData( lWrapper, argv[1] ) )
    {
#ifdef P2
        testP2( lWrapper );

#endif
        
#ifdef P3
        
        printSorted( lWrapper );

#endif
        
        return 0;
    }

    return 2;
    
#else
    
    return 0;
    
#endif
}
