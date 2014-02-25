#include<iostream>
using namespace std;

#define MOD 1000000007


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
		h--;
		if(h==0)
			solution=1;
		else if(h==1)
			solution=1;
		else if(h==2)
			solution=1;
		else
		{
			long long ans1=p(2,h-2);
			h-=2;
		
			
			long long power2=p(2,h);
			if(h%2==0)
			{
				solution=(((MOD+power2-1)%MOD)*inverse3)%MOD;
			}
			else
			{
				solution=(((MOD+power2+1)%MOD)*inverse3)%MOD;
			}
			solution+=ans1;
			solution%=MOD;
				
		}
		printf("%lld\n",solution);
	}	
}
