/*
  Name: 
  Copyright: 
  Author: 
  Date: 05/11/12 23:55
  Description: Everything thrice except 1 which is twice. Sum them and 
*/



#include<stdio.h>

int func(int a[],int n)
{
    int sum=0, xr=0;
    for(int i=0;i<n;i++)
    {
            sum+=a[i];
            xr^=a[i];
    }
    return (xr*3-sum)/2;
}
int main()
{
    int a[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3};
    printf("%d",func(a,10));
    getchar();
    return 0;
}
