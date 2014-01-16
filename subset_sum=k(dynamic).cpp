/*
  Name: Sum of elements os subsets of a set....
  Copyright: 
  Author: Shobhit Saxena
  Date: 28/11/12 00:51
  Description: Just a modified version of 01 knap sack problem
*/

#define MAX 2000
#include<stdio.h>

#define max(a,b) (a)>(b)?a:b;
inline int findsum(int a[],int n,int k)
{
   int i,w;
   int array[2][MAX+1];
   int cur=1;
   int prev=0;
   
   for(i=0;i<=k;i++)
                      array[0][i]=0;
 
   for(i=0;i<=n;i++)
   {
                    for(w=0;w<=k;w++)
                    {
                                     if(a[i]>w) array[cur][w]=array[prev][w];
                                     else
                                                array[cur][w]=max(array[prev][w],array[prev][w-a[i]]+a[i]);
                    }
                    cur^=prev^=cur^=prev;
                    
   }
   printf("%d ",array[prev][k]);
   return array[prev][k]==k;
}
int main()
{
    int n=5;
    int k=100;
    int a[]={2,3,4,6,8};
    printf("%d",findsum(a,n,k));
    getchar();
    return 0;
}
