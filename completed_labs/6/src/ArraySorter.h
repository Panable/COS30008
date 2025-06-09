
// COS30008, Tutorial 6, 2025

#pragma once

#include <cstdint>
#include <ostream>
#include <cassert>

template<typename T>
class ArraySorter
{
public:
    
    ArraySorter( const T aArray[] = nullptr, size_t aSize = 0 ) noexcept
        : fSize(aSize), fSwapCount(0)
    {
        // 0 && 0 -> TRUE
        // 1 && 0 -> FALSE
        // 0 && 1 -> FALSE
        // 1 && 1 -> 0 && 0 -> TRUE
        // This line ensures that if the array exists it has a size
        assert(!aArray == !aSize);
        
        // we should be allocate 0 array
        // if aSize is 0 it doesn't matter
        
        fElements = new T[aSize]; //alloc heap

        for (size_t i = 0; i < aSize; i++) // copy elems
        {
            fElements[i] = aArray[i];
        }
    }
    
    virtual ~ArraySorter() noexcept
    {
        delete[] fElements;
    }
    
    size_t size() const noexcept
    {
        return fSize;
    }

    size_t swapCount() const noexcept
    {
        return fSwapCount;
    }
    
    void swap( T& aLeft, T& aRight ) noexcept
    {
        T temporary = aLeft;
        aLeft = aRight;
        aRight = temporary;
        ++fSwapCount;
    }

    T& operator[]( size_t aIndex ) const noexcept
    {
        assert(aIndex < fSize);
        return fElements[aIndex];
    }
    
    virtual void sort( bool aDoLog = false, std::ostream& aOStream = std::cout ) noexcept
    {
        fSwapCount = 0;
    }
    
    friend std::ostream& operator<<( std::ostream& aOStream, const ArraySorter& aSorter )
    {
        const size_t& sz = aSorter.fSize;

        if (sz > 1)
        {
            aOStream << "[" << aSorter[0];
            for (size_t i = 1; i < sz; i++)
            {
                aOStream << "," << aSorter[i];
            }
            return aOStream << "]" << std::endl;
        }
        return aOStream;
    }
    
private:
    
    T* fElements;
    size_t fSize;
    size_t fSwapCount;
};
