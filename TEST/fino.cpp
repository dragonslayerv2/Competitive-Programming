#include<stdio.h>
#define MOD 1000000007

void tn(long long a[2][2],int n)
{      
    if(n==1) return;
    else
    {
        tn(a,n/2);
        long long u,v,w,x;
        u=(a[0][0]*a[0][0]+a[0][1]*a[1][0])%MOD;
        v=(a[0][0]*a[0][1]+a[0][1]*a[1][1])%MOD;
        w=(a[1][0]*a[0][0]+a[1][1]*a[1][0])%MOD;
        x=(a[1][0]*a[0][1]+a[1][1]*a[1][1])%MOD;
        a[0][0]=u;
        a[0][1]=v;
        a[1][0]=w;
        a[1][1]=x;
        if(n%2!=0)
        {
                  u=a[0][1];
                  v=(a[0][0]+a[0][1])%MOD;
                  w=a[1][1];
                  x=(a[1][0]+a[1][1])%MOD;
                  a[0][0]=u;
                  a[0][1]=v;
                  a[1][0]=w;
                  a[1][1]=x;
        }
    }
}
int main()
{
    int T;
    scanf("%lld",&T);
    while(T--)
    {
              long long n;
              scanf("%lld",&n);
              
              long long t[2][2]={0,1,1,1};
              
              tn(t,2*n);
              printf("%lld\n",(t[1][0]*t[1][1])%MOD);         
              }
    return 0;
}
