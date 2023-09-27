#ifndef POINT_H
#define POINT_H

class QPainter;

class Point
{
public:
    Point();
    Point(int x, int y);

    int getX() const;
    void setX(int newX);

    int getY() const;
    void setY(int newY);

    int getS() const;
    void setS(int newS);
    int &rs();

    void draw(QPainter *painter);

    int distance2(const Point &point);

private:
    int x,y,s;
};

#endif // POINT_H
