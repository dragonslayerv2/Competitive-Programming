#include<stdio.h>


int main()
{
    int x[100000],y[100000];
    int t;
    int n;
    scanf("%d",&t);
    while(t--)
    {
              int res=0;
              scanf("%d",&n);
              for(int i=0;i<n;i++)
              {
                      scanf("%d %d",x+i,y+i);
              }
              for(int i=0;i<n-1;i++)
              {
                      for(int j=i+1;j<n;j++)
                      {
                              if((x[i]>x[j]&&y[i]<y[j])||(x[i]<x[j]&&y[i]>y[j])) res++;
                      }
              }
              
               printf("%d\n",res);
    }
    return 0;
}
