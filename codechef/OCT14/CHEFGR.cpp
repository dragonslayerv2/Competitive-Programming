#include<iostream>
#include<vector>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> a(n);
		int maximum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			maximum=max(maximum,a[i]);
		}
		int cost=0;
		for(int i=0;i<n;i++){
			m-=maximum-a[i];
		}
		cout<<(m>=0&&(m%n==0)?"Yes":"No")<<endl;
	}
}
