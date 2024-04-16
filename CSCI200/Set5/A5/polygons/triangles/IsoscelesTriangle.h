#ifndef ISOSCELESTRIANGLE_H
#define ISOSCELESTRIANGLE_H

#include "../../Coordinate.hpp"
#include "../Triangle.h"

class IsoscelesTriangle : public Triangle
{
public:
    bool validate() override;
};

#endif // ISOSCELESTRIANGLE_H