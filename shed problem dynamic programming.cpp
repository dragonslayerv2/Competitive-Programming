/*
  Name: Shed Problem
  Copyright: 
  Author: Shobhit Saxena
  Date: 17/12/12 21:37
  Description: Dynamic solution of the shed problem. This algo takes O(lb) to solve the matrix. Better than the naive algorithm tht takes O(l^2 b^2). 
*/



#include<stdio.h>

#define MAX 1000

#define GETCHAR getchar//_unlocked

#define min(a,b,c) (a<b?(a<c?a:c):(b<c?b:c))

int matrix[1000][1000];
int main()
{
    int r,c;
    char temp;
    int i,j;
    scanf("%d %d ",&r,&c);
    int max=0;
    
    for(i=0;i<r;i++)
    {
            for(j=0;j<c;j++)
            {
                    scanf(" %c",&temp);
                    if(temp=='T') matrix[i][j]=0;
                    else if(temp=='.')
                    {
                         if(!i||!j) matrix[i][j]=1;
                         else 
                         {
                              matrix[i][j]=1+min(matrix[i][j-1],matrix[i-1][j],matrix[i-1][j-1]);         
                         }          
                    }
                    max=max>matrix[i][j]?max:matrix[i][j];                  
                   
            }
         
    }
    printf("%d\n",max?(max*max):-1);
    return 0;
}
