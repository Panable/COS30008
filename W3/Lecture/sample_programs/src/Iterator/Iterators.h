
#pragma once

#include <cstddef>
#include <iterator>

// Input or Output Iterator

struct InputOrOutputIterator
{
    using difference_type = std::ptrdiff_t;
 
    int& operator*();
 
    InputOrOutputIterator& operator++();
    void operator++(int);
};
 
static_assert(std::input_or_output_iterator<InputOrOutputIterator>);

// Input Iterator

class SimpleInputIterator
{
public:
    using difference_type = std::ptrdiff_t;
    using value_type = int;
 
    int& operator*() const;
 
    SimpleInputIterator& operator++();
    void operator++(int);
};
 
static_assert(std::input_iterator<SimpleInputIterator>);

// Forward Iterator

class SimpleForwardIterator
{
public:
    using difference_type = std::ptrdiff_t;
    using value_type = int;
 
    int& operator*() const;
 
    SimpleForwardIterator& operator++();
 
    SimpleForwardIterator operator++(int);
 
    bool operator==(const SimpleForwardIterator&) const;
};
 
static_assert(std::forward_iterator<SimpleForwardIterator>);

template<typename T, size_t N>
class BasicIterator
{
private:
    T* fElements;                                               // underlying collection (array type decays to pointer)
    size_t fPosition;                                           // iterator position
    
public:
    using iterator = BasicIterator<T, N>;                       // iterator type alias
    using difference_type = std::ptrdiff_t;                     // to satisfy concept weakly_incrementable
    using value_type = T;                                       // to satisfy concept indirectly_readable

    BasicIterator( T aElements[N] = nullptr ) noexcept;         // array decays to pointer, default contructable

    T& operator*() const noexcept;                              // const to satisfy concept indirectly_readable

    iterator& operator++() noexcept;                            // prefix increment
    iterator operator++( int ) noexcept;                        // postfix increment
    
    bool operator==( const iterator& aOther ) const noexcept;   // iter1 == iter2
    
    iterator begin() const noexcept;                            // return fresh iterator positioned at start
    iterator end() const noexcept;                              // return fresh iterator position after last
};

template<typename T>
concept BasicForwardIterator =
std::forward_iterator<T> &&
requires( T i, T j )
{
    { i.begin() } -> std::same_as<T>;
    { i.end() } -> std::same_as<T>;
};

static_assert(BasicForwardIterator<BasicIterator<int, 5>>);

template<typename T, size_t N>
BasicIterator<T, N>::BasicIterator( T aElements[N] ) noexcept :
    fElements(aElements),
    fPosition(0)
{}

template<typename T, size_t N>
T& BasicIterator<T,N>::operator*() const noexcept
{
    return const_cast<T&>(fElements[fPosition]);
}

template<typename T, size_t N>
BasicIterator<T,N>::iterator& BasicIterator<T,N>::operator++() noexcept
{
    fPosition++;
    
    return *this;
}

template<typename T, size_t N>
BasicIterator<T,N>::iterator BasicIterator<T,N>::operator++( int ) noexcept
{
    iterator old = *this;
    
    ++(*this);	// forward to prefix increment
    
    return old;
}

template<typename T, size_t N>
bool BasicIterator<T,N>::operator==( const iterator& aOther ) const noexcept
{
    return
        fElements == aOther.fElements &&        // collection
        fPosition == aOther.fPosition;          // position
}

template<typename T, size_t N>
BasicIterator<T,N>::iterator BasicIterator<T,N>::begin() const noexcept
{
    iterator iter = *this;
    
    iter.fPosition = 0;
    
    return iter;
}

template<typename T, size_t N>
BasicIterator<T,N>::iterator BasicIterator<T,N>::end() const noexcept
{
    iterator iter = *this;
    
    iter.fPosition = N;
    
    return iter;
}

#include <memory>

template<typename T, size_t N = 20>
class BasicIteratorSharedMem
{
private:
    std::shared_ptr<T[N]> fElements;                            // underlying collection
    size_t fPosition;                                           // iterator position
    
public:
    using iterator = BasicIteratorSharedMem<T,N>;                   // iterator type alias
    using difference_type = std::ptrdiff_t;                     // to satisfy concept weakly_incrementable
    using value_type = T;                                       // to satisfy concept indirectly_readable

    BasicIteratorSharedMem() noexcept;

    T& operator*() const noexcept;                              // const to satisfy concept indirectly_readable

    iterator& operator++() noexcept;                            // prefix increment
    iterator operator++( int ) noexcept;                        // postfix increment
    
    bool operator==( const iterator& aOther ) const noexcept;   // iter1 == iter2
    
    iterator begin() const noexcept;                            // return fresh iterator positioned at start
    iterator end() const noexcept;                              // return fresh iterator position after last
};

template<typename T, size_t N>
BasicIteratorSharedMem<T,N>::BasicIteratorSharedMem() noexcept :
    fElements(std::make_shared<T[N]>()),
    fPosition(0)
{}

template<typename T, size_t N>
T& BasicIteratorSharedMem<T,N>::operator*() const noexcept
{
    return const_cast<T&>(fElements[fPosition]);
}

template<typename T, size_t N>
BasicIteratorSharedMem<T,N>::iterator& BasicIteratorSharedMem<T,N>::operator++() noexcept
{
    fPosition++;
    
    return *this;
}

template<typename T, size_t N>
BasicIteratorSharedMem<T,N>::iterator BasicIteratorSharedMem<T,N>::operator++( int ) noexcept
{
    iterator old = *this;
    
    ++(*this);    // forward to prefix increment
    
    return old;
}

template<typename T, size_t N>
bool BasicIteratorSharedMem<T,N>::operator==( const iterator& aOther ) const noexcept
{
    return  fElements.get() == aOther.fElements.get() &&    // collection
            fPosition == aOther.fPosition;                  // position
}

template<typename T, size_t N>
BasicIteratorSharedMem<T,N>::iterator BasicIteratorSharedMem<T,N>::begin() const noexcept
{
    iterator iter = *this;
    
    iter.fPosition = 0;
    
    return iter;
}

template<typename T, size_t N>
BasicIteratorSharedMem<T,N>::iterator BasicIteratorSharedMem<T,N>::end() const noexcept
{
    iterator iter = *this;
    
    iter.fPosition = N;
    
    return iter;
}
