
// COS30008, Tutorial 12, 2025

#pragma once

#include <cstddef>
#include <memory>
#include <cassert>
#include <iostream>
#include <algorithm>

#include "Visitors.h"

template<typename T>
class BTree
{
public:
    using node = std::unique_ptr<BTree>;
    
    BTree( const T& aKey = T{} ) noexcept

    {




    }

    BTree( T&& aKey ) noexcept

    {



    }
    
    ~BTree()
    {
        std::cout << "Deleting " << fKey << std::endl;
    }
    
    template<typename... Args>
    static node makeNode( Args&&... args )
    {




    }


    

    BTree( const BTree& aOther )

    {
                             

         
                                                                 
                                                             
         

                              
         
                                                                  
                                                               
         
    }
    
    //Copy assignment
    BTree& operator=( const BTree& aOther )
    {
                            


         
                          
                           

                                                     
                                     
         

                     
    }

    // Move constructor
    BTree( BTree&& aOther ) noexcept
    {



    }
    
    // Move assignment
    BTree& operator=( BTree&& aOther ) noexcept
    {
         


         
                               
         
                     



    }
    void swap( BTree& aOther ) noexcept
    {
                                     


                                       
                                         
    }
    
    const T& operator*() const noexcept
    {



    }
    
    bool hasLeft() const noexcept
    {



    }
    
    BTree& left() const noexcept
    {



    }
    
    bool hasRight() const noexcept
    {



    }
    
    BTree& right() const noexcept
    {



    }
    
    void attachLeft( node& aNode )
    {




    }
    




    void attachRight( node& aNode )
    {




    }
    
    node detachLeft()
    {




    }
    
    node detachRight()
    {




    }

    bool leaf() const noexcept
    {
        


    }
    
    size_t height() const noexcept
    {
                           



                                   

                  
         
                                           
         
        
                   
         
                                                              
         

                       
    }





    const T& findMax() const noexcept
    {
                   



                                     
                    
    }

    const T& findMin() const noexcept
    {
                  


                                    
                    
    }
    
    void doDepthFirstSearch( const TreeVisitor<T>& aVisitor ) const noexcept
    {
        aVisitor.preVisit( **this );
        
        if ( hasLeft() )
        {
            left().doDepthFirstSearch( aVisitor );
        }
        else
        {
            aVisitor.emitEmpty();
        }
        
        aVisitor.inVisit( **this );

        if ( hasRight() )
        {
            right().doDepthFirstSearch( aVisitor );
        }
        else
        {
            aVisitor.emitEmpty();
        }

        aVisitor.postVisit( **this );
    }

private:

    T fKey;
    node fLeft;
    node fRight;
};
