
/*
  Name: Subset sum O(n) solution....
  Copyright: 
  Author: 
  Date: 28/11/12 13:13
  Description: Each item in total subsets appears 1/2 times... so sum can be found by 2^(n-1) * sum of all elements....
*/
#include<stdio.h>

long long subsetsum(int a[],int n)
{
    long long ans=0;
    int i;
    long long pow=1;
    for(i=0;i<n;i++)
    {
            ans+=a[i];
            pow<<=1;
            
    }
    pow>>=1;
    return ans*pow;
}


int main()
{
    int a[]={1,2,3};
    printf("%lld",subsetsum(a,sizeof(a)/sizeof(*a)));
    getchar();
}
