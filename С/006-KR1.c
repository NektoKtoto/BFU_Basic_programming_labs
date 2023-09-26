/*
Написать функцию Calc
int Calc(char *exp);
которая вычисляет значение “x” в выражениях вида 2+x=7 или x=5/2.
То есть в выражении есть 3 позиции, в которых может находится либо цифра от 1 до 9, либо переменная x.
В качестве операций могут выступать умножение *, целочисленное деление /, сложение + вычитание -, взятие остатка % или знак равенства.
То есть шаблон выражения определяется как ZꚚZꚚZ, где Z={0,1,2,4,4,6,7,8,9, x}, а Ꚛ={+,-,*,/,%,=}.
Z – всегда цифра или х, то есть Z не может быть, например, числом 25, то есть выражение всегда занимает ровно 5 позиций.
Вычисленное значение x, может быть двузначным числом, например “x=8*8” ответ x=64.
Невычислимые выражения типа x*2=3 или x/0=5 или неоднозначные типа 7%x=1 (ответ может быть x=2 или x=6) не допускаются и не должны рассматриваться.
При этом x=7/3 – вычислимое выражение. По правилам целочисленного деления 7/3=2.
*/

#include <stdio.h>

int calc(char *exp)
{
    int c1=10, c2, pz, pr, px, x;
    char z;
    for (int i=0; exp[i] != '\0'; i++)
    {
        if ((exp[i] >= '0')&&(exp[i] <= '9'))
            if (c1 == 10) {c1 = exp[i]-'0'; continue;}
            else {c2 = exp[i]-'0'; continue;}
        if (exp[i] == '=') {pr=i; continue;}
        else if ((exp[i] > '$')&&(exp[i] < '0')) {z = exp[i]; pz=i; continue;}
        if (exp[i] == 'x') px=i;
    }
    switch (z)
    {
    case '+':
        if (px > pr)
            if (pz > pr) x = c1-c2;
            else x = c1+c2;
        else
            if (pz > pr) x = c1+c2;
            else x = c2-c1;
        break;
    case '-':
        if (px > pr)
            if (pz > pr)
                if (px > pz) x = c2-c1;
                else x = c1+c2;
            else x = c1-c2;
        else
            if (pz > pr) x = c1-c2;
            else
                if (px > pz) x = c1-c2;
                else x = c1+c2;
        break;
    case '*':
        if (px > pr)
            if (pz > pr)
                if (c1%c2 == 0) x = c1/c2;
                else x=100;
            else x = c1*c2;
        else
            if (pz > pr) x = c1*c2;
            else
                if (c2%c1 == 0) x = c2/c1;
                else x=100;
        break;
    case '/':
        if (px > pr)
            if (pz > pr)
                if (px > pz)
                    if (c2%c1 == 0) x = c2/c1;
                    else x=100;
                else x = c1*c2;
            else x = c1/c2;
        else
            if (pz > pr) x = c1/c2;
            else
                if (px > pz)
                    if (c1%c2 == 0) x = c1/c2;
                    else x=100;
                else x = c1*c2;
        break;
    case '%':
        if (px > pr)
            if (pz > pr) x=150;
            else x = c1%c2;
        else
            if (pz > pr) x = c1%c2;
            else x=150;
    }
    return x;
}

int main()
{
    char *a[] = {"2+x=5", "x+2=5", "5=x+2", "5=2+x", "5+2=x", "x=5+2",
                 "2-x=5", "x-2=5", "5=x-2", "5=2-x", "5-2=x", "x=5-2",
                 "2*x=5", "x*2=5", "5=x*2", "5=2*x", "5*2=x", "x=5*2", "2*x=6", "x*2=6", "6=x*2", "6=2*x",
                 "7/x=3", "3=7/x", "x/3=7", "7=x/3", "x=7/3", "7/3=x", "9/x=3", "3=9/x",
                 "7%x=3", "3=7%x", "x%3=7", "7=x%3", "x=7%3", "7%3=x"};
    int l = sizeof(a) / sizeof(char *);
    for (int i=0; i<l; i++)
    {
        int b = calc(a[i]);
        if (b < 100) printf("%s x=%d\n", a[i], calc(a[i]));
        else
            if (b == 100) printf("%s - uncomputable expression\n", a[i]);
            else printf("%s - ambiguous expression\n", a[i]);
    }
}
