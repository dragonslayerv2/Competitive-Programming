/*
  Name: Triangle Paths problem(dynamic solution) 
  Copyright: 
  Author: 
  Date: 11/12/12 19:01
  Description: You are given a triangle divided in subtriangles by lines parallel to its sides. at any point you can move to -> or / or \ . Find the total number of path possible.
*/


#include<stdio.h>

#define MAX 100
int solve(int n)
{
    int a[MAX][MAX];
    for(int i=0;i<n;i++)
            a[n-1][i]=1;
    
    for(int i=n-2;i>=0;i--)
    {
            for(int j=0;j<=i;j++)
            {
                    a[i][j]=a[i+1][j]+a[i+1][j+1];
                    if(j) a[i][j]+=a[i][j-1];
            }        
    }
    return a[0][0];   
}


int main()
{
    for(int n=2;n<=10;n++)
                  printf("%d ",solve(n));
    getchar();
    return 0;
}
