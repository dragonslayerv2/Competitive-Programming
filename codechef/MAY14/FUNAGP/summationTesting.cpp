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
		A%=MOD;
		D%=MOD;
		R%=MOD;
		
		if(R==1)
		{
			long long ans1=(((A*n)%MOD)+((((n*(n-1))/2)%MOD)*D)%MOD)%MOD;
			return ans1;
		}
		else
		{
			long long ans1=A*(1-R);
			ans1%=MOD;
			ans1+=MOD;
			ans1%=MOD;
			
			long long ans2=(D*((power(R,n,MOD)-R+MOD)%MOD))%MOD;
			ans2+=MOD;
			ans2%=MOD;
			
			long long ans3= (((A+(n-1)*D)%MOD)*((power(R,n,MOD)*(MOD+1-R)%MOD)%MOD))%MOD;
			
			ans1-=(ans2+ans3)%MOD;
			ans1+=MOD;
			ans1%=MOD;
			
			ans1*=power(((1-R)*(1-R))%MOD,MOD-2,MOD);
			ans1%=MOD;
			return ans1;
		}
	}
	
	
int main()
{
//	freopen("in.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
	int a,d,r,n,MOD;
	cin>>a>>d>>r>>n>>MOD;
	cout<<sumofAGP(a,d,r,n,MOD)<<endl;	
}
}
