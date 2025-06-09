
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

    {
                                               
        



                                               
                                 

                                   
         
                                   
         
    }
    
    const T& operator*() const noexcept
    {





    }







    iterator& operator++() noexcept
    {
                                     


         
                              
                                  
         
                                        
         
                                        
         

                                                     
         
                                    
         

                     
    }

    iterator operator++(int) noexcept
    {
                             





                  

                   
    }

    iterator& operator--() noexcept
    {
                                    
         
                              



                                  
         
                                        
         
                                                   
         

                                                     
         
                                     
         

    }
    iterator operator--(int) noexcept
    {
                             




                  

                   
    }

    bool operator==( const iterator& aOther ) const noexcept
    {
               

                                        
                                        
                                            
                                       
         
    }
    
    iterator begin() const noexcept
    {
                           



                              
                                
                 
    }

    iterator end() const noexcept
    {
                           



                                              
                                 
                 
    }

    iterator rbegin() const noexcept
    {




    }




    iterator rend() const noexcept
    {




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
