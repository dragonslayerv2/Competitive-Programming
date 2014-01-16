/*
  Name: Optimal Binary Search Trees....
  Copyright: 
  Author: Shobhit Saxena
  Date: 14/12/12 18:03
  Description: This is a O(n^3) algorithm to develop a optimal binary search tree....
               Refer to cormen(P no 399) for more
*/


#include<stdio.h>
#include<limits.h>
#define MAX 100
#define max(a,b) a>b?a:b


float initOBST(float p[],float q[],int n, float e[MAX][MAX],int root[MAX][MAX],float w[MAX][MAX])
{
    for(int i=1;i<=n+1;i++)
            e[i][i-1]=w[i][i-1]=q[i-1];
    for(int l=1;l<=n+1;l++)
    {
            for(int i=1;i<=n-l+1;i++)
            {
                    int j=i+l-1;
                    
                    
                    w[i][j]=w[i][j-1]+p[j]+q[j];
                    
                    e[i][j]=e[i][i-1]+e[i+1][j]+w[i][j];
                    root[i][j]=i;
                    
                    for(int r=i+1;r<=j;r++)
                    {
                            if(e[i][j]>=e[i][r-1]+e[r+1][j]+w[i][j])
                            {
                                 e[i][j]=e[i][r-1]+e[r+1][j]+w[i][j];
                                 root[i][j]=r;
                            }
                    }
            }
    }
  /*  printf("E....\n");
    for(int i=0;i<=n+1;i++)
    {
            for(int j=0;j<=n+1;j++)
            {
                    printf("%.2f ",e[i][j]);
            }
            printf("\n");
    }
    
    printf("W....\n");
    for(int i=0;i<=n+1;i++)
    {
            for(int j=0;j<=n+1;j++)
            {
                    printf("%.2f ",w[i][j]);
            }
            printf("\n");
    }
    printf("R....\n");
    for(int i=0;i<=n+1;i++)
    {
            for(int j=0;j<=n+1;j++)
            {
                    printf("%d ",root[i][j]);
            }
            printf("\n");
    }*/
    return e[1][n];
}
void preorder(int root[MAX][MAX],int l,int u)
{
                  
                  if(l>u) printf("D%d,",u);
                  else
                  {
                      printf("K%d,",root[l][u]);
                      preorder(root,l,root[l][u]-1);
                      preorder(root,root[l][u]+1,u);
                  }
}

void inorder(int root[MAX][MAX],int l,int u)
{
                  
                  if(l>u) printf("D%d,",u);
                  else
                  {
                      
                      inorder(root,l,root[l][u]-1);
                      printf("K%d,",root[l][u]);
                      inorder(root,root[l][u]+1,u);
                  }
}

void postorder(int root[MAX][MAX],int l,int u)
{
                  
                  if(l>u) printf("D%d,",u);
                  else
                  {
                      
                      postorder(root,l,root[l][u]-1);
                      postorder(root,root[l][u]+1,u);
                      printf("K%d,",root[l][u]);
                  }
}
int main()
{
    float p[]={0.00,0.15,0.10,0.05,0.10,0.20};
    float q[]={0.05,0.10,0.05,0.05,0.05,0.10};
    int n=5;
    
    float w[MAX][MAX],e[MAX][MAX];
    int root[MAX][MAX];
    printf("Optimal Cost= %f\n",initOBST(p,q,n,e,root,w));
    printf("Preorder Traversal=> ");preorder(root,1,n);
    printf("\n");
    printf("Preorder Traversal=> ");inorder(root,1,n);
    printf("\n");
    printf("Postorder Traversal=> ");postorder(root,1,n);
    printf("\n");    
    
    getchar();
    
}
