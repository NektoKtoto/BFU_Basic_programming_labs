/*
Распространение волны в лабиринте
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10
#define OBS 1
#define O -1
#define S -2
#define F -3

int main()
{
    int a[N][N]={0};
    a[0][0]=S;
    a[N-1][N-1]=F;
    srand((unsigned int)time(0));
    for(int o=0;o<OBS;++o)
    {
        int i=rand()%N;
        int j=rand()%N;
        if(a[i][j]==O||a[i][j]==S||a[i][j]==F) {--o;continue;}
        a[i][j]=-1;
    }
    int n=0,res=0;
    while(!res)
    {
        int k=0;
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<N;++j)
            {
                int what=(n==0?S:n);
                if(a[i][j]!=what) continue;
                if(j>0&&a[i][j-1]==F) {res=1;break;}
                if(j<N-1&&a[i+1][j]==F) {res=1;break;}
                if(j<N-1&&a[i][j+1]==F) {res=1;break;}
                if(j>0&&a[i-1][j]==F) {res=1;break;}
                if(j>0&&a[i][j-1]==0) {a[i][j-1]=n+1;++k;}
                if(j<N-1&&a[i+1][j]==0) {a[i+1][j]=n+1;++k;}
                if(j<N-1&&a[i][j+1]==0) {a[i][j+1]=n+1;++k;}
                if(j>0&&a[i-1][j]==0) {a[i-1][j]=n+1;++k;}
            }
        }
        if(k==0) {res=-1;break;}
        if(n==1) break;
        ++n;
    }
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<N;++j)
                if(a[i][j]==O) printf(" *");
                else if(a[i][j]==S) printf(" S");
                else if(a[i][j]==F) printf(" F");
                else printf("%2d",a[i][j]);
            printf("\n");
        }
    return 0;
}
