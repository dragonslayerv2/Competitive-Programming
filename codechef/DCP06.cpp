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
inline int numrev(int n)
{
       int c=n;
       int x=0;
       while(c)
       {
               x=x*10+c%10;
               c/=10;
       }
       return x;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
              int n;
              scanf("%d",&n);
              int count=0;
              while(!check(n))
              {
                count++;
                n=n+numrev(n);              
              }
              printf("%d %d\n",count,n);
    }
    return 0;
}
