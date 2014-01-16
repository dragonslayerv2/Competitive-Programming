/*
  Name: Catalan Numbers
  Copyright: 
  Author: Shobhit Saxena
  Date: 08/12/12 22:14
  Description: There are several methods to calculate nth catalan number....
               This is a O(n)  algorithm with O(1) memory requirement to compute nth catalan number...
               
               This is based on the formula
               C(n)= (2*(2*n-1)/(n+1) )C(n-1)
               
               use dynamic programming if ur program require a lot of calls to catalan number....
*/


#include<stdio.h>

unsigned long long C(int n)
{
         unsigned long long c=1;
         for(int i=2;i<=n;i++)
         {
                 c=(2*(2*i-1)*c)/(i+1);
         }
         return c;
}


int main()
{
    for(int i=0;i<=15;i++)
    {
            printf("%d = %lld\n",i,C(i));
            
    }
    getchar();
}
