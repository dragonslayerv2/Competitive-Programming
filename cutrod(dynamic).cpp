/*
  Name: Rod cutting problem(dynamic version, NAIVE)
  Copyright: 
  Author: Shobhit Saxena
  Date: 09/12/12 22:17
  Description: This problem solves rod cutting problem recursively. refer to Cormen for problem statement.
               complexity O(n^2).
               it replaces p[] the price array with the max price of that rod.
               to save the price also. copy it initially.
               print solution in O(n)
               
*/

#include<stdio.h>
#define MAX 100
#define max(a,b) a>b?a:b
#define SIZE(p) sizeof(p)/sizeof(*p)



void initRod(int p[],int n,int r[])
{
    for(int i=0;i<=n;i++)
    {
            r[i]=p[i];        
            for(int j=1;j<=i/2;j++)
            {
                    r[i]=max(r[i],r[j]+r[i-j]);
            }
    }
}

void solution(int p[],int r[],int n)
{
     while(n)
     {
     for(int i=1;i<=n;i++)
     {
             if(r[n]==p[i]+r[n-i]) 
                              {printf("%d ",i); n=n-i;break;}
     }
     }
     printf("\n");
}

int main()
{
    int p[]={0,1,5,8,9,10,17,17,20,24,30};
    int r[MAX];
    initRod(p,SIZE(p)-1,r);    
    
    for(int i=0;i<SIZE(p);i++)
    {
            printf("%d=%d\t",i,r[i]);
            solution(p,r,i);
    }
    getchar();
}
