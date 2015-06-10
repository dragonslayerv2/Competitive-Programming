#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long s,e;
		cin>>s>>e;
		bool isPossible=true;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			long long x,y;
			cin>>x>>y;
			if(x>=e||y<=s);
			else
				isPossible=false;
		}
		if(isPossible)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
}
