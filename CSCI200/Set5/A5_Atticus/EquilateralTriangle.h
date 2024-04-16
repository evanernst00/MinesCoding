#ifndef EQUILATERALTRIANGLE_H
#define EQUILATERALTRIANGLE_H

#include "Triangle.h"

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle();
    virtual bool validate() override;
};

#endif // EQUILATERALTRIANGLE_H
