
// COS30008, Tutorial 4, 2025

#pragma once

#include "Map.h"
#include <cassert>
#include <fstream>

#include <string>

using DataMap = Map<size_t, size_t>;

class DataWrapper
{
private:
    size_t fSize;
    DataMap* fData;

public:
       
    DataWrapper()
        : fSize(0), fData(nullptr)
    {
    }

    ~DataWrapper()
    {
        delete[] fData;
    }
    
    // DataWrapper objects are not copyable
    DataWrapper( const DataWrapper& ) = delete;
    DataWrapper& operator=( const DataWrapper& ) = delete;

    bool load( const std::string& aFileName )
    {
        std::ifstream lInput(aFileName, std::ifstream::in);
        if (!lInput.good()) return false;
        if (fData) delete[] fData;

        if (lInput)
        {
            if(lInput >> fSize)
            {
                fData = new DataMap[fSize];
                for (size_t i = 0; i < fSize; i++)
                {
                    lInput >> fData[i];
                }
                return true;
            }
            lInput.close();
        }
        return false;
    }

    size_t size() const noexcept
    {
        return fSize;
    }
    
    const DataMap& operator[]( size_t aIndex ) const
    {
        assert(aIndex < fSize);
        return fData[aIndex];
    }
};
