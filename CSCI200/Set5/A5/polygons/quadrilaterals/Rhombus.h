#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <SFML/Graphics.hpp>
#include "../../Coordinate.hpp"
#include "../../Polygon.h"
#include "../Quadrilateral.h"

// Define the Rhombus class
class Rhombus : public Quadrilateral {
public:
    bool validate() override;
};

#endif // RHOMBUS_H
