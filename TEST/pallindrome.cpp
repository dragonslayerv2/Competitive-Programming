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
                   int x,y;
                 int max=0;
                 for(int i=999;i>=100;i--)
                 {
                         for(int j=999;j>=100;j--)
                         {
                                 if(check(i*j)&&i*j>max)
                                 {
                                                        max=i*j;
                                                        x=i;
                                                        y=j;
                                 }                         
                         } 
                 } 
                 printf("%d*%d=%d",x,y,max);
                 getchar();                 
}
