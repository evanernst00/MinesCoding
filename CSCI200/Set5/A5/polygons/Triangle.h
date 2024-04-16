#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../Coordinate.hpp"
#include "../Polygon.h"

class Triangle : public Polygon
{
public:
    /**
     * @brief Sets the number of vertices to be three and allocates the vertex array to hold three coordinates
     * 
     */
    Triangle();
};

#endif//TRIANGLE_H