#include <SFML/Graphics.hpp>
using namespace sf;

#include "./Triangle.h"

using namespace std;

Triangle::Triangle()
{
    _numVertices = 3;
    _vertices = new Coordinate[_numVertices];
};
