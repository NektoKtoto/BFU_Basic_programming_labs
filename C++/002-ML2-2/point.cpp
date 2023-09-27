#include "point.h"

Point::Point()
    :Point(0,0,0) {}

Point::Point(int x, int y,int i)
    :x(x), y(y), w(1), i(i) {}

int Point::getX() const
{
    return x;
}

void Point::setX(int newX)
{
    x = newX;
}

int Point::getY() const
{
    return y;
}

void Point::setY(int newY)
{
    y = newY;
}

int Point::getW() const
{
    return w;
}

void Point::setW(int newW)
{
    w = newW;
}

int Point::getI() const
{
    return i;
}

void Point::setI(int newI)
{
    i = newI;
}
