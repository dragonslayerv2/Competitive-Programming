#include<stdio.h>

#define btog(n) (n^(n>>1))


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
              int n;
              scanf("%d",&n);
              printf("%d\n",btog(n));              
    }
    return 0;
}
