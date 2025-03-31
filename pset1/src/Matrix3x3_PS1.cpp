#include "Matrix3x3.h"
#include <cassert>

bool Matrix3x3::operator==( const Matrix3x3& aOther ) const noexcept
{
    const Matrix3x3& M = *this;
    return M[0] == aOther[0] && M[1] == aOther[1] && M[2] == aOther[2];
}

Matrix3x3 Matrix3x3::operator*( const Matrix3x3& aOther ) const noexcept
{
    const Matrix3x3& M = *this;
    const Vector3D& col1 = aOther.column(0);
    const Vector3D& col2 = aOther.column(1);
    const Vector3D& col3 = aOther.column(2);
    return Matrix3x3
    (
        { M[0].dot(col1), M[0].dot(col2), M[0].dot(col3) },
        { M[1].dot(col1), M[1].dot(col2), M[1].dot(col3) },
        { M[2].dot(col1), M[2].dot(col2), M[2].dot(col3) }
    );
}

Matrix3x3 Matrix3x3::transpose() const noexcept
{
    const Matrix3x3& M = *this;
    return Matrix3x3(M.column(0), M.column(1), M.column(2));
}

float Matrix3x3::det() const noexcept
{
    const Matrix3x3& M = *this;
    return 
        M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1]) -
        M[0][1] * (M[1][0] * M[2][2] - M[1][2] * M[2][0]) +
        M[0][2] * (M[1][0] * M[2][1] - M[1][1] * M[2][0]); 
}

bool Matrix3x3::hasInverse() const noexcept
{
    return det() != 0;
}

Matrix3x3 Matrix3x3::inverse() const noexcept
{

    assert(hasInverse());

    const Matrix3x3& M = *this;
    float reciprocal = 1 / det();

    return Matrix3x3
    (
    //                                         |                                      |                                       |
        { M[1][1] * M[2][2] - M[1][2] * M[2][1], M[0][2] * M[2][1] - M[0][1] * M[2][2], M[0][1] * M[1][2] - M[0][2] * M[1][1]},
        { M[1][2] * M[2][0] - M[1][0] * M[2][2], M[0][0] * M[2][2] - M[0][2] * M[2][0], M[0][2] * M[1][0] - M[0][0] * M[1][2]},
        { M[1][0] * M[2][1] - M[1][1] * M[2][0], M[0][1] * M[2][0] - M[0][0] * M[2][1], M[0][0] * M[1][1] - M[0][1] * M[1][0]}
    ) * reciprocal;

}

std::ostream& operator<<( std::ostream& aOStream, const Matrix3x3& aMatrix )
{
    return aOStream << "[" << aMatrix[0].toString() << "," << aMatrix[1].toString() << "," << aMatrix[2].toString() << "]";
}
