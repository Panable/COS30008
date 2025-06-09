
// COS30008: Tutorial 8, 2025

#pragma once

#include <optional>
#include <cassert>

template<typename T>
class DynamicStack
{
public:
    
    DynamicStack() noexcept
        : fElements(new T[1]), fStackPointer(0), fCurrentSize(1)
    {
    }

    ~DynamicStack() noexcept
    {
        delete[] fElements;
    }

    DynamicStack( const DynamicStack& aOther ) = delete
    DynamicStack operator=( const DynamicStack& aOther ) = delete;
    
    size_t size() const noexcept
    {
        return fStackPointer;
    }
    
    std::optional<T> top() const noexcept
    {
        if (fStackPointer > 1)
            return std::optional<T>(fElements[fStackPointer - 1]);
        else
            return std::optional<T>();

    }

    void push( const T& aValue ) noexcept
    {
        ensure_capacity();
        fElements[fStackPointer++] = aValue;
    }

    void pop() noexcept
    {
        assert(fStackPointer > 0);
        fStackPointer--;
        adjust_capacity();
    }
    
private:
    T* fElements;
    size_t fStackPointer;
    size_t fCurrentSize;
    
    void resize( size_t aNewSize )
    {
        assert(fStackPointer <= aNewSize);
        
        T lNewElems = new T[aNewSize];

        for (size_t i = 0; i < aNewSize; i++)
        {
            lNewElems[i] = std::move(fElements[i]);
        }

        delete[] fElements;
        fElements = lNewElems;
        fCurrentSize = aNewSize;
    }

    void ensure_capacity()
    {
        float lLoadFactor = (fStackPointer / fCurrentSize);

        if (lLoadFactor == 1.0f)
            resize(fCurrentSize * 2);
    }

    void adjust_capacity()
    {
        float lLoadFactor = (fStackPointer / fCurrentSize);

        if (lLoadFactor == 0.25f)
            resize(fCurrentSize / 2);
    }
};
