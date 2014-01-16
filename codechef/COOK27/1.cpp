#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
              int n,x;
              int cost=0;
              int z[100];
              scanf("%d %d",&n,&x);
              for(int i=0;i<n;i++)
              {
                      scanf("%d",&z[i]);
                      cost+=z[i];
              }
              int final=cost/x;
              int flag=0;
              for(int i=0;i<n;i++)
              {
                      if((cost-z[i])/x==final)
                                      flag=1;        
              }
              if(flag==0)
                         printf("%d\n",final);
              else
                         printf("%d\n",-1);
                  
    }
    return 0;
}
