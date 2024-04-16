#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <SFML/Graphics.hpp>
#include "../Coordinate.hpp"
#include "../Polygon.h"

class Quadrilateral : public Polygon
{
public:
    /**
     * @brief Sets the number of vertices to be four and allocates the vertex array to hold four coordinates
     * 
     */
    Quadrilateral();
};

#endif//QUADRILATERAL_H