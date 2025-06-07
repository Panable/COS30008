#include "VigenereIterator.h"

VigenereIterator::VigenereIterator(const std::string& aKeyword,
                                   const std::string& aSource,
                                   EVigenereMode aMode) noexcept
    : fMode(aMode),
      fKeys(aKeyword),
      fSource(aSource),
      fIndex(0),
      fCurrentChar(0)
{
    initializeTable();
    if (fMode == EVigenereMode::Encode)
        encodeCurrentChar();
    else
        decodeCurrentChar();
}

char VigenereIterator::operator*() const noexcept
{
    return fCurrentChar;
}

VigenereIterator& VigenereIterator::operator++() noexcept
{
    fIndex++;
    if (fMode == EVigenereMode::Encode)
        encodeCurrentChar();
    else
        decodeCurrentChar();
    return *this;
}

VigenereIterator VigenereIterator::operator++(int) noexcept
{
    VigenereIterator old = *this;
    ++(*this);
    return old;
}

bool VigenereIterator::operator==(const VigenereIterator& aOther) const noexcept
{
    return fIndex == aOther.fIndex 
       && fSource == aOther.fSource;
}

VigenereIterator VigenereIterator::begin() const noexcept
{
    VigenereIterator temp = *this;
    temp.fIndex = 0;
    temp.fKeys.reset();
    
    if (temp.fMode == EVigenereMode::Encode)
        temp.encodeCurrentChar();
    else
        temp.decodeCurrentChar();

    return temp;
}

VigenereIterator VigenereIterator::end() const noexcept
{
    VigenereIterator temp = *this;
    temp.fIndex = fSource.size();
    return temp;
}

void VigenereIterator::encodeCurrentChar() noexcept
{
    char c = fSource[fIndex];
    fCurrentChar = c;
    if (!std::isalpha(c)) return;
    
    bool isLower = std::islower(c);
    char upperC = std::toupper(c);
    char keyChar = *fKeys;

    char encoded = fMappingTable[keyChar - 'A'][upperC - 'A'];
    fCurrentChar = isLower ? std::tolower(encoded) : encoded;

    fKeys++;
    fKeys += upperC;
}

void VigenereIterator::decodeCurrentChar() noexcept
{
    char c = fSource[fIndex];
    fCurrentChar = c;
    if (!std::isalpha(c)) return;
    
    bool isLower = std::islower(c);
    char upperC = std::toupper(c);
    char keyChar = *fKeys;

    char decoded = 'A';
    for (size_t i = 0; i < CHARACTERS; i++)
    {
        if (fMappingTable[keyChar - 'A'][i] == upperC)
        {
            decoded = 'A' + i;
            break;
        }
    }

    fCurrentChar = isLower ? std::tolower(decoded) : decoded;

    fKeys++;
    fKeys += decoded;
}
