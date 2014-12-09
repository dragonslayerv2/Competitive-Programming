#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q1, q1res;
		priority_queue<pair<int,int>,vector<pair<int,int> >,less<pair<int,int> > > q2,q2res;
		
		vector<vector<int> > times(n,vector<int>(2));
		for(int i=0;i<n;i++){
			int a,b;
			cin>>a>>b;
			q1.push(make_pair(a,i));
			q2.push(make_pair(b,i));
		}
		int cpuTimeAtA=0;
		int cpuTimeAtB=0;
		int lastRunningA,lastRunningB;
		lastRunningA=lastRunningB=-1;
		while(q1.size()||q2.size()||q1res.size()||q2res.size()){
			while(cpuTimeAt)
		}
	}
}
