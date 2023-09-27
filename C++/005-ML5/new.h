#ifndef NEW_H
#define NEW_H

class New
{
public:
    New();
    New(int h, int m);
    New(char *s);

    void print();

    int operator -(New t);

    New operator +(int dm);

private:
    int h, m;
};

#endif // NEW_H
