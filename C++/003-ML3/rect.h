#ifndef RECT_H
#define RECT_H

class QPainter;
class Point;

class Rect
{
public:
    Rect(Point *p1, Point *p2);

    void draw(QPainter *painter);

    bool belong(Point *p);

private:
    int x1,y1,x2,y2;
};

#endif // RECT_H
