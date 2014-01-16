#include<stdio.h>

#define max(a,b) a>b?a:b

int solve(int n)
{
    if(n==0) return 0;
    int a=solve(n/2)+solve(n/3)+solve(n/4);
    return max(a,n);
}

int main()
{
    
    int n;
    while(scanf("%d",&n)>0)
                           printf("=%d\n",solve(n));
    return 0;    
}
