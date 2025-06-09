
// COS30008, Tutorial 11, 2025

#pragma once

#include <memory>

template<typename T>
struct DoublyLinkedList
{
    using node = std::shared_ptr<DoublyLinkedList>;
    using node_w = std::weak_ptr<DoublyLinkedList>;

    T data;
    node next;
    node_w previous;

    DoublyLinkedList( const T& aData ) noexcept : data(aData) {}
    
    DoublyLinkedList( T&& aData ) noexcept : data(std::move(aData)) {}
    
    void link( node& aPrevious, node& aNext ) noexcept
    {
        previous = aPrevious;
        next = aNext;
    }

    void isolate() noexcept
    {
        if (next)
        {
            next->previous = previous; //fine to do because weak_ptr
        }

        node lNode = previous.lock(); // weak_ptr must be converted to shared_ptr access obj

        if (lNode)
        {
            lNode->next = next;
        }

        // manually set pointers to nullptr
        previous.reset();
        next.reset();

        // lNode goes out of scope
    }

    // factory method for list nodes
    template<typename... Args>
    static node makeNode( Args&&... args )
    {
        // make_share<T, Args...>
        return std::make_shared<DoublyLinkedList>( std::forward<Args>(args)... );
    }
};
