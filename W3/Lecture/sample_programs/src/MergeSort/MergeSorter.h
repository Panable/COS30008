
#pragma once

#include <functional>
#include <iostream>
#include <ranges>

#include "Utilities.h"

template<typename T>
class MergeSorter
{
public:
    
    using array_type = std::vector<T>;
    
    MergeSorter( const array_type& aData ) noexcept;
    
    template<typename Op = std::greater<T>>
    void operator()( Op aTest = Op{}, std::ostream& aOStream = std::cout );
    
    const array_type& data() const noexcept;

private:
    using Comparator = std::function<bool(T, T)>;

    array_type fData;
    array_type fMergeData;
    Comparator fComparator;
    size_t indent;
    
    void doMergeSort( size_t aLow, size_t aHigh, std::ostream& aOStream ) noexcept;
    void doMerge( size_t aLow, size_t aMid, size_t aHigh ) noexcept;
};

template<typename T>
MergeSorter<T>::MergeSorter( const array_type& aData ) noexcept :
    fData(aData),
    fComparator(nullptr),
    indent(2)
{
    fMergeData.resize( fData.size() );
}

template<typename T>
template<typename Op>
void MergeSorter<T>::operator()( Op aTest, std::ostream& aOStream )
{
    fComparator = aTest;
    
    doMergeSort( 0, fData.size() - 1, aOStream );
        
    fComparator = nullptr;
}

template<typename T>
const MergeSorter<T>::array_type& MergeSorter<T>::data() const noexcept
{
    return fData;
}

template<typename T>
void MergeSorter<T>::doMergeSort( size_t aLow, size_t aHigh, std::ostream& aOStream ) noexcept
{
    if ( aLow < aHigh )
    {
        sendToStream( aOStream,
                      fData.begin() + aLow,
                      fData.begin() + aHigh + 1 ,
                      indent ) << std::endl;
        
        size_t lMid = aLow + (aHigh - aLow) / 2;
        
        indent += 2;
        doMergeSort( aLow, lMid, aOStream );
        doMergeSort( lMid + 1, aHigh, aOStream );
        doMerge( aLow, lMid, aHigh );
        indent -= 2;
        
        sendToStream( aOStream,
                      fData.begin() + aLow,
                      fData.begin() + aHigh + 1 ,
                      indent ) << std::endl;
    }
}
    
template<typename T>
void MergeSorter<T>::doMerge( size_t aLow, size_t aMid, size_t aHigh ) noexcept
{
    for ( size_t k = aLow; k <= aMid; k++ )
    {
        fMergeData[k] = fData[k];
    }
    
    for ( size_t k = aMid; k < aHigh; k++ )
    {
        fMergeData[(aHigh - k) + aMid] = fData[k + 1];
    }
    
    size_t lPos1 = aLow;
    size_t lPos2 = aHigh;
    
    for ( size_t i = aLow; i <= aHigh; i++ )
    {
        if ( fComparator( fMergeData[lPos1], fMergeData[lPos2] ) )
        {
            fData[i] = fMergeData[lPos2--];
        }
        else
        {
            fData[i] = fMergeData[lPos1++];
        }
    }
}
