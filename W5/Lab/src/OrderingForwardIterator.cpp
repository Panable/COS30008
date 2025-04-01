#include "OrderingForwardIterator.h"
OrderingForwardIterator::OrderingForwardIterator( const DataWrapper* aCollection, Sorter aOrdering) noexcept
    : fCollection(aCollection), fOrdering(aOrdering), fIndex(0)
{
}

// Iterator must be const
const OrderingForwardIterator::value_type& OrderingForwardIterator::operator*() const noexcept
{
    return fOrdering(*fCollection, fIndex);
}

OrderingForwardIterator::iterator& OrderingForwardIterator::operator++() noexcept
{
    fIndex++;
    return *this;
}

OrderingForwardIterator::iterator OrderingForwardIterator::operator++(int) noexcept
{
    iterator old = *this;

    ++(*this);

    return old;
}

// Iterator must implement operator==. The operation != is synthesized.
bool OrderingForwardIterator::operator==( const iterator& aOther ) const noexcept
{
    return fCollection == aOther.fCollection &&
           fIndex == aOther.fIndex;
}

// Auxiliary methods not part of std::forward_iterator.
OrderingForwardIterator::iterator OrderingForwardIterator::begin() const noexcept
{
    iterator iter = *this;
    iter.fIndex = 0;
    return iter;
}

OrderingForwardIterator::iterator OrderingForwardIterator::end() const noexcept
{
    iterator iter = *this;
    if (!fCollection)
        iter.fIndex = 0;
    else
        iter.fIndex = fCollection->size() - 1;
    return iter;
}
