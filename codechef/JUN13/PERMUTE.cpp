#include<iostream>
using namespace std;


#define MOD 1000000007


//-------------------------------
#define MAX 1000000
long long fact[MAX+10];
void initfact()
{
	fact[0]=1;
	for(int i=1;i<=MAX;i++)
	{
		fact[i]=(fact[i-1]*i)%MOD;
	}
}
//---------------------------------

long long p(int n,int m)
{
    if(m==0) return 1;
    
    long long x=p(n,m/2);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}

//------------------------------------

int main()
{
	initfact();
	
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		long long ans;
		if(1+n>m)
			ans=0;
		else
		{
			int k=m-n+1;
			if(n<=k)
				ans=fact[n];
			else
			{	
				ans=fact[k];
				//cout<<"Ans="<<k<<"!*"<<k-1<<"^"<<(n-k-1)/2+1<<"*"<<k<<"^"<<(n-k)/2<<endl;
				long long powvalue=(p(k-1,(n-k-1)/2+1)*p(k,(n-k)/2))%MOD;
				ans=(ans*powvalue)%MOD;
			}
		}
		if(n==1&&m==1) cout<<1<<endl;
		else		
			cout<<ans<<endl;
	}
}
