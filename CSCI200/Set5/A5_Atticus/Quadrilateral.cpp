#include "Quadrilateral.h"

Quadrilateral::Quadrilateral() : Polygon() {
    numVertices = 4;
    vertices = new Coordinate[numVertices];
}