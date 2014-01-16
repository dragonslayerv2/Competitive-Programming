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

int minchain(int chain[],int l,int u,int s[MAX][MAX])
{
    if(l==u) {return 0;s[l][l]=l;}
    else
    {
        int min=INT_MAX;
        
        for(int i=l;i<u;i++)
        {
                int rec=minchain(chain,l,i,s)+minchain(chain,i+1,u,s)+ chain[l-1]*chain[i]*chain[u];
                if(rec<min)
                {
                           min=rec;            
                           s[l][u]=i;
                }
        }
        return min;
    }
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
    //int matrixchain[]={30,35,15,5,10,20,25}; 
       int matrixchain[]={5,10,3,12,5,50,6}; 
    int n=(sizeof(matrixchain)/sizeof(int)) -1;
    printf("Cost=%d\n",minchain(matrixchain,1,n,s));
    
    printsolution(1,n,s);
    
    getchar();
    return 0;
}
