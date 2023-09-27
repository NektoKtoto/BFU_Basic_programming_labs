#include "point.h"
#include <QPainter>

Point::Point(int x, int y)
    :x(x), y(y) {}

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

void Point::draw(QPainter *painter)
{
    QPen pen(Qt::black);
    pen.setWidth(1);
    painter->setPen(pen);
    painter->drawLine(x-1, y-1, x+1, y+1);
    painter->drawLine(x+1, y-1, x-1, y+1);
}

int Point::distance2(const Point &point)
{
    return (x - point.getX())*(x - point.getX())+(y - point.getY())*(y - point.getY());
}
