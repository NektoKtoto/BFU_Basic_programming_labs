/*
3.	Вхождение подстроки в строку.
Написать функцию strstr(char *s1, char *s2), которая возвращает указатель char * на первое вхождение подстроки s2 в строку s1.
Если s2 не найдена, то возвращается NULL.
Например strstr(“ABABABA”,”BA”) должна вернуть указатель на вторую букву в первой строке, а не на четвертую или шестую.
*/

#include <stdio.h>

int len(char *s)
{
    int l=0;
    while (s[l++]);
    return l-1;
}

char* strstr(char *s1, char *s2)
{
    int ls1=len(s1),ls2=len(s2);
    int c=-1;
    for(int i=0;i < ls1-ls2;i++)
    {
        int a=1;
        for(int j=0;j < ls2;j++)
            if(s1[i+j] != s2[j]) a=0;
        if(a)
        {
            c=i;
            break;
        }
    }
    if(c<0) return NULL;
    else
    {
        for(int i=0;i<c;i++) s1++;
        return s1;
    }
}

int main()
{
    char *a="abababab";
    char *b="ba";
    char *c=strstr(a,b);
    printf("%s\n",c);
    return 0;
}
