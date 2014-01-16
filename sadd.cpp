#include<iostream>
using namespace std;
#define MOD 1000000007

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
		long long n,k;
		cin>>n>>k;
		cout<<(((k*(k-1))%MOD)*p((((k-2)*(k-2))%MOD+(k-1))%MOD,n-1))%MOD<<endl;
	}
}
