#include<iostream>
using namespace std;

#define MOD 1000000009

long long p(long long n,int m)
{
    if(m==0) return 1%MOD;
    
    long long x=p(n,m/2);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}


int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		long long ans = (p(m,n/2)*p(m-1,n/2))%MOD;
		if(n&1)
			ans=(ans*m)%MOD;
		cout<<ans<<endl;
	}
}
