#pragma once

#include "SortablePair.h"

#include <optional>
#include <cassert>
#include <algorithm>

template<typename T, typename P>
class PriorityQueue
{
public:

    using value_type = SortablePair<P, T>;

    PriorityQueue() noexcept
        : fElements(new value_type[1]), fHead(0), fTail(0), fCapacity(1) {}

    ~PriorityQueue() noexcept
    {
        delete[] fElements;
    }

    PriorityQueue(const PriorityQueue&) = delete;
    PriorityQueue& operator=(const PriorityQueue&) = delete;

    size_t count() const noexcept
    {
        return fTail - fHead;
    }

    size_t capacity() const noexcept
    {
        return fCapacity;
    }

    std::optional<T> top() const noexcept
    {
        if (count() == 0) return std::nullopt;
        return fElements[fHead].second();
    }

    void push(const T& aValue, const P& aPriority) noexcept
    {
        ensure_capacity();
        new (&fElements[fTail++]) value_type(aPriority, aValue);
        sort();
    }

    void pop() noexcept
    {
        if (count() > 0)
        {
            ++fHead;
            adjust_capacity();
        }
    }

private:

    value_type* fElements;
    size_t fHead;
    size_t fTail;
    size_t fCapacity;

    void sort() noexcept
    {
        std::sort(&fElements[fHead], &fElements[fTail]);
    }

    void resize(size_t aCapacity)
    {
        value_type* newArray = new value_type[aCapacity];
        size_t n = count();
        for (size_t i = 0; i < n; ++i)
        {
            newArray[i] = fElements[fHead + i];
        }
        delete[] fElements;
        fElements = newArray;
        fHead = 0;
        fTail = n;
        fCapacity = aCapacity;
    }

    void ensure_capacity()
    {
        if (fTail == fCapacity)
        {
            resize(fCapacity * 2);
        }
    }

    void adjust_capacity()
    {
        if (count() <= fCapacity / 4 && fCapacity > 1)
            resize(fCapacity / 2);
    }
};
