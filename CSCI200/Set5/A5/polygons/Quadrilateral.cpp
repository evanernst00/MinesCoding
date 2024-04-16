#include <SFML/Graphics.hpp>
using namespace sf;

#include "./Quadrilateral.h"

using namespace std;

Quadrilateral::Quadrilateral()
{
    _numVertices = 4;
    _vertices = new Coordinate[_numVertices];
};
