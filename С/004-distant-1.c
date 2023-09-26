/*
Указатели и массивы. Адресная арифметика
*/

#include <stdio.h>

void f(int m[]) {}
// void f(int *m) {}

int main()
{
    int a=1,y=2,z[10];
    int *p,*q;
    double *w;
    void *v;
  //void - указатель без типа
    p=&a;
  // *p===a
    *p=0;   //единственный доступный int
  // a=0
    p=&z[5];
    p=NULL;
    q=p;
    w=(double*)p;
    v=p;

    p++;p--;
    p=&z[0];
    p[0]; p[1];
  // z[i]===*(p+i)
    p=&z[5];
  //p[-1]===z[4]
  // p - указател на подмассив

//Функции и указатели

    f(z);
    f(p);
    return 0;
}
