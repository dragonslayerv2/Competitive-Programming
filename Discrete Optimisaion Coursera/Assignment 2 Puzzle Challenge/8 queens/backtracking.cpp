/*
  Name: 8 Queens problem....
  Copyright:
  Author: Shobhit Saxena
  Date: 06/12/12 17:21
  Description: In a n by n chess board, the problem of placing n queens on the board without the queens threatening one another.
*/


#include<stdio.h>

#define isSafe(x1,y1,x2,y2) (x1!=x2&&y1!=y2&&(y1-y2)!=(x1-x2)&&(y1-y2)!=(x2-x1))

#define MAX 100

long long count=0;
void print(int a[],int n)
{
     for(int i=0;i<n;i++)
     {
             printf("%d ",a[i]);
     }
     printf("\n");
}

bool solve(int a[],int n,int y=0)
{

     if(y==n)
     {
             print(a,n);
             count++;
             return true;
     }
     else
     {
         for(int i=0;i<n;i++)
         {
                 int flag=1;
                 for(int j=0;j<y;j++)
                 {
                         if(!isSafe(a[j],j,i,y))
                             {
                                                 flag=0;
                                                 break;
                             }
                 }
                 if(flag)
                 {
                         a[y]=i;
                        if( solve(a,n,y+1)==true)
							return true;
                 }
         }

     }
     return false;
}

int main(int argc,char *argv[])
{
          int a[MAX];
          
          int n;
		  sscanf(argv[1],"%d",&n);
          
		  count=0;
          printf("%d\n",n);
          solve(a,n);
}
