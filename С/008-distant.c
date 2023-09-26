#include <stdio.h>

int main()
{
    printf("%.0f\n",53.141592);
    return 0;
}

#include <stdio.h>

int main()
{
    char *f = "D:/123.txt";
    char buf[256];
    FILE *fd = fopen(f,"r");
    if (!fd) {printf("can't open %s\n",f); return 1;}
    while (fgets(buf,sizeof(buf),fd)) puts(buf);

    fclose(fd);
    return 0;
}

#include <stdio.h>

void readfile(char *filename)
{
    FILE *fd = fopen(filename,"r");
    if (fd == NULL)
    {
        printf("not open %s\n", filename);
        return 1;
    }

    int c;
    while ((c=fgetc(fd)) != EOF)
    {
        putchar(c);
    }
    //неформатируемый ввод/вывод
    //int c = getchar(); putchar(c);

    fclose(fd);
}

int main()
{
    char *f = "D:/123.txt";
    readfile(f);
    return 0;
}