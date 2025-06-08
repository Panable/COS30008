
// COS30008: Tutorial 8, 2025

#pragma once

#include <optional>
#include <cassert>

template<typename T>
class DynamicStack
{
public:
    
    DynamicStack() noexcept;
    ~DynamicStack() noexcept;

    DynamicStack( const DynamicStack& aOther ) = delete;
    DynamicStack operator=( const DynamicStack& aOther ) = delete;
    
    size_t size() const noexcept;
    
    std::optional<T> top() const noexcept;
    void push( const T& aValue ) noexcept;
    void pop() noexcept;
    
private:
    T* fElements;
    size_t fStackPointer;
    size_t fCurrentSize;
    
    void resize( size_t aNewSize );
    void ensure_capacity();
    void adjust_capacity();
};
