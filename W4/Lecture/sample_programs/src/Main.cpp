
#include <iostream>

#include "Pointers.h"

int i = 10;
int* ptr_to_i = &i;        // using & to obtain address of i

#include "SimpleAssociativeArray.h"

void testSimpleAssociveArray()
{
    int lArray[] = { 1, 2, 3, 4, 5 };
    std::string lKeys[] = { "0", "1", "2", "3", "4" };
    constexpr size_t lSize = sizeof( lArray ) / sizeof( int );
        
    SimpleAssociativeArray lDict( lArray, lSize );
        
    SimpleAssociativeArray::value_type lSum1 = 0;
    SimpleAssociativeArray::value_type lSum2 = 0;
        
    for ( size_t i = 0; i < lSize; i++ )
    {
        lSum1 += lDict[i];
        lSum2 += lDict[lKeys[i]];
    }
        
    std::cout << "Sum using indexed set view: " << lSum1 << std::endl;
    std::cout << "Sum using associative array view: " << lSum2 << std::endl;
}

#include "Indexer.h"
#include <concepts>

void testIndexer()
{
    using IntBasicIndexer = BasicIndexer<int>;
    
    // Compile-time check of indexer properties using C++20 concepts and type traits.
    static_assert( std::copyable<IntBasicIndexer> &&
                   std::is_same_v<std::void_t<IntBasicIndexer::value_type,
                                              IntBasicIndexer::difference_type>,
                                  void> );
    
    IntBasicIndexer lIndexer;
    
    for ( size_t i = 0; i < lIndexer.size(); i++ )
    {
        lIndexer[i] = static_cast<int>(i) + 1;
    }
    
    std::cout << "Indexer in reverse order:" << std::endl;
    
    for ( size_t i = lIndexer.size(); i > 0; )
    {
        std::cout << '\t' << lIndexer[--i] << std::endl;
    }
    
    using IntIndexerByString = IndexerByString<int, 5>;
    
    // Compile-time check of indexer properties using C++20 concepts and type traits.
    static_assert( std::copyable<IntIndexerByString> &&
                   std::is_same_v<std::void_t<IntIndexerByString::value_type,
                                              IntIndexerByString::difference_type>,
                                  void> );
    
    IntIndexerByString lIndexerS;
    std::string lKeys[] = { "0", "1", "2", "3", "4" };
    
    for ( size_t i = 0; i < lIndexerS.size(); i++ )
    {
        lIndexerS[lKeys[i]] = static_cast<int>(i) + 1;
    }
    
    std::cout << "Indexer in reverse order:" << std::endl;
    
    for ( size_t i = lIndexerS.size(); i > 0; )
    {
        std::cout << '\t' << lIndexerS[lKeys[--i]] << std::endl;
    }

    using IntIndexerByStringLambda = IndexerByStringLambda<int, 5>;
    
    // Compile-time check of indexer properties using C++20 concepts and type traits.
    static_assert( std::copyable<IntIndexerByString> &&
                   std::is_same_v<std::void_t<IntIndexerByStringLambda::value_type,
                                              IntIndexerByStringLambda::difference_type>,
                                  void> );

    IntIndexerByStringLambda lIndexerL;
    std::string lBinaryKeys[] = { "000", "001", "010", "011", "100" };
        
    auto BtoI = [] ( const std::string& aNumber )
    {
        size_t lIndex = 0;
             
        for ( size_t i = 0; i < aNumber.size(); i++ )
        {
            lIndex = (lIndex << 1) + (static_cast<size_t>(aNumber[i]) - '0');
        }
            
        return lIndex;
    };

    for ( size_t i = 0; i < lIndexerL.size(); i++ )
    {
        lIndexerL( lBinaryKeys[i], BtoI ) = static_cast<int>(i) + 1;
    }
        
    std::cout << "Indexer in reverse order:" << std::endl;
        
    for ( size_t i = lIndexerL.size(); i > 0; )
    {
        std::cout << '\t' << lIndexerL( lBinaryKeys[--i], BtoI ) << std::endl;
    }
}

#include "Iterators.h"
#include <iterator>

void testIterator()
{
    using IntBasicIterator = BasicIterator<int, 5>;
    
    static_assert( std::input_or_output_iterator<IntBasicIterator>);
    static_assert( std::indirectly_readable<IntBasicIterator>);
    static_assert( std::input_iterator<IntBasicIterator>);
    static_assert( std::forward_iterator<IntBasicIterator>);
    static_assert( BasicForwardIterator<IntBasicIterator>);
    
    constexpr size_t lSize = 20;
    int lArray[lSize];
    BasicIterator<int, lSize> lIter1( lArray );
    int i = 1;
    
    for ( ; lIter1 != lIter1.end(); lIter1++ )
    {
        *lIter1 = i * i;
        i++;
    }
    
    std::cout << "Iterator values:" << std::endl;
    
    for ( BasicIterator lIter2 = lIter1.begin(); lIter2 != lIter2.end(); lIter2++ )
    {
        std::cout << '\t' << *lIter2 << std::endl;
    }
}

#include <iomanip>

void range_loop_tests()
{
    int lArray[] = {-100,-3,-2};
        
    std::cout << "Copy: " << std::endl;
        
    for ( int i : lArray )
    {
        std::cout << std::hex << &i << ", " << std::dec << sizeof(i) << ", i = " << i << std::endl;
    }
        
    std::cout << "Const reference: " << std::endl;
        
    for ( const int& i : lArray )
    {
        std::cout << std::hex << &i << ", " << std::dec << sizeof(i) << ", i = " << i  << std::endl;
    }
        
    std::cout << "Auto copy: " << std::endl;
        
    for ( auto i : lArray )
    {
        std::cout << std::hex << &i << ", " << std::dec << sizeof(i) << ", i = " << i  << std::endl;
    }
        
    std::cout << "Const auto reference: " << std::endl;
        
    for ( const auto& i : lArray )
    {
        std::cout << std::hex << &i << ", " << std::dec << sizeof(i) << ", i = " << i  << std::endl;
    }
}

void test_range_loops()
{
    constexpr size_t lSize = 20;
    int lArray[lSize];
    BasicIterator<int, lSize> lIter1( lArray );
    int i = 1;

    // populate underlying collection
    for ( auto& item : lIter1 )
    {
        item = i * i;
        i++;
    }
        
    std::cout << "Iterator values:" << std::endl;

    // fetch elements from underlying collection (copy of lIter1)
    for ( const auto& item : lIter1 )
    {
        std::cout << '\t' << item << std::endl;
    }
}


void test_range_loops_fix_sm()
{
    using IntBasicIterator = BasicIteratorSharedMem<int>;
    
    static_assert( BasicForwardIterator<IntBasicIterator>);
    
    IntBasicIterator lIter1;
    int i = 1;

    // populate underlying collection (copy of lIter1)
    for ( auto& item : lIter1 )
    {
        item = i * i;
        i++;
    }
        
    std::cout << "Iterator values:" << std::endl;

    // fetch elements from underlying collection (copy of lIter1)
    for ( const auto& item : lIter1 )
    {
        std::cout << '\t' << item << std::endl;
    }
}

#include "MergeSorter.h"

void testMergeSort()
{
    std::vector lData { 45, 34, 8, 6, 5, 1, 0, -2, -3, -100 };

    MergeSorter lSorter( lData );

    sendToStream( std::cout, lData ) << std::endl;

    lSorter();

    sendToStream( std::cout, lSorter.data() ) << std::endl;
    sendToStream( std::cout, lData ) << std::endl;

    lSorter( std::less{} );
        
    sendToStream( std::cout, lSorter.data() ) << std::endl;
}

struct X {};

int main()
{
    const char* lString = "12345";
        
    std::cout << "\"12345\": " << convert( lString, ctoi ) << std::endl;

    testSimpleAssociveArray();
    
    testIndexer();
    
    testIterator();
    
    range_loop_tests();
    
    test_range_loops();

    test_range_loops_fix_sm();
    
    testMergeSort();
    
    return 0;
}
