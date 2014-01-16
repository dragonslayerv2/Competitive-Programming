#include<iostream>
using namespace std;

#define MOD (10000000+7)

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
		else if(m<q)
			ans=0;
		else
		{
				ans=0;
				ans=(n*(n-1))%MOD;
				ans=(ans*(m-q))%MOD;
				if(n>1)
					ans=(ans*(p(q+1,n-2)))%MOD;
		
		}
		cout<<ans<<endl;
	}
}
