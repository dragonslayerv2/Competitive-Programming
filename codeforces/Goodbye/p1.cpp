#include<iostream>
#include<vector>
using namespace std;

vector<bool> isPossible,calculated;
vector<int> a;

bool solve(int i,int t){
	if(!calculated[i]){
		if(i==t)
			isPossible[i]=true;
		else if(i>t)
			isPossible[i]=false;
		else
			isPossible[i]=solve(i+a[i],t);					
		calculated[i]=true;
	}
	return isPossible[i];
}
int main(){
	int n,t;
	cin>>n>>t;
	
	a.push_back(0);
	for(int i=0;i<n-1;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}	
	isPossible.resize(n+1);
	calculated.resize(n+1);
	cout<<(solve(1,t)?"YES":"NO");
}
