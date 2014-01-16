#include<stdio.h>

int main()
{
    int N,n,i;
    scanf("%d",&N);
    i=1;
    n=N;     
    while(n)
    {
             n>>=1;
             i<<=1;       
    }
    i>>=1;
    int ans=((N-i)*2)+1;
    printf("%d\n",ans);
    return 0;
}
