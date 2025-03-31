#pragma once

#include <istream>
#include <ostream>

template <typename Key, typename Value>

class Map {
    private:
        Key   fKey;
        Value fValue;
    public:
        Map( const Key& aKey = Key{}, const Value& aValue = Value{} ) noexcept;

        const Key& key() const noexcept;
        const Value& value() const noexcept;

        template<typename U>
        operator U() const noexcept;

        // friend std::istream& operator>>( std::istream& aIStream, Map& map );
        //
        // friend std::ostream& operator<<( std::ostream& aOStream, const Map& map );

        template <typename K, typename V>
        friend std::istream& operator>>( std::istream& aIStream, Map<K, V>& map );

        template <typename K, typename V>
        friend std::ostream& operator<<( std::ostream& aOStream, const Map<K, V>& map );
};

template <typename Key, typename Value>
Map<Key, Value>::Map( const Key& aKey, const Value& aValue) noexcept
    : fKey(aKey), fValue(aValue)
{}

template <typename Key, typename Value>
const Key& Map<Key, Value>::key() const noexcept
{
    return fKey;
}

template <typename Key, typename Value>
const Value& Map<Key, Value>::value() const noexcept
{
    return fValue;
}

template <typename Key, typename Value>
template <typename U>
Map<Key, Value>::operator U() const noexcept
{
    return static_cast<U>(fValue);
}

template <typename Key, typename Value>
std::istream& operator>>( std::istream& aIStream, Map<Key, Value>& map )
{
    return aIStream >> map.fKey >> map.fValue;
}

template <typename Key, typename Value>
std::ostream& operator<<( std::ostream& aOStream, const Map<Key, Value>& map )
{
    return aOStream << "{" << map.fKey << ", " << map.fValue << "}";
}
