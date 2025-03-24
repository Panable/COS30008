
// COS30008, 2025

#include "Vector2D.h"

#include <cmath>
#include <cassert>
#include <concepts>

template<std::floating_point T>
constexpr T pi_v = T(3.14159265358979323846);

constexpr float pif = pi_v<float>;

//const float Pif = std::atan( 1.0f ) * 4.0f;

Vector2D::Vector2D( float aX, float aY ) noexcept :
    fX(aX),
    fY(aY)
{}

Vector2D Vector2D::operator+( const Vector2D& aRHS ) const noexcept
{
    return Vector2D( x() + aRHS.x(), y() + aRHS.y() );
}

Vector2D Vector2D::operator-( const Vector2D& aRHS ) const noexcept
{
    return Vector2D( x() - aRHS.x(), y() - aRHS.y() );
}

Vector2D Vector2D::operator*( const float aRHS ) const noexcept
{
    return Vector2D( x() * aRHS, y() * aRHS );
}

float Vector2D::dot( const Vector2D& aRHS ) const noexcept
{
    return x() * aRHS.x() + y() * aRHS.y();
}

float Vector2D::cross( const Vector2D& aRHS ) const noexcept
{
    return x() * aRHS.y() - y() * aRHS.x();
}

float Vector2D::length() const noexcept
{
    float val = std::sqrt( x() * x() + y() * y() );
    
    return std::round( val * 100.0f ) / 100.0f;
}

Vector2D Vector2D::normalize() const noexcept
{
    assert( length() != 0.0f );
    
    return *this * (1.0f/length());
}

float Vector2D::direction() const noexcept
{
    float val = std::atan2( y(), x() ) * 180.0f / pif;
    
    return std::round( val * 100.0f ) / 100.0f;
}

Vector2D Vector2D::align( float aAngleInDegrees ) const noexcept
{
    float lRadians = aAngleInDegrees * pif / 180.0f;

    return length() * Vector2D( std::cos( lRadians ), std::sin( lRadians ) );
}

std::istream& operator>>( std::istream& aIStream, Vector2D& aVector )
{
    return aIStream >> aVector.fX >> aVector.fY;
}

std::ostream& operator<<( std::ostream& aOStream, const Vector2D& aVector )
{
    return aOStream << "[" << round( aVector.fX ) << "," << round( aVector.fY ) << "]";
}

Vector2D operator*( const float aScalar, const Vector2D& aVector ) noexcept
{
    return aVector * aScalar;
}
