#include<iostream>
using namespace std;
#define MOD 1000000007
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>k>>n;
		
		long long m=1;
		long long nm=0;
		
		while(k--)
		{
			long long tm=m;
			m=nm;
			nm=((nm*(n-1))%MOD+(tm*(n))%MOD)%MOD;
		}
		cout<<m<<endl;	
	}
}
