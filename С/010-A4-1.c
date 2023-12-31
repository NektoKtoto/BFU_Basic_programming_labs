/*
Музей.
В текстовом файле записан дневник прихода и ухода посетителей в музее в течении суток,например:
09:00 10:07
10:20 11:35
12:00 17:00
11:00 11:30
11:20 12:30
11:30 18:15
то есть первый посетитель пришел в 09:00 и ушел в 10:07,
второй посетитель пришел в 10:20 и ушел в 11:35 и т.д.
Время записано в формате «ЧЧ:ММ ЧЧ:ММ» (00:00 ≤ ЧЧ:ММ ≤ 23:59).
Программа должна вывести на экран число - максимальное количество посетителей, одновременно находящихся в музее.
Для приведенных данных правильный ответ 4.
*/

#include <stdio.h>

int main()
{
    char *file = "D:/123.txt";
    FILE *f = fopen(file,"r");
    if (!f) {printf("can't open %s\n",file); return 1;}
    char s, a[11]={0};
    int i=0, b[1440]={0}, m=0;
    while ((s=fgetc(f)) != EOF)
    {
        if(s != '\n') a[i++]=s;
        else
        {
            i=0;
            for(int j = 60*(10*(a[0]-'0')+(a[1]-'0'))+10*(a[3]-'0')+(a[4]-'0'); j <= 60*(10*(a[6]-'0')+(a[7]-'0'))+10*(a[9]-'0')+(a[10]-'0'); j++) b[j]++;
        }
    }
    fclose(f);
    for(int j = 60*(10*(a[0]-'0')+(a[1]-'0'))+10*(a[3]-'0')+(a[4]-'0'); j <= 60*(10*(a[6]-'0')+(a[7]-'0'))+10*(a[9]-'0')+(a[10]-'0'); j++) b[j]++;
    for(int j=0; j<1440; j++)
        if(b[j]>m) m=b[j];
    printf("%d\n",m);
    return 0;
}