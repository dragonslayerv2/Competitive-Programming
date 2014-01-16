#include<stdio.h>

inline int gcf(int a, int b)
{
   int temp;    
   while(b)
   {
           temp=a;
           a=b;
           b=temp%b;
   }
   return a;
}

int main()
{
    printf("%d",gcf(2,3));
    getchar();
}
