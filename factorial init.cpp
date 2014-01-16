#include<stdio.h>

#define MOD 1000000007
#define MAX 800005
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




void initfact(int n,long long fact[],long long ifact[])
{
     int i;
     fact[0]=1;
     for(i=1;i<=n;i++)
                     fact[i] = i*fact[i-1]%MOD;
     ifact[n] = pow(fact[n],MOD-2);
     for(i=n;i>0;i--)
     ifact[i-1] = (ifact[i]*i)%MOD;
}




#define C(a,b) ((((fact[a]*ifact[b])%MOD)*ifact[a-b])%MOD)
int main()
{
    
    initfact(MAX-5,fact,ifact);
    
    int r;
    scanf("%d",&r);
    while(r--)
    {
                    int n,m,a,b,i;
                    scanf("%d %d %d %d",&n,&m,&a,&b);
                    long long total=C((m+n),n);
                    long long subt=0;
                
                    for(i=1;i<b;i++)
                    {
                            subt=(subt+(C((n-a+i),(n-a+1))*C((m+a-i-1),(a-2)))%MOD)%MOD;
                    }
                    subt=(subt+(C((n-a+b),(n-a+1))*C((m+a-b),(a-1)))%MOD)%MOD;
                    printf("%lld\n",(MOD+total-subt)%MOD);
                
    }
          return 0;
}
