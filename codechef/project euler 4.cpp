#include<stdio.h>

inline int check(int n)
{
       int x=0,c=n;
       while(c)
       {
               x=x*10+c%10;
               c/=10;
       }
       if(x==n) return 1;
       else return 0;
}

int main()
{
    int max=0;
    int x,y;
    for(int i=999;i>=101;i--)
    {
     for(int j=999;j>=101;j--)
     {
             if(check(i*j)&&i*j>max)
             {x=i;y=j;max=i*j;}
     }
    }   
    printf("%d %d %d",max,x,y);
    getchar();
    
}
