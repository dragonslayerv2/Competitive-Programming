#include<stdio.h>

#define MOD (1000000000+7)


long long p(int n,int m)
{
    if(m==0) return 1;
    
    long long x=p(n,m/2);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (x*x*n)%MOD;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d",&n);
                  int counter=n%2?-3:3;
                  printf("%d\n",int((p(3,n)+counter)%MOD));
    }
}
