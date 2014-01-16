#include<stdio.h>
#include<limits.h>
int main()
{
    int t;
    
    scanf("%d",&t);
    while(t--)
    {
              int n;
              scanf("%d",&n);
              int speed;
              int max=INT_MAX;
              int count=0;
              
              for(int i=0;i<n;i++)
              {
                      scanf("%d",&speed);
                      if(speed<=max)
                      {
                                   count++;
                                   max=speed;
                      }
              }         
              printf("%d\n",count);
    }
    return 0;
}
