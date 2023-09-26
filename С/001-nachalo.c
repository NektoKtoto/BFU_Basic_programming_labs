#include <stdio.h>

int main()
{
//Нахождение наибольшего числа
    int a[4]={-598,-936,-254,-736},b=-1000;
    for (int i=0;i<4;++i)
    {
        if (a[i]>b)
                b=a[i];
    }
    printf("%d\n",b);

//Определение длины наибольшего тёплого (>0) периода
    float t[]={0,1,0,1,1,0,1,1,0,10,11,12};
    int a=0,c=0,e=sizeof(t)/sizeof(t[0]);
    for(int b=0;b<e;++b)
    {
        if(t[b]>0)
            c+=1;
        else
        {
            a=a<c?c:a;
            c=0;
        }
    }
    a=a<c?c:a;
    printf("%d\n",a);

//Задание единичной матрицы
    int a[10][10];
    for(int b=9;b>=0;b--)
    {
        for(int c=9;c>=0;c--)
        {
            a[b][c]=b==c?1:0;
        }
    }

//Массивы
    int a[10]={0};                  //индексы 0..9|обнуление
    int a0[]={0,1,2,3,4}            //задание поэлементно
    int b=sizeof(a)/sizeof(a[0]);   //размерность
    int a1[2][10]={{0},{0}};        //двумерный массив|обнуление

//Тернарный оператор
    a=(i+j)%2==0?"+":"-";

//Размен числа на 5 и 3 (сначала на max кол-во 5)
    int n=17;
    if((n==1)||(n==2)||(n==4)||(n==7))
        printf("Not\n");
    else
        {
            for(int a=n/5;a>0;a--)
            {
                int b=n-a*5;
                if(b%3==0)
                {
                    printf("5 = %d\n",a);
                    printf("3 = %d\n",b/3);
                    break;
                }
            }
        }

//Цикл
    for(int i=0;i<10;i++)
        printf("%d\n",i);

//Условие
    if(x%2==0)
        printf("odd\n");
    else
        printf("even\n");

//Вывод
    printf("Hello World!\n");

}

