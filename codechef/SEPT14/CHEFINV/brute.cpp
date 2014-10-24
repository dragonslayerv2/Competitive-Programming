#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	
	vector<int> arr;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	
	int inversionCount=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j])
			inversionCount++;
		}
	}
	
	while(m--){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		swap(arr[a],arr[b]);
		int count=0;
		for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j])
			count++;
			}
		}
		cout<<count<<"\n";
		swap(arr[a],arr[b]);
	}
}
