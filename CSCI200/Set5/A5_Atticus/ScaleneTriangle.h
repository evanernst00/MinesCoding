#ifndef SCALENETRIANGLE_H
#define SCALENETRIANGLE_H

#include "Triangle.h"

class ScaleneTriangle : public Triangle {
public:
    ScaleneTriangle();
    virtual bool validate() override;
};

#endif // SCALENETRIANGLE_H
