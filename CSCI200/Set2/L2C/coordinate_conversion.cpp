#include <cmath>
#include "coordinate_conversion.hpp"

void polar_to_cartesian(const double radius, const double angle, double* pXCoordinate, double* pYCoordinate)
{
    *pXCoordinate = radius * cos(angle);
    *pYCoordinate = radius * sin(angle);
}

void cartesian_to_polar(const double xCoordinate, const double yCoordinate, double* pRadius, double* pAngle)
{
    *pRadius = sqrt(xCoordinate*xCoordinate + yCoordinate*yCoordinate);
    *pAngle = atan(yCoordinate/xCoordinate);
}
