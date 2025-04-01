
#pragma once

#include <cstddef>
#include <cassert>

template<typename T, size_t N = 20>
class BasicIndexer
{
private:
    T fElements[N];
    
public:
    
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    
    BasicIndexer() noexcept :
        fElements()
    {}

    size_t size() const noexcept
    {
        return N;
    }
    
    T& operator[]( size_t aIndex )
    {
        assert( aIndex < N );
        
        return fElements[aIndex];
    }
};

#include <string>

template<typename T, size_t N = 20>
class IndexerByString : public BasicIndexer<T, N>
{
public:
    T& operator[]( const std::string& aKey )
    {
        size_t lIndex = 0;
        
        for ( size_t i = 0; i < aKey.size(); i++ )
        {
            lIndex = lIndex * 10 + (static_cast<size_t>(aKey[i]) - '0');
        }
  
        // Call base class operator[] (performs range check)
        return BasicIndexer<T, N>::operator[](lIndex);
    }
};

template<typename T, size_t N = 20>
class IndexerByStringLambda : public BasicIndexer<T, N>
{
public:
    // Use call operator to access element
    T& operator()( const std::string& aKey,
                   auto AtoI = [] ( const std::string& aKey )
                   {
                        size_t lIndex = 0;
        
                        for ( size_t i = 0; i < aKey.size(); i++ )
                        {
                            lIndex = lIndex * 10 + (static_cast<size_t>(aKey[i]) - '0');
                        }
        
                        return lIndex;
                   })
    {
        // Call base class operator[] (performs range check)
        return BasicIndexer<T, N>::operator[](AtoI(aKey));
    }
};
