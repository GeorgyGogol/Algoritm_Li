#include "Point.h"
#include "pch.h"

using namespace algo;

Point::Point(int x, int y) :
    X(x), Y(y)
{
}

Point::Point(unsigned int x, unsigned int y) :
    X(int(x)), Y(int(y))
{
}

bool Point::operator==(const Point& right) const noexcept
{
    return X == right.X && Y == right.Y;
}

int Point::getX() const
{
    return X;
}

int Point::getY() const
{
    return Y;
}
