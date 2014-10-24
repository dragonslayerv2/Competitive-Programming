#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
			
		sort(a.begin(),a.end());
		
		long long chef=0;
		for(int j=a.size()-1;j>=0;j-=2)
			chef+=a[j];
		cout<<chef<<endl;
	
		
	}
}
