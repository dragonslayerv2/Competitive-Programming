/*
  Name: Rod cutting problem(recursive Solution.)
  Copyright: 
  Author: Shobhit Saxena
  Date: 09/12/12 22:17
  Description: This problem solves rod cutting problem recursively. refer to Cormen for problem statement.
               A dynamic solution can be made with complexity O(n^2).
               This program solves it in O(2^n).
*/

#include<stdio.h>

#define max(a,b) a>b?a:b

int cutRod(int p[],int n)
{
    if(n==0)
            return 0;
    else
    {
        int q=p[n];
        for(int i=1;i<n;i++)
        {
                int cuti=cutRod(p,n-i);
                q=max(q,cuti+p[i]);
        }
        return q;     
    }
}


int main()
{
    int p[]={0,1,5,8,9,10,17,17,20,24,30};
    for(int i=0;i<=10;i++)
    {
            printf("%d=%d\n",i,cutRod(p,i));
    }
    getchar();
}
