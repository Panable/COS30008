
// COS30008, Tutorial 10, 2025

#include <iostream>
#include <sstream>

#include "DynamicStack.h"

class Data
{
private:
    std::string fName;
    std::string fType;
    
public:
    Data( const char* aName = "", const char* aType = "", int aValue = 0 ) :
        fName(aName),
        fType(aType)
    {
        std::stringstream lStr;
        
        lStr << aValue;
        
        fName += lStr.str();
    }

    friend std::ostream& operator<<( std::ostream& s, const Data& o );
};

std::ostream& operator<<( std::ostream& s, const Data& o )
{
    return s << o.fName << " : " << o.fType;
}

void testStack()
{
    std::cout << "Basic Test:" << std::endl;

    DynamicStack<Data> lStack;

    std::cout << "Push 30 elements:" << std::endl;

    for ( int i = 1; i <= 30; i++ )
    {
        lStack.push( Data( "n", "int", i ) );
    }
    
    std::cout << "Size of Stack: " << lStack.size() << std::endl;

    std::cout << "Pop 30 elements:" << std::endl;
    
    std::optional lValue = lStack.top();

    while ( lValue )
    {
        std::cout << lValue.value() << std::endl;
    
        lStack.pop();

        lValue = lStack.top();
    }

    std::cout << "Size of Stack: " << lStack.size() << std::endl;

    if ( lValue )
    {
        std::cout << "Failure" << std::endl;
    }
    else
    {
        std::cout << "Success" << std::endl;
    }
}

int main()
{
    testStack();
    
    return 0;
}
