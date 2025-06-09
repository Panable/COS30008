
// COS30008, Tutorial 5, 2025

#pragma once

#include <concepts>

#include "DataWrapper.h"

class SimpleForwardIterator
{
private:
    const DataWrapper* fCollection;
    size_t fIndex;

public:

    // C++20 iterator type properties
    using iterator = SimpleForwardIterator;
    using difference_type = std::ptrdiff_t;
    using value_type = DataMap;
    
    // Iterator must be default initializable
    SimpleForwardIterator( const DataWrapper* aCollection = nullptr ) noexcept
        : fCollection(aCollection), fIndex(0)
    {
    }
    
    // Iterator must be const
    const value_type& operator*() const noexcept
    {
        return (*fCollection)[fIndex];
    }
    
    iterator& operator++() noexcept
    {
        fIndex++;
        return *this;
    }

    iterator operator++(int) noexcept
    {
        iterator it = *this;
        ++(*this);
        return it;
    }

    // Iterator must implement operator==. The operation != is synthesized.
    bool operator==( const iterator& aOther ) const noexcept
    {
        return (fCollection == aOther.fCollection && fIndex == aOther.fIndex);
    }
    
    // Auxiliary methods not part of std::forward_iterator.
    iterator begin() const noexcept
    {
        iterator it = *this;
        it.fIndex = 0;

        return it;
    }

    iterator end() const noexcept
    {
        iterator it = *this;
        if (fCollection)
            it.fIndex = fCollection->size();
        return it;
    }
};

static_assert(std::forward_iterator<SimpleForwardIterator>);
