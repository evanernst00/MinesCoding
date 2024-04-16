#include <SFML/Graphics.hpp>
using namespace sf;

#include "Polygon.h"

using namespace std;

Polygon::Polygon()
{
    _color = sf::Color::White;
    _numVertices = 0;
    _vertices = nullptr;
}
