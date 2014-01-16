#include<iostream>
using namespace std;

#define MOD (1000000000+7)

long long p(int n,int m)
{
    if(m==0) return 1;
    
    long long x=p(n,m/2);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,m,q,k;
		cin>>n>>m>>q>>k;
		long long ans;
		if(n==1)
		{
			if(q==0)
				ans=m;
			else
				ans=0;		
		}
		if(m<q)
			ans=0;
		else
		{
			ans=p(q+1,n);
			ans%=MOD;
			
			ans+=p(q-1,n);
			ans%=MOD;
			
			ans-=(2*p(q,n))%MOD;
			ans+=MOD;
			ans%=MOD;
			
			ans*=(m-q);
			ans%=MOD;
		}
		cout<<ans<<endl;
	}
}
