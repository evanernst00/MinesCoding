#include "./Triangle.h"

using namespace std;

Triangle::Triangle() : Polygon()
{
    _numVertices = 3;
    _vertices = new Coordinate[_numVertices];
};
