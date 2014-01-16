#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    int n;
    while(t--)
    {
              scanf("%d",&n);
              printf("%s",(n%2?"BOB\n":"ALICE\n"));
    }
    return 0;
}
