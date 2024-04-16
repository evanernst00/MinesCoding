#ifndef POLYGON_H
#define POLYGON_H

#include <SFML/Graphics.hpp>
#include "Coordinate.h"

class Polygon {
public:
    Polygon();
    virtual ~Polygon();
    void setColor(const sf::Color color);
    void draw(sf::RenderTarget& window);
    void setCoordinate(int idx, Coordinate coord);
    virtual bool validate() = 0;

protected:
    short numVertices;
    Coordinate* vertices;

private:
    sf::Color color;
};

#endif // POLYGON_H
