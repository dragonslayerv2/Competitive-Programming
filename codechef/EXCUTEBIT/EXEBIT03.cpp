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
   return array[prev][k];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
		int n;
		scanf("%d",&n);
		int a[MAX];
		int sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		int avg=avg/2;
    	printf("%d\n",sum-2*findsum(a,n,avg));		
	}
    return 0;
}
