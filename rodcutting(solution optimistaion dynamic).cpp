/*
  Name: Rod cutting problem(dynamic version, NAIVE)
  Copyright: 
  Author: Shobhit Saxena
  Date: 09/12/12 22:17
  Description: This problem solves rod cutting problem recursively. refer to Cormen for problem statement.
               complexity O(n^2).
               it replaces p[] the price array with the max price of that rod.
               to save the price also. copy it initially.
               print solution in O(length of solution)
               
*/

#include<stdio.h>
#define MAX 100
#define max(a,b) a>b?a:b
#define SIZE(p) sizeof(p)/sizeof(*p)


void initRod(int p[],int n,int r[],int s[])
{
    for(int i=1;i<=n;i++)
    {
            r[i]=p[i];     
            s[i]=i;   
            for(int j=1;j<=i-1;j++)
            {
                    if(r[i]<p[j]+r[i-j])
                    {
                                r[i]=p[j]+r[i-j];
                                s[i]=j;
                    }
            }
    }
}

void solution(int p[],int r[],int s[],int n)
{
     while(n)
     {
         printf("%d ",s[n]);
         n-=s[n];
     }
     printf("\n");
}

int main()
{
    int p[]={0,1,5,8,9,10,17,17,20,24,30};
    int r[MAX];
    int s[MAX];
    initRod(p,SIZE(p)-1,r,s);    
    
    for(int i=0;i<SIZE(p);i++)
    {
            printf("%d=%d\t",i,r[i]);
            solution(p,r,s,i);
    }
    getchar();
}
