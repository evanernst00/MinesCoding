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

Polygon::~Polygon()
{
    delete[] _vertices;
}

void Polygon::setColor(const sf::Color color)
{
    _color = color;
}

void Polygon::draw(sf::RenderTarget& window)
{
    ConvexShape shape;
    shape.setPointCount(_numVertices);
    shape.setFillColor(_color);

    for(int i = 0; i < _numVertices; i++)
    {
        shape.setPoint(i, Vector2f(_vertices[i].x, _vertices[i].y));
    }

    window.draw(shape);
}

void Polygon::setCoordinate(int idx, Coordinate coord)
{
    _vertices[idx] = coord;
}

Coordinate Polygon::getCoordinate(int idx) const
{
    return _vertices[idx];
}

sf::Color Polygon::getColor() const
{
    return _color;
}
