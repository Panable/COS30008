
// COS30008, Tutorial 6, 2025

#pragma once

#include <cstdint>
#include <ostream>
#include <cassert>

template<typename T>
class ArraySorter
{
public:
    
    ArraySorter( const T aArray[] = nullptr, size_t aSize = 0 ) noexcept


    {
                         
                          
                          
                                   
                                                                   
                                  
        
                                        
                                          
        
                                              

                                                        
         
                                     
         
    }
    
    virtual ~ArraySorter() noexcept
    {

        

    }
    
    size_t size() const noexcept
    {



    }





    size_t swapCount() const noexcept
    {



    }
    
    void swap( T& aLeft, T& aRight ) noexcept
    {







    }

    T& operator[]( size_t aIndex ) const noexcept
    {





    }
    
    virtual void sort( bool aDoLog = false, std::ostream& aOStream = std::cout ) noexcept
    {




    }
    
    friend std::ostream& operator<<( std::ostream& aOStream, const ArraySorter& aSorter )
    {









    }
private:
    
    T* fElements;
    size_t fSize;
    size_t fSwapCount;
};
