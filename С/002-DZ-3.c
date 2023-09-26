/*
3) Конь и слон.
На шахматной доске стоят конь и слон. Распечатать шахматную доску, обозначив крестиком те поля, которые бьют эти фигуры.
Не забываем о том, что слон бьет по диагонали и конь может перекрыть ему диагональ.
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int ki=5,kj=6;//положение коня
    int bi=3,bj=4;//положение слона
    for(int i=8;i>0;--i)
        for(int j=1;j<9;++j)
        {
            if((j==1)&&(i!=8))
                printf("\n");
            if((i==ki)&&(j==kj))
            {
                printf("k");
                continue;
                //вывод коня
            }
            if((i==bi)&&(j==bj))
            {
                printf("b");
                continue;
                //вывод слона
            }
            if(((abs(i-ki)==2)&&(abs(j-kj)==1))||((abs(j-kj)==2)&&(abs(i-ki)==1))||((abs(i-bi)==abs(j-bj))&&(!((abs(ki-bi)==abs(kj-bj))&&(abs(i-bi)>abs(i-ki))))))
            {
                printf("X");
                continue;
                //вывод возможных позиций коня и слона
            }
            if(((i+j)%2)==0)
            {
                printf("*");
                continue;
                //вывод чёрных полей
            }
            printf("_");
            //вывод белых полей
        }
    printf("\n");
    return 0;
}
