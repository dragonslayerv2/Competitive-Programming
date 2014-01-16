#include<stdio.h>

#define MAX 6

void multiply(int a[MAX][MAX],int b[MAX][MAX],int c[MAX][MAX],int n)
{
         for(int i=0;i<n;i++)
         {
          for(int j=0;j<n;j++)
          {
                  c[i][j]=0;
          }
         }            
         
         for(int i=0;i<n;i++)
         {
                 for(int j=0;j<n;j++)
                 {
                         for(int k=0;k<n;k++)
                         {
                                 c[i][j]+=a[i][k]*b[k][j];
                         }
                 }
         }
}


int main()
{
    int a[MAX][MAX]={{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1},{1,0,0,0,0,1}};
    int b[MAX][MAX]={{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1},{1,0,0,0,0,1}};
    int c[MAX][MAX];
    for(int i=0;i<MAX;i++)
    {
            for(int j=0;j<MAX;j++)
            {
                    printf("%d\t",a[i][j]);
            }
            printf("\n");
            
    }
    multiply(a,b,c,MAX);
    printf("----\n");
    for(int i=0;i<MAX;i++)
    {
            for(int j=0;j<MAX;j++)
            {
                    printf("%d\t",c[i][j]);
            }
            printf("\n");
            
    }
    multiply(a,c,b,MAX);
    printf("----\n");
        for(int i=0;i<MAX;i++)
    {
            for(int j=0;j<MAX;j++)
            {
                    printf("%d\t",b[i][j]);
            }
            printf("\n");
            
    }
    multiply(a,b,c,MAX);
    printf("----\n");
    for(int i=0;i<MAX;i++)
    {
            for(int j=0;j<MAX;j++)
            {
                    printf("%d\t",c[i][j]);
            }
            printf("\n");
            
    }
    multiply(a,c,b,MAX);
    printf("----\n");
        for(int i=0;i<MAX;i++)
    {
            for(int j=0;j<MAX;j++)
            {
                    printf("%d\t",b[i][j]);
            }
            printf("\n");
            
    }multiply(a,b,c,MAX);
    printf("----\n");
    for(int i=0;i<MAX;i++)
    {
            for(int j=0;j<MAX;j++)
            {
                    printf("%d\t",c[i][j]);
            }
            printf("\n");
            
    }
    multiply(a,c,b,MAX);
    printf("----\n");
        for(int i=0;i<MAX;i++)
    {
            for(int j=0;j<MAX;j++)
            {
                    printf("%d\t",b[i][j]);
            }
            printf("\n");
            
    }multiply(a,b,c,MAX);
    printf("----\n");
    for(int i=0;i<MAX;i++)
    {
            for(int j=0;j<MAX;j++)
            {
                    printf("%d\t",c[i][j]);
            }
            printf("\n");
            
    }
    multiply(a,c,b,MAX);
    printf("----\n");
        for(int i=0;i<MAX;i++)
    {
            for(int j=0;j<MAX;j++)
            {
                    printf("%d\t",b[i][j]);
            }
            printf("\n");
            
    }multiply(a,b,c,MAX);
    printf("----\n");
    for(int i=0;i<MAX;i++)
    {
            for(int j=0;j<MAX;j++)
            {
                    printf("%d\t",c[i][j]);
            }
            printf("\n");
            
    }
    getchar();
}

