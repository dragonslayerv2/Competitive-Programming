#include<iostream>
using namespace std;


long long mod(long long a){
	return a<0?-a:a;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long e,o;
		cin>>e>>o;
		if(mod(3*e-2*o)%5==0)
			cout<<mod(3*e-2*o)/5;
		else
			cout<<-1;
		cout<<endl;
	}
}
