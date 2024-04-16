#ifndef COORDINATE_HPP
#define COORDINATE_HPP

struct Coordinate
{
    Coordinate();
    Coordinate(double x, double y);
    double x;
    double y;
};

Coordinate::Coordinate()
{
    x = 0;
    y = 0;
}

Coordinate::Coordinate(double x, double y)
{
    this->x = x;
    this->y = y;
}

#endif // COORDINATE_HPP