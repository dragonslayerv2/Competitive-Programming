/*
  Name: Matrix Chain Multiplication (Recursive version)
  Copyright: 
  Author: Shobhit Saxena
  Date: 09/12/12 22:43
  Description: Recursive version of matrix multiplication. O(2^n ) time complexity & O(n^2) space requirement
*/
#include<stdio.h>
#include<limits.h>

#define MAX 100

int minchain(int p[],int n,int m[MAX][MAX],int s[MAX][MAX])
{
    int i,k,l,j;
    for(i=1;i<=n;i++)
            m[i][i]=0;
    for(l=1;l<n;l++)
    {
            for(i=1;i<=n-l;i++)
            {
                            j=i+l;
                            m[i][j]=INT_MAX;
                            
                            for(k=i;k<j;k++)
                            {
                                            int current=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                                            if(current<m[i][j])
                                            {
                                                               m[i][j]=current;
                                                               s[i][j]=k;
                                            }
                            }
            }
    }
    return m[1][n];
}

void printsolution(int l,int h,int s[MAX][MAX])
{
     if(l==h) printf(" A%d ",l);
     else
     {
         printf("(");
         printsolution(l,s[l][h],s);
         printsolution(s[l][h]+1,h,s);
         printf(")");
     }
}
int main()
{
    int s[MAX][MAX];
    int m[MAX][MAX];
    //int matrixchain[]={30,35,15,5,10,20,25}; 
       int matrixchain[]={5,10,3,12,5,50,6}; 
    int n=(sizeof(matrixchain)/sizeof(int)) -1;
    printf("Cost=%d\n",minchain(matrixchain,n,m,s));
    
    printsolution(1,n,s);
    
    getchar();
    return 0;
}
