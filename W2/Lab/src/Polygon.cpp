#include "Polygon.h"

Polygon::Polygon() noexcept
    :fNumberOfVertices(MAX_VERTICES)
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

/* Starting at i=0 the first vertex vi , we grab the next vertex vi+1 and build a new vector
segment = vi+1 – vi . The length of the segment is added to the perimeter of the
polygon. We need to run this loop for all elements in fVertices. You may use the
modulus operator for the next vertex to guarantee that the value of loop variable i is
in the interval [0, fNumberOfVertices) */
float Polygon::getPerimeter() const noexcept
{
    float perimeter = 0.0f;
    for (size_t i = 0; i < fNumberOfVertices; i++)
    {
	const Vector2D& current = fVertices[i];
	const Vector2D& next = fVertices[ (i + 1) % fNumberOfVertices ];

	Vector2D segment = next - current;
	perimeter += segment.length();
    }
    return perimeter;
}

Polygon Polygon::scale( float aScalar ) const noexcept
{
    Polygon result = *this;
    for(Vector2D& var : result.fVertices)
    {
	var = var * aScalar;
    }

    return result;
}
