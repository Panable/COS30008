
// COS30008, 2025

#include <iostream>

#include "Particle2D.h"

int main()
{
    
	Vector2D vecA(1.0, 2.0);
	Vector2D vecB = vecA + std::cin;
    std::cout << vecB << std::endl; 

    return 0;
    std::cout << "A simple particle simulation\n" << std::endl;
    
    Particle2D obj{ 0.0f,
                    10.0f,
                    Vector2D( 10.0f, 20.0f ),
                    Vector2D( 4.0f, 15.0f ),
                    Vector2D( 0.0f, -0.1f )
                  };
    
    do
    {
        std::cout << obj << std::endl;

        obj.update();
    } while ( obj.position().y() >= 20.0f );

    std::cout << obj << std::endl;

    return 0;
}
