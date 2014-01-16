#include<stdio.h>

int f(int n)
{
    int a=1;
    int b=1;
    int c;
    for(int i=3;i<=n;i++)
    {
            c=a+b;
            a=b;
            b=c;
    }
    return c;
}
int g(int n)
{
    if(n==0) return 0;
    return g(n-1)+ f(4*n-1);
}
int main()
{
    for(int i=0;i<11;i++)
          {  printf("%d, ",g(i)); }
    getchar();
}
