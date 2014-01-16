#include<stdio.h>

inline unsigned long long gcf(unsigned long long a, unsigned long long b)
{
   unsigned long long temp;    
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
    printf("%d",gcf(1001,2431));
    getchar();
}
