#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Quadrilateral.h"

class Rhombus : public Quadrilateral {
public:
    Rhombus();
    virtual bool validate() override;
};

#endif // RHOMBUS_H
