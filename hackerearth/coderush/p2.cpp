#include<iostream>
using namespace std;
#define MOD (1000000007LL)

long long p(long long n,long long m)
{
    if(m==0) return 1%MOD;
    long long x=p(n,m/2);
    if(m%2==0) 
    	return (x*x)%MOD;
    else
    	return (((x*x)%MOD)*n)%MOD;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		cout<<p(2,n)<<endl;
	}
}
