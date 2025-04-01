#include "SimpleForwardIterator.h"

SimpleForwardIterator::SimpleForwardIterator( const DataWrapper* aCollection) noexcept
    : fCollection(aCollection), fIndex(0)
{
}

// Iterator must be const
const SimpleForwardIterator::value_type& SimpleForwardIterator::operator*() const noexcept
{
    return const_cast<value_type&>((*fCollection)[fIndex]);
}

SimpleForwardIterator::iterator& SimpleForwardIterator::operator++() noexcept
{
    fIndex++;
    return *this;
}

SimpleForwardIterator::iterator SimpleForwardIterator::operator++(int) noexcept
{
    iterator old = *this;

    ++(*this);

    return old;
}

// Iterator must implement operator==. The operation != is synthesized.
bool SimpleForwardIterator::operator==( const iterator& aOther ) const noexcept
{
    return fCollection == aOther.fCollection &&
           fIndex == aOther.fIndex;
}

// Auxiliary methods not part of std::forward_iterator.
SimpleForwardIterator::iterator SimpleForwardIterator::begin() const noexcept
{
    iterator iter = *this;
    iter.fIndex = 0;
    return iter;
}

SimpleForwardIterator::iterator SimpleForwardIterator::end() const noexcept
{
    iterator iter = *this;
    if (!fCollection)
        iter.fIndex = 0;
    else
        iter.fIndex = fCollection->size() - 1;
    return iter;
}
