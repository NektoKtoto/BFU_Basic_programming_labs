/*
& - and - умножение
| - or - сложение
^ - xor - сложение разных { 1^1=0 1^0=1 }
~ - инверсия { ~a }
0xA - 16-ичная СС

a >> b - при сдвиге заполняется самым левым битом - 10011 >> 2 = 11100
a << b - при сдвиге заполняется 0 - 1011 << 2 = 1100
b - на сколько сдвинуть
a << n = a*2^n
a >> n = a/2^n
*/

/*
Найти максимальное число из всех возможных сдвигов числа
*/

#include <stdio.h>

int main()
{
    int n = 17,
        i;
    for(i=31; i>-1; i--)
        if((n >> i) & 0x1) break;
    int a[32]={0},
        b = i+1,
        d=0;
    for(int j=0; j<=i; j++) a[j] = (n >> j) & 0x1;
    for(b; b>0; b--)
    {
        int c = a[i];
        for(int j=i; j>0; j--) a[j]=a[j-1];
        a[0] = c;
        c=0;
        for(int j=i; j>=0; j--) c += a[j]*(1 << j);
        if (c>d) d=c;
    }
    printf(" %d\n",d);
    return 0;
}

/*
Перевод в 2-ую и 16-ую СС
*/

#include <stdio.h>

int main()
{
    int n=29;
    printf(" 2: ");
    for(int i=31; i>-1; i--) printf("%d", (n >> i) & 0x1);
    printf("\n16: ");
    for(int i=7; i>-1; i--)
    {
        int a=((n >> i*4) & 0xF);
        if(a==15) printf("%c",'F');
        else if(a==14) printf("%c",'E');
        else if(a==13) printf("%c",'D');
        else if(a==12) printf("%c",'C');
        else if(a==11) printf("%c",'B');
        else if(a==10) printf("%c",'A');
        else printf("%d",a);
    }
    printf("\n");
    return 0;
}