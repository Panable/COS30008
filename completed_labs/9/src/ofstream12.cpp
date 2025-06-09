#include "ofstream12.h"

void ofstream12::reset()
{
	//clear buffer
	for (size_t i = 0; i < fBufferSize; i++) // compiler may optimize to memset
	{
		fBuffer[i] = std::byte(0);
	}
	fBitIndex = 0;
	fByteIndex = 7;
}

void ofstream12::completeWriteBit()
{
	fBitIndex--;

	if (fBitIndex < 0)
	{
		fByteIndex++;
		fBitIndex = 7;
		if (fByteIndex == fBufferSize)
		{
			flush();
			reset();
		}
	}
}

void ofstream12::writeBit0()
{
	// std::byte& byte = fBuffer[fByteIndex];
	// byte = std::byte(std::to_integer<int>(byte) & ~(1 << fBitIndex));
	completeWriteBit(); //bit is already 0
}

void ofstream12::writeBit1()
{
	fBuffer[fByteIndex] |= std::byte{1} << fBitIndex;
	completeWriteBit();
}

ofstream12::ofstream12( const char *aFileName, size_t aBufferSize)
	: fBufferSize(aBufferSize), fBuffer(new std::byte[128])
{
	open(aFileName);
}

ofstream12::~ofstream12()
{
	close();
	delete[] fBuffer;
}

void ofstream12::open( const char *aFileName )
{
	fOStream = std::ofstream(aFileName, std::ios::binary);
}

void ofstream12::close()
{
	fOStream.close();
}

bool ofstream12::good() const
{
	return fOStream.good();
}

bool ofstream12::is_open() const
{
	return fOStream.is_open();
}

void ofstream12::flush()
{
	size_t size = fByteIndex;

	if (fBitIndex % 7) // there is something in the buffer
	{
		size ++;
	}
	
	fOStream.write(reinterpret_cast<char*>(fBuffer), fBufferSize);
	reset();
}

ofstream12& ofstream12::operator<<( size_t aValue )
{
	for (size_t i = 0; i < 12; i++)
	{
		if (aValue & 0x01 > 0)
			writeBit1();
		else
			writeBit0();

		aValue >>= 1;
	}
	return *this;
}
