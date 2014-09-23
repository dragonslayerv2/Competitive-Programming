#include<iostream>
#include<vector>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int p;
		cin>>p;
		vector<int> nodesConnected(p+1);
		int q;
		cin>>q;
		while(q--){
			int n,a;
			cin>>n>>a;
			a--;
			nodesConnected[a]++;
			nodesConnected[a+n]--;
		}
		int MAX = 0;
		for(int i=1;i<nodesConnected.size();i++)
		{
			nodesConnected[i]+= nodesConnected[i-1]; 
			MAX=max(MAX,nodesConnected[i]);
		}
		cout<<max(nodesConnected[0],MAX)<<endl;
	}
}
