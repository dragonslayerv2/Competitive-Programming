#include<iostream>
using namespace std;

#define MOD 10000007


long long p(long long n,long long m)
{
    if(m==0) return 1;
    
    long long x=p(n,m/2);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}


long long inverse3=p(3,MOD-2);

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long h;
		scanf("%lld",&h);
		long long solution=0;
		long long power2=p(2,h);
		if(h%2==0)
		{
			solution=(((MOD+power2-1)%MOD)*inverse3)%MOD;
		}
		else
		{
			solution=(((MOD+power2+1)%MOD)*inverse3)%MOD;
		}
		printf("%lld\n",solution);
	}	
}
