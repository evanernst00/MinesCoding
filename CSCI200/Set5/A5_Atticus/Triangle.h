#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"

class Triangle : public Polygon {
public:
    Triangle();
    virtual bool validate() override;
};

#endif // TRIANGLE_H
