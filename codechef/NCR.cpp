/*
  Name: nCr
  Copyright: 
  Author: 
  Date: 12/11/12 14:21
  Description: 
*/


#include<stdio.h>

inline int nCr(int n,int r)
{
    int nm=1;
    int rm=1;
    while(r)
    {
              nm=nm*(n--);
              rm*=(r--);
    }
    return nm/rm;
}

int main()
{
    int n,x;
    printf("%d",nCr(6,2));
    getchar();
}
