#include "Matrix3x3.h"
#include <cassert>
#include <numbers>
#include <cmath>

Matrix3x3::Matrix3x3() noexcept
    : fRows
    {
        {1.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 1.0f}
    }
{
}

Matrix3x3::Matrix3x3( const Vector3D& aRow1, const Vector3D& aRow2, const Vector3D& aRow3 )
    : fRows
    {
        aRow1,
        aRow2,
        aRow3
    }
{
}

Matrix3x3 Matrix3x3::operator*( const float aScalar ) const
{
    const Matrix3x3& M = *this;
    return
    {
        {M[0] * aScalar},
        {M[1] * aScalar},
        {M[2] * aScalar}
    };
}

Matrix3x3 Matrix3x3::operator+( const Matrix3x3& aOther ) const
{
    const Matrix3x3& M = *this;
    const Matrix3x3& N = aOther;
    return
    {
        {M[0] + N[0]},
        {M[1] + N[1]},
        {M[2] + N[2]}
    };
}

Vector3D Matrix3x3::operator*( const Vector3D& aVector ) const
{
    const Matrix3x3& M = *this;
    return
    {
        M[0].dot(aVector),
        M[1].dot(aVector),
        M[2].dot(aVector),
    };
}

Matrix3x3 Matrix3x3::getS( const float aX, const float aY )
{
    return
    {
        {aX,   0.0f, 0.0f},
        {0.0f,   aY, 0.0f},
        {0.0f, 0.0f, 1.0f},
    };
}

Matrix3x3 Matrix3x3::getT( const float aX, const float aY )
{
    return
    {
        {1.0f, 0.0f,   aX},
        {0.0f, 1.0f,   aY},
        {0.0f, 0.0f, 1.0f},
    };
}

Matrix3x3 Matrix3x3::getR( const float aAngleInDegree )
{
    float pi = std::numbers::pi_v<float>;
    float radians = aAngleInDegree * (pi / 180);
    return
    {
        {std::cos(radians), -std::sin(radians),   0.0f},
        {std::sin(radians),  std::cos(radians),   0.0f},
        {             0.0f,               0.0f, 1.0f},
    };
}

const Vector3D& Matrix3x3::row( size_t aRowIndex ) const
{
    assert(aRowIndex < 3);
    return fRows[aRowIndex];
}

const Vector3D Matrix3x3::column( size_t aColumnIndex ) const
{
    assert(aColumnIndex < 3);
    const Matrix3x3& M = *this;
    return {M[0][aColumnIndex], M[1][aColumnIndex], M[2][aColumnIndex]};
}

const Vector3D& Matrix3x3::operator[]( size_t aRowIndex ) const
{
    return row(aRowIndex); // assert is done in row.
}
