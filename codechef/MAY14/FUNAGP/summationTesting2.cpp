#include<iostream>
#include<cstdio>
using namespace std;
long long power(long long n,long long m,long long MOD)
{
    if(m==0) return 1%MOD;
    
    long long x=power(n,m/2,MOD);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}

	long long sumofAGP(long long A,long long D,long long R,long long n,long long MOD)
	{
		long long ans=0;
		for(int i=0;i<n;i++)
		{
		//	cerr<<"Term Value "<< (((A+i*D)%MOD)*power(R,i,MOD))%MOD<<endl;
			
			ans+=(((A+i*D)%MOD)*power(R,i,MOD))%MOD;
			ans%=MOD;
		}
		return ans;
	}
int main()
{
	freopen("in.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
	long long a,d,r,n,MOD;
	cin>>a>>d>>r>>n>>MOD;
	cout<<sumofAGP(a,d,r,n,MOD)<<endl;		
	}
	
}
