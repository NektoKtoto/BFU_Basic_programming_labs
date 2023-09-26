/*
Указатели на символьные массивы
*/

#include <stdio.h>

int strlen(char *s)
{
    int count=0;
    while(s[count])
        ++count;
    return count;
}
// dst[]=source[]
void strcpy(char *dst, char *source)
{
    int i;
    for(i=0;source[i];i++)
        dst[i]=source[i];
    dst[i]='\0';
}

int main()
{
    char *ss="abcd"; //в сишной строке всегда в конце нулевой символ, когда в массиве можно без него
    char abcd[]={'a','b','c','d','e','\0'};
    char buf[80];
    strcpy(buf,ss);
    printf("%s\n",abcd);
    printf("len=%d",strlen(abcd));
    char abcd[]={'a','b','c','d','\0'}; //можно и как просто 0
    for(int i=0;i<5;++i)
        printf("%d ",s[i]);
    printf("\n");

    char c='D';
    c+=1;   // 'E'

    for(int i=0;i<255;++i)
        printf("%c",i);

    return(0);
}
