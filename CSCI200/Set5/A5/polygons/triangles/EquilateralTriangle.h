#ifndef EQUILATERALTRIANGLE_H
#define EQUILATERALTRIANGLE_H

#include <SFML/Graphics.hpp>
#include "../../Coordinate.hpp"
#include "../../Polygon.h"
#include "../Triangle.h"

class EquilateralTriangle : public Triangle
{
public:
    bool validate() override;
};

#endif // EQUILATERALTRIANGLE_H