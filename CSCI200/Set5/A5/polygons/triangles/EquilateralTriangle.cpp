#include <SFML/Graphics.hpp>

#include "./EquilateralTriangle.h"

using namespace sf;
using namespace std;

bool EquilateralTriangle::validate()
{
    // Check number of vertices
    if(_numVertices != 3)
    {
        return false;
    }

    // Compute side lengths
    float side1 = sqrt(pow(_vertices[0].x - _vertices[1].x, 2) + pow(_vertices[0].y - _vertices[1].y, 2)); // Compute the distance between vertex 0 and 1
    float side2 = sqrt(pow(_vertices[0].x - _vertices[2].x, 2) + pow(_vertices[0].y - _vertices[2].y, 2)); // Compute the distance between vertex 0 and 2
    float side3 = sqrt(pow(_vertices[1].x - _vertices[2].x, 2) + pow(_vertices[1].y - _vertices[2].y, 2)); // Compute the distance between vertex 1 and 2

    // Check that the sides are equal
    if(side1 != side2 || side1 != side3 || side2 != side3)
    {
        return false;
    }

    // Check that the sides are non-zero
    if(side1 == 0 || side2 == 0 || side3 == 0)
    {
        return false;
    }

    return true;
}
