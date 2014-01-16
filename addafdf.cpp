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
	long long i25=p(25,MOD-2);
	while(t--)
	{
		int n;
		cin>>n;
		long long ans=0;
		
			ans=(2*((((26*(MOD+p(26,n/2)-1))%MOD)*i25)%MOD))%MOD;
		if(n%2)
		{
			ans+=p(26,n/2+1);
			ans%=MOD;
		}		
		cout<<ans<<endl;
	}
	return 0;
}
