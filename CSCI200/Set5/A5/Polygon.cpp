#include <SFML/Graphics.hpp>

#include "Polygon.h"

using namespace sf;
using namespace std;

Polygon::Polygon()
{
    _color = sf::Color::White;
    _numVertices = 0;
    _vertices = nullptr;
}
