
// COS30008, Tutorial 9, 2025

#pragma once

#include <cstddef>              // std::byte
#include <fstream>

class ofstream12
{
private:
	std::ofstream fOStream;

    std::byte* fBuffer;         // output buffer
    size_t fBufferSize;         // output buffer size
    
	size_t fByteIndex;          // current byte index
	int fBitIndex;              // current bit index (can be negative)

	void reset();		        // reset buffer
	void completeWriteBit();    // complete write
	void writeBit0();           // write 0
	void writeBit1();           // write 1

public:
    // using C++11's nullptr
	ofstream12( const char *aFileName = nullptr, size_t aBufferSize = 128 );
	~ofstream12();

	void open( const char *aFileName );
	void close();

	bool good() const;
    bool is_open() const;
    
	void flush();

	ofstream12& operator<<( size_t aValue );
};
