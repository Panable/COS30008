
// COS30008, Tutorial 12, 2025

#pragma once

#include <iostream>

template<typename T>
class TreeVisitor
{
public:
    virtual ~TreeVisitor() {}	// virtual default destructor
	
    virtual void emitEmpty() const noexcept
    {}
    
    // default behavior
    virtual void preVisit( const T& aKey ) const noexcept
    {}

    virtual void postVisit( const T& aKey ) const noexcept
    {}

    virtual void inVisit( const T& aKey ) const noexcept
    {}

    virtual void visit( const T& aKey ) const noexcept
    {
	    std::cout << aKey << " ";
    }
};

template<typename T>
class PreOrderVisitor : public TreeVisitor<T>
{
public:

    // override pre-order behavior
    void preVisit( const T& aKey ) const noexcept override
    {
    	this->visit( aKey ); 	// invoke default behavior
    }
};

template<typename T>
class InOrderVisitor : public TreeVisitor<T>
{
public:

    // override in-order behavior
    void inVisit( const T& aKey ) const noexcept override
    {
        this->visit( aKey );     // invoke default behavior
    }
};

template<typename T>
class PostOrderVisitor : public TreeVisitor<T>
{
public:

    // override post-order behavior
    void postVisit( const T& aKey ) const noexcept override
    {
    	this->visit( aKey ); 	// invoke default behavior
    }
};
