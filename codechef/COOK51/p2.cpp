#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int MAX=INT_MIN;
		int MIN=INT_MAX;
		while(m--){
			int x;
			cin>>x;
			MAX=max(MAX,x);
			MIN=min(MIN,x);
		}
		for(int i=0;i<n;i++){
			cout<<max(abs(MAX-i),abs(MIN-i))<<" ";
		}
		cout<<endl;
	}
}
