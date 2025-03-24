#pragma once

#include <istream>
#include <ostream>

template <typename Key, typename Value>

class Map {
    private:
        Key fKey;
        Value fValue;
    public:
        Map( const Key& aKey = Key{}, const Value& aValue = Value{} ) noexcept;

        const Key& key() const noexcept;
        const Value& value() const noexcept;

        template<typename U>
        operator U() const noexcept;

        friend std::istream& operator>>( std::istream& aIStream, Map& map );
        friend std::ostream& operator<<( std::istream& aOStream, const Map& map );
};

template <typename Key, typename Value>
Map<Key, Value>::Map( const Key& aKey, const Value& aValue) noexcept
    : Key(aKey), Value(aValue)
{}

template <typename Key, typename Value>
const Key& Map<Key, Value>::key() const noexcept
{
}

template <typename Key, typename Value>
const Value& Map<Key, Value>::value() const noexcept
{
}

template <typename Key, typename Value>
template <typename U>
Map<Key, Value>::operator U() const noexcept
{
}


template <typename Key, typename Value>
friend std::istream& operator>>( std::istream& aIStream, Map<Key, Value>& map )
{
}

template <typename Key, typename Value>
friend std::ostream& operator<<( std::istream& aOStream, const Map<Key, Value>& map )
{
}
