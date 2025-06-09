
// COS30008, Tutorial 11, 2025

#pragma once

#include <cassert>

#include "DoublyLinkedList.h"

template<typename T>
class DoublyLinkedListIterator
{
public:
    using iterator = DoublyLinkedListIterator<T>;
    using node = DoublyLinkedList<T>::node;
    using difference_type = std::ptrdiff_t;                     // to satisfy concept weakly_incrementable
    using value_type = T;                                       // to satisfy concept indirectly_readable

    enum class States { BEFORE, DATA, AFTER };

    DoublyLinkedListIterator() noexcept : fState(States::AFTER) {}
    DoublyLinkedListIterator( const node& aHead, const node& aTail ) noexcept
        : fHead(aHead), fTail(aTail), fPosition(aHead), fState(States::DATA)
    {
        // if there is no head there is no tail
        // if there is no tail there is no head
        assert(!fHead == !fTail);

        if (!fPosition) //no object
        {
            fState = States::AFTER;
        }
    }
    
    const T& operator*() const noexcept
    {
        return fPosition->data;
    }

    iterator& operator++() noexcept
    {
        if (fState == States::BEFORE)
        {
            fPosition = fHead;
            fState = States::DATA;
        }
        else if (fState == States::DATA)
        {
            fPosition = fPosition->next;
        }

        if (!fPosition) // no object at this position
        {
            fState = States::AFTER; 
        }

        return *this;
    }

    iterator operator++(int) noexcept
    {
        iterator old = *this;

        ++(*this);

        return old;
    }

    iterator& operator--() noexcept
    {
        if (fState == States::AFTER)
        {
            fPosition = fTail;
            fState = States::DATA;
        }
        else if (fState == States::DATA)
        {
            fPosition = fPosition->previous.lock();
        }

        if (!fPosition) // no object at this position
        {
            fState = States::BEFORE; 
        }

        return *this;
    }

    iterator operator--(int) noexcept
    {
        iterator old = *this;

        --(*this);

        return old;
    }

    bool operator==( const iterator& aOther ) const noexcept
    {
        return 
            fHead     == aOther.fHead &&
            fTail     == aOther.fTail &&
            fPosition == aOther.fPosition &&
            fState    == aOther.fState;

    }
    
    iterator begin() const noexcept
    {
        iterator b = *this;
        b.fPosition = b.fHead;
        b.fState = States::DATA;
        return b;
    }

    iterator end() const noexcept
    {
        iterator b = *this;
        b.fPosition.reset(); // set to nullptr
        b.fState = States::AFTER;
        return b;
    }

    iterator rbegin() const noexcept
    {
        return --end();
    }

    iterator rend() const noexcept
    {
        return --begin();
    }

private:
    node   fHead;
    node   fTail;
    node   fPosition;
    States fState;
};

template<typename T>
concept BasicBidirectionalIterator =
std::bidirectional_iterator<T> &&
requires( T i, T j )
{
    { i.begin() } -> std::same_as<T>;
    { i.end() } -> std::same_as<T>;
};

static_assert( BasicBidirectionalIterator<DoublyLinkedListIterator<int>>);
