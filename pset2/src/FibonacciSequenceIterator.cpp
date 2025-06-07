#include "FibonacciSequenceIterator.h"

FibonacciSequenceIterator::FibonacciSequenceIterator( FibonacciSequence* aSequence, uint64_t aStart) noexcept
    : fSequence(aSequence), fIndex(aStart)
{
    if (fSequence && aStart == 0)
    {
        fSequence->begin();
    } 
    else if (fSequence)
    {
        fSequence->begin();
        for (uint64_t i = 0; i < aStart; ++i)
            ++(fSequence);
    }
}

const uint64_t& FibonacciSequenceIterator::operator*() const noexcept
{
    return **fSequence;
}

FibonacciSequenceIterator& FibonacciSequenceIterator::operator++() noexcept
{
    ++(*fSequence);
    ++fIndex;
    return *this;
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int) noexcept
{
    FibonacciSequenceIterator old = *this;

    ++(*this);

    return old;
}

bool FibonacciSequenceIterator::operator==( const FibonacciSequenceIterator& aOther ) const noexcept
{
    return fIndex == aOther.fIndex;
}

FibonacciSequenceIterator FibonacciSequenceIterator::begin() const noexcept
{
    return FibonacciSequenceIterator(fSequence, 0);
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const noexcept
{
    return FibonacciSequenceIterator(fSequence, MAX_FIBONACCI);
}
