#include <SFML/Graphics.hpp>

#include "./Rhombus.h"
#include "../triangles/IsoscelesTriangle.h"

using namespace sf;
using namespace std;

bool Rhombus::validate()
{
    // Compute side lengths
    float side1 = sqrt(pow(_vertices[0].x - _vertices[1].x, 2) + pow(_vertices[0].y - _vertices[1].y, 2));
    float side2 = sqrt(pow(_vertices[1].x - _vertices[2].x, 2) + pow(_vertices[1].y - _vertices[2].y, 2));
    float side3 = sqrt(pow(_vertices[2].x - _vertices[3].x, 2) + pow(_vertices[2].y - _vertices[3].y, 2));
    float side4 = sqrt(pow(_vertices[3].x - _vertices[0].x, 2) + pow(_vertices[3].y - _vertices[0].y, 2));

    // Check that all four sides are equal
    if (side1 != side2 || side1 != side3 || side1 != side4) {
        return false;
    }

    // Check that the four sides form two isosceles triangles (comprised of vertices 0, 1, 2 and vertices 0, 2, 3)
    IsoscelesTriangle t1;
    t1.setCoordinate(0, _vertices[0]);
    t1.setCoordinate(1, _vertices[1]);
    t1.setCoordinate(2, _vertices[2]);

    IsoscelesTriangle t2;
    t2.setCoordinate(0, _vertices[0]);
    t2.setCoordinate(1, _vertices[2]);
    t2.setCoordinate(2, _vertices[3]);

    if (!t1.validate() || !t2.validate()) {
        return false;
    }

    return true;

}
