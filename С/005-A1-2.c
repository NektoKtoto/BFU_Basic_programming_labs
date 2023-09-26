/*
2.	Слово называется словом палиндромом, если оно читается одинаково слева направо и справа налево, например, “ABBA” – слово палиндром.
Написать функцию palindrom(char *), которая определяет, является ли данная ей строка словом палиндромом.
*/

#include <stdio.h>

int palindrom(char *s)
{
    int p=1,l=0;
    while (s[l++]);
    l--;
    for(int i=0;i < l/2;i++)
        if(s[i] != s[l-i-1])
            p=0;
    return p;
}

int main()
{
    char *a="abba";
    if(palindrom(a)) printf("this is palindrome\n");
    else printf("this is NOT a palindrome\n");
    return 0;
}
