/*
  Name: Sum of elements os subsets of a set....
  Copyright: 
  Author: Shobhit Saxena
  Date: 28/11/12 00:51
  Description: A subset can be treated as a binary tree.. If we r moving left we means we include tht element else we exclude tht from the set.
               Alternatively we can think tht to find the sum of a subset we either include a term or exclude it. Left show tht we include the term and right we exclude tht.
               Complexity O(2^n)
*/


#include<stdio.h>

int findsum(int a[],int n,int i=0,int sum=0)
{
    if(i==n) return sum;
    else
    {
        return findsum(a,n,i+1,sum+a[i])+findsum(a,n,i+1,sum);
    }
}
int main()
{
    
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(*a);
    printf("%d",findsum(a,n));
    getchar();
    return 0;
}
