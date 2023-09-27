#include "new.h"
#include <qDebug>

int main()
{
    New t1(13, 50), t2("17:50"), t3=t1+5;
    qDebug("%d", t1-t2);
    t3.print();
    return 0;
}
