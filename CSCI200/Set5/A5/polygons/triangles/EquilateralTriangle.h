#ifndef EQUILATERALTRIANGLE_H
#define EQUILATERALTRIANGLE_H

#include "../../Coordinate.hpp"
#include "../Triangle.h"

class EquilateralTriangle : public Triangle
{
public:
    bool validate() override;
};

#endif // EQUILATERALTRIANGLE_H