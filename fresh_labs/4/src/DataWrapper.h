
// COS30008, Tutorial 4, 2025

#pragma once

#include "Map.h"

#include <string>

using DataMap = Map<size_t, size_t>;

class DataWrapper
{
private:
    size_t fSize;
    DataMap* fData;

public:
        
    DataWrapper();
    ~DataWrapper();
    
    // DataWrapper objects are not copyable
    DataWrapper( const DataWrapper& ) = delete;
    DataWrapper& operator=( const DataWrapper& ) = delete;

    bool load( const std::string& aFileName );

    size_t size() const noexcept;
    
    const DataMap& operator[]( size_t aIndex ) const;
};
