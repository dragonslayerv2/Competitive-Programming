#include<stdio.h>

#define MOD 1000000007
#define MAX 1010
long long fact[MAX];
long long ifact[MAX];

long long pow(long long n,int m)
{
    if(m==0) return 1;
    
    long long x=pow(n,m/2);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}




void initfact(int n)
{
     int i;
     fact[0]=1;
     for(i=1;i<=n;i++)
                     fact[i] = i*fact[i-1]%MOD;
     ifact[n] = pow(fact[n],MOD-2);
     for(i=n;i>0;i--)
     ifact[i-1] = ifact[i]*i%MOD;
}




#define C(a,b) ((((fact[a]*ifact[b])%MOD)*ifact[a-b])%MOD)




int main()
{
    initfact(MAX);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long N,answer=0;
        scanf("%lld",&N);
        int i;
        for(i=0;i<N;i++)
        {
            int temp;
            scanf("%d",&temp);
        }
        for(i=(N/2)+1;i<=N;i++)
        { 
             answer=(answer+(C(N,i)))%MOD;   
        }
        printf("%lld\n",answer);
    }
}
