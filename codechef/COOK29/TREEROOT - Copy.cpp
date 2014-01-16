#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
              int sum=0;
              int n;
              scanf("%d",&n);
              while(n--)
              {
                        int N;
                        int S;
                        scanf("%d %d",&N,&S);
                        sum+=N-S;
              }
              printf("%d\n",sum);
    }
    return 0;
}
