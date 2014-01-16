#include<stdio.h>
#include<string.h>
#define MAX 100
int path[10][10];
int isVisited[10];
int min,count;

void recurse(int n,int i=0,int sum=0)
{
     if(i==n-1)
     {
             // printf("min =%d,sum=%d i=%d\n",min,sum,i);
              if(sum<min)
              {
                         min=sum;
                         count=1;
              } 
              else if(sum==min)
              {
                         count++;
              }
             // getchar();
     }
     else
     {
         for(int j=0;j<n;j++)
         {
                 if(path[i][j]&&!isVisited[j])
                 {
               //                 printf("path[%d][%d]=%d\n",i,j,path[i][j]);
                                isVisited[j]=1;
                                recurse(n,j,sum+path[i][j]);
                                isVisited[j]=0;
                 }
         }
     }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
          count=0;
          min=MAX;
          memset(path,0,sizeof(path));    
          memset(isVisited,0,sizeof(isVisited));
          
          int n,m;
          scanf("%d %d",&n,&m);
          
          for(int i=0;i<m;i++)
          {
           int x,y,c;
           scanf("%d %d %d",&x,&y,&c);
          
           path[x-1][y-1]=path[y-1][x-1]=c;
          }
          recurse(n);
          printf("%d\n",count);
    }
    return 0;
}
