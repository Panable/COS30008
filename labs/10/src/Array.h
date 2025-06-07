
// COS30008, Tutorial 10, 2025

#pragma once

#include <cstdint>
#include <algorithm>
#include <cassert>

template<typename T>
class Array
{
public:
    
    Array() noexcept;    
    ~Array();

    // copy semantics
    Array( const Array& aOther );
    Array& operator=( const Array& aOther );

    // move semantics
    Array( Array&& aOther ) noexcept;
    Array& operator=( Array&& aOther ) noexcept;

    void swap( Array& aOther ) noexcept;
    
    // array operations
    size_t size() const noexcept;

    const T& operator[]( size_t aIndex ) const noexcept;
    
    void reserve( size_t aNewSize );
    
    void fill( const T& aValue = T{} ) noexcept;
    
    template<typename... Args>
    void emplace_at( size_t aIndex, Args&&... args ) noexcept;

private:

    T* fElements;
    size_t fSize;
};
