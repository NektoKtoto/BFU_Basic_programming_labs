#include "new.h"
#include <qDebug>

New::New()
    :New(0, 0) {}

New::New(int h, int m)
    :h(h), m(m) {}

New::New(char *s)
{
    h = (s[0]-'0')*10 + s[1]-'0';
    m = (s[3]-'0')*10 + s[4]-'0';
}

void New::print()
{
    qDebug("%d%d:%d%d", h/10, h%10, m/10, m%10);
}

int New::operator -(New t)
{
    return t.h >= h ? (t.h-h)*60 + t.m-m : (*this-New(23, 59))+1 + (New(0, 0)-t);
}

New New::operator +(int dm)
{
    return New(h+(m+dm)/60 > 23 ? h+(m+dm)/60-24 : h+(m+dm)/60, (m+dm%60)/60 == 1 ? m+dm%60-60 : m+dm%60);
}
