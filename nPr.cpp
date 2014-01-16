/*
  Name: nPr
  Copyright: 
  Author: 
  Date: 12/11/12 14:16
  Description: Calculates nPr()
*/


#include<stdio.h>

inline unsigned int P(int n,int r)
{
       unsigned int p=1;
       while(r--)
                 p*=n--;
       return p;
}

int main()
{
    printf("%d",P(5,3));
    getchar();
    
}
