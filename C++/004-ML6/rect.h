#ifndef RECT_H
#define RECT_H

class QPainter;
class Point;

class Rect
{
public:
    Rect();
    Rect(Point *p1, Point *p2);
    Rect(Rect *r1, Rect *r2, int c);

    void draw(QPainter *painter);

    bool belong(Point *p);

    int getX1() const;

    int getY1() const;

    int getX2() const;

    int getY2() const;

    int getC() const;

private:
    int x1,y1,x2,y2,c;
};

#endif // RECT_H
