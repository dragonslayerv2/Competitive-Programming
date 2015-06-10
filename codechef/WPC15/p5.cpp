#include<iostream>
#include<vector>
using namespace std;

#define MOD 1000000007
template<class T> T p(T n,int m, long long mod)
{
    if(m==0) return 1%mod;
    
    T x=p(n,m/2,mod);
    if(m%2==0) 
               return (x*x)%mod;
    else
               return (((x*x)%mod)*n)%mod;
}



int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		long long n,k;
		cin>>k>>n;
		long long ans=0;
		if(n==1)
			ans=1;
		else if(n==2)
			ans=k;
		else if(n>=3)
			ans=p(k,p(2,n-3,MOD-1),MOD);
		cout<<ans<<endl;
	}
}
