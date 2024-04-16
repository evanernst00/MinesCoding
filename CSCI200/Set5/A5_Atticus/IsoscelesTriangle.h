#ifndef ISOSCELESTRIANGLE_H
#define ISOSCELESTRIANGLE_H

#include "Triangle.h"

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle();
    virtual bool validate() override;
};

#endif // ISOSCELESTRIANGLE_H
