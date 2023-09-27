#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    Point(int x, int y, int i);

    int getX() const;
    void setX(int newX);

    int getY() const;
    void setY(int newY);

    int getW() const;
    void setW(int newW);

    int getI() const;
    void setI(int newI);

private:
    int x,y,w,i;
};

#endif // POINT_H
