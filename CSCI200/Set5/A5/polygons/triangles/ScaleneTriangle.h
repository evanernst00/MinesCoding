#ifndef SCALENETRIANGLE_H
#define SCALENETRIANGLE_H

#include <SFML/Graphics.hpp>
#include "../../Coordinate.hpp"
#include "../../Polygon.h"
#include "../Triangle.h"

class ScaleneTriangle : public Triangle
{
public:
    bool validate() override;
};

#endif // SCALENETRIANGLE_H
