/*
1.	Подсчет числа слов в файле.
Дан текстовый файл (BogeyBeast.txt).
Подсчитать число слов в этом файле, используя средства библиотеки stdio.
Разделителями слов считать все нетекстовые символы, включая знаки препинания – ‘,’ ‘.’ ‘!’ ‘?’ и переход на новую строку.
*/

#include <stdio.h>

int main()
{
    char *file = "D:/BogeyBeast.txt";
    FILE *f = fopen(file,"r");
    if (!f) {printf("can't open %s\n",file); return 1;}
    int k=0,a=0;
    char s;
    while ((s=fgetc(f)) != EOF)
    {
        if ((s >= 'A')&&(s <= 'Z')||(s >= 'a')&&(s <= 'z')||(s == '-')||(s == 39 /* апостроф */)) a++;
        else
        {
            if (a != 0) k++;
            a=0;
        }
    }
    fclose(f);
    printf("%d\n",k);
    return 0;
}
