#include<stdio.h>

int solve(int from,int to,int n,int temp=2)
{
    if(n>0)
    {
     solve(from, temp, n-1,to);
     printf("%d=> %d---> %d\n",n,from,to);
     solve(temp,to,n-1,from);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    solve(1,18,n);
    fflush(stdin);
    getchar();
}
