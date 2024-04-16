#ifndef SCALENETRIANGLE_H
#define SCALENETRIANGLE_H

#include "../../Coordinate.hpp"
#include "../Triangle.h"

class ScaleneTriangle : public Triangle
{
public:
    bool validate() override;
};

#endif // SCALENETRIANGLE_H
