#include "Triangle.h"

Triangle::Triangle() : Polygon() {
    numVertices = 3;
    vertices = new Coordinate[numVertices];
}

bool Triangle::validate() {
    // To be implemented in derived classes
    return false;
}
