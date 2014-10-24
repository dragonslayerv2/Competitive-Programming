#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long x,m,n;
		cin>>x>>m>>n;
		long long ans=0;
		long long last=1;
		for(int i=0;i<=m;i++){
			ans+=last;
			last*=x;
			last%=n;
			ans%=n;
		}
		cout<<ans<<endl;
	}
}
