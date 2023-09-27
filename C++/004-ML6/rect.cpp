#include "rect.h"
#include "point.h"
#include <QPainter>

Rect::Rect()
    :x1(0), x2(0), y1(0), y2(0), c(0) {}

Rect::Rect(Point *p1, Point *p2)
{
    x1 = std::min(p1->getX(), p2->getX());
    y1 = std::min(p1->getY(), p2->getY());
    x2 = std::max(p1->getX(), p2->getX());
    y2 = std::max(p1->getY(), p2->getY());
    c = 0;
}

Rect::Rect(Rect *r1, Rect *r2, int c)
    :c(c)
{
    x1 = std::max(r1->getX1(), r2->getX1());
    x2 = std::min(r1->getX2(), r2->getX2());
    y1 = std::max(r1->getY1(), r2->getY1());
    y2 = std::min(r1->getY2(), r2->getY2());
}

void Rect::draw(QPainter *painter)
{
    QPen pen(Qt::black);
    pen.setWidth(1);
    painter->setPen(pen);
    QBrush brush(Qt::black);
    if(c > 1)
    {
        if(c == 2)
            brush = Qt::red;
        else if(c == 3)
            brush = Qt::yellow;
        else if(c == 4)
            brush = Qt::green;
        else if(c == 5)
            brush = Qt::blue;;
    }
    else brush = QBrush();
    painter->setBrush(brush);
    painter->drawRect(x1,y1,x2-x1,y2-y1);
}

bool Rect::belong(Point *p)
{
    if((p->getX() < x1) || (p->getX() > x2) || (p->getY() < y1) || (p->getY() > y2)) return false;
    else return true;
}

int Rect::getX1() const
{
    return x1;
}

int Rect::getY1() const
{
    return y1;
}

int Rect::getX2() const
{
    return x2;
}

int Rect::getY2() const
{
    return y2;
}

int Rect::getC() const
{
    return c;
}
