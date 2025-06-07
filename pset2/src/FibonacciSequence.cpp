#include "FibonacciSequence.h"
#include <cstdint>

FibonacciSequence::FibonacciSequence() noexcept
    : fPrevious(0), fCurrent(1)
{
}

const uint64_t& FibonacciSequence::operator*() const noexcept
{
    return fCurrent;
}

FibonacciSequence& FibonacciSequence::operator++() noexcept
{
    uint64_t next = fPrevious + fCurrent;
    fPrevious = fCurrent;
    fCurrent = next;
    return *this;
}

FibonacciSequence FibonacciSequence::operator++(int) noexcept
{
    FibonacciSequence old = *this;

    ++(*this);

    return old;
}

// Iterator must implement operator==. The operation != is synthesized.
bool FibonacciSequence::operator==( const FibonacciSequence& aOther ) const noexcept
{
    return fCurrent == aOther.fCurrent &&
           fPrevious == aOther.fPrevious;
}


void FibonacciSequence::begin() noexcept
{
    fPrevious = 0;
    fCurrent  = 1;
}

void FibonacciSequence::end() noexcept
{
    fPrevious = 0;
    fCurrent = 0;
}
