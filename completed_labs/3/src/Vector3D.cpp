#include "Vector3D.h"
#include <cassert>
Vector3D::Vector3D( float aX, float aY, float aW) noexcept
    : fBaseVector(aX, aY), fW(aW)
{
}

Vector3D::Vector3D( const Vector2D& aVector ) noexcept
    : fBaseVector(aVector), fW(1.0f)
{
}

float Vector3D::operator[]( size_t aIndex ) const noexcept
{
    assert(aIndex < 3);
    return *(reinterpret_cast<const float*>(this) + aIndex);
}

Vector3D::operator Vector2D() const noexcept
{
    return fBaseVector * (1.0f/fW);
}

Vector3D Vector3D::operator*( const float aScalar ) const noexcept
{
    return {x() * aScalar, y() * aScalar, w() * aScalar};
}

Vector3D Vector3D::operator+( const Vector3D& aOther ) const noexcept
{
    return {x() + aOther.x(), y() + aOther.y(), w() + aOther.w()};
}

float Vector3D::dot( const Vector3D& aOther ) const noexcept
{
    return fBaseVector.dot(aOther.fBaseVector) + (w() * aOther.w());
}

std::ostream& operator<<( std::ostream& aOStream, const Vector3D& aVector )
{
    return aOStream << static_cast<Vector2D>(aVector);
}
