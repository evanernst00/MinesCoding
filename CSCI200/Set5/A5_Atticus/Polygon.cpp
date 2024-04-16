#include "Polygon.h"

Polygon::Polygon() : numVertices(0), vertices(nullptr), color(sf::Color::White) {}

Polygon::~Polygon() {
    delete[] vertices;
}

void Polygon::setColor(const sf::Color color) {
    this->color = color;
}

void Polygon::draw(sf::RenderTarget& window) {
    sf::ConvexShape shape;
    shape.setFillColor(color);
    shape.setPointCount(numVertices);
    for (int i = 0; i < numVertices; ++i) {
        shape.setPoint(i, sf::Vector2f(vertices[i].x, vertices[i].y));
    }
    window.draw(shape);
}

void Polygon::setCoordinate(int idx, Coordinate coord) {
    vertices[idx] = coord;
}
