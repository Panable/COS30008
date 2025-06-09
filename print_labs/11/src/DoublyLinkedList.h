
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






    }

    void isolate() noexcept
    {




         




                  
         
                               
         

                                           
                         
                     

                                  
    }

    // factory method for list nodes
    template<typename... Args>
    static node makeNode( Args&&... args )
    {





    }
};
