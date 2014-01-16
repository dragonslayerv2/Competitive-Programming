#include<stdio.h>
#define MAX 49
int a[MAX][MAX];
int flag[MAX];
int max[MAX];

int main()
{
    int t;
    int n;
    int i,j,k,c;
    scanf("%d",&t);
    while(t--)
    {
              for(i=0;i<MAX;i++)
              {
                                flag[i]=0;
                                max[i]=0;
                                for(j=i+1;j<MAX;j++)
                                {
                                                  a[i][j]=0;
                                }
              }
              scanf("%d",&n);
              while(n--)
              {
                      scanf("%d %d %d",&i,&j,&c);
                      if(a[i][j]<c)
                                   a[i][j]=c;
                      flag[i]=1;
              }
              for(i=MAX-1;i>=0;i--)
              {
                                   a[i][i]=0;
                                   if(!flag[i]) {continue;}
                                   max[i]=0;
                                   for(j=i+1;j<MAX;j++)
                                   {  
                                                  if(a[i][j]==0) continue;
                                                  
                                                  for(k=j;k<MAX;k++)
                                                                    if(a[i][j]+max[k]>max[i])
                                                                                             max[i]=a[i][j]+max[k];     
                                   }
              }
              int m=0;
              for(i=0;i<MAX;i++)
              {
                                if(m<max[i]) m=max[i];
              }
              printf("%d\n",m);
    }
    return 0;
}
