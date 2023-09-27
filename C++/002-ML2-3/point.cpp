#include "point.h"
#include <QPainter>

Point::Point()
    :Point(0,0,0) {}

Point::Point(int x, int y, int i)
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

void Point::draw(QPainter *painter)
{
    QPen pen(Qt::black);
    if(i < 5) pen.setWidth(1);
    else pen.setWidth(2);
    painter->setPen(pen);
    if(i%2 == 1)
    {
        painter->drawLine(x-(w-1), y-(w-1), x+w, y+w);
        painter->drawLine(x+w, y-(w-1), x-(w-1), y+w);
    }
    else
    {
        painter->drawLine(x-w, y-w, x+w, y+w);
        painter->drawLine(x+w, y-w, x-w, y+w);
    }
}
