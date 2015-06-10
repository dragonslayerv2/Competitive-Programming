#include<iostream>
#include<vector>
#include<map>
using namespace std;

int n;
vector<vector<long long> > cost;
long long k;
map<pair<int,pair<int,long long> >, bool> dp;
bool solve(int source,int visited, long long current){
	
	pair<int,pair<int,long long > > key=make_pair(source,make_pair(visited,current));
	if(dp.find(key)==dp.end()){
		bool ans=false;
		visited=(visited|(1<<source));
		if(visited==((1<<n)-1)){
			if(source==0){
				if(k==current)
					ans=true;
				else
					ans=false;
			}
			else
				ans=solve(0,visited,current+cost[source][0]);
		}
		else{
			bool isPossible=false;
			for(int i=0;i<n;i++){
				if(!(visited&(1<<i)))
					isPossible=(isPossible||solve(i,visited,current+cost[source][i]));
			}
			ans=isPossible;
		}
		dp[key]=ans;
	}
	return dp[key];
}


int main(){
	 cin>>n>>k;
	 cost.assign(n,vector<long long>(n));
	 for(int i=0;i<n;i++)
	 	for(int j=0;j<n;j++)
	 		cin>>cost[i][j];
	 	
	
	bool isPossible=false;
	for(int i=0;i<n;i++)
		isPossible=(isPossible||solve(i,0,0));
	
	cout<<(isPossible?"possible":"impossible");
}
