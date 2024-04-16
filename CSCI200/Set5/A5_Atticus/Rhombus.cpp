#include "Rhombus.h"
#include <cmath>

Rhombus::Rhombus() : Quadrilateral() {}

bool Rhombus::validate() {
    double side1 = sqrt(pow(vertices[1].x - vertices[0].x, 2) + pow(vertices[1].y - vertices[0].y, 2));
    double side2 = sqrt(pow(vertices[2].x - vertices[1].x, 2) + pow(vertices[2].y - vertices[1].y, 2));
    double side3 = sqrt(pow(vertices[3].x - vertices[2].x, 2) + pow(vertices[3].y - vertices[2].y, 2));
    double side4 = sqrt(pow(vertices[0].x - vertices[3].x, 2) + pow(vertices[0].y - vertices[3].y, 2));

    return side1 > 0 && side2 > 0 && side3 > 0 && side4 > 0 &&
           side1 == side3 && side2 == side4;
}