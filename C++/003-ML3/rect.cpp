#include "rect.h"
#include "point.h"
#include <QPainter>

Rect::Rect(Point *p1, Point *p2)
{
    x1 = std::min(p1->getX(), p2->getX());
    y1 = std::min(p1->getY(), p2->getY());
    x2 = std::max(p1->getX(), p2->getX());
    y2 = std::max(p1->getY(), p2->getY());
}

void Rect::draw(QPainter *painter)
{
    QPen pen(Qt::black);
    pen.setWidth(1);
    painter->setPen(pen);
    QBrush brush(Qt::white);
    painter->setBrush(brush);
    painter->drawRect(x1,y1,x2-x1,y2-y1);
}

bool Rect::belong(Point *p)
{
    if((p->getX() < x1) || (p->getX() > x2) || (p->getY() < y1) || (p->getY() > y2)) return false;
    else return true;
}
