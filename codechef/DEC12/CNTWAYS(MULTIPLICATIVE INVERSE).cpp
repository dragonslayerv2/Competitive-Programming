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
    
    initfact(MAX,fact,ifact);
    
    int r;
    scanf("%d",&r);
    while(r--)
    {
                    int n,m,a,b;
                    scanf("%d %d %d %d",&n,&m,&a,&b);
                    long long total=C((m+n),n);
                    long long subt=0;
                
                    for(int i=1;i<b;i++)
                    {
                            subt=(subt+(C((n-a+i),(n-a+1))*C((m+a-i-1),(a-2)))%MOD)%MOD;
                    }
                    subt=(subt+(C((n-a+b),(n-a+1))*C((m+a-b),(a-1)))%MOD)%MOD;
                    printf("%lld\n",(MOD+total-subt)%MOD);
                
    }
          return 0;
}
