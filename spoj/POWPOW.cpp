#include<iostream>
using namespace std;


#define MAX 1005000

long long p(long long n,long long m,long long MOD)
{
    if(m==0) return 1%MOD;
    
    long long x=p(n,m/2,MOD);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}

long long fact[MAX];
long long ifact[MAX];

void initfact(long long n,long long MOD)
{
     long long i;
     fact[0]=1;
     for(i=1;i<=n;i++)
    	fact[i] = (i*fact[i-1])%MOD;
     ifact[n] = p(fact[n],MOD-2,MOD);
     for(i=n;i>0;i--)
     	ifact[i-1] = (ifact[i]*i)%MOD;
}

#define C(a,b,MOD) ((((fact[a]*ifact[b])%MOD)*ifact[(a)-(b)])%MOD)

#define MOD  1000000007LL
#define MOD1  500000003LL

int main()
{
	initfact(MAX-1,MOD1);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long a,b,n;
		scanf("%lld %lld %lld",&a,&b,&n);
		
		long long exp=(2*C((2*n-1),(n-1),MOD1))%(MOD-1);
		printf("%lld\n",p(a,p(exp,b,MOD-1),MOD));
	}
}
