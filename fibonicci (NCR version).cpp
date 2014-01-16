#include<stdio.h>

#define MOD 1000000007
#define MAX 8001

long long pow(long long n,int m)
{
    if(m==0) return 1;
    
    long long x=pow(n,m/2);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}




void initfact(int n,long long fact[],long long ifact[])
{
     ifact[0]=ifact[1]=fact[0]=fact[1]=1;
     
     for(int i=2;i<n;i++)
     {
             fact[i]=(i*fact[i-1])%MOD;
             ifact[i]=pow(fact[i],MOD-2);
     }
}

#define C(a,b) ((((fact[a]*ifact[b])%MOD)*ifact[a-b])%MOD)
int main()
{
    long long fact[MAX];
    long long ifact[MAX];
    initfact(MAX,fact,ifact);
    
    int r;
    scanf("%d",&r);
    while(r--)
    {
                    int n;
                    scanf("%d",&n);
                    long long ans=0;
                    for(int r=0;r<=(n+1)/2;r++)
                    {
                            ans+=C(n-r+1,r);
                    }
                    printf("%lld\n",ans);
    }
          return 0;
}
