#include<iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		long long x,k;
		cin>>x>>k;
		long double pow2=1;
		
		long long kCopy=k;
		while(kCopy){
			pow2*=2;
			kCopy>>=1;
		}
		
		long double ans=(1+(2*k-pow2))/pow2;
		ans*=x;
		cout.setf(ios::fixed);
		cout.precision(6);
		cout<<ans<<endl;
	}
}
