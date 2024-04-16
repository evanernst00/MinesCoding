#ifndef COORDINATE_HPP
#define COORDINATE_HPP

struct Coordinate
{
    Coordinate();
    Coordinate(int x, int y);
    int x;
    int y;
};

Coordinate::Coordinate()
{
    x = 0;
    y = 0;
}

Coordinate::Coordinate(int x, int y)
{
    this->x = x;
    this->y = y;
}

#endif // COORDINATE_HPP