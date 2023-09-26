/*
Скобки.
Написать функцию, которая получает на вход строку, содержащую арифметическое выражение со скобками,
и определяет, правильно ли расставлены скобки.
Например, в выражении «2+3*(a-b)» скобки расставлены правильно,
а в выражениях «((3+2)» и «)(3+2)» нет.
Скобки могут быть вложенными.
Проверить скобочные выражения “((a+8)*10-4)”, “x*(2+2))”, “2+)a-b)”
*/

#include <stdio.h>

int skobki(char *s)
{
    int a=0;
    for (int i=0;s[i];i++)
    {
        if (s[i] == '(') a++;
        else if (s[i] == ')') a--;
        if (a < 0) break;
    }
    if (a == 0) return 1;
    else return 0;
}

int main()
{
    char *a="2+)a-b";
    if (skobki(a)) printf("brackets are correctly placed\n");
    else printf("brackets are NOT placed correctly\n");
}
