
// COS30008, Tutorial 10, 2025

#pragma once

#include <cstdint>
#include <algorithm>
#include <cassert>

template<typename T>
class Array
{
public:
    
    Array() noexcept
        : fElements(nullptr), fSize(0)
    {
    }

    ~Array()
    {
        delete[] fElements;
    }

    // copy constructor
    Array( const Array& aOther )
        : fSize(aOther.fSize), fElements(new T[aOther.fSize])
    {
        for (size_t i = 0; i < aOther.fSize; i++)
        {
            fElements[i] = aOther.fElements[i];
        }
    }

    // copy assignment
    Array& operator=( const Array& aOther )
    {
        if (this != &aOther)
        {
            this->~Array();

            new (this) Array(aOther);
        }
        return *this;
    }

    // move constructor
    Array( Array&& aOther ) noexcept
        : fSize(0), fElements(nullptr)
    {
        this->swap(aOther);
    }

    // move assignment
    Array& operator=( Array&& aOther ) noexcept
    {
        if (this != &aOther)
        {
            this->swap(aOther);
        }
        return *this;
    }

    void swap( Array& aOther ) noexcept
    {
        std::swap(fElements, aOther.fElements);
        std::swap(fSize, aOther.fSize);
    }
    
    // array operations
    size_t size() const noexcept
    {
        return fSize;
    }

    const T& operator[]( size_t aIndex ) const noexcept
    {
        assert(aIndex < fSize);

        return fElements[aIndex];
    }
    
    void reserve( size_t aNewSize )
    {
        assert(aNewSize > fSize);
        T* newElems = new T[aNewSize];

        for (size_t i = 0; i < fSize; i++)
        {
            newElems[i] = std::move(fElements[i]);
        }

        fSize = aNewSize;

        if (fElements)
            delete[] fElements;
        fElements = newElems;
    }
    
    void fill( const T& aValue = T{} ) noexcept
    {
        for (size_t i = 0; i < fSize; i++)
        {
            fElements[i] = aValue;
        }
    }
    
    template<typename... Args>
    void emplace_at( size_t aIndex, Args&&... args ) noexcept
    {
        assert(aIndex < fSize);
        new (&fElements[aIndex]) T(std::forward<Args>(args)...);
    }

private:

    T* fElements;
    size_t fSize;
};
