#include "Polygon.h"

Polygon::Polygon() noexcept
    :fNumberOfVertices(0)
{
}

void Polygon::readData( std::istream& aIStream )
{
    for (fNumberOfVertices = 0; 
	 fNumberOfVertices < MAX_VERTICES && 
	 aIStream >> fVertices[fNumberOfVertices]; 
	 fNumberOfVertices++);
}

size_t Polygon::getNumberOfVertices() const noexcept
{
    return fNumberOfVertices;
}

const Vector2D& Polygon::getVertex( size_t aIndex ) const
{
    return fVertices[aIndex];
}

float Polygon::getPerimeter() const noexcept
{
    float lPerimeter = 0.0f;
    for (size_t i = 0; i < fNumberOfVertices; i++)
    {
	lPerimeter += (fVertices[(i + 1) % fNumberOfVertices] - fVertices[i]).length();
    }
    return lPerimeter;
}

Polygon Polygon::scale( float aScalar ) const noexcept
{
    Polygon result = *this;
    for (size_t i = 0; i < fNumberOfVertices; i++)
    {
	result.fVertices[i] = fVertices[i] * aScalar;
    }
    return result;
}
