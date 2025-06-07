#include "AutoKey.h"

AutoKey::AutoKey(const std::string& aKeyword) noexcept
    : fValue(), fKeyLength(0), fIndex(0)
{
    for (char c : aKeyword)
    {
        if (std::isalpha(c))
            fValue += std::toupper(c);
    }
    fKeyLength = fValue.size();
}

size_t AutoKey::size() const noexcept
{
    return fValue.size();
}

char AutoKey::operator*() const noexcept
{
    return fValue[fIndex];
}

AutoKey& AutoKey::operator++() noexcept
{
    if (fIndex < fValue.size()) {
        fIndex++;
    }
    return *this;
}

AutoKey AutoKey::operator++(int) noexcept
{
    AutoKey temp = *this;
    ++(*this);
    return temp;
}

AutoKey& AutoKey::operator+=(char aChar) noexcept
{
    if (std::isalpha(aChar)) {
        fValue += std::toupper(aChar);
    }
    return *this;
}

void AutoKey::reset() noexcept
{
    fValue = fValue.substr(0, fKeyLength);
    fIndex = 0;
}
