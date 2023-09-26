/*
Змейка.
Требуется заполнить змейкой квадратную матрицу так, как показано на рисунке ниже:
заполнение происходит с единицы из левого верхнего угла и заканчивается в правом нижнем числом N^2,
где N – порядок матрицы. Продемонстрировать работу программы при N=4,5,6.
 1  3  4 10
 2  5  9 11
 6  8 12 15
 7 13 14 16
*/

#include <stdio.h>
#define N 6                         //максимальный порядок матрицы

int main()
{  
    int n = 4;                      //минимальный порядок матрицы
    for(n; n <= N; ++n)
    {
        int a[N][N]={{0},{0}};
        int i=0, j=0,
            direction=1,            //направление (1 - вниз влево; 0 - вверх вправо)
            fdirection=0;           //флаг перенаправления
        //заполнение матрицы
        for(int c=1; c <= n*n; ++c)
        {
            a[i][j]=c;
            if(direction)
            {
                ++i; --j;
                if(i == n) {i--; j+=2; fdirection=1;}       //вышли вниз
                else if (j < 0) {j++; fdirection=1;}        //вышли влево
            }
            else
            {
                --i; ++j;
                if(j == n) {j--; i+=2; fdirection=1;}       //вышли вправо
                else if(i < 0) {i++; fdirection=1;}         //вышли вверх
            }
            if(fdirection) direction = (direction) ? 0 : 1;
            fdirection=0;
        }
        //вывод
        printf("\nMatrix of order %d:\n",n);
        for(int k=0; k < n; ++k)
        {
            for(int l=0; l < n; ++l) printf("%3d ",a[k][l]);
            printf("\n");
        }
    }
    return 0;
}
