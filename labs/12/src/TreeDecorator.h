
// COS30008, Tutorial 12, 2025

#pragma once

#include "Visitors.h"

template<typename T>
class TreeDecorator : public TreeVisitor<T>
{
public:

    void emitEmpty() const noexcept override;

    // override pre-order behavior
    void preVisit( const T& aKey ) const noexcept override;

    // override post-order behavior
    void postVisit( const T& aKey ) const noexcept override;
};
