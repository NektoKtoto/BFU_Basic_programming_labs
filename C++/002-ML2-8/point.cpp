#include "point.h"
#include <QPainter>

Point::Point()
    :Point(0,0) {}

Point::Point(int x, int y)
    :x(x), y(y), s(1) {}

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

int Point::getS() const
{
    return s;
}

void Point::setS(int newS)
{
    s = newS;
}

int &Point::rs()
{
    return s;
}

void Point::draw(QPainter *painter)
{
    QPen pen(Qt::black);
    pen.setWidth(s);
    painter->setPen(pen);
    painter->drawLine(x-s, y-s, x+s, y+s);
    painter->drawLine(x+s, y-s, x-s, y+s);
}

int Point::distance2(const Point &point)
{
    return (x - point.getX())*(x - point.getX())+(y - point.getY())*(y - point.getY());
}
