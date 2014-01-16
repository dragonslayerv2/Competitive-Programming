// Tracing the path and no reverse paths.

#include<stdio.h>
#define MAX 10
int recurse(int a[MAX][MAX],int x,int y,int n)
{
    if(x==n&&y==n) return 1;
    if(x<0||x>n||y<0||y>n) return 0;
    if(a[x][y]==1) return 0;
    
    a[x][y]=1;
    int c= recurse(a,x+1,y,n)+recurse(a,x-1,y,n)+recurse(a,x,y+1,n)+recurse(a,x,y-1,n);
    a[x][y]=0;   
    return c;
}

int main()
{
    int n,a[MAX][MAX];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
            {
                    scanf("%d",&a[i][j]);
            }
    }
    printf("%d",recurse(a,0,0,n-1));
    return 0;
}
