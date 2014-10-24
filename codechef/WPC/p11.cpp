#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool isPossbile=false;
		while(n%10==0)
			n/=10;
		if(n==1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
}
