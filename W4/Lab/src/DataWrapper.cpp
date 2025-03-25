#include "DataWrapper.h"
#include <fstream>

DataWrapper::DataWrapper()
    : fSize(0), fData(nullptr)
{
}

DataWrapper::~DataWrapper()
{
    delete[] fData;
}

bool DataWrapper::load( const std::string& aFileName )
{
    std::ifstream file( aFileName, std::ifstream::in );
    bool status = file.good();

    if (!status) return status;

    file >> fSize;
    fData = new DataMap[fSize];
    size_t key, value = 0;
    for (size_t i = 0; 
         i < fSize && file >> key >> value; 
         i++)
    {
        fData[i] = DataMap(key, value);
    }
    return true;
}

size_t DataWrapper::size() const noexcept
{
    return fSize;
}

const DataMap& DataWrapper::operator[]( size_t aIndex ) const
{
    return fData[aIndex];
}
