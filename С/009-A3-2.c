/*
Написать программу, которая выводит свой текст на экран задом наперед, используя библиотеку stdio.
То есть первым символом на экране будет выведен последний символ кода программы,
вторым символом – предпоследний и так далее.
*/
#include <stdio.h>
#define K 512

int main()
{
    char *file = "D:/main.c";
    FILE *f = fopen(file,"r");
    if (!f) {printf("can't open %s\n",file); return 1;}
    int i=0;
    char s, a[K]={0};
    while ((s=fgetc(f)) != EOF)
    {
        a[i++]=s;
    }
    fclose(f);
    while (i--) printf("%c",a[i]);
    printf("\n");
    return 0;
}
