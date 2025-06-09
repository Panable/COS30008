
// COS30008, Tutorial 5, 2025

#pragma once

#include <concepts>
#include <functional>

#include "DataWrapper.h"

class OrderingForwardIterator
{
public:

    using Sorter = std::function<const DataMap&(const DataWrapper&, size_t)>;
    
    // C++20 iterator type properties
    using iterator = OrderingForwardIterator;
    using difference_type = std::ptrdiff_t;
    using value_type = DataMap;
    
    // Iterator must be default initializable
    OrderingForwardIterator( const DataWrapper* aCollection = nullptr,
                             Sorter aOrdering = [] ( const DataWrapper& aCollection,
                                                     size_t aIndex ) -> const DataMap&
                                    {
                                        return aCollection[aIndex];
                                    } ) noexcept
        : fCollection(aCollection), fOrdering(aOrdering), fIndex(0) 
    {
    }

    // Iterator must be const
    const value_type& operator*() const noexcept
    {
        return fOrdering(*fCollection, fIndex);
    }
    
    iterator& operator++() noexcept
    {
        fIndex++;
        return *this;
    }

    iterator operator++(int) noexcept
    {
        iterator old = *this;
        ++(*this);
        return old;
    }

    // Iterator must implement operator==. The operation != is synthesized.
    bool operator==( const iterator& aOther ) const noexcept
    {
        return (fCollection == aOther.fCollection && 
                fIndex == aOther.fIndex);
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

private:
    
    const DataWrapper* fCollection;
    Sorter fOrdering;
    size_t fIndex;
};

static_assert(std::forward_iterator<OrderingForwardIterator>);
