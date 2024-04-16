#ifndef ISOSCELESTRIANGLE_H
#define ISOSCELESTRIANGLE_H

#include <SFML/Graphics.hpp>
#include "../../Coordinate.hpp"
#include "../../Polygon.h"
#include "../Triangle.h"

class IsoscelesTriangle : public Triangle
{
public:
    bool validate() override;
};

#endif // ISOSCELESTRIANGLE_H