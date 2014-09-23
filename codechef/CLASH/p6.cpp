#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const string IMPOSSIBLE = "IMPOSSIBLE";
const string POSSIBLE = "POSSIBLE";

const int MAX_POSSIBLE = 10005;
int main(){
	#ifndef ONLINE_JUDGE
		freopen("p6.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	
	int x,y;
	cin>>x>>y;
	
	vector<int> a;
	a.reserve(n);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x-1);	
	}
	
	sort(a.begin(),a.end());
	a.resize(unique(a.begin(),a.end())-a.begin());
	int size=0;
	for(int i=0;i<a.size();i++){
		size=i;	
		if(a[i]>10000)
			break;
	}
	a.resize(size);
	
	if(y<x)
		cout<<IMPOSSIBLE;
	else{
		int toForm = y-x;
		bool isPossible[MAX_POSSIBLE]={false};
		isPossible[0]=true;
		for(int i=0;i<MAX_POSSIBLE;i++)
			if(isPossible[i]){
				for(int j=0;j<a.size();j++){
					if(i+a[j]>=MAX_POSSIBLE)
						break;
					else
						isPossible[i+a[j]]=true;
				}		
			}
		cout<<(isPossible[toForm]?POSSIBLE:IMPOSSIBLE);
	}
}
