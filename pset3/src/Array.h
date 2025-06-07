
// COS30008, Tutorial 10, 2025

#pragma once

#include <cstdint>
#include <algorithm>
#include <cassert>

template<typename T>
class Array
{
public:
    
    Array() noexcept:
        fElements(nullptr),
        fSize(0)
    {}
    
    ~Array()
    {
        delete [] fElements;
    }

    // copy semantics
    Array( const Array& aOther ) :
        fElements(new T[aOther.fSize]),
        fSize(aOther.fSize)
    {
        for ( size_t i = 0; i < fSize; i++ )
        {
            fElements[i] = aOther.fElements[i];
        }
    }
    
    Array& operator=( const Array& aOther )
    {
        if ( this != &aOther )
        {
            this.~Array();
            
            new (this) Array( aOther );
        }
        
        return *this;
    }

    // move semantics
    Array( Array&& aOther ) noexcept :
        Array()
    {
        swap( aOther );
    }

    Array& operator=( Array&& aOther ) noexcept
    {
        if ( this != &aOther )
        {
            swap( aOther );
        }
        
        return *this;
    }

    void swap( Array& aOther ) noexcept
    {
        std::swap( fElements, aOther.fElements );
        std::swap( fSize, aOther.fSize );
    }
    
    // array operations
    size_t size() const noexcept
    {
        return fSize;
    }

    const T& operator[]( size_t aIndex ) const noexcept
    {
        assert( aIndex < fSize );
        
        return fElements[aIndex];
    }
    
    void reserve( size_t aNewSize )
    {
        T* lOldElements = fElements;
        size_t lOldSize = fSize;
        
        fElements = new T[aNewSize];
        fSize = aNewSize;
        
        // Copy the minimum number of elements.
        for ( size_t i = 0; i < std::min(lOldSize, fSize); i++ )
        {
            fElements[i] = std::move(lOldElements[i]);
        }
        
        delete[] lOldElements;
    }
    
    void fill( const T& aValue = T{} ) noexcept
    {
        for ( size_t i = 0; i < fSize; i++ )
        {
            fElements[i] = aValue;
        }
    }
    
    template<typename... Args>
    void emplace_at( size_t aIndex, Args&&... args ) noexcept
    {
        assert( aIndex < fSize );

        fElements[aIndex].~T();
        new (&fElements[aIndex]) T( std::forward<Args>(args)... );
    }

private:

    T* fElements;
    size_t fSize;
};
