#include<stdio.h>
#include<stdlib.h>

#define MOD 1000000007
#define MAX 800005
long long fact[MAX];
long long ifact[MAX];
long long a[MAX];
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
     ifact[i-1] = ifact[i]*i%MOD;
}




#define C(a,b) ((((fact[a]*ifact[b])%MOD)*ifact[a-b])%MOD)


//------------------------------------------------------------------------------
int compare (const void * a, const void * b)
{
    return ( *(int*)b - *(int*)a );
}
//------------------------------------------------------------------------------

int main()
{
		freopen ( "in.txt", "r", stdin );
		freopen ( "out.txt", "w", stdout );
		initfact(MAX,fact,ifact);
		int t;
		scanf("%d",&t);
		for(int T=1;T<=t;T++)
		{
			int n,k;
			scanf("%d %d",&n,&k);
			for(int i=0;i<n;i++)
			{
				scanf("%lld",&a[i]);
			}
			qsort (a, n, sizeof(long long), compare);
			
		/*	for(int i=0;i<n;i++)
			{
				printf("%lld ",a[i]);
			}*/
			long long sum=0;
			
			for(int i=1;n-i>=k-1;i++)
			{
			//	printf("hi..");
			//	printf("%lld*%lld=%lld",a[i-1],C((n-i),(k-1)),a[i-1]*C((n-i),(k-1)));
				sum+=a[i-1]*C((n-i),(k-1));
			//	printf("%d ",sum);
				sum=sum%MOD;
			}
			printf("Case #%d: %lld\n",T,sum);
		}
		return 0;

}
