
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
    
    // Default Constructor
    BTree( const T& aKey = T{} ) noexcept
        : fKey(std::move(aKey)), fLeft(nullptr), fRight(nullptr)
    {
    }

    // Move key constructor
    BTree( T&& aKey ) noexcept
        : fKey(std::move(aKey)), fLeft(nullptr), fRight(nullptr)
    {
    }
    
    ~BTree()
    {
        std::cout << "Deleting " << fKey << std::endl;
    }
    
    template<typename... Args>
    static node makeNode( Args&&... args )
    {
    	return std::make_unique<BTree>( std::forward<Args>(args)... );
    }
    
    // Copy constructor
    BTree( const BTree& aOther )
        : fKey(aOther.fKey)
    {
        if (aOther.hasLeft())
        {
            // Call copy constructor on left and move constructor
            fLeft = std::move(this->makeNode(aOther.left()));
        }

        if (aOther.hasRight())
        {
            // Call copy constructor on right and move constructor
            fRight = std::move(this->makeNode(aOther.right()));
        }
    }
    
    //Copy assignment
    BTree& operator=( const BTree& aOther )
    {
        if (this != &aOther)
        {
            // free memory
            this->~BTree();

            // call copy constructor with inplace new
            new (this) BTree(aOther);
        }

        return *this;
    }

    // Move constructor
    BTree( BTree&& aOther ) noexcept
    {
        this->swap(aOther);
    }
    
    // Move assignment
    BTree& operator=( BTree&& aOther ) noexcept
    {
        if (this != &aOther)
        {
            this->swap(aOther);
        }
        return *this;
    }
    
    void swap( BTree& aOther ) noexcept
    {
        std::swap(fKey, aOther.fKey);
        std::swap(fLeft, aOther.fLeft);
        std::swap(fRight, aOther.fRight);
    }
    
    const T& operator*() const noexcept
    {
        return fKey;
    }
    
    bool hasLeft() const noexcept
    {
        return (fLeft != nullptr);
    }
    
    BTree& left() const noexcept
    {
        return *fLeft;
    }
    
    bool hasRight() const noexcept
    {
        return (fRight != nullptr);
    }
    
    BTree& right() const noexcept
    {
        return *fRight;
    }
    
    void attachLeft( node& aNode )
    {
        assert(!fLeft);
        fLeft = std::move(aNode);
    }
    
    void attachRight( node& aNode )
    {
        assert(!fRight);
        fRight = std::move(aNode);
    }
    
    node detachLeft()
    {
        assert(fLeft);
        return std::move(fLeft);
    }
    
    node detachRight()
    {
        assert(fRight);
        return std::move(fRight);
    }

    bool leaf() const noexcept
    {
        return (!hasRight() && !hasLeft());
    }
    
    size_t height() const noexcept
    {
        size_t lHeight = 0;

        if (leaf()) return lHeight;

        if (fLeft)
        {
            lHeight  = fLeft->height() + 1;
        }
        
        if (fRight)
        {
            lHeight = std::max(lHeight, fRight->height() + 1);
        }

        return lHeight;
    }

    const T& findMax() const noexcept
    {
        if (fRight)
            return fRight->findMax();
        return fKey;
    }

    const T& findMin() const noexcept
    {
        if (fLeft)
            return fLeft->findMin();
        return fKey;
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
