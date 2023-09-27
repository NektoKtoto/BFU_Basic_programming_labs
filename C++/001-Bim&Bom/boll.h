#ifndef BOLL_H
#define BOLL_H


class Boll
{
public:
    Boll();
    int x, y, dx, dy, r;
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    int getDx() const;
    void setDx(int newDx);
    int getDy() const;
    void setDy(int newDy);
    int getR() const;
    void setR(int newR);
};

#endif // BOLL_H
