#include <sstream>
#include "Vector3D.h"
#include <cmath>

bool Vector3D::operator==( const Vector3D& aOther ) const noexcept
{
    return std::abs(x() - aOther.x()) < eps &&
           std::abs(y() - aOther.y()) < eps &&
           std::abs(w() - aOther.w()) < eps;
}

std::string Vector3D::toString() const noexcept
{
    std::stringstream ss;
    ss << "[" << x() << "," << y() << "," << w() << "]";
    return ss.str();
}

