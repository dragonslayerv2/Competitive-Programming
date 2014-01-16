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
		int n;
		cin>>n;
		long long ans=p(2,n);
		cout<<(MOD+ans-1)%MOD<<endl;
	}
}
