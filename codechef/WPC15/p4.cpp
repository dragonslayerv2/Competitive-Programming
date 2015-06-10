#include<iostream>
#include<vector>
using namespace std;

#define MOD 1000000007
template<class T> T p(T n,int m)
{
    if(m==0) return 1%MOD;
    
    T x=p(n,m/2);
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
		long long n,m;
		cin>>n>>m;
		long long ans=0;
		if(n>=1)
			ans=m;
		if(n>=2)
			ans=(ans*(m-1))%MOD;
		if(n>=3)
			ans=(ans*p(m-2,n-2))%MOD;
		cout<<ans<<endl;
	}
}
