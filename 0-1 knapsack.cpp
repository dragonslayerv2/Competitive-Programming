/*
  Name: O 1 knapsack problem. O(n) memory. O(nW) time complexity
  Copyright: 
  Author: Shobhit Saxena
  Date: 28/11/12 00:51
  Description: Pseudopolynomial time knapsack solution
*/

#define MAX 2000
#include<stdio.h>

#define max(a,b) (a)>(b)?a:b;
inline int knapSack(int v[],int W[],int n,int k)
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
                                     if(W[i]>w) array[cur][w]=array[prev][w];
                                     else
                                                array[cur][w]=max(array[prev][w],array[prev][w-W[i]]+v[i]);
                    }
                    cur^=prev^=cur^=prev;
                    
   }
   return array[prev][k];
}
int main()
{
    int n=3;
    int k=50;
    int w[]={10,20,30};
    int v[]={60,100,120};
    printf("%d",knapSack(v,w,n,k));
    return 0;
}
